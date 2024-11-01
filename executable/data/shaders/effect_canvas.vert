////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#include "engine/data_transform_3d.glsl"


varying vec3 v_v3Relative;


void VertexMain()
{
    gl_Position      = coreObject3DPositionLow();
    v_av2TexCoord[0] = a_v2LowTexCoord * u_v3Size.xy;

    v_v3Relative = -(u_m4Camera * vec4(coreObject3DTransformLow(), 1.0)).xyz;
}