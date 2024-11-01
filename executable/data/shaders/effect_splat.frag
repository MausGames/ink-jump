////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#include "engine/util_color.glsl"


varying float v_v1Height;


void FragmentMain()
{
    vec3  v3Tone  = coreHsvToRgb(vec3(mod(v_v1Height, 1.0), 0.8, 0.85));
    float v1Value = coreTexture2D(0, v_av2TexCoord[0]).r;

    gl_FragColor = vec4(v3Tone, v1Value) * u_v4Color;
}