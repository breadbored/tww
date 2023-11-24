#ifndef D_A_BPW_H
#define D_A_BPW_H

#include "f_op/f_op_actor.h"
#include "d/d_cc_d.h"
#include "d/d_bg_s_acch.h"
#include "d/d_bg_s_acch.h"
#include "d/d_particle.h"
#include "m_Do/m_Do_ext.h"

class bpw_class : public fopAc_ac_c {
public:
    /* 0x2AC */ u8 m2AC[0x2B4 - 0x2AC];
    /* 0x2B4 */ mDoExt_McaMorf* m2B4;
    /* 0x2B8 */ u8 m2B8[0x2BC - 0x2B8];
    /* 0x2BC */ mDoExt_brkAnm* mBrkAnim;
    /* 0x2C0 */ mDoExt_baseAnm* m2C0;
    /* 0x2C4 */ mDoExt_baseAnm* m2C4;
    /* 0x2C8 */ mDoExt_baseAnm* m2C8;
    /* 0x2CC */ mDoExt_baseAnm* m2CC;
    /* 0x2D0 */ mDoExt_brkAnm* m2D0;
    /* 0x2D4 */ u8 m2D4[0x304 - 0x2D4];
    /* 0x304 */ cXyz m304[3];
    /* 0x328 */ cXyz m328[3];
    /* 0x34C */ f32 m34C;
    /* 0x350 */ f32 m350;
    /* 0x354 */ node_class* m354;
    /* 0x358 */ f32 m358;
    /* 0x35C */ f32 m35C;
    /* 0x360 */ f32 m360;
    /* 0x364 */ u8 m364[0x370 - 0x364];
    /* 0x370 */ cXyz m370;
    /* 0x37C */ u32 m37C;
    /* 0x380 */ u32 m380;
    /* 0x384 */ u32 m384;
    /* 0x388 */ f32 m388;
    /* 0x38C */ u8 m38C[0x390 - 0x38C];
    /* 0x390 */ f32 m390;
    /* 0x394 */ u8 m394[0x3A0 - 0x394];
    /* 0x3A0 */ cXyz z;
    /* 0x3AC */ f32 m3AC;
    /* 0x3B0 */ u32 m3B0;
    /* 0x3B4 */ f32 m3B4;
    /* 0x3B8 */ f32 m3B8;
    /* 0x3BC */ f32 m3BC;
    /* 0x3C0 */ f32 m3C0;
    /* 0x3C4 */ u8 m3C4[0x3D6 - 0x3C4];
    /* 0x3D6 */ s16 m3D6;
    /* 0x3D8 */ s16 m3D8;
    /* 0x3DA */ u16 m3DA;
    /* 0x3DC */ u8 mUnknownParam1;
    /* 0x3DD */ u8 mUnknownParam2;
    /* 0x3DE */ u8 mUnknownParam3;
    /* 0x3DF */ u8 m3DF;
    /* 0x3E0 */ u8 m3E0;
    /* 0x3E1 */ u8 m3E1[0x3E2 - 0x3E1];
    /* 0x3E2 */ s8 m3E2;
    /* 0x3E3 */ u8 m3E3[0x3E6 - 0x3E3];
    /* 0x3E6 */ u8 m3E6;
    /* 0x3E7 */ s8 m3E7;
    /* 0x3E8 */ u8 m3E8[0x3EB - 0x3E8];
    /* 0x3EB */ u8 m3EB;
    /* 0x3EC */ f32 m3EC;
    /* 0x3F0 */ f32 m3F0;
    /* 0x3F4 */ s16 m3F4;
    /* 0x3F6 */ s16 m3F6;
    /* 0x3F8 */ int m3F8;
    /* 0x3FC */ int m3FC;
    /* 0x400 */ u32 m400;
    /* 0x404 */ int m404;
    /* 0x408 */ u16 m408;
    /* 0x40A */ u8 m40A[0x40C - 0x40A];
    /* 0x40C */ cXyz m40C;
    /* 0x418 */ u32 m418;
    /* 0x41C */ u32 m41C;
    /* 0x420 */ u32 m420;
    /* 0x424 */ f32 m424;
    /* 0x428 */ f32 m428;
    /* 0x42C */ f32 m42C;
    /* 0x430 */ u8 m430[0x43C - 0x430];
    /* 0x43C */ u32 m43C;
    /* 0x440 */ f32 m440;
    /* 0x444 */ u16 m444;
    /* 0x446 */ s16 m446;
    /* 0x448 */ u8 m448[0x44C - 0x448];
    /* 0x44C */ u16 m44C;
    /* 0x44E */ s16 mSomeCountdownTimers[10];
    /* 0x462 */ s16 m462;
    /* 0x464 */ u16 m464;
    /* 0x466 */ u8 m466[0x474 - 0x466];
    /* 0x474 */ s16 m474;
    /* 0x476 */ s16 m476;
    /* 0x478 */ u16 m478;
    /* 0x47A */ u16 m47A;
    /* 0x47C */ s16 m47C;
    /* 0x47E */ s16 m47E;
    /* 0x480 */ u16 m480;
    /* 0x482 */ s16 m482;
    /* 0x484 */ s16 m484;
    /* 0x486 */ u8 m486[0x48C - 0x486];
    /* 0x48C */ f32 m48C;
    /* 0x490 */ u32 m490;
    /* 0x494 */ f32 m494;
    /* 0x498 */ u32 m498;
    /* 0x49C */ u32 m49C;
    /* 0x4A0 */ u32 m4A0;
    /* 0x4A4 */ u32 m4A4;
    /* 0x4A8 */ f32 m4A8;
    /* 0x4AC */ int mChildPoeIds[15];
    /* 0x4E8 */ u8 m4E8[0x4EC - 0x4E8];
    /* 0x4EC */ u32 m4EC;
    /* 0x4F0 */ u32 m4F0;
    /* 0x4F4 */ u32 m4F4;
    /* 0x4F8 */ u16 m4F8;
    /* 0x4FA */ u16 m4FA;
    /* 0x4FC */ u16 m4FC;
    /* 0x4FE */ u8 m4FE[0x500 - 0x4FE];
    /* 0x500 */ u32 m500;
    /* 0x504 */ u32 m504;
    /* 0x508 */ u8 m508[0x50C - 0x508];
    /* 0x50C */ dPa_smokeEcallBack m50C;
    /* 0x52C */ dPa_followEcallBack m52C;
    /* 0x540 */ dPa_followEcallBack m540;
    /* 0x554 */ dPa_followEcallBack m554;
    /* 0x568 */ dPa_followEcallBack m568;
    /* 0x57C */ dPa_followEcallBack m57C;
    /* 0x590 */ dPa_followEcallBack m590;
    /* 0x5A4 */ dPa_followEcallBack m5A4;
    /* 0x5B8 */ dPa_followEcallBack m5B8;
    /* 0x5CC */ dPa_followEcallBack m5CC;
    /* 0x5E0 */ dPa_smokeEcallBack m5E0[4];
    /* 0x660 */ f32 m660;
    /* 0x664 */ f32 m664;
    /* 0x668 */ f32 m668;
    /* 0x66C */ u8 m66C[0x678 - 0x66C];
    /* 0x678 */ u16 m678;
    /* 0x67A */ s16 m67A;
    /* 0x67C */ s16 m67C;
    /* 0x67E */ u8 m67E[0x684 - 0x67E];
    /* 0x684 */ s16 m684;
    /* 0x686 */ u8 m686[0x688 - 0x686];
    /* 0x688 */ dBgS_AcchCir m688;
    /* 0x6C8 */ dBgS_Acch m6C8;
    /* 0x88C */ u8 m88C[0x8A4 - 0x88C];
    /* 0x8A4 */ u32 m8A4;
    /* 0x8A8 */ dCcD_GStts m8A8;
    /* 0x8C8 */ dCcD_GObjInf m8C8;
    /* 0x9C0 */ u8 m9C0[0x9D8 - 0x9C0];
    /* 0x9D8 */ u32 m9D8;
    /* 0x9DC */ u32 m9DC;
    /* 0x9E0 */ u8 m9E0[0x9F0 - 0x9E0];
    /* 0x9F0 */ u32 m9F0;
    /* 0x9F4 */ dCcD_GObjInf m9F4;
    /* 0xAEC */ u8 mAEC[0xB04 - 0xAEC];
    /* 0xB04 */ u32 mB04;
    /* 0xB08 */ u32 mB08;
    /* 0xB0C */ u8 mB0C[0xB1C - 0xB0C];
    /* 0xB1C */ u32 mB1C;
    /* 0xB20 */ dCcD_GObjInf mB20;
    /* 0xC18 */ u8 mC18[0xC30 - 0xC18];
    /* 0xC30 */ u32 mC30;
    /* 0xC34 */ u32 mC34;
    /* 0xC38 */ u8 mC38[0xC48 - 0xC38];
    /* 0xC48 */ u32 mC48;
    /* 0xC4C */ dCcD_GObjInf mC4C;
    /* 0xD44 */ u8 mD44[0xD5C - 0xD44];
    /* 0xD5C */ u32 mD5C;
    /* 0xD60 */ u32 mD60;
    /* 0xD64 */ u8 mD64[0xD74 - 0xD64];
    /* 0xD74 */ u32 mD74;
    /* 0xD78 */ u8 mD78[0xD80 - 0xD78];
};

#endif /* D_A_BPW_H */
