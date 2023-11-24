#ifndef D_A_PZ_H
#define D_A_PZ_H

#include "f_op/f_op_actor.h"
#include "m_Do/m_Do_ext.h"
#include "c/c_damagereaction.h"
#include "c/c_damagereaction.h"
#include "SSystem/SComponent/c_phase.h"
#include "JSystem/J3DGraphAnimator/J3DNode.h"

class daPz_c : public fopAc_ac_c {
public:
    void getRightHandMatrix() {}
    void isAnm(signed char) {}
    void isEyeAnm(signed char) {}
    void modeProcInit(int) {}
    void setAfraid() {}
    void setDown() {}
    void setMove() {}
    void setStand() {}

    void _nodeHeadControl(J3DNode*, J3DModel*);
    void _nodeWaistControl(J3DNode*, J3DModel*);
    void _nodeWaist2Control(J3DNode*, J3DModel*);
    void _nodeSkirtControl(J3DNode*, J3DModel*);
    void bodyCreateHeap();
    void bowCreateHeap();
    void _createHeap();
    void getGndPos();
    void checkEyeArea(cXyz&);
    void getMsg();
    void next_msgStatus(unsigned long*);
    void anmAtr(unsigned short);
    void eventOrder();
    void checkOrder();
    void setFallSplash();
    void setHeadSplash();
    void setRipple();
    void setJntStatus();
    void demo();
    void checkTgHit();
    void getArg();
    void setAttention();
    void setBowAnm(signed char, bool);
    void setBowString(bool);
    void setAnm(signed char, bool, int);
    void setAnmRunSpeed();
    void setEyeBtp(int);
    void setEyeBtk(int);
    void setEyeAnm(signed char);
    void ctrlEye();
    void playEyeAnm();
    void setMtx();
    void modeWaitInit();
    void modeWait();
    void modeMoveInit();
    void modeMove();
    void modeAttackWaitInit();
    void modeAttackWait();
    void modeAttackInit();
    void modeAttack();
    void modeDefendInit();
    void modeDefend();
    void modeDownInit();
    void modeDown();
    void modeAfraidInit();
    void modeAfraid();
    void modeSideStepInit();
    void modeSideStep();
    void modeBackStepInit();
    void modeBackStep();
    void modeTalkInit();
    void modeTalk();
    void modeFollowInit();
    void modeFollow();
    void modeProc(daPz_c::Proc_e, int);
    void _execute();
    void bowDraw();
    void bodyDraw();
    void drawShadow();
    void _draw();
    void bodyCreateInit();
    void createInit();
    void _create();
    void _delete();

public:
    /* 0x06C4 */ int mMode;
    /* 0x06C8 */ u8 m06C8[0x06D3 - 0x06C8];
    /* 0x06D3 */ u8 m06D3;
    /* 0x06D4 */ u8 m06D4[0x06D5 - 0x06D4];
    /* 0x06D5 */ u8 mCurEye;
    /* 0x06D6 */ u8 m06D6[0x073E - 0x06D6];
    /* 0x073E */ u8 mbEyesFollowGanondorf;
    /* 0x073F */ u8 m073F;
    /* 0x0740 */ u8 m0740[0x076C - 0x0740];
    /* 0x076C */ request_of_phase_process_class mPhs;
    /* 0x0774 */ u32 m0774;
    /* 0x0778 */ mDoExt_invisibleModel mInvisibleModel;
    /* 0x0780 */ dKy_tevstr_c mTevstr;
    /* 0x0830 */ u8 m0830[0x08A8 - 0x0830];
    /* 0x08A8 */ J3DMaterialAnm* m08A8[1];
    /* 0x08AC */ u8 m08AC[0x08B0 - 0x08AC];
    /* 0x08B0 */ int m08B0;
    /* 0x08B4 */ u8 m08B4[0x08C4 - 0x08B4];
    /* 0x08C4 */ cXyz m08C4;
    /* 0x08D0 */ u8 m08D0[0x0920 - 0x08D0];
    /* 0x0920 */ int m0920;
    /* 0x0924 */ u8 m0924[0x0928 - 0x0924];
    /* 0x0928 */ enemyice mEventIce;
    /* 0x0CE0 */ enemyfire mEnemyFire;
    /* 0x0F08 */ u8 m0F08[0x0F48 - 0x0F08];
    /* 0x0F48 */ u8 m0F48;
    /* 0x0F49 */ u8 m0F49[0x0F4C - 0x0F49];
    /* 0x0F4C */ cXyz mGanondorfPosCurrent;
    /* 0x0F58 */ cXyz mGanondorfPos4;
    /* 0x0F64 */ u8 mbHasGanondorf;
    /* 0x0F65 */ u8 m0F65;
    /* 0x0F66 */ u8 m0F66[0x0F7C - 0x0F66];
    /* 0x0F7C */ int m0F7C;
    /* 0x0F80 */ u8 m0F80;
    /* 0x0F81 */ u8 m0F81[0x0F82 - 0x0F81];
    /* 0x0F82 */ u8 m0F82;
    /* 0x0F83 */ u8 m0F83[0x0F84 - 0x0F83];
    /* 0x0F84 */ int mArg;
    /* 0x0F88 */ u8 m0F88;
    /* 0x0F89 */ u8 m0F89[0x0F8C - 0x0F89];
    /* 0x0F8C */ mDoExt_McaMorf* mpBowMcaMorf;
    /* 0x0F90 */ mDoExt_brkAnm mBrkAnm;
    /* 0x0FA8 */ mDoExt_btkAnm mBtkAnm;
    /* 0x0FBC */ mDoExt_btpAnm mBtpAnm;
    /* 0x0FD0 */ u8 m0FD0[0x1049 - 0x0FD0];
};

#endif /* D_A_PZ_H */
