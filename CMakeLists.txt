cmake_minimum_required(VERSION 3.17)
project(learn-opengl)

set(CMAKE_CXX_STANDARD 20)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")

file(GLOB SOURCE_FILES
        main.cpp
        )

add_subdirectory(src/vendor/GLFW)
add_subdirectory(src/vendor/GLAD)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/GLFW/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/GLAD/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/stb_image
        ${CMAKE_CURRENT_SOURCE_DIR}/src/vendor/glm
)

target_link_libraries(${PROJECT_NAME} glfw Glad opengl32)