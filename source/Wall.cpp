////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#include "main.h"


// ****************************************************************
CWall::CWall()noexcept
: coreObject3D ()
, m_vOldPos    (coreVector2(0.0f,0.0f))
, m_vOldDir    (coreVector2(0.0f,0.0f))
, m_vBasePos   (coreVector2(0.0f,0.0f))
, m_fBaseSize  (0.0f)
, m_fAnimTime  (0.0f)
, m_fAnimSpeed (0.0f)
, m_fAnimPower (0.0f)
, m_fBounce    (0.0f)
, m_iMoveType  (0u)
, m_iColorType (0u)
, m_bActive    (true)
{
    this->DefineModel  ("object_wall.md3z");
    this->DefineProgram("object_wall_program");

    this->SetColor3(coreVector3(1.0f,1.0f,1.0f) * COLOR_BLACK);
}


// ****************************************************************
void CWall::Move()
{
    m_vOldPos = this->GetPosition ().xy();
    m_vOldDir = this->GetDirection().xy();

    m_fAnimTime.Update(m_fAnimSpeed);

    switch(m_iMoveType)
    {
    // rotation
    case 1u:
        {
            this->SetDirection(coreVector3(coreVector2::Direction(m_fAnimTime), 0.0f));
        }
        break;

    // move infinity
    case 2u:
        {
            coreVector2 vNewPos = this->GetPosition().xy() + coreVector2(1.0f,0.0f) * (m_fAnimSpeed * TIME);

            if(ABS(vNewPos.x) >= m_fAnimPower)
            {
                vNewPos.x -= SIGN(vNewPos.x) * m_fAnimPower * 2.0f;
            }

            this->SetPosition(coreVector3(vNewPos, 0.0f));
        }
        break;

    // move swing fat
    case 3u:
        {
            const coreVector2 vNewPos = m_vBasePos + this->GetDirection().xy() * (SIN(m_fAnimTime) * m_fAnimPower);

            this->SetPosition(coreVector3(vNewPos, 0.0f));
        }
        break;

    // move swing thin
    case 4u:
        {
            const coreVector2 vNewPos = m_vBasePos + this->GetDirection().xy().Rotated90() * (SIN(m_fAnimTime) * m_fAnimPower);

            this->SetPosition(coreVector3(vNewPos, 0.0f));
        }
        break;

    default:
        break;
    }

    m_fBounce.UpdateMax(-3.0f, 0.0f);

    this->SetSize(coreVector3(m_fBaseSize, 1.0f, 0.5f) + (BLENDBR(m_fBounce) * 0.3f));

    this->coreObject3D::Move();
}


// ****************************************************************
void CWall::Configure(const coreUint8 iMoveType, const coreUint8 iColorType, const coreVector2 vPosition, const coreFloat fSize, const coreVector2 vDirection, const coreFloat fAnimOffset, const coreFloat fAnimSpeed, const coreFloat fAnimPower)
{
    m_iMoveType  = iMoveType;
    m_iColorType = iColorType;

    m_vBasePos  = vPosition;
    m_fBaseSize = fSize / WALL_LENGTH;

    m_fAnimTime  = fAnimOffset;
    m_fAnimSpeed = fAnimSpeed;
    m_fAnimPower = fAnimPower;

    this->SetPosition (coreVector3(m_vBasePos,        0.0f));
    this->SetSize     (coreVector3(m_fBaseSize, 1.0f, 0.5f));
    this->SetDirection(coreVector3(vDirection,        0.0f));

    if(iColorType == 3u) m_bActive = false;
}


// ****************************************************************
void CWall::ToggleActive()
{
    switch(m_iColorType)
    {
    // toggle
    case 2u:
    case 3u:
        {
            this->__SetActive(!m_bActive);
        }
        break;

    default:
        break;
    }
}


// ****************************************************************
void CWall::EnableActive()
{
    switch(m_iColorType)
    {
    // once
    case 1u:
        {
            this->__SetActive(true);
        }
        break;

    default:
        break;
    }
}


// ****************************************************************
void CWall::DisableActive()
{
    switch(m_iColorType)
    {
    // once
    case 1u:
        {
            this->__SetActive(false);
        }
        break;

    default:
        break;
    }
}