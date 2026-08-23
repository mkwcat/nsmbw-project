// d_a_en_water_stream.cpp
// NSMBW d_enemies.text: 0x80AC7800 - 0x80AC8270

#include "d_a_en_water_stream.h"

u32 daEnWaterStream_c_size = sizeof(daEnWaterStream_c);

[[nsmbw(0x80AC7800)]]
daEnWaterStream_c* daEnWaterStream_c_classInit() ASM_METHOD(
  // clang-format off
/* 80AC7800 9421FFE0 */  stwu     r1, -32(r1);
/* 80AC7804 7C0802A6 */  mflr     r0;
/* 80AC7808          */  lis      r3, daEnWaterStream_c_size@ha;
/* 80AC780C 90010024 */  stw      r0, 36(r1);
/* 80AC7810 93E1001C */  stw      r31, 28(r1);
/* 80AC7814 93C10018 */  stw      r30, 24(r1);
/* 80AC7818 93A10014 */  stw      r29, 20(r1);
                         lwz      r3, daEnWaterStream_c_size@l(r3);
/* 80AC781C 4B69B1E5 */  bl       UNDEF_80162a00;
/* 80AC7820 2C030000 */  cmpwi    r3, 0;
/* 80AC7824 7C7E1B78 */  mr       r30, r3;
/* 80AC7828 41820070 */  beq-     UNDEF_80ac7898;
/* 80AC782C 4B5CD655 */  bl       UNDEF_80094e80;
/* 80AC7830 3C6080B1 */  lis      r3, UNDEF_80b0fbe0@ha;
/* 80AC7834 3CA08030 */  lis      r5, UNDEF_802fd628@ha;
/* 80AC7838 3863FBE0 */  addi     r3, r3, UNDEF_80b0fbe0@l;
/* 80AC783C 907E0060 */  stw      r3, 96(r30);
/* 80AC7840 38A5D628 */  addi     r5, r5, UNDEF_802fd628@l;
/* 80AC7844 3BBE053C */  addi     r29, r30, 1340;
/* 80AC7848 80050004 */  lwz      r0, 4(r5);
/* 80AC784C 3BE00000 */  li       r31, 0;
/* 80AC7850 80850000 */  lwz      r4, 0(r5);
/* 80AC7854 7FA3EB78 */  mr       r3, r29;
/* 80AC7858 909E0528 */  stw      r4, 1320(r30);
/* 80AC785C 901E052C */  stw      r0, 1324(r30);
/* 80AC7860 80050008 */  lwz      r0, 8(r5);
/* 80AC7864 901E0530 */  stw      r0, 1328(r30);
/* 80AC7868 93FE0534 */  stw      r31, 1332(r30);
/* 80AC786C 93FE0538 */  stw      r31, 1336(r30);
/* 80AC7870 4B810521 */  bl       UNDEF_802d7d90;
/* 80AC7874 3C608033 */  lis      r3, UNDEF_80329ca0@ha;
/* 80AC7878 38639CA0 */  addi     r3, r3, UNDEF_80329ca0@l;
/* 80AC787C 907D0000 */  stw      r3, 0(r29);
/* 80AC7880 93FD0114 */  stw      r31, 276(r29);
/* 80AC7884 93FD0118 */  stw      r31, 280(r29);
/* 80AC7888 9BFD011C */  stb      r31, 284(r29);
/* 80AC788C 9BFD011D */  stb      r31, 285(r29);
/* 80AC7890 93FD0120 */  stw      r31, 288(r29);
/* 80AC7894 93FD0124 */  stw      r31, 292(r29);

                         addi     r3, r30, 0x664;
                         li       r4, 0;
                         li       r5, PLAYER_COUNT * 4;
                         bl       memset;
UNDEF_80ac7898:;
/* 80AC7898 7FC3F378 */  mr       r3, r30;
/* 80AC789C 83E1001C */  lwz      r31, 28(r1);
/* 80AC78A0 83C10018 */  lwz      r30, 24(r1);
/* 80AC78A4 83A10014 */  lwz      r29, 20(r1);
/* 80AC78A8 80010024 */  lwz      r0, 36(r1);
/* 80AC78AC 7C0803A6 */  mtlr     r0;
/* 80AC78B0 38210020 */  addi     r1, r1, 32;
/* 80AC78B4 4E800020 */  blr;
  // clang-format on
);
