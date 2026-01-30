// d_a_player_demo_manager.cpp
// NSMBW .text: 0x8005B3A0 - 0x8005D7E0

#include "d_a_player_demo_manager.h"

#include "d_player/d_a_player.h"
#include "d_system/d_a_player_manager.h"
#include "d_system/d_game_common.h"
#include "d_system/d_mj2d_game.h"
#include <revolution/os.h>
#include <revolution/os/OSError.h>

[[nsmbw(0x80429F74)]]
daPyDemoMng_c* daPyDemoMng_c::mspInstance;

[[nsmbw(0x8005B3A0)]]
daPyDemoMng_c::daPyDemoMng_c();

/* VT+0x8 */
[[nsmbw(0x8005B3E0)]]
daPyDemoMng_c::~daPyDemoMng_c();

[[nsmbw(0x8005B430)]]
void daPyDemoMng_c::initStage();

EXTERN_REPL(
  0x8005B4A0, //
  void daPyDemoMng_c::baseInit()
);

[[nsmbw(0x8005B4A0)]]
void daPyDemoMng_c::init()
{
    baseInit();

    for (int i = 4; i < PLAYER_COUNT; i++) {
        mExPlayerIDs[i - 4] = -1;
        mExCourseOutList[i - 4] = -1;
    }
}

[[nsmbw(0x8005B550)]]
void daPyDemoMng_c::update();

[[nsmbw(0x8005B5C0)]]
void daPyDemoMng_c::setDemoMode(Mode_e mode, int state);

[[nsmbw(0x8005B6A0)]]
void daPyDemoMng_c::calcNotGoalPlayer() ASM_METHOD(
  // clang-format off
/* 8005B6A0 9421FFF0 */  stwu     r1, -16(r1);
/* 8005B6A4 7C0802A6 */  mflr     r0;
/* 8005B6A8 90010014 */  stw      r0, 20(r1);
/* 8005B6AC 93E1000C */  stw      r31, 12(r1);
/* 8005B6B0 93C10008 */  stw      r30, 8(r1);
/* 8005B6B4 8003003C */  lwz      r0, 60(r3);
/* 8005B6B8 2C000000 */  cmpwi    r0, 0;
/* 8005B6BC 418200A4 */  beq-     UNDEF_8005b760;
/* 8005B6C0 3400FFFF */  subic.   r0, r0, 1;
/* 8005B6C4 9003003C */  stw      r0, 60(r3);
/* 8005B6C8 40820098 */  bne-     UNDEF_8005b760;
/* 8005B6CC 880DA658 */  lbz      r0, UNDEF_80429fd8@sda21;
/* 8005B6D0 3BE00000 */  li       r31, 0;
/* 8005B6D4 54000636 */  rlwinm   r0, r0, 0, 24, 27;
/* 8005B6D8 980DA658 */  stb      r0, UNDEF_80429fd8@sda21;
UNDEF_8005b6dc:;
/* 8005B6DC 7FE3FB78 */  mr       r3, r31;
/* 8005B6E0 480044B1 */  bl       UNDEF_8005fb90;
/* 8005B6E4 2C030000 */  cmpwi    r3, 0;
UNDEF_8005b6e8:;
/* 8005B6E8 41820014 */  beq-     UNDEF_8005b6fc;
/* 8005B6EC 81830060 */  lwz      r12, 96(r3);
/* 8005B6F0 818C012C */  lwz      r12, 300(r12);
/* 8005B6F4 7D8903A6 */  mtctr    r12;
/* 8005B6F8 4E800421 */  bctrl;
UNDEF_8005b6fc:;
/* 8005B6FC 3BFF0001 */  addi     r31, r31, 1;
/* 8005B700 2C1F0004 */  cmpwi    r31, PLAYER_COUNT;
/* 8005B704 4180FFD8 */  blt+     UNDEF_8005b6dc;
/* 8005B708 3BC00000 */  li       r30, 0;
UNDEF_8005b70c:;
/* 8005B70C 7FC3F378 */  mr       r3, r30;
/* 8005B710 48004461 */  bl       UNDEF_8005fb70;
/* 8005B714 2C030000 */  cmpwi    r3, 0;
/* 8005B718 7C7F1B78 */  mr       r31, r3;
/* 8005B71C 41820038 */  beq-     UNDEF_8005b754;
/* 8005B720 81830060 */  lwz      r12, 96(r3);
/* 8005B724 818C006C */  lwz      r12, 108(r12);
/* 8005B728 7D8903A6 */  mtctr    r12;
/* 8005B72C 4E800421 */  bctrl;
/* 8005B730 88030000 */  lbz      r0, 0(r3);
/* 8005B734 7C000774 */  extsb    r0, r0;
/* 8005B738 2C00FFFF */  cmpwi    r0, -1;
/* 8005B73C 40820018 */  bne-     UNDEF_8005b754;
/* 8005B740 819F0060 */  lwz      r12, 96(r31);
/* 8005B744 7FE3FB78 */  mr       r3, r31;
/* 8005B748 818C012C */  lwz      r12, 300(r12);
/* 8005B74C 7D8903A6 */  mtctr    r12;
/* 8005B750 4E800421 */  bctrl;
UNDEF_8005b754:;
/* 8005B754 3BDE0001 */  addi     r30, r30, 1;
/* 8005B758 2C1E0004 */  cmpwi    r30, PLAYER_COUNT;
/* 8005B75C 4180FFB0 */  blt+     UNDEF_8005b70c;
UNDEF_8005b760:;
/* 8005B760 80010014 */  lwz      r0, 20(r1);
/* 8005B764 83E1000C */  lwz      r31, 12(r1);
/* 8005B768 83C10008 */  lwz      r30, 8(r1);
/* 8005B76C 7C0803A6 */  mtlr     r0;
/* 8005B770 38210010 */  addi     r1, r1, 16;
/* 8005B774 4E800020 */  blr;
  // clang-format on
);

[[gnu::const]] [[gnu::used]]
static int get_index_daPyDemoMng_c(int index)
{
    if (index < 4) {
        return index;
    }

    return (index - 4) +
           (offsetof(daPyDemoMng_c, mExPlayerIDs) - offsetof(daPyDemoMng_c, mPlayerIDs)) /
             sizeof(int);
}

[[gnu::const]] [[gnu::used]]
static int get_index_daPyDemoMng_c_mCourseInList(int index)
{
    if (index < 4) {
        return index;
    }

    return (index - 4) +
           (offsetof(daPyDemoMng_c, mExCourseInList) - offsetof(daPyDemoMng_c, mCourseInList)) /
             sizeof(int);
}

[[gnu::const]] [[gnu::used]]
static int get_index_daPyDemoMng_c_mCourseOutList(int index)
{
    if (index < 4) {
        return index;
    }

    return (index - 4) +
           (offsetof(daPyDemoMng_c, mExCourseOutList) - offsetof(daPyDemoMng_c, mCourseOutList)) /
             sizeof(int);
}

#define convIdx get_index_daPyDemoMng_c
#define convIdx60 get_index_daPyDemoMng_c_mCourseInList
#define convIdx70 get_index_daPyDemoMng_c_mCourseOutList

[[nsmbw(0x8005B780)]]
int daPyDemoMng_c::setGoalDemoList(int param)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerIDs[convIdx(i)] == -1) {
            mPlayerIDs[convIdx(i)] = param;
            return i;
        }
    }

    return -1;
}

[[nsmbw(0x8005B840)]]
int daPyDemoMng_c::getPoleBelowPlayer(int param)
{
    for (int i = 0; i < mPlayerCount; i++) {
        if (mPlayerIDs[convIdx(i)] == param && i > 0) {
            return mPlayerIDs[convIdx(i - 1)];
        }
    }

    return -1;
}

#define STACK_PLAYER_ARRAY 0x10
#define STACK_PLAYER_ARRAY2 (0x10 + PLAYER_COUNT * 4)
#define STACK_SIZE (STACK_PLAYER_ARRAY2 + PLAYER_COUNT * 4 + 0x50)

[[nsmbw(0x8005B8A0)]]
void daPyDemoMng_c::executeGoalDemo_Pole() ASM_METHOD(
  // clang-format off
/* 8005B8A0 9421FF80 */  stwu     r1, -STACK_SIZE(r1);
/* 8005B8A4 7C0802A6 */  mflr     r0;
/* 8005B8A8 90010084 */  stw      r0, STACK_SIZE+0x4(r1);
/* 8005B8AC 39610060 */  addi     r11, r1, STACK_SIZE-0x20;
/* 8005B8B0 DBE10070 */  stfd     f31, STACK_SIZE-0x10(r1);
/* 8005B8B4 F3E10078 */  .long    0xF3E10000 | (STACK_SIZE-0x8); // psq_st   f31, 120(r1), 0, 0;
/* 8005B8B8 DBC10060 */  stfd     f30, STACK_SIZE-0x20(r1);
/* 8005B8BC F3C10068 */  .long    0xF3C10000 | (STACK_SIZE-0x18); // psq_st   f30, 104(r1), 0, 0;
/* 8005B8C0 48281795 */  bl       UNDEF_802dd054;

/* 8005B8CC 7C7A1B78 */  mr       r26, r3;

                         // Set STACK_PLAYER_ARRAY2 to -1
                         li       r0, PLAYER_COUNT;
                         mtctr    r0;
                         li       r5, -1;
                         mr       r9, r1;
L_ClearStackPlayerArray2_LoopStart:;
                         stw      r5, STACK_PLAYER_ARRAY2(r9);
                         addi     r9, r9, 0x4;
                         bdnz+    L_ClearStackPlayerArray2_LoopStart;

/* 8005B8D8 3B010020 */  addi     r24, r1, STACK_PLAYER_ARRAY2;
/* 8005B8E0 3BC00000 */  li       r30, 0;
/* 8005B8E8 3B200001 */  li       r25, 1;

UNDEF_8005b8f8:;
/* 8005B8F8 57C0063E */  clrlwi   r0, r30, 24;
/* 8005B8FC 886DA608 */  lbz      r3, UNDEF_80429f88@sda21;
/* 8005B900 7F200030 */  slw      r0, r25, r0;
/* 8005B904 7C600039 */  and.     r0, r3, r0;
/* 8005B908 4182007C */  beq-     UNDEF_8005b984;
/* 8005B90C 7FC3F378 */  mr       r3, r30;
/* 8005B910 48004281 */  bl       getCtrlPlayer__9daPyMng_cFi;
/* 8005B914 2C030000 */  cmpwi    r3, 0;
/* 8005B918 7C771B78 */  mr       r23, r3;
/* 8005B91C 41820068 */  beq-     UNDEF_8005b984;
/* 8005B920 801A0010 */  lwz      r0, 16(r26);
/* 8005B924 5400077B */  rlwinm.  r0, r0, 0, 29, 29;
/* 8005B928 4182002C */  beq-     UNDEF_8005b954;
/* 8005B92C 38800065 */  li       r4, 101;
/* 8005B930 4BFFB3C1 */  bl       isStatus__10daPlBase_cFi;
/* 8005B934 2C030000 */  cmpwi    r3, 0;
/* 8005B938 4182002C */  beq-     UNDEF_8005b964;
/* 8005B93C 7EE3BB78 */  mr       r3, r23;
/* 8005B940 38800066 */  li       r4, 102;
/* 8005B944 4BFFB3AD */  bl       isStatus__10daPlBase_cFi;
/* 8005B948 2C030000 */  cmpwi    r3, 0;
/* 8005B94C 40820018 */  bne-     UNDEF_8005b964;
/* 8005B950 48000374 */  b        UNDEF_8005bcc4;
UNDEF_8005b954:;
/* 8005B954 38800066 */  li       r4, 102;
/* 8005B958 4BFFB399 */  bl       isStatus__10daPlBase_cFi;
/* 8005B95C 2C030000 */  cmpwi    r3, 0;
/* 8005B960 41820364 */  beq-     UNDEF_8005bcc4;
UNDEF_8005b964:;
/* 8005B964 7EE3BB78 */  mr       r3, r23;
/* 8005B968 38800066 */  li       r4, 102;
/* 8005B96C 4BFFB385 */  bl       isStatus__10daPlBase_cFi;
/* 8005B970 2C030000 */  cmpwi    r3, 0;
/* 8005B974 41820010 */  beq-     UNDEF_8005b984;
/* 8005B978 80170430 */  lwz      r0, 1072(r23);
/* 8005B97C 5400103A */  slwi     r0, r0, 2;
/* 8005B980 7FD8012E */  stwx     r30, r24, r0;
UNDEF_8005b984:;
/* 8005B984 3BDE0001 */  addi     r30, r30, 1;
/* 8005B988          */  cmpwi    r30, PLAYER_COUNT;
/* 8005B98C 4180FF6C */  blt+     UNDEF_8005b8f8;

                         // Set STACK_PLAYER_ARRAY to -1
                         li       r0, PLAYER_COUNT;
                         mtctr    r0;
                         li       r5, -1;
                         mr       r9, r1;
L_ClearStackPlayerArray_LoopStart:;
                         stw      r5, STACK_PLAYER_ARRAY(r9);
                         addi     r9, r9, 0x4;
                         bdnz+    L_ClearStackPlayerArray_LoopStart;

/* 8005B99C 3BC10020 */  addi     r30, r1, STACK_PLAYER_ARRAY2;
/* 8005B9A4 3B210010 */  addi     r25, r1, STACK_PLAYER_ARRAY;
/* 8005B9AC 3B800000 */  li       r28, 0;
/* 8005B9B4 3FE08000 */  lis      r31, UNDEF_80000001@ha;
UNDEF_8005b9c4:;
/* 8005B9C4 83BE0000 */  lwz      r29, 0(r30);
/* 8005B9C8 2C1DFFFF */  cmpwi    r29, -1;
/* 8005B9CC 418201A0 */  beq-     UNDEF_8005bb6c;
/* 8005B9D0 7FA3EB78 */  mr       r3, r29;
/* 8005B9D4 480041BD */  bl       getCtrlPlayer__9daPyMng_cFi;
/* 8005B9D8 2C030000 */  cmpwi    r3, 0;
/* 8005B9DC 7C781B78 */  mr       r24, r3;
/* 8005B9E0 4182018C */  beq-     UNDEF_8005bb6c;
/* 8005B9E4 80010010 */  lwz      r0, STACK_PLAYER_ARRAY(r1);
/* 8005B9E8 2C00FFFF */  cmpwi    r0, -1;
/* 8005B9EC 4082000C */  bne-     UNDEF_8005b9f8;
/* 8005B9F0 93A10010 */  stw      r29, STACK_PLAYER_ARRAY(r1);
/* 8005B9F4 48000178 */  b        UNDEF_8005bb6c;
UNDEF_8005b9f8:;
/* 8005B9F8 3AE10010 */  addi     r23, r1, STACK_PLAYER_ARRAY;
/* 8005B9FC 3B600000 */  li       r27, 0;
UNDEF_8005ba00:;
/* 8005BA00 80770000 */  lwz      r3, 0(r23);
/* 8005BA04 2C03FFFF */  cmpwi    r3, -1;
/* 8005BA08 40820010 */  bne-     UNDEF_8005ba18;
/* 8005BA0C 5760103A */  slwi     r0, r27, 2;
/* 8005BA10 7FB9012E */  stwx     r29, r25, r0;
/* 8005BA14 48000158 */  b        UNDEF_8005bb6c;
UNDEF_8005ba18:;
/* 8005BA18 48004179 */  bl       UNDEF_8005fb90;
/* 8005BA1C C03800B0 */  lfs      f1, 176(r24);
/* 8005BA20 C00300B0 */  lfs      f0, 176(r3);
/* 8005BA24 FC010040 */  fcmpo    cr0, f1, f0;
/* 8005BA28 4C401382 */  cror     2, 0, 2;
/* 8005BA2C 40820130 */  bne-     UNDEF_8005bb5c;
/* 8005BA30 2C9B0003 */  cmpwi    cr1, r27, PLAYER_COUNT - 1;
/* 8005BA34 38600003 */  li       r3, PLAYER_COUNT - 1;
/* 8005BA38 40840118 */  bge-     cr1, UNDEF_8005bb50;
/* 8005BA3C 211B0003 */  subfic   r8, r27, PLAYER_COUNT - 1;
/* 8005BA40 389B0008 */  addi     r4, r27, 8;
/* 8005BA44 2C080008 */  cmpwi    r8, 8;
/* 8005BA48 408100D8 */  ble-     UNDEF_8005bb20;
/* 8005BA4C 38A00000 */  li       r5, 0;
/* 8005BA50 38C00000 */  li       r6, 0;
/* 8005BA54 38E00000 */  li       r7, 0;
/* 8005BA58 41850014 */  bgt-     cr1, UNDEF_8005ba6c;
/* 8005BA5C 381F0001 */  addi     r0, r31, UNDEF_80000001@l;
UNDEF_8005ba60:;
/* 8005BA60 7C1B0000 */  cmpw     r27, r0;
/* 8005BA64 41800008 */  blt-     UNDEF_8005ba6c;
/* 8005BA68 38E00001 */  li       r7, 1;
UNDEF_8005ba6c:;
/* 8005BA6C 2C070000 */  cmpwi    r7, 0;
UNDEF_8005ba70:;
/* 8005BA70 41820014 */  beq-     UNDEF_8005ba84;
/* 8005BA74 3C1B8000 */  addis    r0, r27, 0x8000;
/* 8005BA78 28000000 */  cmplwi   r0, 0;
/* 8005BA7C 41820008 */  beq-     UNDEF_8005ba84;
/* 8005BA80 38C00001 */  li       r6, 1;
UNDEF_8005ba84:;
/* 8005BA84 2C060000 */  cmpwi    r6, 0;
/* 8005BA88 4182002C */  beq-     UNDEF_8005bab4;
/* 8005BA8C 7C1B00D0 */  neg      r0, r27;
/* 8005BA90 38C00001 */  li       r6, 1;
/* 8005BA94 54000001 */  clrrwi.  r0, r0, 31;
/* 8005BA98 40820010 */  bne-     UNDEF_8005baa8;
/* 8005BA9C 55000001 */  clrrwi.  r0, r8, 31;
/* 8005BAA0 41820008 */  beq-     UNDEF_8005baa8;
/* 8005BAA4 38C00000 */  li       r6, 0;
UNDEF_8005baa8:;
/* 8005BAA8 2C060000 */  cmpwi    r6, 0;
/* 8005BAAC 41820008 */  beq-     UNDEF_8005bab4;
/* 8005BAB0 38A00001 */  li       r5, 1;
UNDEF_8005bab4:;
/* 8005BAB4 2C050000 */  cmpwi    r5, 0;
/* 8005BAB8 41820068 */  beq-     UNDEF_8005bb20;
/* 8005BABC 2004000A */  subfic   r0, r4, 10;
/* 8005BAC0 38A1001C */  addi     r5, r1, STACK_PLAYER_ARRAY + ((PLAYER_COUNT - 1) * 4);
/* 8005BAC4 5400E8FE */  srwi     r0, r0, 3;
/* 8005BAC8 7C0903A6 */  mtctr    r0;
/* 8005BACC 2C040003 */  cmpwi    r4, 3;
/* 8005BAD0 40800050 */  bge-     UNDEF_8005bb20;
UNDEF_8005bad4:;
/* 8005BAD4 8005FFFC */  lwz      r0, -4(r5);
/* 8005BAD8 3863FFF8 */  subi     r3, r3, 8;
/* 8005BADC 90050000 */  stw      r0, 0(r5);
/* 8005BAE0 8005FFF8 */  lwz      r0, -8(r5);
/* 8005BAE4 9005FFFC */  stw      r0, -4(r5);
/* 8005BAE8 8005FFF4 */  lwz      r0, -12(r5);
/* 8005BAEC 9005FFF8 */  stw      r0, -8(r5);
/* 8005BAF0 8005FFF0 */  lwz      r0, -16(r5);
/* 8005BAF4 9005FFF4 */  stw      r0, -12(r5);
/* 8005BAF8 8005FFEC */  lwz      r0, -20(r5);
/* 8005BAFC 9005FFF0 */  stw      r0, -16(r5);
/* 8005BB00 8005FFE8 */  lwz      r0, -24(r5);
/* 8005BB04 9005FFEC */  stw      r0, -20(r5);
/* 8005BB08 8005FFE4 */  lwz      r0, -28(r5);
/* 8005BB0C 9005FFE8 */  stw      r0, -24(r5);
/* 8005BB10 8005FFE0 */  lwz      r0, -32(r5);
/* 8005BB14 9005FFE4 */  stw      r0, -28(r5);
/* 8005BB18 38A5FFE0 */  subi     r5, r5, 32;
/* 8005BB1C 4200FFB8 */  bdnz+    UNDEF_8005bad4;
UNDEF_8005bb20:;
/* 8005BB20 5464103A */  slwi     r4, r3, 2;
/* 8005BB24 38A10010 */  addi     r5, r1, STACK_PLAYER_ARRAY;
/* 8005BB28 7C1B1850 */  sub      r0, r3, r27;
/* 8005BB2C 7CA52214 */  add      r5, r5, r4;
/* 8005BB30 7C0903A6 */  mtctr    r0;
/* 8005BB34 7C03D800 */  cmpw     r3, r27;
/* 8005BB38 40810018 */  ble-     UNDEF_8005bb50;
UNDEF_8005bb3c:;
/* 8005BB3C 8005FFFC */  lwz      r0, -4(r5);
/* 8005BB40 3863FFFF */  subi     r3, r3, 1;
/* 8005BB44 90050000 */  stw      r0, 0(r5);
/* 8005BB48 38A5FFFC */  subi     r5, r5, 4;
/* 8005BB4C 4200FFF0 */  bdnz+    UNDEF_8005bb3c;
UNDEF_8005bb50:;
/* 8005BB50 5760103A */  slwi     r0, r27, 2;
/* 8005BB54 7FB9012E */  stwx     r29, r25, r0;
/* 8005BB58 48000014 */  b        UNDEF_8005bb6c;
UNDEF_8005bb5c:;
/* 8005BB5C 3B7B0001 */  addi     r27, r27, 1;
/* 8005BB60 3AF70004 */  addi     r23, r23, 4;
/* 8005BB64 2C1B0004 */  cmpwi    r27, PLAYER_COUNT;
/* 8005BB68 4180FE98 */  blt+     UNDEF_8005ba00;
UNDEF_8005bb6c:;
/* 8005BB6C 3B9C0001 */  addi     r28, r28, 1;
/* 8005BB70 3BDE0004 */  addi     r30, r30, 4;
/* 8005BB74          */  cmpwi    r28, PLAYER_COUNT;
/* 8005BB78 4180FE4C */  blt+     UNDEF_8005b9c4;
/* 8005BB7C 80610010 */  lwz      r3, STACK_PLAYER_ARRAY(r1);
/* 8005BB80 38000000 */  li       r0, 0;
/* 8005BB84 901A001C */  stw      r0, STACK_PLAYER_ARRAY + ((PLAYER_COUNT - 1) * 4)(r26);
/* 8005BB88 C0028998 */  lfs      f0, UNDEF_8042bcf8@sda21;
/* 8005BB8C 2C03FFFF */  cmpwi    r3, -1;
/* 8005BB90 D0010008 */  stfs     f0, 8(r1);
/* 8005BB94 418200FC */  beq-     UNDEF_8005bc90;
/* 8005BB98 48003FF9 */  bl       getCtrlPlayer__9daPyMng_cFi;
/* 8005BB9C 2C030000 */  cmpwi    r3, 0;
/* 8005BBA0 7C771B78 */  mr       r23, r3;
/* 8005BBA4 41820064 */  beq-     UNDEF_8005bc08;
/* 8005BBA8 4BFF5549 */  bl       UNDEF_800510f0; // stopGoalOther__10daPlBase_cFv
/* 8005BBAC 88B7038F */  lbz      r5, 911(r23);
/* 8005BBB0 387700AC */  addi     r3, r23, 172;
/* 8005BBB4 38810008 */  addi     r4, r1, 8;
/* 8005BBB8 38C00001 */  li       r6, 1;
/* 8005BBBC 38E0FFFF */  li       r7, -1;
/* 8005BBC0 48019BF1 */  bl       UNDEF_800757b0; // checkGround__5dBc_cFPC7mVec3_cPfUcUcSc
/* 8005BBC4 8817038C */  lbz      r0, 908(r23);
/* 8005BBC8 28000002 */  cmplwi   r0, 2;
/* 8005BBCC 40820018 */  bne-     UNDEF_8005bbe4;
/* 8005BBD0 C0210008 */  lfs      f1, 8(r1);
/* 8005BBD4 C002899C */  lfs      f0, UNDEF_8042bcfc@sda21;
/* 8005BBD8 EC010028 */  fsubs    f0, f1, f0;
/* 8005BBDC D0010008 */  stfs     f0, 8(r1);
/* 8005BBE0 48000028 */  b        UNDEF_8005bc08;
UNDEF_8005bbe4:;
/* 8005BBE4 80171090 */  lwz      r0, 4240(r23);
/* 8005BBE8 2C000003 */  cmpwi    r0, 3;
/* 8005BBEC 4182001C */  beq-     UNDEF_8005bc08;
/* 8005BBF0 2C000000 */  cmpwi    r0, 0;
/* 8005BBF4 41820014 */  beq-     UNDEF_8005bc08;
/* 8005BBF8 C0210008 */  lfs      f1, 8(r1);
/* 8005BBFC C00289A0 */  lfs      f0, UNDEF_8042bd00@sda21;
/* 8005BC00 EC010028 */  fsubs    f0, f1, f0;
/* 8005BC04 D0010008 */  stfs     f0, 8(r1);
UNDEF_8005bc08:;
/* 8005BC08 C3C289A4 */  lfs      f30, UNDEF_8042bd04@sda21;
/* 8005BC0C 7F59D378 */  mr       r25, r26;
/* 8005BC10 C3E289A8 */  lfs      f31, UNDEF_8042bd08@sda21;
/* 8005BC14 3B010010 */  addi     r24, r1, STACK_PLAYER_ARRAY;
/* 8005BC18 3AE00000 */  li       r23, 0;
UNDEF_8005bc1c:;
                         mr       r3, r23;
                         bl       get_index_daPyDemoMng_c__Fi;
                         slwi     r3, r3, 2;
                         add      r25, r26, r3;

/* 8005BC1C 80780000 */  lwz      r3, 0(r24);
/* 8005BC20 90790020 */  stw      r3, 0x20(r25);
/* 8005BC24 2C03FFFF */  cmpwi    r3, -1;
/* 8005BC28 41820054 */  beq-     UNDEF_8005bc7c;
/* 8005BC2C 809A001C */  lwz      r4, 28(r26);
/* 8005BC30 38040001 */  addi     r0, r4, 1;
/* 8005BC34 901A001C */  stw      r0, 28(r26);
/* 8005BC38 48003F59 */  bl       getCtrlPlayer__9daPyMng_cFi;
/* 8005BC3C 2C030000 */  cmpwi    r3, 0;
/* 8005BC40 4182003C */  beq-     UNDEF_8005bc7c;
/* 8005BC44 C00300B0 */  lfs      f0, 176(r3);
/* 8005BC48 C0210008 */  lfs      f1, 8(r1);
/* 8005BC4C EC1E002A */  fadds    f0, f30, f0;
/* 8005BC50 FC010040 */  fcmpo    cr0, f1, f0;
/* 8005BC54 4081000C */  ble-     UNDEF_8005bc60;
/* 8005BC58 FC200090 */  fmr      f1, f0;
/* 8005BC5C D0010008 */  stfs     f0, 8(r1);
UNDEF_8005bc60:;
/* 8005BC60 FC000818 */  frsp     f0, f1;
/* 8005BC64 D0030438 */  stfs     f0, 1080(r3);
/* 8005BC68 C0231030 */  lfs      f1, 4144(r3);
/* 8005BC6C C0010008 */  lfs      f0, 8(r1);
/* 8005BC70 EC3F0072 */  fmuls    f1, f31, f1;
/* 8005BC74 EC00082A */  fadds    f0, f0, f1;
/* 8005BC78 D0010008 */  stfs     f0, 8(r1);
UNDEF_8005bc7c:;
/* 8005BC7C 3AF70001 */  addi     r23, r23, 1;
/* 8005BC80 3B390004 */  addi     r25, r25, 4;
/* 8005BC84          */  cmpwi    r23, PLAYER_COUNT;
/* 8005BC88 3B180004 */  addi     r24, r24, 4;
/* 8005BC8C 4180FF90 */  blt+     UNDEF_8005bc1c;
UNDEF_8005bc90:;
/* 8005BC90 480A66A1 */  bl       UNDEF_80102330; // ReplayEnd__10dScStage_cFv
/* 8005BC94 806DA5F4 */  lwz      r3, UNDEF_80429f74@sda21;
/* 8005BC98 4BFFFB79 */  bl       UNDEF_8005b810; // stopBgmGoalDemo__13daPyDemoMng_cFv
/* 8005BC9C 38600001 */  li       r3, 1;
/* 8005BCA0 3880000A */  li       r4, 10;
/* 8005BCA4 38000000 */  li       r0, 0;
/* 8005BCA8 907A0008 */  stw      r3, 8(r26);
/* 8005BCAC 7F43D378 */  mr       r3, r26;
/* 8005BCB0 909A000C */  stw      r4, 12(r26);
/* 8005BCB4 901A0018 */  stw      r0, 24(r26);
/* 8005BCB8 4BFFF9D9 */  bl       UNDEF_8005b690; // deleteNotGoalPlayer__13daPyDemoMng_cFv
/* 8005BCBC 7F43D378 */  mr       r3, r26;
/* 8005BCC0 48000B71 */  bl       UNDEF_8005c830;
UNDEF_8005bcc4:;
/* 8005BCC4 39610060 */  addi     r11, r1, STACK_SIZE-0x20;
/* 8005BCC8 E3E10078 */  .long    0xE3E10000 | (STACK_SIZE-0x8); // psq_l    f31, 120(r1), 0, 0;
/* 8005BCCC CBE10070 */  lfd      f31, STACK_SIZE-0x10(r1);
/* 8005BCD0 E3C10068 */  .long    0xE3C10000 | (STACK_SIZE-0x18); // psq_l    f30, 104(r1), 0, 0;
/* 8005BCD4 CBC10060 */  lfd      f30, STACK_SIZE-0x20(r1);
/* 8005BCD8 482813C9 */  bl       UNDEF_802dd0a0;
/* 8005BCDC 80010084 */  lwz      r0, STACK_SIZE+0x4(r1);
/* 8005BCE0 7C0803A6 */  mtlr     r0;
/* 8005BCE4 38210080 */  addi     r1, r1, STACK_SIZE;
/* 8005BCE8 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x8005BCF0)]]
void daPyDemoMng_c::executeGoalDemo_PoleDown()
{
    mDemoState = 2;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerIDs[convIdx(i)] == -1) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(mPlayerIDs[convIdx(i)]);
        if (player != nullptr) {
            player->onStatus(103);
        }
    }
}

[[nsmbw(0x8005BD60)]]
void daPyDemoMng_c::executeGoalDemo_JumpCheck()
{
    if (!(mFlags & 0x2)) {
        return;
    }

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (player->isStatus(101) && !player->isStatus(104)) {
            return;
        }
    }

    m0x54 = 0;
    mDemoState = 3;
    mPlayerIndex = mPlayerCount - 1;
    m0x0C = 10;
}

[[nsmbw(0x8005BE30)]]
void daPyDemoMng_c::executeGoalDemo_Jump() ASM_METHOD(
  // clang-format off
/* 8005BE30 9421FFF0 */  stwu     r1, -16(r1);
/* 8005BE34 7C0802A6 */  mflr     r0;
/* 8005BE38 90010014 */  stw      r0, 20(r1);
/* 8005BE3C 93E1000C */  stw      r31, 12(r1);
/* 8005BE40 7C7F1B78 */  mr       r31, r3;
/* 8005BE44 80030018 */  lwz      r0, 24(r3);
/* 8005BE48 2C000000 */  cmpwi    r0, 0;
/* 8005BE4C 40800010 */  bge-     UNDEF_8005be5c;
/* 8005BE50 38000004 */  li       r0, 4;
/* 8005BE54 90030008 */  stw      r0, 8(r3);
/* 8005BE58 4800009C */  b        UNDEF_8005bef4;
UNDEF_8005be5c:;
/* 8005BE5C 40820044 */  bne-     UNDEF_8005bea0;
/* 8005BE60 80030054 */  lwz      r0, 84(r3);
/* 8005BE64 2C000000 */  cmpwi    r0, 0;
/* 8005BE68 40820038 */  bne-     UNDEF_8005bea0;
/* 8005BE6C 88030040 */  lbz      r0, 64(r3);
/* 8005BE70 2C000000 */  cmpwi    r0, 0;
/* 8005BE74 41820014 */  beq-     UNDEF_8005be88;
/* 8005BE78 806DAE08 */  lwz      r3, UNDEF_8042a788@sda21;
/* 8005BE7C 38800001 */  li       r4, 1;
/* 8005BE80 481404A1 */  bl       UNDEF_8019c320;
/* 8005BE84 48000010 */  b        UNDEF_8005be94;
UNDEF_8005be88:;
/* 8005BE88 806DAE08 */  lwz      r3, UNDEF_8042a788@sda21;
/* 8005BE8C 38800000 */  li       r4, 0;
/* 8005BE90 48140491 */  bl       UNDEF_8019c320;
UNDEF_8005be94:;
/* 8005BE94 807F0054 */  lwz      r3, 84(r31);
/* 8005BE98 38030001 */  addi     r0, r3, 1;
/* 8005BE9C 901F0054 */  stw      r0, 84(r31);
UNDEF_8005bea0:;
/* 8005BEA0 801F000C */  lwz      r0, 12(r31);
/* 8005BEA4 2C000000 */  cmpwi    r0, 0;
/* 8005BEA8 4082004C */  bne-     UNDEF_8005bef4;
/* 8005BEAC          */  lwz      r3, 24(r31); // mPlayerIndex
                         bl       get_index_daPyDemoMng_c__Fi;
/* 8005BEB0          */  slwi     r0, r3, 2;
/* 8005BEB4 7C7F0214 */  add      r3, r31, r0;
/* 8005BEB8 80630020 */  lwz      r3, 32(r3);
/* 8005BEBC 48003CD5 */  bl       getCtrlPlayer__9daPyMng_cFi;
/* 8005BEC0 80DF0018 */  lwz      r6, 24(r31);
/* 8005BEC4 2C030000 */  cmpwi    r3, 0;
/* 8005BEC8 809F001C */  lwz      r4, 28(r31);
/* 8005BECC 3806FFFF */  subi     r0, r6, 1;
/* 8005BED0 38A60001 */  addi     r5, r6, 1;
/* 8005BED4 901F0018 */  stw      r0, 24(r31);
/* 8005BED8 7C052050 */  sub      r0, r4, r5;
/* 8005BEDC 41820018 */  beq-     UNDEF_8005bef4;
/* 8005BEE0 90030434 */  stw      r0, 1076(r3);
/* 8005BEE4 38800069 */  li       r4, 105;
/* 8005BEE8 4BFFAD89 */  bl       onStatus__10daPlBase_cFi;
/* 8005BEEC 3800000A */  li       r0, 10;
/* 8005BEF0 901F000C */  stw      r0, 12(r31);
UNDEF_8005bef4:;
/* 8005BEF4 80010014 */  lwz      r0, 20(r1);
/* 8005BEF8 83E1000C */  lwz      r31, 12(r1);
/* 8005BEFC 7C0803A6 */  mtlr     r0;
/* 8005BF00 38210010 */  addi     r1, r1, 16;
/* 8005BF04 4E800020 */  blr;
  // clang-format on
);

[[nsmbw(0x8005BF10)]]
void daPyDemoMng_c::executeGoalDemo_Land()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (!player->isStatus(101) || player->isStatus(106)) {
            continue;
        }

        return;
    }

    mDemoState = 5;
    mFlags |= 0x8;
}

[[nsmbw(0x8005BFD0)]]
void daPyDemoMng_c::executeGoalDemo_KimeWait()
{
    bool setFlag = false;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (!player->isStatus(101) || !player->isStatus(108)) {
            continue;
        }

        setFlag = true;
        break;
    }

    if (setFlag) {
        mFlags |= 0x10;
    } else {
        mFlags &= ~0x10;
    }
}

[[nsmbw(0x8005C130)]]
void daPyDemoMng_c::setGoalDemoKimeAll()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerIDs[convIdx(i)] == -1) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(mPlayerIDs[convIdx(i)]);
        if (player != nullptr) {
            player->onStatus(107);
        }
    }
}

[[nsmbw(0x8005C1A0)]]
void daPyDemoMng_c::setGoalDemoRunCastle()
{
    setDemoMode(Mode_e::MODE_0, 0);

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mPlayerIDs[convIdx(i)] == -1) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(mPlayerIDs[convIdx(i)]);
        if (player != nullptr) {
            player->onStatus(109);
        }
    }
}

[[nsmbw(0x8005C210)]]
bool daPyDemoMng_c::isAllPlayerGoalIn()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (!player->isStatus(101) || player->isStatus(110)) {
            continue;
        }

        return false;
    }

    return true;
}

[[nsmbw(0x8005C6D0)]]
void daPyDemoMng_c::calcGoalCenterPos()
{
    int count = 0;
    mVec3_c posSum = mVec3_c::Zero;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (!player->isStatus(101)) {
            continue;
        }

        count++;
        posSum += player->mPos;
    }

    if (count == 0) {
        return;
    }

    if (mDemoMode == Mode_e::MODE_1) {
        float factor = 1.0f / count;
        mGoalCenterPos = posSum * factor;
    } else {
        mGoalCenterPos.x = posSum.x / count;
    }
}

[[nsmbw(0x8005C930)]]
bool daPyDemoMng_c::startControlDemoAll()
{
    if (daPyMng_c::mNum == 0) {
        return false;
    }

    int ret = 1;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (!player->startControlDemo()) {
            ret = 0;
        }
    }

    return ret == 0;
}

[[nsmbw(0x8005C9D0)]]
bool daPyDemoMng_c::isAllPlayerControlDemo()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (player->isStatus(114)) {
            continue;
        }

        return false;
    }

    return true;
}

[[nsmbw(0x8005CA50)]]
void daPyDemoMng_c::endControlDemoAll(int param)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        player->endControlDemo(param);
    }
}

[[nsmbw(0x8005CAD0)]]
int daPyDemoMng_c::getControlDemoPlayerNum()
{
    int count = 0;

    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (player->isDemoType(daPlBase_c::DemoType_e::DEMO_4)) {
            count++;
        }
    }

    return count;
}

[[nsmbw(0x8005CB70)]]
void daPyDemoMng_c::onLandStopReq()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (!player->isDemoType(daPlBase_c::DemoType_e::DEMO_4)) {
            player->onStatus(95);
        }
    }
}

[[nsmbw(0x8005CC00)]]
bool daPyDemoMng_c::startControlDemoLandPlayer()
{
    if (daPyMng_c::mNum == 0) {
        return false;
    }

    int ret = 1;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (!player->isBossDemoLand()) {
            ret = 0;
            continue;
        }

        if (!player->isDemoType(daPlBase_c::DemoType_e::DEMO_4)) {
            player->startControlDemo();
            ret = 0;
        }
    }

    return ret != 0;
}

[[nsmbw(0x8005CDD0)]]
bool daPyDemoMng_c::isLandAll()
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        if (!player->isBossDemoLand()) {
            return false;
        }
    }

    return true;
}

[[nsmbw(0x8005CE50)]]
void daPyDemoMng_c::UNDEF_8005CE50(s32 param)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (!(daPyMng_c::mActPlayerInfo & (1 << i))) {
            continue;
        }

        daPlBase_c* player = daPyMng_c::getCtrlPlayer(i);
        if (player == nullptr) {
            continue;
        }

        player->UNDEF_80052290(param);
    }
}

[[nsmbw(0x8005CED0)]]
void daPyDemoMng_c::executeStartToride()
{
    if (mDemoState == 0) {
        m0x8C = -1;
    }

    if (mDemoState != 1) {
        return;
    }

    if (m0x8C == -1) {
        for (int i = 0; i < PLAYER_COUNT; i++) {
            if (mPlayerIDs[convIdx(i)] == -1) {
                continue;
            }

            daPlBase_c* player = daPyMng_c::getCtrlPlayer(mPlayerIDs[convIdx(i)]);
            if (player == nullptr) {
                continue;
            }

            if (player->isBossDemoLand()) {
                m0x8C = i;
                break;
            }
        }
    }

    if (isLandAll()) {
        UNDEF_8005CE50(1);
        mDemoState = 2;
    }
}

[[nsmbw(0x8005D050)]]
void daPyDemoMng_c::setCourseOutList(s8 param)
{
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (mCourseOutList[convIdx70(i)] == -1) {
            mCourseOutList[convIdx70(i)] = param;
            break;
        }
    }
}

[[nsmbw(0x8005D0D0)]]
void daPyDemoMng_c::turnNextDemoNo()
{
    for (int i = 0; i < PLAYER_COUNT - 1; i++) {
        mCourseInList[convIdx60(i)] = mCourseInList[convIdx60(i + 1)];
    }
    mCourseInList[convIdx60(PLAYER_COUNT - 1)] = -1;
}

[[nsmbw(0x8005D100)]]
void daPyDemoMng_c::clearDemoNo(s8 param)
{
    int demoWriteCount = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        int demoNo = mCourseInList[convIdx60(i)];
        if (demoNo != -1 && demoNo != param) {
            mCourseInList[convIdx60(demoWriteCount++)] = demoNo;
        }
    }

    for (int i = demoWriteCount; i < PLAYER_COUNT; i++) {
        mCourseInList[convIdx60(i)] = -1;
    }
}

[[nsmbw(0x8005D280)]]
void daPyDemoMng_c::genCourseInList()
{
    u32 playerOutMask = 0;
    int playerOutCount = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        int plrNo = mCourseOutList[convIdx70(i)];
        if (plrNo == -1) {
            break;
        }

        mCourseInList[convIdx60(i)] = plrNo;
        playerOutMask |= 1 << plrNo;
        playerOutCount++;
    }

    int randomOrder[PLAYER_COUNT];
    int randomOrderCount = 0;
    for (int i = 0; i < PLAYER_COUNT; i++) {
        if (playerOutMask & (1 << i) || daPyMng_c::mPlayerEntry[i] == 0) {
            continue;
        }

        if (!!(
              daPyMng_c::mCreateItem[static_cast<int>(daPyMng_c::mPlayerType[i])] &
              PLAYER_CREATE_ITEM_e::BUBBLE
            )) {
            continue;
        }

        randomOrder[randomOrderCount++] = i;
    }

    // Random swap them
    for (int i = 0; i < randomOrderCount; i++) {
        int randomIndex = dGameCom::rndInt(randomOrderCount);
        int temp = randomOrder[i];
        randomOrder[i] = randomOrder[randomIndex];
        randomOrder[randomIndex] = temp;
    }

    // Copy the randomized order to the final list
    for (int i = 0, j = playerOutCount; i < randomOrderCount; i++, j++) {
        mCourseInList[convIdx60(j)] = randomOrder[i];
    }

    // Copy to player manager and clear course out list
    for (int i = 0; i < PLAYER_COUNT; i++) {
        daPyMng_c::mCourseInList[i] = mCourseInList[convIdx60(i)];
        mCourseOutList[convIdx70(i)] = -1;
    }
}
