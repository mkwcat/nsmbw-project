#pragma once

EXTERN_C_START

struct __locale {
    /* 0x00 */ struct __locale*        next_locale;
    /* 0x04 */ char                    name[0x30];
    /* 0x34 */ struct _loc_coll_cmpt*  coll_cmpt_ptr;
    /* 0x38 */ struct _loc_ctype_cmpt* ctype_cmpt_ptr;
    /* 0x3C */ struct _loc_mon_cmpt*   mon_cmpt_ptr;
    /* 0x40 */ struct _loc_num_cmpt*   num_cmpt_ptr;
    /* 0x44 */ struct _loc_time_cmpt*  time_cmpt_ptr;
};

typedef int (*__decode_mbyte)(wchar_t*, const char*, size_t);
typedef int (*__encode_mbyte)(char*, wchar_t);

struct _loc_ctype_cmpt {
    /* 0x00 */ char                  name[8];
    /* 0x08 */ const unsigned short* ctype_map_ptr;
    /* 0x0C */ const unsigned char*  upper_map_ptr;
    /* 0x10 */ const unsigned char*  lower_map_ptr;
    /* 0x14 */ const unsigned short* wctype_map_ptr;
    /* 0x18 */ const wchar_t*        wupper_map_ptr;
    /* 0x1C */ const wchar_t*        wlower_map_ptr;
    /* 0x20 */ __decode_mbyte        decode_mb;
    /* 0x24 */ __encode_mbyte        encode_wc;
};

EXTERN_C_END
