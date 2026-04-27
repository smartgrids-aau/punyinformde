# German Grammar in PunyInformDE

## Overview

This document describes the three core German grammar problems that had to be
solved, how the reference libraries **deform 6/11** (Martin Oehm) and
**German.i7x** (Team GerX) approached them, and how PunyInformDE solved each
one within PunyInform's lightweight, old-hardware-targeted architecture.

Reference files consulted:
- `c:\Source\informtest\deform\German.h`, `GermanG.h` — deform 6/11 (2005–2010)
- `c:\Source\fiction\Staub\Staub.materials\Extensions\Team GerX\German.i7x` — German.i7x v4 (2023)

**Performance constraint**: PunyInform targets old 8-bit hardware via
Z-machine interpreters (1 MHz effective throughput, ~64 KB story file).
Every extra array entry, property, or per-command function call has real cost.

---

## 1. Article System: Cases (Nominativ, Akkusativ, Dativ)

### The Problem

Base PunyInform prints only Nominative article forms everywhere. German grammar
requires four cases:

| Case        | m (der)  | f (die)   | n (das)  | pl (die)  |
|-------------|----------|-----------|----------|-----------|
| Nominativ   | der/ein  | die/eine  | das/ein  | die/-     |
| Dativ       | **dem/einem**| der/einer | **dem/einem**| den/- |
| Akkusativ   | **den/einen**| die/eine  | das/ein  | die/-     |

IF messages need Akkusativ and Dativ constantly:
- "Du legst **den** Schlüssel in **die** Kiste."  (Akk)
- "Du kannst nicht mit **dem** Schlüssel öffnen."  (Dat)

Without case support, masculine objects in Akkusativ ("den Schlüssel") are
silently printed as "der Schlüssel".

### How Deform / German.i7x Solve It

Both use a `short_name_case` global (0=Nom, 1=Gen, 2=Dat, 3=Akk) and a flat
article table indexed by `case × 4 + gender`:

```inform
Array LanguageArticles -->
    "die " "der " "die " "das "    ! def, Nom: pl m f n
    "den " "dem " "der " "dem "    ! def, Dat
    "die " "den " "die " "das "    ! def, Akk
    ...
```

Messages set `short_name_case` before printing so the table lookup picks the
right form. Shorthand print-rule functions (`der`, `den`, `dem`) wrap this.

Gender is derived from attributes (`male`/`female`/`neuter`/`pluralname`).
German.i7x uses a `grammatical_gender` property instead of attributes, but
that costs one property slot per object — the attribute approach is cheaper.

### PunyInformDE Solution

Implemented in `lib/de/article_de.h`, `lib/puny.h`, `lib/de/messages_de.h`.

- `DE_DefArticles` / `DE_IndefArticles` arrays (Nom/Akk/Dat × 4 genders = 24 entries each)
- `short_name_case` global; case-set helpers `DE_Der`, `DE_Den`, `DE_Dem`, `DE_Ein`, `DE_Einen`, `DE_Einem`
- `_PrintObjName` in `puny.h` uses the tables
- Messages that use Akkusativ or Dativ call the helpers

Genitiv is not implemented — it is not needed by any PunyInform message and
appears rarely in IF command parsing.

---

## 2. Pronoun Input

### The Problem

PunyInform's parser recognises only four English pronouns: `it`, `him`, `her`,
`them`. German input forms (`er`, `ihn`, `ihm`, `sie`, `es`, `ihnen`) are
unknown words:

```
>> oeffne kiste
Du öffnest die Seekiste.
>> schau in sie          ← natural German
Ich verstehe dieses Verb nicht.   ← parser sees "sie" as unknown noun
```

### How Deform Solves It

Deform uses a `LanguagePronouns` table interpreted by the full Inform 6 parser,
with GNA bit-patterns for gender/animateness matching. The full parser maintains
a pronoun→object mapping updated after each successful parse.

PunyInform's four-slot model (`itobj`/`himobj`/`herobj`/`themobj`) has no GNA
table and cannot use that mechanism directly.

### PunyInformDE Solution

Implemented in `lib/de/parser_de.h` (BeforeParsing Pass 3) and `lib/parser.h`
(`PronounNotice`, `#IfDef LANG_DE` block).

**BeforeParsing Pass 3** rewrites German pronoun tokens to their English
equivalents in the raw input buffer before the main parser runs:

| German | → English | Condition |
|--------|-----------|-----------|
| `er`, `ihn`, `ihm` | `him` | `himobj ≠ 0` |
| `sie` | `her` | `herobj ≠ 0` (feminine priority) |
| `sie` | `them` | `themobj ≠ 0` (plural fallback) |
| `es` | `it` | `itobj ≠ 0` |
| `ihnen` | `them` | `themobj ≠ 0` |

`PronounNotice` in `puny.h` is extended (`#IfDef LANG_DE`) so that inanimate
feminine objects update `herobj` (not just animate), enabling "die Kiste → sie".

**Known limitation**: `ihr` is excluded — it is ambiguous between the
possessive article ("ihr Haus"), the Dativ pronoun, and the 2nd-person-plural
address. Players can use `sie` in Dativ contexts instead.

---

## 3. Adjective Inflection

### The Problem

German adjectives decline by case, gender, and definiteness. A stem-only
`name` entry like `'klein'` matches "kleiner Schlüssel" (Nom indef m) but
not "kleinen Schlüssel" (Akk def m) since the player types the inflected form.

On the output side, printing "kleiner Schlüssel" statically in the object's
`short_name` is wrong in Akkusativ contexts ("den kleinen Schlüssel").

### How Deform / German.i7x Solve It

#### Input: `PruneWord`

When a word is not found in the dictionary, try stripping common endings:
1. `-em`, `-en`, `-er`, `-es` (two-char)
2. `-e`, `-n`, `-s` (one-char)

and re-check the dictionary. Game authors declare only the stem in `name`.

Both deform and German.i7x use an identical `PruneWord` algorithm with a
`DictionaryLookup` safety check to avoid false stripping.

#### Output: `adj` property + suffix table

Objects declare an adjective stem via `adj "klein"`. The print function
appends the correct case/gender/definiteness suffix from a lookup table
(deform: 80 entries; German.i7x: same layout).

### PunyInformDE Solution

**Stage 1 — Input** (`lib/de/parser_de.h`, Pass 4): Unknown words have
`-em/-en/-er/-es/-e/-n/-s` stripped via `_DE_PruneWordSuffixLen`. Only applied
when the stripped stem is found in the dictionary (dict-safe check).

**Stage 2 — Output** (`lib/de/article_de.h`, `lib/puny.h`): The `adj` property
stores the adjective stem. `_PrintObjName` appends a suffix from three compact
12-entry tables:

```inform
Array DE_AdjSuffix_Def  --> "en" "e"  "e"  "e"   ! Nom: pl m f n
                            "en" "en" "e"  "e"    ! Akk
                            "en" "en" "en" "en"   ! Dat
Array DE_AdjSuffix_Indef --> "en" "er" "e"  "es"  ! Nom
                             "en" "en" "e"  "es"   ! Akk
                             "en" "en" "en" "en"   ! Dat
Array DE_AdjSuffix_Bare  --> "e"  "er" "e"  "es"  ! Nom
                             "e"  "en" "e"  "es"   ! Akk
                             "en" "em" "er" "em"   ! Dat
```

36 entries vs. deform's 80 — Genitiv and demonstrative forms are omitted.

#### The `adj` property vs. inflected forms in `name`

The two mechanisms are orthogonal:
- `adj "alt"` → **output only**: provides the stem that gets a declined suffix appended when printing
- `name 'alt'` → **input only**: the stem must be in the dictionary so Pass 4 can reduce "alten"/"alter"/"altem" to "alt" and match it

Inflected forms in `name` (e.g. `'alter' 'alten'`) are redundant when Pass 4
is working — they are stripped to `'alt'` automatically. Only the stem needs
to be in `name`.

---

## Design Comparison

| Feature | deform | German.i7x | PunyInformDE |
|---------|--------|------------|--------------|
| Definite articles Nom | ✅ | ✅ | ✅ |
| Definite articles Akk/Dat | ✅ | ✅ | ✅ |
| Definite articles Gen | ✅ | ✅ | ❌ not needed |
| Indefinite articles Nom | ✅ | ✅ | ✅ |
| Indefinite articles Akk/Dat | ✅ | ✅ | ✅ |
| Gender via attributes | ✅ | ⚠️ property | ✅ |
| German pronoun INPUT (er/ihn/ihm/sie/es/ihnen) | ✅ | ❌ | ✅ |
| `ihr` pronoun input | ✅ | ❌ | ❌ ambiguous |
| Gender-aware inanimate pronouns | ✅ GNA table | ✅ | ✅ LANG_DE hook |
| Adjective input stripping | ✅ PruneWord | ✅ | ✅ Pass 4 |
| Adjective output (declined) | ✅ 80-entry table | ✅ | ✅ 36-entry tables |
| Noun declension (Genitiv-s) | ✅ `dekl` | ✅ | ❌ not planned |
| Synonym contractions (ins/vom) | ✅ | ✅ | ❌ not planned |
| Compound word splitting | ❌ | ✅ | ❌ not planned |
| Pronominal adverbs (damit/daraus) | ✅ | ✅ | ❌ not planned |
| Changing gender at runtime | ❌ | ✅ CG system | ❌ not planned |

