cmake_minimum_required (VERSION 2.6)
project (CS585)

# GTest
enable_testing()
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ..)

# version number
set (cs585_VERSION_MAJOR 1)
set (cs585_VERSION_MINOR 0)
set (QTCP_PROJECT_DIR ${..})

add_executable(CS585 ../game.m.cpp)
add_executable(gtest ../src/testing/gtest.cpp)
add_library(square ../src/testing/square.cpp)
target_link_libraries(CS585 square)
target_link_libraries(gtest libgtest.a libgtest_main.a ${CMAKE_THREAD_LIBS_INIT} square)
add_test(AllTests gtest)