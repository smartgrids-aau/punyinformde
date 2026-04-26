! Part of PunyInformDE: German localisation of PunyInform.
!
! This file:
!   1. Defines LANG_DE constant (used by parser.h for German yes/no words in YesOrNo).
!   2. Provides BeforeParsing hook to normalise unrecognised words in player input.
!
!      For each word NOT found in the dictionary (dict value == 0 after the
!      initial @aread tokenisation), the following normalisation is applied
!      IN TWO PASSES on the buffer bytes:
!
!      Pass 1 (Unicode build only):
!         Collapse ASCII digraph pairs to umlaut bytes:
!            ae->ae-umlaut, oe->oe-umlaut, ue->ue-umlaut
!            ss->sz only when NOT followed by a vowel.
!         Re-tokenise after pass 1 if anything changed. This means that
!         e.g. 'oeffne' is correctly resolved to the dictionary word 'öffne'
!         and NOT further reduced to 'öffn' in pass 2.
!
!      Pass 2 (both builds):
!         For words still not in the dictionary that end with 'e',
!         strip the trailing 'e' and re-tokenise.
!
!      After any modification the buffer is re-tokenised.
!
!      Words already found in the dictionary are left entirely unchanged,
!      so explicit grammar aliases (e.g. 'schaue') are always respected.
!
!      Together, only the canonical e-less umlaut form needs to appear in
!      Verb statements.  All four surface forms are accepted automatically:
!        flücht / fluecht / flüchte / fluechte
!
! 
! Included by lib/de/globals_de.h before lib/parser.h. The LANG_DE constant
! enables German yes/no word support in parser.h via #IfDef guards.

System_file;

Constant LANG_DE;

! ---------------------------------------------------------------------------
! _DE_IsVowelByte: return true if byte c is a German vowel (ASCII or umlaut).
! ---------------------------------------------------------------------------
[ _DE_IsVowelByte c;
    if(c == 'a' or 'e' or 'i' or 'o' or 'u' or
       'A' or 'E' or 'I' or 'O' or 'U' or
       'ä' or 'ö' or 'ü' or 'Ä' or 'Ö' or 'Ü') rtrue;
    rfalse;
];

! ---------------------------------------------------------------------------
! _DE_NormaliseDigraphsOnly
! Collapse digraph pairs to umlaut bytes in-place, WITHOUT stripping trailing e.
! Returns new length.
! ---------------------------------------------------------------------------
#IfNDef USE_ASCII;
[ _DE_NormaliseDigraphsOnly p_start p_len  _src _dst _c _next _after;
    _src = 0;
    _dst = 0;
    while(_src < p_len) {
        _c    = (p_start + _src)->0;
        _next = (p_start + _src + 1)->0;

        if     (_c == 'a' && _next == 'e') { (p_start + _dst)->0 = 'ä'; _src = _src + 2; _dst++; }
        else if(_c == 'o' && _next == 'e') { (p_start + _dst)->0 = 'ö'; _src = _src + 2; _dst++; }
        else if(_c == 'u' && _next == 'e') { (p_start + _dst)->0 = 'ü'; _src = _src + 2; _dst++; }
        else if(_c == 'A' && _next == 'e') { (p_start + _dst)->0 = 'Ä'; _src = _src + 2; _dst++; }
        else if(_c == 'O' && _next == 'e') { (p_start + _dst)->0 = 'Ö'; _src = _src + 2; _dst++; }
        else if(_c == 'U' && _next == 'e') { (p_start + _dst)->0 = 'Ü'; _src = _src + 2; _dst++; }
        else if(_c == 's' && _next == 's') {
            _after = (p_start + _src + 2)->0;
            if(_DE_IsVowelByte(_after)) {
                (p_start + _dst)->0 = 's'; _src++; _dst++;
            } else {
                (p_start + _dst)->0 = 'ß'; _src = _src + 2; _dst++;
            }
        } else {
            (p_start + _dst)->0 = _c; _src++; _dst++;
        }
    }
    return _dst;
];
#Endif; ! USE_ASCII

! ---------------------------------------------------------------------------
! _DE_PruneWordSuffixLen -- §3 Stage 1 input robustness.
!
! For an unknown word, try stripping common inflection endings and check if
! the stem exists in the dictionary. Returns the new length if a valid stem
! was found, otherwise returns p_len unchanged.
!
! Order matches deform/German.i7x behavior:
!   1) two-char endings: -em / -en / -er / -es
!   2) one-char endings: -e / -n / -s
! ---------------------------------------------------------------------------
[ _DE_PruneWordSuffixLen p_start p_len _newlen _c0 _c1;
    if (p_len >= 4) {
        _newlen = p_len - 2;
        _c0 = (p_start + _newlen)->0;
        _c1 = (p_start + _newlen + 1)->0;
        if (_c0 == 'e' && (_c1 == 'm' || _c1 == 'n' || _c1 == 'r' || _c1 == 's')) return _newlen;
    }

    if (p_len >= 3) {
        _newlen = p_len - 1;
        _c0 = (p_start + _newlen)->0;
        if (_c0 == 'e' || _c0 == 'n' || _c0 == 's') return _newlen;
    }
    return p_len;
];


! ---------------------------------------------------------------------------
! BeforeParsing -- normalise unrecognised words then re-tokenise.
! Two-pass approach:
!   Pass 1 (Unicode only): collapse digraph pairs to umlaut bytes in-place
!          for any word not in the dictionary. Re-tokenise if anything changed.
!   Pass 2: for any word still not in the dictionary that ends with 'e',
!          strip the trailing 'e'. Re-tokenise if anything changed.
! This two-pass design ensures that e.g. 'oeffne' is first converted to
! 'öffne' (which IS in the dictionary) and not further reduced to 'öffn'.
! ---------------------------------------------------------------------------
[ BeforeParsing  _nwords _i _waddr _wlen _newlen _changed _j _blen;
    _nwords  = parse->1;

#IfNDef USE_ASCII;
    ! --- Pass 1: digraph normalisation only ---
    _changed = false;
    for(_i = 1 : _i <= _nwords : _i++) {
        if(parse-->(_i + _i - 1) ~= 0) continue;
        _waddr = WordAddress(_i);
        _wlen  = WordLength(_i);
        if(_wlen < 2) continue;
        _newlen = _DE_NormaliseDigraphsOnly(_waddr, _wlen);
        if(_newlen < _wlen) {
            _blen  = buffer->1;
            for(_j = (_waddr + _newlen) - buffer : _j <= _blen + 1 : _j++) {
                buffer->_j = buffer->(_j + (_wlen - _newlen));
            }
            buffer->1 = _blen - (_wlen - _newlen);
            _changed = true;
        }
    }
    if(_changed) {
        buffer->(2 + buffer->1) = 0;
        @tokenise buffer parse;
        _nwords = parse->1;
    }
#Endif; ! USE_ASCII

    ! --- Pass 3: deutsche Pronomina → englische Pronomina ersetzen ---
    ! WICHTIG: Muss vor Pass 2 laufen, damit "sie" nicht durch die
    ! -e-Stripping-Regel zu "si" reduziert wird (Pass 2 entfernt
    ! abschließendes 'e' von nicht erkannten Wörtern).
    if (_DE_SubstitutePronouns()) {
        buffer->(2 + buffer->1) = 0;
        @tokenise buffer parse;
        _nwords = parse->1;
    }

    ! --- Pass 2: strip trailing -e from still-unrecognised words ---
    ! Note: some interpreters (e.g. dfrotz) convert digraphs like 'ue'→ü on
    ! input, so 'schaue' arrives as 'schaü' (ZSCII 157). We expand trailing
    ! ZSCII umlauts back to their two-byte digraph forms (ü→ue, ö→oe, ä→ae)
    ! so the -e stripping below can recover the canonical verb root.
    _changed = false;
    for(_i = 1 : _i <= _nwords : _i++) {
        if(parse-->(_i + _i - 1) ~= 0) continue;
        _waddr = WordAddress(_i);
        _wlen  = WordLength(_i);
        if(_wlen < 2) continue;
        ! Check for trailing ZSCII umlaut (155=ä, 156=ö, 157=ü) that was
        ! produced by interpreter digraph conversion from a trailing -ae/-oe/-ue.
        _j = (_waddr + _wlen - 1)->0;  ! last byte
        if(_j == 155 or 156 or 157) {
            ! Expand: replace the umlaut with its vowel (a/o/u) and append 'e'.
            ! This undoes the interpreter's digraph conversion.
            _blen = buffer->1;
            ! shift everything after the umlaut right by 1 to make room for 'e'
            for(_newlen = _blen + 1 : _newlen >= (_waddr + _wlen) - buffer : _newlen--) {
                buffer->(_newlen + 1) = buffer->_newlen;
            }
            ! replace umlaut byte with vowel
            if(_j == 155) (_waddr + _wlen - 1)->0 = 'a';
            else if(_j == 156) (_waddr + _wlen - 1)->0 = 'o';
            else (_waddr + _wlen - 1)->0 = 'u';
            ! insert 'e' after the vowel
            (_waddr + _wlen)->0 = 'e';
            buffer->1 = _blen + 1;
            _wlen++;
            ! fall through: now the word ends in 'e' so the strip below applies
        }
        if((_waddr + _wlen - 1)->0 ~= 'e') continue;
        _newlen = _wlen - 1;
        ! shift later bytes left by 1 to close the gap left by the stripped 'e'
        _blen = buffer->1;
        for(_j = (_waddr + _newlen) - buffer : _j <= _blen + 1 : _j++) {
            buffer->_j = buffer->(_j + 1);
        }
        buffer->1 = _blen - 1;
        _changed = true;
    }
    if(_changed) {
        ! null-terminate buffer at the new end (required by @tokenise in some implementations)
        buffer->(2 + buffer->1) = 0;
        @tokenise buffer parse;
        _nwords = parse->1;
    }

    ! --- Pass 4: prune unknown-word suffixes (-em/-en/-er/-es, -e/-n/-s) ---
    _changed = false;
    for(_i = 1 : _i <= _nwords : _i++) {
        if(parse-->(_i + _i - 1) ~= 0) continue;
        _waddr = WordAddress(_i);
        _wlen  = WordLength(_i);
        if(_wlen < 3) continue;
        _newlen = _DE_PruneWordSuffixLen(_waddr, _wlen);
        if(_newlen >= _wlen) continue;

        _blen = buffer->1;
        ! shift later bytes left by (_wlen - _newlen) to close the removed suffix
        for(_j = (_waddr + _newlen) - buffer : _j <= _blen + 1 : _j++) {
            buffer->_j = buffer->(_j + (_wlen - _newlen));
        }
        buffer->1 = _blen - (_wlen - _newlen);
        _changed = true;
    }
    if(_changed) {
        buffer->(2 + buffer->1) = 0;
        @tokenise buffer parse;
    }
];

! _DE_SubstitutePronouns is defined in de/article_de.h (compiled after globals.h
! so that herobj/themobj global variables are already declared when needed).
