////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#include "main.h"

coreMusicPlayer g_aMusicPlayer[3] = {};

STATIC_MEMORY(CInterface, g_pInterface)
STATIC_MEMORY(CCanvas,    g_pCanvas)
STATIC_MEMORY(CPath,      g_pPath)
STATIC_MEMORY(CGame,      g_pGame)


// ****************************************************************
// init the application
void CoreApp::Init()
{
    Core::Graphics->SetCamera(CAMERA_POSITION, CAMERA_DIRECTION, CAMERA_ORIENTATION);
    Core::Graphics->SetView(Core::System->GetResolution(), DEG_TO_RAD(45.0f), 10.0f, 500.0f);

    for(coreUintW i = 0u; i < ARRAY_SIZE(g_aMusicPlayer); ++i)
    {
        g_aMusicPlayer[i].AddMusicFile(PRINT("data/music/intro_%02zu.opus", i + 1u));
        g_aMusicPlayer[i].AddMusicFile(PRINT("data/music/loop_%02zu.opus",  i + 1u));

        g_aMusicPlayer[i].GetMusic(1u)->SetLoop(true);
        g_aMusicPlayer[i].SetVolume(0.0f);
    }

    Core::Input->ShowCursor(false);

    STATIC_NEW(g_pInterface)
    STATIC_NEW(g_pCanvas)
    STATIC_NEW(g_pPath)
    STATIC_NEW(g_pGame)
}


// ****************************************************************
// exit the application
void CoreApp::Exit()
{
    STATIC_DELETE(g_pGame)
    STATIC_DELETE(g_pPath)
    STATIC_DELETE(g_pCanvas)
    STATIC_DELETE(g_pInterface)

    for(coreUintW i = 0u; i < ARRAY_SIZE(g_aMusicPlayer); ++i)
    {
        g_aMusicPlayer[i].ClearMusic();
    }
}


// ****************************************************************
// render the application
void CoreApp::Render()
{
    glClearColor(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK, 1.0f);

    glDisable(GL_DEPTH_TEST);
    {
        g_pCanvas->Render();
        g_pPath  ->Render();
        g_pGame  ->Render();

        g_pCanvas->RenderAfter();

        g_pInterface->Render();
    }
    glEnable(GL_DEPTH_TEST);
}


// ****************************************************************
// move the application
void CoreApp::Move()
{
    if(Core::System->GetWinSizeChanged())
    {
        Core::Reshape();
    }

    g_pInterface->Move();
    g_pCanvas   ->Move();
    g_pGame     ->Move();
    g_pPath     ->Move();

    const coreFloat fProgress = g_pGame->GetProgress();
    const coreFloat fStep1    = STEPH3(350.0f, 450.0f, fProgress);
    const coreFloat fStep2    = STEPH3(650.0f, 750.0f, fProgress);

    g_aMusicPlayer[0].SetVolume(1.0f - fStep1);
    g_aMusicPlayer[1].SetVolume(       fStep1 - fStep2);
    g_aMusicPlayer[2].SetVolume(                fStep2);

    for(coreUintW i = 0u; i < ARRAY_SIZE(g_aMusicPlayer); ++i)
    {
        g_aMusicPlayer[i].Update();
    }
}