// d_a_next_goto_block.cpp
// NSMBW d_bases.text: 0x8086E670 - 0x8086EEA0

#include "d_a_next_goto_block.h"

[[nsmbw(0x8086E670)]]
daNextGotoBlock_c* daNextGotoBlock_c_classInit()
{
    return new daNextGotoBlock_c();
}

/**
 * VT+0x08
 * do method for the create operation.
 */
[[nsmbw(0x8086E6C0)]]
fBase_c::PACK_RESULT_e daNextGotoBlock_c::create();

/**
 * VT+0x14
 * do method for the delete operation. This method was renamed due to conflict with the delete
 * C++ keyword.
 */
[[nsmbw(0x8086E870)]]
fBase_c::PACK_RESULT_e daNextGotoBlock_c::execute();

/**
 * VT+0x2C
 * do method for the draw operation.
 */
[[nsmbw(0x8086E8C0)]]
fBase_c::PACK_RESULT_e daNextGotoBlock_c::draw()
{
    return PACK_RESULT_e::SUCCEEDED;
}

[[nsmbw(0x8086E8D0)]]
void daNextGotoBlock_c::normal_collcheck(dCc_c* self, dCc_c* other)
{
    daNextGotoBlock_c* nextGotoBlock = reinterpret_cast<daNextGotoBlock_c*>(self->mpOwner);

    daPlBase_c* player = other->mpOwner->castToPlayerBase();
    if (player == nullptr || player->isItemKinopio() || player->isDemo()) {
        return;
    }

    int index = player->getPlrNo();
    if (nextGotoBlock->mPlayerInBlock[index]) {
        return;
    }

    if (nextGotoBlock->mRequireVine == 1 && !player->isStatus(51)) {
        return;
    }

    nextGotoBlock->m0x3FA[index] = 10;
    nextGotoBlock->m0x406[index] = 1;
    nextGotoBlock->mPlayerInBlock[index] = true;
    nextGotoBlock->mpaPlayers[index] = player;
}

[[nsmbw(0x8086EA10)]]
void daNextGotoBlock_c::executeState_Move() ASM_METHOD(
  // clang-format off
/* 8086EA10 9421FFB0 */  stwu     r1, -80(r1);
/* 8086EA14 7C0802A6 */  mflr     r0;
/* 8086EA18 90010054 */  stw      r0, 84(r1);
/* 8086EA1C 39610040 */  addi     r11, r1, 64;
/* 8086EA20 DBE10040 */  stfd     f31, 64(r1);
/* 8086EA24 F3E10048 */  .long    0xF3E10048; // psq_st   f31, 72(r1), 0, 0;
/* 8086EA28 4BA6E629 */  bl       UNDEF_802dd050;
/* 8086EA2C 3C808043 */  lis      r4, UNDEF_80429f74@ha;
/* 8086EA30 7C7F1B78 */  mr       r31, r3;
/* 8086EA34 80849F74 */  lwz      r4, UNDEF_80429f74@l(r4);
/* 8086EA38 80040058 */  lwz      r0, 88(r4);
/* 8086EA3C 2C000000 */  cmpwi    r0, 0;
/* 8086EA40 40820150 */  bne-     UNDEF_8086eb90;
/* 8086EA44 A0030354 */  lhz      r0, 852(r3);
/* 8086EA48 38C00000 */  li       r6, 0;
/* 8086EA4C 2C000000 */  cmpwi    r0, 0;
/* 8086EA50 41820034 */  beq-     UNDEF_8086ea84;
/* 8086EA54 3C808043 */  lis      r4, UNDEF_8042a358@ha;
/* 8086EA58 80030358 */  lwz      r0, 856(r3);
/* 8086EA5C 80A4A358 */  lwz      r5, UNDEF_8042a358@l(r4);
/* 8086EA60 8063035C */  lwz      r3, 860(r3);
/* 8086EA64 80850000 */  lwz      r4, 0(r5);
/* 8086EA68 80A50004 */  lwz      r5, 4(r5);
/* 8086EA6C 7C800038 */  and      r0, r4, r0;
/* 8086EA70 7CA31838 */  and      r3, r5, r3;
/* 8086EA74 7C600379 */  or.      r0, r3, r0;
/* 8086EA78 41820010 */  beq-     UNDEF_8086ea88;
/* 8086EA7C 38C00001 */  li       r6, 1;
/* 8086EA80 48000008 */  b        UNDEF_8086ea88;
UNDEF_8086ea84:;
/* 8086EA84 38C00001 */  li       r6, 1;
UNDEF_8086ea88:;
/* 8086EA88 2C060000 */  cmpwi    r6, 0;
/* 8086EA8C 41820104 */  beq-     UNDEF_8086eb90;
/* 8086EA90 3C608094 */  lis      r3, UNDEF_80939ba8@ha;
/* 8086EA94 7FF9FB78 */  mr       r25, r31;
/* 8086EA98 C3E39BA8 */  lfs      f31, UNDEF_80939ba8@l(r3);
/* 8086EA9C 3AE00000 */  li       r23, 0;
/* 8086EAA0 3F408043 */  lis      r26, UNDEF_8042a2a0@ha;
/* 8086EAA4 3F608043 */  lis      r27, UNDEF_80429f74@ha;
/* 8086EAA8 3F808097 */  lis      r28, UNDEF_80971584@ha;
/* 8086EAAC 3BA00001 */  li       r29, 1;
/* 8086EAB0 3BC00000 */  li       r30, 0;
UNDEF_8086eab4:;
/* 8086EAB4 7F1FBA14 */  add      r24, r31, r23;
/* 8086EAB8          */  lbz      r0, OFFSET_mPlayerInBlock(r24);
/* 8086EABC 28000001 */  cmplwi   r0, 1;
/* 8086EAC0 408200C0 */  bne-     UNDEF_8086eb80;
/* 8086EAC4 881F0413 */  lbz      r0, 1043(r31);
/* 8086EAC8 2C000000 */  cmpwi    r0, 0;
/* 8086EACC 41820088 */  beq-     UNDEF_8086eb54;
/* 8086EAD0 807AA2A0 */  lwz      r3, UNDEF_8042a2a0@l(r26);
/* 8086EAD4 88030018 */  lbz      r0, 24(r3);
/* 8086EAD8 2C000000 */  cmpwi    r0, 0;
/* 8086EADC 408200B4 */  bne-     UNDEF_8086eb90;
/* 8086EAE0 7EE3BB78 */  mr       r3, r23;
/* 8086EAE4 4B7F0E1D */  bl       getPlayer__9daPyMng_cFi;
/* 8086EAE8 2C030000 */  cmpwi    r3, 0;
/* 8086EAEC 7C761B78 */  mr       r22, r3;
/* 8086EAF0 41820090 */  beq-     UNDEF_8086eb80;
/* 8086EAF4 4B7E337D */  bl       startControlDemo__10daPlBase_cFv;
/* 8086EAF8 2C030000 */  cmpwi    r3, 0;
/* 8086EAFC 41820084 */  beq-     UNDEF_8086eb80;
/* 8086EB00 807B9F74 */  lwz      r3, UNDEF_80429f74@l(r27);
/* 8086EB04 80030080 */  lwz      r0, 128(r3);
/* 8086EB08 2C000000 */  cmpwi    r0, 0;
/* 8086EB0C 4080001C */  bge-     UNDEF_8086eb28;
/* 8086EB10 92E30080 */  stw      r23, 128(r3);
/* 8086EB14 38600003 */  li       r3, 3;
/* 8086EB18 38800000 */  li       r4, 0;
/* 8086EB1C 38A00002 */  li       r5, 2;
/* 8086EB20 38C00005 */  li       r6, 5;
/* 8086EB24 4B89384D */  bl       UNDEF_80102370;
UNDEF_8086eb28:;
/* 8086EB28 C01F00AC */  lfs      f0, 172(r31);
/* 8086EB2C 7EC3B378 */  mr       r3, r22;
/* 8086EB30 38810008 */  addi     r4, r1, 8;
/* 8086EB34 38BC1584 */  addi     r5, r28, UNDEF_80971584@l;
/* 8086EB38 EC00F828 */  fsubs    f0, f0, f31;
/* 8086EB3C D0010008 */  stfs     f0, 8(r1);
/* 8086EB40 4B7E3541 */  bl       UNDEF_80052080;
/* 8086EB44 807B9F74 */  lwz      r3, UNDEF_80429f74@l(r27);
/* 8086EB48 93A3005C */  stw      r29, 92(r3);
/* 8086EB4C          */  stb      r30, OFFSET_mPlayerInBlock(r24);
/* 8086EB50 48000030 */  b        UNDEF_8086eb80;
UNDEF_8086eb54:;
/* 8086EB54          */  lwz      r0, OFFSET_mpaPlayers(r25);
/* 8086EB58 2C000000 */  cmpwi    r0, 0;
/* 8086EB5C 41820024 */  beq-     UNDEF_8086eb80;
/* 8086EB60 7EE3BB78 */  mr       r3, r23;
/* 8086EB64 4B7F102D */  bl       UNDEF_8005fb90;
/* 8086EB68 2C030000 */  cmpwi    r3, 0;
/* 8086EB6C 41820014 */  beq-     UNDEF_8086eb80;
/* 8086EB70 889F0412 */  lbz      r4, 1042(r31);
/* 8086EB74 38A0000A */  li       r5, 10;
/* 8086EB78 80DF03F0 */  lwz      r6, 1008(r31);
/* 8086EB7C 4B7E4375 */  bl       UNDEF_80052ef0;
UNDEF_8086eb80:;
/* 8086EB80 3AF70001 */  addi     r23, r23, 1;
/* 8086EB84 3B390004 */  addi     r25, r25, 4;
/* 8086EB88          */  cmpwi    r23, PLAYER_COUNT;
/* 8086EB8C 4180FF28 */  blt+     UNDEF_8086eab4;
UNDEF_8086eb90:;
/* 8086EB90 39610040 */  addi     r11, r1, 64;
/* 8086EB94 E3E10048 */  .long    0xE3E10048; // psq_l    f31, 72(r1), 0, 0;
/* 8086EB98 CBE10040 */  lfd      f31, 64(r1);
/* 8086EB9C 4BA6E501 */  bl       UNDEF_802dd09c;
/* 8086EBA0 80010054 */  lwz      r0, 84(r1);
/* 8086EBA4 7C0803A6 */  mtlr     r0;
/* 8086EBA8 38210050 */  addi     r1, r1, 80;
/* 8086EBAC 4E800020 */  blr;
  // clang-format on
);

/* VT+0x48 */
[[nsmbw(0x8086EBB0)]]
daNextGotoBlock_c::~daNextGotoBlock_c()
{
}