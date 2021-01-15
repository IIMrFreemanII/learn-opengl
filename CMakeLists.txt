cmake_minimum_required(VERSION 3.17)
project(learn-opengl)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES
        main.cpp
        src/vendor/stb_image/stb_image.cpp
        src/vendor/stb_image/stb_image.h
        src/Shader.h
        src/Camera.h
        src/ImGui/ImGuiBuild.cpp
        src/Mesh.h
        src/Model.h
        )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")
add_subdirectory(src/vendor/GLFW)

add_subdirectory(src/vendor/GLAD)
add_subdirectory(src/vendor/imgui)

set(BUILD_SHARED_LIBS ON)
set(ASSIMP_INSTALL OFF)
add_subdirectory(src/vendor/assimp)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        src
        src/vendor/GLFW/include
        src/vendor/GLAD/include
        src/vendor/stb_image
        src/vendor/glm
        src/vendor/imgui
        src/vendor/assimp/include
)

target_link_directories(${PROJECT_NAME} PUBLIC src/vendor/assimp/lib)

target_link_libraries(${PROJECT_NAME} glfw Glad ImGui opengl32 assimp)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_custom_command(
            TARGET
            ${PROJECT_NAME}
            POST_BUILD COMMAND
            ${CMAKE_COMMAND} -E copy
            "${CMAKE_BINARY_DIR}/src/vendor/assimp/bin/libassimp${CMAKE_DEBUG_POSTFIX}.dll"
            ${CMAKE_BINARY_DIR}/.
    )
else()
    add_custom_command(
            TARGET
            ${PROJECT_NAME}
            POST_BUILD COMMAND
            ${CMAKE_COMMAND} -E copy
            "${CMAKE_BINARY_DIR}/src/vendor/assimp/bin/libassimp.dll"
            ${CMAKE_BINARY_DIR}/.
    )
endif()