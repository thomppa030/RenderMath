cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

set(EXECUTABLE_NAME RenderMath)
set(LIBRARY_NAME cmath)
set(LIBRARY_VERSION_NUMBER 0.1)

project(${LIBRARY_NAME} VERSION ${LIBRARY_VERSION_NUMBER})

add_subdirectory(Include)
add_subdirectory(sandbox)