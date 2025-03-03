////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#pragma once
#ifndef _INJ_GUARD_UTILITIES_H_
#define _INJ_GUARD_UTILITIES_H_


// ****************************************************************
inline coreFloat FrictionFactor(const coreFloat fStrength)
{
    return POW(1.0f - fStrength * (1.0f / 60.0f), TIME * 60.0f);
}


#endif // _INJ_GUARD_UTILITIES_H_