set(SANDBOX_SOURCES "rendermath.cpp")
add_executable(${EXECUTABLE_NAME} "${SANDBOX_SOURCES}")
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${LIBRARY_NAME})