cmake_minimum_required(VERSION 3.15..3.31)

project("template"  VERSION 1.0
                    DESCRIPTION "Template for C++ projects"
                    LANGUAGES CXX)

                    
option(ENABLE_WARNINGS "Enable warnings" ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable warnings as errors" OFF)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)

add_git_submodule("${PROJECT_SOURCE_DIR}/external/Catch2")
add_git_submodule("${PROJECT_SOURCE_DIR}/external/spdlog")

if(ENABLE_WARNINGS)
    include(Warnings)
endif()




add_subdirectory("src")
add_subdirectory("test")

