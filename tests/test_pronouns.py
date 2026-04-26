"""Tests: §2 Pronomensubstitution — deutsche Pronomina im Eingabepuffer.

Verifiziert, dass BeforeParsing (Pass 3) deutsche Pronomina korrekt in die
englischen Entsprechungen umwandelt, die PunyInform intern verwendet:

  Genus           Pronomen           Intern   Slot
  ─────────────────────────────────────────────────
  Maskulin        er / ihn / ihm   → him      himobj
  Feminin         sie              → her      herobj
  Neutrum         es               → it       itobj
  Plural          sie / ihnen      → them     themobj

Alle Tests verwenden ASCII-Eingabe (keine Umlaute) und die ASCII-Digraph-
Varianten, damit dfrotz im piped-stdin-Modus zuverlässig funktioniert.
"""

from __future__ import annotations

import pytest
from PunyTest.asserts import (
    assert_output_contains,
    assert_output_not_contains,
)

NOT_UNDERSTOOD = "verstehe nicht"
UNKNOWN_VERB   = "kenne ich nicht"


# ---------------------------------------------------------------------------
# Hilfsbefehle
# ---------------------------------------------------------------------------

_GET_KEY = ["oeffne kiste", "nimm schluessel"]
_UNLOCK_AND_GOTO_OBERDECK = _GET_KEY + [
    "schliess tuer mit schluessel auf",
    "oeffne tuer", "nord", "rauf",
]


# ---------------------------------------------------------------------------
# Maskulin: "ihn" → him (Akkusativ)
# ---------------------------------------------------------------------------

@pytest.mark.feature("pronouns")
def test_ihn_maskulin_kompass(game):
    """'ihn' nach 'nimm kompass' → examines Kompass (maskulin, himobj)."""
    out = game.run(["nimm kompass", "untersuche ihn"])
    assert_output_contains(out, "Kompass",
        msg="'untersuche ihn' soll Kompass (maskulin) untersuchen")
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("pronouns")
def test_ihn_maskulin_schluessel(game):
    """'ihn' nach 'nimm schluessel' → examines Schlüssel (maskulin, himobj)."""
    out = game.run(_GET_KEY + ["untersuche ihn"])
    assert_output_contains(out, "Messingschl",  # "Messingschlüssel" in UTF-8 or ASCII
        msg="'untersuche ihn' soll Schlüssel untersuchen")
    assert_output_not_contains(out, NOT_UNDERSTOOD)


# ---------------------------------------------------------------------------
# Maskulin: "er" → him (Nominativ/Subjekt-Pronomen)
# ---------------------------------------------------------------------------

@pytest.mark.feature("pronouns")
def test_er_maskulin_kompass(game):
    """'er' (Nom) nach 'nimm kompass' → examines Kompass."""
    out = game.run(["nimm kompass", "untersuche er"])
    assert_output_contains(out, "Kompass",
        msg="'untersuche er' soll Kompass (maskulin) untersuchen")
    assert_output_not_contains(out, NOT_UNDERSTOOD)


# ---------------------------------------------------------------------------
# Feminin: "sie" → her (wenn herobj gesetzt)
# ---------------------------------------------------------------------------

@pytest.mark.feature("pronouns")
def test_sie_feminin_kiste(game):
    """'sie' nach 'oeffne kiste' → examines Seekiste (feminin, herobj)."""
    out = game.run(["oeffne kiste", "untersuche sie"])
    assert_output_contains(out, "Seekiste",
        msg="'untersuche sie' nach 'oeffne kiste' soll Seekiste untersuchen")
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("pronouns")
def test_sie_feminin_tuer(game):
    """'sie' nach 'untersuche tuer' → examines Kajütetür (feminin, herobj)."""
    out = game.run(["untersuche tuer", "untersuche sie"])
    # Description contains 'Eichenholz' (pure ASCII) — unique to Kajüentür
    assert_output_contains(out, "Eichenholz",
        msg="'untersuche sie' soll Kajütentür (feminin) untersuchen")
    assert_output_not_contains(out, NOT_UNDERSTOOD)


# ---------------------------------------------------------------------------
# Plural: "sie" → them (wenn herobj==0 aber themobj gesetzt)
# ---------------------------------------------------------------------------

@pytest.mark.feature("pronouns")
def test_sie_plural_muenzen(game):
    """'sie' nach 'nimm muenzen' → examines Goldmünzen (Plural, themobj)."""
    out = game.run(["nimm muenzen", "untersuche sie"])
    assert_output_contains(out, "Goldm",  # "Goldmünzen" or "Goldmuenzen"
        msg="'untersuche sie' soll Goldmünzen (Plural) untersuchen")
    assert_output_not_contains(out, NOT_UNDERSTOOD)


@pytest.mark.feature("pronouns")
def test_sie_plural_after_previous_feminine_reference(game):
    """After a feminine object was referenced, taking coins should still make 'sie' plural."""
    out = game.run(["untersuche nadel", "nimm muenzen", "untersuche sie"])
    assert_output_contains(out, "Goldm",
        msg="'untersuche sie' should resolve to plural Goldmünzen after taking coins")
    assert_output_not_contains(out, NOT_UNDERSTOOD)


# ---------------------------------------------------------------------------
# Neutrum: "es" → it
# ---------------------------------------------------------------------------

@pytest.mark.feature("pronouns")
def test_es_neutrum_fernrohr(game):
    """'es' nach 'nimm fernrohr' → triggers win condition (Fernrohr, Neutrum, itobj)."""
    out = game.run(_UNLOCK_AND_GOTO_OBERDECK + [
        "talk to steuermann", "1",
        "talk to papagei", "1",
        "talk to navigatorin", "1",
        "nimm fernrohr", "untersuche es",
    ])
    assert_output_contains(out, "gewonnen",
        msg="'untersuche es' soll Fernrohr (Neutrum) untersuchen und Spiel gewinnen")


# ---------------------------------------------------------------------------
# "ihnen" → them (Dativ Plural)
# ---------------------------------------------------------------------------

@pytest.mark.feature("pronouns")
def test_ihnen_plural_muenzen(game):
    """'nimm ihnen' nach 'lege muenzen hin' verwendet ihnen→them korrekt."""
    # Da der Befehl 'nimm ihnen' kein direktes Testszenario hat,
    # testen wir die Tokenisierung: "lege ihnen karte" sollte nicht abstürzen.
    # Pragmatischer Test: nimm muenzen → lege sie ab → nimm ihnen (them)
    out = game.run(["nimm muenzen", "lege muenzen auf schreibtisch", "nimm ihnen"])
    # "nimm ihnen" → "nimm them" → parser versucht Münzen zu nehmen
    assert_output_not_contains(out, NOT_UNDERSTOOD,
        msg="'nimm ihnen' (ihnen→them) soll nicht 'nicht verstanden' auslösen")


# ---------------------------------------------------------------------------
# Pronomen ohne vorher gesetztes Objekt (Fehlverhalten, kein Absturz)
# ---------------------------------------------------------------------------

@pytest.mark.feature("pronouns")
def test_es_ohne_referenz_kein_absturz(game):
    """'untersuche es' ohne vorheriges Neutrum-Objekt → graceful parser message."""
    out = game.run(["untersuche es"])
    # Parser sagt something like "Darauf beziehst du dich nicht" oder "verstehe nicht"
    # Hauptsache: kein Absturz, kein "kenne ich nicht" (Verb muss bekannt sein)
    assert_output_not_contains(out, UNKNOWN_VERB,
        msg="'untersuche es' soll kein unbekanntes Verb auslösen")


@pytest.mark.feature("pronouns")
def test_ihn_ohne_referenz_kein_absturz(game):
    """'untersuche ihn' ohne vorheriges Maskulin-Objekt → graceful parser message."""
    out = game.run(["untersuche ihn"])
    assert_output_not_contains(out, UNKNOWN_VERB,
        msg="'untersuche ihn' soll kein unbekanntes Verb auslösen")
