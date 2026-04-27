---
name: PunyInformDE
description: Continues the PunyInform plan with... (see docs/Plan.md)

Understands and executes tasks closely following the project plan at `docs/Plan.md`. Update the `docs/Plan.md`, `docs/Implementation.md` and `README.md` with the current state and progress. `example\sterne.inf` is a definition for an example adventure - extend and/or rewrite it to cover the changes we made. `example\sterne.walkthrough.txt` shall contain a full walkthrough of the game that shall also be covered by tests. Test using PunyTest and put them in `tests/`. Always run builds and all tests in a loop until the task is complete.

## MANDATORY Verification Loop (NEVER skip any step)

Every code change MUST go through this loop before reporting completion:

1. **Build**: Run `powershell -ExecutionPolicy Bypass -File .vscode\build.ps1`. Fix any compiler errors before continuing.
2. **Review transcripts**: Read `build/sterne.transcript.txt` and `build/sterne.transcript.ascii.txt` in full. Confirm the walkthrough still completes with 5/5 points and no unexpected output.
3. **Write tests FIRST**: Before claiming a fix is done, write pytest tests in `tests/` that would have FAILED before the fix and PASS after. Tests must cover:
   - Both `game` (Unicode build) and `game_ascii` (ASCII build) fixtures unless a feature is build-specific.
   - The exact symptom reported by the user (use dfrotz piped input to verify the exact output text).
4. **Run tests**: `python -m pytest tests/ -v --tb=short`. ALL tests must be green. Fix failures before continuing.
5. **Manual dfrotz verification**: Run `echo "cmd1\ncmd2\nq\ny" | tools\dfrotz.exe build\sterne.z5` and `... build\sterne.ascii.z5` for the exact scenario the user reported. Show the exact output lines that prove the fix.
6. **Repeat from step 1** if any step reveals a problem.

Only report completion after all six steps pass without issues.

## Base File Policy (CRITICAL)

The files `lib/globals.h`, `lib/puny.h`, `lib/grammar.h`, `lib/parser.h`, `lib/scope.h`, and `lib/messages.h` are **base PunyInform files**. They MUST NOT be modified with language-specific content (German words, German strings, German grammar).

**The only allowed changes to base files** are minimal, language-agnostic **extension points** — i.e., adding `#IfNDef SOME_CONSTANT; Constant SOME_CONSTANT = "english default"; #EndIf;` defaults or `#IfDef SOME_FLAG;` conditional blocks that are activated by constants defined in `lib/de/` files. The German content always lives in `lib/de/`.

**All German translations belong exclusively in `lib/de/` files:**
- `lib/de/globals_de.h` — German constants (words, strings, flags like `EXTRA_DIRECTION_ROW`, `AND_LIST_STR`)
- `lib/de/grammar_de.h` — German verb definitions
- `lib/de/messages_de.h` — German message text
- `lib/de/puny_de.h` — German helpers (if needed)

**Rationale:** Functions cannot be redefined in Inform 6 after compilation. Where German override functions (`_PrintObjName`, `_PrintAfterEntry`) exist in `puny.h`, they are marked `! PunyInformDE:` and are a known, documented exception. No new such exceptions should be introduced without explicit justification.

Before modifying any base file, ask: "Can this be achieved by defining a constant in `globals_de.h` that the base file already checks (or can check via `#IfNDef`/`#IfDef`)?" If yes, do that instead.
