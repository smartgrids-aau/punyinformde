"""PunyInformDE test configuration.

Wires the PunyTest framework to the 'sterne' game.
The compiled .z5 in build/ is used if present; otherwise inform6 is invoked.

Two game variants are supported:
    game          – Unicode build (build/sterne.z5)      uses cp1252 I/O
    game_ascii    – ASCII build   (build/sterne.ascii.z5) uses ASCII I/O
"""

from __future__ import annotations

import subprocess
import sys
from pathlib import Path
import importlib

GAME_ROOT = Path(__file__).resolve().parent.parent

# Add the sibling PunyTest repository root (e.g. C:\Source\PunyTest) so the
# public package name `punytest` can be imported.
_PUNYTEST_REPO = GAME_ROOT.parent / "PunyTest"
if str(_PUNYTEST_REPO) not in sys.path:
    sys.path.insert(0, str(_PUNYTEST_REPO))

import pytest

try:
    # New public repository layout/package name.
    _pt_pkg = importlib.import_module("punytest")
    _pt_asserts = importlib.import_module("punytest.asserts")
    _pt_conftest_base = importlib.import_module("punytest.conftest_base")
    _pt_runner = importlib.import_module("punytest.runner")
    _pt_tools = importlib.import_module("punytest.tools")

    # Compatibility aliases for existing test imports: from PunyTest.asserts import ...
    sys.modules.setdefault("PunyTest", _pt_pkg)
    sys.modules.setdefault("PunyTest.asserts", _pt_asserts)
    sys.modules.setdefault("PunyTest.conftest_base", _pt_conftest_base)
    sys.modules.setdefault("PunyTest.runner", _pt_runner)
    sys.modules.setdefault("PunyTest.tools", _pt_tools)

    from punytest.conftest_base import pytest_configure  # noqa: F401
    from punytest.runner import compile_story, GameSession, GameOutput
    from punytest.tools import find_dfrotz, find_inform6
except ModuleNotFoundError:
    # Legacy fallback for older local checkouts that still expose `PunyTest`.
    from PunyTest.conftest_base import pytest_configure  # noqa: F401
    from PunyTest.runner import compile_story, GameSession, GameOutput
    from PunyTest.tools import find_dfrotz, find_inform6

STORY_SOURCE       = GAME_ROOT / "example" / "sterne.inf"
STORY_Z5           = GAME_ROOT / "build" / "sterne.z5"
STORY_ASCII_SOURCE = GAME_ROOT / "example" / "sterne_ascii.inf"
STORY_ASCII_Z5     = GAME_ROOT / "build" / "sterne.ascii.z5"
STORY_Z3_SOURCE    = GAME_ROOT / "example" / "sterne_z3.inf"
STORY_Z3           = GAME_ROOT / "build" / "sterne.z3"

# Input encoding for dfrotz on Windows.
# dfrotz reads raw bytes from piped stdin; Windows Latin-1 (cp1252) encodes
# ä→0xE4, ö→0xF6, ü→0xFC, ß→0xDF — the same byte values that dfrotz maps
# to the Zcharacter-declared ZSCII codes.
_INPUT_ENCODING  = "cp1252"
_OUTPUT_ENCODING = "cp1252"


class DE_GameSession(GameSession):
    """GameSession variant that uses cp1252 byte encoding for German umlauts."""

    def run(self, commands: list[str], *, quit_after: bool = True) -> GameOutput:
        entered_commands = list(commands)
        cmds = list(entered_commands)
        if quit_after:
            cmds.extend(["quit", "y"])

        input_text = "\n".join(cmds) + "\n"
        input_bytes = input_text.encode(_INPUT_ENCODING, errors="replace")

        cmd = [
            str(self.dfrotz),
            "-w", str(self.width),
            "-h", str(self.height),
            "-p",
        ]
        if self.seed is not None:
            cmd.extend(["-s", str(self.seed)])
        cmd.append(str(self.story_file))

        result = subprocess.run(
            cmd,
            input=input_bytes,
            capture_output=True,
            timeout=30,
        )

        raw = result.stdout.decode(_OUTPUT_ENCODING, errors="replace")

        lines = raw.splitlines()
        cleaned: list[str] = []
        for line in lines:
            if "Are you sure you want to quit?" in line:
                break
            cleaned.append(line)

        return GameOutput(raw=raw, lines=cleaned, commands=entered_commands, quit_after=quit_after)


class ASCII_GameSession(GameSession):
    """GameSession for the USE_ASCII build: pure ASCII I/O.

    Input is encoded as ASCII (no umlaut bytes needed).
    Output is decoded as latin-1 so that any accidentally-output umlaut bytes
    remain visible as characters (ord > 127) rather than being silently
    replaced with '?' — this allows tests to assert the output is truly ASCII.
    """

    def run(self, commands: list[str], *, quit_after: bool = True) -> GameOutput:
        entered_commands = list(commands)
        cmds = list(entered_commands)
        if quit_after:
            cmds.extend(["quit", "y"])

        input_bytes = ("\n".join(cmds) + "\n").encode("ascii", errors="replace")

        cmd = [
            str(self.dfrotz),
            "-w", str(self.width),
            "-h", str(self.height),
            "-p",
        ]
        if self.seed is not None:
            cmd.extend(["-s", str(self.seed)])
        cmd.append(str(self.story_file))

        result = subprocess.run(
            cmd,
            input=input_bytes,
            capture_output=True,
            timeout=30,
        )

        # Decode as latin-1 (lossless for all byte values 0x00-0xFF).
        # Any umlaut bytes from the game will appear as their latin-1 characters
        # (ord > 127), which our no-high-bytes test detects.
        raw = result.stdout.decode("latin-1")

        lines = raw.splitlines()
        cleaned: list[str] = []
        for line in lines:
            if "Are you sure you want to quit?" in line:
                break
            cleaned.append(line)

        return GameOutput(raw=raw, lines=cleaned, commands=entered_commands, quit_after=quit_after)


# ---------------------------------------------------------------------------
# Per-game fixtures (override the stubs in conftest_base)
# ---------------------------------------------------------------------------

@pytest.fixture(scope="session")
def story_source() -> Path:
    return STORY_SOURCE


@pytest.fixture(scope="session")
def story_z5() -> Path | None:
    return STORY_Z5 if STORY_Z5.is_file() else None


@pytest.fixture(scope="session")
def include_paths() -> list[Path]:
    return [GAME_ROOT / "lib"]


@pytest.fixture(scope="session")
def compiled_game(story_source: Path, story_z5: Path | None, include_paths: list[Path]) -> Path:
    """Return a ready-to-run .z5 (compile only if the pre-built file is missing)."""
    if story_z5 and story_z5.is_file():
        return story_z5

    if find_inform6() is None:
        pytest.skip("inform6 not found and no pre-built .z5 in build/")

    result = compile_story(
        story_source,
        include_paths=include_paths,
        output=STORY_Z5,
    )
    return result.z_file


@pytest.fixture
def game(compiled_game: Path) -> DE_GameSession:
    """Fresh DE_GameSession (cp1252 input encoding) for each test."""
    if find_dfrotz() is None:
        pytest.skip("dfrotz not found")
    return DE_GameSession(compiled_game, dfrotz=GAME_ROOT / "tools" / "dfrotz.exe")


@pytest.fixture(scope="session")
def compiled_game_ascii(include_paths: list[Path]) -> Path:
    """Return the ASCII build .z5, compiling if needed."""
    if STORY_ASCII_Z5.is_file():
        return STORY_ASCII_Z5
    if find_inform6() is None:
        pytest.skip("inform6 not found and no pre-built ASCII .z5 in build/")
    result = compile_story(
        STORY_ASCII_SOURCE,
        include_paths=include_paths,
        output=STORY_ASCII_Z5,
    )
    return result.z_file


@pytest.fixture
def game_ascii(compiled_game_ascii: Path) -> ASCII_GameSession:
    """Fresh ASCII_GameSession for the USE_ASCII build."""
    if find_dfrotz() is None:
        pytest.skip("dfrotz not found")
    return ASCII_GameSession(compiled_game_ascii, dfrotz=GAME_ROOT / "tools" / "dfrotz.exe")


@pytest.fixture(scope="session")
def compiled_game_z3(include_paths: list[Path]) -> Path:
    """Return the Z3 build .z3, compiling if needed."""
    if STORY_Z3.is_file():
        return STORY_Z3
    if find_inform6() is None:
        pytest.skip("inform6 not found and no pre-built .z3 in build/")
    result = compile_story(
        STORY_Z3_SOURCE,
        include_paths=include_paths,
        output=STORY_Z3,
    )
    return result.z_file


@pytest.fixture
def game_z3(compiled_game_z3: Path) -> ASCII_GameSession:
    """Fresh ASCII_GameSession for the Z3 build (pure ZSCII, no Unicode)."""
    if find_dfrotz() is None:
        pytest.skip("dfrotz not found")
    return ASCII_GameSession(compiled_game_z3, dfrotz=GAME_ROOT / "tools" / "dfrotz.exe")

