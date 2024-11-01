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
    float v1Value = coreTexture2D(0, v_av2TexCoord[0]).r;

    gl_FragColor = vec4(vec3(1.0), v1Value) * u_v4Color;
}