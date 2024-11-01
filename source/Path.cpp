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
CPath::CPath()noexcept
: m_apTrail     {}
, m_apSplat     {}
, m_TrailList   (PATH_RESERVE_TRAILS)
, m_SplatList   (PATH_RESERVE_SPLATS)
, m_TrailMemory (sizeof(coreObject3D), PATH_RESERVE_TRAILS)
, m_SplatMemory (sizeof(coreObject3D), PATH_RESERVE_SPLATS)
, m_vLastPos    (coreVector2(FLT_MAX, FLT_MAX))
, m_vLastDir    (coreVector2(0.0f,1.0f))
, m_bTrack      (false)
, m_iCurTrail   (0u)
, m_iCurSplat   (0u)
{
    m_apTrail.reserve(PATH_RESERVE_TRAILS);
    m_apSplat.reserve(PATH_RESERVE_SPLATS);

    m_TrailList.DefineProgram("effect_splat_inst_program");
    m_SplatList.DefineProgram("effect_splat_inst_program");

    coreObject3D* pPreload = this->__CreateSplat();
    pPreload->SetPosition(coreVector3(1000.0f,0.0f,0.0f));
    pPreload->SetEnabled (CORE_OBJECT_ENABLE_NOTHING);
}


// ****************************************************************
CPath::~CPath()
{
    m_TrailMemory.Shutdown();
    m_SplatMemory.Shutdown();

    FOR_EACH(it, m_apTrail) POOLED_DELETE(m_TrailMemory, *it)
    FOR_EACH(it, m_apSplat) POOLED_DELETE(m_SplatMemory, *it)

    m_apTrail.clear();
    m_apSplat.clear();
}


// ****************************************************************
void CPath::Render()
{
    m_TrailList.Render();
    m_SplatList.Render();
}


// ****************************************************************
void CPath::Move()
{
    const coreFloat fCamHeight = Core::Graphics->GetCamPosition().y;
    const coreFloat fCamRange  = MAX(Core::Graphics->GetViewResolution().xy().yx().AspectRatio(), 1.0f) * 30.0f;

    FOR_EACH(it, m_apTrail)
    {
        (*it)->SetEnabled(coreMath::IsNear((*it)->GetPosition().y, fCamHeight, fCamRange) ? CORE_OBJECT_ENABLE_ALL : CORE_OBJECT_ENABLE_NOTHING);
    }

    FOR_EACH(it, m_apSplat)
    {
        (*it)->SetEnabled(coreMath::IsNear((*it)->GetPosition().y, fCamHeight, fCamRange) ? CORE_OBJECT_ENABLE_ALL : CORE_OBJECT_ENABLE_NOTHING);
    }

    m_TrailList.MoveNormal();
    m_SplatList.MoveNormal();
}


// ****************************************************************
void CPath::UpdateTrack(const coreVector2 vPosition)
{
    if(!m_bTrack) return;

    const coreVector2 vDiff = vPosition - m_vLastPos;
    if(vDiff.IsNull()) return;

    const coreVector2 vNewDir = vDiff.Normalized();
    const coreFloat   fAngle  = coreVector2::Angle(m_vLastDir, vNewDir);

    if((vDiff.LengthSq() >= POW2(1.2f)) || ((fAngle > 0.1f) && (fAngle < 0.8f)))
    {
        m_iCurTrail += 1u;

        coreObject3D* pTrail = this->__CreateTrail();

        pTrail->SetPosition (coreVector3(m_vLastPos + vDiff * 0.5f, 0.0f));
        pTrail->SetSize     (coreVector3(0.5f, vDiff.Length() + 0.1f, 1.0f));
        pTrail->SetDirection(coreVector3(vDiff.Normalized(), 0.0f));
        pTrail->SetColor3   (coreVector3(1.0f,1.0f,1.0f));

        m_vLastPos = vPosition;
        m_vLastDir = vNewDir;
    }
}


// ****************************************************************
void CPath::StartTrack(const coreVector2 vPosition)
{
    m_vLastPos = vPosition;
    m_bTrack   = true;
}


// ****************************************************************
void CPath::StopTrack()
{
    m_bTrack = false;
}


// ****************************************************************
void CPath::AddSplat(const coreVector2 vPosition, const coreVector2 vVelocity)
{
    m_iCurSplat += 1u;

    coreVector2 vOffset;
    switch(m_iCurSplat % 5u)
    {
    default: UNREACHABLE
    case 0u: vOffset = coreVector2(1.0f,0.0f); break;
    case 1u: vOffset = coreVector2(2.0f,0.0f); break;
    case 2u: vOffset = coreVector2(3.0f,0.0f); break;
    case 3u: vOffset = coreVector2(0.0f,1.0f); break;
    case 4u: vOffset = coreVector2(1.0f,1.0f); break;
    }

    const coreVector2 vDirection = vVelocity.IsNull() ? coreVector2::Rand() : vVelocity.Normalized();

    coreObject3D* pSplat = this->__CreateSplat();

    pSplat->SetPosition (coreVector3(vPosition, 0.0f));
    pSplat->SetSize     (coreVector3(1.0f,1.0f,1.0f) * 9.0f);
    pSplat->SetDirection(coreVector3(vDirection, 0.0f));
    pSplat->SetTexSize  (coreVector2(1.0f,1.0f) * (1.0f/4.0f));
    pSplat->SetTexOffset(vOffset * (1.0f/4.0f));
}


// ****************************************************************
RETURN_RESTRICT coreObject3D* CPath::__CreateTrail()
{
    coreObject3D* pTrail = POOLED_NEW(m_TrailMemory, coreObject3D);

    pTrail->DefineModel  (Core::Manager::Object->GetLowQuad());
    pTrail->DefineTexture(0u, "default_white.webp");
    pTrail->DefineProgram("effect_splat_program");

    m_apTrail  .push_back (pTrail);
    m_TrailList.BindObject(pTrail);

    return pTrail;
}


// ****************************************************************
RETURN_RESTRICT coreObject3D* CPath::__CreateSplat()
{
    coreObject3D* pSplat = POOLED_NEW(m_SplatMemory, coreObject3D);

    pSplat->DefineModel  (Core::Manager::Object->GetLowQuad());
    pSplat->DefineTexture(0u, "effect_splat.webp");
    pSplat->DefineProgram("effect_splat_program");

    m_apSplat  .push_back (pSplat);
    m_SplatList.BindObject(pSplat);

    return pSplat;
}