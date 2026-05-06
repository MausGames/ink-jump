////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#pragma once
#ifndef _INJ_GUARD_ARROW_H_
#define _INJ_GUARD_ARROW_H_

// TODO 3: make the player look more like a squid, maybe even wobbly


// ****************************************************************
#define ARROW_LAST_DELAY     (0.1f)
#define ARROW_EYE_SIZE_WHITE (coreVector2(1.0f,1.5f) * 1.05f)
#define ARROW_EYE_SIZE_BLACK (coreVector2(0.6f,0.6f) * 1.05f)
#define ARROW_EYE_MARGIN     (0.65f)
#define ARROW_EYES           (2u)


// ****************************************************************
class CArrow final : public coreObject3D
{
private:
    struct SStickyData final
    {
        coreVector2 vDiff;
        coreFloat   fAngle;
        coreFloat   fOffset;
        coreUint8   iSide;
    };


private:
    coreObject3D m_aEyeWhite[ARROW_EYES];
    coreObject3D m_aEyeBlack[ARROW_EYES];

    coreVector2 m_vVelocity;
    coreVector2 m_vOldPos;

    SStickyData m_Sticky;

    CWall*   m_pCurWall;
    CWall*   m_pLastWall;
    coreFlow m_fLastDelay;

    coreBool m_bJumped;

    coreFlow m_fRotation;

    coreVector2 m_vView;

    coreSoundPtr m_pJumpSound;
    coreSoundPtr m_pStickSound;


public:
    CArrow()noexcept;

    DISABLE_COPY(CArrow)

    void Render()final;
    void Move  ()final;

    void MakeSticky(CWall* pWall, const coreVector2 vIntersection, const coreUint8 iSide);

    inline coreBool IsSticky()const {return (m_pCurWall != NULL);}

    inline const coreVector2& GetVelocity()const {return m_vVelocity;}
    inline const coreVector2& GetOldPos  ()const {return m_vOldPos;}
    inline const CWall*       GetLastWall()const {return m_pLastWall;}
    inline const coreBool&    GetJumped  ()const {return m_bJumped;}


private:
    void __MoveEyes();

    coreVector2 __CalcStickyPos()const;
};


#endif // _INJ_GUARD_ARROW_H_