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
CGame::CGame()noexcept
: m_apWall     {}
, m_WallList   (GAME_RESERVE_WALLS)
, m_WallMemory (sizeof(CWall), GAME_RESERVE_WALLS)
, m_fProgress  (0.0f)
, m_fTop       (0.0f)
, m_fTime      (0.0f)
, m_bStarted   (false)
{
    m_apWall.reserve(GAME_RESERVE_WALLS);

    m_WallList.DefineProgram("object_wall_inst_program");
    m_WallList.CreateCustom(sizeof(coreFloat) * 2u, [](coreVertexBuffer* OUTPUT pBuffer)
    {
        pBuffer->DefineAttribute(WALL_SHADER_ATTRIBUTE_LENGTH_NUM,    1u, GL_FLOAT, sizeof(coreFloat), false, 0u, 0u);
        pBuffer->DefineAttribute(WALL_SHADER_ATTRIBUTE_LENGTHDIV_NUM, 1u, GL_FLOAT, sizeof(coreFloat), false, 0u, sizeof(coreFloat));
    },
    [](coreByte* OUTPUT pData, const coreObject3D* pObject)
    {
        const coreFloat fLength = pObject->GetSize().x;

        r_cast<coreFloat*>(pData)[0] = (fLength - 1.0f) * (WALL_LENGTH / 2.0f);
        r_cast<coreFloat*>(pData)[1] = (1.0f / fLength);
    },
    [](const coreProgramPtr& pProgram, const coreObject3D* pObject)
    {
        const coreFloat fLength = pObject->GetSize().x;

        pProgram->SendUniform("u_v1Length",    (fLength - 1.0f) * (WALL_LENGTH / 2.0f));
        pProgram->SendUniform("u_v1LengthDiv", (1.0f / fLength));
    });

    this->__Setup();   // # before arrow position

    m_Arrow.SetPosition(coreVector3(0.0f, g_pCanvas->GetDarkHeight() + 35.0f, 0.0f));
}


// ****************************************************************
CGame::~CGame()
{
    m_WallMemory.Shutdown();

    FOR_EACH(it, m_apWall) POOLED_DELETE(m_WallMemory, *it)

    m_apWall.clear();
}


// ****************************************************************
void CGame::Render()
{
    glEnable(GL_DEPTH_TEST);
    {
        m_WallList.Render();
    }
    glDisable(GL_DEPTH_TEST);

    m_Arrow.Render();
}


// ****************************************************************
void CGame::Move()
{
    const coreFloat fCamHeight = Core::Graphics->GetCamPosition().y;
    const coreFloat fCamRange  = MAX(Core::Graphics->GetViewResolution().xy().yx().AspectRatio(), 1.0f) * 50.0f;

    FOR_EACH(it, *m_WallList.List())
    {
        if((*it)->GetSize().x < 30.0f)
        {
            (*it)->SetEnabled(coreMath::IsNear((*it)->GetPosition().y, fCamHeight, fCamRange) ? CORE_OBJECT_ENABLE_ALL : CORE_OBJECT_ENABLE_NOTHING);
        }
    }

    m_WallList.MoveNormal();   // walls first for sticky

    m_Arrow.Move();

    if(m_Arrow.GetJumped())
    {
        FOR_EACH(it, m_apWall)
        {
            CWall* pWall = (*it);

            pWall->ToggleActive();
            if(pWall != m_Arrow.GetLastWall())
            {
                pWall->EnableActive();
            }
        }

        if(m_Arrow.GetLastWall()->GetMoveType())
        {
            g_pPath->AddSplat(m_Arrow.GetPosition().xy(), coreVector2(0.0f,0.0f));
        }

        g_pPath->StartTrack(m_Arrow.GetPosition().xy());
    }

    const coreVector2 vArrowMove   = m_Arrow.GetPosition().xy() - m_Arrow.GetOldPos();
    const coreVector2 vArrowRayDir = vArrowMove.IsNull() ? coreVector2(0.0f,1.0f) : vArrowMove.Normalized();
    const coreVector2 vArrowRayPos = m_Arrow.GetOldPos();

    if(!m_Arrow.IsSticky() && !vArrowMove.IsNull() && !m_Arrow.GetJumped())
    {
        FOR_EACH(it, m_apWall)
        {
            CWall* pWall = (*it);

            if(!pWall->IsEnabled(CORE_OBJECT_ENABLE_MOVE)) continue;
            if(!pWall->GetActive() || !pWall->IsSticky())  continue;
            if(pWall == m_Arrow.GetLastWall())             continue;
            if(!m_bStarted && m_apWall.index(it))          break;

            for(coreUintW i = 0u; i < 2u; ++i)
            {
                const coreFloat fSide = i ? -1.0f : 1.0f;

                const coreVector2 vPos    = pWall->GetPosition().xy() + pWall->GetDirection().xy() * pWall->GetCollisionRange().y * fSide;
                const coreVector2 vPosOld = pWall->GetOldPos()        + pWall->GetOldDir()         * pWall->GetCollisionRange().y * fSide;

                const coreVector2 vDiff    = m_Arrow.GetPosition().xy() - vPos;
                const coreVector2 vDiffOld = m_Arrow.GetOldPos()        - vPosOld;

                const coreFloat fDot    = coreVector2::Dot(vDiff,    pWall->GetDirection().xy());
                const coreFloat fDotOld = coreVector2::Dot(vDiffOld, pWall->GetOldDir());

                if((SIGN(fDot) != SIGN(fDotOld)) && (SIGN(fDot) != SIGN(fSide)))
                {
                    const coreVector2 vRayDir = pWall->GetDirection().xy().Rotated90();
                    const coreVector2 vRayPos = vPos - vRayDir * pWall->GetCollisionRange().x;

                    coreVector2 vIntersection;
                    if(coreVector2::Intersect(vRayPos, vRayDir, vArrowRayPos, vArrowRayDir, &vIntersection))
                    {
                        const coreVector2 vRealDiff = vPos - vIntersection;

                        if((vRealDiff.LengthSq() < POW2(pWall->GetCollisionRange().x)) &&
                           (vDiff    .LengthSq() < POW2(pWall->GetCollisionRange().x)))
                        {
                            if(SIGN(coreVector2::Dot(vDiffOld, pWall->GetDirection().xy())) == SIGN(fDot))
                            {
                                const coreVector2 vCenter = vArrowRayPos + vArrowMove * 0.5f;
                                vIntersection = vCenter + pWall->GetDirection().xy() * SIGN(coreVector2::Dot(vCenter - vPos, pWall->GetDirection().xy()));
                            }

                            m_Arrow.MakeSticky(pWall, vIntersection, (fDotOld > 0.0f) ? 0u : 2u);

                            g_pPath->AddSplat(vIntersection, m_Arrow.GetVelocity());
                            g_pPath->StopTrack();

                            if(!m_bStarted)
                            {
                                m_bStarted = true;
                                for(coreUintW j = 0u; j < ARRAY_SIZE(g_aMusicPlayer); ++j)
                                {
                                    g_aMusicPlayer[j].Play();
                                }
                            }

                            break;
                        }
                    }
                }
            }
        }
    }

    if(this->IsRunning()) m_fTime.Update(1.0f);

    if(m_Arrow.GetPosition().y < GAME_HEIGHT_END_2)
    {
        g_pPath->UpdateTrack(m_Arrow.GetPosition().xy());
    }
    else
    {
        g_pInterface->StartOutro();
    }

    m_fProgress = MAX(m_Arrow.GetPosition().y, 18.0f);

    const coreVector3 vCamPos = CAMERA_POSITION + coreVector3(0.0f, m_fProgress, 0.0f);

    Core::Graphics->SetCamera(vCamPos, CAMERA_DIRECTION, CAMERA_ORIENTATION);
    Core::Audio->SetListener(vCamPos, coreVector3(0.0f,0.0f,0.0f), CAMERA_DIRECTION, CAMERA_ORIENTATION);
}


// ****************************************************************
RETURN_RESTRICT CWall* CGame::__CreateWall()
{
    CWall* pWall = POOLED_NEW(m_WallMemory, CWall);

    m_apWall  .push_back (pWall);
    m_WallList.BindObject(pWall);

    return pWall;
}