"""Regression tests for §2 + §3 behavior.

§2: pronoun substitution must keep working.
§3: adjective input suffix pruning and adjective output declension.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import assert_output_contains, assert_output_not_contains


@pytest.mark.feature("pronouns")
def test_untersuche_sie_not_stripped_to_si(game):
    """Regression: 'sie' must not be reduced to 'si' by -e stripping."""
    out = game.run(["nimm muenzen", "untersuche sie"])
    assert_output_not_contains(out, '"si"', msg="Pronoun 'sie' was incorrectly stripped to 'si'")
    assert_output_not_contains(out, "verstehe nicht", msg="Pronoun command should be understood")
    assert_output_contains(out, "Goldm", msg="Expected Münzen description from 'untersuche sie'")


@pytest.mark.feature("adjective-input")
def test_suffix_pruning_accepts_kleinen_schluessel(game):
    """§3 Stage 1: inflected adjective input should resolve to stem form."""
    out = game.run(["oeffne kiste", "nimm kleinen schluessel"])
    assert_output_not_contains(out, "verstehe nicht")
    assert_output_contains(out, "Genommen")


@pytest.mark.feature("adjective-declension")
def test_puton_declines_alter_to_alten(game):
    """§3 Stage 2: accusative masculine adjective declension in output."""
    out = game.run(["nimm kompass", "lege kompass auf schreibtisch"])
    assert_output_contains(out, "Du legst den alten Kompass auf den Schreibtisch.")


@pytest.mark.feature("adjective-declension")
def test_open_kiste_shows_einen_kleinen_schluessel(game):
    """§3 Stage 2: opening a container prints accusative indefinite object phrase."""
    out = game.run(["oeffne kiste"])
    assert_output_contains(out, "siehst einen kleinen Schl",
        msg="Expected accusative phrase '... siehst einen kleinen Schlüssel'")
