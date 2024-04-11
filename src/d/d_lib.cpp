//
// Generated by dtk
// Translation Unit: d_lib.cpp
//

#include "d/d_lib.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_sea.h"
#include "m_Do/m_Do_mtx.h"
#include "SSystem/SComponent/c_math.h"
#include "m_Do/m_Do_controller_pad.h"

Quaternion ZeroQuat = {0.0f, 0.0f, 0.0f, 1.0f};

/* 80057000-800570CC       .text dLib_setCirclePath__FP18dLib_circle_path_c */
void dLib_setCirclePath(dLib_circle_path_c* path) {
    path->mAngle += path->mAngleSpeed;
    f32 rad = path->mRadius + path->mWobbleAmplitude * cM_ssin(path->mAngle);
    mDoMtx_stack_c::transS(path->mTranslation);
    mDoMtx_stack_c::YrotM(path->mAngle);
    mDoMtx_stack_c::transM(rad, 0.0f, 0.0f);
    mDoMtx_stack_c::multVecZero(&path->mPos);
}

/* 800570CC-8005716C       .text dLib_getWaterY__FR4cXyzR12dBgS_ObjAcch */
f32 dLib_getWaterY(cXyz& pos, dBgS_ObjAcch& acch) {
    BOOL waterHit = acch.ChkWaterHit();
    f32 waterHeight = waterHit ? acch.m_wtr.GetHeight() : -1e+09f;
    if (daSea_ChkArea(pos.x, pos.z)) {
        f32 seaHeight = daSea_calcWave(pos.x, pos.z);
        if (!waterHit || seaHeight > waterHeight) {
            return seaHeight;
        }
    }
    return waterHit ? waterHeight : 0.0f;
}

/* 8005716C-80057368       .text dLib_waveRot__FP3VecfP11dLib_wave_c */
void dLib_waveRot(Vec*, f32, dLib_wave_c*) {
    /* Nonmatching */
}

/* 80057368-8005746C       .text dLib_debugDrawAxis__FRA3_A4_ff */
void dLib_debugDrawAxis(Mtx& mtx, f32 length) {
    cXyz r1_98(length, 0.0f, 0.0f);
    cXyz r1_8c(0.0f, length, 0.0f);
    cXyz r1_80(0.0f, 0.0f, length);
    cXyz r1_74(0.0f, 0.0f, 0.0f);
    cXyz r1_68(0.0f, 0.0f, 0.0f);
    cXyz r1_5c(0.0f, 0.0f, 0.0f);
    cXyz r1_50;
    cXyz r1_4c;
    cXyz r1_40;
    cXyz r1_34;
    cXyz r1_28;
    cXyz r1_1c;
    cXyz r1_14;
    cXyz r1_08;
    mDoMtx_stack_c::copy(mtx);
    mDoMtx_stack_c::multVecZero(&r1_08);
    mDoMtx_stack_c::multVec(&r1_98, &r1_50);
    mDoMtx_stack_c::multVec(&r1_8c, &r1_40);
    mDoMtx_stack_c::multVec(&r1_80, &r1_34);
    mDoMtx_stack_c::multVec(&r1_74, &r1_28);
    mDoMtx_stack_c::multVec(&r1_68, &r1_1c);
    mDoMtx_stack_c::multVec(&r1_5c, &r1_14);
    
    // The rest of this function may have been commented out for release builds.
}

/* 8005746C-80057510       .text dLib_debugDrawFan__FR4cXyzssfRC8_GXColor */
void dLib_debugDrawFan(cXyz& center, s16 angleY, s16 fanSpreadAngle, f32 radius, const GXColor& color) {
    int angle1 = angleY + fanSpreadAngle;
    cXyz corner1(center);
    corner1.z += cM_scos(angle1) * radius;
    corner1.x += cM_ssin(angle1) * radius;
    
    int angle2 = angleY - fanSpreadAngle;
    cXyz corner2(center);
    corner2.z += cM_scos(angle2) * radius;
    corner2.x += cM_ssin(angle2) * radius;
    
    // The rest of this function may have been commented out for release builds.
}

/* 80057510-800575E0       .text dLib_brkInit__FP12J3DModelDataP13mDoExt_brkAnmPCci */
bool dLib_brkInit(J3DModelData* modelData, mDoExt_brkAnm* anm, const char* arcName, int fileno) {
    J3DAnmTevRegKey* brk = (J3DAnmTevRegKey*)dComIfG_getObjectRes(arcName, fileno);
    JUT_ASSERT(0xae, brk != 0);
    if (anm->init(modelData, brk, 1, J3DFrameCtrl::LOOP_ONCE_e, 1.0f, 0, -1, false, 0) == 0)
        return false;
    return true;
}

/* 800575E0-800576B0       .text dLib_btkInit__FP12J3DModelDataP13mDoExt_btkAnmPCci */
bool dLib_btkInit(J3DModelData* modelData, mDoExt_btkAnm* anm, const char* arcName, int fileno) {
    J3DAnmTextureSRTKey* btk = (J3DAnmTextureSRTKey*)dComIfG_getObjectRes(arcName, fileno);
    JUT_ASSERT(0xbb, btk != 0);
    if (anm->init(modelData, btk, 1, J3DFrameCtrl::LOOP_ONCE_e, 1.0f, 0, -1, false, 0) == 0)
        return false;
    return true;
}

/* 800576B0-80057844       .text dLib_setAnm__FPCcP14mDoExt_McaMorfPScPScPScPC14dLib_anm_idx_cPC14dLib_anm_prm_cb */
void dLib_setAnm(const char* arcName, mDoExt_McaMorf* morf, s8*, s8*,
                 s8*, const dLib_anm_idx_c*, const dLib_anm_prm_c* anmPrmTbl, bool param_8)
{
    /* Nonmatching */
}

/* 80057844-80057988       .text dLib_bcks_setAnm__FPCcP14mDoExt_McaMorfPScPScPScPCiPC14dLib_anm_prm_cb */
void dLib_bcks_setAnm(const char* arcName, mDoExt_McaMorf* morf, s8* pBckIdx, s8* pPrmIdx,
                      s8* param_5, const int* bcksTbl, const dLib_anm_prm_c* anmPrmTbl, bool param_8)
{
    if ((*param_5 != *pPrmIdx && anmPrmTbl[*pPrmIdx].mBckIdx != -1) || param_8 == true) {
        *pBckIdx = anmPrmTbl[*pPrmIdx].mBckIdx;
        J3DAnmTransform* bck = (J3DAnmTransform*)dComIfG_getObjectRes(arcName, bcksTbl[*pBckIdx]);
        morf->setAnm(bck, anmPrmTbl[*pPrmIdx].mLoopMode, anmPrmTbl[*pPrmIdx].mMorf, anmPrmTbl[*pPrmIdx].mPlaySpeed, 0.0f, -1.0f, NULL);
    }
    
    *param_5 = *pPrmIdx;
    
    if (morf->isStop()) {
        if (anmPrmTbl[*pPrmIdx].mNextPrmIdx != -1 && anmPrmTbl[*pPrmIdx].mLoopMode == J3DFrameCtrl::LOOP_ONCE_e) {
            *pPrmIdx = anmPrmTbl[*pPrmIdx].mNextPrmIdx;
        }
    }
}

/* 80057988-80057A14       .text dLib_scaleAnime__FPfPfiPifff */
void dLib_scaleAnime(f32* o_value, f32* p_targets, int targetNum, int* p_targetIdx, f32 scale, f32 maxStep, f32 minStep) {
    if (*p_targetIdx < targetNum) {
        f32 temp = cLib_addCalc(o_value, p_targets[*p_targetIdx], scale, maxStep, minStep);
        if (temp != 0.0f) {
            return;
        }
        (*p_targetIdx)--;
        if (*p_targetIdx < 0) {
            *p_targetIdx = 0;
        }
    } else {
        (*p_targetIdx)--;
    }
}

/* 80057A14-80057A30       .text dLib_getPosFromMtx__FPA4_fP4cXyz */
void dLib_getPosFromMtx(MtxP mtx, cXyz* pos) {
    pos->set(mtx[0][3], mtx[1][3], mtx[2][3]);
}

/* 80057A30-80057AA4       .text dLib_pathInfo__FPP5dPathUc */
bool dLib_pathInfo(dPath** dst, u8 no) {
    dStage_dPath_c * path = dComIfGp_getStage().getPathInf();
    if (path != NULL) {
        *dst = path->m_path + no;
        return true;
    } else {
        return false;
    }
}

/* 80057AA4-80057D1C       .text dLib_pathMove__FP4cXyzPScP5dPathfPFP4cXyzP4cXyzP4cXyzPv_iPv */
void dLib_pathMove(cXyz* pos, s8* pPntNo, dPath* pPath, f32 speed, int (*pCallBack)(cXyz*, cXyz*, cXyz*, void*), void* pCallBackData) {
    /* Nonmatching */
    s8 pnt_no = *pPntNo;
    s8 pnt_next_no = pnt_no > (pPath->m_num - 1) ? 0 : pnt_no + 1;
    cXyz pnt_pos = pPath->mpPnt[pnt_no].mPos;
    cXyz pnt_next_pos = pPath->mpPnt[pnt_next_no].mPos;

    cXyz move = (pnt_next_pos - pnt_pos).normZP();
    if (pCallBack == NULL) {
        *pos = *pos + move * speed;
        f32 dist = pnt_pos.abs(*pos);
        f32 pnt_dist = pnt_pos.abs(pnt_next_pos);
        if (dist > pnt_dist) {
            *pPntNo = pnt_next_no;
            *pos = pnt_next_pos;
        }
    } else {
        if (pCallBack(pos, &pnt_pos, &pnt_next_pos, pCallBackData))
            *pPntNo = pnt_next_no;
    }
}

/* 80057D1C-80057EC0       .text dLib_setNextStageBySclsNum__FUcSc */
void dLib_setNextStageBySclsNum(u8 i_sclsnum, s8 room_no) {
    stage_scls_info_dummy_class* sclsinfo;
    if (room_no == -1) {
        sclsinfo = dComIfGp_getStageSclsInfo();
    } else {
        JUT_ASSERT(452, 0 <= room_no && room_no < 64);
        sclsinfo = dComIfGp_roomControl_getStatusRoomDt(room_no)->getSclsInfo();
    }
    if (sclsinfo == NULL) {
        return;
    }
    
    stage_scls_info_class* scls_data = sclsinfo->m_entries;
    JUT_ASSERT(462, scls_data != 0);
    JUT_ASSERT(463, 0 <= i_sclsnum && i_sclsnum < sclsinfo->num);
    
    stage_scls_info_class* scls_entry = &scls_data[i_sclsnum];
    s32 wipe = dStage_sclsInfo_getWipe(scls_entry);
    wipe = wipe == 0xFF ? 0 : wipe;
    dComIfGp_setNextStage(scls_entry->mStage, scls_entry->mStart, scls_entry->mRoom, -1, 0.0f, 0, TRUE, wipe);
}

/* 80057EC0-80057F30       .text dLib_setFirstMsg__FUsUlUl */
u32 dLib_setFirstMsg(u16 eventBit, u32 firstMsgNo, u32 secondMsgNo) {
    if (!dComIfGs_isEventBit(eventBit)) {
        dComIfGs_onEventBit(eventBit);
        return firstMsgNo;
    } else {
        return secondMsgNo;
    }
}

/* 80057F30-80057F78       .text dLib_checkPlayerInCircle__F4cXyzff */
bool dLib_checkPlayerInCircle(cXyz center, f32 radius, f32 halfHeight) {
    fopAc_ac_c* link = dComIfGp_getLinkPlayer();
    return dLib_checkActorInCircle(center, link, radius, halfHeight);
}

/* 80057F78-80058098       .text dLib_checkActorInCircle__F4cXyzP10fopAc_ac_cff */
bool dLib_checkActorInCircle(cXyz center, fopAc_ac_c* actor, f32 radius, f32 halfHeight) {
    f32 distXZ = (center - actor->current.pos).absXZ();
    f32 distY = fabsf(center.y - actor->current.pos.y);
    if (distXZ < radius && distY < halfHeight) {
        return true;
    }
    return false;
}

/* 80058098-8005820C       .text dLib_checkActorInFan__F4cXyzP10fopAc_ac_cssff */
bool dLib_checkActorInFan(cXyz center, fopAc_ac_c* actor, s16 angleY, s16 fanSpreadAngle, f32 radius, f32 halfHeight) {
    f32 distXZ = (center - actor->current.pos).absXZ();
    f32 distY = fabsf(center.y - actor->current.pos.y);
    s16 targetY = cLib_targetAngleY(&center, &actor->current.pos);
    int angleDistY = cLib_distanceAngleS(angleY, targetY);
    if (distXZ < radius && distY < halfHeight && angleDistY < fanSpreadAngle) {
        return true;
    }
    return false;
}

/* 8005820C-80058250       .text __ct__9STControlFssssffss */
STControl::STControl(s16, s16, s16, s16, f32, f32, s16, s16) {
    /* Nonmatching */
}

/* 80058250-80058274       .text setWaitParm__9STControlFssssffss */
void STControl::setWaitParm(s16, s16, s16, s16, f32, f32, s16, s16) {
    /* Nonmatching */
}

/* 80058274-800582B0       .text init__9STControlFv */
void STControl::init() {
    field_0x0e = 0;
    field_0x10 = 0;
    field_0x0d = 0;
    field_0x0c = 0;
    field_0x22 = 0;
    field_0x18 = field_0x12;
    field_0x1a = field_0x12;
    field_0x1e = field_0x1c;
    field_0x20 = field_0x1c;
}

/* 800582B0-800582D8       .text Xinit__9STControlFv */
void STControl::Xinit() {
    /* Nonmatching */
}

/* 800582D8-80058300       .text Yinit__9STControlFv */
void STControl::Yinit() {
    /* Nonmatching */
}

/* 80058300-80058310       .text getValueStick__9STControlFv */
f32 STControl::getValueStick() {
    return g_mDoCPd_cpadInfo[0].mMainStickValue;
}

/* 80058310-80058320       .text getAngleStick__9STControlFv */
s16 STControl::getAngleStick() {
    return g_mDoCPd_cpadInfo[0].mMainStickAngle;
}

/* 80058320-80058330       .text getValueStick__10CSTControlFv */
f32 CSTControl::getValueStick() {
    return g_mDoCPd_cpadInfo[0].mCStickValue;
}

/* 80058330-80058340       .text getAngleStick__10CSTControlFv */
s16 CSTControl::getAngleStick() {
    return g_mDoCPd_cpadInfo[0].mCStickAngle;
}

/* 80058340-800585D0       .text checkTrigger__9STControlFv */
bool STControl::checkTrigger() {
    /* Nonmatching */
}

/* 800585D0-8005863C       .text checkLeftTrigger__9STControlFv */
bool STControl::checkLeftTrigger() {
    /* Nonmatching */
}

/* 8005863C-800586A8       .text checkRightTrigger__9STControlFv */
bool STControl::checkRightTrigger() {
    /* Nonmatching */
}

/* 800586A8-80058714       .text checkUpTrigger__9STControlFv */
bool STControl::checkUpTrigger() {
    /* Nonmatching */
}

/* 80058714-80058780       .text checkDownTrigger__9STControlFv */
bool STControl::checkDownTrigger() {
    /* Nonmatching */
}

/* 80058780-80058834       .text dLib_getIplDaysFromSaveTime__Fv */
u32 dLib_getIplDaysFromSaveTime() {
    /* Nonmatching */
    OSTime dateIpl = dComIfGs_getDateIpl();
    if (dateIpl == 0)
        return 0;

    OSTime curTime = OSGetTime();
    return (curTime - dateIpl);
}

/* 80058834-80058910       .text dLib_get_QuatFromTriangle__FP4cXyzP4cXyzP4cXyz */
void dLib_get_QuatFromTriangle(cXyz*, cXyz*, cXyz*) {
    /* Nonmatching */
}

/* 80058910-800589A8       .text dLib_calc_QuatFromTriangle__FP10QuaternionfP4cXyzP4cXyzP4cXyz */
void dLib_calc_QuatFromTriangle(Quaternion*, f32, cXyz*, cXyz*, cXyz*) {
    /* Nonmatching */
}

