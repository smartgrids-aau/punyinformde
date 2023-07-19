! Part of PunyInform: A small stdlib and parser for interactive fiction
! suitable for old-school computers such as the Commodore 64.
! Designed to be similar, but not identical, to the Inform 6 library.
!
System_file;

!
! Simple string messages
!

#IfV5;
Zcharacter '@{0e4}';
Zcharacter '@{0f6}';
Zcharacter '@{0fc}';
Zcharacter '@{0df}';
#EndIf;

#Ifndef MSG_TAKE_YOURSELF;
Constant MSG_TAKE_YOURSELF "Selbstverliebt wie immer.";
#EndIf;
#Ifndef MSG_TAKE_NO_CAPACITY;
Constant MSG_TAKE_NO_CAPACITY "Du haltest schon zu viele Sachen.";
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
Constant MSG_SMELL_DEFAULT "Du riechst nichts unerwartetes.";
#Endif;
#Ifndef MSG_LISTEN_DEFAULT;
Constant MSG_LISTEN_DEFAULT "Du kriegst nichts unerwartetes mit.";
#Endif;
#Ifndef MSG_TELL_PLAYER;
Constant MSG_TELL_PLAYER "Du redest eine Weile mit dir selbst.";
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
Constant MSG_GO_CANT_GO "Da kannst du nicht hingehen";
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
Constant MSG_PUSHDIR_DEFAULT "Ist das das Beste, was dir in den Sinn kommt?";
#EndIf;
#Ifndef MSG_JUMP;
Constant MSG_JUMP "Du springst auf der Stelle, ohne Erfolg.";
#EndIf;
#Ifndef MSG_REMOVE_DEFAULT;
Constant MSG_REMOVE_DEFAULT "Entfernt.";
#EndIf;
#Ifndef MSG_SEARCH_NOTHING_SPECIAL;
Constant MSG_SEARCH_NOTHING_SPECIAL "Du findest nichts Besonderes.";
#EndIf;
#Ifndef MSG_PARSER_ONLY_TO_ANIMATE;
Constant MSG_PARSER_ONLY_TO_ANIMATE "Das kann man nur mit etwas Lebendigem machen.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_VERB;
Constant MSG_PARSER_NOT_MULTIPLE_VERB "Mit diesem Verb kann man nicht mehrere Objekte verwenden.";
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
#Ifndef MSG_PARSER_NOSUCHTHING;
Constant MSG_PARSER_NOSUCHTHING "So etwas kannst du nicht sehen.";
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
Default MSG_REMOVE_CLOSED 78;
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

#IfDef OPTIONAL_PROVIDE_UNDO_FINAL;
#Ifndef MSG_UNDO_NOTHING_DONE;
Constant MSG_UNDO_NOTHING_DONE "[Man kann nicht ~rückängig machen~, was nicht getan wurde!]";
#EndIf;
#Ifndef MSG_UNDO_NOT_PROVIDED;
Constant MSG_UNDO_NOT_PROVIDED "[Ihr Dolmetscher bietet kein ~rückängig machen~ an.]";
#EndIf;
#Ifndef MSG_UNDO_FAILED;
Constant MSG_UNDO_FAILED "~Rückängig machen~ fehlgeschlagen.";
#EndIf;
#Ifndef MSG_UNDO_DONE;
Constant MSG_UNDO_DONE "Vorherige Wende rückgängig gemacht.";
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
Constant MSG_SING_DEFAULT "Dein Gesang ist abscheulich.";
#EndIf;
#Ifndef MSG_SLEEP_DEFAULT;
Constant MSG_SLEEP_DEFAULT "Du bist dich nicht besonders kraftlos.";
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
Constant MSG_SWING_DEFAULT "Hier gibt es nichts um zu schaukeln.";
#EndIf;
#Ifndef MSG_TASTE_DEFAULT;
Constant MSG_TASTE_DEFAULT "Du schmeckst nichts Unerwartetes.";
#EndIf;
#Ifndef MSG_THINK_DEFAULT;
Constant MSG_THINK_DEFAULT "Das ist eine gute Idee.";
#EndIf;
#Ifndef MSG_WAVEHANDS_DEFAULT;
Constant MSG_WAVEHANDS_DEFAULT "Du winkst und kommst dir dumm vor.";
#EndIf;
#Ifndef MSG_WAKE_DEFAULT;
Constant MSG_WAKE_DEFAULT "Die schreckliche Wahrheit ist, dass dies kein Traum ist.";
#Endif;
#Ifndef MSG_WAKEOTHER_DEFAULT;
Constant MSG_WAKEOTHER_DEFAULT "Das erscheint unsinning.";
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
#Iffalse MSG_REMOVE_CLOSED < 1000;
Constant SKIP_MSG_ENTER_NOT_OPEN;
#Endif;
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


#Ifndef OPTIONAL_NO_DARKNESS;
#Iffalse MSG_EXAMINE_DARK < 1000;
#Iffalse MSG_SEARCH_DARK < 1000;
Constant SKIP_MSG_EXAMINE_DARK;
#Endif;
#Endif;
#Endif;

[ _PrintMsg p_msg p_arg_1 p_arg_2;
	if(p_msg ofclass String)
		print_ret (string) p_msg;

#Ifdef LibraryMessages;
	if(p_msg > 999) {
		return LibraryMessages(p_msg, p_arg_1, p_arg_2);
	}
#Endif;

	! Not a string, there should be code for the message here
	switch(p_msg) {
#Iftrue MSG_TAKE_SCENERY < 1000;
	MSG_TAKE_SCENERY:
		print_ret (CTheyreorThats) noun, " kaum tragbar.";
#EndIf;
#Ifndef SKIP_MSG_PUSH_DEFAULT;
	MSG_PUSH_DEFAULT, MSG_PULL_DEFAULT, MSG_TURN_DEFAULT:
		"Es passiert nichts Offensichtliches.";
#Endif;
#Ifndef SKIP_MSG_PUSH_STATIC;
	MSG_PUSH_STATIC, MSG_PULL_STATIC, MSG_TURN_STATIC, MSG_TAKE_STATIC:
		print_ret (CTheyreorThats) noun, " fixiert.";
#Endif;
#Ifndef SKIP_MSG_PUSH_SCENERY;
	MSG_PUSH_SCENERY, MSG_PULL_SCENERY, MSG_TURN_SCENERY:
		"Welches Konzept!";
#Endif;
#IfDef SACK_OBJECT;
#IfTrue MSG_SACK_PUTTING < 1000;
	MSG_SACK_PUTTING:
	! p_arg_1 = the object being put into SACK_OBJECT.
		"(lege ", (the) p_arg_1, " in ", (the) SACK_OBJECT, " um Platz zu machen.)";
#EndIf;
#EndIf;
#IfTrue MSG_PROMPT < 1000;
	MSG_PROMPT:
		print "> ";
		rtrue;
#EndIf;
#IfTrue MSG_INVENTORY_DEFAULT < 1000;
	MSG_INVENTORY_DEFAULT:
		! return true if something listed to run afterroutines
		! or false if MSG_INVENTORY_EMPTY should be displayed
		p_arg_1 = "Du haltest ";
		if(inventory_style == 0) {
			p_arg_1 = "Du haltest: ";
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
		"Es ist nichts Besonderes an ", (the) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_PUSH_ANIMATE;
	MSG_PUSH_ANIMATE, MSG_PULL_ANIMATE, MSG_TURN_ANIMATE, MSG_CLIMB_ANIMATE:
		"Das ist weniger als aufmerksam.";
#Endif;
#Ifndef SKIP_MSG_DROP_NOT_HOLDING;
	MSG_DROP_NOT_HOLDING, MSG_SHOW_NOT_HOLDING, MSG_GIVE_NOT_HOLDING,
	MSG_WEAR_NOT_HOLDING:
		"Du haltest ", (ItorThem) noun, " nicht.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	MSG_WEAR_NOT_CLOTHING:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du kannst ", (ThatorThose) noun, " nicht anziehen.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	  MSG_UNLOCK_NOT_A_LOCK:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du kannst ", (ThatorThose) noun, " nicht aufsperren.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	MSG_OPEN_YOU_CANT:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du kannst ", (ThatorThose) noun, " nicht öffnen.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
   MSG_CLOSE_YOU_CANT:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du kannst ", (ThatorThose) noun, " nicht schließen.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	MSG_ENTER_YOU_CANT:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du kannst ", (ThatorThose) noun, " nicht betreten.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	MSG_LOCK_NOT_A_LOCK:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du kannst ", (ThatorThose) noun, " nicht verschließen.";
#Endif;
#IfTrue MSG_EAT_INEDIBLE < 1000;
	MSG_EAT_INEDIBLE:
		print_ret (CTheyreorThats) noun, " schlichtweg ungeniessbar.";
#EndIf;
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
		"Zuerst musst du ", (the) p_arg_1, " verlassen.";
#Endif;
#Iftrue MSG_OPEN_DEFAULT < 1000;
	MSG_OPEN_DEFAULT:
		print "Du machst ", (the) noun, " auf";
		if(noun has container && noun hasnt transparent &&
				~~IndirectlyContains(noun, player)) {
			print " und siehst ";
			if(PrintContents(0, noun)==false) print "nichts neues";
		}
		".";
#Endif;
#Iftrue MSG_LOOK_BEFORE_ROOMNAME < 1000;
	MSG_LOOK_BEFORE_ROOMNAME:
		! what to write at first when describing a room. Can be used to
		! add a newline, but default is to write nothing.
		!@new_line;
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT; MSG_EXIT_DEFAULT:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du verlässt ", (the) noun, ".";
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT;
	MSG_CLOSE_DEFAULT:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du schließt ", (the) noun, ".";
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT; MSG_LOCK_DEFAULT:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du verschließt ", (the) noun, ".";
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT;
	MSG_UNLOCK_DEFAULT:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du schließt ", (the) noun, " auf.";
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT; MSG_ENTER_DEFAULT:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Du betrittst ", (the) noun, ".";
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
	MSG_GO_DOOR_CLOSED, MSG_EMPTY_IS_CLOSED, MSG_REMOVE_CLOSED:
	! p_arg_1 = the object which is closed, thus blocking the player's action.
		"Du kannst nicht, da ", (the) p_arg_1, " geschlossen ", (isorare) p_arg_1, ".";
#Endif;
#Ifndef SKIP_MSG_GIVE_PLAYER;
	MSG_GIVE_PLAYER, MSG_TAKE_ALREADY_HAVE:
		"Du hast ", (ItorThem) noun, " schon genommen.";
#Endif;
#Ifndef SKIP_MSG_SAVE_FAILED;
	MSG_SAVE_FAILED, MSG_RESTORE_FAILED, MSG_RESTART_FAILED:
		"Gescheitert ", (verbname) verb_word, ".";
#Endif;
#Ifndef SKIP_MSG_INSERT_ALREADY;
	MSG_INSERT_ALREADY, MSG_PUTON_ALREADY, MSG_TRANSFER_ALREADY:
		"Schon da.";
#Endif;
#Ifndef SKIP_MSG_INSERT_ANIMATE;
	MSG_INSERT_ANIMATE, MSG_PUTON_ANIMATE:
		"Versuch ",(ItorThem) noun," stattdessen zu geben.";
#Endif;
#Ifndef SKIP_MSG_INSERT_NO_ROOM;
	MSG_INSERT_NO_ROOM, MSG_PUTON_NO_ROOM:
		"Es gibt keinen Platz mehr.";
#Endif;
#IfTrue MSG_INSERT_DEFAULT < 1000;
	MSG_INSERT_DEFAULT:
		"Du legst ", (the) noun, " in ", (the) second, ".";
#EndIf;
#IfTrue MSG_PUTON_DEFAULT < 1000;
	MSG_PUTON_DEFAULT:
		"Du legst ", (the) noun, " auf ", (the) second, ".";
#EndIf;
#Ifndef SKIP_MSG_ASK_DEFAULT;
	MSG_ASK_DEFAULT, MSG_ANSWER_DEFAULT, MSG_SHOUT_DEFAULT, MSG_SHOUTAT_DEFAULT:
		"Keine Antwort.";
#Endif;
#IfTrue MSG_WEAR_ALREADY_WORN < 1000;
	MSG_WEAR_ALREADY_WORN:
		"Du bist mit ", (ItorThem) noun, " bereits bekleidet.";
#EndIf;
#IfTrue MSG_WEAR_DEFAULT < 1000;
	MSG_WEAR_DEFAULT:
		"Du bist nun mit ", (the) noun, " bekleidet.";
#EndIf;
#IfTrue MSG_DISROBE_NOT_WEARING < 1000;
	MSG_DISROBE_NOT_WEARING:
		"Du bist nicht mit ", (the) noun, " bekleidet.";
#EndIf;
#IfTrue MSG_DISROBE_DEFAULT < 1000;
	MSG_DISROBE_DEFAULT:
		"Du ziehst ", (the) noun, " aus.";
#EndIf;
#Ifndef SKIP_MSG_SWITCH_ON_NOT_SWITCHABL;
	MSG_SWITCH_ON_NOT_SWITCHABLE, MSG_SWITCH_OFF_NOT_SWITCHABLE:
		print_ret (CTheyreorThats) noun, " nicht etwas, das man umschalten kann.";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_ON;
	MSG_SWITCH_ON_ON, MSG_SWITCH_OFF_NOT_ON:
		print_ret (CTheyreorThats) noun, " schon ", (OnOff) noun, ".";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_DEFAULT;
	MSG_SWITCH_ON_DEFAULT, MSG_SWITCH_OFF_DEFAULT:
		"Du schaltest ", (the) noun, " ", (OnOff) noun, ".";
#Endif;
#Iftrue MSG_AUTO_TAKE < 1000;
	MSG_AUTO_TAKE:
	! p_arg_1 = the object the player automatically picks up
	print "(Du nimmst zuerst ", (the) p_arg_1, ")^";
#Endif;
#Iftrue MSG_AUTO_DISROBE < 1000;
	MSG_AUTO_DISROBE:
	! p_arg_1 = the object the player automatically takes off.
		print "(Du ziehst zuerst ", (the) p_arg_1, " aus)^";
#Endif;
#Iftrue MSG_AUTO_DISROBE_WORN < 1000;
	MSG_AUTO_DISROBE_WORN:
	! p_arg_1 = the object the player would need to take off.
		print "Du musst ", (the) p_arg_1, " zuerst ausziehen.^";
#Endif;
#IfTrue MSG_PARSER_NOTHING_TO_VERB < 1000;
	MSG_PARSER_NOTHING_TO_VERB:
	! p_arg_1 = the last word in player input + 1.
		if(action == ##Drop or ##Insert && (parse + 2 + (p_arg_1 - 2) *4)-->0 == ALL_WORD) {
			"Du haltest nichts.";
		}  else {
			print "Es gibt keine Dinge, die ~ gleichen";
			_PrintPartialMatch(verb_wordnum, p_arg_1 - 1);
			"~.";
		}
#EndIf;
#Ifndef SKIP_MSG_PARSER_NOT_HOLDING;
	MSG_PARSER_NOT_HOLDING, MSG_AUTO_TAKE_NOT_HELD, MSG_WAVE_NOTHOLDING:
	! p_arg_1 = the object which the player must be holding to perform the
	! action but isn't.
		print_ret "Aber du haltest ", (the) p_arg_1, " nicht.";
#Endif;
#IfTrue MSG_PARSER_PARTIAL_MATCH < 1000;
	MSG_PARSER_PARTIAL_MATCH:
	! p_arg_1 = the word number of the last word understood + 1.
		print "Ich habe nur bis zu ~ ";
		_PrintPartialMatch(verb_wordnum, p_arg_1);
		"~ verstanden, aber dann hast du mich verloren.";
#EndIf;
#IfTrue MSG_PARSER_CANT_TALK < 1000;
	MSG_PARSER_CANT_TALK:
	! p_arg_1 = the object which can't be talked to.
		print_ret "Du kannst nicht mit ", (the) p_arg_1, " reden.";
#EndIf;
#IfTrue MSG_PARSER_NO_NEED_REFER_TO < 1000;
	MSG_PARSER_NO_NEED_REFER_TO:
		print "Du musst dich nicht auf ~ beziehen";
		_PrintUnknownWord();
		print_ret "~ in diesem Spiel.";
#EndIf;
#IfTrue MSG_PARSER_DONT_UNDERSTAND_WORD < 1000;
	MSG_PARSER_DONT_UNDERSTAND_WORD:
			print "Entschuldigung, ich verstehe nicht was ~";
			_PrintUnknownWord();
			print_ret "~ bedeutet.";
#EndIf;
#IfTrue MSG_PARSER_BAD_PATTERN_PREFIX < 1000;
	MSG_PARSER_BAD_PATTERN_PREFIX:
		print "Ich glaube, du wolltest sagen ~";
		rtrue;
#EndIf;
#IfTrue MSG_PARSER_BAD_PATTERN_SUFFIX < 1000;
	MSG_PARSER_BAD_PATTERN_SUFFIX:
		"~. Bitte versuche es erneut.";
#EndIf;
#IfTrue MSG_PARSER_NO_IT < 1000;
	MSG_PARSER_NO_IT:
		"Ich weiß nicht auf was sich ~",(address) p_arg_1, "~ bezieht.";
#EndIf;
#IfTrue MSG_PARSER_CANT_SEE_IT < 1000;
	MSG_PARSER_CANT_SEE_IT:
		"Du kannst ~",(address) p_arg_1, "~ (", (name) p_arg_2, ") momentan nicht sehen.";
#EndIf;
#Ifndef SKIP_MSG_CLOSE_NOT_OPEN;
	MSG_CLOSE_NOT_OPEN, MSG_TOUCHABLE_FOUND_CLOSED,
	MSG_PARSER_CONTAINER_ISNT_OPEN:
	! p_arg_1 = the object which isn't open.
		print_ret (CObjIs) p_arg_1, " ist nicht offen.";
#Endif;
#IfTrue MSG_CONSULT_NOTHING_INTERESTING < 1000;
	MSG_CONSULT_NOTHING_INTERESTING:
		"Du findest nichts interessantes in ", (the) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_CUT_NO_USE;
	MSG_CUT_NO_USE, MSG_JUMP_OVER, MSG_TIE_DEFAULT, MSG_CLIMB_DEFAULT:
		"Damit erreichst du nichts.";
#Endif;
#Ifndef SKIP_MSG_LOCK_ALREADY_LOCKED; MSG_UNLOCK_ALREADY_UNLOCKED:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		print_ret (CObjIs) noun, " schon aufgesperrt.";
#Endif;
#Ifndef SKIP_MSG_LOCK_ALREADY_LOCKED;
	MSG_LOCK_ALREADY_LOCKED:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		print_ret (CObjIs) noun, " schon zugesperrt.";
#Endif;
#IfTrue MSG_LOCK_CLOSE_FIRST < 1000;
	MSG_LOCK_CLOSE_FIRST:
		"Zuerst musst du ", (the) noun, " schließen.";
#EndIf;
#Ifndef SKIP_MSG_LOCK_KEY_DOESNT_FIT;
	MSG_LOCK_KEY_DOESNT_FIT, MSG_UNLOCK_KEY_DOESNT_FIT:
		print_ret (The) second, " scheint nicht in das Schloss zu passen.";
#Endif;
#IfTrue MSG_EXAMINE_CLOSED < 1000;
	MSG_EXAMINE_CLOSED:
	! p_arg_1 = the examines object (which is closed).
		print_ret (The) p_arg_1, " ", (isorare) p_arg_1, " geschlossen.";
#Endif;
#IfTrue MSG_REMOVE_NOT_HERE < 1000;
	MSG_REMOVE_NOT_HERE:
		"But ", (the) noun, " ist momentan nicht da.";
#EndIf;
#IfTrue MSG_SEARCH_IN_IT_ISARE < 1000;
	MSG_SEARCH_IN_IT_ISARE:
		print (The) noun, " beinhaltet ";
		PrintContents(0, noun);
		".";
#EndIf;
#IfTrue MSG_SEARCH_ON_IT_ISARE < 1000;
	MSG_SEARCH_ON_IT_ISARE:
		print "Ein ", (the) noun;
		PrintContents(" ", noun, ISARE_BIT);
		".";
#EndIf;
#IfTrue MSG_SEARCH_EMPTY < 1000;
	MSG_SEARCH_EMPTY:
		print_ret (CObjIs) noun, " leer.";
#EndIf;
#IfTrue MSG_SEARCH_NOTHING_ON < 1000;
	MSG_SEARCH_NOTHING_ON:
		"Es ist nichts auf ", (the) noun, ".";
#EndIf;
#IfTrue MSG_SEARCH_CANT_SEE_CLOSED < 1000;
	MSG_SEARCH_CANT_SEE_CLOSED:
		"Du kannst nicht reinschauen, da ", (the) noun, " geschlossen ", (IsorAre) noun, ".";
#EndIf;
#IfTrue MSG_EXAMINE_ONOFF < 1000;
	MSG_EXAMINE_ONOFF:
		print_ret (The) noun, " ", (IsOrAre) noun, " aktuell geschaltet ", (onoff) noun, ".";
#EndIf;
#IfTrue MSG_EAT_DEFAULT < 1000;
	MSG_EAT_DEFAULT:
		"Du isst ", (the) noun, ". Nicht schlecht.";
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
		print_ret (The) p_arg_1, " scheint ", (the) p_arg_2, " zu haben.";
#EndIf;
#IfTrue MSG_TAKE_PART_OF < 1000;
	MSG_TAKE_PART_OF:
		! p_arg_1 = the object that is part of p_arg_2
		print_ret (The) p_arg_1, " scheint ein Teil von ", (the) p_arg_2, " zu sein.";
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
#Ifndef SKIP_MSG_EXAMINE_DARK;
	MSG_EXAMINE_DARK, MSG_SEARCH_DARK:
		"Aber es ist dunkel.";
#Endif;
#Endif;
#Iftrue MSG_SCORE_DEFAULT < 1000;
	MSG_SCORE_DEFAULT:
#Ifdef NO_SCORE;
		"Es gibt keine Punkte in diesem Spiel.";
#Ifnot;
		if (deadflag) print "In diesem Spiel hast du"; else print "Soweit hast du";
		print " erzielt ", score, " von ", MAX_SCORE, " erreichbaren Punkten, in ", turns, " Runden";
		if(turns ~= 1) print "s";
		rtrue;
#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
#IfTrue MSG_FULLSCORE_START < 1000;
	MSG_FULLSCORE_START:
		print "Der Punktestand ";
		if(deadflag) print "kamm so zustande:"; else print "ist so zustande gekommen:";
#EndIf;
#IfTrue MSG_FULLSCORE_END < 1000;
	MSG_FULLSCORE_END:
		"insgesamt (von ", MAX_SCORE, ")";
#EndIf;
#EndIf;
#Ifndef SKIP_MSG_LOOKMODE;
	MSG_LOOKMODE_NORMAL, MSG_LOOKMODE_LONG, MSG_LOOKMODE_SHORT:
		print "Dieses Spiel ist jetzt in seinem ";
		if(lookmode==1) print "normalen ~";
		if(lookmode==2) print "~langen";
		else {
			if(lookmode==3) print "~super";
			print "kurzen";
		}
		print "~ Modus, welcher ";
		if(lookmode ~= 1) print "immer ";
		if(lookmode == 3) print "kurze";
		else print "lange";
		print " Beschreibungen von Orten gibt ";
		if(lookmode == 1)
			"die noch nie besucht wurden, und ansonsten kurze Beschreibungen.";
		print "(selbst wenn du";
		if(lookmode == 2) print " dort schon warst";
		else print " dort noch nicht warst";
#Endif;
#IfTrue MSG_RESTART_RESTORE_OR_QUIT < 1000;
	MSG_RESTART_RESTORE_OR_QUIT:
		print "^Willst du NEUSTART, WIDERHERSTELLEN";
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
		if(deadflag == 2 && AMUSING_PROVIDED == 0) print ", einige Vorschläge für UNTERHALTSAME Aktivitäten sehen";
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
#IfTrue MSG_ENTER_BAD_LOCATION < 1000;
	MSG_ENTER_BAD_LOCATION:
		print "Du musst zuerst ";
		if(player notin location && ~~IndirectlyContains(parent(player), noun))
			print (the) noun, " verlassen";
		else
			print (the) noun, " betreten";
		".";
#EndIf;
#IfTrue MSG_INSERT_NOT_CONTAINER < 1000;
	MSG_INSERT_NOT_CONTAINER:
		! p_arg_1 = the object that can't contain things
		print_ret (The) p_arg_1, " kann Dinge nicht aufbewahren";
#Endif;
#IfTrue MSG_YES_OR_NO < 1000;
	MSG_YES_OR_NO:
		print "Bitte beantworte mit ja oder nein: ";
#EndIf;
#IfTrue MSG_RESTART_CONFIRM < 1000;
	MSG_RESTART_CONFIRM:
		print "Bist du dir sicher, dass du neu starten willst? ";
#Endif;
#Ifndef NO_SCORE;
#Iftrue MSG_PARSER_NEW_SCORE < 1000;
	MSG_PARSER_NEW_SCORE:
		! p_arg_1 = the old score
		print "^[Der Punktestand ";
		if(p_arg_1 < score) {
			p_arg_2 = score - p_arg_1;
			print "stieg";
		} else {
			p_arg_2 = p_arg_1 - score;
			print "sank";
		}
		print " um ", p_arg_2, " Punkt";
		if(p_arg_2 > 1) print "e";
		print ".]^";
#Endif;
#Endif;




#IfDef OPTIONAL_EXTENDED_VERBSET;
#IfTrue MSG_BLOW_DEFAULT < 1000;
	MSG_BLOW_DEFAULT:
		"Du kannst ", (the) noun, " nicht sinvoll blasen.";
#EndIf;
#IfTrue MSG_EMPTY_ALREADY_EMPTY < 1000;
	MSG_EMPTY_ALREADY_EMPTY:
		! p_arg_1 = the object that is already empty
		print_ret (The) p_arg_1, " ", (isorare) p_arg_1, " schon leer.";
#EndIf;
#IfTrue MSG_SET_DEFAULT < 1000;
	MSG_SET_DEFAULT:
		"Nein, du kannst nicht ", (thatorthose) noun, " einstellen.";
#EndIf;
#IfTrue MSG_SET_TO_DEFAULT < 1000;
	MSG_SET_TO_DEFAULT:
		"Nein, du kannst nicht ", (thatorthose) noun, " zu etwas einstellen.";
#EndIf;
#IfTrue MSG_WAVE_DEFAULT < 1000;
	MSG_WAVE_DEFAULT:
		"Du siehst stupide aus, wenn du mit ", (the) noun, " winkst.";
#EndIf;
#EndIf;

default:
		! No code found. Print an error message.
		_RunTimeError(ERR_UNKNOWN_MSGNO);
	}
];

[ ThatorThose obj;
	if (obj has pluralname) print "diese"; else print "das";
];

[ ItorThem obj;
	if (obj == player) { print "du selbst"; rtrue; }
	if (obj has pluralname) { print "sie"; rtrue; }
	if (obj has female) { print "sie"; rtrue; }
	if (obj has neuter) { print "es"; rtrue; }
	print "er";
];

[ CObjIs p_obj;
	print (The) p_obj, " ", (isorare) p_obj;
];

[ IsorAre obj;
	if (obj has pluralname || obj == player) print "sind"; else print "ist";
];

[ CTheyreorThats obj;
	if (obj == player)			 { print "Du bist"; return; }
	if (obj has pluralname)		{ print "Sie sind"; return; }
	if (obj has female)		{ print "Sie ist"; return; }
	if (obj has neuter) { print "Es ist"; return; }
	print "Er ist";
];

[ CTheyreorIts p_obj;
	if(p_obj ~= player && p_obj hasnt pluralname && p_obj hasnt animate) {
    if (p_obj has female)
      print "Sie ist";
    else if (p_obj has neuter)
  		print "Es ist";
    else
      print "Er ist";
		return;
	}
	CTheyreorThats(p_obj);
];

[OnOff obj;
	if(obj has on) print "ein";
	else print "aus";
	return;
];


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

[_RunTimeError p_err p_obj _parent;
	print "^[PunyInform Fehler: ";
	if(p_err ofclass string)
		print (string) p_err;
	else {
		print p_err;
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
		print " - ";
		switch(p_err) {
		ERR_TOO_MANY_TIMERS_DAEMONS:
			print "Zu viele Timer/daemons";
		ERR_OBJECT_HASNT_PROPERTY:
			print "Objekt fehlt erforderliche Eigenschaft";
		ERR_SCOPE_FULL:
			print "Umfang voll";
		ERR_UNKNOWN_MSGNO:
			print "Unbekannte Nachricht#";
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
		default:
			print "Unbekannter Fehler";
		}
#EndIf;
	}
	print "]^";
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
	if(p_obj ofclass object) {
		_parent = parent(p_obj);
		print "Verletzendes Objekt: ", (the) p_obj, " (", p_obj, ") in ", (name) _parent, " (", _parent, ")^"; 
	}
#Ifnot;
	_parent = p_obj; ! Avoid compiler warning
#EndIf;
	rtrue;
];
