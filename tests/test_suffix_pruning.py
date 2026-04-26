"""Tests: §3 Stage 1 unknown-word suffix pruning.

Verifies that inflected adjective forms are pruned to known stems for
object resolution (deform-style behavior):
- two-char endings: -em/-en/-er/-es
- one-char endings: -e/-n/-s
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import assert_output_contains, assert_output_not_contains

UNKNOWN_VERB = "kenne ich nicht"
NOT_UNDERSTOOD = "verstehe nicht"


@pytest.mark.feature("suffix-pruning")
def test_take_kleinen_schluessel(game):
    """Akkusativ adjective input ('kleinen') resolves to stem 'klein'."""
    out = game.run(["oeffne kiste", "nimm kleinen schluessel"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_contains(out, "Genommen")


@pytest.mark.feature("suffix-pruning")
def test_take_alte_karte(game):
    """One-char suffix ('alte' -> 'alt') should resolve to the Karte object."""
    out = game.run(["nimm alte karte"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_contains(out, "Genommen")


@pytest.mark.feature("suffix-pruning")
def test_untersuche_altem_kompass(game):
    """Two-char suffix ('altem' -> 'alt') should resolve to Kompass."""
    out = game.run(["untersuche altem kompass"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)
    assert_output_contains(out, "Kompass")


@pytest.mark.feature("suffix-pruning")
def test_lege_kleinem_schluessel_in_kiste(game):
    """Dative-like form in input should still resolve to key object."""
    out = game.run(["oeffne kiste", "nimm schluessel", "lege kleinem schluessel in kiste"])
    assert_output_not_contains(out, UNKNOWN_VERB)
    assert_output_not_contains(out, NOT_UNDERSTOOD)
