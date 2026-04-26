"""Tests: object-list formatting.

Verifies the German-correct list separator and container state strings.

Coverage:
  (b) 'und' is used instead of 'and' when listing multiple objects
      '(geschlossen)' is shown instead of '(ist geschlossen)' for closed containers
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)


@pytest.mark.feature("list-format")
def test_list_uses_und_not_and(game):
    """Room listing uses 'und' (German) not 'and' (English) between objects."""
    out = game.run(["schau"])
    # The initial room has Kajuentuer and Kiste visible — listed with 'und'
    assert_output_contains(out, " und ")
    assert_output_not_contains(out, " and ")


@pytest.mark.feature("list-format")
def test_closed_container_shows_geschlossen_not_ist(game):
    """Closed container annotation is '(geschlossen)', not '(ist geschlossen)'."""
    out = game.run(["schau"])
    assert_output_contains(out, "(geschlossen)")
    assert_output_not_contains(out, "(ist geschlossen)")
    assert_output_not_contains(out, "(ist offen)")


@pytest.mark.feature("list-format")
def test_open_container_no_ist_prefix(game):
    """After opening the chest the annotation should not contain 'ist'."""
    out = game.run(["\u00f6ffne kiste", "schau"])
    # Once open with contents, the listing shows 'enthält' not 'ist offen'
    assert_output_not_contains(out, "(ist offen)")
    assert_output_not_contains(out, "ist geschlossen")
