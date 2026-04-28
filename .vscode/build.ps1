#Requires -Version 3.0
# PunyInformDE build script — invoked by the VS Code "Build" task.
# Working directory must be the project root (set by the task via options.cwd).

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"

# Replace all German umlauts with ASCII digraphs in a source file.
# Writes UTF-8 WITHOUT BOM — Inform 6 rejects the UTF-8 BOM that
# PowerShell 5.x's Set-Content -Encoding UTF8 adds automatically.
function Convert-ToAsciiDigraphs {
    param([string]$Source, [string]$Destination)
    $destDir = Split-Path $Destination -Parent
    if ($destDir -and (-not (Test-Path $destDir))) {
        New-Item -ItemType Directory -Force -Path $destDir | Out-Null
    }
    $lines = (Get-Content $Source -Encoding UTF8) `
        -replace [char]0xe4, "ae" `
        -replace [char]0xf6, "oe" `
        -replace [char]0xfc, "ue" `
        -replace [char]0xdf, "ss" `
        -replace [char]0xc4, "Ae" `
        -replace [char]0xd6, "Oe" `
        -replace [char]0xdc, "Ue"
    $utf8NoBom = New-Object System.Text.UTF8Encoding $false
    $absPath = Join-Path $PWD.Path $Destination
    [System.IO.File]::WriteAllLines($absPath, $lines, $utf8NoBom)
}

New-Item -ItemType Directory -Force -Path "build" | Out-Null

# -------------------------------------------------------------------------
# Standard Unicode build
# -------------------------------------------------------------------------
Write-Host "Compiling sterne.z5..."
# +lib       — finds puny.h, globals.h, grammar.h etc.
# +lib\de    — finds chartable_de.h, globals_de.h, messages_de.h etc. (no "de/" prefix needed in source)
& .\tools\inform6.exe "+include_path=lib,lib\de" example\sterne.inf build\sterne.z5
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

# -------------------------------------------------------------------------
# ASCII build
#
# Inform 6 stores string literals with their Unicode code-points regardless
# of whether Zcharacter is declared. To get truly ASCII output, every source
# file that contains German strings must be preprocessed (umlauts → digraphs)
# before compilation.
#
# Files preprocessed into build\ascii_lib\  (override lib\ on the include path):
#   lib\de\globals_de.h   – status-bar label " Züge: " → " Zuege: "
#   lib\de\messages_de.h  – all parser messages
#   lib\de\grammar_de.h   – all verb dictionary words (e.g. öffne → oeffne)
#   lib\puny.h            – " (enthält" → " (enthaelt"
# File preprocessed into build\ascii_src\   (override example\ on include path):
#   example\sterne.inf  – all game text (rooms, objects, intro, …)
#
# grammar_de.h defines only the canonical umlaut forms of each verb; the
# BeforeParsing hook in lib/de/parser_de.h handles digraph→umlaut and -e
# suffix normalisation at runtime in the Unicode build. In the ASCII build
# this preprocessing step converts umlaut verb words to their digraph forms
# so that player input (always digraph-only in the ASCII build) matches.
# -------------------------------------------------------------------------
Write-Host "Generating ASCII source tree..."
New-Item -ItemType Directory -Force -Path "build\ascii_lib\de" | Out-Null
New-Item -ItemType Directory -Force -Path "build\ascii_src"     | Out-Null

Convert-ToAsciiDigraphs "lib\de\globals_de.h"  "build\ascii_lib\de\globals_de.h"
Convert-ToAsciiDigraphs "lib\de\chartable_de.h" "build\ascii_lib\de\chartable_de.h"
Convert-ToAsciiDigraphs "lib\de\messages_de.h" "build\ascii_lib\de\messages_de.h"
Convert-ToAsciiDigraphs "lib\de\grammar_de.h"  "build\ascii_lib\de\grammar_de.h"
Convert-ToAsciiDigraphs "lib\de\parser_de.h"   "build\ascii_lib\de\parser_de.h"
Convert-ToAsciiDigraphs "lib\de\article_de.h"  "build\ascii_lib\de\article_de.h"
Convert-ToAsciiDigraphs "lib\puny.h"           "build\ascii_lib\puny.h"
Convert-ToAsciiDigraphs "example\sterne.inf" "build\ascii_src\sterne.inf"

Write-Host "Compiling sterne.ascii.z5..."
& .\tools\inform6.exe "+include_path=build\ascii_lib,build\ascii_lib\de,build\ascii_src,lib,lib\de" example\sterne_ascii.inf build\sterne.ascii.z5
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

# -------------------------------------------------------------------------
# Z3 build
#
# Reuses the same preprocessed ASCII source tree as the ASCII build.
# Output extension .z3 tells inform6 to target the Z3 machine format (128 KB).
# No -Cu: Z3 has no Unicode extension.
#
# Note (fredrikr, PunyInform dev): game globals must not be declared before
# globals.h in Z3 because the Z-machine spec requires score/turns/location at
# specific global-variable indices. sterne.inf moves all game Global
# declarations to after the library includes for this reason.
# -------------------------------------------------------------------------
Write-Host "Compiling sterne.z3..."
& .\tools\inform6.exe "+include_path=build\ascii_lib,build\ascii_lib\de,build\ascii_src,lib,lib\de" example\sterne_z3.inf build\sterne.z3
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

# -------------------------------------------------------------------------
# ASCII walkthrough (for manual testing / Test Dfrotz (ASCII) task)
# -------------------------------------------------------------------------
Write-Host "Generating ASCII walkthrough..."
(Get-Content "example\sterne.walkthrough.txt" -Encoding UTF8) `
    -replace [char]0xe4, "ae" `
    -replace [char]0xf6, "oe" `
    -replace [char]0xfc, "ue" `
    -replace [char]0xdf, "ss" `
    -replace [char]0xc4, "Ae" `
    -replace [char]0xd6, "Oe" `
    -replace [char]0xdc, "Ue" `
    | Set-Content "example\sterne.walkthrough.ascii.txt" -Encoding ASCII

# -------------------------------------------------------------------------
# Transcript generation
#
# PowerShell 5.x's [Console]::OutputEncoding = UTF8 uses UTF-8-with-BOM,
# which corrupts the first bytes sent to dfrotz's stdin.  Instead we write
# BOM-free temp files and use cmd.exe's `<` redirect, which passes raw
# file bytes directly to dfrotz without any encoding layer.
# -------------------------------------------------------------------------
Write-Host "Generating transcripts..."
$utf8NoBom = New-Object System.Text.UTF8Encoding $false

Remove-Item "build\sterne.transcript.txt"       -ErrorAction SilentlyContinue
Remove-Item "build\sterne.transcript.ascii.txt" -ErrorAction SilentlyContinue
Remove-Item "build\sterne.transcript.z3.txt"    -ErrorAction SilentlyContinue

# Unicode transcript
$tmpUnicode = [System.IO.Path]::GetTempFileName()
try {
    $lines = Get-Content "example\sterne.walkthrough.txt" -Encoding UTF8
    [System.IO.File]::WriteAllLines($tmpUnicode, $lines, $utf8NoBom)
    cmd /c "tools\dfrotz.exe -m -q -Z 0 -T -n ""build\sterne.transcript.txt"" ""build\sterne.z5"" < ""$tmpUnicode"""
} finally {
    Remove-Item $tmpUnicode -ErrorAction SilentlyContinue
}

# ASCII transcript
cmd /c "tools\dfrotz.exe -m -q -Z 0 -T -n ""build\sterne.transcript.ascii.txt"" ""build\sterne.ascii.z5"" < ""example\sterne.walkthrough.ascii.txt"""

# Z3 transcript (reuses ASCII walkthrough — same commands, same ZSCII input)
cmd /c "tools\dfrotz.exe -m -q -Z 0 -T -n ""build\sterne.transcript.z3.txt"" ""build\sterne.z3"" < ""example\sterne.walkthrough.ascii.txt"""

Write-Host "Build complete: build\sterne.z5, build\sterne.ascii.z5, build\sterne.z3, build\sterne.transcript.txt, build\sterne.transcript.ascii.txt, build\sterne.transcript.z3.txt"
