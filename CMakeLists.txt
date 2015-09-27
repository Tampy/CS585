cmake_minimum_required (VERSION 2.6)
project (CS585)
add_definitions(-std=c++11)

# GTest
enable_testing()
find_package(Threads REQUIRED)
include_directories(. src/ext/gtest-1.7.0/include src/engine)
link_directories(/src/ext)
add_subdirectory(src/ext/gtest-1.7.0)

# version number
set (cs585_VERSION_MAJOR 1)
set (cs585_VERSION_MINOR 0)
set (QTCP_PROJECT_DIR ${.})

add_executable(CS585 game.m.cpp)
add_executable(gtest_CS585 src/testing/gtest.cpp)
target_link_libraries(gtest_CS585 gtest ${CMAKE_THREAD_LIBS_INIT})
add_test(AllTests gtest_CS585)
