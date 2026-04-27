! PunyInformDE: German-specific globals
! This file is included by lib/globals.h at the very start, so these
! definitions take precedence over any English defaults in globals.h.
!
! To update from a new PunyInform release, only globals.h needs updating
! — the German overrides here remain separate.

! ---------------------------------------------------------------------------
! German special characters
! The Zcharacter alphabet table is defined in lib/de/dechar.h, which game
! source must include before any string literal (even "Constant Story").
! ASCII and Z3 builds skip the table automatically via #IfV5/#IfNDef USE_ASCII
! guards inside dechar.h.
! ---------------------------------------------------------------------------

! ---------------------------------------------------------------------------
! German parser word constants
! These override the English defaults defined in globals.h.
! ---------------------------------------------------------------------------
Constant ALL_WORD     = 'alles';   ! English: 'all'
Constant EXCEPT_WORD1 = 'ausser';  ! English: 'but'   (außer — digraph)
Constant EXCEPT_WORD2 = 'ohne';    ! English: 'except'
Constant AND_WORD     = 'und';     ! English: 'and'
Constant THEN1__WD    = 'dann';    ! English: 'then'

! ---------------------------------------------------------------------------
! German string constants for is/are
! ---------------------------------------------------------------------------
Constant IS_STR  = "ist ";   ! English: "is "
Constant ARE_STR = "sind ";  ! English: "are "

! Status line labels (override English Score/Moves)
Constant SCORE__TX       = " Punkte: ";
Constant SCORE_SHORT__TX = " Pt:";
Constant MOVES__TX       = " Züge: ";
Constant MOVES_SHORT__TX = " Zg:";

! Suffix printed after room contents list (override " here.^" from grammar.h)
! German prefix functions end with "ist "/"befinden sich ", so no suffix needed
Constant LISTOBJS_ROOM_SUFFIX = ".^";

! ---------------------------------------------------------------------------
! §3 groundwork: grammatical case and adjective properties
! ---------------------------------------------------------------------------
#IfNDef Nom;
Constant Nom = 0;
#EndIf;
#IfNDef Akk;
Constant Akk = 1;
#EndIf;
#IfNDef Dat;
Constant Dat = 2;
#EndIf;

! Current case used by _PrintObjName / article_de helpers.
! Default stays Nominativ for generic object rendering.
Global short_name_case = Nom;

! Last preferred target for ambiguous German "sie": 1=herobj, 2=themobj.
Global de_last_sie_target = 0;

! Optional adjective stem(s) and noun declension marker for §3.
#IfNDef adj;
Property adj;
#EndIf;

! ---------------------------------------------------------------------------
! German string constants (for parser messages)
! ---------------------------------------------------------------------------
Constant SOMETHING_STR      = "etwas";           ! English: "something"
Constant SOMEONE_STR        = "jemanden";        ! English: "someone"
Constant SOMEDIRECTION_STR  = "(eine Richtung)"; ! English: "(some direction)"

! ---------------------------------------------------------------------------
! German abbreviations
! Defining CUSTOM_ABBREVIATIONS prevents globals.h from adding English ones.
! ---------------------------------------------------------------------------
Constant CUSTOM_ABBREVIATIONS;
Abbreviate "Bist du sicher, dass du das ";
Abbreviate " Selbstverliebt wie immer";
Abbreviate "nichts Unerwartetes";
Abbreviate "(zuerst nehme ";
Abbreviate "Entschuldigung,";
Abbreviate "Du kannst ";
Abbreviate "verstehe nicht";
Abbreviate "Du bist ";
Abbreviate " bereits ";
Abbreviate " nichts ";
Abbreviate "Du hast ";
Abbreviate " nicht ";
Abbreviate "etwas ";
Abbreviate "Richtung";
Abbreviate "Punkte";
Abbreviate "Du tr";
Abbreviate " kein";
Abbreviate "[Kommentar";
Abbreviate " dich";
Abbreviate "Inform ";
Abbreviate "estand";
Abbreviate " sein";
Abbreviate " haben";
Abbreviate "halten";
Abbreviate "stehst";

! German string constants for list printing
! Override the English " and " separator used in PrintContents (puny.h).
Constant AND_LIST_STR = " und ";

! ---------------------------------------------------------------------------
! German direction word constants
! Setting EXTRA_DIRECTION_ROW tells globals.h to append a 3rd row of German
! direction words to _direction_dict_words, making bare commands like
! 'nord', 'rauf', 'sued' etc. work as directions.
! ---------------------------------------------------------------------------
Constant EXTRA_DIRECTION_ROW;
Constant DE_NORD   = 'nord';
Constant DE_SUED   = 'sued';
Constant DE_OST    = 'ost';
Constant DE_WEST   = 'west';
Constant DE_RAUF   = 'rauf';
Constant DE_RUNTER = 'runter';
Constant DE_REIN   = 'rein';
Constant DE_RAUS   = 'raus';
#IfDef OPTIONAL_FULL_DIRECTIONS;
Constant DE_NORDOST  = 0;  ! no standard German abbreviation
Constant DE_NORDWEST = 0;
Constant DE_SUEDOST  = 0;
Constant DE_SUEDWEST = 0;
#EndIf;

! German parser extension (enables ja/nein in YesOrNo via Replace directive)
Include "de/parser_de.h";
