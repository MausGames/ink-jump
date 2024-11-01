////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#pragma once
#ifndef _INJ_GUARD_WALL_H_
#define _INJ_GUARD_WALL_H_

// TODO 4: enums for move-type and color-type


// ****************************************************************
#define WALL_LENGTH (3.5958f * 2.0f)

#define WALL_SHADER_ATTRIBUTE_LENGTH_NUM    (CORE_SHADER_ATTRIBUTE_USER_NUM + 0u)
#define WALL_SHADER_ATTRIBUTE_LENGTHDIV_NUM (CORE_SHADER_ATTRIBUTE_USER_NUM + 1u)


// ****************************************************************
class CWall final : public coreObject3D
{
private:
    coreVector2 m_vOldPos;
    coreVector2 m_vOldDir;

    coreVector2 m_vBasePos;
    coreFloat   m_fBaseSize;

    coreFlow  m_fAnimTime;
    coreFloat m_fAnimSpeed;
    coreFloat m_fAnimPower;

    coreFlow m_fBounce;

    coreUint8 m_iMoveType;
    coreUint8 m_iColorType;

    coreBool m_bActive;


public:
    CWall()noexcept;

    ENABLE_COPY(CWall)

    void Move()final;

    void Configure(const coreUint8 iMoveType, const coreUint8 iColorType, const coreVector2 vPosition, const coreFloat fSize, const coreVector2 vDirection, const coreFloat fAnimOffset, const coreFloat fAnimSpeed, const coreFloat fAnimPower);

    void ToggleActive();
    void EnableActive();
    void DisableActive();

    inline void Bounce() {m_fBounce = 1.0f;}

    inline coreBool IsSticky  ()const {return (m_iColorType != 4u);}
    inline coreBool IsPowerful()const {return (m_iColorType == 5u);}

    inline const coreVector2& GetOldPos   ()const {return m_vOldPos;}
    inline const coreVector2& GetOldDir   ()const {return m_vOldDir;}
    inline const coreUint8&   GetMoveType ()const {return m_iMoveType;}
    inline const coreUint8&   GetColorType()const {return m_iColorType;}
    inline const coreBool&    GetActive   ()const {return m_bActive;}


private:
    inline void __SetActive(const coreBool bActive) {m_bActive = bActive; this->SetAlpha(bActive ? 1.0f : 0.35f);}
};


#endif // _INJ_GUARD_WALL_H_