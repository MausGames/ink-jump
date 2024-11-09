////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#pragma once
#ifndef _INJ_GUARD_GAME_H_
#define _INJ_GUARD_GAME_H_


// ****************************************************************
#define GAME_RESERVE_WALLS (128u)

#define GAME_WIDTH        (34.0f)
#define GAME_HEIGHT_END_1 (g_pGame->GetTop())
#define GAME_HEIGHT_END_2 (g_pCanvas->GetSize().y)


// ****************************************************************
class CGame final
{
private:
    CArrow m_Arrow;

    coreList<CWall*> m_apWall;
    coreBatchList    m_WallList;
    coreMemoryPool   m_WallMemory;

    coreFloat m_fProgress;
    coreFloat m_fTop;
    coreFlow  m_fTime;

    coreBool m_bStarted;


public:
    CGame()noexcept;
    ~CGame();

    DISABLE_COPY(CGame)

    void Render();
    void Move();

    inline coreBool IsStarted()const {return (m_bStarted);}
    inline coreBool IsEnded  ()const {return (m_Arrow.GetPosition().y >= m_fTop);}
    inline coreBool IsRunning()const {return (this->IsStarted() && !this->IsEnded());}

    inline const coreFloat& GetProgress()const {return m_fProgress;}
    inline const coreFloat& GetTop     ()const {return m_fTop;}
    inline const coreFloat& GetTime    ()const {return m_fTime;}


private:
    RETURN_RESTRICT CWall* __CreateWall();

    void __Setup();
};


#endif // _INJ_GUARD_GAME_H_