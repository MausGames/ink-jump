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
// 
static coreRichText::coreAnim AnimateFunc(const coreRichText::coreCharacter& oCharacter, void* pData)
{
    const coreFloat   fTime  = Core::System->GetTotalTimeFloat(2.0f*PI) * 2.0f;
    const coreVector2 vShift = coreVector2::Direction(fTime + I_TO_F(oCharacter.iOrder) * GA) * 0.003f;

    coreRichText::coreAnim oAnim;

    oAnim.vPosition  = vShift;
    oAnim.vDirection = coreVector2(0.0f, 1.0f);
    oAnim.vColor     = coreVector4(1.0f, 1.0f, 1.0f, 1.0f);

    return oAnim;
}


// ****************************************************************
CInterface::CInterface()noexcept
: m_Title       ()
, m_Name        ()
, m_Message     ()
, m_Record      ()
, m_aBack       {}
, m_bOutro      (false)
, m_fIntroValue (2.5f)
, m_fOutroValue (0.0f)
{
    m_Title.AssignStyle   (CORE_RICHTEXT_DEFAULT, "inkpoint.ttf", 180u, 5u);
    m_Title.AssignColor3  ("a", COLOR_YELLOW);
    m_Title.AssignColor3  ("b", COLOR_ORANGE);
    m_Title.AssignColor3  ("c", COLOR_RED);
    m_Title.AssignColor3  ("d", COLOR_PURPLE);
    m_Title.AssignColor3  ("e", COLOR_BLUE);
    m_Title.AssignColor3  ("f", COLOR_CYAN);
    m_Title.AssignColor3  ("g", COLOR_GREEN);
    m_Title.SetCenter     (coreVector2(0.0f,0.14f));
    m_Title.SetText       ("<color=a>I<color=b>N<color=c>K <color=d>J<color=e>U<color=f>M<color=g>P");
    m_Title.SetAnimateFunc(NULL, AnimateFunc);

    m_Name.AssignStyle   (CORE_RICHTEXT_DEFAULT, "inkpoint.ttf", 80u, 4u);
    m_Name.SetCenter     (coreVector2(0.0f,-0.2f));
    m_Name.SetColor3     (INTERFACE_COLOR);
    m_Name.SetText       ("A GAME BY MARTIN MAUERSICS");
    m_Name.SetAnimateFunc(NULL, AnimateFunc);

    m_Message.AssignStyle   (CORE_RICHTEXT_DEFAULT, "inkpoint.ttf", 80u, 4u);
    m_Message.SetCenter     (coreVector2(0.0f,0.1f));
    m_Message.SetColor3     (INTERFACE_COLOR);
    m_Message.SetAlpha      (0.0f);
    m_Message.SetText       ("THANK YOU FOR PLAYING");
    m_Message.SetAnimateFunc(NULL, AnimateFunc);

    m_Record.AssignStyle   (CORE_RICHTEXT_DEFAULT, "inkpoint.ttf", 80u, 4u);
    m_Record.SetCenter     (coreVector2(0.0f,-0.1f));
    m_Record.SetColor3     (INTERFACE_COLOR);
    m_Record.SetAlpha      (0.0f);
    m_Record.SetAnimateFunc(NULL, AnimateFunc);

    for(coreUintW i = 0u; i < ARRAY_SIZE(m_aBack); ++i)
    {
        m_aBack[i].DefineTexture(0u, "point.webp");
        m_aBack[i].DefineProgram("point_program");
        m_aBack[i].SetColor3    (coreVector3(0.0f,0.0f,0.0f));
    }

    m_aBack[0].SetPosition(m_Title.GetPosition());
    m_aBack[0].SetSize    (coreVector2(1.0f,0.12f));
    m_aBack[0].SetCenter  (m_Title.GetCenter());

    m_aBack[1].SetPosition(m_Name.GetPosition());
    m_aBack[1].SetSize    (coreVector2(1.1f,0.06f));
    m_aBack[1].SetCenter  (m_Name.GetCenter());

    m_aBack[2].SetPosition(m_Message.GetPosition());
    m_aBack[2].SetSize    (coreVector2(1.0f,0.06f));
    m_aBack[2].SetCenter  (m_Message.GetCenter());
}


// ****************************************************************
void CInterface::Render()
{
    for(coreUintW i = 0u; i < ARRAY_SIZE(m_aBack); ++i)
    {
        m_aBack[i].Render();
    }

    m_Title  .Render();
    m_Name   .Render();
    m_Message.Render();
    m_Record .Render();
}


// ****************************************************************
void CInterface::Move()
{
    m_fIntroValue.UpdateMax(-0.5f, 0.0f);

    if(m_bOutro)
    {
        m_fOutroValue.UpdateMin(0.5f, 1.0f);

        const coreFloat fTime = g_pGame->GetTime();
        m_Record.SetText(PRINT("%02u:%02u.%02u", F_TO_UI(fTime) / 60u, F_TO_UI(fTime) % 60u, F_TO_UI(FRACT(fTime) * 100.0f)));
    }

    const auto nSetAlphaFunc = [](coreObject2D* OUTPUT pObject, const coreFloat fAlpha)
    {
        pObject->SetAlpha  (fAlpha);
        pObject->SetEnabled(fAlpha ? CORE_OBJECT_ENABLE_ALL : CORE_OBJECT_ENABLE_NOTHING);
    };

    const coreFloat fIntro = BLENDH3(CLAMP01(m_fIntroValue));
    const coreFloat fOutro = BLENDH3(CLAMP01(m_fOutroValue));

    nSetAlphaFunc(&m_Title,   fIntro);
    nSetAlphaFunc(&m_Name,    fIntro);
    nSetAlphaFunc(&m_Message, fOutro);
    nSetAlphaFunc(&m_Record,  fOutro);

    m_Title  .Move();
    m_Name   .Move();
    m_Message.Move();
    m_Record .Move();

    nSetAlphaFunc(&m_aBack[0], fIntro * 0.1f);
    nSetAlphaFunc(&m_aBack[1], fIntro * 0.1f);
    nSetAlphaFunc(&m_aBack[2], fOutro * 0.1f);

    for(coreUintW i = 0u; i < ARRAY_SIZE(m_aBack); ++i)
    {
        m_aBack[i].Move();
    }
}