cmake_minimum_required(VERSION 3.18.3)

set(PROJECT_NAME Quadratic_Polynomial_Solver)

project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE debug)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-g -std=c++17 -Wall")

include_directories(include)

# add all files cpp and hpp files to the project

file(GLOB SOURCES "./src/*.cpp" "./*.hpp")
add_executable(${PROJECT_NAME} ${SOURCES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})


message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
