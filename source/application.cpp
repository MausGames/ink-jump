///////////////////////////////////////////////
//*-----------------------------------------*//
//| Auto-Generated by the Core Engine       |//
//| Direct modifications may be overwritten |//
//*-----------------------------------------*//
///////////////////////////////////////////////
#include "main.h"


// ****************************************************************
// project settings
const coreChar* const CoreApp::Settings::Name                          = "Ink Jump";
const coreChar* const CoreApp::Settings::Version                       = "1.0.0";
const coreChar* const CoreApp::Settings::IconPath                      = "data/textures/game_icon.webp";
const coreChar* const CoreApp::Settings::CursorPath                    = "data/textures/default_cursor.webp";
const coreBool        CoreApp::Settings::UserManagement                = false;
const coreUint8       CoreApp::Settings::Graphics::DepthSize           = 16u;
const coreUint8       CoreApp::Settings::Graphics::StencilSize         = 0u;
const coreBool        CoreApp::Settings::Graphics::AlphaChannel        = false;
const coreBool        CoreApp::Settings::Graphics::DoubleBuffer        = true;
const coreBool        CoreApp::Settings::Graphics::StereoRender        = false;
const coreUint32      CoreApp::Settings::Platform::SteamAppID[2]       = {0u, 0u};
const coreChar* const CoreApp::Settings::Platform::EpicProductID       = NULL;
const coreChar* const CoreApp::Settings::Platform::EpicSandboxID   [3] = {NULL, NULL, NULL};
const coreChar* const CoreApp::Settings::Platform::EpicDeploymentID[3] = {NULL, NULL, NULL};
const coreChar* const CoreApp::Settings::Platform::EpicClientID        = NULL;
const coreChar* const CoreApp::Settings::Platform::EpicClientSecret    = NULL;

coreBool CoreApp::Settings::IsDemo() {return false;}


// ****************************************************************
// setup the application
void CoreApp::Setup()
{
    Core::Manager::Resource->Load<coreModel>  ("object_arrow.md3z",       CORE_RESOURCE_UPDATE_AUTO,   "data/models/object_arrow.md3z", CORE_MODEL_LOAD_NO_CLUSTERS);
    Core::Manager::Resource->Load<coreModel>  ("object_wall.md3z",        CORE_RESOURCE_UPDATE_AUTO,   "data/models/object_wall.md3z", CORE_MODEL_LOAD_NO_CLUSTERS);

    Core::Manager::Resource->Load<coreTexture>("effect_splat.webp",       CORE_RESOURCE_UPDATE_AUTO,   "data/textures/effect_splat.webp", CORE_TEXTURE_LOAD_R);
    Core::Manager::Resource->Load<coreTexture>("point.webp",              CORE_RESOURCE_UPDATE_AUTO,   "data/textures/point.webp", CORE_TEXTURE_LOAD_R);

    Core::Manager::Resource->Load<coreShader> ("effect_canvas.vert",      CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/effect_canvas.vert", CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("effect_canvas.frag",      CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/effect_canvas.frag");
    Core::Manager::Resource->Load<coreShader> ("effect_dark.vert",        CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/effect_dark.vert", CORE_SHADER_OPTION_NO_ROTATION);
    Core::Manager::Resource->Load<coreShader> ("effect_dark.frag",        CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/effect_dark.frag");
    Core::Manager::Resource->Load<coreShader> ("effect_splat.vert",       CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/effect_splat.vert");
    Core::Manager::Resource->Load<coreShader> ("effect_splat.frag",       CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/effect_splat.frag");
    Core::Manager::Resource->Load<coreShader> ("effect_splat_inst.vert",  CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/effect_splat.vert", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("effect_splat_inst.frag",  CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/effect_splat.frag", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("object_arrow.vert",       CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_arrow.vert");
    Core::Manager::Resource->Load<coreShader> ("object_arrow.frag",       CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_arrow.frag");
    Core::Manager::Resource->Load<coreShader> ("object_arrow_inst.vert",  CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_arrow.vert", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("object_arrow_inst.frag",  CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_arrow.frag", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("object_wall.vert",        CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_wall.vert");
    Core::Manager::Resource->Load<coreShader> ("object_wall.frag",        CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_wall.frag");
    Core::Manager::Resource->Load<coreShader> ("object_wall_inst.vert",   CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_wall.vert", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("object_wall_inst.frag",   CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/object_wall.frag", CORE_SHADER_OPTION_INSTANCING);
    Core::Manager::Resource->Load<coreShader> ("point.frag",              CORE_RESOURCE_UPDATE_MANUAL, "data/shaders/point.frag", CORE_SHADER_OPTION_NO_ROTATION);

    Core::Manager::Resource->Load<coreSound>  ("jump.opus",               CORE_RESOURCE_UPDATE_AUTO,   "data/sounds/jump.opus", CORE_SOUND_LOAD_MULAW);
    Core::Manager::Resource->Load<coreSound>  ("stick.opus",              CORE_RESOURCE_UPDATE_AUTO,   "data/sounds/stick.opus", CORE_SOUND_LOAD_MULAW);

    Core::Manager::Resource->Load<coreFont>   ("inkpoint.ttf",            CORE_RESOURCE_UPDATE_AUTO,   "data/fonts/inkpoint.ttf");

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("effect_canvas_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("effect_canvas.vert")
        ->AttachShader("effect_canvas.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("effect_dark_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("effect_dark.vert")
        ->AttachShader("effect_dark.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("effect_splat_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("effect_splat.vert")
        ->AttachShader("effect_splat.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("effect_splat_inst_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("effect_splat_inst.vert")
        ->AttachShader("effect_splat_inst.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_arrow_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_arrow.vert")
        ->AttachShader("object_arrow.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_arrow_inst_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_arrow_inst.vert")
        ->AttachShader("object_arrow_inst.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_wall_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("object_wall.vert")
        ->AttachShader("object_wall.frag")
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("object_wall_inst_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader ("object_wall_inst.vert")
        ->AttachShader ("object_wall_inst.frag")
        ->BindAttribute("u_v1Length",    WALL_SHADER_ATTRIBUTE_LENGTH_NUM)
        ->BindAttribute("u_v1LengthDiv", WALL_SHADER_ATTRIBUTE_LENGTHDIV_NUM)
        ->Finish();

    d_cast<coreProgram*>(Core::Manager::Resource->Load<coreProgram>("point_program", CORE_RESOURCE_UPDATE_AUTO, NULL)->GetRawResource())
        ->AttachShader("default_2d.vert")
        ->AttachShader("point.frag")
        ->Finish();
}