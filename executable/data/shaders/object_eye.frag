////////////////////////////////////////////////////
//*----------------------------------------------*//
//| Part of Ink Jump (https://www.maus-games.at) |//
//*----------------------------------------------*//
//| Copyright (c) 2024 Martin Mauersics          |//
//| Released under the zlib License              |//
//*----------------------------------------------*//
////////////////////////////////////////////////////


void FragmentMain()
{
    float v1Width = length(fwidth(v_av2TexCoord[0]));
    float v1Len   = length(v_av2TexCoord[0]);
    float v1Value = 1.0 - coreSmoothStep(1.0 - 2.0 * v1Width, 1.0, v1Len);

    gl_FragColor = vec4(vec3(1.0), v1Value) * u_v4Color;
}