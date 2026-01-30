// From
// https://github.com/muff1n1634/wpad_11dec2009/blob/3c3aa5416d15ccc5867517d9ed4aaf6d25a70e9c/include/revolution/WPAD/WPAD.h

#pragma once

#include "revolution/sc.h"
#include "revolution/types.h"

#include <stdlib.h>

EXTERN_C_START

// Constants
// ^^^^^^

#define WPAD_MAX_DPD_OBJECTS 4

#define WPAD_MIN_DPD_SENS 1
#define WPAD_MAX_DPD_SENS 5

// Enumerations
// ^^^^^^

enum WUDLibStatus {
    WUD_LIB_STATUS_0 = 0,
    WUD_LIB_STATUS_1 = 1,
    WUD_LIB_STATUS_2 = 2,
    WUD_LIB_STATUS_3 = 3,
    WUD_LIB_STATUS_4 = 4,
    WUD_LIB_STATUS_5 = 5,
};

enum WPADLibStatus {
    WPAD_LIB_STATUS_0 = WUD_LIB_STATUS_0,
    WPAD_LIB_STATUS_1 = WUD_LIB_STATUS_1,
    WPAD_LIB_STATUS_2 = WUD_LIB_STATUS_2,
    WPAD_LIB_STATUS_3 = WUD_LIB_STATUS_3,
    WPAD_LIB_STATUS_4 = WUD_LIB_STATUS_4,
};

enum WUDChannel {
    WUD_CHAN0 = 0,
    WUD_CHAN1 = 1,
    WUD_CHAN2 = 2,
    WUD_CHAN3 = 3,

    WUD_MAX_CHANNELS = 4,
    WUD_CHAN_INVALID = -1
};

enum WPADChannel {
    WPAD_CHAN0 = WUDChannel::WUD_CHAN0,
    WPAD_CHAN1 = WUDChannel::WUD_CHAN1,
    WPAD_CHAN2 = WUDChannel::WUD_CHAN2,
    WPAD_CHAN3 = WUDChannel::WUD_CHAN3,

    WPAD_MAX_CHANNELS = WUDChannel::WUD_MAX_CHANNELS,
    WPAD_CHAN_INVALID = WUDChannel::WUD_CHAN_INVALID,
};

enum WPADResult {
    WPAD_ERR_OK = 0,
    WPAD_ERR_NO_CONTROLLER = -1,
    WPAD_ERR_COMMUNICATION_ERROR = -2,
    WPAD_ERR_3 = -3,
    WPAD_ERR_INVALID = -4,
    WPAD_ERR_CORRUPTED = -7,
};

enum WPADDeviceType : u8 {
    WPAD_DEV_CORE = 0,
    WPAD_DEV_FREESTYLE = 1,
    WPAD_DEV_CLASSIC = 2,
    WPAD_DEV_BALANCE_CHECKER = 3,
    WPAD_DEV_VSM = 4,

    WPAD_DEV_MOTION_PLUS = 5,
    WPAD_DEV_MPLS_PT_FS = 6,
    WPAD_DEV_MPLS_PT_CLASSIC = 7,

    WPAD_DEV_TRAIN = 16,
    WPAD_DEV_GUITAR = 17,
    WPAD_DEV_DRUM = 18,
    WPAD_DEV_TAIKO = 19,
    WPAD_DEV_TURNTABLE = 20,

    WPAD_DEV_BULK_1 = 21,
    WPAD_DEV_BULK_2 = 22,
    WPAD_DEV_BULK_3 = 23,
    WPAD_DEV_BULK_4 = 24,
    WPAD_DEV_BULK_5 = 25,
    WPAD_DEV_BULK_6 = 26,
    WPAD_DEV_BULK_7 = 27,
    WPAD_DEV_BULK_8 = 28,

    WPAD_DEV_MPLS_PT_UNKNOWN = 250,

    WPAD_DEV_FUTURE = 251,
    WPAD_DEV_NOT_SUPPORTED = 252,
    WPAD_DEV_NOT_FOUND = 253,
    WPAD_DEV_NULL = 254,
    WPAD_DEV_UNKNOWN = 255,
};

enum WPADDataFormat {
    WPAD_FMT_CORE_BTN = 0,
    WPAD_FMT_CORE_BTN_ACC = 1,
    WPAD_FMT_CORE_BTN_ACC_DPD = 2,

    WPAD_FMT_FS_BTN = 3,
    WPAD_FMT_FS_BTN_ACC = 4,
    WPAD_FMT_FS_BTN_ACC_DPD = 5,

    WPAD_FMT_CLASSIC_BTN = 6,
    WPAD_FMT_CLASSIC_BTN_ACC = 7,
    WPAD_FMT_CLASSIC_BTN_ACC_DPD = 8,

    WPAD_FMT_BTN_ACC_DPD_EXTENDED = 9,

    // Extensions

    WPAD_FMT_TRAIN = 10,
    WPAD_FMT_GUITAR = 11,
    WPAD_FMT_BALANCE_CHECKER = 12,
    WPAD_FMT_VSM = 13,
    WPAD_FMT_DRUM = 15,
    WPAD_FMT_MOTION_PLUS = 16,
    WPAD_FMT_TAIKO = 17,
    WPAD_FMT_TURNTABLE = 18,
    WPAD_FMT_BULK = 19,
};

enum WPADDeviceMode {
    WPAD_DEV_MODE_NORMAL = 0,

    WPAD_DEV_MODE_CLASSIC_REDUCED = 1,
    WPAD_DEV_MODE_CLASSIC_EXTENDED = 2,
    WPAD_DEV_MODE_CLASSIC_STANDARD = 3,

    WPAD_DEV_MODE_MPLS_PT_MAIN = 4,
    WPAD_DEV_MODE_MPLS_PT_FS = 5,
    WPAD_DEV_MODE_MPLS_PT_CLASSIC = 7,
};

/**
 * Wii Remote (+ Nunchuk) button bitfield.
 */

enum WPADButton : u16 {
    WPAD_BUTTON_LEFT = 0_bit,
    WPAD_BUTTON_RIGHT = 1_bit,
    WPAD_BUTTON_DOWN = 2_bit,
    WPAD_BUTTON_UP = 3_bit,
    WPAD_BUTTON_PLUS = 4_bit,

    WPAD_BUTTON_2 = 8_bit,
    WPAD_BUTTON_1 = 9_bit,
    WPAD_BUTTON_B = 10_bit,
    WPAD_BUTTON_A = 11_bit,
    WPAD_BUTTON_MINUS = 12_bit,
    WPAD_BUTTON_FS_Z = 13_bit,
    WPAD_BUTTON_FS_C = 14_bit,
    WPAD_BUTTON_HOME = 15_bit,

    WPAD_BUTTON_ALL = 0xFF1F,
};

/**
 * Wii Remote (sideways) button bitfield.
 */
enum WPADButtonSideways : u16 {
    WPAD_SIDE_BUTTON_DOWN = WPAD_BUTTON_LEFT,
    WPAD_SIDE_BUTTON_UP = WPAD_BUTTON_RIGHT,
    WPAD_SIDE_BUTTON_LEFT = WPAD_BUTTON_UP,
    WPAD_SIDE_BUTTON_RIGHT = WPAD_BUTTON_DOWN,
};

/**
 * Classic Controller button bitfield.
 */
enum WPADClassicButton : u16 {
    WPAD_BUTTON_CL_UP = 0_bit,
    WPAD_BUTTON_CL_LEFT = 1_bit,
    WPAD_BUTTON_CL_ZR = 2_bit,
    WPAD_BUTTON_CL_X = 3_bit,
    WPAD_BUTTON_CL_A = 4_bit,
    WPAD_BUTTON_CL_Y = 5_bit,
    WPAD_BUTTON_CL_B = 6_bit,
    WPAD_BUTTON_CL_ZL = 7_bit,
    WPAD_BUTTON_CL_FULL_R = 9_bit,
    WPAD_BUTTON_CL_PLUS = 10_bit,
    WPAD_BUTTON_CL_HOME = 11_bit,
    WPAD_BUTTON_CL_MINUS = 12_bit,
    WPAD_BUTTON_CL_FULL_L = 13_bit,
    WPAD_BUTTON_CL_DOWN = 14_bit,
    WPAD_BUTTON_CL_RIGHT = 15_bit,

    WPAD_BUTTON_CL_ALL = 0xFEFF,
};

enum WPADMotorCommand {
    WPAD_MOTOR_STOP = 0,
    WPAD_MOTOR_RUMBLE = 1,
};

enum WPADSpeakerCommand {
    WPAD_SPEAKER_DISABLE = 0,
    WPAD_SPEAKER_ENABLE = 1,
    WPAD_SPEAKER_MUTE = 2,
    WPAD_SPEAKER_UNMUTE = 3,
    WPAD_SPEAKER_PLAY = 4,
    WPAD_SPEAKER_CMD_05 = 5,
};

enum WPADDpdCommand {
    WPAD_DPD_DISABLE = 0x00,
    WPAD_DPD_BASIC = 0x01,
    WPAD_DPD_STANDARD = 0x03,
    WPAD_DPD_EXTENDED = 0x05,
};

enum WPADBLCCommand : u8 {
    WPAD_BLC_DISABLE = 0x00,
    WPAD_BLC_CMD_55 = 0x55,
    WPAD_BLC_ENABLE = 0xAA,
};

enum WPADMPStatusFlags : u8 {
    WPAD_MPLS_STATUS_DATA_VALID = 7_bit,
    WPAD_MPLS_STATUS_EXTENSION_DATA_VALID = 6_bit,

    WPAD_MPLS_STATUS_YAW_SLOW_MODE = 3_bit,
    WPAD_MPLS_STATUS_PITCH_SLOW_MODE = 2_bit,
    WPAD_MPLS_STATUS_ROLL_SLOW_MODE = 1_bit,

    // Just that it's present; not that it's actually being used.
    WPAD_MPLS_STATUS_EXTENSION_CONNECTED = 0_bit,
};

enum WPADAccGravityUnitType {
    WPAD_ACC_GRAVITY_UNIT_CORE,
    WPAD_ACC_GRAVITY_UNIT_FS,
};

// Type Definitions
// ^^^^^^

typedef void* (*WUDAllocFunc)(size_t size);
typedef int (*WUDFreeFunc)(void* ptr);
typedef void (*WUDSyncDeviceCallback)(s32 result, s32 num);
typedef void (*WUDClearDeviceCallback)(s32);

typedef void (*WPADInitFunc)(void); // see __wpadInitSub in WPAD.c
typedef void (*WPADCallback)(WPADChannel chan, WPADResult result);
typedef void (*WPADSamplingCallback)(WPADChannel chan);
typedef void (*WPADConnectCallback)(WPADChannel chan, s32 result);
typedef void (*WPADExtensionCallback)(WPADChannel chan, WPADDeviceType devType);

using WPADSaveCallback = SCFlushCallback;
using WPADAllocFunc = WUDAllocFunc;
using WPADFreeFunc = WUDFreeFunc;
using WPADSyncDeviceCallback = WUDSyncDeviceCallback;
using WPADSimpleSyncCallback = WUDSyncDeviceCallback;
using WPADClearDeviceCallback = WUDClearDeviceCallback;

// Structures
// ^^^^^^

struct DPDObject {
    SIZE_ASSERT(0x8);

    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ u16 size;
    /* 0x6 */ u8 traceId;
};

struct DPDObjEx {
    SIZE_ASSERT(0xC);

    /* 0x0 */ s16 range_x1;
    /* 0x2 */ s16 range_y1;
    /* 0x4 */ s16 range_x2;
    /* 0x6 */ s16 range_y2;
    /* 0x8 */ u16 pixel;
    /* 0xA */ s8 radius;
};

struct WPADInfo {
    SIZE_ASSERT(0x18);

    /* 0x00 */ BOOL dpd;
    /* 0x04 */ BOOL speaker;
    /* 0x08 */ BOOL attach;
    /* 0x0C */ BOOL lowBat;
    /* 0x10 */ BOOL nearempty;
    /* 0x14 */ u8 battery;
    /* 0x15 */ u8 led;
    /* 0x16 */ u8 protocol;
    /* 0x17 */ u8 firmware;
};

struct WPADStatus {
    SIZE_ASSERT(0x2A);

    /* 0x00 */ WPADButton button;
    /* 0x02 */ s16 accX;
    /* 0x04 */ s16 accY;
    /* 0x06 */ s16 accZ;
    /* 0x08 */ DPDObject obj[WPAD_MAX_DPD_OBJECTS];
    /* 0x28 */ u8 dev;
    /* 0x29 */ s8 err;
};

struct WPADStatusEx {
    SIZE_ASSERT(0x5A);

    /* 0x00 */ WPADStatus wpad;

    /* 0x2A */ DPDObjEx exp[WPAD_MAX_DPD_OBJECTS];
};

struct WPADFSStatus {
    SIZE_ASSERT(0x32);

    /* 0x00 */ WPADStatus wpad;

    /* 0x2A */ s16 fsAccX;
    /* 0x2C */ s16 fsAccY;
    /* 0x2E */ s16 fsAccZ;
    /* 0x30 */ s8 fsStickX;
    /* 0x31 */ s8 fsStickY;
};

struct WPADCLStatus {
    SIZE_ASSERT(0x36);

    /* 0x00 */ WPADStatus wpad;

    /* 0x2A */ WPADClassicButton clButton;
    /* 0x2C */ s16 clLStickX;
    /* 0x2E */ s16 clLStickY;
    /* 0x30 */ s16 clRStickX;
    /* 0x32 */ s16 clRStickY;
    /* 0x34 */ u8 clTriggerL;
    /* 0x35 */ u8 clTriggerR;
};

struct WPADTRStatus {
    SIZE_ASSERT(0x2E);

    /* 0x00 */ WPADStatus wpad;

    /* 0x2A */ WPADClassicButton trButton;
    /* 0x2C */ u8 brake;
    /* 0x2D */ u8 mascon;
};

struct WPADBLStatus {
    SIZE_ASSERT(0x34);

    /* 0x00 */ WPADStatus wpad;

    /* 0x2A */ u16 press[4];
    /* 0x32 */ s8 temp;
    /* 0x33 */ u8 battery;
};

struct WPADMPStatus {
    SIZE_ASSERT(0x3E);

    /* 0x00 */ WPADStatus wpad;

    union {
        // Takes its members from WPADFSStatus
        struct {
            /* 0x2A */ s16 fsAccX;
            /* 0x2C */ s16 fsAccY;
            /* 0x2E */ s16 fsAccZ;
            /* 0x30 */ s8 fsStickX;
            /* 0x31 */ s8 fsStickY;
        } fs;

        // Takes its members from WPADCLStatus
        struct {
            /* 0x2A */ WPADClassicButton clButton;
            /* 0x2C */ s16 clLStickX;
            /* 0x2E */ s16 clLStickY;
            /* 0x30 */ s16 clRStickX;
            /* 0x32 */ s16 clRStickY;
            /* 0x34 */ u8 clTriggerL;
            /* 0x35 */ u8 clTriggerR;
        } cl;
    } ext;

    /* 0x36 */ WPADMPStatusFlags stat;
    /* 0x37 */ u8 reserved;

    /* 0x38 */ s16 pitch;
    /* 0x3A */ s16 yaw;
    /* 0x3C */ s16 roll;
};

struct WPADBKStatus {
    SIZE_ASSERT(0x40);

    /* 0x00 */ WPADStatus wpad;

    /* 0x2A */ u8 bulk[21];
    /* 0x3F */ u8 padding[1];
};

struct WPADVSStatus {
    SIZE_ASSERT(0x46);

    /* 0x00 */ WPADStatus wpad;

    /* 0x2A */ u16 m0x2A[5];
    /* 0x34 */ u8 m0x34;

    /* 0x36 */ u16 m0x36[5];
    /* 0x40 */ u8 m0x40;

    /* 0x42 */ u16 m0x42;
    /* 0x44 */ u8 m0x44;
};

struct WPADAccGravityUnit {
    SIZE_ASSERT(0x6);

    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
};

// Functions
// ^^^^^^

/* 0x801DDB90 */
BOOL WPADIsEnabledVSM(void);

/* 0x801DDBA0 */
BOOL WPADIsEnabledTRN(void);

/* 0x801DDBB0 */
BOOL WPADIsEnabledGTR(void);

/* 0x801DDBC0 */
BOOL WPADIsEnabledDRM(void);

/* 0x801DFB90 */
void WPADInit(void);

/* 0x801DFC00 */
BOOL WPADStartFastSimpleSync(void);

/* 0x801DFC10 */
BOOL WPADStopSimpleSync(void);

/* 0x801DFC20 */
BOOL WPADStartClearDevice(void);

/* 0x801DFC30 */
WPADSyncDeviceCallback WPADSetSimpleSyncCallback(WPADSyncDeviceCallback pCallback);

/* 0x801DFC40 */
WPADClearDeviceCallback WPADSetClearDeviceCallback(WPADClearDeviceCallback pCallback);

/* 0x801DFC50 */
void WPADRegisterAllocator(WPADAllocFunc pAllocFunc, WPADFreeFunc pFreeFunc);

/* 0x801DFC60 */
u32 WPADGetWorkMemorySize(void);

/* 0x801DFC70 */
WPADLibStatus WPADGetStatus(void);

/* 0x801DFCD0 */
u8 WPADGetSensorBarPosition(void);

/* 0x801DFD10 */
BOOL WPADSetAcceptConnection(BOOL accept);

void WPADGetAccGravityUnit(WPADChannel chan, u32 type, WPADAccGravityUnit* pAcc);

/* 0x801E0F80 */
void WPADDisconnect(WPADChannel chan);

/* 0x801E1080 */
WPADResult WPADProbe(WPADChannel chan, u32* pDevType);

WPADSamplingCallback WPADSetSamplingCallback(WPADChannel chan, WPADSamplingCallback pCallback);
WPADConnectCallback WPADSetConnectCallback(WPADChannel chan, WPADConnectCallback pCallback);
WPADExtensionCallback WPADSetExtensionCallback(WPADChannel chan, WPADExtensionCallback pCallback);

u32 WPADGetDataFormat(WPADChannel chan);
s32 WPADSetDataFormat(WPADChannel chan, u32 format);
s32 WPADGetInfoAsync(WPADChannel chan, WPADInfo* pInfo, WPADCallback pCallback);

/* 0x801E1620 */
void WPADControlMotor(WPADChannel chan, WPADMotorCommand command);

void WPADEnableMotor(BOOL enable);
BOOL WPADIsMotorEnabled(void);
s32 WPADControlLed(WPADChannel chan, u8 flags, WPADCallback pCallback);
BOOL WPADSaveConfig(WPADSaveCallback pCallback);

/**
 * @param status should match the WPADStatus type for the channel; a check
 * against the currently assigned device type is made to know how much to copy
 *
 * for example, if devType[chan] == WPAD_DEV_CLASSIC, status should be a
 * pointer to WPADCLStatus cast to a pointer to WPADStatus
 */
void WPADRead(WPADChannel chan, WPADStatus* pStatus);

void WPADSetAutoSamplingBuf(WPADChannel chan, void* pBuffer, u32 len);
BOOL WPADIsSpeakerEnabled(WPADChannel chan);
s32 WPADControlSpeaker(WPADChannel chan, u32 command, WPADCallback pCallback);
u8 WPADGetSpeakerVolume(void);
void WPADSetSpeakerVolume(u8 volume);
BOOL WPADCanSendStreamData(WPADChannel chan);
s32 WPADSendStreamData(WPADChannel chan, void* pData, u16 len);
u8 WPADGetDpdSensitivity(void);
BOOL WPADSetSensorBarPower(BOOL enable);
BOOL WPADIsDpdEnabled(WPADChannel chan);
s32 WPADControlDpd(WPADChannel chan, u32 command, WPADCallback pCallback);
void WPADRecalibrate(WPADChannel chan);

EXTERN_C_END
