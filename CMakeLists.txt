cmake_minimum_required(VERSION 3.15...3.31)

project(moonVeil VERSION 1.0 LANGUAGES CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;--config-file=${CMAKE_SOURCE_DIR}/.clang-tidy")
option(ENABLE_WARNINGS "Enable warnings" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable warnings as errors" OFF)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)

add_git_submodule("${PROJECT_SOURCE_DIR}/external/Catch2")
add_git_submodule("${PROJECT_SOURCE_DIR}/external/spdlog")


set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/external/raylib")
add_subdirectory(${RAYLIB_DIR})
add_git_submodule("${PROJECT_SOURCE_DIR}/external/raylib-tmx")
set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/external/imgui")
add_subdirectory(${IMGUI_DIR})

set(RLIMGUI_DIR "${CMAKE_SOURCE_DIR}/external/rlImGui")
add_subdirectory(${RLIMGUI_DIR})
if(ENABLE_WARNINGS)
    include(Warnings)
endif()

add_subdirectory("src")
add_subdirectory("test")


