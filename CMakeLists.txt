cmake_minimum_required (VERSION 2.6)
project (CS585)
add_definitions(-std=c++11)
cmake_policy(SET CMP0009 OLD)

link_directories(/src/ext)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/src/ext" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)

# GTest
enable_testing()
find_package(Threads REQUIRED)
file(GLOB_RECURSE SOURCES "src/engine/*.cpp" "src/game/*.cpp")
file(GLOB_RECURSE HEADERS "src/engine/*.h" "src/game/*.cpp")
include_directories(src/ext/gtest-1.7.0/include ${SFML_INCLUDE_DIR} src/engine src/game)
add_subdirectory(src/ext/gtest-1.7.0 src/ext/SFML-2.3.2)

# version number
set (cs585_VERSION_MAJOR 1)
set (cs585_VERSION_MINOR 0)
set (QTCP_PROJECT_DIR ${.})

add_executable(CS585 game.m.cpp ${SOURCES} ${HEADERS})
add_executable(gtest_CS585 src/testing/gtest.cpp ${SOURCES} ${HEADERS})
target_link_libraries(CS585 ${SFML_LIBRARIES})
target_link_libraries(gtest_CS585 gtest ${CMAKE_THREAD_LIBS_INIT} ${SFML_LIBRARIES})
add_test(AllTests gtest_CS585)