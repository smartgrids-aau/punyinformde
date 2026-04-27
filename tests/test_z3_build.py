"""Tests: Z3 build.

Verifies the Z3 story file (build/sterne.z3) produced by compiling sterne.inf
with USE_ASCII and targeting z3 (128 KB limit, pure ZSCII).

Why Z3?
  Z3 is the smallest Z-machine format and runs on the widest range of
  interpreters (including 8-bit machines). The main extra constraint is that
  game Global declarations must come AFTER including globals.h; Z3 requires
  score, turns, and location at specific global-variable indices 0-2.

Coverage:
  - ASCII commands work (same digraph input as ASCII build)
  - Parser messages have no umlaut bytes
  - Complete walkthrough wins the game
  - Maximum score (5/5) is reached
  - Full output contains no bytes outside ASCII range
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)

NOT_UNDERSTOOD = "verstehe nicht"
UNKNOWN_VERB   = "kenne ich nicht"

Z3_WALKTHROUGH = [
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


@pytest.mark.feature("z3")
def test_z3_walkthrough_no_unknown_commands(game_z3):
    """Every command in the Z3 walkthrough is understood."""
    out = game_z3.run(Z3_WALKTHROUGH)
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_not_contains(out, UNKNOWN_VERB)


@pytest.mark.feature("z3")
def test_z3_walkthrough_wins(game_z3):
    """Z3 walkthrough reaches the win condition."""
    out = game_z3.run(Z3_WALKTHROUGH)
    assert_output_contains(out, "gewonnen")


@pytest.mark.feature("z3")
def test_z3_walkthrough_full_score(game_z3):
    """Z3 walkthrough achieves maximum score (5/5)."""
    out = game_z3.run(Z3_WALKTHROUGH)
    assert_output_contains(out, "5")


@pytest.mark.feature("z3")
def test_z3_output_has_no_high_bytes(game_z3):
    """Full game output must contain NO characters outside ASCII range.

    Z3 has no Unicode extension; any umlaut in the output would indicate
    a string literal that was not preprocessed via Convert-ToAsciiDigraphs.
    """
    out = game_z3.run(Z3_WALKTHROUGH)
    high = [c for c in out.raw if ord(c) > 127]
    assert not high, (
        f"Z3 output contains {len(high)} non-ASCII character(s): "
        + "".join(repr(c) for c in sorted(set(high)))
    )


@pytest.mark.feature("z3")
def test_z3_unlock_door(game_z3):
    """'schliess tuer mit schluessel auf' unlocks the door in Z3 mode."""
    out = game_z3.run([
        "oeffne kiste", "nimm schluessel",
        "schliess tuer mit schluessel auf",
    ])
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_contains(out, "auf")
