"""Tests: German direction words.

Verifies that bare German direction commands are understood by the parser
and move the player to the expected room.

Coverage:
  (e) nord  → moves north (from Kajuete with open door → Schiffsgang)
      rauf  → moves up    (from Schiffsgang → Oberdeck)
      runter → moves down  (from Oberdeck → Schiffsgang)
      sued  → moves south  (from Schiffsgang → Kajuete)
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)

UNKNOWN_VERB   = "kenne ich nicht"
NOT_UNDERSTOOD = "verstehe nicht"

# Commands to get through door (unlock + open it) — use ASCII digraphs
# to ensure setup works regardless of encoding; the actual direction words
# tested below are all ASCII.
_OPEN_DOOR = [
    "oeffne kiste",
    "nimm schluessel",
    "schliess tuer mit schluessel auf",
    "oeffne tuer",
]


@pytest.mark.feature("directions")
def test_nord_recognised(game):
    """'nord' is accepted by the parser (not 'Dieses Verb kenne ich nicht')."""
    out = game.run(_OPEN_DOOR + ["nord"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("directions")
def test_nord_moves_to_schiffsgang(game):
    """'nord' from Kajuete (door open) moves player to Schiffsgang."""
    out = game.run(_OPEN_DOOR + ["nord"])
    assert_output_contains(out, "Schiffsgang")


@pytest.mark.feature("directions")
def test_rauf_recognised(game):
    """'rauf' is accepted by the parser."""
    out = game.run(_OPEN_DOOR + ["nord", "rauf"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("directions")
def test_rauf_moves_to_oberdeck(game):
    """'rauf' from Schiffsgang moves player to Oberdeck."""
    out = game.run(_OPEN_DOOR + ["nord", "rauf"])
    assert_output_contains(out, "Oberdeck")


@pytest.mark.feature("directions")
def test_runter_moves_to_schiffsgang(game):
    """'runter' from Oberdeck moves player back to Schiffsgang."""
    out = game.run(_OPEN_DOOR + ["nord", "rauf", "runter"])
    assert_output_contains(out, "Schiffsgang")


@pytest.mark.feature("directions")
def test_sued_moves_to_kajuete(game):
    """'sued' from Schiffsgang moves player back south to Kajuete."""
    out = game.run(_OPEN_DOOR + ["nord", "sued", "schau"])
    # Starting room has the Schreibtisch — ASCII-safe landmark
    assert_output_contains(out, "Schreibtisch")
