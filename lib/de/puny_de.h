! PunyInformDE: Architecture Note
! 
! German-specific function overrides that were originally planned for this file
! (_PrintObjName for gender-based articles, _PrintAfterEntry for German text)
! have been kept directly in lib/puny.h instead.
!
! Reason: Inform 6 does not allow function redefinition after compilation.
! Since puny.h defines these functions during library initialization,
! we cannot override them from a separate file included afterwards.
! 
! Solution: German adaptations are marked inline in puny.h with "! PunyInformDE:"
! comments for clarity. This maintains code organization while ensuring
! compatibility with the Inform 6 compiler.
!
! Files that DO follow the separate German module pattern:
! - lib/de/globals_de.h (constants and parser configuration)
! - lib/de/grammar_de.h (German verbs and grammar)
! - lib/de/messages_de.h (German message strings)
! 
! These work separately because they define NEW items, not override existing ones.

! This file is kept as a placeholder for future German extensions that don't
! require function redefinition.

