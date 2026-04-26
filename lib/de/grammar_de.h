! Part of PunyInformDE: German localisation of PunyInform.
! This file replaces grammar.h with German verb definitions.
! It first includes the base English grammar.h, then adds German synonyms.
!
! German verb definitions follow the tradition of using the second-person
! imperative singular (du-form) as the command word.
! Special characters: digraphs ae/oe/ue/ss are used for umlauts/Eszett
! for z3 compatibility; they map to ä/ö/ü/ß in z5+.
!
System_file;

! ---------------------------------------------------------------------------
! German room/container contents listing functions.
! Defined BEFORE Include "grammar.h" so that grammar.h's #IfNDef guards skip
! the English defaults. LISTOBJS_ROOM_SUFFIX = ".^" is set in globals_de.h.
! ---------------------------------------------------------------------------

[ _ListObjsMsg p_parent  _count;
	_count = PrintContents(1, p_parent, 0); ! count without printing
	print "^";
	if(_count == 2) print "Hier befinden sich ";
	else print "Hier ist ";
	if(also_flag) print "auch ";
];

[ _ListObjsInOnMsg p_parent  _count;
	_count = PrintContents(1, p_parent, 0);
	print "^";
	if(p_parent has supporter) print "Auf "; else print "In ";
	print (the) p_parent;
	if(_count == 2) print " befinden sich "; else print " ist ";
	if(also_flag) print "auch ";
];

! Include the base English grammar (actions and action subs)
Include "grammar.h";

! ---------------------------------------------------------------------------
! PrintVerb is intentionally NOT defined here.
! VerbName() in grammar.h will print German verb words naturally by calling
! print (address) p_v, which gives the correct German verb word.
! If you need to override how a specific verb is printed, define PrintVerb
! in your game file before including globals.h.
! ---------------------------------------------------------------------------

! German meta verbs
! ---------------------------------------------------------------------------

Extend 'again' first
	*                                           -> Again;
Verb meta 'erneut' 'nochmal'
	*                                           -> Again;

Verb meta 'beende' 'ende'
	*                                           -> Quit;

Verb meta 'lade'
	*                                           -> Restore;

Verb meta 'neustart'
	*                                           -> Restart;

Verb meta 'speicher'
	*                                           -> Save;

Verb meta 'punkte' 'punktestand'
	*                                           -> Score;

Extend 'version' first
	*                                           -> Version;

Verb meta 'knapp'
	*                                           -> LookModeNormal;

Verb meta 'ausfuehrlich'
	*                                           -> LookModeLong;

Verb meta 'superknapp'
	*                                           -> LookModeShort;

#IfDef OPTIONAL_EXTENDED_METAVERBS;
#Ifndef NO_PLACES;
! 'orte'/'objekte' alias existing English meta verbs (only if OPTIONAL_EXTENDED_METAVERBS)
Verb 'orte' = 'places';
Verb 'objekte' = 'objects';
#EndIf;
#EndIf; ! OPTIONAL_EXTENDED_METAVERBS

#Ifdef OPTIONAL_EXTENDED_METAVERBS;
Verb meta 'skript' 'transkript'
	*                                           -> ScriptOn
	* 'an'/'ein'                                -> ScriptOn
	* 'aus'                                     -> ScriptOff;
#EndIf;

! ---------------------------------------------------------------------------
! German game verbs
! ---------------------------------------------------------------------------

! --- Take / Pick up ---
Verb 'nimm' 'hol' 'nehm'
	* multi                                     -> Take
	* 'auf' multi                               -> Take
	* multi 'auf'                               -> Take
	* multiinside 'aus' noun                    -> Remove
	* multiinside 'von' noun                    -> Remove;

Verb 'greif'
	* multi                                     -> Take
	* 'nach' multi                              -> Take
	* creature 'an'                             -> Attack;

Verb 'fass'
	* noun 'an'                                 -> Touch;

! --- Drop ---
Verb 'schmeiß' 'wirf'
	* multiheld                                 -> Drop
	* multiheld 'fallen'/'hin'/'hier'/'ab'/'weg' -> Drop
	* multiheld 'aus' 'der'/'dem'/'den'/'die' noun -> Remove
	* multiheld 'aus' noun                      -> Remove
	* multiexcept 'in'/'hinein' noun            -> Insert
	* multiexcept 'auf' noun                    -> PutOn;

! --- Look / Examine ---
Verb 'schau' 'seh' 'sieh' 'guck' 'blick' 'u//'
	*                                           -> Look
	* 'dich' 'um'                               -> Look
	* 'um'                                      -> Look
	* noun                                      -> Examine
	* 'an' noun                                 -> Examine
	* noun 'an'                                 -> Examine
	* 'in' noun                                 -> Search
	* 'auf' noun                                -> Examine
	* 'unter' noun                              -> Search;

Verb 'untersuch' 'betracht' 'inspizier'
	* noun                                      -> Examine;

! --- Open ---
Verb 'öffne' 'entkork'
	* noun                                      -> Open
	* noun 'mit' held                           -> Unlock;

! --- Close / Lock / Unlock via schließ ---
Verb 'schließ'
	* noun 'auf' 'mit' held                     -> Unlock
	* noun 'mit' held 'auf'                     -> Unlock
	* noun 'auf'                                -> Unlock
	* noun 'zu'/'ab' 'mit' held                 -> Lock
	* noun 'mit' held 'zu'/'ab'                 -> Lock
	* noun 'zu'/'ab'                            -> Lock
	* noun                                      -> Close;

! --- mach (multi-purpose German verb: mach auf/zu/an/aus) ---
Verb 'mach'
	* noun 'auf'                                -> Open
	* noun 'zu'                                 -> Close
	* noun 'an'                                 -> SwitchOn
	* noun 'aus'                                -> SwitchOff
	* noun 'kaputt'                             -> Attack
	* 'auf' noun                                -> Open
	* 'zu' noun                                 -> Close
	* 'an' noun                                 -> SwitchOn
	* 'aus' noun                                -> SwitchOff;

! --- Inventory ---
Verb 'inventar' 'besitz'
	*                                           -> Inv;

! --- Wait ---
Verb 'wart'
	*                                           -> Wait;

! --- Go ---
#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'geh' 'lauf' 'renn' 'wander' 'flücht' 'flieh'
	* noun=ADirection                           -> Go
	* 'nach' noun=ADirection                    -> Go
	* noun                                      -> Enter
	* 'in' noun                                 -> Enter
	* 'raus'/'hinaus'/'heraus'                  -> Exit
	* 'rein'/'hinein'/'herein'                  -> GoIn;
#IfNot;
Verb 'geh' 'lauf' 'renn' 'wander' 'flücht' 'flieh'
	* noun=ADirection                           -> Go
	* 'nach' noun=ADirection                    -> Go
	* noun                                      -> Enter
	* 'in' noun                                 -> Enter
	* 'raus'/'hinaus'/'heraus'                  -> Exit;
#EndIf;

Verb 'verlass'
	*                                           -> Exit
	* noun                                      -> Exit;

Verb 'betret' 'betritt'
	* noun                                      -> Enter;

! --- Give / Show ---
Verb 'gib' 'reich'
	* held 'an' creature                        -> Give
	* held creature                             -> Give
	* creature held                             -> Give reverse;

Verb 'zeig' 'präsentier'
	* creature held                             -> Show reverse
	* held creature                             -> Show
	* held 'an' creature                        -> Show
	* creature held 'vor'                       -> Show reverse;

! --- Put in / Put on / Drop ---
Verb 'stell' 'steck' 'tu'
	* multiheld                                 -> Drop
	* multiheld 'ab'/'hin'/'weg'/'nieder'       -> Drop
	* multiexcept 'in'/'hinein' noun            -> Insert
	* multiexcept 'auf' noun                    -> PutOn
	* multiexcept noun                          -> Insert
	* 'an' held                                 -> Wear;

Verb 'leg'
	* multiheld                                 -> Drop
	* multiexcept 'in' noun                     -> Insert
	* multiexcept 'auf' noun                    -> PutOn;

! --- Wear ---
Verb 'trag'
	* held                                      -> Wear;

Verb 'zieh'
	* worn 'aus'                                -> Disrobe
	* held 'an'                                 -> Wear
	* noun 'an'                                 -> Pull
	* noun                                      -> Pull;

! --- Ask / Tell ---
Verb 'frag'
	* creature 'nach' topic                     -> Ask
	* creature 'fuer'/'um' noun                 -> AskFor
	* creature 'zu' topic                       -> AskTo;

Verb 'bitt'
	* creature 'um' noun                        -> AskFor;

Verb 'erzähl' 'bericht'
	* creature 'über' topic                     -> Tell
	* creature 'von' topic                      -> Tell;

Verb 'sag' 'sprich' 'antwort'
	* topic 'zu' creature                       -> Answer
	* creature topic                            -> Tell;

! --- Drink ---
Verb 'trink' 'sauf'
	* noun                                      -> Drink;

! --- Eat ---
Verb 'iss' 'fris' 'ess'
	* held                                      -> Eat;

! --- Listen ---
Verb 'hör' 'lausch'
	*                                           -> Listen
	* 'auf' noun                                -> Listen
	* noun                                      -> Listen;

! --- Smell ---
Verb 'riech' 'schnupper'
	*                                           -> Smell
	* noun                                      -> Smell;

! --- Touch / Feel ---
Verb 'berühr' 'fühl' 'tast'
	* noun                                      -> Touch;

! --- Search ---
Verb 'durchsuch' 'such'
	* noun                                      -> Search
	* 'in' noun                                 -> Search;

! --- Read ---
Verb 'lies' 'les'
	* noun                                      -> Examine;

! --- Lock / Unlock ---
Verb 'verriegel'
	* noun 'mit' held                           -> Lock
	* noun                                      -> Lock;

Verb 'entriegel' 'aufschließ' 'entsperr'
	* noun 'mit' held                           -> Unlock
	* noun                                      -> Unlock;

! --- Switch on/off ---
Verb 'schalt'
	* noun 'an'                                 -> SwitchOn
	* noun 'aus'                                -> SwitchOff
	* 'an' noun                                 -> SwitchOn
	* 'aus' noun                                -> SwitchOff;

! --- Attack ---
Verb 'hau' 'schlag' 'tritt' 'töt' 'zerstör' 'erschlag'
	* noun                                      -> Attack
	* noun 'mit' held                           -> Attack;

! --- Climb ---
Verb 'kletter' 'steig'
	* noun                                      -> Climb
	* 'hoch' noun                               -> Climb
	* noun 'hoch'                               -> Climb
	* 'auf' noun                                -> Enter;

! --- Jump ---
Verb 'spring'
	*                                           -> Jump
	* 'über' noun                               -> JumpOver
	* 'in'/'auf' noun                           -> Enter;

! --- Push / Pull / Turn ---
Verb 'schieb' 'drück' 'stoß'
	* noun                                      -> Push
	* noun noun=ADirection                      -> PushDir;

Verb 'dreh' 'kurbel'
	* noun                                      -> Turn;

! --- Dig ---
Verb 'grab' 'buddel'
	* noun                                      -> Dig
	* noun 'mit' held                           -> Dig;

! --- Fill ---
Verb 'füll' 'befüll'
	* noun                                      -> Fill;

! --- Cut ---
Verb 'schneid' 'hack'
	* noun                                      -> Cut
	* noun 'mit' held                           -> Attack;

! --- Tie ---
Verb 'bind' 'befestig' 'knot'
	* noun                                      -> Tie
	* noun 'an' noun                            -> Tie;

! --- Shout ---
Verb 'schrei' 'ruf' 'brüll'
	* topic 'zu' creature                       -> Answer
	* noun 'an'                                 -> ShoutAt
	* topic                                     -> Shout
	*                                           -> Shout;

! --- Rub / Clean ---
Verb 'reib' 'putz' 'wisch' 'polier'
	* noun                                      -> Rub;

! --- Squeeze (only in extended verbset) ---
#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'quetsch' 'press'
	* noun                                      -> Squeeze;
#EndIf;

! --- Sit / Stand / Lie ---
Verb 'sitz'
	* 'auf' noun                                -> Enter
	* 'in' noun                                 -> Enter;

Verb 'steh'
	*                                           -> Exit
	* 'auf'                                     -> Exit
	* 'von' noun 'auf'                          -> GetOff;

Verb 'lieg'
	* 'auf' noun                                -> Enter;

! --- Yes / No ---
! Note: 'ja', 'j//' and 'nein' are added to the dictionary via parser.h (YesOrNo function),
! so they work as answers to yes/no prompts even without OPTIONAL_EXTENDED_VERBSET.
#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'ja' 'j//'
	*                                           -> Yes;
Verb 'nein'
	*                                           -> No;
#EndIf;

! --- Transfer (push to location) ---
Verb 'bring'
	* noun noun=ADirection                      -> PushDir;

#Ifdef OPTIONAL_EXTENDED_VERBSET;
! --- Extended verbset German synonyms ---

! Burn
Verb 'verbrenn' 'zünd' 'entzünd'
	* noun                                      -> Burn
	* noun 'an'                                 -> Burn
	* noun 'mit' held                           -> Burn
	* noun 'mit' held 'an'                      -> Burn;

! Buy
Verb 'kauf'
	* noun                                      -> Buy;

! Consult
Verb 'schlage'
	* topic 'nach'                              -> Consult
	* 'in' noun 'nach' topic 'nach'             -> Consult reverse;

! Empty
Verb 'leer' 'schütt'
	* noun                                      -> Empty
	* noun 'aus'                                -> Empty;

! Kiss
Verb 'umarm' 'küss'
	* noun                                      -> Kiss;

! Pray
Verb 'bet'
	*                                           -> Pray;

! Set / Adjust
Verb 'stelle'
	* noun 'ein'                                -> Set
	* noun 'auf' topic 'ein'                    -> SetTo;

! Sing
Verb 'sing'
	*                                           -> Sing;

! Sleep
Verb 'schlaf'
	*                                           -> Sleep;

! Sorry
Verb 'entschuldig' 'verzeih'
	*                                           -> Sorry;

! Swim
Verb 'schwimm' 'tauch'
	*                                           -> Swim;

! Swing
Verb 'schaukel'
	* noun                                      -> Swing;

! Taste
Verb 'probier' 'kost' 'schmeck'
	* noun                                      -> Taste;

! Think
Verb 'denk' 'überleg'
	*                                           -> Think;

! Transfer
Verb 'transportier' 'bring'
	* noun 'zu' noun                            -> Transfer;

! Wake
Verb 'weck'
	*                                           -> Wake
	* noun                                      -> WakeOther;

! Wave
Verb 'wink'
	*                                           -> WaveHands
	* noun                                      -> Wave
	* noun 'zu'                                 -> Wave;

! Blow
Verb 'blas'
	* noun                                      -> Blow;

! Strong/Mild language - German expletives
Verb 'mist' 'scheiß' 'verflucht' 'verdammt' 'verflixt' 'fuck'
	*                                           -> Mild;
#EndIf; ! OPTIONAL_EXTENDED_VERBSET
