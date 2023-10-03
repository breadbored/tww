//
// Generated by dtk
// Translation Unit: d_s_open.cpp
//

#include "f_op/f_op_scene.h"
#include "f_op/f_op_draw_iter.h"
#include "f_op/f_op_scene_mng.h"
#include "f_op/f_op_overlap_mng.h"
#include "JSystem/JKernel/JKRSolidHeap.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_audio.h"
#include "m_Do/m_Do_controller_pad.h"

class dScnOpen_message_c;
class J2DScreen;

class dScnOpen_proc_c : public dDlst_base_c {
public:
    dScnOpen_proc_c();
    virtual ~dScnOpen_proc_c();
    void proc_execute();

    /* 0x004 */ JKRExpHeap* exp_heap;
    /* 0x008 */ dScnOpen_message_c* m_message;
    /* 0x00C */ J2DScreen* m_Screen;
    /* 0x010 */ u8 pad[0x2a0];
    /* 0x2B0 */ s32 field_0x2b0;
    /* 0x010 */ u8 pad2[0x014];
};

class dScnOpen_c : public scene_class {
public:
    ~dScnOpen_c();
    void changeGameScene();
    s32 create();
    BOOL draw();
    BOOL execute();

    /* 0x1C4 */ request_of_phase_process_class mPhs;
    /* 0x1CC */ JKRSolidHeap* solid_heap;
    /* 0x1D0 */ dScnOpen_proc_c* mpProc;
    /* 0x1D4 */ u8 field_0x1d4;
};

/* 80232A68-80232BC4       .text create__10dScnOpen_cFv */
s32 dScnOpen_c::create() {
    dComIfGp_offEnableNextStage();
    mpProc = NULL;

    s32 rt = dComIfG_resLoad(&mPhs, "Opening");
    if (rt == cPhs_COMPLEATE_e) {
        solid_heap = mDoExt_createSolidHeapFromGameToCurrent(0x20000, 0);
        JUT_ASSERT(0x3b, solid_heap != 0);
        mpProc = new dScnOpen_proc_c();
        field_0x1d4 = NULL;
        mDoExt_restoreCurrentHeap();
        mDoExt_adjustSolidHeap(solid_heap);
        // mDoGph_gInf_c::setTickRate();
    } else if (rt == cPhs_ERROR_e) {
        JUT_ASSERT(0x48, rt == cPhs_COMPLEATE_e);
    }
    return rt;
}

/* 80232BC4-80232CAC       .text execute__10dScnOpen_cFv */
BOOL dScnOpen_c::execute() {
    if (mpProc->field_0x2b0 >= 5 && !fopOvlpM_IsPeek() && !dComIfG_resetToOpening(this)) {
        if (fpcM_GetName(this) == PROC_OPEN2_SCENE && (CPad_CHECK_TRIG_A(0) || CPad_CHECK_TRIG_B(0) || CPad_CHECK_TRIG_START(0))) {
            field_0x1d4 = 1;
            mDoAud_bgmStop(20);
        }

        if (field_0x1d4 == 1 && !mDoAud_isUsedHeapForStreamBuffer())
            dComIfG_changeOpeningScene(this, PROC_OPENING2_SCENE);
    }

    mpProc->proc_execute();
    if (mpProc->field_0x2b0 == 44)
        changeGameScene();

    return TRUE;
}

/* 80232CAC-80232D38       .text draw__10dScnOpen_cFv */
BOOL dScnOpen_c::draw() {
    dComIfGd_setWindow(dComIfGp_getWindow(0));
    dComIfGd_setViewPort(dComIfGp_getWindow(0)->getViewPort());
    for (create_tag_class* pTag = fopDwIt_Begin(); pTag != NULL; pTag = fopDwIt_Next(pTag))
        fpcM_Draw(pTag->mpTagData);
    dComIfGd_set2DOpa(mpProc);
    return TRUE;
}

/* 80232D38-80232DD8       .text __dt__10dScnOpen_cFv */
dScnOpen_c::~dScnOpen_c() {
    if (mpProc != NULL)
        delete mpProc;
    if (solid_heap != NULL)
        mDoExt_destroySolidHeap(solid_heap);
    dComIfG_resDelete(&mPhs, "Opening");
    g_dComIfG_gameInfo.play.field_0x4841 = 0;
}

/* 80232DD8-80232E6C       .text changeGameScene__10dScnOpen_cFv */
void dScnOpen_c::changeGameScene() {
    if (fopOvlpM_IsPeek())
        return;

    if (fpcM_GetName(this) == PROC_OPEN2_SCENE) {
        dComIfG_changeOpeningScene(this, PROC_OPENING2_SCENE);
    } else {
        if (fopScnM_ChangeReq(this, PROC_PLAY_SCENE, 0, 5)) {
            dComIfGs_setRestartRoomParam(0);
            mDoAud_setSceneName(dComIfGp_getNextStageName(), dComIfGp_getNextStageRoomNo(), dComIfGp_getNextStageLayer());
        }
    }
}

/* 80232E6C-80232E8C       .text dScnOpen_Draw__FP10dScnOpen_c */
BOOL dScnOpen_Draw(dScnOpen_c* i_this) {
    return i_this->draw();
}

/* 80232E8C-80232EAC       .text dScnOpen_Execute__FP10dScnOpen_c */
BOOL dScnOpen_Execute(dScnOpen_c* i_this) {
    return i_this->execute();
}

/* 80232EAC-80232EB4       .text dScnOpen_IsDelete__FP10dScnOpen_c */
BOOL dScnOpen_IsDelete(dScnOpen_c* i_this) {
    return TRUE;
}

/* 80232EB4-80232EDC       .text dScnOpen_Delete__FP10dScnOpen_c */
BOOL dScnOpen_Delete(dScnOpen_c* i_this) {
    i_this->~dScnOpen_c();
    return TRUE;
}

/* 80232EDC-80232EFC       .text dScnOpen_Create__FP11scene_class */
s32 dScnOpen_Create(scene_class* i_scn) {
    dScnOpen_c* i_this = (dScnOpen_c*)i_scn;
    return i_this->create();
}

static scene_method_class l_dScnOpen_Method = {
    (process_method_func)dScnOpen_Create,
    (process_method_func)dScnOpen_Delete,
    (process_method_func)dScnOpen_Execute,
    (process_method_func)dScnOpen_IsDelete,
    (process_method_func)dScnOpen_Draw,
};

extern scene_process_profile_definition g_profile_OPEN_SCENE = {
    fpcLy_ROOT_e,
    1,
    fpcPi_CURRENT_e,
    PROC_OPEN_SCENE,
    &g_fpcLf_Method.mBase,
    sizeof(dScnOpen_c),
    0,
    0,
    &g_fopScn_Method.mBase,
    &l_dScnOpen_Method,
    NULL,
};

extern scene_process_profile_definition g_profile_OPEN2_SCENE = {
    fpcLy_ROOT_e,
    1,
    fpcPi_CURRENT_e,
    PROC_OPEN2_SCENE,
    &g_fpcLf_Method.mBase,
    sizeof(dScnOpen_c),
    0,
    0,
    &g_fopScn_Method.mBase,
    &l_dScnOpen_Method,
    NULL,
};
