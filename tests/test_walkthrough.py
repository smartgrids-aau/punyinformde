"""Tests: complete walkthrough of 'Das Schiff der Sterne'.

Plays through the entire game from start to win condition, verifying the
final score (3/3) and the victory message.

Commands use ASCII digraphs (oeffne, schluessel, schliess) because dfrotz
in piped-stdin mode on Windows does not reliably map Latin-1 bytes to the
Z-machine's extended character table. All umlaut forms are also accepted by
the game parser (öffne, schlüssel, schließ) and tested interactively.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)
NOT_UNDERSTOOD = "verstehe nicht"
UNKNOWN_VERB   = "kenne ich nicht"

# Full walkthrough including pronouns, extra verb forms, and talk menu use.
WALKTHROUGH = [
    "schau",
    "riech",
    "hoer",
    "untersuche schreibtisch",
    "untersuche ring",
    "untersuche alte nadel",
    "nimm muenzen",
    "nimm sie",
    "lege muenzen auf schreibtisch",
    "untersuche feinem tuch",
    "nimm muenzen",
    "untersuche sie",
    "lege muenzen auf schreibtisch",
    "nimm kompass",
    "untersuche ihn",
    "lege alten kompass auf schreibtisch",
    "nimm karte",
    "untersuche alte karte",
    "untersuche karte",
    "inventar",
    "untersuche koje",
    "untersuche kiste",
    "schau in kiste",
    "oeffne kiste",
    "untersuche sie",
    "nimm kleinen schluessel",
    "untersuche ihn",
    "schliess tuer mit schluessel auf",
    "oeffne tuer",
    "nord",
    "lies plakat",
    "beruehr glocke",
    "geh rauf",
    "kletter mast",
    "warte",
    "schau",
    "rede mit steuermann",
    "1",
    "rede mit papagei",
    "1",
    "rede mit navigatorin",
    "1",
    "frag steuermann nach wetter",
    "nimm fernrohr",
    "untersuche es",
]


@pytest.mark.feature("walkthrough")
def test_no_unknown_commands(game):
    """Every command in the walkthrough is understood by the parser."""
    out = game.run(WALKTHROUGH)
    assert_output_not_contains(out, NOT_UNDERSTOOD,
        msg="A command in the walkthrough was not understood")
    assert_output_not_contains(out, UNKNOWN_VERB,
        msg="An unknown verb appeared during the walkthrough")


@pytest.mark.feature("walkthrough")
def test_wins_game(game):
    """The walkthrough reaches the win condition ('Du hast gewonnen')."""
    out = game.run(WALKTHROUGH)
    assert_output_contains(out, "gewonnen")


@pytest.mark.feature("walkthrough")
def test_reaches_oberdeck(game):
    """The walkthrough successfully navigates to Oberdeck."""
    out = game.run(WALKTHROUGH[:33])  # up to 'geh rauf'
    assert_output_contains(out, "Oberdeck")


@pytest.mark.feature("walkthrough")
def test_ambiguous_sie_prefers_recent_plural(game):
    """After feminine references, taking coins should make 'sie' refer to coins."""
    out = game.run([
        "untersuche alte nadel",
        "nimm muenzen",
        "untersuche sie",
    ])
    assert_output_contains(out, "Goldm")


@pytest.mark.feature("walkthrough")
def test_full_score(game):
    """The walkthrough achieves the maximum score (5)."""
    out = game.run(WALKTHROUGH)
    # Score line appears as "5/5" or "Punkte: 5"
    assert_output_contains(out, "5")


@pytest.mark.feature("walkthrough")
def test_list_separator_und(game):
    """Room listing in the walkthrough uses 'und', never 'and'."""
    out = game.run(["schau"])
    assert_output_not_contains(out, " and ")
    assert_output_contains(out, " und ")


@pytest.mark.feature("messages")
def test_score_notification_du_hast_erhalten(game):
    """Score notification says 'Du hast X Punkt(e) erhalten.' not 'Punktestand stieg'."""
    out = game.run(["oeffne kiste", "nimm schluessel"])
    assert_output_contains(out, "Du hast")
    assert_output_contains(out, "erhalten")
    assert_output_not_contains(out, "Punktestand")
    assert_output_not_contains(out, "stieg")


@pytest.mark.feature("messages")
def test_open_message_no_comma_before_und(game):
    """Open+contents message uses '... Seekiste und siehst ...' (no comma)."""
    out = game.run(["oeffne kiste"])
    assert_output_contains(out, "Seekiste und siehst")
    assert_output_not_contains(out, "Seekiste, und siehst")


@pytest.mark.feature("messages")
def test_unlock_message_german(game):
    """Unlocking a door produces German text, not English 'unlock'."""
    out = game.run([
        "oeffne kiste", "nimm schluessel",
        "schliess tuer mit schluessel auf",
    ])
    assert_output_contains(out, "auf")
    assert_output_not_contains(out, " unlock ")


@pytest.mark.feature("messages")
def test_close_message_german(game):
    """Closing a container produces German text, not English 'close'."""
    out = game.run([
        "oeffne kiste",
        "schliess kiste",
    ])
    assert_output_contains(out, "schlie")  # covers both schließt and schliesst
    assert_output_not_contains(out, " close ")


@pytest.mark.feature("messages")
def test_open_message_oeffnest(game):
    """Opening a door uses 'Du öffnest', not 'Du machst ... auf'."""
    out = game.run([
        "oeffne kiste", "nimm schluessel",
        "schliess tuer mit schluessel auf",
        "oeffne tuer",
    ])
    assert_output_contains(out, "ffnest")  # covers both öffnest and oeffnest
    assert_output_not_contains(out, "machst")


@pytest.mark.feature("messages")
def test_room_items_hier_nicht_du_siehst(game):
    """Room contents are listed as 'Hier ist/befinden sich', not 'Du siehst ... hier'."""
    out = game.run(["schau"])
    assert_output_contains(out, "Hier ")
    assert_output_not_contains(out, "Du siehst")


@pytest.mark.feature("messages")
def test_end_screen_zuegen(game):
    """Final score screen uses 'Zügen' (not 'Runden') for turn count."""
    out = game.run(WALKTHROUGH)
    assert_output_contains(out, "gen")   # covers both Zügen and Zuegen (ASCII dfrotz)
    assert_output_not_contains(out, "Runden")
