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
CArrow::CArrow()noexcept
: m_vVelocity   (coreVector2(0.0f,0.0f))
, m_vOldPos     (coreVector2(0.0f,0.0f))
, m_Sticky      {}
, m_pCurWall    (NULL)
, m_pLastWall   (NULL)
, m_fLastDelay  (0.0f)
, m_bJumped     (false)
, m_fRotation   (0.0f)
, m_pJumpSound  (NULL)
, m_pStickSound (NULL)
{
    this->DefineModel  ("object_arrow.md3z");
    this->DefineProgram("object_arrow_program");

    this->SetSize  (coreVector3(1.0f,1.0f,1.0f) * 0.78f);
    this->SetColor3(coreVector3(1.0f,1.0f,1.0f) * COLOR_BLACK);

    m_pJumpSound  = Core::Manager::Resource->Get<coreSound>("jump.opus");
    m_pStickSound = Core::Manager::Resource->Get<coreSound>("stick.opus");
}


// ****************************************************************
void CArrow::Move()
{
    m_vOldPos = this->GetPosition().xy();
    m_bJumped = false;

    m_fLastDelay.UpdateMax(-1.0f, 0.0f);
    if(!m_fLastDelay) m_pLastWall = NULL;

    coreVector2 vMove   = coreVector2(0.0f,0.0f);
    coreBool    bAction = false;

    if(g_pGame->IsStarted())
    {
        Core::Input->ForwardHatToStick(CORE_INPUT_JOYSTICK_ANY);

        vMove += Core::Input->GetJoystickStickL(CORE_INPUT_JOYSTICK_ANY) +
                 Core::Input->GetJoystickStickR(CORE_INPUT_JOYSTICK_ANY);

        if(Core::Input->GetKeyboardButton(CORE_INPUT_KEY(A),    CORE_INPUT_HOLD) ||
           Core::Input->GetKeyboardButton(CORE_INPUT_KEY(LEFT), CORE_INPUT_HOLD))
        {
            vMove.x -= 1.0f;
        }

        if(Core::Input->GetKeyboardButton(CORE_INPUT_KEY(D),     CORE_INPUT_HOLD) ||
           Core::Input->GetKeyboardButton(CORE_INPUT_KEY(RIGHT), CORE_INPUT_HOLD))
        {
            vMove.x += 1.0f;
        }

        if(Core::Input->GetKeyboardButton(CORE_INPUT_KEY(S),    CORE_INPUT_HOLD) ||
           Core::Input->GetKeyboardButton(CORE_INPUT_KEY(DOWN), CORE_INPUT_HOLD))
        {
            vMove.y -= 1.0f;
        }

        if(Core::Input->GetKeyboardButton(CORE_INPUT_KEY(W),  CORE_INPUT_HOLD) ||
           Core::Input->GetKeyboardButton(CORE_INPUT_KEY(UP), CORE_INPUT_HOLD))
        {
            vMove.y += 1.0f;
        }

        bAction = Core::Input->GetJoystickButton(CORE_INPUT_JOYSTICK_ANY, SDL_CONTROLLER_BUTTON_A, CORE_INPUT_PRESS) ||
                  Core::Input->GetJoystickButton(CORE_INPUT_JOYSTICK_ANY, SDL_CONTROLLER_BUTTON_B, CORE_INPUT_PRESS) ||
                  Core::Input->GetKeyboardButton(CORE_INPUT_KEY(SPACE),                            CORE_INPUT_PRESS) ||
                  Core::Input->GetKeyboardButton(CORE_INPUT_KEY(RETURN),                           CORE_INPUT_PRESS) ||
                  Core::Input->GetMouseButton   (CORE_INPUT_LEFT,                                  CORE_INPUT_PRESS);
    }

    if(m_pCurWall)
    {
        m_vVelocity = coreVector2(0.0f,0.0f);

        const coreVector2 vNewPos = this->__CalcStickyPos();
        const coreVector2 vNewDir = coreVector2::Direction(m_pCurWall->GetDirection().xy().Angle() + m_Sticky.fAngle);

        this->SetPosition (coreVector3(vNewPos, 0.0f));
        this->SetDirection(coreVector3(vNewDir, 0.0f));
    }
    else
    {
        if(Core::System->GetTotalTime() >= 2.0)
        {
            if(this->GetPosition().y > GAME_HEIGHT_END_1)
            {
                m_vVelocity.y += 100.0f * TIME;

                     if(vMove.x < 0.0f) m_vVelocity.x -= 300.0f * TIME;
                else if(vMove.x > 0.0f) m_vVelocity.x += 300.0f * TIME;
            }
            else
            {
                m_vVelocity.y -= 100.0f * TIME;

                     if(vMove.x < 0.0f) m_vVelocity.x -= 100.0f * TIME;
                else if(vMove.x > 0.0f) m_vVelocity.x += 100.0f * TIME;

                     if(vMove.y < 0.0f) m_vVelocity.y -= 10.0f * TIME;
                else if(vMove.y > 0.0f) m_vVelocity.y += 10.0f * TIME;
            }

            m_vVelocity.x *= FrictionFactor(4.0f);
            m_vVelocity.y  = CLAMP(m_vVelocity.y, -300.0f, 300.0f);
        }

        const coreVector2 vNewPos = this->GetPosition().xy() + m_vVelocity * TIME;

        this->SetPosition(coreVector3(vNewPos, 0.0f));
    }

    if(bAction)
    {
        if(m_pCurWall)
        {
            coreVector2 vLean = coreVector2(0.0f,0.0f);

            if(vMove.x < 0.0f) vLean.x -= 1.0f;
            if(vMove.x > 0.0f) vLean.x += 1.0f;
            if(vMove.y < 0.0f) vLean.y -= 1.0f;
            if(vMove.y > 0.0f) vLean.y += 1.0f;

            if(vLean.y > 0.0f) vLean.y *= 3.0f;

            const coreVector2 vWallDir = m_pCurWall->GetDirection().xy().MapStepRotated90(m_Sticky.iSide);

            m_vVelocity += LERP(vWallDir, vLean, 0.2f).Normalized() * (m_pCurWall->IsPowerful() ? 130.0f : 65.0f);

            m_pCurWall->DisableActive();
            m_pCurWall->Bounce();

            m_pLastWall  = m_pCurWall;
            m_fLastDelay = 0.1f;
            m_pCurWall   = NULL;

            m_bJumped   = true;
            m_fRotation = 1.0f;

            if(m_pJumpSound.IsUsable()) m_pJumpSound->PlayPosition(NULL, 1.0f, 0.8f + 0.2f * Core::Rand->Float(-1.0f,1.0f), false, 0u, this->GetPosition());
        }
    }

    if(ABS(this->GetPosition().x) > GAME_WIDTH)
    {
        this->SetPosition(coreVector3(CLAMP(this->GetPosition().x, -GAME_WIDTH, GAME_WIDTH), this->GetPosition().yz()));

        m_vVelocity.x = 0.0f;

        if(m_pCurWall)
        {
            coreVector2 vNewPos = this->__CalcStickyPos();

            vNewPos.x = CLAMP(vNewPos.x, -GAME_WIDTH, GAME_WIDTH);

            m_Sticky.vDiff   = vNewPos - m_pCurWall->GetPosition().xy();
            m_Sticky.fOffset = coreVector2::Dot(m_Sticky.vDiff, m_pCurWall->GetDirection().xy().Rotated90());

            const coreVector2 vTest = m_Sticky.vDiff.MapToAxis(m_pCurWall->GetDirection().xy());

            if((ABS(vTest.x) > m_pCurWall->GetCollisionRange().x) ||
               (ABS(vTest.y) > m_pCurWall->GetCollisionRange().y))
            {
                m_pLastWall  = m_pCurWall;
                m_fLastDelay = 0.1f;
                m_pCurWall   = NULL;
            }
        }
    }

    if(!m_vVelocity.IsNull()) this->SetDirection(coreVector3(m_vVelocity.Normalized(), 0.0f));

    if(!g_pGame->IsRunning())
    {
        m_fRotation.Update(-1.0f);

        const coreVector2 vDir = this->GetDirection().xy();
        const coreVector2 vOri = coreVector2::Direction(m_fRotation * (2.0f*PI));

        this->SetOrientation(coreVector3(-vOri.x * vDir.y,
                                          vOri.x * vDir.x,
                                          vOri.y));
    }
    else if(!m_pCurWall)
    {
        m_fRotation.UpdateMax(-1.0f, 0.0f);

        const coreVector2 vDir = this->GetDirection().xy();
        const coreVector2 vOri = coreVector2::Direction(LERPBR(0.0f*PI, 2.0f*PI, m_fRotation));

        this->SetOrientation(coreVector3(-vOri.x * vDir.y,
                                          vOri.x * vDir.x,
                                          vOri.y));
    }
    else
    {
        this->SetOrientation(coreVector3(0.0f,0.0f,1.0f));
    }

    this->coreObject3D::Move();
}


// ****************************************************************
void CArrow::MakeSticky(CWall* pWall, const coreVector2 vIntersection, const coreUint8 iSide)
{
    if(pWall == m_pLastWall) return;

    m_Sticky.vDiff   = vIntersection - pWall->GetPosition().xy();
    m_Sticky.fAngle  = this->GetDirection().xy().Angle() - pWall->GetDirection().xy().Angle();
    m_Sticky.fOffset = coreVector2::Dot(m_Sticky.vDiff, pWall->GetDirection().xy().Rotated90());
    m_Sticky.iSide   = iSide;

    m_pCurWall = pWall;

    this->SetPosition(coreVector3(this->__CalcStickyPos(), 0.0f));
    this->coreObject3D::Move();

    if(m_pStickSound.IsUsable()) m_pStickSound->PlayPosition(NULL, 1.0f, 0.8f + 0.2f * Core::Rand->Float(-1.0f,1.0f), false, 0u, this->GetPosition());
}


// ****************************************************************
coreVector2 CArrow::__CalcStickyPos()const
{
    ASSERT(m_pCurWall)
    return m_pCurWall->GetPosition ().xy() +
           m_pCurWall->GetDirection().xy().Rotated90() * m_Sticky.fOffset +
           m_pCurWall->GetDirection().xy() * m_pCurWall->GetVisualRange().yx().MapStepRotated90(m_Sticky.iSide).x;
}