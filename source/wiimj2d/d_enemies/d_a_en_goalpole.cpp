// d_a_en_goalpole.cpp
// NSMBW d_enemies.text: 0x80A096E0 - 0x80A0BE30

#include "d_a_en_goalpole.h"

#include "d_system/d_a_player_base.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_cc.h"
#include <bit>

[[nsmbw(0x80A096E0)]]
daEnGlpole_c* daEnGlpole_c_classInit()
{
    return new daEnGlpole_c();
}

[[nsmbw(0x80A09710)]]
daEnGlpole_c::daEnGlpole_c();

/**
 * VT+0x08
 * do method for the create operation.
 */
[[nsmbw(0x80A09980)]]
fBase_c::PACK_RESULT_e daEnGlpole_c::create() ASM_METHOD(
  // clang-format off
/* 80A09980 9421FFE0 */  stwu     r1, -32(r1);
/* 80A09984 7C0802A6 */  mflr     r0;
/* 80A09988 90010024 */  stw      r0, 36(r1);
/* 80A0998C 93E1001C */  stw      r31, 28(r1);
/* 80A09990 7C7F1B78 */  mr       r31, r3;
/* 80A09994 93C10018 */  stw      r30, 24(r1);
/* 80A09998 3FC080AF */  lis      r30, UNDEF_80aec030@ha;
/* 80A0999C 3BDEC030 */  addi     r30, r30, UNDEF_80aec030@l;
/* 80A099A0 93A10014 */  stw      r29, 20(r1);
/* 80A099A4 3FA080AD */  lis      r29, UNDEF_80ad01d0@ha;
/* 80A099A8 3BBD01D0 */  addi     r29, r29, UNDEF_80ad01d0@l;
/* 80A099AC 80030004 */  lwz      r0, 4(r3);
/* 80A099B0 5404273E */  srwi     r4, r0, 28;
/* 80A099B4 5400073E */  clrlwi   r0, r0, 28;
/* 80A099B8 90830AA4 */  stw      r4, 2724(r3);
/* 80A099BC 90030AA0 */  stw      r0, 2720(r3);
/* 80A099C0 4B65B191 */  bl       UNDEF_80064b50; // checkAreaNo__8dActor_cFv
/* 80A099C4 2C030000 */  cmpwi    r3, 0;
/* 80A099C8 4082000C */  bne-     UNDEF_80a099d4;
/* 80A099CC 38600002 */  li       r3, 2;
/* 80A099D0 4800027C */  b        UNDEF_80a09c4c;
UNDEF_80a099d4:;
/* 80A099D4 C03F00AC */  lfs      f1, 172(r31);
/* 80A099D8 3C808043 */  lis      r4, UNDEF_8042a020@ha;
/* 80A099DC C01D0088 */  lfs      f0, 136(r29);
/* 80A099E0 7FE3FB78 */  mr       r3, r31;
/* 80A099E4 8084A020 */  lwz      r4, UNDEF_8042a020@l(r4);
/* 80A099E8 EC010028 */  fsubs    f0, f1, f0;
/* 80A099EC D0040044 */  stfs     f0, 68(r4);
/* 80A099F0 48000681 */  bl       UNDEF_80a0a070;
/* 80A099F4 C05F00AC */  lfs      f2, 172(r31);
/* 80A099F8 38C00000 */  li       r6, 0;
/* 80A099FC C01D0088 */  lfs      f0, 136(r29);
/* 80A09A00 3800FFFF */  li       r0, -1;
/* 80A09A04 C0FF00B0 */  lfs      f7, 176(r31);
/* 80A09A08 7FE4FB78 */  mr       r4, r31;
/* 80A09A0C EC620028 */  fsubs    f3, f2, f0;
/* 80A09A10 C03D008C */  lfs      f1, 140(r29);
/* 80A09A14 C09D0090 */  lfs      f4, 144(r29);
/* 80A09A18 EC070028 */  fsubs    f0, f7, f0;
/* 80A09A1C ECC1382A */  fadds    f6, f1, f7;
/* 80A09A20 C03D0094 */  lfs      f1, 148(r29);
/* 80A09A24 D05F07C0 */  stfs     f2, 1984(r31);
/* 80A09A28 ECA1382A */  fadds    f5, f1, f7;
/* 80A09A2C C05D0098 */  lfs      f2, 152(r29);
/* 80A09A30 387F0148 */  addi     r3, r31, 328;
/* 80A09A34 D0DF07C4 */  stfs     f6, 1988(r31);
/* 80A09A38 38BD0014 */  addi     r5, r29, 20;
/* 80A09A3C C03D009C */  lfs      f1, 156(r29);
/* 80A09A40 D09F07C8 */  stfs     f4, 1992(r31);
/* 80A09A44 D07F0A84 */  stfs     f3, 2692(r31);
/* 80A09A48 C09E0018 */  lfs      f4, 24(r30);
/* 80A09A4C C07E001C */  lfs      f3, 28(r30);
/* 80A09A50 EC85202A */  fadds    f4, f5, f4;
/* 80A09A54 D01F00B0 */  stfs     f0, 176(r31);
/* 80A09A58 EC63202A */  fadds    f3, f3, f4;
/* 80A09A5C D0FF0A80 */  stfs     f7, 2688(r31);
/* 80A09A60 D03F0A8C */  stfs     f1, 2700(r31);
/* 80A09A64 EC031028 */  fsubs    f0, f3, f2;
/* 80A09A6C D01F0A88 */  stfs     f0, 2696(r31);

                         li       r10, PLAYER_COUNT;
                         mtctr    r10;
                         addi     r11, r31, daEnGlpole_c_OFFSET_mPlayerPos;
L_daEnGlpole_c_create_ClearLoopStart:;
                         sth      r6, 0x00(r11);
                         stfs     f1, 0x04(r11);
                         stw      r6, 0x08(r11);
                         stb      r0, 0x0C(r11);
                         stb      r6, 0x0D(r11);
                         addi     r11, r11, 0x10;
                         bdnz+    L_daEnGlpole_c_create_ClearLoopStart;

/* 80A09ABC 90DF0A9C */  stw      r6, 2716(r31);
/* 80A09AC0 98DF0AAA */  stb      r6, 2730(r31);
/* 80A09AC4 4B68291D */  bl       UNDEF_8008c3e0;
/* 80A09AC8 C07D009C */  lfs      f3, 156(r29);
/* 80A09ACC 387F0148 */  addi     r3, r31, 328;
/* 80A09AD0 D07F0A18 */  stfs     f3, 2584(r31);
/* 80A09AD4 C03D00A0 */  lfs      f1, 160(r29);
/* 80A09AD8 C05E0018 */  lfs      f2, 24(r30);
/* 80A09ADC D05F0A1C */  stfs     f2, 2588(r31);
/* 80A09AE0 D03F0A20 */  stfs     f1, 2592(r31);
/* 80A09AE4 C01E001C */  lfs      f0, 28(r30);
/* 80A09AE8 D01F0A24 */  stfs     f0, 2596(r31);
/* 80A09AEC D07F0164 */  stfs     f3, 356(r31);
/* 80A09AF0 D05F0168 */  stfs     f2, 360(r31);
/* 80A09AF4 D03F016C */  stfs     f1, 364(r31);
/* 80A09AF8 D01F0170 */  stfs     f0, 368(r31);
/* 80A09AFC 4B682835 */  bl       UNDEF_8008c330;
/* 80A09B00 3C608043 */  lis      r3, UNDEF_8042a260@ha;
/* 80A09B04 8003A260 */  lwz      r0, UNDEF_8042a260@l(r3);
/* 80A09B08 540006F7 */  rlwinm.  r0, r0, 0, 27, 27;
/* 80A09B0C 40820028 */  bne-     UNDEF_80a09b34;
/* 80A09B10 7FE4FB78 */  mr       r4, r31;
/* 80A09B14 387F0974 */  addi     r3, r31, 2420;
/* 80A09B18 38BD0038 */  addi     r5, r29, 56;
/* 80A09B1C 4B6828C5 */  bl       UNDEF_8008c3e0;
/* 80A09B20 3C808043 */  lis      r4, UNDEF_8042a008@ha;
/* 80A09B24 387F0974 */  addi     r3, r31, 2420;
/* 80A09B28 8804A008 */  lbz      r0, UNDEF_8042a008@l(r4);
/* 80A09B2C 981F0A14 */  stb      r0, 2580(r31);
/* 80A09B30 4B682801 */  bl       UNDEF_8008c330;
UNDEF_80a09b34:;
/* 80A09B34 7FE4FB78 */  mr       r4, r31;
/* 80A09B38 387F08D0 */  addi     r3, r31, 2256;
/* 80A09B3C 38BD005C */  addi     r5, r29, 92;
/* 80A09B40 4B6828A1 */  bl       UNDEF_8008c3e0;
/* 80A09B44 C07E0020 */  lfs      f3, 32(r30);
/* 80A09B48 3C808043 */  lis      r4, UNDEF_8042a008@ha;
/* 80A09B4C D07F0A28 */  stfs     f3, 2600(r31);
/* 80A09B50 387F08D0 */  addi     r3, r31, 2256;
/* 80A09B54 C05E0024 */  lfs      f2, 36(r30);
/* 80A09B58 D05F0A2C */  stfs     f2, 2604(r31);
/* 80A09B5C C03E0028 */  lfs      f1, 40(r30);
/* 80A09B60 D03F0A30 */  stfs     f1, 2608(r31);
/* 80A09B64 C01E002C */  lfs      f0, 44(r30);
/* 80A09B68 D01F0A34 */  stfs     f0, 2612(r31);
/* 80A09B6C D07F08EC */  stfs     f3, 2284(r31);
/* 80A09B70 D05F08F0 */  stfs     f2, 2288(r31);
/* 80A09B74 D03F08F4 */  stfs     f1, 2292(r31);
/* 80A09B78 D01F08F8 */  stfs     f0, 2296(r31);
/* 80A09B7C 8804A008 */  lbz      r0, UNDEF_8042a008@l(r4);
/* 80A09B80 981F0970 */  stb      r0, 2416(r31);
/* 80A09B84 4B6827AD */  bl       UNDEF_8008c330;
/* 80A09B88 C01D00A4 */  lfs      f0, 164(r29);
/* 80A09B8C 3CA080B1 */  lis      r5, UNDEF_80b15560@ha;
/* 80A09B90 D01F07CC */  stfs     f0, 1996(r31);
/* 80A09B94 7FE4FB78 */  mr       r4, r31;
/* 80A09B98 88FF038F */  lbz      r7, 911(r31);
/* 80A09B9C 387F07EC */  addi     r3, r31, 2028;
/* 80A09BA0 D01F07D0 */  stfs     f0, 2000(r31);
/* 80A09BA4 38A55560 */  addi     r5, r5, UNDEF_80b15560@l;
/* 80A09BA8 391F07CC */  addi     r8, r31, 1996;
/* 80A09BAC 38C00003 */  li       r6, 3;
/* 80A09BB0 D01F07D4 */  stfs     f0, 2004(r31);
/* 80A09BB4 4B675F5D */  bl       UNDEF_8007fb10;
/* 80A09BB8 387F07EC */  addi     r3, r31, 2028;
/* 80A09BBC 4B675D45 */  bl       UNDEF_8007f900;
/* 80A09BC0 C03D00A4 */  lfs      f1, 164(r29);
/* 80A09BC4 3BC00000 */  li       r30, 0;
/* 80A09BC8 C01F00AC */  lfs      f0, 172(r31);
/* 80A09BCC 3800C000 */  li       r0, -16384;
/* 80A09BD0 9BDF036D */  stb      r30, 877(r31);
/* 80A09BD4 3C8080B1 */  lis      r4, UNDEF_80b15470@ha;
/* 80A09BD8 7FE3FB78 */  mr       r3, r31;
/* 80A09BDC D03F00DC */  stfs     f1, 220(r31);
/* 80A09BE0 38845470 */  addi     r4, r4, UNDEF_80b15470@l;
/* 80A09BE4 D03F00E0 */  stfs     f1, 224(r31);
/* 80A09BE8 D03F00E4 */  stfs     f1, 228(r31);
/* 80A09BEC B3DF07D8 */  sth      r30, 2008(r31);
/* 80A09BF0 B01F07DA */  sth      r0, 2010(r31);
/* 80A09BF4 B3DF07DC */  sth      r30, 2012(r31);
/* 80A09BF8 B3DF0100 */  sth      r30, 256(r31);
/* 80A09BFC B3DF0102 */  sth      r30, 258(r31);
/* 80A09C00 B3DF0104 */  sth      r30, 260(r31);
/* 80A09C04 D01F0A7C */  stfs     f0, 2684(r31);
/* 80A09C08 819F0060 */  lwz      r12, 96(r31);
/* 80A09C0C 818C00D4 */  lwz      r12, 212(r12);
/* 80A09C10 7D8903A6 */  mtctr    r12;
/* 80A09C14 4E800421 */  bctrl;
/* 80A09C18 C07D009C */  lfs      f3, 156(r29);
/* 80A09C1C 38600001 */  li       r3, 1;
/* 80A09C20 C05D00A8 */  lfs      f2, 168(r29);
/* 80A09C24 C03D00AC */  lfs      f1, 172(r29);
/* 80A09C28 C01D00B0 */  lfs      f0, 176(r29);
/* 80A09C2C 9BDF0AAE */  stb      r30, 2734(r31);
/* 80A09C30 9BDF0AAC */  stb      r30, 2732(r31);
/* 80A09C34 9BDF0AAB */  stb      r30, 2731(r31);
/* 80A09C38 D07F0A78 */  stfs     f3, 2680(r31);
/* 80A09C3C D07F0320 */  stfs     f3, 800(r31);
/* 80A09C40 D05F0324 */  stfs     f2, 804(r31);
/* 80A09C44 D03F0318 */  stfs     f1, 792(r31);
/* 80A09C48 D01F031C */  stfs     f0, 796(r31);
UNDEF_80a09c4c:;
/* 80A09C4C 80010024 */  lwz      r0, 36(r1);
/* 80A09C50 83E1001C */  lwz      r31, 28(r1);
/* 80A09C54 83C10018 */  lwz      r30, 24(r1);
/* 80A09C58 83A10014 */  lwz      r29, 20(r1);
/* 80A09C5C 7C0803A6 */  mtlr     r0;
/* 80A09C60 38210020 */  addi     r1, r1, 32;
/* 80A09C64 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80A0A550)]]
void daEnGlpole_c::ccCallBackForPole2(dCc_c* self, dCc_c* other)
{
    if (other->mCcData.mAttack == CC_ATTACK_YOSHI_EAT) {
        return;
    }

    daPlBase_c* player = other->mpOwner->DynamicCast<daPlBase_c>();
    if (player == nullptr || player->m0x43C) {
        return;
    }

    static_cast<daEnGlpole_c*>(self->mpOwner)->mPlrTouchPoleFlag2 |= (1u << player->getPlrNo());
}

[[nsmbw(0x80A0A5E0)]]
void daEnGlpole_c::ccCallBackForPole(dCc_c* self, dCc_c* other)
{
    if (other->mCcData.mAttack == CC_ATTACK_YOSHI_EAT) {
        return;
    }

    daPlBase_c* player = other->mpOwner->DynamicCast<daPlBase_c>();
    if (player == nullptr || player->m0x43C) {
        return;
    }

    static_cast<daEnGlpole_c*>(self->mpOwner)->mPlrTouchPoleFlag |= (1u << player->getPlrNo());
}

[[nsmbw(0x80A0A700)]]
bool daEnGlpole_c::isTopOfFlagPole(u32 mask, int player)
{
    return mask & (1u << player);
}

float l_POLE_PLAYER_BASE_POS[PLAYER_COUNT] = {
  8.0 * 1, 8.0 * 2, 8.0 * 3, 8.0 * 4, 8.0 * 5, 8.0 * 6, 8.0 * 7,
};

[[nsmbw(0x80A0AB10)]]
void UNDEF_80A0AB10() ASM_METHOD(
  // clang-format off
/* 80A0AB10 9421FFD0 */  stwu     r1, -48(r1);
/* 80A0AB14 7C0802A6 */  mflr     r0;
/* 80A0AB18 90010034 */  stw      r0, 52(r1);
/* 80A0AB1C 93E1002C */  stw      r31, 44(r1);
/* 80A0AB20 93C10028 */  stw      r30, 40(r1);
/* 80A0AB24 93A10024 */  stw      r29, 36(r1);
/* 80A0AB28 93810020 */  stw      r28, 32(r1);
/* 80A0AB2C 7C7C1B78 */  mr       r28, r3;
/* 80A0AB30 80030A9C */  lwz      r0, 2716(r3);
/* 80A0AB34 2C000000 */  cmpwi    r0, 0;
/* 80A0AB38 4182007C */  beq-     UNDEF_80a0abb4;
/* 80A0AB3C 3C8080AD */  lis      r4, UNDEF_80ad02c8@ha;
/* 80A0AB40 3FE080AD */  lis      r31, l_POLE_PLAYER_BASE_POS@ha;
/* 80A0AB44 C06300AC */  lfs      f3, 172(r3);
/* 80A0AB48 7F9EE378 */  mr       r30, r28;
/* 80A0AB4C C00402C8 */  lfs      f0, UNDEF_80ad02c8@l(r4);
/* 80A0AB50 3BFF02B8 */  addi     r31, r31, l_POLE_PLAYER_BASE_POS@l;
/* 80A0AB54 C02300B4 */  lfs      f1, 180(r3);
/* 80A0AB58 3BA00000 */  li       r29, 0;
/* 80A0AB5C C04300B0 */  lfs      f2, 176(r3);
/* 80A0AB60 EC030028 */  fsubs    f0, f3, f0;
/* 80A0AB64 D041000C */  stfs     f2, 12(r1);
/* 80A0AB68 D0210010 */  stfs     f1, 16(r1);
/* 80A0AB6C D0010008 */  stfs     f0, 8(r1);
/* 80A0AB70 48000038 */  b        UNDEF_80a0aba8;
UNDEF_80a0ab74:;
/* 80A0AB74 C05C0A80 */  lfs      f2, 2688(r28);
/* 80A0AB78 38610008 */  addi     r3, r1, 8;
/* 80A0AB7C C03F0000 */  lfs      f1, 0(r31);
/* 80A0AB80 C01C0A8C */  lfs      f0, 2700(r28);
/* 80A0AB84 EC22082A */  fadds    f1, f2, f1;
/* 80A0AB88 EC00082A */  fadds    f0, f0, f1;
/* 80A0AB8C D001000C */  stfs     f0, 12(r1);
/* 80A0AB90 889E0A44 */  lbz      r4, 2628 + daEnGlpole_c_ADJUST_mPlayerPos(r30);
/* 80A0AB94 7C840774 */  extsb    r4, r4;
/* 80A0AB98 4B6A8A39 */  bl       UNDEF_800b35d0;
/* 80A0AB9C 3BFF0004 */  addi     r31, r31, 4;
/* 80A0ABA0 3BDE0010 */  addi     r30, r30, 16;
/* 80A0ABA4 3BBD0001 */  addi     r29, r29, 1;
UNDEF_80a0aba8:;
/* 80A0ABA8 801C0A9C */  lwz      r0, 2716(r28);
/* 80A0ABAC 7C1D0000 */  cmpw     r29, r0;
/* 80A0ABB0 4180FFC4 */  blt+     UNDEF_80a0ab74;
UNDEF_80a0abb4:;
/* 80A0ABB4 80010034 */  lwz      r0, 52(r1);
/* 80A0ABB8 83E1002C */  lwz      r31, 44(r1);
/* 80A0ABBC 83C10028 */  lwz      r30, 40(r1);
/* 80A0ABC0 83A10024 */  lwz      r29, 36(r1);
/* 80A0ABC4 83810020 */  lwz      r28, 32(r1);
/* 80A0ABC8 7C0803A6 */  mtlr     r0;
/* 80A0ABCC 38210030 */  addi     r1, r1, 48;
/* 80A0ABD0 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80A0ABE0)]]
void UNDEF_80A0ABE0() ASM_METHOD(
  // clang-format off
UNDEF_80a0abe0:;
/* 80A0ABE0 9421FFD0 */  stwu     r1, -48(r1);
/* 80A0ABE4 7C0802A6 */  mflr     r0;
/* 80A0ABE8 90010034 */  stw      r0, 52(r1);
/* 80A0ABEC 39610030 */  addi     r11, r1, 48;
/* 80A0ABF0 4B8D2471 */  bl       UNDEF_802dd060;
/* 80A0ABF4 C00300B4 */  lfs      f0, 180(r3);
/* 80A0ABF8 3FE080AD */  lis      r31, UNDEF_80ad01d0@ha;
/* 80A0ABFC C02300B0 */  lfs      f1, 176(r3);
/* 80A0AC00 2806FFFF */  cmplwi   r6, 65535;
/* 80A0AC04 C04300AC */  lfs      f2, 172(r3);
/* 80A0AC08 7C7B1B78 */  mr       r27, r3;
/* 80A0AC0C D0410008 */  stfs     f2, 8(r1);
/* 80A0AC10 7C9A2378 */  mr       r26, r4;
/* 80A0AC14 7CBC2B78 */  mr       r28, r5;
/* 80A0AC18 3BFF01D0 */  addi     r31, r31, UNDEF_80ad01d0@l;
/* 80A0AC1C D021000C */  stfs     f1, 12(r1);
/* 80A0AC20 3BC00000 */  li       r30, 0;
/* 80A0AC24 D0010010 */  stfs     f0, 16(r1);
/* 80A0AC28 C0230A88 */  lfs      f1, 2696(r3);
/* 80A0AC2C C00400B0 */  lfs      f0, 176(r4);
/* 80A0AC30 EC610028 */  fsubs    f3, f1, f0;
/* 80A0AC34 40820050 */  bne-     UNDEF_80a0ac84;
/* 80A0AC38 C01F009C */  lfs      f0, 156(r31);
/* 80A0AC3C FC030040 */  fcmpo    cr0, f3, f0;
/* 80A0AC40 40800008 */  bge-     UNDEF_80a0ac48;
/* 80A0AC44 FC600090 */  fmr      f3, f0;
UNDEF_80a0ac48:;
/* 80A0AC48 C05F0150 */  lfs      f2, 336(r31);
/* 80A0AC4C C01F009C */  lfs      f0, 156(r31);
/* 80A0AC50 48000010 */  b        UNDEF_80a0ac60;
UNDEF_80a0ac58:;
/* 80A0AC58 EC631028 */  fsubs    f3, f3, f2;
/* 80A0AC5C 3BDE0001 */  addi     r30, r30, 1;
UNDEF_80a0ac60:;
/* 80A0AC60 EC231028 */  fsubs    f1, f3, f2;
/* 80A0AC64 FC010040 */  fcmpo    cr0, f1, f0;
/* 80A0AC68 4C411382 */  cror     2, 1, 2;
/* 80A0AC6C 4182FFEC */  beq+     UNDEF_80a0ac58;
/* 80A0AC70 57C0043E */  clrlwi   r0, r30, 16;
/* 80A0AC74 28000007 */  cmplwi   r0, 7;
/* 80A0AC78 41800010 */  blt-     UNDEF_80a0ac88;
/* 80A0AC7C 3BC00007 */  li       r30, 7;
/* 80A0AC80 48000008 */  b        UNDEF_80a0ac88;
UNDEF_80a0ac84:;
/* 80A0AC84 7CDE3378 */  mr       r30, r6;
UNDEF_80a0ac88:;
/* 80A0AC88 57C00BFC */  clrlslwi r0, r30, 16, 1;
/* 80A0AC8C 387F0100 */  addi     r3, r31, 256;
/* 80A0AC90 7FA3022E */  lhzx     r29, r3, r0;
/* 80A0AC94 7F63DB78 */  mr       r3, r27;
/* 80A0AC98 7F44D378 */  mr       r4, r26;
/* 80A0AC9C 48000465 */  bl       UNDEF_80a0b100;
/* 80A0ACA0 2C030000 */  cmpwi    r3, 0;
/* 80A0ACA4 41820008 */  beq-     UNDEF_80a0acac;
/* 80A0ACA8 3BA0000A */  li       r29, 10;
UNDEF_80a0acac:;
/* 80A0ACAC 281D000A */  cmplwi   r29, 10;
/* 80A0ACB0 41820140 */  beq-     UNDEF_80a0adf0;
/* 80A0ACB4 57C0043F */  clrlwi.  r0, r30, 16;
/* 80A0ACB8 40820020 */  bne-     UNDEF_80a0acd8;
/* 80A0ACBC 889B0AAD */  lbz      r4, 2733(r27);
/* 80A0ACC0 7F63DB78 */  mr       r3, r27;
/* 80A0ACC4 7F85E378 */  mr       r5, r28;
/* 80A0ACC8 4BFFFA39 */  bl       UNDEF_80a0a700;
/* 80A0ACCC 2C030000 */  cmpwi    r3, 0;
/* 80A0ACD0 41820008 */  beq-     UNDEF_80a0acd8;
/* 80A0ACD4 3BA00009 */  li       r29, 9;
UNDEF_80a0acd8:;
/* 80A0ACD8 801B0A9C */  lwz      r0, 2716(r27);
/* 80A0ACDC 38800000 */  li       r4, 0;
/* 80A0ACE0 C01A00B0 */  lfs      f0, 176(r26);
/* 80A0ACE4 54002036 */  slwi     r0, r0, 4;
/* 80A0ACE8 7C7B0214 */  add      r3, r27, r0;
/* 80A0ACEC D0030A3C */  stfs     f0, 2620 + daEnGlpole_c_ADJUST_mPlayerPos(r3);
/* 80A0ACF0 801B0A9C */  lwz      r0, 2716(r27);
/* 80A0ACF4 54002036 */  slwi     r0, r0, 4;
/* 80A0ACF8 7C7B0214 */  add      r3, r27, r0;
/* 80A0ACFC B3A30A38 */  sth      r29, 2616 + daEnGlpole_c_ADJUST_mPlayerPos(r3);
/* 80A0AD00 801B0A9C */  lwz      r0, 2716(r27);
/* 80A0AD04 54002036 */  slwi     r0, r0, 4;
/* 80A0AD08 7C7B0214 */  add      r3, r27, r0;
/* 80A0AD0C 9B830A44 */  stb      r28, 2628 + daEnGlpole_c_ADJUST_mPlayerPos(r3);
/* 80A0AD10 807B0A9C */  lwz      r3, 2716(r27);
/* 80A0AD14 54602036 */  slwi     r0, r3, 4;
/* 80A0AD18 38A30001 */  addi     r5, r3, 1;
/* 80A0AD1C 7C7B0214 */  add      r3, r27, r0;
/* 80A0AD20 90A30A40 */  stw      r5, 2624 + daEnGlpole_c_ADJUST_mPlayerPos(r3);
/* 80A0AD24 801B0A9C */  lwz      r0, 2716(r27);
/* 80A0AD28 54002036 */  slwi     r0, r0, 4;
/* 80A0AD2C 7C7B0214 */  add      r3, r27, r0;
/* 80A0AD30 98830A45 */  stb      r4, 2629 + daEnGlpole_c_ADJUST_mPlayerPos(r3);
/* 80A0AD34 801B0A9C */  lwz      r0, 2716(r27);
/* 80A0AD38 2C000000 */  cmpwi    r0, 0;
/* 80A0AD3C 41820010 */  beq-     UNDEF_80a0ad4c;
/* 80A0AD40 7F63DB78 */  mr       r3, r27;
/* 80A0AD44 4BFFFCAD */  bl       UNDEF_80a0a9f0;
/* 80A0AD48 48000014 */  b        UNDEF_80a0ad5c;
UNDEF_80a0ad4c:;
/* 80A0AD4C 54002036 */  slwi     r0, r0, 4;
/* 80A0AD50 38800001 */  li       r4, 1;
/* 80A0AD54 7C7B0214 */  add      r3, r27, r0;
/* 80A0AD58 98830A45 */  stb      r4, 2629 + daEnGlpole_c_ADJUST_mPlayerPos(r3);
UNDEF_80a0ad5c:;
/* 80A0AD5C C0210008 */  lfs      f1, 8(r1);
/* 80A0AD60 387F00E8 */  addi     r3, r31, 232;
/* 80A0AD64 C01F00F8 */  lfs      f0, 248(r31);
/* 80A0AD68 281D0009 */  cmplwi   r29, 9;
/* 80A0AD6C EC010028 */  fsubs    f0, f1, f0;
/* 80A0AD70 D0010008 */  stfs     f0, 8(r1);
/* 80A0AD74 801B0A9C */  lwz      r0, 2716(r27);
/* 80A0AD78 C03B0A80 */  lfs      f1, 2688(r27);
/* 80A0AD7C 5400103A */  slwi     r0, r0, 2;
/* 80A0AD80 7C03042E */  lfsx     f0, r3, r0;
/* 80A0AD84 EC01002A */  fadds    f0, f1, f0;
/* 80A0AD88 D001000C */  stfs     f0, 12(r1);
/* 80A0AD8C 4082002C */  bne-     UNDEF_80a0adb8;
/* 80A0AD90 7F85E378 */  mr       r5, r28;
/* 80A0AD94 38610008 */  addi     r3, r1, 8;
/* 80A0AD98 38800010 */  li       r4, 16;
/* 80A0AD9C 38C00001 */  li       r6, 1;
/* 80A0ADA0 4B6A87A1 */  bl       UNDEF_800b3540;
/* 80A0ADA4 7F83E378 */  mr       r3, r28;
/* 80A0ADA8 38800001 */  li       r4, 1;
/* 80A0ADAC 38A00001 */  li       r5, 1;
/* 80A0ADB0 4B6556B1 */  bl       UNDEF_80060460;
/* 80A0ADB4 48000030 */  b        UNDEF_80a0ade4;
UNDEF_80a0adb8:;
/* 80A0ADB8 57DD13BA */  clrlslwi r29, r30, 16, 2;
/* 80A0ADBC 387F0110 */  addi     r3, r31, 272;
/* 80A0ADC0 7C83E82E */  lwzx     r4, r3, r29;
/* 80A0ADC4 7F85E378 */  mr       r5, r28;
/* 80A0ADC8 38610008 */  addi     r3, r1, 8;
/* 80A0ADCC 38C00001 */  li       r6, 1;
/* 80A0ADD0 4B6A8771 */  bl       UNDEF_800b3540;
/* 80A0ADD4 387F0130 */  addi     r3, r31, 304;
/* 80A0ADD8 7F84E378 */  mr       r4, r28;
/* 80A0ADDC 7C63E82E */  lwzx     r3, r3, r29;
/* 80A0ADE0 4B6558B1 */  bl       UNDEF_80060690;
UNDEF_80a0ade4:;
/* 80A0ADE4 807B0A9C */  lwz      r3, 2716(r27);
/* 80A0ADE8 38030001 */  addi     r0, r3, 1;
/* 80A0ADEC 901B0A9C */  stw      r0, 2716(r27);
UNDEF_80a0adf0:;
/* 80A0ADF0 39610030 */  addi     r11, r1, 48;
/* 80A0ADF4 7FC3F378 */  mr       r3, r30;
/* 80A0ADF8 4B8D22B5 */  bl       UNDEF_802dd0ac;
/* 80A0ADFC 80010034 */  lwz      r0, 52(r1);
/* 80A0AE00 7C0803A6 */  mtlr     r0;
/* 80A0AE04 38210030 */  addi     r1, r1, 48;
/* 80A0AE08 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80A0A9F0)]]
void UNDEF_80A0A9F0() ASM_METHOD(
  // clang-format off
/* 80A0A9F0 9421FFE0 */  stwu     r1, -32(r1);
/* 80A0A9F4 39400000 */  li       r10, 0;
/* 80A0A9F8 38000003 */  li       r0, 3;
/* 80A0A9FC 60000000 */  nop;
UNDEF_80a0aa00:;
/* 80A0AA00          */  addi     r8, r3, daEnGlpole_c_ADJUST_mPlayerPos;
/* 80A0AA04 7C0903A6 */  mtctr    r0;
UNDEF_80a0aa08:;
/* 80A0AA08 89280A44 */  lbz      r9, 2628(r8);
/* 80A0AA0C 7D240774 */  extsb    r4, r9;
/* 80A0AA10 2C04FFFF */  cmpwi    r4, -1;
/* 80A0AA14 41820080 */  beq-     UNDEF_80a0aa94;
/* 80A0AA18 88880A54 */  lbz      r4, 2644(r8);
/* 80A0AA1C 7C840774 */  extsb    r4, r4;
/* 80A0AA20 2C04FFFF */  cmpwi    r4, -1;
/* 80A0AA24 41820070 */  beq-     UNDEF_80a0aa94;
/* 80A0AA28 C0280A3C */  lfs      f1, 2620(r8);
/* 80A0AA2C C0080A4C */  lfs      f0, 2636(r8);
/* 80A0AA30 FC010040 */  fcmpo    cr0, f1, f0;
/* 80A0AA34 40810060 */  ble-     UNDEF_80a0aa94;
/* 80A0AA38 A0E80A38 */  lhz      r7, 2616(r8);
/* 80A0AA3C 88C80A45 */  lbz      r6, 2629(r8);
/* 80A0AA40 80A80A40 */  lwz      r5, 2624(r8);
/* 80A0AA44 A0880A48 */  lhz      r4, 2632(r8);
/* 80A0AA48 B0880A38 */  sth      r4, 2616(r8);
/* 80A0AA4C C0080A4C */  lfs      f0, 2636(r8);
/* 80A0AA50 D0080A3C */  stfs     f0, 2620(r8);
/* 80A0AA54 88880A54 */  lbz      r4, 2644(r8);
/* 80A0AA58 98880A44 */  stb      r4, 2628(r8);
/* 80A0AA5C 88880A55 */  lbz      r4, 2645(r8);
/* 80A0AA60 98880A45 */  stb      r4, 2629(r8);
/* 80A0AA64 80880A50 */  lwz      r4, 2640(r8);
/* 80A0AA68 90880A40 */  stw      r4, 2624(r8);
/* 80A0AA6C B0E80A48 */  sth      r7, 2632(r8);
/* 80A0AA70 D0280A4C */  stfs     f1, 2636(r8);
/* 80A0AA74 99280A54 */  stb      r9, 2644(r8);
/* 80A0AA78 98C80A55 */  stb      r6, 2645(r8);
/* 80A0AA7C B0E10008 */  sth      r7, 8(r1);
/* 80A0AA80 D021000C */  stfs     f1, 12(r1);
/* 80A0AA84 99210014 */  stb      r9, 20(r1);
/* 80A0AA88 98C10015 */  stb      r6, 21(r1);
/* 80A0AA8C 90A10010 */  stw      r5, 16(r1);
/* 80A0AA90 90A80A50 */  stw      r5, 2640(r8);
UNDEF_80a0aa94:;
/* 80A0AA94 39080010 */  addi     r8, r8, 16;
/* 80A0AA98 4200FF70 */  bdnz+    UNDEF_80a0aa08;
/* 80A0AA9C 394A0001 */  addi     r10, r10, 1;
/* 80A0AAA0          */  cmpwi    r10, PLAYER_COUNT;
/* 80A0AAA4 4180FF5C */  blt+     UNDEF_80a0aa00;
/* 80A0AAA8 3C8080AD */  lis      r4, UNDEF_80ad026c@ha;
/* 80A0AAAC 38000004 */  li       r0, 4;
/* 80A0AAB0 7C651B78 */  mr       r5, r3;
/* 80A0AAB4 C004026C */  lfs      f0, UNDEF_80ad026c@l(r4);
/* 80A0AAB8 38C00000 */  li       r6, 0;
/* 80A0AABC 7C0903A6 */  mtctr    r0;
UNDEF_80a0aac0:;
/* 80A0AAC0 C0250A3C */  lfs      f1, 0xA3C + daEnGlpole_c_ADJUST_mPlayerPos(r5);
/* 80A0AAC4 FC010000 */  fcmpu    cr0, f1, f0;
/* 80A0AAC8 41820028 */  beq-     UNDEF_80a0aaf0;
/* 80A0AACC 88050A45 */  lbz      r0, 0xA45 + daEnGlpole_c_ADJUST_mPlayerPos(r5);
/* 80A0AAD0 2C000000 */  cmpwi    r0, 0;
/* 80A0AAD4 4082001C */  bne-     UNDEF_80a0aaf0;
/* 80A0AAD8 54C02036 */  slwi     r0, r6, 4;
/* 80A0AADC 38A00001 */  li       r5, 1;
/* 80A0AAE0 7C830214 */  add      r4, r3, r0;
/* 80A0AAE4 7CC33378 */  mr       r3, r6;
/* 80A0AAE8 98A40A45 */  stb      r5, 0xA45 + daEnGlpole_c_ADJUST_mPlayerPos(r4);
/* 80A0AAEC 48000014 */  b        UNDEF_80a0ab00;
UNDEF_80a0aaf0:;
/* 80A0AAF0 38A50010 */  addi     r5, r5, 16;
/* 80A0AAF4 38C60001 */  addi     r6, r6, 1;
/* 80A0AAF8 4200FFC8 */  bdnz+    UNDEF_80a0aac0;
/* 80A0AAFC 38600000 */  li       r3, 0;
UNDEF_80a0ab00:;
/* 80A0AB00 38210020 */  addi     r1, r1, 32;
/* 80A0AB04 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x80A0B020)]]
bool daEnGlpole_c::isAllPlayerOnPole()
{
    return std::popcount(mPlrOnPoleFlag) == daPyMng_c::mNum;
}