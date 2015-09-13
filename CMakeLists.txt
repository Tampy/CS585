cmake_minimum_required (VERSION 2.6)
project (CS585)

# GTest
enable_testing()
find_package(Threads REQUIRED)
include_directories(. /src/ext)
link_directories(/src/ext)

# version number
set (cs585_VERSION_MAJOR 1)
set (cs585_VERSION_MINOR 0)
set (QTCP_PROJECT_DIR ${.})

add_executable(CS585 game.m.cpp)
add_executable(gtest src/testing/gtest.cpp)
target_link_libraries(gtest libgtest.a)
target_link_libraries(gtest libgtest_main.a)
target_link_libraries(gtest ${CMAKE_THREAD_LIBS_INIT})
add_test(AllTests gtest)