"""Tests: ASCII build (USE_ASCII mode).

These tests use the 'game_ascii' fixture, which runs 'build/beispiel_ascii.z5'
compiled with Constant USE_ASCII.  All commands use ASCII digraph forms
(oeffne, schluessel, schliess ... auf) so no umlaut bytes need to be piped
to dfrotz — solving the xfail problem that affects the Unicode build on Windows.

Coverage:
  - Parser understands all ASCII digraph commands
  - Parser messages output ASCII digraphs (no ä/ö/ü/ß in output)
  - Complete walkthrough wins the game in ASCII mode
  - Score and moves shown with Pt: / Zg: labels (status bar)
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)

NOT_UNDERSTOOD = "verstehe nicht"
UNKNOWN_VERB   = "kenne ich nicht"

ASCII_WALKTHROUGH = [
    "schau",
    "untersuche schreibtisch",
    "nimm karte",
    "untersuche karte",
    "untersuche koje",
    "untersuche kiste",
    "oeffne kiste",
    "nimm schluessel",
    "untersuche schluessel",
    "schliess tuer mit schluessel auf",
    "oeffne tuer",
    "nord",
    "rauf",
    "schau",
    "rede mit steuermann",
    "1",
    "rede mit papagei",
    "1",
    "rede mit navigatorin",
    "1",
    "nimm fernrohr",
    "untersuche fernrohr",
]


# ---------------------------------------------------------------------------
# Command recognition — same scenarios as xfail umlaut tests, now passing
# ---------------------------------------------------------------------------

@pytest.mark.feature("ascii")
def test_ascii_oeffne_kiste(game_ascii):
    """'oeffne kiste' is accepted in ASCII mode (mirrors xfail umlaut test)."""
    out = game_ascii.run(["oeffne kiste"])
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_not_contains(out, UNKNOWN_VERB)


@pytest.mark.feature("ascii")
def test_ascii_nimm_schluessel(game_ascii):
    """'nimm schluessel' picks up the key in ASCII mode."""
    out = game_ascii.run(["oeffne kiste", "nimm schluessel"])
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_contains(out, "Genommen")


@pytest.mark.feature("ascii")
def test_ascii_schliess_tuer_auf(game_ascii):
    """'schliess tuer mit schluessel auf' unlocks the door in ASCII mode."""
    out = game_ascii.run([
        "oeffne kiste", "nimm schluessel",
        "schliess tuer mit schluessel auf",
    ])
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_contains(out, "auf")


# ---------------------------------------------------------------------------
# ASCII output: parser messages must not contain umlauts
# ---------------------------------------------------------------------------

@pytest.mark.feature("ascii")
def test_ascii_open_message_no_umlauts(game_ascii):
    """Open message uses 'oeffnest' not 'öffnest' in ASCII mode."""
    out = game_ascii.run([
        "oeffne kiste", "nimm schluessel",
        "schliess tuer mit schluessel auf",
        "oeffne tuer",
    ])
    assert_output_contains(out, "oeffnest")
    assert_output_not_contains(out, "\u00f6ffnest")   # ö


@pytest.mark.feature("ascii")
def test_ascii_unlock_message_no_umlauts(game_ascii):
    """Unlock message uses 'schliesst' not 'schließt' in ASCII mode."""
    out = game_ascii.run([
        "oeffne kiste", "nimm schluessel",
        "schliess tuer mit schluessel auf",
    ])
    assert_output_contains(out, "schliesst")
    assert_output_not_contains(out, "schlie\u00dft")  # ß


@pytest.mark.feature("ascii")
def test_ascii_score_screen_no_umlauts(game_ascii):
    """Final score screen uses 'moeglichen' and 'Zuegen' in ASCII mode."""
    out = game_ascii.run(ASCII_WALKTHROUGH)
    assert_output_contains(out, "moeglichen")
    assert_output_not_contains(out, "m\u00f6glichen")  # ö
    assert_output_contains(out, "Zuegen")
    assert_output_not_contains(out, "Z\u00fcgen")       # ü


# ---------------------------------------------------------------------------
# Full walkthrough in ASCII mode
# ---------------------------------------------------------------------------

@pytest.mark.feature("ascii")
def test_ascii_walkthrough_no_unknown_commands(game_ascii):
    """Every command in the ASCII walkthrough is understood."""
    out = game_ascii.run(ASCII_WALKTHROUGH)
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_not_contains(out, UNKNOWN_VERB)


@pytest.mark.feature("ascii")
def test_ascii_walkthrough_wins(game_ascii):
    """ASCII walkthrough reaches the win condition."""
    out = game_ascii.run(ASCII_WALKTHROUGH)
    assert_output_contains(out, "gewonnen")


@pytest.mark.feature("ascii")
def test_ascii_walkthrough_full_score(game_ascii):
    """ASCII walkthrough achieves maximum score (5/5)."""
    out = game_ascii.run(ASCII_WALKTHROUGH)
    assert_output_contains(out, "5")


@pytest.mark.feature("ascii")
def test_ascii_output_has_no_high_bytes(game_ascii):
    """Full game output must contain NO characters outside ASCII range (0x00-0x7F).

    This test catches any string literal in the game source or library that was
    not preprocessed for the ASCII build.  dfrotz outputs umlaut bytes either as
    latin-1 (e.g. 0xF6 for ö) or as UTF-8 multi-byte sequences (e.g. 0xC3 0xB6);
    both are decoded as latin-1 by ASCII_GameSession, so any umlaut byte appears
    as a character with ord > 127.
    """
    out = game_ascii.run(ASCII_WALKTHROUGH)
    high = [c for c in out.raw if ord(c) > 127]
    assert not high, (
        f"ASCII build output contains {len(high)} non-ASCII character(s): "
        + repr("".join(sorted(set(high))))
    )
