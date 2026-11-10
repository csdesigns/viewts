project(tstools CXX)
cmake_minimum_required(VERSION 3.5...4.5)

add_subdirectory(ext)

#---------------------------------------------------------------- target test
#source files
set(SOURCE_FILES
    test.cpp
)

include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_BINARY_DIR})
add_executable(tstool_tests ${SOURCE_FILES})
target_link_libraries(tstool_tests ${GTEST_LIBS_DIR}/libgtest.a ${GTEST_LIBS_DIR}/libgtest_main.a tstoolcheck tstoolmap)
add_dependencies(tstool_tests googletest tstoolcheck)
