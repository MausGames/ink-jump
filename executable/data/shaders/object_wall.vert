////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#include "engine/data_transform_3d.glsl"


#if defined(_CORE_OPTION_INSTANCING_)
    attribute float u_v1Length;
    attribute float u_v1LengthDiv;
#else
    uniform float u_v1Length;
    uniform float u_v1LengthDiv;
#endif


void VertexMain()
{
    vec3 v3Stretch = a_v3RawPosition;

    v3Stretch.x = (v3Stretch.x >= 0.0) ? max(v3Stretch.x + u_v1Length, 0.0) : min(v3Stretch.x - u_v1Length, 0.0);
    v3Stretch.x = (v3Stretch.x * u_v1LengthDiv);

    gl_Position = u_m4ViewProj * vec4(coreQuatApply(u_v4Rotation, v3Stretch * u_v3Size) + u_v3Position, 1.0);
}