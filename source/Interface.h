////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#pragma once
#ifndef _INJ_GUARD_INTERFACE_H_
#define _INJ_GUARD_INTERFACE_H_


// ****************************************************************
#define INTERFACE_COLOR (coreVector3(1.0f,1.0f,1.0f) * 0.92f)


// ****************************************************************
class CInterface final
{
private:
    coreRichText m_Title;
    coreRichText m_Name;
    coreRichText m_Message;
    coreRichText m_Record;

    coreObject2D m_aBack[3];

    coreBool m_bOutro;
    coreFlow m_fIntroValue;
    coreFlow m_fOutroValue;


public:
    CInterface()noexcept;

    DISABLE_COPY(CInterface)

    void Render();
    void Move();

    inline void StartOutro() {m_bOutro = true;}
};


#endif // _INJ_GUARD_INTERFACE_H_