# PunyInformDE - Implementation Notes

This document contains the technical details for the current German-language
implementation strategy. The README is intentionally brief; this file is the
reference for internals.

## Scope

- Base library: PunyInform v6.5
- Compiler: Inform 6.44
- Targets: z5 (Unicode + ASCII build variants)
- Design rule: German-specific behavior lives in `lib/de/` whenever possible

## Credits and Source Algorithms

The implementation approach is based on the same core ideas used by:

1. deform 6/11 (2005-2010), Martin Oehm
   - Reference files: `c:/Source/informtest/deform/German.h`, `GermanG.h`
2. German.i7x (Team GerX, Frank Gerbig et al.)
   - Reference file: `c:/Source/fiction/Staub/Staub.materials/Extensions/Team GerX/German.i7x`

PunyInformDE adopts equivalent concepts but keeps them lightweight for
PunyInform's smaller footprint and architecture.

## Implemented Features

## §1 Article System

Implemented in:

- `lib/de/article_de.h`
- `lib/puny.h`
- `lib/de/messages_de.h`

Key elements:

- Gender derivation via attributes (`female`, `neuter`, `pluralname`, default masculine)
- Case-aware definite and indefinite article tables (Nom/Akk/Dat)
- Case print helpers: `DE_Der`, `DE_Den`, `DE_Dem`, `DE_Ein`, `DE_Einen`, `DE_Einem`
- Backward-compatible `article` behavior:
  - `article 0` suppresses indefinite article
  - `article "..."` is treated as string override

## §2 Pronoun Input

Implemented in:

- `lib/parser.h` (`PronounNotice` LANG_DE behavior)
- `lib/de/parser_de.h` (`BeforeParsing` call sequence)
- `lib/de/article_de.h` (`_DE_SubstitutePronouns` routine)

German pronouns are rewritten before parse resolution:

- `er`/`ihn`/`ihm` -> `him`
- `sie` -> `her` or `them` (slot-based fallback)
- `es` -> `it`
- `ihnen` -> `them`

## §3 Stage 1 Input Suffix Pruning

Implemented in:

- `lib/de/parser_de.h`

Added `_DE_PruneWordSuffixLen` and a post-tokenization pass for unknown words.
Recognized endings:

- Two-char: `-em`, `-en`, `-er`, `-es`
- One-char: `-e`, `-n`, `-s`

This allows commands like:

- `nimm kleinen schluessel`
- `untersuche altem kompass`

with stem-based dictionary entries.

## §3 Stage 2 Output Adjective Declension

Implemented in:

- `lib/de/article_de.h`
- `lib/puny.h`
- `lib/de/messages_de.h`
- `lib/de/globals_de.h` (case globals and `adj` property)

Key mechanisms:

- `short_name_case` global (`Nom`, `Akk`, `Dat`)
- Adjective suffix selection by mode/case/gender:
  - definite article
  - indefinite article
  - bare noun phrase (no article)
- `adj` property support for stem-based adjective rendering
- `_PrintObjName` delegates to `_DE_PrintObjByForm(...)`
- Messages that list contained items in accusative context now set and restore
  `short_name_case` around `PrintContents(...)`

This fixes outputs such as:

- `Du legst den alten Kompass auf den Schreibtisch.`
- `Du öffnest die Seekiste, und siehst einen kleinen Schlüssel.`

## Example Story Coverage

`example/sterne.inf` now contains explicit §3 demo objects and stems:

- `Kompass` with `adj "alt"`
- `Schluessel` with `adj "klein"`
- Dative/default-examine demo objects:
  - `Ring` (m), `Nadel` (f), `Tuch` (n)

Walkthrough (`example/beispiel.walkthrough.txt`) includes commands that exercise:

- Pronoun replacement
- Suffix-pruned input forms
- Accusative and dative adjective output paths

## Test Coverage

### Test Harness Setup

PunyTest is maintained as a separate public repository:

- `https://github.com/IkeC/PunyTest`

Expected local layout:

- `C:/Source/PunyInformDE`
- `C:/Source/PunyTest`

`tests/conftest.py` prepends the parent folder (for example `C:/Source`) to
`sys.path`, so importing `PunyTest.*` works without copying framework files
into this repository.

Key files:

- `tests/test_articles.py`
- `tests/test_pronouns.py`
- `tests/test_suffix_pruning.py`
- `tests/test_stage3_known_limitations.py`
- `tests/test_walkthrough.py`

Current suite status (latest run):

- 81 passed
- 3 xfailed (known dfrotz umlaut-pipe limitation on Windows)

## Build and Transcript Loop

Build task (`.vscode/build.ps1`) does all of:

1. Compile Unicode story
2. Generate ASCII source tree and compile ASCII story
3. Generate ASCII walkthrough
4. Run walkthrough through dfrotz and emit transcripts

Artifacts used for validation:

- `build/sterne.transcript.txt`
- `build/sterne.transcript.ascii.txt`

## Architectural Decisions

1. Attribute-based gender (not a new grammatical_gender property)
2. Pronoun substitution in `BeforeParsing` instead of deep parser replacement
3. Stem + suffix model via `adj` property for adjective output
4. Keep `article` as optional override for edge cases
5. Keep technical complexity primarily in `lib/de/article_de.h`

## Known Limits

1. Noun declension beyond adjective endings (for example weak noun class behavior)
   is not fully modeled.
2. Genitive system is intentionally limited.
3. Advanced deform/German.i7x features remain out of scope for now:
   - contraction tables (`ins`, `vom`, etc.)
   - compound splitting tables
   - pronominal adverbs (`damit`, `daraus`)
   - runtime gender mutation system
