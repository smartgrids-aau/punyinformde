! Part of PunyInformDE: German localisation of PunyInform.
! This file replaces messages.h with German translations.
!
! Note: Zcharacter declarations for German special characters are in globals.h.
!
System_file;

!
! Simple string messages
!

#Ifndef MSG_TAKE_YOURSELF;
Constant MSG_TAKE_YOURSELF "Selbstverliebt wie immer.";
#EndIf;
#Ifndef MSG_TAKE_NO_CAPACITY;
Constant MSG_TAKE_NO_CAPACITY "Du hältst schon zu viele Sachen.";
#EndIf;
#Ifndef MSG_TAKE_DEFAULT;
Constant MSG_TAKE_DEFAULT "Genommen.";
#EndIf;
#Ifndef MSG_DRINK_NOTHING_SUITABLE;
Constant MSG_DRINK_NOTHING_SUITABLE "Hier gibt es nichts zu trinken.";
#EndIf;
#Ifndef MSG_DROP_DROPPED;
Constant MSG_DROP_DROPPED "Fallengelassen.";
#EndIf;
#Ifndef MSG_THROW_ANIMATE;
Constant MSG_THROW_ANIMATE "Sinnlos.";
#Endif;
#Ifndef MSG_THROW_DEFAULT;
Constant MSG_THROW_DEFAULT "Im entscheidenden Moment fehlen dir die Nerven.";
#Endif;
#Ifndef MSG_SMELL_DEFAULT;
Constant MSG_SMELL_DEFAULT "Du riechst nichts Unerwartetes.";
#Endif;
#Ifndef MSG_LISTEN_DEFAULT;
Constant MSG_LISTEN_DEFAULT "Du hörst nichts Unerwartetes.";
#Endif;
#Ifndef MSG_TELL_PLAYER;
Constant MSG_TELL_PLAYER "Du redest ein Weilchen mit dir selbst.";
#Endif;
#Ifndef MSG_TELL_DEFAULT;
Constant MSG_TELL_DEFAULT "Keine Reaktion.";
#Endif;
#Ifndef MSG_ENTER_ALREADY;
Constant MSG_ENTER_ALREADY "Aber du bist schon da!";
#Endif;
#Ifndef MSG_EXIT_ALREADY;
Constant MSG_EXIT_ALREADY "Aber du bist im Moment in nichts drin!";
#Endif;
#Ifndef MSG_EXIT_NOT_ON;
Constant MSG_EXIT_NOT_ON "Du bist da nicht drauf.";
#Endif;
#Ifndef MSG_EXIT_NOT_IN;
Constant MSG_EXIT_NOT_IN "Du bist da nicht drinnen.";
#Endif;
#Ifndef MSG_INVENTORY_EMPTY;
Constant MSG_INVENTORY_EMPTY "Du stehst mit leeren Händen da.";
#Endif;
#Ifndef MSG_GO_CANT_GO;
Constant MSG_GO_CANT_GO "Da kannst du nicht hingehen.";
#Endif;
#Ifndef MSG_SAVE_DEFAULT;
Constant MSG_SAVE_DEFAULT "Ok.";
#Endif;
#Ifndef MSG_INSERT_ITSELF;
Constant MSG_INSERT_ITSELF "Man kann nichts in sich selbst hineinlegen.";
#Endif;
#Ifndef MSG_PUTON_ITSELF;
Constant MSG_PUTON_ITSELF "Man kann nicht etwas auf sich selbst stellen.";
#Endif;
#Ifndef MSG_ATTACK_DEFAULT;
Constant MSG_ATTACK_DEFAULT "Gewalt ist in diesem Fall nicht die Antwort.";
#Endif;
#Ifndef MSG_FILL_NO_WATER;
Constant MSG_FILL_NO_WATER "Aber hier gibt es kein Wasser zum Tragen.";
#EndIf;
#Ifndef MSG_DIG_NO_USE;
Constant MSG_DIG_NO_USE "Graben bringt hier nichts.";
#EndIf;
#Ifndef MSG_WAIT_DEFAULT;
Constant MSG_WAIT_DEFAULT "Nichts passiert.";
#EndIf;
#Ifndef MSG_TOUCH_DEFAULT;
Constant MSG_TOUCH_DEFAULT "Du ertastest nichts Unerwartetes.";
#EndIf;
#Ifndef MSG_PUSHDIR_DEFAULT;
Constant MSG_PUSHDIR_DEFAULT "Ist das das Beste, was dir einfällt?";
#EndIf;
#Ifndef MSG_JUMP;
Constant MSG_JUMP "Du springst auf der Stelle.";
#EndIf;
#Ifndef MSG_REMOVE_DEFAULT;
Constant MSG_REMOVE_DEFAULT "Entfernt.";
#EndIf;
#Ifndef MSG_SEARCH_NOTHING_SPECIAL;
Constant MSG_SEARCH_NOTHING_SPECIAL "Du findest nichts Besonderes.";
#EndIf;
#Ifndef MSG_OOPS_DEFAULT;
Constant MSG_OOPS_DEFAULT "Denk dir nichts dabei.";
#EndIf;
#Ifndef MSG_PARSER_ONLY_TO_ANIMATE;
Constant MSG_PARSER_ONLY_TO_ANIMATE "Das kann man nur mit etwas Lebendigem machen.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_VERB;
Constant MSG_PARSER_NOT_MULTIPLE_VERB "Man kann mit diesem Verb nicht mehrere Objekte verwenden.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_DIRS;
Constant MSG_PARSER_NOT_MULTIPLE_DIRS "Du kannst nicht mehrere Richtungen verwenden.";
#EndIf;
#Ifndef MSG_PARSER_BAD_NUMBER;
Constant MSG_PARSER_BAD_NUMBER "Ich habe diese Zahl nicht verstanden.";
#EndIf;
#Ifndef MSG_PARSER_NO_INPUT;
Constant MSG_PARSER_NO_INPUT "Wie bitte?";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_SENTENCE;
Constant MSG_PARSER_UNKNOWN_SENTENCE "Ich verstehe diesen Satz nicht.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_VERB;
Constant MSG_PARSER_UNKNOWN_VERB "Dieses Verb kenne ich nicht.";
#EndIf;
#Ifndef MSG_PARSER_CANT_DISAMBIGUATE;
Constant MSG_PARSER_CANT_DISAMBIGUATE "Ich verstehe immer noch nicht, worauf du anspielst.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_PERSON;
Constant MSG_PARSER_UNKNOWN_PERSON "Ich kann nicht erkennen, auf wen du dich beziehst.";
#EndIf;
#Ifndef MSG_PARSER_CANT_OOPS;
Constant MSG_PARSER_CANT_OOPS "Tut mir leid, das kann nicht korrigiert werden.";
#EndIf;
#Ifndef MSG_PARSER_COMPLEX_AGAIN;
Constant MSG_PARSER_COMPLEX_AGAIN "Der Befehl 'erneut' muss in einer neuen Eingabezeile stehen.^";
#EndIf;
#Ifndef MSG_PARSER_NOTHING_TO_AGAIN;
Constant MSG_PARSER_NOTHING_TO_AGAIN "Das kannst du kaum wiederholen.";
#EndIf;
#Ifndef MSG_PARSER_BE_MORE_SPECIFIC;
Constant MSG_PARSER_BE_MORE_SPECIFIC "Du musst genauer sein.";
#EndIf;
#Ifndef MSG_PARSER_NO_MULTIPLES_FOR_NPC;
Constant MSG_PARSER_NO_MULTIPLES_FOR_NPC "Du kannst nur auf einzelne Objekte verweisen, wenn du mit anderen redest.";
#EndIf;
#IfnDef OPTIONAL_NO_DARKNESS;
#IfnDef MSG_NOW_DARK;
Constant MSG_NOW_DARK "^Es ist nun stockdunkel hier.";
#EndIf;
#EndIf;

#IfDef OPTIONAL_FULL_SCORE;
#IfDef OPTIONAL_SCORED;
#Ifndef MSG_FULLSCORE_OBJECTS;
Constant MSG_FULLSCORE_OBJECTS "finde diverse Objekte";
#EndIf;
#Ifndef MSG_FULLSCORE_ROOMS;
Constant MSG_FULLSCORE_ROOMS "besuch verschiedene Orte";
#EndIf;
#EndIf;
#Ifndef MSG_FULLSCORE_ACTIONS;
Constant MSG_FULLSCORE_ACTIONS "mache bemerkenswerte Aktionen";
#EndIf;
#EndIf;

!
! complex messages (enumerated)
!

! Note, we can only use id 2-999
Default MSG_CLOSE_YOU_CANT = 2;
Default MSG_ENTER_YOU_CANT = 3;
Default MSG_EXAMINE_NOTHING_SPECIAL = 4;
Default MSG_TAKE_ANIMATE = 5;
Default MSG_TAKE_PLAYER_PARENT = 6;
Default MSG_EAT_ANIMATE = 7;
Default MSG_DROP_NOT_HOLDING = 8;
Default MSG_OPEN_DEFAULT = 9;
Default MSG_CLOSE_DEFAULT = 10;
Default MSG_LOOK_BEFORE_ROOMNAME  = 11;
Default MSG_SHOW_NOT_HOLDING = 12;
Default MSG_SHOW_DEFAULT = 13;
Default MSG_GIVE_NOT_HOLDING = 14;
Default MSG_GIVE_DEFAULT = 15;
Default MSG_ASKFOR_DEFAULT = 16;
Default MSG_ASKTO_DEFAULT = 17;
Default MSG_ENTER_DEFAULT = 18;
Default MSG_EXIT_FIRST_LEAVE = 19;
Default MSG_ENTER_NOT_OPEN = 20;
Default MSG_EXIT_NOT_OPEN = 21;
Default MSG_EXIT_DEFAULT = 22;
Default MSG_INVENTORY_DEFAULT = 23;
Default MSG_GO_FIRST_LEAVE = 24;
Default MSG_GIVE_PLAYER 25;
Default MSG_SAVE_FAILED 26;
Default MSG_RESTORE_FAILED 27;
Default MSG_RESTART_FAILED 28;
Default MSG_INSERT_DEFAULT 29;
Default MSG_INSERT_NOT_OPEN 30;
Default MSG_ASK_DEFAULT 31;
Default MSG_ANSWER_DEFAULT 32;
Default MSG_RESTART_RESTORE_OR_QUIT 33;
Default MSG_AREYOUSUREQUIT 34;
Default MSG_WEAR_ALREADY_WORN 35;
Default MSG_WEAR_NOT_CLOTHING 36;
Default MSG_WEAR_NOT_HOLDING 37;
Default MSG_WEAR_DEFAULT 38;
Default MSG_INSERT_ALREADY 39;
Default MSG_INSERT_NO_ROOM 40;
Default MSG_PUTON_ALREADY 41;
Default MSG_PUTON_NO_ROOM 42;
Default MSG_PUTON_DEFAULT 43;
Default MSG_GO_DOOR_CLOSED 44;
Default MSG_SWITCH_ON_NOT_SWITCHABLE 45;
Default MSG_SWITCH_OFF_NOT_SWITCHABLE 46;
Default MSG_SWITCH_ON_ON 47;
Default MSG_SWITCH_OFF_NOT_ON 48;
Default MSG_SWITCH_ON_DEFAULT 49;
Default MSG_SWITCH_OFF_DEFAULT 50;
Default MSG_PUSH_STATIC 51;
Default MSG_PULL_STATIC 52;
Default MSG_TURN_STATIC 53;
Default MSG_PUSH_SCENERY 54;
Default MSG_PULL_SCENERY 55;
Default MSG_TURN_SCENERY 56;
Default MSG_PUSH_ANIMATE 57;
Default MSG_PULL_ANIMATE 58;
Default MSG_TURN_ANIMATE 59;
Default MSG_TURN_DEFAULT 60;
Default MSG_PUSH_DEFAULT 61;
Default MSG_PULL_DEFAULT 62;
Default MSG_YOU_HAVE_WON 63;
Default MSG_YOU_HAVE_DIED 64;
Default MSG_OPEN_YOU_CANT = 65;
Default MSG_PARSER_NOTHING_TO_VERB 66;
Default MSG_TOUCHABLE_FOUND_CLOSED 67;
Default MSG_CONSULT_NOTHING_INTERESTING 68;
Default MSG_CUT_NO_USE 69;
Default MSG_SACK_PUTTING 70;
Default MSG_LOCK_NOT_A_LOCK 71;
Default MSG_LOCK_ALREADY_LOCKED 72;
Default MSG_LOCK_CLOSE_FIRST 73;
Default MSG_LOCK_KEY_DOESNT_FIT 74;
Default MSG_LOCK_DEFAULT 75;
Default MSG_DISROBE_NOT_WEARING 76;
Default MSG_DISROBE_DEFAULT 77;
Default MSG_REMOVE_NOT_HERE 79;
Default MSG_SEARCH_IN_IT_ISARE 80;
Default MSG_SEARCH_ON_IT_ISARE 81;
Default MSG_SEARCH_EMPTY 82;
Default MSG_SEARCH_NOTHING_ON 83;
Default MSG_SEARCH_CANT_SEE_CLOSED 84;
Default MSG_EAT_DEFAULT = 85;
#Ifdef OPTIONAL_FULL_SCORE;
Default MSG_FULLSCORE_START 86;
Default MSG_FULLSCORE_END 87;
#Endif;
Default MSG_SCORE_DEFAULT 88;
Default MSG_UNLOCK_NOT_A_LOCK 89;
Default MSG_UNLOCK_ALREADY_UNLOCKED 90;
Default MSG_UNLOCK_KEY_DOESNT_FIT 91;
Default MSG_UNLOCK_DEFAULT 92;
Default MSG_ENTER_BAD_LOCATION 93;
Default MSG_PROMPT 94;
#Ifndef OPTIONAL_NO_DARKNESS;
Default MSG_EXAMINE_DARK 95;
Default MSG_SEARCH_DARK 96;
#Endif;
Default MSG_EXAMINE_ONOFF 97;
Default MSG_ORDERS_WONT 98;
Default MSG_AUTO_TAKE 99;
Default MSG_AUTO_DISROBE = 100;
Default MSG_PARSER_PARTIAL_MATCH = 101;
Default MSG_TAKE_BELONGS 102;
Default MSG_TAKE_PART_OF 103;
Default MSG_TAKE_NOT_AVAILABLE 104;
Default MSG_PARSER_CONTAINER_ISNT_OPEN 105;
Default MSG_PARSER_NOT_HOLDING 106;
Default MSG_PARSER_CANT_TALK 107;
Default MSG_WAVE_NOTHOLDING 108;
Default MSG_JUMP_OVER 109;
Default MSG_TIE_DEFAULT 110;
Default MSG_CLOSE_NOT_OPEN 111;
Default MSG_RUB_DEFAULT 112;
Default MSG_SQUEEZE_DEFAULT 113;
Default MSG_EXAMINE_CLOSED 114;
Default MSG_EMPTY_IS_CLOSED 115; ! Only used from extended verbset, but same message also used in basic set.
Default MSG_PARSER_NO_NEED_REFER_TO 116;
Default MSG_PARSER_DONT_UNDERSTAND_WORD 117;
Default MSG_INSERT_NOT_CONTAINER 118;
Default MSG_TRANSFER_ALREADY 119;
Default MSG_YES_OR_NO 120;
Default MSG_RESTART_CONFIRM 121;
#Ifndef NO_SCORE;
Default MSG_PARSER_NEW_SCORE 122;
#Endif;
Default MSG_CLIMB_ANIMATE 123;
Default MSG_CLIMB_DEFAULT 124;
Default MSG_PARSER_BAD_PATTERN_PREFIX 125;
Default MSG_PARSER_BAD_PATTERN_SUFFIX 126;
Default MSG_TAKE_ALREADY_HAVE 127;
Default MSG_SHOUT_DEFAULT 128;
Default MSG_SHOUTAT_DEFAULT 129;
Default MSG_INSERT_ANIMATE 130;
Default MSG_PUTON_ANIMATE 131;
Default MSG_LOOKMODE_NORMAL 132;
Default MSG_LOOKMODE_LONG 133;
Default MSG_LOOKMODE_SHORT 134;
Default MSG_AUTO_TAKE_NOT_HELD = 135;
Default MSG_AUTO_DISROBE_WORN = 136;
Default MSG_TAKE_SCENERY = 137;
Default MSG_TAKE_STATIC = 138;
Default MSG_EAT_INEDIBLE = 139;
Default MSG_OPEN_ALREADY = 140;
Default MSG_OPEN_LOCKED = 141;
Default MSG_PUTON_NOT_SUPPORTER = 142;
Default MSG_PARSER_NO_IT = 143;
Default MSG_PARSER_CANT_SEE_IT = 144;
Default MSG_NOTIFY_ON = 145;
Default MSG_NOTIFY_OFF = 146;
Default MSG_ENTER_HELD 147;
Default MSG_PARSER_NOSUCHTHING 148;
Default MSG_SHOUT_NOSUCHTHING 149;

#IfDef OPTIONAL_PROVIDE_UNDO_FINAL;
#Ifndef MSG_UNDO_NOTHING_DONE;
Constant MSG_UNDO_NOTHING_DONE "[Man kann nicht ~rückgängig machen~, was nicht getan wurde!]";
#EndIf;
#Ifndef MSG_UNDO_NOT_PROVIDED;
Constant MSG_UNDO_NOT_PROVIDED "[Ihr Interpreter bietet kein ~rückgängig machen~ an.]";
#EndIf;
#Ifndef MSG_UNDO_FAILED;
Constant MSG_UNDO_FAILED "~Rückgängig machen~ fehlgeschlagen.";
#EndIf;
#Ifndef MSG_UNDO_DONE;
Constant MSG_UNDO_DONE "Vorherigen Zug rückgängig gemacht.";
#EndIf;
#EndIf;

#Ifndef MSG_COMMENT_TRANSCRIPT;
Constant MSG_COMMENT_TRANSCRIPT "[Kommentar aufgezeichnet]^";
#EndIf;
#Ifndef MSG_COMMENT_NO_TRANSCRIPT;
#ifdef OPTIONAL_EXTENDED_METAVERBS;
Constant MSG_COMMENT_NO_TRANSCRIPT "[Kommentar nicht aufgezeichnet. Um Kommentare aufzuzeichnen, starte ein Transkript.]^";
#IfNot;
Constant MSG_COMMENT_NO_TRANSCRIPT "[Kommentar nicht aufgezeichnet. Dieses Spiel unterstützt keine Transkripte.]^";
#EndIf;
#EndIf;

#IfDef OPTIONAL_EXTENDED_VERBSET;
#Ifndef MSG_BURN_DEFAULT;
Constant MSG_BURN_DEFAULT "Dieser gewagte Akt wird wenig bringen.";
#EndIf;
#Ifndef MSG_BUY_DEFAULT;
Constant MSG_BUY_DEFAULT "Es wird nichts verkauft.";
#EndIf;
#Ifndef MSG_EMPTY_WOULDNT_ACHIEVE;
Constant MSG_EMPTY_WOULDNT_ACHIEVE "Das wird kaum etwas leeren.";
#EndIf;
#Ifndef MSG_RHETORICAL_QUESTION;
Constant MSG_RHETORICAL_QUESTION "Das war eine rhetorische Frage.";
#EndIf;
#Ifndef MSG_PRAY_DEFAULT;
Constant MSG_PRAY_DEFAULT "Dein Gebet hat keine praktischen Auswirkungen.";
#EndIf;
#Ifndef MSG_SING_DEFAULT;
Constant MSG_SING_DEFAULT "Dein Gesang ist schrecklich.";
#EndIf;
#Ifndef MSG_SLEEP_DEFAULT;
Constant MSG_SLEEP_DEFAULT "Du fühlst dich nicht besonders müde.";
#EndIf;
#Ifndef MSG_SORRY_DEFAULT;
Constant MSG_SORRY_DEFAULT "Oh, du musst dich nicht entschuldigen.";
#EndIf;
#Ifndef MSG_SQUEEZE_YOURSELF;
Constant MSG_SQUEEZE_YOURSELF "Behalte deine Hände bei dir.";
#EndIf;
#Ifndef MSG_SWIM_DEFAULT;
Constant MSG_SWIM_DEFAULT "Es gibt nicht genug Wasser, um darin zu schwimmen.";
#EndIf;
#Ifndef MSG_SWING_DEFAULT;
Constant MSG_SWING_DEFAULT "Hier gibt es nichts Sinnvolles zum Schaukeln.";
#EndIf;
#Ifndef MSG_TASTE_DEFAULT;
Constant MSG_TASTE_DEFAULT "Du schmeckst nichts Unerwartetes.";
#EndIf;
#Ifndef MSG_THINK_DEFAULT;
Constant MSG_THINK_DEFAULT "Das ist eine gute Idee.";
#EndIf;
#Ifndef MSG_WAVEHANDS_DEFAULT;
Constant MSG_WAVEHANDS_DEFAULT "Du winkst und kommst dir etwas blöd vor.";
#EndIf;
#Ifndef MSG_WAKE_DEFAULT;
Constant MSG_WAKE_DEFAULT "Die schreckliche Wahrheit ist, dass dies kein Traum ist.";
#Endif;
#Ifndef MSG_WAKEOTHER_DEFAULT;
Constant MSG_WAKEOTHER_DEFAULT "Das erscheint unsinnig.";
#Endif;
#Ifndef MSG_KISS_PLAYER;
Constant MSG_KISS_PLAYER "Wenn du glaubst, dass das hilft.";
#Endif;
#Ifndef MSG_KISS_DEFAULT;
Constant MSG_KISS_DEFAULT "Konzentriere dich auf das Spiel.";
#Endif;
#Ifndef MSG_MILD_DEFAULT;
Constant MSG_MILD_DEFAULT "Durchaus.";
#EndIf;
#Ifndef MSG_STRONG_DEFAULT;
Constant MSG_STRONG_DEFAULT "Echte Abenteurer verwenden solche Begriffe nicht.";
#EndIf;

Default MSG_BLOW_DEFAULT 200;
Default MSG_WAVE_DEFAULT 201;
Default MSG_EMPTY_ALREADY_EMPTY 202;
Default MSG_SET_DEFAULT 203;
Default MSG_SET_TO_DEFAULT 204;
Default MSG_EMPTY_NOT_CONTAINER 205;
#EndIf;


#Iffalse MSG_PUSH_DEFAULT < 1000;
#Iffalse MSG_PULL_DEFAULT < 1000;
#Iffalse MSG_TURN_DEFAULT < 1000;
Constant SKIP_MSG_PUSH_DEFAULT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_STATIC < 1000;
#Iffalse MSG_PULL_STATIC < 1000;
#Iffalse MSG_TURN_STATIC < 1000;
#Iffalse MSG_TAKE_STATIC < 1000;
Constant SKIP_MSG_PUSH_STATIC;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_SCENERY < 1000;
#Iffalse MSG_PULL_SCENERY < 1000;
#Iffalse MSG_TURN_SCENERY < 1000;
Constant SKIP_MSG_PUSH_SCENERY;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_ANIMATE < 1000;
#Iffalse MSG_PULL_ANIMATE < 1000;
#Iffalse MSG_TURN_ANIMATE < 1000;
#Iffalse MSG_CLIMB_ANIMATE < 1000;
Constant SKIP_MSG_PUSH_ANIMATE;
#Endif;
#Endif;
#Endif;
#Endif;


#Iffalse MSG_DROP_NOT_HOLDING < 1000;
#Iffalse MSG_SHOW_NOT_HOLDING < 1000;
#Iffalse MSG_GIVE_NOT_HOLDING < 1000;
#Iffalse MSG_WEAR_NOT_HOLDING < 1000;
Constant SKIP_MSG_DROP_NOT_HOLDING;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_OPEN_YOU_CANT < 1000;
#Iffalse MSG_CLOSE_YOU_CANT < 1000;
#Iffalse MSG_ENTER_YOU_CANT < 1000;
#Iffalse MSG_LOCK_NOT_A_LOCK < 1000;
#Iffalse MSG_UNLOCK_NOT_A_LOCK < 1000;
#Iffalse MSG_WEAR_NOT_CLOTHING < 1000;
Constant SKIP_MSG_OPEN_YOU_CANT;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_TAKE_ANIMATE < 1000;
#Iffalse MSG_EAT_ANIMATE < 1000;
Constant SKIP_MSG_TAKE_ANIMATE;
#Endif;
#Endif;

#Iffalse MSG_TAKE_PLAYER_PARENT < 1000;
#Iffalse MSG_GO_FIRST_LEAVE < 1000;
#Iffalse MSG_EXIT_FIRST_LEAVE < 1000;
Constant SKIP_MSG_TAKE_PLAYER_PARENT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CLOSE_DEFAULT < 1000;
#Iffalse MSG_ENTER_DEFAULT < 1000;
#Iffalse MSG_LOCK_DEFAULT < 1000;
#Iffalse MSG_UNLOCK_DEFAULT < 1000;
#Iffalse MSG_EXIT_DEFAULT < 1000;
Constant SKIP_MSG_CLOSE_DEFAULT;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_GIVE_DEFAULT < 1000;
#Iffalse MSG_SHOW_DEFAULT < 1000;
Constant SKIP_MSG_GIVE_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_ASKFOR_DEFAULT < 1000;
#Iffalse MSG_ASKTO_DEFAULT < 1000;
#Iffalse MSG_ORDERS_WONT < 1000;
Constant SKIP_MSG_ASKFOR_DEFAULT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_ENTER_NOT_OPEN < 1000;
#Iffalse MSG_EXIT_NOT_OPEN < 1000;
#Iffalse MSG_INSERT_NOT_OPEN < 1000;
#Iffalse MSG_GO_DOOR_CLOSED < 1000;
#Iffalse MSG_EMPTY_IS_CLOSED < 1000;
Constant SKIP_MSG_ENTER_NOT_OPEN;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_GIVE_PLAYER < 1000;
#Iffalse MSG_TAKE_ALREADY_HAVE < 1000;
Constant SKIP_MSG_GIVE_PLAYER;
#Endif;
#Endif;

#Iffalse MSG_SAVE_FAILED < 1000;
#Iffalse MSG_RESTORE_FAILED < 1000;
#Iffalse MSG_RESTART_FAILED < 1000;
Constant SKIP_MSG_SAVE_FAILED;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_ALREADY < 1000;
#Iffalse MSG_PUTON_ALREADY < 1000;
#Iffalse MSG_TRANSFER_ALREADY < 1000;
Constant SKIP_MSG_INSERT_ALREADY;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_ANIMATE < 1000;
#Iffalse MSG_PUTON_ANIMATE < 1000;
Constant SKIP_MSG_INSERT_ANIMATE;
#Endif;
#Endif;

#Iffalse MSG_INSERT_NO_ROOM < 1000;
#Iffalse MSG_PUTON_NO_ROOM < 1000;
Constant SKIP_MSG_INSERT_NO_ROOM;
#Endif;
#Endif;

#Iffalse MSG_ASK_DEFAULT < 1000;
#Iffalse MSG_ANSWER_DEFAULT < 1000;
#Iffalse MSG_SHOUT_DEFAULT < 1000;
#Iffalse MSG_SHOUTAT_DEFAULT < 1000;
Constant SKIP_MSG_ASK_DEFAULT;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_SWITCH_ON_NOT_SWITCHABLE < 1000;
#Iffalse MSG_SWITCH_OFF_NOT_SWITCHABLE < 1000;
Constant SKIP_MSG_SWITCH_ON_NOT_SWITCHABL;
#Endif;
#Endif;

#Iffalse MSG_SWITCH_ON_ON < 1000;
#Iffalse MSG_SWITCH_OFF_NOT_ON < 1000;
Constant SKIP_MSG_SWITCH_ON_ON;
#Endif;
#Endif;

#Iffalse MSG_SWITCH_ON_DEFAULT < 1000;
#Iffalse MSG_SWITCH_OFF_DEFAULT < 1000;
Constant SKIP_MSG_SWITCH_ON_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_PARSER_NOT_HOLDING < 1000;
#Iffalse MSG_AUTO_TAKE_NOT_HELD < 1000;
#Iffalse MSG_WAVE_NOTHOLDING < 1000;
Constant SKIP_MSG_PARSER_NOT_HOLDING;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CLOSE_NOT_OPEN < 1000;
#Iffalse MSG_TOUCHABLE_FOUND_CLOSED < 1000;
#Iffalse MSG_PARSER_CONTAINER_ISNT_OPEN < 1000;
Constant SKIP_MSG_CLOSE_NOT_OPEN;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CUT_NO_USE < 1000;
#Iffalse MSG_JUMP_OVER < 1000;
#Iffalse MSG_TIE_DEFAULT < 1000;
#Iffalse MSG_CLIMB_DEFAULT < 1000;
Constant SKIP_MSG_CUT_NO_USE;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_LOCK_ALREADY_LOCKED < 1000;
#Iffalse MSG_UNLOCK_ALREADY_UNLOCKED < 1000;
Constant SKIP_MSG_LOCK_ALREADY_LOCKED;
#Endif;
#Endif;

#Iffalse MSG_LOCK_KEY_DOESNT_FIT < 1000;
#Iffalse MSG_UNLOCK_KEY_DOESNT_FIT < 1000;
Constant SKIP_MSG_LOCK_KEY_DOESNT_FIT;
#Endif;
#Endif;

#Iffalse MSG_RUB_DEFAULT < 1000;
#Iffalse MSG_SQUEEZE_DEFAULT < 1000;
Constant SKIP_MSG_RUB_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_LOOKMODE_NORMAL < 1000;
#Iffalse MSG_LOOKMODE_LONG < 1000;
#Iffalse MSG_LOOKMODE_SHORT < 1000;
Constant SKIP_MSG_LOOKMODE;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_NOT_CONTAINER < 1000;
#Ifndef MSG_EMPTY_NOT_CONTAINER;
Constant SKIP_MSG_INSERT_NOT_CONTAINER;
#Ifnot;
#Iffalse MSG_EMPTY_NOT_CONTAINER < 1000;
Constant SKIP_MSG_INSERT_NOT_CONTAINER;
#Endif;
#Endif;
#Endif;

#Ifndef OPTIONAL_NO_SCORE;
#Iffalse MSG_NOTIFY_ON < 1000;
#Iffalse MSG_NOTIFY_OFF < 1000;
Constant SKIP_MSG_NOTIFY_ON;
#Endif;
#Endif;
#Endif;

#Ifndef OPTIONAL_NO_DARKNESS;
#Iffalse MSG_EXAMINE_DARK < 1000;
#Iffalse MSG_SEARCH_DARK < 1000;
Constant SKIP_MSG_EXAMINE_DARK;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PARSER_NOSUCHTHING < 1000;
#Iffalse MSG_SHOUT_NOSUCHTHING < 1000;
Constant SKIP_MSG_PARSER_NOSUCHTHING;
#Endif;
#Endif;

[ _PrintMsg p_msg p_arg_1 p_arg_2;
	if(IsAString(p_msg))
		print_ret (string) p_msg;

#Ifdef LibraryMessages;
	if(p_msg > 999) {
		return LibraryMessages(p_msg, p_arg_1, p_arg_2);
	}
#Endif;

	! Not a string, there should be code for the message here
	switch(p_msg) {
#IfTrue MSG_PROMPT < 1000;
	MSG_PROMPT:
		print "> ";
		rtrue;
#EndIf;
#Iftrue MSG_LOOK_BEFORE_ROOMNAME < 1000;
	MSG_LOOK_BEFORE_ROOMNAME:
		! what to write at first when describing a room. Can be used to
		! add a newline, but default is to write nothing.
		!@new_line;
#Endif;
#Iftrue MSG_TAKE_SCENERY < 1000;
	MSG_TAKE_SCENERY:
		print_ret (CTheyreorThats) noun, " ist nicht portabel.";
#EndIf;
#Ifndef SKIP_MSG_PUSH_DEFAULT;
	MSG_PUSH_DEFAULT, MSG_PULL_DEFAULT, MSG_TURN_DEFAULT:
		"Es passiert nichts Offensichtliches.";
#Endif;
#Ifndef SKIP_MSG_PUSH_STATIC;
	MSG_PUSH_STATIC, MSG_PULL_STATIC, MSG_TURN_STATIC, MSG_TAKE_STATIC:
		print_ret (CTheyreorThats) noun, " ist fixiert.";
#Endif;
#Ifndef SKIP_MSG_PUSH_SCENERY;
	MSG_PUSH_SCENERY, MSG_PULL_SCENERY, MSG_TURN_SCENERY:
		"Das kannst du nicht bewegen.";
#Endif;
#IfDef SACK_OBJECT;
#IfTrue MSG_SACK_PUTTING < 1000;
	MSG_SACK_PUTTING:
	! p_arg_1 = the object being put into SACK_OBJECT.
		"(lege ", (the) p_arg_1, " in ", (the) SACK_OBJECT, " um Platz zu schaffen)";
#EndIf;
#EndIf;
#IfTrue MSG_INVENTORY_DEFAULT < 1000;
	MSG_INVENTORY_DEFAULT:
		! return true if something listed to run afterroutines
		! or false if MSG_INVENTORY_EMPTY should be displayed
		p_arg_1 = "Du hast ";
		if(inventory_style == 0) {
			p_arg_1 = "Du hast:";
			p_arg_2 = NEWLINE_BIT;
		}
		if(PrintContents(p_arg_1, player, p_arg_2)) {
			if(inventory_style) print ".^";
			rtrue;
		}
		rfalse;
#EndIf;
#IfTrue MSG_EXAMINE_NOTHING_SPECIAL < 1000;
	MSG_EXAMINE_NOTHING_SPECIAL:
		! "an" + Dativ → (DE_Dem)
		"Du erkennst nichts Besonderes an ", (DE_Dem) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_PUSH_ANIMATE;
	MSG_PUSH_ANIMATE, MSG_PULL_ANIMATE, MSG_TURN_ANIMATE, MSG_CLIMB_ANIMATE:
		"Das wäre nicht gerade höflich.";
#Endif;
#Ifndef SKIP_MSG_DROP_NOT_HOLDING;
	MSG_DROP_NOT_HOLDING, MSG_SHOW_NOT_HOLDING, MSG_GIVE_NOT_HOLDING,
	MSG_WEAR_NOT_HOLDING:
		! "halten" = Akkusativ → (DE_Den)
		"Du hältst ", (DE_Den) noun, " nicht.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	MSG_OPEN_YOU_CANT, MSG_CLOSE_YOU_CANT, MSG_ENTER_YOU_CANT,
	MSG_LOCK_NOT_A_LOCK, MSG_UNLOCK_NOT_A_LOCK, MSG_WEAR_NOT_CLOTHING:
	! p_arg_1 = the base verb for this action.
		"Du kannst ", (ThatorThose) noun, " nicht ", (verbname) p_arg_1, ".";
#Endif;
#IfTrue MSG_OPEN_ALREADY < 1000;
	MSG_OPEN_ALREADY:
		print_ret (CTheyreorIts) noun, " bereits offen.";
#EndIf;
#IfTrue MSG_OPEN_LOCKED < 1000;
	MSG_OPEN_LOCKED:
		print_ret (CTheyreorIts) noun, " verschlossen.";
#EndIf;
#IfTrue MSG_PUTON_NOT_SUPPORTER < 1000;
	MSG_PUTON_NOT_SUPPORTER:
		"Du kannst nichts auf ", (ThatorThose) second, " stellen.";
#EndIf;
#Ifndef SKIP_MSG_TAKE_ANIMATE;
	MSG_TAKE_ANIMATE, MSG_EAT_ANIMATE:
		"Ich glaube nicht, dass ", (the) noun, " das interessiert.";
#Endif;
#Ifndef SKIP_MSG_TAKE_PLAYER_PARENT;
	MSG_TAKE_PLAYER_PARENT, MSG_GO_FIRST_LEAVE, MSG_EXIT_FIRST_LEAVE:
	! p_arg_1 = the object the player has to leave to perform the action.
	! "verlassen" = Akkusativ → (DE_Den)
		"Zuerst musst du ", (DE_Den) p_arg_1, " verlassen.";
#Endif;
#Iftrue MSG_OPEN_DEFAULT < 1000;
	MSG_OPEN_DEFAULT:
		! "öffnen" = Akkusativ → (DE_Den)
		print "Du öffnest ", (DE_Den) noun;
		if (noun has container && noun hasnt transparent &&
				~~IndirectlyContains(noun, player)) {
			print " und siehst ";
			p_arg_2 = short_name_case;
			short_name_case = Akk;
			if (PrintContents(0, noun) == false) print "nichts";
			short_name_case = p_arg_2;
		}
		".";
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT;
	MSG_CLOSE_DEFAULT:
		! "schließen" = Akkusativ → (DE_Den)
		"Du schließt ", (DE_Den) noun, ".";
	MSG_ENTER_DEFAULT:
		! "betreten" = Akkusativ → (DE_Den)
		"Du betrittst ", (DE_Den) noun, ".";
	MSG_EXIT_DEFAULT:
		! "verlassen" = Akkusativ → (DE_Den)
		"Du verlässt ", (DE_Den) noun, ".";
	MSG_LOCK_DEFAULT:
		! "verriegeln" = Akkusativ → (DE_Den)
		"Du verriegelst ", (DE_Den) noun, ".";
	MSG_UNLOCK_DEFAULT:
		! "aufschließen" = Akkusativ → (DE_Den)
		"Du schließt ", (DE_Den) noun, " auf.";
#Endif;
#Ifndef SKIP_MSG_GIVE_DEFAULT;
	MSG_GIVE_DEFAULT, MSG_SHOW_DEFAULT:
		print_ret (The) second, " scheint nicht interessiert zu sein.";
#Endif;
#Ifndef SKIP_MSG_ASKFOR_DEFAULT;
	MSG_ASKFOR_DEFAULT, MSG_ASKTO_DEFAULT, MSG_ORDERS_WONT:
	! p_arg_1 = the actor which the player has asked to do something.
		print_ret (The) p_arg_1, " hat Besseres zu tun.";
#Endif;
#Ifndef SKIP_MSG_ENTER_NOT_OPEN;
	MSG_ENTER_NOT_OPEN, MSG_EXIT_NOT_OPEN, MSG_INSERT_NOT_OPEN,
	MSG_GO_DOOR_CLOSED, MSG_EMPTY_IS_CLOSED:
	! p_arg_1 = the object which is closed, thus blocking the players action
		"Das geht nicht, da ", (ObjIs) p_arg_1, " geschlossen ist.";
#Endif;
#Ifndef SKIP_MSG_GIVE_PLAYER;
	MSG_GIVE_PLAYER, MSG_TAKE_ALREADY_HAVE:
		"Du hast ", (ItorThem) noun, " bereits.";
#Endif;
#Ifndef SKIP_MSG_SAVE_FAILED;
	MSG_SAVE_FAILED, MSG_RESTORE_FAILED, MSG_RESTART_FAILED:
		"Fehlgeschlagen: ", (verbname) verb_word, ".";
#Endif;
#Ifndef SKIP_MSG_INSERT_ALREADY;
	MSG_INSERT_ALREADY, MSG_PUTON_ALREADY, MSG_TRANSFER_ALREADY:
		"Schon da.";
#Endif;
#Ifndef SKIP_MSG_INSERT_ANIMATE;
	MSG_INSERT_ANIMATE, MSG_PUTON_ANIMATE:
		"Versuch stattdessen ", (ItorThem) noun, " zu geben.";
#Endif;
#Ifndef SKIP_MSG_INSERT_NO_ROOM;
	MSG_INSERT_NO_ROOM, MSG_PUTON_NO_ROOM:
		"Es ist kein Platz mehr.";
#Endif;
#IfTrue MSG_INSERT_DEFAULT < 1000;
	MSG_INSERT_DEFAULT:
		! "legen in" (wohin?) = Akkusativ für noun + second → (DE_Den)
		"Du legst ", (DE_Den) noun, " in ", (DE_Den) second, ".";
#EndIf;
#IfTrue MSG_PUTON_DEFAULT < 1000;
	MSG_PUTON_DEFAULT:
		! "legen auf" (wohin?) = Akkusativ für noun + second → (DE_Den)
		"Du legst ", (DE_Den) noun, " auf ", (DE_Den) second, ".";
#EndIf;
#Ifndef SKIP_MSG_ASK_DEFAULT;
	MSG_ASK_DEFAULT, MSG_ANSWER_DEFAULT, MSG_SHOUT_DEFAULT, MSG_SHOUTAT_DEFAULT:
		"Keine Antwort.";
#Endif;
#IfTrue MSG_WEAR_ALREADY_WORN < 1000;
	MSG_WEAR_ALREADY_WORN:
		! "mit" + Dativ → (DE_Dem)
		"Du bist bereits mit ", (DE_Dem) noun, " bekleidet.";
#EndIf;
#IfTrue MSG_WEAR_DEFAULT < 1000;
	MSG_WEAR_DEFAULT:
		! "mit" + Dativ → (DE_Dem)
		"Du bist nun mit ", (DE_Dem) noun, " bekleidet.";
#EndIf;
#IfTrue MSG_DISROBE_NOT_WEARING < 1000;
	MSG_DISROBE_NOT_WEARING:
		! "mit" + Dativ → (DE_Dem)
		"Du bist nicht mit ", (DE_Dem) noun, " bekleidet.";
#EndIf;
#IfTrue MSG_DISROBE_DEFAULT < 1000;
	MSG_DISROBE_DEFAULT:
		! "ausziehen" = Akkusativ → (DE_Den)
		"Du ziehst ", (DE_Den) noun, " aus.";
#EndIf;
#Ifndef SKIP_MSG_SWITCH_ON_NOT_SWITCHABL;
	MSG_SWITCH_ON_NOT_SWITCHABLE, MSG_SWITCH_OFF_NOT_SWITCHABLE:
		print_ret (CTheyreorThats) noun, " ist nicht umschaltbar.";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_ON;
	MSG_SWITCH_ON_ON, MSG_SWITCH_OFF_NOT_ON:
		print_ret (CTheyreorThats) noun, " ist schon ", (OnOff) noun, ".";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_DEFAULT;
	MSG_SWITCH_ON_DEFAULT, MSG_SWITCH_OFF_DEFAULT:
		! "schalten" = Akkusativ → (DE_Den)
		"Du schaltest ", (DE_Den) noun, " ", (OnOff) noun, ".";
#Endif;
#Iftrue MSG_AUTO_TAKE < 1000;
	MSG_AUTO_TAKE:
	! p_arg_1 = the object the player automatically picks up
	! "nehmen" = Akkusativ → (DE_Den)
		"(du nimmst zuerst ", (DE_Den) p_arg_1, ")";
#Endif;
#Iftrue MSG_AUTO_DISROBE < 1000;
	MSG_AUTO_DISROBE:
	! p_arg_1 = the object the player automatically takes off.
	! "ausziehen" = Akkusativ → (DE_Den)
		"(du ziehst zuerst ", (DE_Den) p_arg_1, " aus)";
#Endif;
#Iftrue MSG_AUTO_DISROBE_WORN < 1000;
	MSG_AUTO_DISROBE_WORN:
	! p_arg_1 = the object the player would need to take off.
	! "ausziehen" = Akkusativ → (DE_Den)
		"Du müsstest zuerst ", (DE_Den) p_arg_1, " ausziehen.";
#Endif;
#IfTrue MSG_PARSER_NOTHING_TO_VERB < 1000;
	MSG_PARSER_NOTHING_TO_VERB:
	! p_arg_1 = the last word in player input + 1.
		if(action == ##Drop or ##Insert) {
			if((parse + 2 + (p_arg_1 - 2) *4) --> 0 == ALL_WORD)
				"Du trägst nichts.";
			if(TryNumber(verb_wordnum + 1) > 0) "Du hältst nichts davon.";
		}
		print "Es gibt keine Dinge, die ~";
		_PrintPartialMatch(verb_wordnum, p_arg_1 - 1);
		"~ entsprechen.";
#EndIf;
#Ifndef SKIP_MSG_PARSER_NOT_HOLDING;
	MSG_PARSER_NOT_HOLDING, MSG_AUTO_TAKE_NOT_HELD, MSG_WAVE_NOTHOLDING:
	! p_arg_1 = the object which the player must be holding to perform the
	! action but isnt.
	! "halten" = Akkusativ → (DE_Den)
		"Aber du hältst ", (DE_Den) p_arg_1, " nicht.";
#Endif;
#IfTrue MSG_PARSER_PARTIAL_MATCH < 1000;
	MSG_PARSER_PARTIAL_MATCH:
	! p_arg_1 = the word number of the last word understood + 1.
		print "Ich habe dich nur bis ~";
		_PrintPartialMatch(verb_wordnum, p_arg_1);
		"~ verstanden.";
#EndIf;
#IfTrue MSG_PARSER_CANT_TALK < 1000;
	MSG_PARSER_CANT_TALK:
	! p_arg_1 = the object which cant be talked to.
	! "mit" + Dativ → (DE_Dem)
		"Du kannst nicht mit ", (DE_Dem) p_arg_1, " reden.";
#EndIf;
#IfTrue MSG_PARSER_NO_NEED_REFER_TO < 1000;
	MSG_PARSER_NO_NEED_REFER_TO:
		! TODO: "Du musst dich in diesem Spiel nicht auf ~ beziehen."
		print "Du musst dich in diesem Spiel nicht auf ~";
		_PrintUnknownWord();
		"~ beziehen.";
#EndIf;
#IfTrue MSG_PARSER_DONT_UNDERSTAND_WORD < 1000;
	MSG_PARSER_DONT_UNDERSTAND_WORD:
		! TODO: "Entschuldigung, ich verstehe nicht was ~ bedeutet."
		print "Entschuldigung, ich verstehe nicht ";
		if(oops_unfixed) {
			"dieses Wort auch nicht.";
		}
		print "was ~";
		_PrintUnknownWord();
		"~ bedeutet.";
#EndIf;
#IfTrue MSG_PARSER_BAD_PATTERN_PREFIX < 1000;
	MSG_PARSER_BAD_PATTERN_PREFIX:
		print "Ich glaube, du wolltest ~";
		rtrue;
#EndIf;
#IfTrue MSG_PARSER_BAD_PATTERN_SUFFIX < 1000;
	MSG_PARSER_BAD_PATTERN_SUFFIX:
		"~ sagen. Bitte versuche es erneut.";
#EndIf;
#IfTrue MSG_PARSER_NO_IT < 1000;
	MSG_PARSER_NO_IT:
		print "Ich weiß nicht, was ~";
		if (p_arg_1 == 'it') print "es";
		else if (p_arg_1 == 'him') print "er";
		else if (p_arg_1 == 'her' or 'them') print "sie";
		else print (address) p_arg_1;
		print_ret "~ bedeutet.";
#EndIf;
#Ifndef SKIP_MSG_PARSER_NOSUCHTHING;
	MSG_PARSER_NOSUCHTHING, MSG_SHOUT_NOSUCHTHING:
		"So etwas kannst du nicht sehen.";
#EndIf;
#IfTrue MSG_PARSER_CANT_SEE_IT < 1000;
	MSG_PARSER_CANT_SEE_IT:
		"Du kannst ~", (address) p_arg_1, "~ (", (name) p_arg_2, ") momentan nicht sehen.";
#EndIf;
#Ifndef SKIP_MSG_CLOSE_NOT_OPEN;
	MSG_CLOSE_NOT_OPEN, MSG_TOUCHABLE_FOUND_CLOSED,
	MSG_PARSER_CONTAINER_ISNT_OPEN:
	! p_arg_1 = the object which isnt open.
		print_ret (CObjIs) p_arg_1, " nicht offen.";
#Endif;
#IfTrue MSG_CONSULT_NOTHING_INTERESTING < 1000;
	MSG_CONSULT_NOTHING_INTERESTING:
		! "in" + Dativ (wo?) → (DE_Dem)
		"Du findest nichts von Belang in ", (DE_Dem) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_CUT_NO_USE;
	MSG_CUT_NO_USE, MSG_JUMP_OVER, MSG_TIE_DEFAULT, MSG_CLIMB_DEFAULT:
		"Damit erreichst du nichts.";
#Endif;
#Ifndef SKIP_MSG_LOCK_ALREADY_LOCKED;
	MSG_LOCK_ALREADY_LOCKED:
		print_ret (The) noun, " ist bereits verschlossen.";
	MSG_UNLOCK_ALREADY_UNLOCKED:
		print_ret (The) noun, " ist bereits aufgeschlossen.";
#Endif;
#IfTrue MSG_LOCK_CLOSE_FIRST < 1000;
	MSG_LOCK_CLOSE_FIRST:
		! "schließen" = Akkusativ → (DE_Den)
		"Zuerst musst du ", (DE_Den) noun, " schließen.";
#EndIf;
#Ifndef SKIP_MSG_LOCK_KEY_DOESNT_FIT;
	MSG_LOCK_KEY_DOESNT_FIT, MSG_UNLOCK_KEY_DOESNT_FIT:
		if (second == nothing) "Du hast keinen passenden Schlüssel dafür.";
		print_ret (The) second, " scheint nicht in das Schloss zu passen.";
#Endif;
#IfTrue MSG_EXAMINE_CLOSED < 1000;
	MSG_EXAMINE_CLOSED:
	! p_arg_1 = the examined object (which is closed).
		print_ret (CObjIs) p_arg_1, " geschlossen.";
#Endif;
#IfTrue MSG_REMOVE_NOT_HERE < 1000;
	MSG_REMOVE_NOT_HERE:
		"Aber ", (ObjIs) noun, " momentan nicht da.";
#EndIf;
#IfTrue MSG_SEARCH_IN_IT_ISARE < 1000;
	MSG_SEARCH_IN_IT_ISARE:
		print (The) noun, " enthält bereits ";
		p_arg_2 = short_name_case;
		short_name_case = Akk;
		PrintContents(0, noun);
		short_name_case = p_arg_2;
		".";
#EndIf;
#IfTrue MSG_SEARCH_ON_IT_ISARE < 1000;
	MSG_SEARCH_ON_IT_ISARE:
		! "auf" + Dativ (Lage, wo?) → (DE_Dem)
		print "Auf ", (DE_Dem) noun;
		PrintContents(" ", noun, ISARE_BIT);
		".";
#EndIf;
#IfTrue MSG_SEARCH_EMPTY < 1000;
	MSG_SEARCH_EMPTY:
		print_ret (CObjIs) noun, " leer.";
#EndIf;
#IfTrue MSG_SEARCH_NOTHING_ON < 1000;
	MSG_SEARCH_NOTHING_ON:
		! "auf" + Dativ (Lage) → (DE_Dem)
		"Es ist nichts auf ", (DE_Dem) noun, ".";
#EndIf;
#IfTrue MSG_SEARCH_CANT_SEE_CLOSED < 1000;
	MSG_SEARCH_CANT_SEE_CLOSED:
		"Du kannst nicht reinschauen, ", (ObjIs) noun, " geschlossen.";
#EndIf;
#IfTrue MSG_EXAMINE_ONOFF < 1000;
	MSG_EXAMINE_ONOFF:
		print_ret (CObjIs) noun, " aktuell ", (OnOff) noun, "geschaltet.";
#EndIf;
#IfTrue MSG_EAT_DEFAULT < 1000;
	MSG_EAT_DEFAULT:
		! "essen" = Akkusativ → (DE_Den)
		"Du isst ", (DE_Den) noun, ". Nicht schlecht.";
#EndIf;
#Ifndef SKIP_MSG_RUB_DEFAULT;
MSG_RUB_DEFAULT, MSG_SQUEEZE_DEFAULT:
	"Damit erreichst du nichts.";
#Endif;
#IfTrue MSG_TAKE_NOT_AVAILABLE < 1000;
	MSG_TAKE_NOT_AVAILABLE:
		print_ret (CObjIs) noun, " nicht vorhanden.";
#EndIf;
#IfTrue MSG_TAKE_BELONGS < 1000;
	MSG_TAKE_BELONGS:
		! p_arg_1 = the object that is held by p_arg_2
		print_ret (The) p_arg_1, " gehört ", (the) p_arg_2, ".";
#EndIf;
#IfTrue MSG_TAKE_PART_OF < 1000;
	MSG_TAKE_PART_OF:
		! p_arg_1 = the object that is part of p_arg_2
		print_ret (The) p_arg_1, " ist ein Teil von ", (the) p_arg_2, ".";
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
#Ifndef SKIP_MSG_EXAMINE_DARK;
	MSG_EXAMINE_DARK, MSG_SEARCH_DARK:
		"Aber es ist dunkel.";
#Endif;
#Endif;
#IfTrue MSG_EAT_INEDIBLE < 1000;
	MSG_EAT_INEDIBLE:
		print_ret (CTheyreorThats) noun, " ist ungenießbar.";
#EndIf;
#IfTrue MSG_ENTER_BAD_LOCATION < 1000;
	MSG_ENTER_BAD_LOCATION:
		print "Du musst zuerst ";
		if(player notin location && ~~IndirectlyContains(parent(player), noun))
			print (the) parent(player), " verlassen";
		else
			print (the) parent(noun), " betreten";
		".";
#EndIf;
#IfTrue MSG_ENTER_HELD < 1000;
	MSG_ENTER_HELD:
		! "betreten" = Akkusativ → (DE_Den); (ItorThem) = Akkusativ-Pronomen
		"Du kannst ", (DE_Den) noun, " nicht betreten, während du ", (ItorThem) noun, " trägst.";
#EndIf;
#Ifndef SKIP_MSG_INSERT_NOT_CONTAINER;
#ifdef MSG_EMPTY_NOT_CONTAINER;
	MSG_INSERT_NOT_CONTAINER, MSG_EMPTY_NOT_CONTAINER:
#Ifnot;
	MSG_INSERT_NOT_CONTAINER:
#Endif;
		! p_arg_1 = the object that cant contain things
		print_ret (The) p_arg_1, " kann keine Dinge enthalten.";
#Endif;

#IfDef OPTIONAL_EXTENDED_VERBSET;
#IfTrue MSG_BLOW_DEFAULT < 1000;
	MSG_BLOW_DEFAULT:
		"Du kannst ", (the) noun, " nicht sinnvoll pusten.";
#EndIf;
#IfTrue MSG_EMPTY_ALREADY_EMPTY < 1000;
	MSG_EMPTY_ALREADY_EMPTY:
		! p_arg_1 = the object that is already empty
		print_ret (CObjIs) p_arg_1, " bereits leer.";
#EndIf;
#IfTrue MSG_SET_DEFAULT < 1000;
	MSG_SET_DEFAULT:
		"Nein, du kannst ", (thatorthose) noun, " nicht einstellen.";
#EndIf;
#IfTrue MSG_SET_TO_DEFAULT < 1000;
	MSG_SET_TO_DEFAULT:
		"Nein, du kannst ", (thatorthose) noun, " nicht auf etwas einstellen.";
#EndIf;
#IfTrue MSG_WAVE_DEFAULT < 1000;
	MSG_WAVE_DEFAULT:
		! "mit" + Dativ → (DE_Dem)
		"Du siehst dämlich aus, wenn du mit ", (DE_Dem) noun, " winkst.";
#EndIf;
#EndIf; ! Extended verbset

#Ifndef NO_SCORE;
#Iftrue MSG_PARSER_NEW_SCORE < 1000;
	MSG_PARSER_NEW_SCORE:
		! p_arg_1 = the old score
		if(p_arg_1 < score) {
			p_arg_2 = score - p_arg_1;
			print "^[Du hast ", p_arg_2, " Punkt";
			if(p_arg_2 ~= 1) print "e";
			" erhalten.]";
		} else {
			p_arg_2 = p_arg_1 - score;
			print "^[Du hast ", p_arg_2, " Punkt";
			if(p_arg_2 ~= 1) print "e";
			" verloren.]";
		}
#Endif;
#Endif;
#Iftrue MSG_SCORE_DEFAULT < 1000;
	MSG_SCORE_DEFAULT:
#Ifdef NO_SCORE;
		"Es gibt keine Punkte in diesem Spiel.";
#Ifnot;
		if (deadflag) print "In diesem Spiel hast du"; else print "Bisher hast du";
		print " ", score, " von ", MAX_SCORE, " möglichen Punkten erreicht, in ", turns, " ";
		if(turns == 1) print "Zug"; else print "Zügen";
		rtrue;
#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
#IfTrue MSG_FULLSCORE_START < 1000;
	MSG_FULLSCORE_START:
		print "Die Punktzahl setzt sich wie folgt zusammen:";
#EndIf;
#IfTrue MSG_FULLSCORE_END < 1000;
	MSG_FULLSCORE_END:
		"insgesamt (von ", MAX_SCORE, ")";
#EndIf;
#EndIf;

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Infrequently used messages
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#Ifndef SKIP_MSG_LOOKMODE;
	MSG_LOOKMODE_NORMAL, MSG_LOOKMODE_LONG, MSG_LOOKMODE_SHORT:
		print "Dieses Spiel ist jetzt im ";
		if(lookmode==1) print "normalen ~";
		if(lookmode==2) print "~ausführlichen";
		else {
			if(lookmode==3) print "~sehr ";
			print "kurzen";
		}
		print "~ Modus, welcher ";
		if(lookmode ~= 1) print "immer ";
		print "gibt ";
		if(lookmode == 3) print "kurze";
		else print "lange";
		print " Beschreibungen von Orten ";
		if(lookmode == 1)
			"die noch nie besucht wurden, und ansonsten kurze.";
		print "(auch wenn du";
		if(lookmode == 2) print " dort schon warst";
		else print " dort noch nicht warst";
		").";
#Endif;
#IfTrue MSG_RESTART_RESTORE_OR_QUIT < 1000;
	MSG_RESTART_RESTORE_OR_QUIT:
		print "^Möchtest du NEUSTART, WIEDERHERSTELLEN";
#Ifdef OPTIONAL_PROVIDE_UNDO_FINAL;
	#Ifdef DEATH_MENTION_UNDO;
			if(((HDR_GAMEFLAGS->1) & 16) ~= 0)
				print ", die letzte Runde RÜCKGÄNGIG machen";
	#Ifnot;
			if(((HDR_GAMEFLAGS->1) & 16) ~= 0 && deadflag ~= GS_WIN)
				print ", die letzte Runde RÜCKGÄNGIG machen";
	#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
		print ", die VOLLSTÄNDIGE Punktzahl dieses Spiels angeben";
#EndIf;
		if(AMUSING_PROVIDED == 0 && deadflag == 2) print ", einige Vorschläge für UNTERHALTSAME Aktivitäten sehen";
		print " oder BEENDEN? ";
		rtrue;
#EndIf;
#IfTrue MSG_AREYOUSUREQUIT < 1000;
	MSG_AREYOUSUREQUIT: ! print and rtrue to avoid newline
		print "Bist du sicher, dass du das Spiel beenden willst? ";
		rtrue;
#EndIf;
#IfTrue MSG_YOU_HAVE_WON < 1000;
	MSG_YOU_HAVE_WON: ! print and rtrue to avoid newline
 		print "Du hast gewonnen";
 		rtrue;
#EndIf;
#IfTrue MSG_YOU_HAVE_DIED < 1000;
	MSG_YOU_HAVE_DIED: ! print and rtrue to avoid newline
		print "Du bist gestorben";
		rtrue;
#EndIf;
#IfTrue MSG_YES_OR_NO < 1000;
	MSG_YES_OR_NO:
		print "Bitte antworte mit Ja oder Nein: ";
		rtrue;
#EndIf;
#IfTrue MSG_RESTART_CONFIRM < 1000;
	MSG_RESTART_CONFIRM:
		print "Bist du sicher, dass du neu starten willst? ";
		rtrue;
#Endif;

#Ifndef NO_SCORE;
#Ifndef SKIP_MSG_NOTIFY_ON;
	MSG_NOTIFY_ON, MSG_NOTIFY_OFF:
		print "Spielstandsmeldung ";
		if(p_msg == MSG_NOTIFY_ON) "ein.";
		"aus.";
#Endif;
#Endif;

default:
		! No code found. Print an error message.
		_RunTimeError(ERR_UNKNOWN_MSGNO);
	}
];

! German gender/article helpers
! TODO: These need to be extended for full German grammatical gender support

[ ThatorThose p_obj;
	! Akkusativ Demonstrativpronomen nach Genus:
	! maskulin="den", feminin="die", Neutrum="das", Plural="die"
	if (p_obj has pluralname) { print "die";  return; }
	if (p_obj has female)     { print "die";  return; }
	if (p_obj has neuter)     { print "das";  return; }
	print "den";  ! maskulin Akkusativ
];

[ ItorThem p_obj;
	! Akkusativ-Pronomen nach Genus (für alle Objekte, belebt oder unbelebt):
	! maskulin="ihn", feminin="sie", Neutrum="es", Plural="sie"
	! Hinweis: Im Deutschen haben auch unbelebte Objekte Genus-abhängige Pronomina.
	if (p_obj == player)       { print "du selbst"; rtrue; }
	if (p_obj has pluralname)  { print "sie"; rtrue; }  ! Plural Akk = "sie"
	if (p_obj has female)      { print "sie"; rtrue; }  ! Feminin Akk = "sie"
	if (p_obj has neuter)      { print "es";  rtrue; }  ! Neutrum Akk = "es"
	print "ihn";  ! Maskulin Akk = "ihn" (Standard)
];

! Note: ItOrThem() is an alias for ItorThem() - Inform 6 is case-insensitive

[ CObjIs p_obj;
	print (The) p_obj, " ", (isorare) p_obj;
];

[ ObjIs p_obj;
	print (the) p_obj, " ", (isorare) p_obj;
];

[ DoOrDoes p_obj;
	! TODO: German doesn't use "do/does" in the same way - returns generic form
	p_obj = p_obj; ! suppress warning
	print "tut";
];

[ HaveOrHas p_obj;
	! TODO: German "haben/hat"
	if (p_obj has pluralname) print "haben"; else print "hat";
];

[ IsorAre p_obj;
	! TODO: German "ist/sind"
	if (p_obj has pluralname || p_obj == player) print "sind"; else print "ist";
];

[ CTheyreorThats p_obj;
	! Nominativ "ist"-Ausdruck nach Genus (für belebte und unbelebte Objekte)
	if (p_obj == player)       { print "Du bist"; return; }
	if (p_obj has pluralname)  { print "Sie sind"; return; }
	if (p_obj has female)      { print "Sie ist"; return; }  ! feminin
	if (p_obj has neuter)      { print "Es ist";  return; }  ! Neutrum
	print "Er ist";  ! maskulin (Standard)
];

[ CTheyreorIts p_obj;
	! Für unbelebte Objekte: Genus-abhängig
	if (p_obj ~= player && p_obj hasnt pluralname) {
		if (p_obj has female)  { print "Sie ist"; return; }  ! feminin
		if (p_obj has neuter)  { print "Es ist";  return; }  ! Neutrum
		if (p_obj hasnt animate) { print "Er ist"; return; } ! maskulin (unbelebt)
	}
	CTheyreorThats(p_obj);
];

[ OnOff p_obj;
	! TODO: German "ein/aus"
	if(p_obj has on) print "ein";
	else print "aus";
	return;
];

[ SingularS p_obj;
	! German doesn't use -s for verb conjugation in the same way
	! but this is kept for compatibility
	p_obj = p_obj; ! suppress warning
];

! Note: thatorthose() is an alias for ThatorThose() - Inform 6 is case-insensitive

!
! Error messages
!
Constant ERR_TOO_MANY_TIMERS_DAEMONS 1;
Constant ERR_OBJECT_HASNT_PROPERTY 2;
Constant ERR_SCOPE_FULL 3;
Constant ERR_UNKNOWN_MSGNO 4;
Constant ERR_INVALID_DIR_PROP 5;
Constant ERR_TOO_MANY_FLOATING 6;
Constant ERR_NOT_DIR_PROP 7;
Constant ERR_NOT_FAKE_OBJ 8;
Constant ERR_ILLEGAL_CHOOSEOBJNO 9;
Constant ERR_BUFFER_OVERRUN 10;

[_RunTimeError p_err p_obj _parent;
	print "^[PunyInformDE Fehler: ";
	if(p_err ofclass string)
		print (string) p_err;
	else {
		print p_err;
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
		print " - ";
		switch(p_err) {
		ERR_TOO_MANY_TIMERS_DAEMONS:
			print "Zu viele Timer/Daemons";
		ERR_OBJECT_HASNT_PROPERTY:
			print "Objekt fehlt erforderliche Eigenschaft";
		ERR_SCOPE_FULL:
			print "Umfang voll";
		ERR_UNKNOWN_MSGNO:
			print "Unbekannte Nachrichten-Nr.";
		ERR_INVALID_DIR_PROP:
			print "GoSub mit ungültiger Richtungseigenschaft aufgerufen";
		ERR_TOO_MANY_FLOATING:
			print "Zu viele schwebende Objekte";
		ERR_NOT_DIR_PROP:
			print "DirPropToFakeObj mit nicht-Dirprop aufgerufen";
		ERR_NOT_FAKE_OBJ:
			print "FakeObjToDirProp mit nicht-fakeobj aufgerufen";
		ERR_ILLEGAL_CHOOSEOBJNO:
			print "ChooseObjectsFinal_(Pick oder Discard) mit nicht vorhandenem Array-Index aufgerufen";
#Ifdef DEBUG;
		ERR_BUFFER_OVERRUN:
			print "Pufferüberlauf: Zu viele Zeichen in einen Puffer gedruckt";
#Endif;
		default:
			print "Unbekannter Fehler";
		}
#EndIf;
	}
	print "]^";
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
	if(p_obj ofclass object) {
		_parent = parent(p_obj);
		print "Fehlerverursachendes Objekt: ", (the) p_obj, " (", p_obj, ") in ", (name) _parent, " (", _parent, ")^";
	}
#Ifnot;
	_parent = p_obj; ! Avoid compiler warning
#EndIf;
	rtrue;
];
