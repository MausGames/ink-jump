////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#include "engine/data_transform_3d.glsl"


varying float v_v1Height;


void VertexMain()
{
    gl_Position      = coreObject3DPositionLow();
    v_av2TexCoord[0] = coreObject3DTexCoordLow();

    v_v1Height = coreObject3DTransformRaw().y * 0.002 + 0.6;
}