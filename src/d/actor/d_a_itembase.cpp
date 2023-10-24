//
// Generated by dtk
// Translation Unit: d_a_itembase.cpp
//

#include "d/actor/d_a_itembase.h"
#include "d/d_item.h"
#include "d/d_item_data.h"
#include "d/d_resorce.h"
#include "d/d_drawlist.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_graphic.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_item_data.h"
#include "d/d_com_inf_game.h"
#include "d/actor/d_a_player_main.h"
#include "dolphin/types.h"

/* 800F8A14-800F8A3C       .text DeleteBase__12daItemBase_cFPCc */
BOOL daItemBase_c::DeleteBase(const char* resName) {
    dComIfG_resDelete(&mPhs, resName);
    return TRUE;
}

/* 800F8A3C-800F8A44       .text clothCreate__12daItemBase_cFv */
BOOL daItemBase_c::clothCreate() {
    return TRUE;
}

/* 800F8A44-800F9074       .text CreateItemHeap__12daItemBase_cFPCcsssssss */
BOOL daItemBase_c::CreateItemHeap(const char* resName, short resIdx, short btkAnm1, short btkAnm2, short brkAnm1, short brkAnm2, short bckAnm, short) {
    JUT_ASSERT(78, 0 <= m_itemNo && m_itemNo <= 255);
    
    J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes(resName, resIdx);
    JUT_ASSERT(85, modelData != 0);
    
    mpModel = mDoExt_J3DModel__create(modelData, 0, 0x11020203);
    if (!mpModel) {
        return FALSE;
    }
    
    switch (m_itemNo) {
    case ARROW_30:
        mpModelArrow[0] = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000002);
        if (!mpModelArrow[0]) {
            return FALSE;
        }
    case ARROW_20:
        mpModelArrow[1] = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000002);
        if (!mpModelArrow[1]) {
            return FALSE;
        }
        break;
    default:
        mpModelArrow[1] = NULL;
        mpModelArrow[0] = NULL;
    }
    
    J3DAnmTextureSRTKey* pbtk;
    mpBtkAnm1 = NULL;
    if (btkAnm1 != -1) {
        pbtk = (J3DAnmTextureSRTKey*)dComIfG_getObjectRes(resName, btkAnm1);
        JUT_ASSERT(140, pbtk != 0);
        mpBtkAnm1 = new mDoExt_btkAnm();
        if (!mpBtkAnm1 || !mpBtkAnm1->init(modelData, pbtk, TRUE, 2, 1.0, 0, -1, false, 0)) {
            return FALSE;
        }
    }
    
    mpBtkAnm2 = NULL;
    if (btkAnm2 != -1) {
        pbtk = (J3DAnmTextureSRTKey*)dComIfG_getObjectRes(resName, btkAnm2);
        JUT_ASSERT(156, pbtk != 0);
        mpBtkAnm2 = new mDoExt_btkAnm();
        if (!mpBtkAnm2 || !mpBtkAnm2->init(modelData, pbtk, TRUE, 2, 1.0, 0, -1, false, 0)) {
            return FALSE;
        }
    }
    
    J3DAnmTevRegKey* pbrk;
    mpBrkAnm1 = NULL;
    if (brkAnm1 != -1) {
        pbrk = (J3DAnmTevRegKey*)dComIfG_getObjectRes(resName, brkAnm1);
        JUT_ASSERT(172, pbrk != 0);
        s8 tevFrm = dItem_data::getTevFrm(m_itemNo);
        BOOL shouldAnimate = TRUE;
        if (tevFrm != -1) {
            shouldAnimate = FALSE;
        }
        mpBrkAnm1 = new mDoExt_brkAnm();
        if (!mpBrkAnm1 || !mpBrkAnm1->init(modelData, pbrk, shouldAnimate, 2, 1.0, 0, -1, false, false)) {
            return FALSE;
        }
    }
    
    mpBrkAnm2 = NULL;
    if (brkAnm2 != -1) {
        pbrk = (J3DAnmTevRegKey*)dComIfG_getObjectRes(resName, brkAnm2);
        JUT_ASSERT(197, pbrk != 0);
        mpBrkAnm2 = new mDoExt_brkAnm();
        if (!mpBrkAnm2 || !mpBrkAnm2->init(modelData, pbrk, TRUE, 2, 1.0, 0, -1, false, false)) {
            return FALSE;
        }
    }
    
    J3DAnmTransform* pbck;
    mpBckAnm = NULL;
    if (bckAnm != -1) {
        pbck = (J3DAnmTransform*)dComIfG_getObjectRes(resName, bckAnm);
        JUT_ASSERT(212, pbck != 0);
        mpBckAnm = new mDoExt_bckAnm();
        if (!mpBckAnm || !mpBckAnm->init(modelData, pbck, TRUE, 2, 1.0, 0, -1, false)) {
            return FALSE;
        }
    }
    
    if (!clothCreate()) {
        return FALSE;
    }
    
    return TRUE;
}

/* 800F9074-800F9130       .text DrawBase__12daItemBase_cFv */
BOOL daItemBase_c::DrawBase() {
    setTevStr();
    animEntry();
    setListStart();
    settingBeforeDraw();
    
    mDoExt_modelUpdateDL(mpModel);
    
    if (mpModelArrow[0]) {
        mDoExt_modelUpdateDL(mpModelArrow[0]);
    }
    if (mpModelArrow[1]) {
        mDoExt_modelUpdateDL(mpModelArrow[1]);
    }
    
    setListEnd();
    setShadow();
    
    return TRUE;
}

/* 800F9130-800F9184       .text setListStart__12daItemBase_cFv */
void daItemBase_c::setListStart() {
    if (!mDoGph_gInf_c::isMonotone()) {
        dComIfGd_setListMaskOff();
    } else {
        dComIfGd_setListP1();
    }
}

/* 800F9184-800F91A8       .text setListEnd__12daItemBase_cFv */
void daItemBase_c::setListEnd() {
    dComIfGd_setList();
}

/* 800F91A8-800F9244       .text settingBeforeDraw__12daItemBase_cFv */
void daItemBase_c::settingBeforeDraw() {
    if (isBomb(m_itemNo)) {
        daPy_lk_c* link = daPy_getPlayerLinkActorClass();
        link->getBombBrk()->setFrame(0.0f);
        mpModel->getModelData()->getJointNodePointer(0)->setMtxCalc(NULL);
    }
    
    if (m_itemNo == BOMB_BAG || m_itemNo == HUMMER || m_itemNo == SMALL_KEY) {
        dDlst_texSpecmapST(&mEyePos, &mTevStr, mpModel->getModelData(), 1.0f);
    }
}

/* 800F9244-800F92DC       .text setTevStr__12daItemBase_cFv */
void daItemBase_c::setTevStr() {
    g_env_light.settingTevStruct(TEV_TYPE_ACTOR, getPositionP(), &mTevStr);
    g_env_light.setLightTevColorType(mpModel, &mTevStr);
    
    for (int i = 0; i < 2; i++) {
        if (!mpModelArrow[i]) {
            continue;
        }
        g_env_light.setLightTevColorType(mpModelArrow[i], &mTevStr);
    }
}

/* 800F92DC-800F93A8       .text setShadow__12daItemBase_cFv */
void daItemBase_c::setShadow() {
    f32 shadowSize = mScale.x * dItem_data::getShadowSize(m_itemNo);
    if (!dItem_data::chkFlag(m_itemNo, 0x10)) {
        dComIfGd_setSimpleShadow2(
            getPositionP(), mAcch.GetGroundH(), shadowSize, mAcch.m_gnd,
            0, 1.0f, dDlst_shadowControl_c::getSimpleTex()
        );
    } else {
        mShadowId = dComIfGd_setShadow(
            mShadowId, 1, mpModel, getPositionP(), 80.0f, shadowSize,
            current.pos.y, mAcch.GetGroundH(), mAcch.m_gnd, &mTevStr,
            0, 1.0f, dDlst_shadowControl_c::getSimpleTex()
        );
    }
}

/* 800F93A8-800F94C0       .text animEntry__12daItemBase_cFv */
void daItemBase_c::animEntry() {
    if (mpBrkAnm1) {
        int constantFrame = dItem_data::getTevFrm(m_itemNo);
        if (constantFrame != -1) {
            mpBrkAnm1->entry(mpModel->getModelData(), constantFrame);
        } else {
            mpBrkAnm1->entry(mpModel->getModelData());
        }
    }
    if (mpBtkAnm1) {
        mpBtkAnm1->entry(mpModel->getModelData());
    }
    if (mpBrkAnm2) {
        mpBrkAnm2->entry(mpModel->getModelData());
    }
    if (mpBtkAnm2) {
        mpBtkAnm2->entry(mpModel->getModelData());
    }
    if (mpBckAnm) {
        mpBckAnm->entry(mpModel->getModelData());
    }
}

/* 800F94C0-800F95B8       .text animPlay__12daItemBase_cFfffff */
void daItemBase_c::animPlay(f32 brk1Speed, f32 brk2Speed, f32 btk1Speed, f32 btk2Speed, f32 bckSpeed) {
    if (mpBrkAnm1 && dItem_data::getTevFrm(m_itemNo) == -1) {
        mpBrkAnm1->setPlaySpeed(brk1Speed);
        mpBrkAnm1->play();
    }
    
    if (mpBtkAnm1) {
        mpBtkAnm1->setPlaySpeed(btk1Speed);
        mpBtkAnm1->play();
    }
    
    if (mpBrkAnm2) {
        mpBrkAnm2->setPlaySpeed(brk2Speed);
        mpBrkAnm2->play();
    }
    
    if (mpBtkAnm2) {
        mpBtkAnm2->setPlaySpeed(btk2Speed);
        mpBtkAnm2->play();
    }
    
    if (mpBckAnm) {
        mpBckAnm->setPlaySpeed(bckSpeed);
        mpBckAnm->play();
    }
}
