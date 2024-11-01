////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////
#include "engine/util_color.glsl"


uniform float u_v1Time;

varying vec3 v_v3Relative;


void FragmentMain()
{
    float v1Intensity = normalize(v_v3Relative).z * inversesqrt(coreLengthSq(v_v3Relative)) * 45.0;
    float v1Pattern   = 0.8 + 0.1 * smoothstep(-0.05, 0.05, sin(dot(v_av2TexCoord[0], normalize(vec2(1.0, 1.0))) * 0.5 - u_v1Time));

    gl_FragColor = vec4(vec3(v1Intensity * mix(v1Pattern, 0.85, 0.0)) + vec3(coreDither() / 100.0), 1.0) * u_v4Color;
}