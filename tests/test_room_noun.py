"""Tests: room objects can be examined by name.

Verifies that the player can refer to the current room (Kajüte / Kajuete)
as a noun — e.g. "x kajüte" or "x kajuete" — and receives the room
description rather than a parser error.

Coverage (both Unicode and ASCII builds):
  "x kajuete"            → shows room description fragment
  "x kapitaenskajuete"   → shows room description fragment
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import assert_output_contains, assert_output_not_contains

_ROOM_DESC_FRAGMENT = "Schreibtisch"  # always present in Kajüte description
_UNKNOWN_WORD = "kenne ich nicht"


# ---------------------------------------------------------------------------
# ASCII build (game_ascii)
# ---------------------------------------------------------------------------

@pytest.mark.feature("room-noun")
def test_examine_kajuete_ascii(game_ascii):
    """'x kajuete' should show the room description (ASCII build)."""
    out = game_ascii.run(["x kajuete"])
    assert_output_not_contains(out, _UNKNOWN_WORD)
    assert_output_contains(out, _ROOM_DESC_FRAGMENT)


@pytest.mark.feature("room-noun")
def test_examine_kapitaenskajuete_ascii(game_ascii):
    """'x kapitaenskajuete' should show the room description (ASCII build)."""
    out = game_ascii.run(["x kapitaenskajuete"])
    assert_output_not_contains(out, _UNKNOWN_WORD)
    assert_output_contains(out, _ROOM_DESC_FRAGMENT)


# ---------------------------------------------------------------------------
# Unicode build (game)
# ---------------------------------------------------------------------------

@pytest.mark.feature("room-noun")
def test_examine_kajuete_unicode(game):
    """'x kajuete' should show the room description (Unicode build)."""
    out = game.run(["x kajuete"])
    assert_output_not_contains(out, _UNKNOWN_WORD)
    assert_output_contains(out, _ROOM_DESC_FRAGMENT)


@pytest.mark.feature("room-noun")
def test_examine_kapitaenskajuete_unicode(game):
    """'x kapitaenskajuete' should show the room description (Unicode build)."""
    out = game.run(["x kapitaenskajuete"])
    assert_output_not_contains(out, _UNKNOWN_WORD)
    assert_output_contains(out, _ROOM_DESC_FRAGMENT)
