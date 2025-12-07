// d_a_player_key.cpp
// NSMBW .text: 0x8005DFD0 - 0x8005E9A0

#include "d_a_player_key.h"
#include "d_game_key.h"
#include "d_system/d_game_key_core.h"
[[address(0x8005E040)]]
void dAcPyKey_c::update() ASM_METHOD(
  // clang-format off
/* 8005E040 9421FFE0 */  stwu     r1, -32(r1);
/* 8005E044 7C0802A6 */  mflr     r0;
/* 8005E048 90010024 */  stw      r0, 36(r1);
/* 8005E04C 93E1001C */  stw      r31, 28(r1);
/* 8005E050 7C7F1B78 */  mr       r31, r3;
/* 8005E054 93C10018 */  stw      r30, 24(r1);
/* 8005E058 93A10014 */  stw      r29, 20(r1);
/* 8005E05C 80830000 */  lwz      r4, 0(r3);
/* 8005E060 A0A30004 */  lhz      r5, 4(r3);
/* 8005E064 A0030006 */  lhz      r0, 6(r3);
/* 8005E068 2C04FFFF */  cmpwi    r4, -1;
/* 8005E06C B0A30008 */  sth      r5, 8(r3);
/* 8005E070 B003000A */  sth      r0, 10(r3);
/* 8005E074 40820014 */  bne-     UNDEF_8005e088;
/* 8005E078 38000000 */  li       r0, 0;
/* 8005E07C B0030004 */  sth      r0, 4(r3);
/* 8005E080 B0030006 */  sth      r0, 6(r3);
/* 8005E084 48000210 */  b        UNDEF_8005e294;
UNDEF_8005e088:;
/* 8005E088 A0C30012 */  lhz      r6, 18(r3);
/* 8005E08C 54C007FF */  clrlwi.  r0, r6, 31;
/* 8005E090 41820014 */  beq-     UNDEF_8005e0a4;
/* 8005E094 38000000 */  li       r0, 0;
/* 8005E098 B0030004 */  sth      r0, 4(r3);
/* 8005E09C B0030006 */  sth      r0, 6(r3);
/* 8005E0A0 48000074 */  b        UNDEF_8005e114;
UNDEF_8005e0a4:;
/* 8005E0A4 54C00631 */  rlwinm.  r0, r6, 0, 24, 24;
/* 8005E0A8 41820020 */  beq-     UNDEF_8005e0c8;
/* 8005E0AC A083000C */  lhz      r4, 12(r3);
/* 8005E0B0 A003000E */  lhz      r0, 14(r3);
/* 8005E0B4 7C800378 */  or       r0, r4, r0;
/* 8005E0B8 B0030004 */  sth      r0, 4(r3);
/* 8005E0BC 7C002878 */  andc     r0, r0, r5;
/* 8005E0C0 B0030006 */  sth      r0, 6(r3);
/* 8005E0C4 48000050 */  b        UNDEF_8005e114;
UNDEF_8005e0c8:;
/* 8005E0C8 54C005EF */  rlwinm.  r0, r6, 0, 23, 23;
/* 8005E0CC 41820018 */  beq-     UNDEF_8005e0e4;
/* 8005E0D0 38800004 */  li       r4, 4;
/* 8005E0D4 38000000 */  li       r0, 0;
/* 8005E0D8 B0830004 */  sth      r4, 4(r3);
/* 8005E0DC B0030006 */  sth      r0, 6(r3);
/* 8005E0E0 48000034 */  b        UNDEF_8005e114;
UNDEF_8005e0e4:;
/* 8005E0E4 80ADA8B0 */  lwz      r5, m_instance__10dGameKey_c@sda21;
/* 8005E0E8 5484103A */  slwi     r4, r4, 2;
/* 8005E0EC 54C007BD */  rlwinm.  r0, r6, 0, 30, 30;
/* 8005E0F0 7CA52214 */  add      r5, r5, r4;
/* 8005E0F4 80850004 */  lwz      r4, 4(r5);
/* 8005E0F8 80040014 */  lwz      r0, 20(r4);
/* 8005E0FC B0030004 */  sth      r0, 4(r3);
/* 8005E100 80850004 */  lwz      r4, 4(r5);
/* 8005E104 8004001C */  lwz      r0, 28(r4);
/* 8005E108 B0030006 */  sth      r0, 6(r3);
/* 8005E10C 41820008 */  beq-     UNDEF_8005e114;
/* 8005E110 48000391 */  bl       UNDEF_8005e4a0; // clearCrossKey__10dAcPyKey_cFv
UNDEF_8005e114:;
/* 8005E114 A01F0012 */  lhz      r0, 18(r31);
/* 8005E118 54000673 */  rlwinm.  r0, r0, 0, 25, 25;
/* 8005E11C 41820018 */  beq-     UNDEF_8005e134;
/* 8005E120 7FE3FB78 */  mr       r3, r31;
/* 8005E124 38800006 */  li       r4, 6;
/* 8005E128 48000339 */  bl       UNDEF_8005e460;
/* 8005E12C 3800000A */  li       r0, 10;
/* 8005E130 901F001C */  stw      r0, 28(r31);
UNDEF_8005e134:;
/* 8005E134 807F001C */  lwz      r3, 28(r31);
/* 8005E138 2C030000 */  cmpwi    r3, 0;
/* 8005E13C 4182000C */  beq-     UNDEF_8005e148;
/* 8005E140 3803FFFF */  subi     r0, r3, 1;
/* 8005E144 901F001C */  stw      r0, 28(r31);
UNDEF_8005e148:;
/* 8005E148 A09F0012 */  lhz      r4, 18(r31);
/* 8005E14C 38600000 */  li       r3, 0;
/* 8005E150 987F0018 */  stb      r3, 24(r31);
/* 8005E154 548007FF */  clrlwi.  r0, r4, 31;
/* 8005E158 987F0017 */  stb      r3, 23(r31);
/* 8005E15C 4082005C */  bne-     UNDEF_8005e1b8;
/* 8005E160 548005EF */  rlwinm.  r0, r4, 0, 23, 23;
/* 8005E164 40820054 */  bne-     UNDEF_8005e1b8;
/* 8005E168 54800631 */  rlwinm.  r0, r4, 0, 24, 24;
/* 8005E16C 41820014 */  beq-     UNDEF_8005e180;
/* 8005E170 A01F0010 */  lhz      r0, 16(r31);
/* 8005E174 981F0018 */  stb      r0, 24(r31);
/* 8005E178 981F0017 */  stb      r0, 23(r31);
/* 8005E17C 4800003C */  b        UNDEF_8005e1b8;
UNDEF_8005e180:;
/* 8005E180 801F001C */  lwz      r0, 28(r31);
/* 8005E184 2C000000 */  cmpwi    r0, 0;
/* 8005E188 40820030 */  bne-     UNDEF_8005e1b8;
/* 8005E18C 801F0000 */  lwz      r0, 0(r31);
/* 8005E190 806DA8B0 */  lwz      r3, m_instance__10dGameKey_c@sda21;
/* 8005E194 5400103A */  slwi     r0, r0, 2;
/* 8005E198 7C630214 */  add      r3, r3, r0;
/* 8005E19C 80630004 */  lwz      r3, 4(r3);
/* 8005E1A0 8803008C */  lbz      r0, 140(r3);
/* 8005E1A4 2C000000 */  cmpwi    r0, 0;
/* 8005E1A8 41820010 */  beq-     UNDEF_8005e1b8;
/* 8005E1AC 38000001 */  li       r0, 1;
/* 8005E1B0 981F0018 */  stb      r0, 24(r31);
/* 8005E1B4 981F0017 */  stb      r0, 23(r31);
UNDEF_8005e1b8:;
/* 8005E1B8 881F0015 */  lbz      r0, 21(r31);
/* 8005E1BC 2C000000 */  cmpwi    r0, 0;
/* 8005E1C0 40820010 */  bne-     UNDEF_8005e1d0;
/* 8005E1C4 38000000 */  li       r0, 0;
/* 8005E1C8 981F0016 */  stb      r0, 22(r31);
/* 8005E1CC 981F0014 */  stb      r0, 20(r31);
UNDEF_8005e1d0:;
// /* 8005E1D0 801F0000 */  lwz      r0, 0(r31);
/* 8005E1D4 3BA00000 */  li       r29, 0;
/* 8005E1D8 9BBF0015 */  stb      r29, 21(r31);
/* 8005E1DC 7FE3FB78 */  mr       r3, r31;
// /* 8005E1E0 1C000028 */  mulli    r0, r0, 40;
// /* 8005E1E4 7FDF0214 */  add      r30, r31, r0;
                         mr       r30, r31;
/* 8005E1E8 801E0044 */  lwz      r0, 68(r30);
/* 8005E1EC 901E0048 */  stw      r0, 72(r30);
/* 8005E1F0 801E00E4 */  lwz      r0, 228(r30);
/* 8005E1F4 901E00E8 */  stw      r0, 232(r30);
/* 8005E1F8 801E0040 */  lwz      r0, 64(r30);
/* 8005E1FC 901E0044 */  stw      r0, 68(r30);
/* 8005E200 801E00E0 */  lwz      r0, 224(r30);
/* 8005E204 901E00E4 */  stw      r0, 228(r30);
/* 8005E208 801E003C */  lwz      r0, 60(r30);
/* 8005E20C 901E0040 */  stw      r0, 64(r30);
/* 8005E210 801E00DC */  lwz      r0, 220(r30);
/* 8005E214 901E00E0 */  stw      r0, 224(r30);
/* 8005E218 801E0038 */  lwz      r0, 56(r30);
/* 8005E21C 901E003C */  stw      r0, 60(r30);
/* 8005E220 801E00D8 */  lwz      r0, 216(r30);
/* 8005E224 901E00DC */  stw      r0, 220(r30);
/* 8005E228 801E0034 */  lwz      r0, 52(r30);
/* 8005E22C 901E0038 */  stw      r0, 56(r30);
/* 8005E230 801E00D4 */  lwz      r0, 212(r30);
/* 8005E234 901E00D8 */  stw      r0, 216(r30);
/* 8005E238 801E0030 */  lwz      r0, 48(r30);
/* 8005E23C 901E0034 */  stw      r0, 52(r30);
/* 8005E240 801E00D0 */  lwz      r0, 208(r30);
/* 8005E244 901E00D4 */  stw      r0, 212(r30);
/* 8005E248 801E002C */  lwz      r0, 44(r30);
/* 8005E24C 901E0030 */  stw      r0, 48(r30);
/* 8005E250 801E00CC */  lwz      r0, 204(r30);
/* 8005E254 901E00D0 */  stw      r0, 208(r30);
/* 8005E258 801E0028 */  lwz      r0, 40(r30);
/* 8005E25C 901E002C */  stw      r0, 44(r30);
/* 8005E260 801E00C8 */  lwz      r0, 200(r30);
/* 8005E264 901E00CC */  stw      r0, 204(r30);
/* 8005E268 801E0024 */  lwz      r0, 36(r30);
/* 8005E26C 901E0028 */  stw      r0, 40(r30);
/* 8005E270 801E00C4 */  lwz      r0, 196(r30);
/* 8005E274 901E00C8 */  stw      r0, 200(r30);
/* 8005E278 48000469 */  bl       UNDEF_8005e6e0;
/* 8005E27C 907E0024 */  stw      r3, 36(r30);
/* 8005E280 7FE3FB78 */  mr       r3, r31;
/* 8005E284 480004BD */  bl       UNDEF_8005e740;
/* 8005E288 907E00C4 */  stw      r3, 196(r30);
/* 8005E28C B3BF000E */  sth      r29, 14(r31);
/* 8005E290 B3BF0010 */  sth      r29, 16(r31);
UNDEF_8005e294:;
/* 8005E294 80010024 */  lwz      r0, 36(r1);
/* 8005E298 83E1001C */  lwz      r31, 28(r1);
/* 8005E29C 83C10018 */  lwz      r30, 24(r1);
/* 8005E2A0 83A10014 */  lwz      r29, 20(r1);
/* 8005E2A4 7C0803A6 */  mtlr     r0;
/* 8005E2A8 38210020 */  addi     r1, r1, 32;
/* 8005E2AC 4E800020 */  blr;

  // clang-format on
);

[[address(0x8005E590)]]
u16 dAcPyKey_c::triggerOne() const
{
    dGameKeyCore_c* core = dGameKey_c::m_instance->mpCores[mRemoconID];
    switch (core->mType) {
    case dGameKeyCore_c::Type_e::DOLPHIN:
    case dGameKeyCore_c::Type_e::FREESTYLE:
        // Nunchuk mode
        return mTriggeredButtons & dGameKeyCore_c::BTN_B;

    default:
        // Other
        return mTriggeredButtons & dGameKeyCore_c::BTN_1;
    }
}

[[address(0x8005E5D0)]]
u16 dAcPyKey_c::buttonOne() const
{
    dGameKeyCore_c* core = dGameKey_c::m_instance->mpCores[mRemoconID];
    switch (core->mType) {
    case dGameKeyCore_c::Type_e::DOLPHIN:
    case dGameKeyCore_c::Type_e::FREESTYLE:
        // Nunchuk mode
        return mDownButtons & dGameKeyCore_c::BTN_B;
        
    default:
        // Other
        return mDownButtons & dGameKeyCore_c::BTN_1;
    }
}

[[address(0x8005E8B0)]]
bool dAcPyKey_c::triggerJumpBuf(int param2) ASM_METHOD(
  // clang-format off
/* 8005E8B0 80030000 */  lwz      r0, 0(r3);
/* 8005E8B4 2C00FFFF */  cmpwi    r0, -1;
/* 8005E8B8 4082000C */  bne-     UNDEF_8005e8c4;
/* 8005E8BC 38600000 */  li       r3, 0;
/* 8005E8C0 4E800020 */  blr;
UNDEF_8005e8c4:;
/* 8005E8C4 2C04000A */  cmpwi    r4, 10;
/* 8005E8C8 40810008 */  ble-     UNDEF_8005e8d0;
/* 8005E8CC 3880000A */  li       r4, 10;
UNDEF_8005e8d0:;
// /* 8005E8D0 1C000028 */  mulli    r0, r0, 40;
// /* 8005E8D4 7C630214 */  add      r3, r3, r0;
/* 8005E8D8 38630024 */  addi     r3, r3, 36;
/* 8005E8DC 7C8903A6 */  mtctr    r4;
/* 8005E8E0 2C040000 */  cmpwi    r4, 0;
/* 8005E8E4 40810020 */  ble-     UNDEF_8005e904;
UNDEF_8005e8e8:;
/* 8005E8E8 80030000 */  lwz      r0, 0(r3);
/* 8005E8EC 2C000000 */  cmpwi    r0, 0;
/* 8005E8F0 4182000C */  beq-     UNDEF_8005e8fc;
/* 8005E8F4 38600001 */  li       r3, 1;
/* 8005E8F8 4E800020 */  blr;
UNDEF_8005e8fc:;
/* 8005E8FC 38630004 */  addi     r3, r3, 4;
/* 8005E900 4200FFE8 */  bdnz+    UNDEF_8005e8e8;
UNDEF_8005e904:;
/* 8005E904 38600000 */  li       r3, 0;
/* 8005E908 4E800020 */  blr;
  // clang-format on
);

[[address(0x8005E910)]]
void dAcPyKey_c::onDemoButton(int button);

[[address(0x8005E930)]]
void dAcPyKey_c::offDemoButton(int button);
