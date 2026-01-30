#pragma once

EXTERN_C_START

/**
 * Pack value into bitfield.
 * Value is shifted to the specified bit position.
 * (Bit indices are LSB)
 */
#define GX_BITSET(field, pos, size, value)                                                         \
    __rlwimi((field), (value), 31 - (pos) - (size) + 1, (pos), (pos) + (size) - 1)

/**
 * Compose value from bitfield.
 * Value is shifted after masking.
 * (Bit indices are LSB)
 */
#define GX_BITGET(field, pos, size) ((field) >> (31 - (pos) - (size) + 1) & ((1 << (size)) - 1))

/**
 * Pack value into bitfield.
 * Value is not shifted, only masked.
 * (Bit indices are LSB)
 */
#define GX_BITSET_TRUNC(field, pos, size, value)                                                   \
    __rlwimi((field), (value), 0, (pos), (pos) + (size) - 1)

/**
 * Compose value from bitfield.
 * Value is not shifted, only masked.
 * (Bit indices are LSB)
 */
#define GX_BITGET_TRUNC(field, pos, size) ((field) & (((1 << (size)) - 1) << (32 - (pos) - (size))))

/**
 * Common types used throughout many GX files.
 * To avoid circular depencies, common structures and all enums have been moved
 * here. Everything is organized in alphabetical order.
 */

// Differentiate between 8-byte and boolean values
// Real name! (from patent)
typedef unsigned char GXBool;

/**
 * Common enums
 */

enum GXAlphaOp {
    GX_AOP_AND,
    GX_AOP_OR,
    GX_AOP_XOR,
    GX_AOP_XNOR,

    GX_MAX_ALPHAOP
};

enum GXAnisotropy {
    GX_ANISO_1,
    GX_ANISO_2,
    GX_ANISO_4,

    GX_MAX_ANISOTROPY
};

enum GXAttnFn {
    GX_AF_SPEC,
    GX_AF_SPOT,
    GX_AF_NONE,
};

enum GXAttr {
    GX_VA_PNMTXIDX,
    GX_VA_TEX0MTXIDX,
    GX_VA_TEX1MTXIDX,
    GX_VA_TEX2MTXIDX,
    GX_VA_TEX3MTXIDX,
    GX_VA_TEX4MTXIDX,
    GX_VA_TEX5MTXIDX,
    GX_VA_TEX6MTXIDX,
    GX_VA_TEX7MTXIDX,
    GX_VA_POS,
    GX_VA_NRM,
    GX_VA_CLR0,
    GX_VA_CLR1,
    GX_VA_TEX0,
    GX_VA_TEX1,
    GX_VA_TEX2,
    GX_VA_TEX3,
    GX_VA_TEX4,
    GX_VA_TEX5,
    GX_VA_TEX6,
    GX_VA_TEX7,
    GX_POS_MTX_ARRAY,
    GX_NRM_MTX_ARRAY,
    GX_TEX_MTX_ARRAY,
    GX_LIGHT_ARRAY,
    GX_VA_NBT, // All three normal elements (normal/binormal/tangent)

    GX_VA_MAX_ATTR,
    GX_VA_NULL = 255
};

enum GXAttrType {
    GX_NONE, //! No data sent
    GX_DIRECT, //! Data sent directly to FIFO
    GX_INDEX8, //! 8-bit index sent to FIFO
    GX_INDEX16 //! 16-bit index sent to FIFO
};

enum GXBlendFactor {
    GX_BL_ZERO,
    GX_BL_ONE,
    GX_BL_SRCCLR,
    GX_BL_INVSRCCLR,
    GX_BL_SRCALPHA,
    GX_BL_INVSRCALPHA,
    GX_BL_DSTALPHA,
    GX_BL_INVDSTALPHA,

    GX_BL_DSTCLR = GX_BL_SRCCLR,
    GX_BL_INVDSTCLR = GX_BL_INVSRCCLR
};

enum GXBlendMode {
    GX_BM_NONE,
    GX_BM_BLEND,
    GX_BM_LOGIC,
    GX_BM_SUBTRACT,

    GX_MAX_BLENDMODE
};

enum GXChannelID {
    GX_COLOR0,
    GX_COLOR1,
    GX_ALPHA0,
    GX_ALPHA1,
    GX_COLOR0A0,
    GX_COLOR1A1,
    GX_COLOR_ZERO,
    GX_ALPHA_BUMP,
    GX_ALPHA_BUMPN,

    GX_COLOR_NULL = 255
};

enum GXCITexFmt {
    GX_TF_C4 = 8,
    GX_TF_C8,
    GX_TF_C14X2,
};

enum GXClearZ {
    GX_CLEAR_Z_MIN = 0,
    GX_CLEAR_Z_MAX = 24_bit - 1,
};

enum GXClipMode {
    // "ClipDisable" in XF mem, so 0 = enable
    GX_CLIP_ENABLE,
    GX_CLIP_DISABLE,
};

enum GXColorSrc {
    GX_SRC_REG,
    GX_SRC_VTX
};

enum GXCompare {
    GX_NEVER,
    GX_LESS,
    GX_EQUAL,
    GX_LEQUAL,
    GX_GREATER,
    GX_NEQUAL,
    GX_GEQUAL,
    GX_ALWAYS
};

enum GXCompCnt {
    GX_POS_XY = 0,
    GX_POS_XYZ,

    GX_NRM_XYZ = 0,
    GX_NRM_NBT,
    GX_NRM_NBT3,

    GX_CLR_RGB = 0,
    GX_CLR_RGBA,

    GX_TEX_S = 0,
    GX_TEX_ST
};

enum GXCompType {
    GX_U8,
    GX_S8,
    GX_U16,
    GX_S16,
    GX_F32,

    GX_RGB565 = 0,
    GX_RGB8,
    GX_RGBX8,
    GX_RGBA4,
    GX_RGBA6,
    GX_RGBA8
};

enum GXCopyClamp {
    GX_CLAMP_NONE,
    GX_CLAMP_TOP,
    GX_CLAMP_BOTTOM,
    GX_CLAMP_ALL,
};

enum GXCullMode {
    GX_CULL_NONE,
    GX_CULL_FRONT,
    GX_CULL_BACK,
    GX_CULL_ALL
};

enum GXDiffuseFn {
    GX_DF_NONE,
    GX_DF_SIGN,
    GX_DF_CLAMP
};

enum GXDirtyFlag {
    GX_DIRTY_SU_TEX = 0_bit,
    GX_DIRTY_BP_MASK = 1_bit,
    GX_DIRTY_GEN_MODE = 2_bit,
    GX_DIRTY_VCD = 3_bit,
    GX_DIRTY_VAT = 4_bit,
    // . . .
    GX_DIRTY_AMB_COLOR0 = 8_bit,
    GX_DIRTY_AMB_COLOR1 = 9_bit,
    GX_DIRTY_MAT_COLOR0 = 10_bit,
    GX_DIRTY_MAT_COLOR1 = 11_bit,
    GX_DIRTY_CHAN_COLOR0 = 12_bit,
    GX_DIRTY_CHAN_COLOR1 = 13_bit,
    GX_DIRTY_CHAN_ALPHA0 = 14_bit,
    GX_DIRTY_CHAN_ALPHA1 = 15_bit,
    GX_DIRTY_TEX0 = 16_bit,
    GX_DIRTY_TEX1 = 17_bit,
    GX_DIRTY_TEX2 = 18_bit,
    GX_DIRTY_TEX3 = 19_bit,
    GX_DIRTY_TEX4 = 20_bit,
    GX_DIRTY_TEX5 = 21_bit,
    GX_DIRTY_TEX6 = 22_bit,
    GX_DIRTY_TEX7 = 23_bit,
    GX_DIRTY_NUM_COLORS = 24_bit,
    GX_DIRTY_NUM_TEX = 25_bit,
    GX_DIRTY_MTX_IDX = 26_bit,
    GX_DIRTY_PROJECTION = 27_bit,
    GX_DIRTY_VIEWPORT = 28_bit,

    GX_AMB_MAT_MASK =
      GX_DIRTY_AMB_COLOR0 | GX_DIRTY_AMB_COLOR1 | GX_DIRTY_MAT_COLOR0 | GX_DIRTY_MAT_COLOR1,

    GX_LIGHT_CHAN_MASK = GX_DIRTY_CHAN_COLOR0 | GX_DIRTY_CHAN_COLOR1 | GX_DIRTY_CHAN_ALPHA0 |
                         GX_DIRTY_CHAN_ALPHA1 | GX_DIRTY_NUM_COLORS,

    GX_TEX_GEN_MASK = 0x2FF0000,
};

enum GXDistAttnFn {
    GX_DA_OFF,
    GX_DA_GENTLE,
    GX_DA_MEDIUM,
    GX_DA_STEEP
};

enum GXFogType {
    GX_FOG_NONE,

    GX_FOG_PERSP_LIN = 2,
    GX_FOG_PERSP_EXP = 4,
    GX_FOG_PERSP_EXP2 = 5,
    GX_FOG_PERSP_REVEXP = 6,
    GX_FOG_PERSP_REVEXP2 = 7,

    // Fourth bit is set to mark orthographic
    GX_FOG_ORTHO_LIN = 3_bit | GX_FOG_PERSP_LIN,
    GX_FOG_ORTHO_EXP = 3_bit | GX_FOG_PERSP_EXP,
    GX_FOG_ORTHO_EXP2 = 3_bit | GX_FOG_PERSP_EXP2,
    GX_FOG_ORTHO_REVEXP = 3_bit | GX_FOG_PERSP_REVEXP,
    GX_FOG_ORTHO_REVEXP2 = 3_bit | GX_FOG_PERSP_REVEXP2
};

// Access components of the fog type
#define GX_FOG_GET_PROJ(x) ((x) >> 3 & 1)
#define GX_FOG_GET_FSEL(x) ((x) & 7)

enum GXIndTexAlphaSel {
    GX_ITBA_OFF,
    GX_ITBA_S,
    GX_ITBA_T,
    GX_ITBA_U,

    GX_MAX_ITBALPHA
};

enum GXIndTexBiasSel {
    GX_ITB_NONE,
    GX_ITB_S,
    GX_ITB_T,
    GX_ITB_ST,
    GX_ITB_U,
    GX_ITB_SU,
    GX_ITB_TU,
    GX_ITB_STU,

    GX_MAX_ITBIAS
};

enum GXIndTexFormat {
    GX_ITF_8,
    GX_ITF_5,
    GX_ITF_4,
    GX_ITF_3,

    GX_MAX_ITFORMAT
};

enum GXIndTexMtxID {
    GX_ITM_OFF,
    GX_ITM_0,
    GX_ITM_1,
    GX_ITM_2,

    GX_ITM_S0 = 5,
    GX_ITM_S1,
    GX_ITM_S2,

    GX_ITM_T0 = 9,
    GX_ITM_T1,
    GX_ITM_T2,
};

enum GXIndTexScale {
    GX_ITS_1,
    GX_ITS_2,
    GX_ITS_4,
    GX_ITS_8,
    GX_ITS_16,
    GX_ITS_32,
    GX_ITS_64,
    GX_ITS_128,
    GX_ITS_256,

    GX_MAX_ITSCALE
};

enum GXIndTexStageID {
    GX_INDTEXSTAGE0,
    GX_INDTEXSTAGE1,
    GX_INDTEXSTAGE2,
    GX_INDTEXSTAGE3,

    GX_MAX_INDTEXSTAGE
};

enum GXIndTexWrap {
    GX_ITW_OFF,
    GX_ITW_256,
    GX_ITW_128,
    GX_ITW_64,
    GX_ITW_32,
    GX_ITW_16,
    GX_ITW_0,

    GX_MAX_ITWRAP,
};

enum GXLightID {
    GX_LIGHT0 = 0_bit,
    GX_LIGHT1 = 1_bit,
    GX_LIGHT2 = 2_bit,
    GX_LIGHT3 = 3_bit,
    GX_LIGHT4 = 4_bit,
    GX_LIGHT5 = 5_bit,
    GX_LIGHT6 = 6_bit,
    GX_LIGHT7 = 7_bit,

    GX_MAX_LIGHT = 8_bit,
    GX_LIGHT_NULL = 0
};

enum GXLogicOp {
    GX_LO_CLEAR,
    GX_LO_AND,
    GX_LO_REVAND,
    GX_LO_COPY,
    GX_LO_INVAND,
    GX_LO_NOOP,
    GX_LO_XOR,
    GX_LO_OR,
    GX_LO_NOR,
    GX_LO_EQUIV,
    GX_LO_INV,
    GX_LO_REVOR,
    GX_LO_INVCOPY,
    GX_LO_INVOR,
    GX_LO_NAND,
    GX_LO_SET
};

enum GXMtxType {
    GX_MTX_3x4,
    GX_MTX_2x4,
};

enum GXPixelFmt {
    GX_PF_RGB8_Z24, // from Dolphin
    GX_PF_RGBA6_Z24, // from EGG
    GX_PF_RGBA565_Z16, // from Dolphin
    GX_PF_Z24, // from Dolphin
    GX_PF_Y8, // from Dolphin
    GX_PF_U8, // from Dolphin
    GX_PF_V8, // from Dolphin
    GX_PF_YUV420, // from Dolphin

    GX_MAX_PIXELFMT
};

/**
 * Matrix column index into XF memory.
 * (Multiply by row dimension to get XF mem offset)
 */
enum GXPosNrmMtx {
    GX_PNMTX0 = 0,
    GX_PNMTX1 = 3,
    GX_PNMTX2 = 6,
    GX_PNMTX3 = 9,
    GX_PNMTX4 = 12,
    GX_PNMTX5 = 15,
    GX_PNMTX6 = 18,
    GX_PNMTX7 = 21,
    GX_PNMTX8 = 24,
    GX_PNMTX9 = 27
};

enum GXPrimitive {
    GX_POINTS = 0xB8,
    GX_LINES = 0xA8,
    GX_LINESTRIP = 0xB0,
    GX_TRIANGLES = 0x90,
    GX_TRIANGLESTRIP = 0x98,
    GX_TRIANGLEFAN = 0xA0,
    GX_QUADS = 0x80,
};

enum GXProjectionType {
    GX_PERSPECTIVE,
    GX_ORTHOGRAPHIC
};

enum GXSpotFn {
    GX_SP_OFF,
    GX_SP_FLAT,
    GX_SP_COS,
    GX_SP_COS2,
    GX_SP_SHARP,
    GX_SP_RING1,
    GX_SP_RING2
};

enum GXTevAlphaArg {
    GX_CA_APREV,
    GX_CA_A0,
    GX_CA_A1,
    GX_CA_A2,
    GX_CA_TEXA,
    GX_CA_RASA,
    GX_CA_KONST,
    GX_CA_ZERO,
    GX_CA_ONE
};

enum GXTevBias {
    GX_TB_ZERO,
    GX_TB_ADDHALF,
    GX_TB_SUBHALF,

    GX_MAX_TEVBIAS
};

enum GXTevColorArg {
    GX_CC_CPREV,
    GX_CC_APREV,
    GX_CC_C0,
    GX_CC_A0,
    GX_CC_C1,
    GX_CC_A1,
    GX_CC_C2,
    GX_CC_A2,
    GX_CC_TEXC,
    GX_CC_TEXA,
    GX_CC_RASC,
    GX_CC_RASA,
    GX_CC_ONE,
    GX_CC_HALF,
    GX_CC_KONST,
    GX_CC_ZERO,
    GX_CC_TEXRRR,
    GX_CC_TEXGGG,
    GX_CC_TEXBBB,

    GX_CC_QUARTER = GX_CC_KONST
};

enum GXTevColorChan {
    GX_CH_RED,
    GX_CH_GREEN,
    GX_CH_BLUE,
    GX_CH_ALPHA
};

enum GXTevOp {
    GX_TEV_ADD,
    GX_TEV_SUB,

    GX_TEV_COMP_R8_GT = 8,
    GX_TEV_COMP_R8_EQ,
    GX_TEV_COMP_GR16_GT,
    GX_TEV_COMP_GR16_EQ,
    GX_TEV_COMP_BGR24_GT,
    GX_TEV_COMP_BGR24_EQ,
    GX_TEV_COMP_RGB8_GT,
    GX_TEV_COMP_RGB8_EQ,

    GX_TEV_COMP_A8_GT = GX_TEV_COMP_RGB8_GT,
    GX_TEV_COMP_A8_EQ = GX_TEV_COMP_RGB8_EQ
};

enum GXTevRegID {
    GX_TEVPREV,
    GX_TEVREG0,
    GX_TEVREG1,
    GX_TEVREG2,

    GX_MAX_TEVREG
};

enum GXTevScale {
    GX_CS_SCALE_1,
    GX_CS_SCALE_2,
    GX_CS_SCALE_4,
    GX_CS_DIVIDE_2,

    GX_MAX_TEVSCALE
};

enum GXTevStageID {
    GX_TEVSTAGE0,
    GX_TEVSTAGE1,
    GX_TEVSTAGE2,
    GX_TEVSTAGE3,
    GX_TEVSTAGE4,
    GX_TEVSTAGE5,
    GX_TEVSTAGE6,
    GX_TEVSTAGE7,
    GX_TEVSTAGE8,
    GX_TEVSTAGE9,
    GX_TEVSTAGE10,
    GX_TEVSTAGE11,
    GX_TEVSTAGE12,
    GX_TEVSTAGE13,
    GX_TEVSTAGE14,
    GX_TEVSTAGE15,

    GX_MAX_TEVSTAGE
};

enum GXTevSwapSel {
    GX_TEV_SWAP0,
    GX_TEV_SWAP1,
    GX_TEV_SWAP2,
    GX_TEV_SWAP3,

    GX_MAX_TEVSWAP
};

enum GXTevKAlphaSel {
    GX_TEV_KASEL_8_8,
    GX_TEV_KASEL_7_8,
    GX_TEV_KASEL_6_8,
    GX_TEV_KASEL_5_8,
    GX_TEV_KASEL_4_8,
    GX_TEV_KASEL_3_8,
    GX_TEV_KASEL_2_8,
    GX_TEV_KASEL_1_8,

    GX_TEV_KASEL_1 = 0,
    GX_TEV_KASEL_3_4 = 2,
    GX_TEV_KASEL_1_2 = 4,
    GX_TEV_KASEL_1_4 = 6,

    GX_TEV_KASEL_K0_R = 16,
    GX_TEV_KASEL_K1_R,
    GX_TEV_KASEL_K2_R,
    GX_TEV_KASEL_K3_R,
    GX_TEV_KASEL_K0_G,
    GX_TEV_KASEL_K1_G,
    GX_TEV_KASEL_K2_G,
    GX_TEV_KASEL_K3_G,
    GX_TEV_KASEL_K0_B,
    GX_TEV_KASEL_K1_B,
    GX_TEV_KASEL_K2_B,
    GX_TEV_KASEL_K3_B,
    GX_TEV_KASEL_K0_A,
    GX_TEV_KASEL_K1_A,
    GX_TEV_KASEL_K2_A,
    GX_TEV_KASEL_K3_A
};

enum GXTevKColorID {
    GX_KCOLOR0,
    GX_KCOLOR1,
    GX_KCOLOR2,
    GX_KCOLOR3,

    GX_MAX_KCOLOR
};

enum GXTevKColorSel {
    GX_TEV_KCSEL_8_8,
    GX_TEV_KCSEL_7_8,
    GX_TEV_KCSEL_6_8,
    GX_TEV_KCSEL_5_8,
    GX_TEV_KCSEL_4_8,
    GX_TEV_KCSEL_3_8,
    GX_TEV_KCSEL_2_8,
    GX_TEV_KCSEL_1_8,

    GX_TEV_KCSEL_1 = 0,
    GX_TEV_KCSEL_3_4 = 2,
    GX_TEV_KCSEL_1_2 = 4,
    GX_TEV_KCSEL_1_4 = 6,

    GX_TEV_KCSEL_K0 = 12,
    GX_TEV_KCSEL_K1,
    GX_TEV_KCSEL_K2,
    GX_TEV_KCSEL_K3,
    GX_TEV_KCSEL_K0_R,
    GX_TEV_KCSEL_K1_R,
    GX_TEV_KCSEL_K2_R,
    GX_TEV_KCSEL_K3_R,
    GX_TEV_KCSEL_K0_G,
    GX_TEV_KCSEL_K1_G,
    GX_TEV_KCSEL_K2_G,
    GX_TEV_KCSEL_K3_G,
    GX_TEV_KCSEL_K0_B,
    GX_TEV_KCSEL_K1_B,
    GX_TEV_KCSEL_K2_B,
    GX_TEV_KCSEL_K3_B,
    GX_TEV_KCSEL_K0_A,
    GX_TEV_KCSEL_K1_A,
    GX_TEV_KCSEL_K2_A,
    GX_TEV_KCSEL_K3_A
};

enum GXTevMode {
    GX_MODULATE,
    GX_DECAL,
    GX_REPLACE,
    GX_PASSCLR,
    GX_BLEND
};

enum GXTexCoordID {
    GX_TEXCOORD0,
    GX_TEXCOORD1,
    GX_TEXCOORD2,
    GX_TEXCOORD3,
    GX_TEXCOORD4,
    GX_TEXCOORD5,
    GX_TEXCOORD6,
    GX_TEXCOORD7,

    GX_MAX_TEXCOORD,
    GX_TEXCOORD_NULL = 255
};

enum GXTexFilter {
    GX_NEAR,
    GX_LINEAR,
    GX_NEAR_MIP_NEAR,
    GX_LIN_MIP_NEAR,
    GX_NEAR_MIP_LIN,
    GX_LIN_MIP_LIN,
};

enum GXTexFmt {
    GX_TF_I4,
    GX_TF_I8,
    GX_TF_IA4,
    GX_TF_IA8,
    GX_TF_RGB565,
    GX_TF_RGB5A3,
    GX_TF_RGBA8,
    GX_TF_CMPR = 14,

    GX_CTF_R4 = 32,
    GX_CTF_RA4 = 34,
    GX_CTF_RA8 = 35,
    GX_CTF_YUVA8 = 38,
    GX_CTF_A8 = 39,
    GX_CTF_R8 = 40,
    GX_CTF_G8 = 41,
    GX_CTF_B8 = 42,
    GX_CTF_RG8 = 43,
    GX_CTF_GB8 = 44,

    GX_TF_Z8 = 17,
    GX_TF_Z16 = 19,
    GX_TF_Z24X8 = 22,

    GX_CTF_Z4 = 48,
    GX_CTF_Z8M = 57,
    GX_CTF_Z8L = 58,
    GX_CTF_Z16L = 60,

    GX_TF_A8 = GX_CTF_YUVA8
};

enum GXTexGenSrc {
    GX_TG_POS,
    GX_TG_NRM,
    GX_TG_BINRM,
    GX_TG_TANGENT,
    GX_TG_TEX0,
    GX_TG_TEX1,
    GX_TG_TEX2,
    GX_TG_TEX3,
    GX_TG_TEX4,
    GX_TG_TEX5,
    GX_TG_TEX6,
    GX_TG_TEX7,
    GX_TG_TEXCOORD0,
    GX_TG_TEXCOORD1,
    GX_TG_TEXCOORD2,
    GX_TG_TEXCOORD3,
    GX_TG_TEXCOORD4,
    GX_TG_TEXCOORD5,
    GX_TG_TEXCOORD6,
    GX_TG_COLOR0,
    GX_TG_COLOR1,
};

enum GXTexGenType {
    GX_TG_MTX3x4,
    GX_TG_MTX2x4,
    GX_TG_BUMP0,
    GX_TG_BUMP1,
    GX_TG_BUMP2,
    GX_TG_BUMP3,
    GX_TG_BUMP4,
    GX_TG_BUMP5,
    GX_TG_BUMP6,
    GX_TG_BUMP7,
    GX_TG_SRTG
};

enum GXTexMapID {
    GX_TEXMAP0,
    GX_TEXMAP1,
    GX_TEXMAP2,
    GX_TEXMAP3,
    GX_TEXMAP4,
    GX_TEXMAP5,
    GX_TEXMAP6,
    GX_TEXMAP7,
    GX_MAX_TEXMAP,

    GX_TEXMAP_NULL = 255,
    GX_TEX_DISABLE
};

enum GXTexMtx {
    // Any dimension (in standard XF matrix memory)
    // Enum represents base row of matrix
    GX_TEXMTX0 = 30,
    GX_TEXMTX1 = 33,
    GX_TEXMTX2 = 36,
    GX_TEXMTX3 = 39,
    GX_TEXMTX4 = 42,
    GX_TEXMTX5 = 45,
    GX_TEXMTX6 = 48,
    GX_TEXMTX7 = 51,
    GX_TEXMTX8 = 54,
    GX_TEXMTX9 = 57,
    GX_TEXMTX_IDENT = 60,

    // 3x4 matrices (in dual-tex XF matrix memory)
    // Enum represents base row of matrix
    GX_DUALMTX0 = 64,
    GX_DUALMTX1 = 67,
    GX_DUALMTX2 = 70,
    GX_DUALMTX3 = 73,
    GX_DUALMTX4 = 76,
    GX_DUALMTX5 = 79,
    GX_DUALMTX6 = 82,
    GX_DUALMTX7 = 85,
    GX_DUALMTX8 = 88,
    GX_DUALMTX9 = 91,
    GX_DUALMTX10 = 94,
    GX_DUALMTX11 = 97,
    GX_DUALMTX12 = 100,
    GX_DUALMTX13 = 103,
    GX_DUALMTX14 = 106,
    GX_DUALMTX15 = 109,
    GX_DUALMTX16 = 112,
    GX_DUALMTX17 = 115,
    GX_DUALMTX18 = 118,
    GX_DUALMTX19 = 121,
    GX_DUALMTX_IDENT = 125,
};

enum GXTexWrapMode {
    GX_CLAMP,
    GX_REPEAT,
    GX_MIRROR,

    GX_MAX_TEXWRAPMODE
};

enum GXTlut {
    GX_TLUT0,
    GX_TLUT1,
    GX_TLUT2,
    GX_TLUT3,
    GX_TLUT4,
    GX_TLUT5,
    GX_TLUT6,
    GX_TLUT7,
    GX_TLUT8,
    GX_TLUT9,
    GX_TLUT10,
    GX_TLUT11,
    GX_TLUT12,
    GX_TLUT13,
    GX_TLUT14,
    GX_TLUT15,
    GX_BIGTLUT0,
    GX_BIGTLUT1,
    GX_BIGTLUT2,
    GX_BIGTLUT3,
};

enum GXTlutFmt {
    GX_TL_IA8,
    GX_TL_RGB565,
    GX_TL_RGB5A3,

    GX_MAX_TLUTFMT
};

enum GXVtxFmt {
    GX_VTXFMT0,
    GX_VTXFMT1,
    GX_VTXFMT2,
    GX_VTXFMT3,
    GX_VTXFMT4,
    GX_VTXFMT5,
    GX_VTXFMT6,
    GX_VTXFMT7,

    GX_MAX_VTXFMT
};

enum GXZFmt16 {
    GX_ZC_LINEAR,
    GX_ZC_NEAR,
    GX_ZC_MID,
    GX_ZC_FAR,
};

// From patent
enum GXZTexOp {
    GX_ZT_DISABLE,
    GX_ZT_ADD,
    GZ_ZT_REPLACE,

    GX_MAX_ZTEXOP
};

EXTERN_C_END
