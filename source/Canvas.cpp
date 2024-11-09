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
CCanvas::CCanvas()noexcept
: coreObject3D  ()
, m_Dark        ()
, m_aSide       {}
, m_fDarkHeight (0.0f)
{
    const coreVector3 vColor = coreVector3(1.0f,1.0f,1.0f) * coreMath::FloorFactor(COLOR_BLACK, 1.0f/255.0f);   // get same color as with instancing compression

    this->DefineModel  (Core::Manager::Object->GetLowQuad());
    this->DefineProgram("effect_canvas_program");
    this->SetSize      (coreVector3(70.0f,3000.0f,1.0f));

    m_Dark.DefineModel  (Core::Manager::Object->GetLowQuad());
    m_Dark.DefineProgram("effect_dark_program");
    m_Dark.SetSize      (coreVector3(80.0f,70.0f,1.0f));
    m_Dark.SetColor3    (vColor);

    for(coreUintW i = 0u; i < ARRAY_SIZE(m_aSide); ++i)
    {
        m_aSide[i].DefineModel  (Core::Manager::Object->GetLowQuad());
        m_aSide[i].DefineProgram("effect_dark_program");
        m_aSide[i].SetSize      (coreVector3(200.0f, this->GetSize().y, 1.0f));
        m_aSide[i].SetColor3    (vColor);
    }
}


// ****************************************************************
void CCanvas::Render()
{
    if(!this->GetProgram().IsUsable()) return;
    if(!this->GetProgram()->Enable())  return;

    this->GetProgram()->SendUniform("u_v1Time", Core::System->GetTotalTimeFloat(2.0f*PI));

    glDisable(GL_BLEND);
    {
        this->coreObject3D::Render();
        m_Dark.Render();
    }
    glEnable(GL_BLEND);
}


// ****************************************************************
void CCanvas::Move()
{
    this->SetPosition(coreVector3(0.0f, this->GetSize().y * 0.5f, 0.0f));
    this->coreObject3D::Move();

    m_Dark.SetPosition(coreVector3(0.0f, m_Dark.GetSize().y * 0.5f + m_fDarkHeight, 0.0f));
    m_Dark.Move();

    for(coreUintW i = 0u; i < ARRAY_SIZE(m_aSide); ++i)
    {
        const coreVector2 vDir = coreVector2::StepRotated90(i + 1u);

        m_aSide[i].SetPosition(this->GetPosition() +  coreVector3((this->GetSize().xy() + m_aSide[i].GetSize().xy()) * vDir * 0.5f, 0.0f));
        m_aSide[i].Move();
    }
}


// ****************************************************************
void CCanvas::RenderAfter()
{
    glDisable(GL_BLEND);
    {
        for(coreUintW i = 0u; i < ARRAY_SIZE(m_aSide); ++i)
        {
            m_aSide[i].Render();
        }
    }
    glEnable(GL_BLEND);
}