! Part of PunyInformDE: Deutsche Artikeltabellen und Druckfunktionen.
!
! Dieses Modul implementiert §1 der Grammatikanalyse: korrekte Artikel
! für alle drei Kasus (Nominativ, Akkusativ, Dativ) und alle vier
! grammatischen Geschlechter (maskulin, feminin, Neutrum, Plural).
!
! === Für Spieleautoren ===
!
! Nach diesem Modul braucht kein Objekt mehr "with article ..." zu
! deklarieren, solange es has female, has neuter oder den Standard
! (maskulin) verwendet. Die Tabelle liefert automatisch den richtigen
! Artikel für alle Kasus:
!
!   Object -> Kiste "Seekiste"          ! hat female → Artikel "eine/einer/die/der..."
!       ...
!       has female, container, openable;   ! kein article: Eigenschaft nötig
!
!   Object -> Schlüssel "kleiner Schlüssel"   ! kein female/neuter → maskulin
!       ...                                   ! kein article: Eigenschaft nötig
!
! Nur bei Ausnahmen wird article gesetzt:
!
!   Object Sonne "Sonne"
!       with article 0,   ! Kein unbestimmter Artikel ("die Sonne", nie "eine Sonne")
!       has female;
!
!   Object Hotel "Hotel"
!       with article "so ein",   ! Ungewöhnliche Form
!       has neuter;
!
! === Für Nachrichten in messages_de.h ===
!
! Verwende folgende Druckfunktionen für grammatisch korrekte Kasus:
!
!   (DE_Der) obj    Nominativ bestimmt   : "der/die/das/die Schlüssel"
!   (DE_Den) obj    Akkusativ bestimmt   : "den/die/das/die Schlüssel"
!   (DE_Dem) obj    Dativ bestimmt       : "dem/der/dem/den Schlüssel"
!   (DE_Ein) obj    Nominativ unbestimmt : "ein/eine/ein/einige Schlüssel"
!   (DE_Einen) obj  Akkusativ unbestimmt : "einen/eine/ein/einige Schlüssel"
!   (DE_Einem) obj  Dativ unbestimmt     : "einem/einer/einem/einigen Schlüssel"
!
! Die (the)/(The) und (a)/(A) Formatzeiger bleiben für Nominativ erhalten.
!
! === Speicherbedarf ===
! DE_DefArticles:   12 Einträge × 2 Bytes = 24 Bytes (Zeiger auf Strings)
! DE_IndefArticles: 12 Einträge × 2 Bytes = 24 Bytes
! Stringliterale: ca. 60 Bytes (geteilt, da Inform kurze Strings optimiert)
!
System_file;

! ---------------------------------------------------------------------------
! DE_Gender -- grammatisches Geschlecht eines Objekts ermitteln.
!
! Gibt zurück:
!   0 = maskulin  (Standard, wenn weder has female noch has neuter)
!   1 = feminin   (has female)
!   2 = Neutrum   (has neuter)
!   3 = Plural    (has pluralname)
! ---------------------------------------------------------------------------
[ DE_Gender p_obj;
    if (p_obj has pluralname) return 3;
    if (p_obj has female)     return 1;
    if (p_obj has neuter)     return 2;
    return 0;  ! maskulin (Standard)
];

! ---------------------------------------------------------------------------
! Bestimmte Artikel: der/die/das/die  (Nominativ/Akkusativ/Dativ × 4 Geschlechter)
!
! Index: case * 4 + gender
!   case:   0 = Nominativ   1 = Akkusativ   2 = Dativ
!   gender: 0 = mask.       1 = fem.        2 = Neut.   3 = Plural
!
!           mask.   fem.    Neut.   Plural
! ---------------------------------------------------------------------------
Array DE_DefArticles -->
    "der"  "die"  "das"  "die"    ! Nominativ (Index 0..3)
    "den"  "die"  "das"  "die"    ! Akkusativ (Index 4..7)
    "dem"  "der"  "dem"  "den"    ! Dativ     (Index 8..11)
;

! ---------------------------------------------------------------------------
! Unbestimmte Artikel: ein/eine/ein/- (Nominativ/Akkusativ/Dativ × 4 Geschlechter)
!
! Plural: 0 = kein unbestimmter Artikel (wird separat behandelt).
!
!           mask.     fem.      Neut.     Plural
! ---------------------------------------------------------------------------
Array DE_IndefArticles -->
    "ein"    "eine"   "ein"    0        ! Nominativ (Index 0..3)
    "einen"  "eine"   "ein"    0        ! Akkusativ (Index 4..7)
    "einem"  "einer"  "einem"  0        ! Dativ     (Index 8..11)
;

! ---------------------------------------------------------------------------
! _DE_IndefArtStr -- gibt den richtigen unbestimmten Artikel als String zurück,
!   unter Berücksichtigung einer optionalen article-Override-Eigenschaft.
!
!   Gibt 0 zurück wenn kein Artikel gedruckt werden soll.
!   Gibt -1 zurück wenn der Plural-Fallback "einige"/"einigen" verwendet wird.
!   Sonst: Zeiger auf Artikelstring.
!
! p_case: 0=Nom, 1=Akk, 2=Dat
! p_plural_dative: true → Plural-Fallback ist "einigen" (Dativ)
! ---------------------------------------------------------------------------
[ _DE_IndefArtStr p_obj p_case p_plural_dative   g s;
    ! Override: article 0 → kein Artikel
    if (p_obj.&article && p_obj.article == 0) return 0;
    ! Override: article "string" → Legacy-Eigenschaft, nur für Nominativ
    if (p_obj.&article && p_obj.article ofclass String) return p_obj.article;
    g = DE_Gender(p_obj);
    ! Plural: kein unbestimmter Artikel → "einige"/"einigen"
    if (g == 3) {
        if (p_plural_dative) return -2;  ! signal: print "einigen"
        return -1;                        ! signal: print "einige"
    }
    s = DE_IndefArticles-->(p_case * 4 + g);
    return s;
];

Constant DE_MODE_DEF   = 0;
Constant DE_MODE_INDEF = 1;
Constant DE_MODE_BARE  = 2;

! ---------------------------------------------------------------------------
! _DE_GetAdjSuffix -- Adjektiv-Endung nach Modus/Kasus/Genus ermitteln.
!   p_mode: DE_MODE_DEF / DE_MODE_INDEF / DE_MODE_BARE
!   p_case: Nom/Akk/Dat
!   p_gender: 0=mask, 1=fem, 2=neut, 3=plural
! ---------------------------------------------------------------------------
[ _DE_GetAdjSuffix p_mode p_case p_gender;
    if (p_mode == DE_MODE_DEF) {
        ! Definiter Artikel (schwache Flexion)
        ! Nom: m/f/n=-e, pl=-en; Akk: m=-en,f/n=-e,pl=-en; Dat: alle -en
        if (p_case == Dat) return "en";
        if (p_case == Akk) {
            if (p_gender == 0 or 3) return "en";
            return "e";
        }
        ! Nom
        if (p_gender == 3) return "en";
        return "e";
    }

    if (p_mode == DE_MODE_INDEF) {
        ! Indefiniter Artikel (gemischte Flexion)
        ! Nom: m=-er,f=-e,n=-es,pl=-en; Akk: m=-en,f=-e,n=-es,pl=-en; Dat: alle -en
        if (p_case == Dat) return "en";
        if (p_case == Akk) {
            if (p_gender == 0 or 3) return "en";
            if (p_gender == 1) return "e";
            return "es";
        }
        ! Nom
        if (p_gender == 0) return "er";
        if (p_gender == 1) return "e";
        if (p_gender == 2) return "es";
        return "en";
    }

    ! Ohne Artikel (starke Flexion)
    ! Nom: m=-er,f=-e,n=-es,pl=-e; Akk: m=-en,f=-e,n=-es,pl=-e; Dat: m=-em,f=-er,n=-em,pl=-en
    if (p_case == Dat) {
        if (p_gender == 0) return "em";
        if (p_gender == 1) return "er";
        if (p_gender == 2) return "em";
        return "en";
    }
    if (p_case == Akk) {
        if (p_gender == 0) return "en";
        if (p_gender == 1) return "e";
        if (p_gender == 2) return "es";
        return "e";
    }
    ! Nom
    if (p_gender == 0) return "er";
    if (p_gender == 1) return "e";
    if (p_gender == 2) return "es";
    return "e";
];

[ _DE_PrintAdjList p_obj p_mode p_case p_gender _i _n _suffix;
    if (p_obj provides adj) {
        _n = p_obj.#adj / WORDSIZE;
        _suffix = _DE_GetAdjSuffix(p_mode, p_case, p_gender);
        for (_i = 0 : _i < _n : _i++) {
            print (string) (p_obj.&adj-->_i), (string) _suffix, " ";
        }
    }
];

[ _DE_PrintDefWithName p_obj p_case p_cap _g _s;
    _g = DE_Gender(p_obj);
    _s = DE_DefArticles-->(p_case * 4 + _g);
    if (_s) {
        if (p_cap) {
            if (p_case == Nom) {
                if (_g == 0) print "Der";
                else if (_g == 1 or 3) print "Die";
                else print "Das";
            } else if (p_case == Akk) {
                if (_g == 0) print "Den";
                else if (_g == 1 or 3) print "Die";
                else print "Das";
            } else {
                if (_g == 0 or 2) print "Dem";
                else if (_g == 1) print "Der";
                else print "Den";
            }
        } else {
            print (string) _s;
        }
        print " ";
    }
    _DE_PrintAdjList(p_obj, DE_MODE_DEF, p_case, _g);
    PrintShortName(p_obj);
];

[ _DE_PrintIndefWithName p_obj p_case _g _s _mode;
    _g = DE_Gender(p_obj);
    _s = _DE_IndefArtStr(p_obj, p_case, (p_case == Dat));
    _mode = DE_MODE_INDEF;

    if (_s == 0) {
        _mode = DE_MODE_BARE;
    } else if (_s == -1) {
        print "einige ";
    } else if (_s == -2) {
        print "einigen ";
    } else {
        print (string) _s; print " ";
        if (p_obj.&article && p_obj.article ofclass String) {
            ! Bei freier String-Überschreibung keine automatische Adjektiv-Flexion erzwingen.
            _mode = -1;
        }
    }

    if (_mode >= 0) _DE_PrintAdjList(p_obj, _mode, p_case, _g);
    PrintShortName(p_obj);
];

[ _DE_PrintObjByForm p_obj p_form p_case;
    if (p_form == FORM_CDEF) { _DE_PrintDefWithName(p_obj, p_case, true);  return; }
    if (p_form == FORM_DEF)  { _DE_PrintDefWithName(p_obj, p_case, false); return; }
    if (p_form == FORM_INDEF) { _DE_PrintIndefWithName(p_obj, p_case); return; }
    PrintShortName(p_obj);
];

! ---------------------------------------------------------------------------
! _DE_PrintIndefWithName -- Hilfsfunktion: unbestimmten Artikel + Name drucken.
! p_case: 0=Nom, 1=Akk, 2=Dat
! ---------------------------------------------------------------------------
[ _DE_PrintIndefWithName_Compat p_obj p_case;
    _DE_PrintIndefWithName(p_obj, p_case);
];

! ---------------------------------------------------------------------------
! Bestimmte Artikel + Name (Druckfunktionen für Spielnachrichten)
! ---------------------------------------------------------------------------

! Nominativ bestimmt: "der Schlüssel / die Kiste / das Fernrohr / die Münzen"
! (entspricht (the) in Nominativ-Position)
[ DE_Der p_obj;
    _DE_PrintDefWithName(p_obj, Nom, false);
];

! Akkusativ bestimmt: "den Schlüssel / die Kiste / das Fernrohr / die Münzen"
[ DE_Den p_obj;
    _DE_PrintDefWithName(p_obj, Akk, false);
];

! Dativ bestimmt: "dem Schlüssel / der Kiste / dem Fernrohr / den Münzen"
[ DE_Dem p_obj;
    _DE_PrintDefWithName(p_obj, Dat, false);
];

! ---------------------------------------------------------------------------
! Unbestimmte Artikel + Name (Druckfunktionen für Spielnachrichten)
! ---------------------------------------------------------------------------

! Nominativ unbestimmt: "ein Schlüssel / eine Kiste / ein Fernrohr / einige Münzen"
[ DE_Ein p_obj;
    _DE_PrintIndefWithName(p_obj, Nom);
];

! Akkusativ unbestimmt: "einen Schlüssel / eine Kiste / ein Fernrohr / einige Münzen"
[ DE_Einen p_obj;
    _DE_PrintIndefWithName(p_obj, Akk);
];

! Dativ unbestimmt: "einem Schlüssel / einer Kiste / einem Fernrohr / einigen Münzen"
[ DE_Einem p_obj;
    _DE_PrintIndefWithName(p_obj, Dat);
];

! ---------------------------------------------------------------------------
! _DE_SubstitutePronouns — §2 Pronomenersetzung (Pass 3 von BeforeParsing).
!
! Hinweis: Diese Funktion ist hier (article_de.h) definiert, nicht in
! parser_de.h, weil sie auf die globalen Variablen herobj/himobj/itobj/themobj
! zugreift. Diese werden erst am Ende von globals.h deklariert, also NACHDEM
! parser_de.h eingebunden wurde. article_de.h wird hingegen von puny.h
! eingebunden, das nach globals.h eingebunden wird — die Variablen sind
! daher hier bereits bekannt.
!
! BeforeParsing (in parser_de.h) ruft _DE_SubstitutePronouns() auf;
! Inform 6 löst Vorwärts-Funktionsreferenzen auf.
!
! Unterstützte Ersetzungen:
!   "er"    (2 Bytes) → "him"   (3 Bytes)  Maskulin Nominativ/Subjekt
!   "ihn"   (3 Bytes) → "him"   (3 Bytes)  Maskulin Akkusativ (in-place)
!   "ihm"   (3 Bytes) → "him"   (3 Bytes)  Maskulin Dativ     (in-place)
!   "sie"   (3 Bytes) → "her"   (3 Bytes)  Feminin  (wenn herobj gesetzt)
!   "sie"   (3 Bytes) → "them"  (4 Bytes)  Plural   (wenn nur themobj gesetzt)
!   "es"    (2 Bytes) → "it"    (2 Bytes)  Neutrum  (in-place)
!   "ihnen" (5 Bytes) → "them"  (4 Bytes)  Dativ Plural (schrumpft um 1)
!
! Nicht ersetzt: "ihr" (Possessivpronomen, mehrdeutig)
!
! Rückgabe: true wenn Ersetzungen vorgenommen wurden, sonst false.
! ---------------------------------------------------------------------------
[ _DE_SubstitutePronouns   _nwords _i _waddr _woff _wlen _blen _j _changed;
    _nwords  = parse->1;
    _changed = false;
    ! Von rechts nach links: Pufferverschiebungen bei früheren Wörtern bleiben gültig
    for (_i = _nwords : _i >= 1 : _i--) {
        if (parse-->(_i + _i - 1) ~= 0) continue;  ! Wort im Wörterbuch → überspringen
        _waddr = WordAddress(_i);
        _wlen  = WordLength(_i);
        _blen  = buffer->1;
        _woff  = _waddr - buffer;  ! Byte-Offset ab Pufferanfang (inkl. 2-Byte-Header)

        ! --- "es" (2 Bytes) → "it" (2 Bytes): in-place ---
        if (_wlen == 2 && _waddr->0 == 'e' && _waddr->1 == 's') {
            buffer->_woff       = 'i';
            buffer->(_woff + 1) = 't';
            _changed = true;
            continue;
        }

        ! --- "er" (2 Bytes) → "him" (3 Bytes): Puffer 1 Byte nach rechts verschieben ---
        if (_wlen == 2 && _waddr->0 == 'e' && _waddr->1 == 'r') {
            if (_blen >= buffer->0) continue;  ! Pufferüberlauf verhindern
            for (_j = _blen + 1 : _j >= _woff + 2 : _j--)
                buffer->(_j + 1) = buffer->_j;
            buffer->_woff       = 'h';
            buffer->(_woff + 1) = 'i';
            buffer->(_woff + 2) = 'm';
            buffer->1 = _blen + 1;
            _changed = true;
            continue;
        }

        ! --- "ihn" (3 Bytes) → "him" (3 Bytes): in-place ---
        if (_wlen == 3 && _waddr->0 == 'i' && _waddr->1 == 'h' && _waddr->2 == 'n') {
            buffer->_woff       = 'h';
            buffer->(_woff + 1) = 'i';
            buffer->(_woff + 2) = 'm';
            _changed = true;
            continue;
        }

        ! --- "ihm" (3 Bytes) → "him" (3 Bytes): in-place (i↔h tauschen) ---
        if (_wlen == 3 && _waddr->0 == 'i' && _waddr->1 == 'h' && _waddr->2 == 'm') {
            buffer->_woff       = 'h';
            buffer->(_woff + 1) = 'i';
            buffer->(_woff + 2) = 'm';
            _changed = true;
            continue;
        }

        ! --- "sie" (3 Bytes) → "her" (3 Bytes) oder "them" (4 Bytes) ---
        if (_wlen == 3 && _waddr->0 == 's' && _waddr->1 == 'i' && _waddr->2 == 'e') {
            if (themobj ~= 0 && (herobj == 0 || de_last_sie_target == 2)) {
                ! Plural bevorzugen, wenn zuletzt ein Plural-Objekt referenziert wurde.
                ! 3→4 Bytes, 1 Byte rechts verschieben.
                if (_blen >= buffer->0) continue;
                for (_j = _blen + 1 : _j >= _woff + 3 : _j--)
                    buffer->(_j + 1) = buffer->_j;
                buffer->_woff       = 't';
                buffer->(_woff + 1) = 'h';
                buffer->(_woff + 2) = 'e';
                buffer->(_woff + 3) = 'm';
                buffer->1 = _blen + 1;
                _changed = true;
            } else if (herobj ~= 0) {
                ! Feminin: "sie" → "her" (in-place, beide 3 Bytes)
                buffer->_woff       = 'h';
                buffer->(_woff + 1) = 'e';
                buffer->(_woff + 2) = 'r';
                _changed = true;
            } else if (themobj ~= 0) {
                ! Nur Plural gesetzt: ebenfalls "them".
                if (_blen >= buffer->0) continue;
                for (_j = _blen + 1 : _j >= _woff + 3 : _j--)
                    buffer->(_j + 1) = buffer->_j;
                buffer->_woff       = 't';
                buffer->(_woff + 1) = 'h';
                buffer->(_woff + 2) = 'e';
                buffer->(_woff + 3) = 'm';
                buffer->1 = _blen + 1;
                _changed = true;
            }
            ! Weder herobj noch themobj gesetzt: "sie" unverändert lassen
            continue;
        }

        ! --- "ihnen" (5 Bytes) → "them" (4 Bytes): überschreiben + 1 Byte links ---
        if (_wlen == 5 && _waddr->0 == 'i' && _waddr->1 == 'h' &&
                          _waddr->2 == 'n' && _waddr->3 == 'e' && _waddr->4 == 'n') {
            buffer->_woff       = 't';
            buffer->(_woff + 1) = 'h';
            buffer->(_woff + 2) = 'e';
            buffer->(_woff + 3) = 'm';
            ! Bytes nach "ihnen" um 1 nach links schieben
            for (_j = _woff + 4 : _j <= _blen : _j++)
                buffer->_j = buffer->(_j + 1);
            buffer->1 = _blen - 1;
            _changed = true;
            continue;
        }
    }
    return _changed;
];
