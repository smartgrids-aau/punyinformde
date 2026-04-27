"""Tests: unknown-word error messages preserve the original input form.

Verifies that when the player types a word the parser does not recognise,
the error message echoes back exactly what was typed — not a normalised
or suffix-stripped variant.

Key regressions guarded (both Unicode and ASCII builds):

  "x kajute"              → error shows "kajute"  (not "kajut" — e-stripping)
  "x kajuete" / ASCII     → error shows "kajuete" (not "kajüte" — digraph pass)
  "x kajuet"              → error shows "kajuet"
  "x kapitaenskajuete"    → error shows "kapitaenskajuete"

ASCII-build tests use `game_ascii` (digraph input is the natural form).
Unicode-build tests use `game` with the same digraph inputs, which are safe
because dfrotz on Windows piped stdin cannot reliably deliver umlaut bytes
(see test_umlauts.py), so we use ASCII-only input in both fixture variants.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import assert_output_contains


# ---------------------------------------------------------------------------
# ASCII build (game_ascii)
# ---------------------------------------------------------------------------

@pytest.mark.feature("unknown-word-display")
def test_unknown_noun_e_not_stripped_ascii(game_ascii):
    """'kajute' must appear as 'kajute' in error (ASCII build, e-stripping regression)."""
    out = game_ascii.run(["x kajute"])
    assert_output_contains(out, '"kajute"')


@pytest.mark.feature("unknown-word-display")
def test_unknown_digraph_noun_not_normalised_ascii(game_ascii):
    """Unknown word with 'ue' must NOT be normalised to umlaut in error (ASCII build, digraph-pass regression)."""
    out = game_ascii.run(["x geruest"])
    assert_output_contains(out, '"geruest"')


@pytest.mark.feature("unknown-word-display")
def test_unknown_noun_no_e_preserved_ascii(game_ascii):
    """'kajuet' must appear unchanged in error (ASCII build)."""
    out = game_ascii.run(["x kajuet"])
    assert_output_contains(out, '"kajuet"')


@pytest.mark.feature("unknown-word-display")
def test_unknown_long_noun_preserved_ascii(game_ascii):
    """Long unknown compound noun with digraph must appear unchanged (ASCII build)."""
    out = game_ascii.run(["x geruesthaken"])
    assert_output_contains(out, '"geruesthaken"')


# ---------------------------------------------------------------------------
# Unicode build (game) — same ASCII-safe inputs, exercises the Unicode code paths
# ---------------------------------------------------------------------------

@pytest.mark.feature("unknown-word-display")
def test_unknown_noun_e_not_stripped_unicode(game):
    """'kajute' must appear as 'kajute' in error (Unicode build, e-stripping regression)."""
    out = game.run(["x kajute"])
    assert_output_contains(out, '"kajute"')


@pytest.mark.feature("unknown-word-display")
def test_unknown_digraph_noun_not_normalised_unicode(game):
    """Unknown word with 'ue' must NOT be normalised to umlaut in error (Unicode build, digraph-pass regression)."""
    out = game.run(["x geruest"])
    assert_output_contains(out, '"geruest"')


@pytest.mark.feature("unknown-word-display")
def test_unknown_noun_no_e_preserved_unicode(game):
    """'kajuet' must appear unchanged in error (Unicode build)."""
    out = game.run(["x kajuet"])
    assert_output_contains(out, '"kajuet"')


@pytest.mark.feature("unknown-word-display")
def test_unknown_long_noun_preserved_unicode(game):
    """Long unknown compound noun with digraph must appear unchanged (Unicode build)."""
    out = game.run(["x geruesthaken"])
    assert_output_contains(out, '"geruesthaken"')
