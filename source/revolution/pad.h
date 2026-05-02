#pragma once

#include <revolution/types.h>

EXTERN_C_START

enum PADSpec {
    PAD_SPEC_0 = 0,
    PAD_SPEC_1 = 1,
    PAD_SPEC_2 = 2,
    PAD_SPEC_3 = 3,
    PAD_SPEC_4 = 4,
    PAD_SPEC_5 = 5,
};

enum PADMotor {
    PAD_MOTOR_STOP      = 0,
    PAD_MOTOR_RUMBLE    = 1,
    PAD_MOTOR_STOP_HARD = 2,
};

enum PADChan {
    PAD_CHAN0_BIT = 31_bit, // 0x80000000
    PAD_CHAN1_BIT = 30_bit, // 0x40000000
    PAD_CHAN2_BIT = 29_bit, // 0x20000000
    PAD_CHAN3_BIT = 28_bit, // 0x10000000
};

enum PADButton {
    PAD_BUTTON_LEFT  = 0_bit,  // 0x0001
    PAD_BUTTON_RIGHT = 1_bit,  // 0x0002
    PAD_BUTTON_DOWN  = 2_bit,  // 0x0004
    PAD_BUTTON_UP    = 3_bit,  // 0x0008
    PAD_TRIGGER_Z    = 4_bit,  // 0x0010
    PAD_TRIGGER_R    = 5_bit,  // 0x0020
    PAD_TRIGGER_L    = 6_bit,  // 0x0040
    PAD_BUTTON_A     = 8_bit,  // 0x0100
    PAD_BUTTON_B     = 9_bit,  // 0x0200
    PAD_BUTTON_X     = 10_bit, // 0x0400
    PAD_BUTTON_Y     = 11_bit, // 0x0800
    PAD_BUTTON_MENU  = 12_bit, // 0x1000
    PAD_BUTTON_START = 12_bit, // 0x1000
};

enum PADErr {
    PAD_ERR_NONE          = 0,
    PAD_ERR_NO_CONTROLLER = -1,
    PAD_ERR_NOT_READY     = -2,
    PAD_ERR_TRANSFER      = -3,
};

enum PAD {
    PAD_MAX_CONTROLLERS = 4,
    RES_WIRELESS_LITE   = 0x40000,
};

struct PADStatus {
    /* 0x00 */ u16 button;
    /* 0x02 */ s8  stickX;
    /* 0x03 */ s8  stickY;
    /* 0x04 */ s8  substickX;
    /* 0x05 */ s8  substickY;
    /* 0x06 */ u8  triggerLeft;
    /* 0x07 */ u8  triggerRight;
    /* 0x08 */ u8  analogA;
    /* 0x09 */ u8  analogB;
    /* 0x0A */ s8  err;
};

struct PADClampRegion {
    u8 minTrigger;
    u8 maxTrigger;
    s8 minStick;
    s8 maxStick;
    s8 xyStick;
    s8 minSubstick;
    s8 maxSubstick;
    s8 xySubstick;
    s8 radStick;
    s8 radSubstick;
};

typedef void (*PADSamplingCallback)(void);

// Pad
int PADReset(u32 mask);
BOOL PADRecalibrate(u32 mask);
BOOL PADInit(void);
u32 PADRead(PADStatus* status);
void PADSetSamplingRate(u32 msec);
void __PADTestSamplingRate(u32 tvmode);
void PADControlAllMotors(const u32* commandArray);
void PADControlMotor(s32 chan, u32 command);
void PADSetSpec(u32 spec);
u32 PADGetSpec(void);
int PADGetType(s32 chan, u32* type);
BOOL PADSync(void);
void PADSetAnalogMode(u32 mode);
BOOL __PADDisableRecalibration(BOOL disable);
BOOL PADIsBarrel(s32 chan);

PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback);

// Padclamp
void PADClamp(PADStatus* status);
void PADClampCircle(PADStatus* status);

EXTERN_C_END
