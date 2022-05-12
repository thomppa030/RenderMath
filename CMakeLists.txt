cmake_minimum_required(VERSION 3.22)

set(LIBRARY_NAME RenderMath)
set(LIBRARY_VERSION_NUMBER 0.1)

project(${LIBRARY_NAME} VERSION ${LIBRARY_VERSION_NUMBER})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

add_executable(${LIBRARY_NAME} sandbox/rendermath.cpp)
