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
#define ARROW_LAST_DELAY (0.1f)


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
    coreVector2 m_vVelocity;
    coreVector2 m_vOldPos;

    SStickyData m_Sticky;

    CWall*   m_pCurWall;
    CWall*   m_pLastWall;
    coreFlow m_fLastDelay;

    coreBool m_bJumped;

    coreFlow m_fRotation;

    coreSoundPtr m_pJumpSound;
    coreSoundPtr m_pStickSound;


public:
    CArrow()noexcept;

    DISABLE_COPY(CArrow)

    void Move()final;

    void MakeSticky(CWall* pWall, const coreVector2 vIntersection, const coreUint8 iSide);

    inline coreBool IsSticky()const {return (m_pCurWall != NULL);}

    inline const coreVector2& GetVelocity()const {return m_vVelocity;}
    inline const coreVector2& GetOldPos  ()const {return m_vOldPos;}
    inline const CWall*       GetLastWall()const {return m_pLastWall;}
    inline const coreBool&    GetJumped  ()const {return m_bJumped;}


private:
    coreVector2 __CalcStickyPos()const;
};


#endif // _INJ_GUARD_ARROW_H_