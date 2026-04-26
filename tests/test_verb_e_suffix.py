"""Tests: German imperative -e suffix acceptance.

The German imperative can optionally take a trailing -e (e.g. 'nehme' and
'nehm' are both valid). Grammar_de.h defines the e-less form as primary and
accepts the -e form as a synonym.

Because dfrotz in piped-stdin mode on Windows does not reliably map
extended characters via pipes, these tests use only ASCII-safe commands
(no umlauts in the verb word itself). Umlaut *nouns* (kiste, schluessel,
tuer) are used where needed; those are ASCII-digraph forms from the game.

Coverage:
  (b) nehme  -> Take  (= nehm)
      schaue -> Look  (= schau)
      warte  -> Wait  (= wart)
      gehe   -> Go    (= geh)
      laufe  -> Go    (= lauf)
      lege   -> Put   (= leg)
      sage   -> Tell-style Answer (= sag) [checks no unknown-verb]
      oeffne -> Open  (= öffne, digraph form; game already accepts this)
      schliess -> Close/Unlock  (= schließ, digraph form)
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)

UNKNOWN_VERB = "kenne ich nicht"
NOT_UNDERSTOOD = "verstehe nicht"

# Helper to open the chest and get the key (sets up for door tests).
_GET_KEY = [
    "oeffne kiste",
    "nimm schluessel",
]


@pytest.mark.feature("verb-e-suffix")
def test_nehme_accepted(game):
    """'nehme' (e-form of 'nehm') is recognised as Take."""
    out = game.run(["nehme karte"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("verb-e-suffix")
def test_schaue_accepted(game):
    """'schaue' (e-form of 'schau') is recognised as Look."""
    out = game.run(["schaue"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("verb-e-suffix")
def test_warte_accepted(game):
    """'warte' (e-form of 'wart') is recognised as Wait."""
    out = game.run(["warte"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("verb-e-suffix")
def test_gehe_accepted(game):
    """'gehe' (e-form of 'geh') is recognised as Go."""
    out = game.run(["gehe nord"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("verb-e-suffix")
def test_laufe_accepted(game):
    """'laufe' (e-form of 'lauf') is recognised as Go."""
    out = game.run(["laufe nord"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("verb-e-suffix")
def test_oeffne_accepted(game):
    """'oeffne' (ASCII digraph for 'öffne') is recognised as Open."""
    out = game.run(["oeffne kiste"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_contains(out, "siehst")  # kiste opens, reveals schlüssel


@pytest.mark.feature("verb-e-suffix")
def test_schliess_accepted(game):
    """'schliess' (ASCII digraph for 'schließ') is recognised as Close/Unlock."""
    out = game.run(_GET_KEY + ["schliess tuer mit schluessel auf"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("verb-e-suffix")
def test_sage_accepted(game):
    """'sage' (e-form of 'sag') is recognised as Answer/Tell."""
    out = game.run(["sage hallo"])
    assert_output_not_contains(out, UNKNOWN_VERB)


@pytest.mark.feature("verb-e-suffix")
def test_untersuche_accepted(game):
    """'untersuche' (e-form accepted alongside e-less 'untersuch')."""
    out = game.run(["untersuche schreibtisch"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("verb-e-suffix")
def test_lege_accepted(game):
    """'lege' (e-form of 'leg') is recognised as Put."""
    out = game.run(["nimm karte", "lege karte"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("verb-e-suffix")
def test_ziehe_accepted(game):
    """'ziehe' (e-form of 'zieh') is recognised as Pull/Wear/Disrobe."""
    out = game.run(["ziehe schreibtisch"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)
