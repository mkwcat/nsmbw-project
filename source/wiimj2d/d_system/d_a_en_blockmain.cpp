// d_a_en_block_main.cpp
// NSMBW .text: 0x800208B0 - 0x80023C60

#include "d_a_en_blockmain.h"

#include "d_player/d_a_yoshi.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_actorcreate_mng.h"
#include "d_system/d_yoshi_model.h"
#include "framework/f_feature.h"

[[nsmbw(0x80021AB0)]]
bool daEnBlockMain_c::isYossyColor(u16 yoshiColor)
{
    int index = 0;
    int checkColor = dYoshiMdl_c::s_yoshiColors[yoshiColor];
    daYoshi_c* yoshi;
    while (yoshi = daPyMng_c::getYoshi(index),
           yoshi == nullptr ||
             checkColor != static_cast<dYoshiMdl_c*>(yoshi->mModelMng.mModel)->mColor) {
        index++;
        if (index > dYoshiMdl_c::COLOR_COUNT) {
            return false;
        }
    }
    return true;
}

[[nsmbw(0x80021B30)]]
s16 daEnBlockMain_c::yossy_color_search()
{
    s16 yoshiColor;
    switch (fFeat::yoshi_color_mode) {
    default:
        yoshiColor = dActorCreateMng_c::m_instance->m0xBC8;

        for (int i = 0; i < dYoshiMdl_c::COLOR_COUNT; i++) {
            if (!isYossyColor(yoshiColor)) {
                dActorCreateMng_c::m_instance->m0xBC8 = yoshiColor;
                dActorCreateMng_c::m_instance->m0xBC8++;
                return dYoshiMdl_c::s_yoshiColors[yoshiColor];
            }
            yoshiColor++;
        }
        return -1;
    case fFeat::YOSHI_COLOR_MODE_e::ALL_GREEN:
        return 0;
    }
}

[[nsmbw(0x80022810)]]
void daEnBlockMain_c::FUN_80022810() ASM_METHOD(
  // clang-format off
/* 80022810 9421FFC0 */  stwu     r1, -64(r1);
/* 80022814 7C0802A6 */  mflr     r0;
/* 80022818 90010044 */  stw      r0, 68(r1);
/* 8002281C 39610040 */  addi     r11, r1, 64;
/* 80022820 482BA845 */  bl       UNDEF_802dd064;
/* 80022824 80030648 */  lwz      r0, 1608(r3);
/* 80022828 7C7B1B78 */  mr       r27, r3;
/* 8002282C 7C9C2378 */  mr       r28, r4;
/* 80022830 7CBD2B78 */  mr       r29, r5;
/* 80022834 2C000000 */  cmpwi    r0, 0;
/* 80022838 408202C0 */  bne-     UNDEF_80022af8;
/* 8002283C 88040014 */  lbz      r0, 20(r4);
/* 80022840 3BC00000 */  li       r30, 0;
/* 80022844 2C000000 */  cmpwi    r0, 0;
/* 80022848 4082001C */  bne-     UNDEF_80022864;
/* 8002284C 80A40010 */  lwz      r5, 16(r4);
/* 80022850 3C60802F */  lis      r3, UNDEF_802ee620@ha;
/* 80022854 3863E620 */  addi     r3, r3, UNDEF_802ee620@l;
/* 80022858 54A0103A */  slwi     r0, r5, 2;
/* 8002285C 7FE3002E */  lwzx     r31, r3, r0;
/* 80022860 4800001C */  b        UNDEF_8002287c;
UNDEF_80022864:;
/* 80022864 80A40010 */  lwz      r5, 16(r4);
/* 80022868 3C60802F */  lis      r3, UNDEF_802ee668@ha;
/* 8002286C 3863E668 */  addi     r3, r3, UNDEF_802ee668@l;
/* 80022870 3BC01000 */  li       r30, 4096;
/* 80022874 54A0103A */  slwi     r0, r5, 2;
/* 80022878 7FE3002E */  lwzx     r31, r3, r0;
UNDEF_8002287c:;
/* 8002287C 281F000F */  cmplwi   r31, 15;
/* 80022880 41820278 */  beq-     UNDEF_80022af8;
/* 80022884 281F0006 */  cmplwi   r31, 6;
/* 80022888 40820008 */  bne-     UNDEF_80022890;
/* 8002288C 4800026C */  b        UNDEF_80022af8;
UNDEF_80022890:;
/* 80022890 2C05000E */  cmpwi    r5, 14;
/* 80022894 40820058 */  bne-     UNDEF_800228ec;
/* 80022898 8804000C */  lbz      r0, 12(r4);
/* 8002289C 7C000774 */  extsb    r0, r0;
/* 800228A0 2C00FFFF */  cmpwi    r0, -1;
/* 800228A4 41820254 */  beq-     UNDEF_80022af8;
/* 800228A8 7F63DB78 */  mr       r3, r27;
/* 800228AC 4BFFFAE5 */  bl       UNDEF_80022390;
/* 800228B0 2C030000 */  cmpwi    r3, 0;
/* 800228B4 40820030 */  bne-     UNDEF_800228e4;
/* 800228B8 2C1D0000 */  cmpwi    r29, 0;
/* 800228BC 40820030 */  bne-     UNDEF_800228ec;
/* 800228C0 881C000C */  lbz      r0, 12(r28);
/* 800228C4 7F63DB78 */  mr       r3, r27;
/* 800228C8 7C040774 */  extsb    r4, r0;
/* 800228CC 4BFFF8B5 */  bl       UNDEF_80022180;
/* 800228D0 2C030000 */  cmpwi    r3, 0;
/* 800228D4 41820224 */  beq-     UNDEF_80022af8;
/* 800228D8 3BE00002 */  li       r31, 2;
/* 800228DC 48000010 */  b        UNDEF_800228ec;
/* 800228E0 48000218 */  b        UNDEF_80022af8;
UNDEF_800228e4:;
/* 800228E4 2C1D0000 */  cmpwi    r29, 0;
/* 800228E8 41820210 */  beq-     UNDEF_80022af8;
UNDEF_800228ec:;
/* 800228EC 281F000C */  cmplwi   r31, 12;
/* 800228F0 889C0015 */  lbz      r4, 21(r28);
/* 800228F4 4082001C */  bne-     UNDEF_80022910;
/* 800228F8 7F63DB78 */  mr       r3, r27;
/* 800228FC 38800000 */  li       r4, 0;
/* 80022900 4BFFFAC1 */  bl       UNDEF_800223c0;
/* 80022904 38000001 */  li       r0, 1;
/* 80022908 901B0648 */  stw      r0, 1608(r27);
/* 8002290C 480001EC */  b        UNDEF_80022af8;
UNDEF_80022910:;
/* 80022910 281F000D */  cmplwi   r31, 13;
/* 80022914 40820018 */  bne-     UNDEF_8002292c;
/* 80022918 7F63DB78 */  mr       r3, r27;
/* 8002291C 4BFFEED5 */  bl       UNDEF_800217f0;
/* 80022920 38000001 */  li       r0, 1;
/* 80022924 901B0648 */  stw      r0, 1608(r27);
/* 80022928 480001D0 */  b        UNDEF_80022af8;
UNDEF_8002292c:;
/* 8002292C 281F0005 */  cmplwi   r31, 5;
/* 80022930 4082009C */  bne-     UNDEF_800229cc;
/* 80022934 C01B00B4 */  lfs      f0, 180(r27);
/* 80022938 C03B00B0 */  lfs      f1, 176(r27);
/* 8002293C C05B00AC */  lfs      f2, 172(r27);
/* 80022940 D041001C */  stfs     f2, 28(r1);
/* 80022944 D0210020 */  stfs     f1, 32(r1);
/* 80022948 D0010024 */  stfs     f0, 36(r1);
/* 8002294C 881B068D */  lbz      r0, 1677(r27);
/* 80022950 28000002 */  cmplwi   r0, 2;
/* 80022954 4082004C */  bne-     UNDEF_800229a0;
/* 80022958 C0028264 */  lfs      f0, -32156(r2);
/* 8002295C 3881001C */  addi     r4, r1, 28;
/* 80022960 806DA6A0 */  lwz      r3, UNDEF_8042a020@sda21;
/* 80022964 38A00005 */  li       r5, 5;
/* 80022968 EC01002A */  fadds    f0, f1, f0;
/* 8002296C 38C00000 */  li       r6, 0;
/* 80022970 D0010020 */  stfs     f0, 32(r1);
/* 80022974 48043DCD */  bl       UNDEF_80066740;
/* 80022978 83ADA6C0 */  lwz      r29, UNDEF_8042a040@sda21;
/* 8002297C 7F84E378 */  mr       r4, r28;
/* 80022980 38610008 */  addi     r3, r1, 8;
/* 80022984 48047B2D */  bl       UNDEF_8006a4b0;
/* 80022988 7FA3EB78 */  mr       r3, r29;
/* 8002298C 38A10008 */  addi     r5, r1, 8;
/* 80022990 38800238 */  li       r4, 568;
/* 80022994 38C00000 */  li       r6, 0;
/* 80022998 481763D9 */  bl       UNDEF_80198d70;
/* 8002299C 48000024 */  b        UNDEF_800229c0;
UNDEF_800229a0:;
/* 800229A0 C0028270 */  lfs      f0, -32144(r2);
/* 800229A4 3881001C */  addi     r4, r1, 28;
/* 800229A8 806DA6A0 */  lwz      r3, UNDEF_8042a020@sda21;
/* 800229AC 38A00005 */  li       r5, 5;
/* 800229B0 EC010028 */  fsubs    f0, f1, f0;
/* 800229B4 38C00000 */  li       r6, 0;
/* 800229B8 D0010020 */  stfs     f0, 32(r1);
/* 800229BC 48043DF5 */  bl       UNDEF_800667b0;
UNDEF_800229c0:;
/* 800229C0 38000001 */  li       r0, 1;
/* 800229C4 901B0648 */  stw      r0, 1608(r27);
/* 800229C8 48000130 */  b        UNDEF_80022af8;
UNDEF_800229cc:;
/* 800229CC 281F000A */  cmplwi   r31, 10;
/* 800229D0 40820020 */  bne-     UNDEF_800229f0;
/* 800229D4 88BB068D */  lbz      r5, 1677(r27);
/* 800229D8 7F63DB78 */  mr       r3, r27;
/* 800229DC 38800001 */  li       r4, 1;
/* 800229E0 4BFFF041 */  bl       UNDEF_80021a20;
/* 800229E4 38000001 */  li       r0, 1;
/* 800229E8 901B0648 */  stw      r0, 1608(r27);
/* 800229EC 4800010C */  b        UNDEF_80022af8;
UNDEF_800229f0:;
/* 800229F0 281F0002 */  cmplwi   r31, 2;
/* 800229F4 4182000C */  beq-     UNDEF_80022a00;
/* 800229F8 281F0004 */  cmplwi   r31, 4;
/* 800229FC 40820008 */  bne-     UNDEF_80022a04;
UNDEF_80022a00:;
/* 80022A00 38800000 */  li       r4, 0;
UNDEF_80022a04:;
/* 80022A04 C03C0004 */  lfs      f1, 4(r28);
/* 80022A08 C05C0000 */  lfs      f2, 0(r28);
/* 80022A0C C0028214 */  lfs      f0, -32236(r2);
/* 80022A10 D0410010 */  stfs     f2, 16(r1);
/* 80022A14 D0210014 */  stfs     f1, 20(r1);
/* 80022A18 D0010018 */  stfs     f0, 24(r1);
/* 80022A1C 801B0690 */  lwz      r0, 1680(r27);
/* 80022A20 2C000002 */  cmpwi    r0, 2;
/* 80022A24 41820010 */  beq-     UNDEF_80022a34;
/* 80022A28 881B038F */  lbz      r0, 911(r27);
/* 80022A2C 2C000000 */  cmpwi    r0, 0;
/* 80022A30 4182000C */  beq-     UNDEF_80022a3c;
UNDEF_80022a34:;
/* 80022A34 C0028274 */  lfs      f0, -32140(r2);
/* 80022A38 D0010018 */  stfs     f0, 24(r1);
UNDEF_80022a3c:;
/* 80022A3C 8BBC000C */  lbz      r29, 12(r28);
/* 80022A40 7FA30774 */  extsb    r3, r29;
/* 80022A44 2C03FFFF */  cmpwi    r3, -1;
/* 80022A48 418200B0 */  beq-     UNDEF_80022af8;
/* 80022A4C 2C040000 */  cmpwi    r4, 0;
/* 80022A50 40820038 */  bne-     UNDEF_80022a88;
/* 80022A54 88BC0016 */  lbz      r5, 22(r28);
/* 80022A58 7FE0F378 */  or       r0, r31, r30;
/* 80022A5C 889B068D */  lbz      r4, 1677(r27);
/* 80022A60 5463801E */  slwi     r3, r3, 16;
/* 80022A64          */  oris     r0, r0, 0x4000;
/* 80022A68 2C050000 */  cmpwi    r5, 0;
                         // Proper direction bitfield
/* 80022A6C          */  slwi     r4, r4, 29;
/* 80022A70 7C600378 */  or       r0, r3, r0;
/* 80022A74 7C830378 */  or       r3, r4, r0;
/* 80022A78 41820020 */  beq-     UNDEF_80022a98;
/* 80022A7C 54A0A116 */  clrlslwi r0, r5, 24, 20;
/* 80022A80 7C630378 */  or       r3, r3, r0;
/* 80022A84 48000014 */  b        UNDEF_80022a98;
UNDEF_80022a88:;
/* 80022A88 7FE0F378 */  or       r0, r31, r30;
/* 80022A8C 5463801E */  slwi     r3, r3, 16;
/* 80022A90 64000A00 */  oris     r0, r0, 2560;
/* 80022A94 7C630378 */  or       r3, r3, r0;
UNDEF_80022a98:;
/* 80022A98 88FB038F */  lbz      r7, 911(r27);
/* 80022A9C 60640800 */  ori      r4, r3, 2048;
/* 80022AA0 38A10010 */  addi     r5, r1, 16;
/* 80022AA4 3860003C */  li       r3, 60;
/* 80022AA8 38C00000 */  li       r6, 0;
/* 80022AAC 48041B65 */  bl       construct__8dActor_cFUsUlPC7mVec3_cPC7mAng3_cUc;
/* 80022AB0 2C030000 */  cmpwi    r3, 0;
/* 80022AB4 41820018 */  beq-     UNDEF_80022acc;
/* 80022AB8 881C0016 */  lbz      r0, 22(r28);
/* 80022ABC 2C000000 */  cmpwi    r0, 0;
/* 80022AC0 4182000C */  beq-     UNDEF_80022acc;
/* 80022AC4 801B0000 */  lwz      r0, 0(r27);
/* 80022AC8 90030BD0 */  stw      r0, 3024(r3);
UNDEF_80022acc:;
/* 80022ACC 7F63DB78 */  mr       r3, r27;
/* 80022AD0 7FE5FB78 */  mr       r5, r31;
/* 80022AD4 38810010 */  addi     r4, r1, 16;
/* 80022AD8 7FA60774 */  extsb    r6, r29;
/* 80022ADC 38E00000 */  li       r7, 0;
/* 80022AE0 39000000 */  li       r8, 0;
/* 80022AE4 4BFFF9AD */  bl       UNDEF_80022490;
/* 80022AE8 281F0004 */  cmplwi   r31, 4;
/* 80022AEC 4182000C */  beq-     UNDEF_80022af8;
/* 80022AF0 38000001 */  li       r0, 1;
/* 80022AF4 901B0648 */  stw      r0, 1608(r27);
UNDEF_80022af8:;
/* 80022AF8 39610040 */  addi     r11, r1, 64;
/* 80022AFC 482BA5B5 */  bl       UNDEF_802dd0b0;
/* 80022B00 80010044 */  lwz      r0, 68(r1);
/* 80022B04 7C0803A6 */  mtlr     r0;
/* 80022B08 38210040 */  addi     r1, r1, 64;
/* 80022B0C 4E800020 */  blr;
  // clang-format on
);