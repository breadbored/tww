//
// Generated by dtk
// Translation Unit: d_chain.cpp
//

#include "d/d_kankyo.h"
#include "d/d_a_obj.h"
#include "d/d_s_play.h"
#include "global.h"
#include "m_Do/m_Do_mtx.h"
#include "JSystem/J3DGraphBase/J3DPacket.h"

class dChain_packet_c : public J3DPacket {
public:
    dChain_packet_c(int, dKy_tevstr_c*, f32);
    ~dChain_packet_c();
    void draw();

public:
    /* 0x10 */ dKy_tevstr_c* mpTevStr;
    /* 0x14 */ cXyz mScale;
    /* 0x20 */ s32 mNum;
    /* 0x24 */ cXyz* mPt;
};

static Vec dummy0 = { 1.0f, 1.0f, 1.0f };
static Vec dummy1 = { 1.0f, 1.0f, 1.0f };

static u8 l_chainS3TCTex[] ALIGN_DECL(32) = {
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDE, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDE, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDE, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDE, 0xDB, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xDB, 0xB5, 0xB6, 0x00, 0x55, 0x55, 0x55, 0xDE, 0xDB, 0xB5, 0xB6, 0x00, 0x55, 0x55, 0x55,
    0xB5, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB5, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xDB, 0xB5, 0xB6, 0x00, 0x55, 0x55, 0x55, 0xDE, 0xDB, 0xB5, 0xB6, 0x00, 0x55, 0x55, 0x55,
    0xB5, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB5, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xDB, 0xB5, 0xB6, 0x00, 0x55, 0x55, 0x55, 0xDE, 0xDB, 0xB5, 0xB6, 0x00, 0x55, 0x55, 0x55,
    0xB5, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB5, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xDE, 0xDB, 0xB5, 0xB6, 0x00, 0x55, 0x55, 0x55, 0xDE, 0xDB, 0xB5, 0xB6, 0x00, 0x55, 0x55, 0x55,
    0xB5, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xB5, 0xB6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xB5, 0xB6, 0x94, 0x92, 0x00, 0x55, 0x55, 0x55, 0xB5, 0xB6, 0x94, 0x92, 0x00, 0x55, 0x55, 0x55,
    0x8C, 0x31, 0x6B, 0x2D, 0x00, 0x55, 0x55, 0x55, 0x8C, 0x31, 0x6B, 0x2D, 0x00, 0x55, 0x55, 0x55,
    0xB5, 0xB6, 0x94, 0x92, 0x00, 0x55, 0x55, 0x55, 0xB5, 0xB6, 0x94, 0x92, 0x00, 0x55, 0x55, 0x55,
    0x8C, 0x31, 0x6B, 0x2D, 0x00, 0x55, 0x55, 0x55, 0x8C, 0x31, 0x6B, 0x2D, 0x00, 0x55, 0x55, 0x55,
    0xB5, 0xB6, 0x94, 0x92, 0x00, 0x55, 0x55, 0x55, 0xB5, 0xB6, 0x94, 0x92, 0x00, 0x55, 0x55, 0x55,
    0x8C, 0x31, 0x6B, 0x2D, 0x00, 0x55, 0x55, 0x55, 0x8C, 0x31, 0x6B, 0x2D, 0x00, 0x55, 0x55, 0x55,
    0xB5, 0xB6, 0x94, 0x92, 0x00, 0x55, 0x55, 0x55, 0xB5, 0xB6, 0x94, 0x92, 0x00, 0x55, 0x55, 0x55,
    0x8C, 0x31, 0x6B, 0x2D, 0x00, 0x55, 0x55, 0x55, 0x8C, 0x31, 0x6B, 0x2D, 0x00, 0x55, 0x55, 0x55,
    0x94, 0x92, 0x6B, 0x2D, 0x55, 0x55, 0xAA, 0x00, 0x94, 0x92, 0x6B, 0x2D, 0x55, 0x55, 0xAA, 0x00,
    0xB5, 0xB6, 0x94, 0x92, 0x55, 0x55, 0x00, 0x00, 0xB5, 0xB6, 0x94, 0x92, 0x55, 0x55, 0x00, 0x00,
    0x94, 0x92, 0x6B, 0x2D, 0x55, 0x55, 0xAA, 0x00, 0x94, 0x92, 0x6B, 0x2D, 0x55, 0x55, 0xAA, 0x00,
    0xB5, 0xB6, 0x94, 0x92, 0x55, 0x55, 0x00, 0x00, 0xB5, 0xB6, 0x94, 0x92, 0x55, 0x55, 0x00, 0x00,
    0x94, 0x92, 0x6B, 0x2D, 0x55, 0x55, 0xAA, 0x00, 0x94, 0x92, 0x6B, 0x2D, 0x55, 0x55, 0xAA, 0x00,
    0xB5, 0xB6, 0x94, 0x92, 0x55, 0x55, 0x00, 0x00, 0xB5, 0xB6, 0x94, 0x92, 0x55, 0x55, 0x00, 0x00,
    0x94, 0x92, 0x6B, 0x2D, 0x55, 0x55, 0xAA, 0x00, 0x94, 0x92, 0x6B, 0x2D, 0x55, 0x55, 0xAA, 0x00,
    0xB5, 0xB6, 0x94, 0x92, 0x55, 0x55, 0x00, 0x00, 0xB5, 0xB6, 0x94, 0x92, 0x55, 0x55, 0x00, 0x00
};
static Vec l_pos[] = {
    { -2.0f, 1.522254f, -0.0f },
    { -2.0f, 1.522254f, 7.0f },
    { 2.0f, 1.522254f, -0.0f },
    { -3.5f, 0.0f, -1.5f },
    { -3.5f, 0.0f, 8.5f },
    { 3.5f, 0.0f, -1.5f },
    { -2.0f, -1.522254f, -0.0f },
    { -2.0f, -1.522254f, 7.0f },
    { 2.0f, -1.522254f, -0.0f },
    { 2.0f, 1.522254f, 7.0f },
    { 3.5f, 0.0f, 8.5f },
    { 2.0f, -1.522254f, 7.0f },

};
static f32 l_texCoord[][2] = {
    { 0.02736f, 0.041406f },
    { 0.97264f, 0.041406f },
    { 0.830848f, 0.40324f },
    { 0.169152f, 0.40324f },
    { 0.03125f, 0.0f },
    { 0.96875f, 0.0f },
    { 0.767857f, 0.494086f },
    { 0.232143f, 0.494086f },
    { 0.038462f, 0.48226f },
    { 0.038462f, 0.983522f },
    { 0.961538f, 0.48226f },
    { 0.961538f, 0.983522f },
};

#define CONST_U32(v) ((u8)((v) >> 16)), ((u8)((v) >> 8)), ((u8)((v) >> 0))
#define IMAGE_ADDR(addr) CONST_U32((u32)(addr) >> 5)

static u8 l_chainDL[0x7a] ALIGN_DECL(32) = { 0x98, 0x00, 0x06, 0x01, 0x0A, 0x07, 0x0B, 0x09, 0x08, 0x0B, 0x09, 0x02, 0x08, 0x08, 0x09, 0x98, 0x00, 0x06, 0x0B, 0x07, 0x07, 0x06, 0x0A, 0x04, 0x04, 0x05, 0x09, 0x07, 0x01, 0x06, 0x98, 0x00, 0x06, 0x08, 0x03, 0x0B, 0x02, 0x05, 0x00, 0x0A, 0x01, 0x02, 0x03, 0x09, 0x02, 0x98, 0x00, 0x06, 0x02, 0x0A, 0x08, 0x0B, 0x00, 0x08, 0x06, 0x09, 0x01, 0x08, 0x07, 0x09, 0x98, 0x00, 0x06, 0x06, 0x07, 0x08, 0x06, 0x03, 0x04, 0x05, 0x05, 0x00, 0x07, 0x02, 0x06, 0x98, 0x00, 0x06, 0x07, 0x03, 0x06, 0x02, 0x04, 0x00, 0x03, 0x01, 0x01, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, };
static u8 l_matDL[0xa8] ALIGN_DECL(32) = {
    0x61, 0x80, 0x00, 0x01, 0x3A, 0x61, 0x84, 0x00, 0x00, 0x00, 0x61, 0x88, 0xE0, 0x7C, 0x1F, 0x61, 0x94,
    IMAGE_ADDR(&l_chainS3TCTex),
    0x61, 0x30, 0x00, 0x00, 0x20, 0x61, 0x31, 0x00, 0x00, 0x20, 0x10, 0x00, 0x00, 0x10, 0x40, 0xFF, 0xFF, 0x42, 0x80, 0x08, 0x30, 0x3C, 0xF3, 0xCF, 0x00, 0x10, 0x00, 0x00, 0x10, 0x18, 0x3C, 0xF3, 0xCF, 0x00, 0x10, 0x00, 0x00, 0x10, 0x0E, 0x00, 0x00, 0x05, 0x43, 0x61, 0x28, 0x3C, 0x00, 0x00, 0x61, 0xC0, 0x08, 0x24, 0xAF, 0x61, 0xC1, 0x08, 0xFF, 0xF0, 0x61, 0x28, 0x3C, 0x00, 0x00, 0x61, 0xC2, 0x08, 0xF0, 0x8F, 0x61, 0xC3, 0x08, 0xFF, 0xC0, 0x61, 0x43, 0x00, 0x00, 0x01, 0x61, 0x40, 0x00, 0x00, 0x17, 0x61, 0x41, 0x00, 0x01, 0x0C, 0x61, 0xF3, 0x64, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x3F, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x10, 0x09, 0x00, 0x00, 0x00, 0x01, 0x61, 0x00, 0x00, 0x04, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  };

/* 800628B4-80062954       .text __ct__15dChain_packet_cFiP12dKy_tevstr_cf */
dChain_packet_c::dChain_packet_c(int num, dKy_tevstr_c* tevstr, f32 scale) {
    mNum = num;
    mScale.setall(scale);
    mpTevStr = tevstr;
    mPt = new cXyz[mNum];
}

/* 80062954-800629B0       .text __dt__15dChain_packet_cFv */
dChain_packet_c::~dChain_packet_c() {
}

/* 800629B0-80062CB0       .text draw__15dChain_packet_cFv */
void dChain_packet_c::draw() {
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_INDEX8);
    GXSetVtxDesc(GX_VA_TEX0, GX_INDEX8);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetArray(GX_VA_POS, l_pos, sizeof(*l_pos));
    GXSetArray(GX_VA_TEX0, l_texCoord, sizeof(*l_texCoord));
    dKy_GxFog_tevstr_set(mpTevStr);
    GXCallDisplayList(l_matDL, 0xa0);
    GXSetTevColorS10(GX_TEVREG0, mpTevStr->mColorC0);
    GXSetTevColor(GX_TEVREG1, mpTevStr->mColorK0);
    GXSetCurrentMtx(GX_PNMTX0);

    cXyz* points = mPt;
    f32 segmentLen = (g_regHIO.mChild[10].mFloatRegs[11] + 6.75f) * mScale.z;
    s16 angle = 0;
    cXyz pos = *points;
    for (s32 i = 0; i < mNum - 1; i++) {
        cXyz dir = points[i+1] - pos;
        f32 len = dir.abs();
        if (!dir.normalizeRS())
            continue;

        Quaternion quat;
        daObj::quat_rotBaseZ(&quat, dir);
        while (len > 0.0f) {
            mDoMtx_stack_c::transS(pos);
            mDoMtx_stack_c::quatM(&quat);
            mDoMtx_stack_c::ZrotM(angle);
            mDoMtx_stack_c::scaleM(mScale);
            mDoMtx_stack_c::revConcat(j3dSys.getViewMtx());
            GXLoadPosMtxImm(mDoMtx_stack_c::get(), GX_PNMTX0);
            GXCallDisplayList(l_chainDL, 0x60);
            len -= segmentLen;
            pos += dir * segmentLen;
            angle += 0x4000;
        }
    }
}

/* 80062CB0-80062D30       .text dChain_packet_create__FiP12dKy_tevstr_cf */
dChain_packet_c* dChain_packet_create(int p0, dKy_tevstr_c* tevstr, f32 f0) {
    dChain_packet_c* chain = new dChain_packet_c(p0, tevstr, f0);
    if (chain != NULL && chain->mPt == NULL)
        chain = NULL;
    return chain;
}
