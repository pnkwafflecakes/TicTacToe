cmake_minimum_required(VERSION 3.5)

project(hello_world LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

target_link_libraries(hello_world ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
