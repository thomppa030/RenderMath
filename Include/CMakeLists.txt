set(LIBRARY_SOURCES vector3.cpp)
set(LIBRARY_INCLUDES    
    "./" 
    "${CMAKE_BINARY_DIR}/configured_files/include/")

add_library(${LIBRARY_NAME} STATIC
    "${LIBRARY_SOURCES}")
target_include_directories(${LIBRARY_NAME} PUBLIC 
    "${LIBRARY_INCLUDES}")