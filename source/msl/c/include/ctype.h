#pragma once

#include "msl/c/internal/__locale.h"

EXTERN_C_START

inline int isalpha(
    int c
) {
    extern struct __locale _current_locale;
    return ((c < 0) || (c >= 0x100))
               ? 0
               : (int) (_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x1);
}

inline int isdigit(
    int c
) {
    extern struct __locale _current_locale;
    return ((c < 0) || (c >= 0x100))
               ? 0
               : (int) (_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x8);
}

inline int isspace(
    int c
) {
    extern struct __locale _current_locale;
    return ((c < 0) || (c >= 0x100))
               ? 0
               : (int) (_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x100);
}

inline int isupper(
    int c
) {
    extern struct __locale _current_locale;
    return ((c < 0) || (c >= 0x100))
               ? 0
               : (int) (_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x200);
}

inline int isxdigit(
    int c
) {
    extern struct __locale _current_locale;
    return ((c < 0) || (c >= 0x100))
               ? 0
               : (int) (_current_locale.ctype_cmpt_ptr->ctype_map_ptr[c] & 0x400);
}

inline int toupper(
    int c
) {
    extern struct __locale _current_locale;
    return ((c < 0) || (c >= 0x100)) ? c : (int) (_current_locale.ctype_cmpt_ptr->upper_map_ptr[c]);
}

inline int tolower(
    int c
) {
    extern struct __locale _current_locale;
    return ((c < 0) || (c >= 0x100)) ? c : (int) (_current_locale.ctype_cmpt_ptr->lower_map_ptr[c]);
}

EXTERN_C_END
