////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#pragma once
#ifndef _INJ_GUARD_CANVAS_H_
#define _INJ_GUARD_CANVAS_H_


// ****************************************************************
class CCanvas final : public coreObject3D
{
private:
    coreObject3D m_Dark;
    coreObject3D m_aSide[3];

    coreFloat m_fDarkHeight;


public:
    CCanvas()noexcept;

    DISABLE_COPY(CCanvas)

    void Render()final;
    void Move  ()final;

    void RenderAfter();

    inline void SetDarkHeight(const coreFloat fHeight) {m_fDarkHeight = fHeight;}

    inline const coreFloat& GetDarkHeight()const {return m_fDarkHeight;}
};


#endif // _INJ_GUARD_CANVAS_H_