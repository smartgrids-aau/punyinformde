# German Grammar Analysis: Articles, Pronouns, Adjective Inflection

## Overview

This document analyses three known issues in PunyInformDE by examining how
the **deform** library (a full German Inform 6 library, Release 6/11, 2005–2010
by Martin Oehm) solved them. It proposes concrete implementation plans and
shows how the solutions would look in `sterne.inf`.

The deform source files examined are in `c:\Source\informtest\deform\`:
- `German.h` — language engine, article tables, printing, input normalisation
- `GermanG.h` — grammar (verb definitions)

The Inform 7 extension **German.i7x** (Team GerX, v4/230629, by Frank Gerbig
et al., `c:\Source\fiction\Staub\Staub.materials\Extensions\Team GerX\German.i7x`)
was also examined.  It is an I7 adaptation of deform 6/11, substantially
extending it with a `grammatical_gender` property, inline gender markers, a
changing-gender system, pronominal adverbs, and a libcheck tool.  Where it
offers alternative designs, these are noted per section.

**Performance constraint**: PunyInform targets old 8-bit hardware via
Z-machine interpreters (1 MHz effective throughput, ~64 KB story file).
Every extra array entry, property, or per-command function call has real
cost.  All solutions below are evaluated against this constraint.

**Documentation requirement**: After implementing any feature in §1–§3,
create (or update) `docs/Implementation.md` recording what was built,
crediting the source algorithms, and listing known limitations.  See §5.

---

## 1. Article System: Cases (Nominativ, Akkusativ, Dativ)

### The Problem

Current PunyInformDE knows three print-forms for an object name:
- `FORM_CDEF` → "Die Seekiste" / "Der Schlüssel" / "Das Fernrohr"
- `FORM_DEF`  → "die Seekiste" / "der Schlüssel" / "das Fernrohr"
- `FORM_INDEF` → uses the `article` property: "eine Seekiste" / "ein Schlüssel"

All three forms are **Nominative only**. German grammar requires four cases:

| Case        | m (der)  | f (die)   | n (das)  | pl (die)  |
|-------------|----------|-----------|----------|-----------|
| Nominativ   | der/ein  | die/eine  | das/ein  | die/-     |
| Genitiv     | des/eines| der/einer | des/eines| der/-     |
| Dativ       | **dem/einem**| der/einer | **dem/einem**| den/- |
| Akkusativ   | **den/einen**| die/eine  | das/ein  | die/-     |

IF messages constantly need Akkusativ and Dativ:
- "Du legst **den** Schlüssel in **die** Kiste." (Akk noun, Akk second)
- "Du gibst **dem** Kapitän **die** Karte." (Dat second, Akk noun)
- "Du schließt **die** Tür auf." (Akk — currently happens to look correct for fem.)
- "Du kannst nicht mit **dem** Schlüssel öffnen." (Dat)

The current code silently prints Nominative everywhere, so masculine objects
in Akkusativ ("den Schlüssel") come out as "der Schlüssel" — grammatically wrong.

### How Deform Solves It

**Key globals** (`German.h` lines 125–135):
```inform
Global short_name_case;    ! Current grammatical case (Nom/Gen/Dat/Akk)
Constant Nom = 0;
Constant Gen = 1;
Constant Dat = 2;
Constant Akk = 3;
```

**Article table** (`German.h` lines 1565–1585) — indexed by
`[article_type * 16 + case * 4 + gender]`:
```inform
Array LanguageArticles -->
        "die "  "der " "die " "das "    ! def, Nom: pl m f n
        "der "  "des " "der " "des "    ! def, Gen
        "den "  "dem " "der " "dem "    ! def, Dat
        "die "  "den " "die " "das "    ! def, Akk
        0       "ein " "eine " "ein "   ! indef, Nom
        ...
```

**`Gender(obj)` function** returns 0=plural, 1=male, 2=female, 3=neuter
by checking `pluralname`, `male`, `female`, `neuter` attributes in order.

**Case-specific print functions** (`German.h` lines ~1980–2000):
```inform
[ der obj; DefArt(obj, Nom); ];
[ des obj; DefArt(obj, Gen); ];
[ dem obj; DefArt(obj, Dat); ];
[ den obj; DefArt(obj, Akk); ];
[ ein   obj; IndefArt(obj, Nom); ];
[ einen obj; IndefArt(obj, Akk); ];
[ einem obj; IndefArt(obj, Dat); ];
```

Messages use these as print rules:
```inform
  Close:  "Du schließt ", (den) x1, ".";   ! Akk
  Unlock: "Du schließt ", (den) x1, " auf.";
  Insert: "Du legst ", (den) x1, " in ", (die) x2, ".";  ! Akk, Akk
  Give:   "Du gibst ", (dem) x2, " ", (den) x1, ".";    ! Dat, Akk
```

`SetLowStrings(case, gender)` also pre-computes adjective endings into
low-strings `@01`–`@04` (noun case endings like "-n" in Dativ) and
`@00` (adjective suffix, see §3 below).

### Implementation Plan for PunyInformDE

**Step A — Case constants and global** (in `lib/de/globals_de.h`):
```inform
Constant Nom = 0;
Constant Gen = 1;
Constant Dat = 2;
Constant Akk = 3;
Global short_name_case = 0;    ! Default: Nominative
```

**Step B — Gender helper function** (in `lib/de/globals_de.h` or new
`lib/de/article_de.h`):
```inform
[ DE_Gender obj;
    if (obj has pluralname) return 0;   ! plural
    if (obj has male)       return 1;   ! masculine
    if (obj has female)     return 2;   ! feminine
    return 3;                           ! neuter (default)
];
```

(PunyInformDE already uses `female`/`neuter` attributes.  The `male`
attribute is needed for NPC objects or objects that are grammatically
masculine but not using the default.  Objects without any gender attribute
default to masculine — matching current behaviour.)

**Step C — Article tables** (in `lib/de/article_de.h`, new file):
```inform
Array DE_DefArticles -->
    ! Nom   Gen   Dat   Akk    (order: pl m f n per case)
    "die " "der " "die " "das "    ! Nom
    "der " "des " "der " "des "    ! Gen
    "den " "dem " "der " "dem "    ! Dat
    "die " "den " "die " "das "    ! Akk
    ;

Array DE_IndefArticles -->
    0      "ein " "eine " "ein "   ! Nom (plural has no indefinite)
    0      "eines " "einer " "eines "  ! Gen
    0      "einem " "einer " "einem "  ! Dat
    0      "einen " "eine " "ein "     ! Akk
    ;
```

**Step D — Article print functions**:
```inform
[ DE_DefArt obj case  g;
    g = DE_Gender(obj);
    print (string) DE_DefArticles-->(case * 4 + g);
    PrintShortName(obj);
];

[ DE_IndefArt obj case  g s;
    g = DE_Gender(obj);
    s = DE_IndefArticles-->(case * 4 + g);
    if (s) print (string) s; else print "einige ";
    PrintShortName(obj);
];

! Shorthand print-rule functions
[ der   obj; DE_DefArt(obj, Nom); ];    ! "der Schlüssel"
[ die   obj; DE_DefArt(obj, Nom); ];    ! "die Kiste"  (alias, same as Nom fem)
[ das   obj; DE_DefArt(obj, Nom); ];    ! "das Fernrohr"
[ dem   obj; DE_DefArt(obj, Dat); ];    ! "dem Schlüssel"
[ den   obj; DE_DefArt(obj, Akk); ];    ! "den Schlüssel"
[ GDer  obj; print (char) 'D'; der(obj); ];  ! capitalised "Der/Die/Das"
[ GDen  obj; print (char) 'D'; den(obj); ];  ! "Den/Die/Das"
[ GDem  obj; print (char) 'D'; dem(obj); ];  ! "Dem/Der/Dem"
```

Note: `der`/`die`/`das` as print-rule function names are short enough to
clash with dictionary words in some contexts, but Inform 6 resolves this
correctly since print rules are called only as `(der) obj`.

**Step E — Update messages_de.h** to use case-correct articles where needed:
```inform
MSG_UNLOCK_NOT_A_LOCK:
    print_ret (GDas) noun, " hat kein Schloss.";   ! neuter 
MSG_CLOSE_YOU_CANT:
    print_ret "Du kannst ", (den) noun, " nicht schließen.";
MSG_LOCK_CLOSE_FIRST:
    print_ret "Du musst ", (den) noun, " zuerst schließen.";
MSG_INSERT_DEFAULT:
    "Du legst ", (den) noun, " in ", (die) second, ".";
MSG_PUTON_DEFAULT:
    "Du legst ", (den) noun, " auf ", (den) second, ".";
MSG_GIVE_DEFAULT:
    print_ret (GDer) second, " scheint nicht interessiert zu sein.";
```

**Example impact in sterne.inf** — current vs. proposed output:

```
>> nimm schluessel
Genommen.       ← no article needed here, fine

>> steck schluessel in kiste
Current:  "Du legst der Schlüssel in die Seekiste."  ← wrong "der"
Fixed:    "Du legst den Schlüssel in die Seekiste."  ← correct Akk

>> gib karte kapitaen
Current:  "Der Kapitän scheint nicht interessiert zu sein."  ← ok
Fixed:    "Dem Kapitän scheint das egal zu sein."  ← example with Dat
```

**Effort estimate**: Medium. ~150 lines of new code in `article_de.h`,
~30 message edits in `messages_de.h`, 4 lines in `globals_de.h`.
Does **not** require touching `puny.h`.

> **German.i7x comparison**: German.i7x uses the identical `short_name_case`
> global (0-indexed Nom/Gen/Dat/Akk) and `LanguageArticles` array layout,
> confirming this design.  One difference: I7 GerX uses a `grammatical_gender`
> **property** (0=plural, 1=masc, 2=fem, 3=neuter) instead of attributes.
> It also supports inline gender markers in the printed name — e.g.
> `short_name "Schlüssel[m]"` sets gender during name printing via a text
> substitution.  The inline-marker approach adds a Gobble/print-to-buffer
> call on every name print; for PunyInform's old-computer target the
> attribute approach is better (a `has` test is a single VM opcode).
>
> **Memory**: `DE_DefArticles` (16 words) + `DE_IndefArticles` (16 words) =
> 64 bytes.  `DE_Gender()` is 3 attribute tests — negligible.

---

## 2. Pronouns

### The Problem

PunyInform's parser (`parser.h` line 858) recognises exactly four pronoun
dictionary words:
```inform
if(_k == 'it' or 'him' or 'her' or 'them') { ... }
```

German pronouns in player input — `er`, `sie`, `es`, `ihn`, `ihm`, `ihr`,
`ihnen` — are simply unknown words to the parser.  The player types:

```
>> oeffne kiste
Du öffnest die Seekiste.
>> schau in sie          ← natural German
Ich verstehe dieses Verb nicht.   ← parser sees "sie" as unknown noun
```

### How Deform Solves It

`German.h` defines `LanguagePronouns` (a table used by the full Inform 6
parser's built-in pronoun mechanism, lines ~330–355):
```inform
Array LanguagePronouns table
    'er'     $$100000100000   NULL   ! m-Nom  → himobj equivalent
    'sie'    $$010111010111   NULL   ! f-Nom/Akk + all plurals
    'es'     $$001000001000   NULL   ! n-Nom/Akk
    'ihn'    $$100000100000   NULL   ! m-Akk
    'ihm'    $$101000101000   NULL   ! m/n-Dat
    'ihr'    $$010000010000   NULL   ! f-Dat
    'ihnen'  $$000111000111   NULL   ! p-Dat
    ;
```

This table is interpreted by the full Inform 6 parser which maintains a
pronoun→object mapping updated after each successful parse.  The full parser
does gender/animateness matching via the GNA bit patterns.

### PunyInform's Pronoun Architecture

PunyInform uses a **simplified 4-slot model** (`itobj`, `himobj`, `herobj`,
`themobj`) with no GNA table.  `PronounNotice(obj)` (parser.h ~line 2000)
assigns objects to slots:
```inform
[ PronounNotice p_object;
    if (p_object has pluralname)     themobj = p_object;
    else if (p_object has animate) {
        if (p_object has female)     herobj = p_object;
        else if (p_object has neuter) itobj = p_object;
        else                          himobj = p_object;
    } else itobj = p_object;
];
```

Objects without `animate` all go to `itobj`.  Most game objects (Seekiste,
Schlüssel, Tür) are inanimate, so they land in `itobj`.  This is fine:
German "es" / "sie" (for a feminine inanimate object) should resolve to the
last touched inanimate object.

### Implementation Plan for PunyInformDE

**Architecture constraint**: All German-specific logic must live in `lib/de/`.
`lib/parser.h` (the shared base) must not be modified for this feature.
The existing `BeforeParsing` hook in `parser_de.h` is the natural place.

#### Approach: BeforeParsing Pass 3 — buffer byte substitution

`parser_de.h` already manipulates the raw input buffer in Pass 1
(digraph→umlaut) and Pass 2 (umlaut expand + verb -e stripping), ending
each pass with a `VM_Tokenise` call.  Pass 3 follows the same pattern:
scan the parse array for German pronoun words; for any match whose
corresponding slot (`himobj`/`herobj`/`itobj`/`themobj`) is non-zero,
overwrite the buffer bytes with the English equivalent, then call
`VM_Tokenise` once.  The main parser in `parser.h` then sees the
familiar English pronoun words and resolves them normally.

No modification to `parser.h` is needed.

**Pronoun mapping** (slot checks are pre-conditions):

| German | Len | Slot | English | Len | Buffer operation |
|--------|-----|------|---------|-----|-----------------|
| `er`   | 2   | `himobj` | `him`  | 3 | +1: shift buffer right from word end |
| `ihn`  | 3   | `himobj` | `him`  | 3 | overwrite bytes 0–2 in-place |
| `ihm`  | 3   | `himobj` | `him`  | 3 | overwrite bytes 0–2 in-place |
| `sie`  | 3   | `herobj` | `her`  | 3 | overwrite in-place (preferred when `herobj≠0`) |
| `sie`  | 3   | `themobj`| `them` | 4 | +1: shift buffer right from word end (fallback when `herobj=0`) |
| `es`   | 2   | `itobj`  | `it`   | 2 | overwrite in-place |
| `ihnen`| 5   | `themobj`| `them` | 4 | overwrite bytes 0–3, write space at byte 4, decrement length by 1 |

> **`ihr` is excluded**.  The word `ihr` serves triple duty in German
> (3rd-pers-fem Dativ pronoun; possessive article "ihr Haus"; 2nd-pers-pl
> "ihr geht").  A naive substitution would break "zeig ihr haus an" →
> "zeig her haus an", confusing the parser.  Players can use `sie` in
> dative contexts or rephrase without the pronoun.  Document as known
> limitation in `Implementation.md`.

**Buffer shift helper** (only needed for `er`→`him` and `sie`→`them`):

```inform
[ _DE_ShiftRight1 p_off  i;
    ! Shift bytes at offset p_off..end of buffer right by one position.
    ! Z-machine: buffer->1 is length, buffer starts at index 2.
    i = 2 + buffer->1;     ! one past last char
    while (i > p_off) { buffer->i = buffer->(i-1); i--; }
    buffer->1 = buffer->1 + 1;
];
```

This is a simple O(n) loop where n is the remaining bytes in the buffer
after the pronoun — typically under 30 chars.  Cost is negligible.

**Pass 3 implementation sketch** (to be called from `BeforeParsing` after
the final `VM_Tokenise` of Pass 2):

```inform
[ _DE_SubstitutePronouns  wn wc wl ws  b0 b1 b2;
    ! Walk the parse array.  Replace any German pronoun whose slot is set.
    ! Return after the first substitution (re-tokenise and restart if needed).
    wc = parse->1;
    for (wn = 1 : wn <= wc : wn++) {
        wl = parse->(wn * 4);       ! word length
        ws = parse->(wn * 4 + 1);   ! start offset in buffer (Z-machine)
        b0 = buffer->ws;
        b1 = buffer->(ws + 1);
        if (wl >= 3) b2 = buffer->(ws + 2); else b2 = 0;

        ! --- 2-byte pronouns ---
        if (wl == 2 && b0 == 'e') {
            if (b1 == 'r' && himobj ~= 0) {   ! 'er' → 'him'
                _DE_ShiftRight1(ws + 2);
                buffer->ws = 'h'; buffer->(ws+1) = 'i'; buffer->(ws+2) = 'm';
                VM_Tokenise(buffer, parse); return;
            }
            if (b1 == 's' && itobj ~= 0) {    ! 'es' → 'it'
                buffer->ws = 'i'; buffer->(ws+1) = 't';
                VM_Tokenise(buffer, parse); return;
            }
        }

        ! --- 3-byte pronouns ---
        if (wl == 3) {
            if (b0 == 'i' && b1 == 'h') {
                if (b2 == 'n' && himobj ~= 0) {   ! 'ihn' → 'him'
                    buffer->(ws+2) = 'm';
                    VM_Tokenise(buffer, parse); return;
                }
                if (b2 == 'm' && himobj ~= 0) {   ! 'ihm' → 'him'
                    buffer->ws = 'h'; buffer->(ws+1) = 'i';
                    VM_Tokenise(buffer, parse); return;
                }
            }
            if (b0 == 's' && b1 == 'i' && b2 == 'e') {   ! 'sie'
                if (herobj ~= 0) {              ! feminine → 'her'
                    buffer->ws = 'h'; buffer->(ws+1) = 'e'; buffer->(ws+2) = 'r';
                    VM_Tokenise(buffer, parse); return;
                }
                if (themobj ~= 0) {             ! plural → 'them' (+1)
                    _DE_ShiftRight1(ws + 3);
                    buffer->ws='t'; buffer->(ws+1)='h';
                    buffer->(ws+2)='e'; buffer->(ws+3)='m';
                    VM_Tokenise(buffer, parse); return;
                }
            }
        }

        ! --- 5-byte pronoun ---
        if (wl == 5 && b0 == 'i' && b1 == 'h'
                && buffer->(ws+2) == 'n'
                && buffer->(ws+3) == 'e'
                && buffer->(ws+4) == 'n'
                && themobj ~= 0) {              ! 'ihnen' → 'them' (shrink)
            buffer->ws='t'; buffer->(ws+1)='h';
            buffer->(ws+2)='e'; buffer->(ws+3)='m';
            buffer->(ws+4) = ' ';              ! overwrite 'n' with space
            buffer->1 = buffer->1 - 1;
            VM_Tokenise(buffer, parse); return;
        }
    }
];
```

> **Design note**: The function returns after the first substitution and
> re-tokenises.  This keeps things simple.  A command with two pronouns
> (e.g., "gib es ihm") would process on the next iteration of BeforeParsing
> — but BeforeParsing runs only once per command.  To handle multiple
> pronouns in a single command, the caller loop should call
> `_DE_SubstitutePronouns` in a loop until no further changes occur.
> In practice, most IF commands contain at most one pronoun.

**Also required: minimal `PronounNotice` patch in `puny.h`**

Currently `PronounNotice` only maps feminine **animate** objects to
`herobj`; inanimate objects of any gender go to `itobj`.  A minimal
`#IfDef LANG_DE` block inside `PronounNotice` makes inanimate feminine
objects also map to `herobj`, so "die Kiste → sie" works.  This is a
small hook (6 lines) that must live in `puny.h` because `PronounNotice`
is called from deep inside the parser loop:

```inform
! In puny.h, PronounNotice, the else-branch for inanimate objects:
    } else {
#IfDef LANG_DE;
        if (p_object has female)       herobj = p_object;
        else if (p_object has neuter)  itobj  = p_object;
        else { himobj = p_object; itobj = p_object; }
#IfNot;
        itobj = p_object;
#EndIf; ! LANG_DE
    }
```

The implementation logic itself (the gender check) stays trivial —
no lookup tables, no function calls, just three attribute tests.

> **German.i7x comparison**: German.i7x's `PersonalPronouns` array
> (`"sie"/"es"/"er"/"sie"` per case) is for **output** only — printing
> "er/ihn/ihm" in game messages.  The extension does **not** add input
> handling for German pronoun forms; it relies on Inform 7's built-in
> four-pronoun mechanism (`it/him/her/them`) and uses grammar tokens
> `[dich]`/`[dir]` for the player-character only.  PunyInformDE's
> BeforeParsing substitution approach therefore offers **better German
> pronoun input coverage than German.i7x** for the common pronoun forms.

**CPU/memory impact**: Pass 3 is O(words) per command.  Typical commands
have 2–5 words; each check is 2–5 byte comparisons.  No extra arrays.
One `VM_Tokenise` call per command at most.  The `_DE_ShiftRight1` loop
runs at most once, over typically 5–20 bytes.  Essentially free on any
platform, old or new.

**Example impact in sterne.inf**:
```
>> oeffne kiste
Du öffnest die Seekiste.

>> schau sie an          ← 'sie' → 'her' (die Kiste, herobj ≠ 0)
Du siehst innen nichts Besonderes.

>> nimm schluessel
Genommen.

>> leg ihn in die kiste  ← 'ihn' → 'him' (der Schlüssel, himobj ≠ 0)
Du legst den Schlüssel in die Seekiste.

>> schau in kiste
Du siehst darin: den Schlüssel.

>> nimm es aus kiste     ← 'es' → 'it' (neuter: Fernrohr, itobj ≠ 0)
Du nimmst das Fernrohr aus der Seekiste.
```

**Limitation vs. deform**: The GNA bit-pattern system in deform resolves
`sie` (f-Nom/Akk) vs. `sie` (p-Nom/Akk/Dat) from grammar context.
PunyInform's 4-slot model cannot.  The fallback priority (`herobj`
before `themobj`) handles the most common IF scenarios acceptably.

**Effort estimate**: Low–Medium. ~80 lines in `parser_de.h` (helper +
Pass 3 function + BeforeParsing call + loop wrapper). One 6-line
`#IfDef LANG_DE` block in `puny.h` inside `PronounNotice`.
Test cases required for each pronoun form.

---

## 3. Adjective Inflection

### The Problem

German adjectives decline based on case, gender, and definiteness.
A key object in `sterne.inf`:

```inform
Object -> Schluessel "kleiner Schlüssel"
    with name 'schluessel' 'kleiner' 'schlüssel', ...
```

- The `short_name` "kleiner Schlüssel" is always printed as-is, regardless
  of context. In Akkusativ it should be "kleinen Schlüssel".
- The `name` property only has Nominative "kleiner". If the player types
  "nimm kleinen schluessel" (Akkusativ), the word "kleinen" is unknown
  and matching fails.

### How Deform Solves It

**Three-level system in deform**:

#### 3a. Input: suffix stripping via `PruneWord`

When a word is not found in the dictionary, `PruneWord(w)` tries stripping
common endings in order:
1. `-e`, `-n`, `-s` (one char)
2. `-em`, `-en`, `-er`, `-es` (two chars)
```inform
[ PruneWord w   start length;
    wn = w; if (NextWord()) return;   ! already known
    start = WordAddress(w);
    length = WordLength(w);
    if (start->(length-1) == 'e' or 'n' or 's'
        && DictionaryLookup(start, length-1)) {
        start->(length-1) = ' '; Tokenise__(buffer, parse); return;
    }
    if (start->(length-2) == 'e'
        && start->(length-1) == 'm' or 'n' or 'r' or 's'
        && DictionaryLookup(start, length-2)) {
        start->(length-1) = ' '; start->(length-2) = ' ';
        Tokenise__(buffer, parse); return;
    }
];
```

This runs **on every unknown word** in `LanguageToInformese`, not just
verbs. It means the game author only defines the stem in `name`:
```inform
name 'klein' 'schluessel'   ! NOT 'kleiner', 'kleinem', 'kleinen' etc.
```
and "kleiner", "kleinem", "kleinen" all strip to "klein" automatically.

#### 3b. Output: adjective property + low-string suffix

Objects declare adjective stems via an `adj` property:
```inform
Object Schluessel "Schlüssel"
    with adj "klein",
         name 'klein' 'schluessel', ...
```

The printing function `PSN__` (Print Short Name internal) iterates `adj`:
```inform
if (o provides adj) {
    for (i=0: i<o.#adj/WORDSIZE: i++) {
        print (string) o.&adj-->i, "@00";   ! stem + adjective suffix
        print " ";
    }
}
```

`@00` is a **low string** (Inform 6 dynamic string slot 0) which is set
by `SetLowStrings(case, gender)` before any print:
```inform
! Adjective suffix lookup: indef_mode × case × gender
[ SetLowStrings k g;
    if (indef_mode==0) {        ! with definite article
        switch(k*4 + g) {
            1, 2, 3, 14, 15:  string 0 "e";
            default:           string 0 "en";
        }   ! e.g. "der kleine Schlüssel" (Nom m def → "-e")
            ! but "den kleinen Schlüssel" (Akk m def → "-en")
    } else if (indef_mode==1) { ! with indefinite article
        switch(k*4 + g) {
            0, 2, 12, 14:     string 0 "e";
            1, 4:             string 0 "er";
            3, 15:            string 0 "es";
            default:          string 0 "en";
        }   ! "ein kleiner Schlüssel" (Nom m indef → "-er")
            ! "einen kleinen Schlüssel" (Akk m indef → "-en")
    } else {                    ! no article (bare adjective)
        switch(k*4 + g) { ... }
    }
];
```

The full adjective suffix table (from `LanguageSuffixes`) covers
5 article modes × 4 cases × 4 genders = 80 entries.

#### 3c. Noun declension via `dekl` property

Nouns can carry weak-declension info:
```inform
Object Schluessel "Schlüssel"
    with dekl 1,   ! type 1 = Genitiv-s, so "des Schlüssels"
    ...
```

`DeclinationSuffix(o)` maps the `dekl` value to a suffix appended after
the noun stem. For most objects this is just Genitiv `-s`/`-es`; for
weak masculines (Typ 6, e.g. "der Graf" → "dem Grafen") it is `-en`.

### Implementation Plan for PunyInformDE

A full port of deform's system requires touching `puny.h` extensively
(since `_PrintObjName` / `PrintShortName` would need the `SetLowStrings` +
`adj` machinery). Below is a **two-stage plan**:

#### Stage 1 — Input: suffix stripping (high value, low risk)

Extend `_DE_NormaliseDigraphsOnly` / Pass 2 in `lib/de/parser_de.h` with
a **`PruneWord` equivalent** that strips adjectival suffixes from unknown
words. This is separate from verb normalisation (which handles -e stripping
for verbs) because it should only apply to non-verb words.

```inform
! In lib/de/parser_de.h, add after Pass 2:
!
! Pass 3 (all builds): Strip adjective/noun case endings from unknown words
! so "kleinen"→"klein", "dem"→"der" etc. match dictionary entries.

[ _DE_PruneWordSuffix p_start p_len    new_len;
    ! Strip -em/-en/-er/-es (two-char endings)
    if (p_len >= 4) {
        new_len = p_len - 2;
        if ((p_start->(new_len) == 'e')
            && (p_start->(new_len+1) == 'm' or 'n' or 'r' or 's')) {
            if (DictionaryLookup(p_start, new_len)) return new_len;
        }
    }
    ! Strip -e/-n/-s (one-char endings)
    if (p_len >= 3) {
        new_len = p_len - 1;
        if (p_start->new_len == 'e' or 'n' or 's') {
            if (DictionaryLookup(p_start, new_len)) return new_len;
        }
    }
    return p_len;
];
```

This is called in `BeforeParsing` for every word whose dictionary address
is 0 **and** which was not already processed by Pass 1/2 (i.e. not a verb).
The word boundary is then adjusted just like Pass 2 does.

**Impact in sterne.inf** (no game source changes needed):
```
>> nimm kleinen schluessel     ← currently fails
(matches 'klein' after stripping '-en')
Genommen.
>> leg messingschluessel in geschlossene kiste
(strips 'geschlossen' + 'e' → matches 'geschlossen')
Das geht nicht, da die Seekiste geschlossen ist.
```

**Effort**: Low–Medium. ~40 lines in `parser_de.h`. Needs test cases.

> **German.i7x comparison**: German.i7x uses an **identical `PruneWord`
> function** (copied from deform) with the same 1-char / 2-char suffix
> stripping algorithm and `DictionaryLookup` safety check.  It also
> handles compound words (`CheckCompoundHeads`/`CheckCompoundTails` tables)
> but that is not planned for PunyInformDE.  The Stage 1 plan is
> therefore well-validated by two independent implementations.
>
> **Integration note**: Stage 1's unknown-word suffix stripping and the
> Pass 3 pronoun substitution can share the same BeforeParsing pass.
> Add the PruneWord loop after the pronoun substitution (so that a
> stripped stem can still be tested as a pronoun first).

#### Stage 2 — Output: declined article + adjective printing

This requires modifying `_PrintObjName` in `puny.h` and adding the
`adj` property and suffix tables.

**New properties** (in `lib/de/globals_de.h`):
```inform
Property adj;          ! adjective stem(s): adj "klein" or adj "hell" "blau"
Property dekl;         ! declension type (Genitiv-s = 1, weak-masc = 6, etc.)
```

**New globals** (in `lib/de/globals_de.h`):
```inform
Global DE_indef_mode = -1;   ! -1=no article, 0=definite, 1=indefinite
! short_name_case already added in §1
```

**`DE_SetAdjSuffix(case, gender, indef_mode)` function** (in `lib/de/article_de.h`):
```inform
! Returns index into DE_AdjSuffixes table
! DE_AdjSuffixes holds the 20 most-used combinations (def+indef, Nom+Akk)
Array DE_AdjSuffix_Def  --> "en" "e"  "e"  "e"   ! Nom: pl m f n
                            "en" "en" "e"  "e"    ! Akk
                            "en" "en" "en" "en"   ! Dat (all "-en")
                            ;
Array DE_AdjSuffix_Indef --> "en" "er" "e"  "es"  ! Nom: pl m f n
                             "en" "en" "e"  "es"   ! Akk
                             "en" "en" "en" "en"   ! Dat
                             ;
Array DE_AdjSuffix_Bare  --> "e"  "er" "e"  "es"  ! Nom: pl m f n
                             "e"  "en" "e"  "es"   ! Akk
                             "en" "em" "er" "em"   ! Dat
                             ;
```

**Modified `_PrintObjName`** (in `puny.h`, under `! PunyInformDE:` comment):
```inform
[ _PrintObjName p_obj p_form   g k s i;
    caps_mode = false;
    if (p_form == FORM_CDEF) caps_mode = 2;
    if (p_obj hasnt proper) {
        g = DE_Gender(p_obj);
        k = short_name_case;
        switch (p_form) {
        FORM_CDEF:
            s = DE_DefArticles-->(k*4 + g);
            if (s) { print (char) UpperCase(s->0); print (string) (s+1); }
        FORM_DEF:
            s = DE_DefArticles-->(k*4 + g);
            if (s) print (string) s;
        FORM_INDEF:
            if (p_obj.&article) { PrintOrRun(p_obj, article, true); print " "; }
            else {
                s = DE_IndefArticles-->(k*4 + g);
                if (s) print (string) s; else print "einige ";
            }
        }
        ! Print adjectives with declined suffix
        if (p_obj provides adj) {
            for (i=0: i < p_obj.#adj/WORDSIZE: i++) {
                print (string) p_obj.&adj-->i;
                ! append correct suffix based on p_form, case, gender
                DE_PrintAdjSuffix(p_form, k, g);
                print " ";
            }
        }
    }
    PrintShortName(p_obj);
    ! Print noun case ending if dekl property present
    if (p_obj provides dekl && p_obj hasnt proper)
        DE_PrintNounSuffix(p_obj, k);
];
```

**Example usage in sterne.inf** — comparing current vs. proposed:

Current (static `short_name`):
```inform
Object -> Schluessel "kleiner Schlüssel"
    with name 'schluessel' 'kleiner' 'schlüssel', ...
```

Proposed (dynamic adjective):
```inform
Object -> Schluessel "Schlüssel"
    with name    'schluessel' 'klein' 'schlüssel',
         adj     "klein",
         article "ein",
         ...
```

Output comparison:
```
FORM_CDEF (Nom):  "Ein kleiner Schlüssel"      ! indef: "-er" for m
FORM_DEF  (Nom):  "der kleine Schlüssel"       ! def:   "-e" for m Nom
FORM_DEF  (Akk):  "den kleinen Schlüssel"      ! def:   "-en" for m Akk
FORM_DEF  (Dat):  "dem kleinen Schlüssel"      ! def:   "-en" for m Dat
```

**Effort**: High. Requires:
- New `article_de.h` (~100 lines)
- Modified `_PrintObjName` in `puny.h` (~40 lines, replaces current 30)
- New `DE_Gender`, `DE_SetAdjSuffix`, `DE_PrintAdjSuffix`, `DE_PrintNounSuffix`
  functions (~80 lines)
- Updating `sterne.inf` objects to use `adj` property
- New test cases for all 4 objects with adjectives in the example game

**Open question — backwards compatibility**: The current `article` property
is a string like "eine". The deform approach replaces it with an integer
article-mode code. We can keep backwards compatibility by checking:
`if (p_obj.article ofclass String)` → print directly (legacy),
`else if (p_obj.article == definite)` → use definite article table (deform style).

> **German.i7x comparison**: German.i7x uses the same `adj` property and
> a `LanguageSuffixes` array of 80 entries (5 modes × 4 cases × 4 genders).
> The PunyInformDE plan uses 3 × 12 = 36 entries covering the most-needed
> combinations (def/indef/bare × Nom+Akk+Dat × 4 genders), omitting
> the rarely-needed Genitiv and demonstrative forms.  This saves ~88 bytes
> vs. the full I7 table while covering all common IF messages.
>
> German.i7x also defines `special_article` as an integer enum
> (`definite = 1`, `yours = 2`, `no_article = 3`) instead of a string
> property, enabling cleaner table lookups.  For PunyInformDE the simpler
> approach — a string `article` that becomes an optional override after §1
> — is sufficient and requires no additional migration work.  See §4.

---

## Comparison Table

| Feature | deform | German.i7x | PunyInformDE now | After plan |
|---------|--------|------------|------------------|------------|
| Definite articles Nom | ✅ die/der/das | ✅ | ✅ die/der/das | ✅ same |
| Definite articles Akk | ✅ den/die/das | ✅ | ❌ (uses Nom) | ✅ den/die/das |
| Definite articles Dat | ✅ dem/der/dem | ✅ | ❌ (uses Nom) | ✅ dem/der/dem |
| Definite articles Gen | ✅ des/der/des | ✅ | ❌ | ❌ (not planned) |
| Indefinite articles Nom | ✅ ein/eine | ✅ | ✅ via `article` | ✅ same |
| Indefinite articles Akk | ✅ einen/eine | ✅ | ❌ | ✅ |
| Indefinite articles Dat | ✅ einem/einer | ✅ | ❌ | ✅ |
| Gender via attributes | ✅ male/female/neuter | ⚠️ uses property | ✅ | ✅ same |
| Gender via property | ❌ | ✅ `grammatical_gender` | ❌ | ❌ (not planned) |
| Inline gender markers | ❌ | ✅ `[m]`/`[f]` in name | ❌ | ❌ (too heavy) |
| English pronouns (it/him) | ❌ (replaced) | ❌ (I7 handles) | ✅ | ✅ same |
| German pronoun INPUT (er/ihn/ihm) | ✅ LanguagePronouns | ❌ | ❌ | ✅ BeforeParsing |
| German pronoun INPUT (sie/ihr/es) | ✅ | ❌ | ❌ | ✅ (sie/es) |
| German pronoun INPUT (ihnen) | ✅ | ❌ | ❌ | ✅ |
| Gender-aware pronoun assignment | ✅ GNA table | ✅ | ❌ animate-only | ✅ all genders |
| Adjective input (kleinen→klein) | ✅ PruneWord | ✅ same | ❌ | ✅ Stage 1 |
| Adjective output (declined) | ✅ adj+SetLowStrings | ✅ same | ❌ | ✅ Stage 2 |
| Noun declension (des Schlüssels) | ✅ dekl property | ✅ | ❌ | ✅ Stage 2 |
| Synonym contractions (ins=in das) | ✅ LanguageSynonyms | ✅ | ❌ | possible future |
| Compound word splitting | ❌ | ✅ Compound tables | ❌ | not planned |
| Pronominal adverbs (damit/daraus) | ✅ tokens | ✅ tokens | ❌ | not planned |
| Changing gender at runtime | ❌ | ✅ CG system | ❌ | not planned |

---

## 4. The `article` Property After §1

You may have noticed that `sterne.inf` objects currently declare:
```inform
Object -> Kiste "Seekiste"
    with article "eine",
    ...
    has female, ...
```
The natural question is: **if the gender is already declared via `has female`, why is `"eine"` needed?**

The answer is that `article "eine"` is a **current workaround**, not a permanent requirement.
`FORM_INDEF` currently prints the `article` string directly because there is no
case-aware article table yet.  Once §1 is implemented (full `DE_DefArticles` /
`DE_IndefArticles` tables keyed by gender), the tables produce the correct indefinite
article automatically from the gender attribute alone:

| Gender attribute | Nom | Akk | Dat |
|-----------------|-----|-----|-----|
| *(none, default masculine)* | ein | einen | einem |
| `has female` | eine | eine | einer |
| `has neuter` | ein | ein | einem |
| `has pluralname` | *(no indefinite)* | — | — |

So **after §1, `with article` can be dropped from all normal objects**.
`sterne.inf` would become:
```inform
Object -> Kiste "Seekiste"    ! no 'article' property needed
    ...
    has female, ...

Object -> Schluessel "kleiner Schlüssel"    ! no 'article' needed
    ...                                     ! masculine is the default
```

### When is `article` still needed?

Only for objects whose indefinite article is genuinely non-standard:

```inform
! 1. An uncountable or "definite-only" concept that should never print
!    an indefinite article (unusual in IF; 'has proper' handles names):
Object Sonne "Sonne"
    with article 0,      ! suppress indefinite: "die Sonne", never "eine Sonne"
    has female, ...

! 2. An object with an irregular or colloquial article form (very rare):
Object Hotel "Hotel"
    with article "so ein",   ! "so ein Hotel" as a special flavour
    has neuter, ...

! 3. Nothing needed for standard objects — the table handles it:
Object Fernrohr "Messing-Fernrohr"
    has neuter, ...    ! → "ein Fernrohr" / "das Fernrohr" from table
```

### Implementation note

The Stage 2 `_PrintObjName` code handles this simply:
```inform
FORM_INDEF:
    if (p_obj.article == 0) {         ! explicitly no article
        ! print bare name
    } else if (p_obj.&article && p_obj.article ofclass String) {
        print (string) p_obj.article; print " ";  ! legacy override
    } else {
        s = DE_IndefArticles-->(case * 4 + g);    ! table default
        if (s) { print (string) s; print " "; }
    }
```

The `ofclass String` branch costs one extra type-check only when an `article`
property is present — which, after §1 migration, is the rare-exception path.
For the common case (no `article` property set), the code goes straight to
the table lookup: a single array index read.

**No design decision is needed before starting work.**  The migration is:
1. Implement §1 article tables.
2. Remove `with article "..."` from all standard objects in `sterne.inf`.
3. `article` remains as an optional override for edge cases.

---

## 5. Documentation Requirement

After implementing any feature in §1–§3, create (or update)
`docs/Implementation.md` with the following information:

### Required content for Implementation.md

1. **What was implemented** — list each feature: article cases, pronoun
   input handling, adjective input stripping (Stage 1), adjective output
   declension (Stage 2), or any subset.

2. **Algorithm origins** — explicitly credit:
   - **deform 6/11** (2005–2010) by Martin Oehm — the original German
     Inform 6 library that solved all three problems first.  Source files
     used: `c:\Source\informtest\deform\German.h`, `GermanG.h`.
   - **German.i7x "Team GerX"** (v4, 230629) by Frank Gerbig et al. —
     the Inform 7 adaptation of deform.  It confirmed the design patterns
     and provided additional reference code for article printing functions
     (`GDer`/`GDen`/`GDem`), personal pronoun output arrays, and suffix
     tables.  Source: `c:\Source\fiction\Staub\Staub.materials\Extensions\Team GerX\German.i7x`.

3. **Architectural decisions** — record all deliberate simplifications,
   e.g.:
   - 3 × 12 adjective suffix table instead of deform's 80-entry full table
   - BeforeParsing buffer substitution for pronouns (instead of
     LanguagePronouns GNA table or parser.h modification)
   - Attribute-based gender instead of `grammatical_gender` property
   - `ihr` excluded from pronoun substitution (possessive ambiguity)
   - Genitiv articles not implemented
   - `article` kept as optional string override; standard articles derived
     from gender attribute via table (no `special_article` enum adopted)

4. **Known limitations** — what deform/I7 GerX supports that PunyInformDE
   does not: synonym contractions (`ins`/`im`/`vom`), compound word
   splitting, pronominal adverbs (`damit`/`daraus`), changing gender at
   runtime, Genitiv articles, formal player address ("Sie").

---

## Recommended Implementation Order

### Current Status (2026-04-26)

- **§1 Article system**: IMPLEMENTED in `lib/de/article_de.h` + `puny.h` + `messages_de.h`
- **§2 Pronoun input**: IMPLEMENTED in `parser.h` + `parser_de.h` (`_DE_SubstitutePronouns` call path)
- **§3 Stage 1 (input suffix stripping)**: IMPLEMENTED in `lib/de/parser_de.h` (`_DE_PruneWordSuffixLen` + BeforeParsing pass)
- **§3 Stage 2 (output adjective declension)**: IMPLEMENTED in `lib/de/article_de.h` + `puny.h` + `messages_de.h`

Transcript-verified examples after §3 implementation:
- `Du legst den alten Kompass auf den Schreibtisch.`
- `Du öffnest die Seekiste, und siehst einen kleinen Schlüssel.`

1. **§1 Article system** — highest impact on correctness of existing messages.
   Start with article tables + `den`/`dem`/`einen`/`einem` print functions,
   then update the ~15 messages in `messages_de.h` that use Akkusativ/Dativ.

2. **§2 Pronoun input** — low effort, easily testable, high player-facing value.
   Implement `_DE_SubstitutePronouns` and its `_DE_ShiftRight1` helper in
   `parser_de.h` (new Pass 3); add the 6-line `#IfDef LANG_DE` block inside
   `PronounNotice` in `puny.h`; add `test_pronouns.py` covering each form.

3. **§3 Stage 1 — input suffix stripping** — improves robustness of player
   input with no game-source changes needed.  The `PruneWord`-equivalent loop
   can share the same BeforeParsing pass as the pronoun substitution (§2).
   Test with "nimm kleinen schluessel"-style inputs.

4. **§3 Stage 2 — output adjective declension** — largest effort, most
   invasive change to `puny.h`.  Remove `with article "..."` from all
   standard `sterne.inf` objects after §1 is done (see §4 migration note).
   Best done after all tests are green for steps 1–3.

5. **§5 Documentation** — create `docs/Implementation.md` after each
   completed step, crediting deform 6/11 (Martin Oehm) and German.i7x
   (Team GerX) as the reference implementations.
