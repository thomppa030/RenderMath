cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)
set(CMAKE_CXX_EXTENSIONS            OFF)
set(CMAKE_C_STANDARD                17)



set(EXECUTABLE_NAME                 Sandbox)
set(LIBRARY_NAME                    cmath)
set(LIBRARY_VERSION_NUMBER          0.1)

project(${LIBRARY_NAME} VERSION ${LIBRARY_VERSION_NUMBER})

option(COMPILE_EXECUTABLE "Disable for Library only builds" ON)

add_subdirectory(Include)

if(COMPILE_EXECUTABLE)
    add_subdirectory(sandbox)
endif()
