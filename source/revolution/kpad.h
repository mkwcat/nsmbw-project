#pragma once

#include <revolution/mtx.h>
#include <revolution/wpad.h>

EXTERN_C_START

struct KPADEXStatus {
    SIZE_ASSERT(0x50);

    struct Freestyle {
        SIZE_ASSERT(0x1C);

        /* 0x00 */ Vec2 stick;
        /* 0x08 */ Vec  acc;
        /* 0x14 */ f32  acc_value;
        /* 0x08 */ f32  acc_speed;
    };

    struct Classic {
        SIZE_ASSERT(0x24);

        /* 0x00 */ u32  hold;
        /* 0x04 */ u32  trig;
        /* 0x08 */ u32  release;
        /* 0x0C */ Vec2 lstick;
        /* 0x14 */ Vec2 rstick;
        /* 0x1C */ f32  ltrigger;
        /* 0x20 */ f32  rtrigger;
    };

    struct Balance {
        SIZE_ASSERT(0x50);

        /* 0x00 */ f64 tgc_weight;
        /* 0x08 */ f64 weight[4];
        /* 0x28 */ f64 weight_ave[4];
        /* 0x48 */ s32 weight_err;
        /* 0x4C */ s32 tgc_weight_err;
    };

    union {
        Freestyle fs;
        Classic   cl;
        Balance   bl;
    };
};

struct KPADStatus {
    SIZE_ASSERT(0xB0);

    /* 0x00 */ u32            hold;
    /* 0x04 */ u32            trig;
    /* 0x08 */ u32            release;
    /* 0x0C */ Vec            acc;
    /* 0x18 */ float          acc_value;
    /* 0x1C */ float          acc_speed;
    /* 0x20 */ Vec2           pos;
    /* 0x28 */ Vec2           vec;
    /* 0x30 */ f32            speed;
    /* 0x34 */ Vec2           horizon;
    /* 0x3C */ Vec2           hori_vec;
    /* 0x44 */ f32            hori_speed;
    /* 0x48 */ f32            dist;
    /* 0x4C */ f32            dist_vec;
    /* 0x50 */ f32            dist_speed;
    /* 0x54 */ Vec2           acc_vertical;
    /* 0x5C */ WPADDeviceType dev_type;
    /* 0x5D */ s8             wpad_err;
    /* 0x5E */ s8             dpd_valid_fg;
    /* 0x5F */ u8             data_format;
    /* 0x60 */ KPADEXStatus   ex_status;
};

/* 0x801ED4F0 */
int KPADReadEx(WPADChannel chan, KPADStatus* status, u32 count, s32* result);

EXTERN_C_END
