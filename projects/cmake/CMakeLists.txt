cmake_minimum_required(VERSION 3.25)

set(BASE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(ENGINE_DIRECTORY ${BASE_DIRECTORY}/../core-engine)

project(InkJump VERSION 1.0.0)
add_subdirectory(${ENGINE_DIRECTORY}/projects/cmake CoreEngine)
add_executable(InkJump)

set_target_properties(
    InkJump PROPERTIES
    C_STANDARD 17
    CXX_STANDARD 23
    DEBUG_POSTFIX _debug
    BUILD_WITH_INSTALL_RPATH TRUE
    INSTALL_RPATH $ORIGIN
)

target_sources(
    InkJump PRIVATE
    ${BASE_DIRECTORY}/source/Arrow.cpp
    ${BASE_DIRECTORY}/source/Canvas.cpp
    ${BASE_DIRECTORY}/source/Game.cpp
    ${BASE_DIRECTORY}/source/Interface.cpp
    ${BASE_DIRECTORY}/source/Level.cpp
    ${BASE_DIRECTORY}/source/Path.cpp
    ${BASE_DIRECTORY}/source/Wall.cpp
    ${BASE_DIRECTORY}/source/application.cpp
    ${BASE_DIRECTORY}/source/main.cpp
)

target_include_directories(
    InkJump PRIVATE
    ${BASE_DIRECTORY}/source
)

target_precompile_headers(
   InkJump PRIVATE
   $<$<COMPILE_LANGUAGE:CXX>: ${BASE_DIRECTORY}/source/main.h>
)

target_link_libraries(
    InkJump PRIVATE
    CoreEngine
)

if(CORE_EMSCRIPTEN)

    set_target_properties(
        InkJump PROPERTIES
        SUFFIX .html
        RUNTIME_OUTPUT_DIRECTORY ${BASE_DIRECTORY}/executable/bin/emscripten/
    )

else()

    set_target_properties(
        InkJump PROPERTIES
        SUFFIX .elf
        RUNTIME_OUTPUT_DIRECTORY ${BASE_DIRECTORY}/executable/bin/linux_x86_64/
    )

    if(NOT CORE_DEBUG)

        add_custom_command(
            TARGET InkJump POST_BUILD
            COMMAND ${ENGINE_DIRECTORY}/tools/scripts/extract_symbols.sh $<TARGET_FILE:InkJump>
        )

    endif()

endif()