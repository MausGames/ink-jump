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
void CGame::__Setup()
{
    coreVector2 vCursor = coreVector2(0.0f,0.0f);

    this->__CreateWall()->Configure(0u, 0u, coreVector2(  0.0f,0.0f) + vCursor,   80.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 4u, coreVector2(-35.0f,0.0f) + vCursor, 6000.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 4u, coreVector2( 35.0f,0.0f) + vCursor, 6000.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 10.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(0.0f,0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-19.0f, 0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 19.0f, 0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(  0.0f,21.0f) + vCursor, 36.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 66.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-0.0f,0.0f) + vCursor, 60.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 30.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-19.0f,0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 19.0f,0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 40.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(60.0f,0.0f) + vCursor, 40.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 40.0f, coreVector2(0.0f,1.0f), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(60.0f,0.0f) + vCursor, 40.0f, coreVector2(0.0f,1.0f), 0.0f, -20.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 40.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(60.0f,0.0f) + vCursor, 40.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(40.0f,0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(80.0f,0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(30.0f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(60.0f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(90.0f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2(  0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 40.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 60.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 80.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(100.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);

    vCursor.y += 17.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(40.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(80.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);

    vCursor.y += 5.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(40.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(80.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);

    vCursor.y += 5.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(40.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(80.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);

    vCursor.y += 5.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(40.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(80.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, -30.0f, 60.0f);

    vCursor.y += 5.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 0.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(40.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(80.0f,0.0f) + vCursor, 30.0f, coreVector2(0.0f,1.0f), 0.0f, 30.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-19.0f,0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 19.0f,0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 20.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-24.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( -8.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(  8.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 24.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-16.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(  0.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 16.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-24.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( -8.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(  8.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 24.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-16.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(  0.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 16.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-8.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 8.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2(  0.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 12.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 24.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 36.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 48.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 60.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 72.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 84.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 96.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(108.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -10.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2(  0.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 12.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 24.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 36.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 48.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 60.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 72.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 84.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 96.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(108.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f, 0.5f).Normalized(), 0.0f, 15.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2(  0.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 12.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 24.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 36.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 48.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 60.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 72.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 84.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 96.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(108.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,-0.5f).Normalized(), 0.0f, -20.0f, 60.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-30.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-18.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( -6.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(  6.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 18.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 30.0f,0.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 10.0f;
    this->__CreateWall()->Configure(2u, 0u, coreVector2(  0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 40.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 60.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2( 80.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 0u, coreVector2(100.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);

    Core::Rand->SetSeed(0u);

    vCursor.y += 10.0f;
    for(coreUintW i = 0u; i < 50u; ++i)
    {
        this->__CreateWall()->Configure(0u, 0u, coreVector2(Core::Rand->Float(30.0f) * ((i % 2u) ? 1.0f : -1.0f), I_TO_F(i) * 2.0f) + vCursor, 5.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    }

    vCursor.y += 100.0f;
    for(coreUintW i = 0u; i < 50u; ++i)
    {
        this->__CreateWall()->Configure(2u, 0u, coreVector2(Core::Rand->Float(60.0f) * ((i % 2u) ? 1.0f : -1.0f), I_TO_F(i) * 2.0f) + vCursor, 5.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f * (((i/2u) % 2u) ? 1.0f : -1.0f), 60.0f);
    }

    vCursor.y += 106.0f;
    this->__CreateWall()->Configure(1u, 0u, coreVector2(  0.0f, 0.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f,  2.0f, 0.0f);
    this->__CreateWall()->Configure(1u, 0u, coreVector2(-15.0f,15.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, -2.0f, 0.0f);
    this->__CreateWall()->Configure(1u, 0u, coreVector2( 15.0f,15.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, -2.0f, 0.0f);
    this->__CreateWall()->Configure(1u, 0u, coreVector2(  0.0f,30.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f,  2.0f, 0.0f);
    this->__CreateWall()->Configure(1u, 0u, coreVector2(-15.0f,45.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, -2.0f, 0.0f);
    this->__CreateWall()->Configure(1u, 0u, coreVector2( 15.0f,45.0f) + vCursor, 15.0f, coreVector2(1.0f,0.0f), 0.0f, -2.0f, 0.0f);

    vCursor.y += 85.0f;
    this->__CreateWall()->Configure(1u, 0u, coreVector2(0.0f,0.0f) + vCursor, 60.0f, coreVector2(1.0f,0.0f), 0.0f,    2.0f, 0.0f);
    this->__CreateWall()->Configure(1u, 0u, coreVector2(0.0f,0.0f) + vCursor, 60.0f, coreVector2(1.0f,0.0f), 0.5f*PI, 2.0f, 0.0f);

    vCursor.y += 61.0f;
    this->__CreateWall()->Configure(1u, 0u, coreVector2(0.0f,0.0f) + vCursor, 60.0f, coreVector2(1.0f,0.0f), 0.0f,    2.0f, 0.0f);
    this->__CreateWall()->Configure(1u, 0u, coreVector2(0.0f,0.0f) + vCursor, 60.0f, coreVector2(1.0f,0.0f), 0.5f*PI, 2.0f, 0.0f);

    vCursor.y += 51.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(0.0f,0.0f) + vCursor, 40.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 20.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-19.0f, 0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 19.0f, 0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(  0.0f,15.0f) + vCursor, 36.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 25.0f;
    g_pCanvas->SetDarkHeight(vCursor.y);   // #
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-4.0f, 0.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (3.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 4.0f, 0.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (3.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-2.0f, 0.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (1.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-1.0f, 2.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (2.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 1.0f, 6.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (2.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-1.0f, 8.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (2.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 2.0f,10.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (1.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-1.0f, 1.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (1.0f/3.0f) + 1.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 3.0f, 3.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (3.0f/3.0f) + 1.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 1.0f, 3.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (1.0f/3.0f) + 1.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-1.0f, 5.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (1.0f/3.0f) + 1.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-3.0f, 5.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (3.0f/3.0f) + 1.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-1.0f,10.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (2.0f/3.0f) + 1.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 3.0f, 8.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (2.0f/3.0f) + 1.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 1.0f,11.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (1.0f/3.0f) + 1.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-4.0f,12.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (3.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 4.0f,12.0f) * 35.0f * (1.0f/6.0f) + vCursor, 35.0f * (3.0f/3.0f) + 1.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 85.0f;
    this->__CreateWall()->Configure(0u, 2u, coreVector2(-22.5f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( -7.5f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2(  7.5f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( 22.5f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 2u, coreVector2(-22.5f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( -7.5f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2(  7.5f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( 22.5f,0.0f) + vCursor, 15.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 3u, coreVector2(-26.25f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2(-18.75f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2(-11.25f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2( -3.75f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2(  3.75f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2( 11.25f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( 18.75f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2( 26.25f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 2u, coreVector2(-26.25f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2(-18.75f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2(-11.25f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( -3.75f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2(  3.75f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( 11.25f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 2u, coreVector2( 18.75f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( 26.25f,0.0f) + vCursor, 7.5f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(2u, 2u, coreVector2(  0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 10.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 30.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 40.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 50.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 60.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 70.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 80.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 90.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2(100.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2(110.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);

    vCursor.y += 8.0f;
    this->__CreateWall()->Configure(2u, 2u, coreVector2(  0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 10.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 30.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 40.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 50.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 60.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 70.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 80.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 90.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2(100.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2(110.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);

    vCursor.y += 8.0f;
    this->__CreateWall()->Configure(2u, 2u, coreVector2(  0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 10.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 30.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 40.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 50.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 60.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 70.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 80.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 90.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2(100.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2(110.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);

    vCursor.y += 8.0f;
    this->__CreateWall()->Configure(2u, 2u, coreVector2(  0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 10.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 30.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 40.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 50.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 60.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 70.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 80.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 90.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2(100.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2(110.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, -10.0f, 60.0f);

    vCursor.y += 8.0f;
    this->__CreateWall()->Configure(2u, 2u, coreVector2(  0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 10.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 30.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 40.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 50.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 60.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 70.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2( 80.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2( 90.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 2u, coreVector2(100.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);
    this->__CreateWall()->Configure(2u, 3u, coreVector2(110.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 10.0f, 60.0f);

    vCursor.y += 35.0f;
    this->__CreateWall()->Configure(0u, 2u, coreVector2(-6.0f,0.0f) + vCursor, 40.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 3u, coreVector2( 6.0f,0.0f) + vCursor, 40.0f, coreVector2(1.0f,0.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 15.0f;
    this->__CreateWall()->Configure(0u, 0u, coreVector2(-19.0f, 0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2( 19.0f, 0.0f) + vCursor, 20.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 0u, coreVector2(  0.0f,15.0f) + vCursor, 36.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 20.0f;
    this->__CreateWall()->Configure(0u, 5u, coreVector2(0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 80.0f;
    this->__CreateWall()->Configure(0u, 5u, coreVector2(20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 60.0f;
    this->__CreateWall()->Configure(0u, 5u, coreVector2(-20.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 80.0f;
    this->__CreateWall()->Configure(0u, 5u, coreVector2(0.0f,0.0f) + vCursor, 10.0f, coreVector2(0.0f,1.0f), 0.0f, 0.0f, 0.0f);

    vCursor.y += 200.0f;
    this->__CreateWall()->Configure(0u, 5u, coreVector2(-8.35f,0.0f) + vCursor, 310.0f, coreVector2(1.0f,-0.05f).Normalized(), 0.0f, 0.0f, 0.0f);
    this->__CreateWall()->Configure(0u, 5u, coreVector2( 8.35f,0.0f) + vCursor, 310.0f, coreVector2(1.0f, 0.05f).Normalized(), 0.0f, 0.0f, 0.0f);

    vCursor.y += 160.0f;
    m_fTop = vCursor.y;
}