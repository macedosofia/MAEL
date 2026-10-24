cmake_minimum_required(VERSION 3.22)

project(RoboLab LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "Usar X11" FORCE)
set(GLFW_BUILD_X11 ON CACHE BOOL "Usar X11" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 6.2
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

add_executable(game
    src/main.cpp
    src/game.cpp
    src/map.cpp
    src/map_renderer.cpp
    src/character.cpp
    src/ui.cpp
)

target_include_directories(game PRIVATE include)

target_link_libraries(game PRIVATE raylib)
