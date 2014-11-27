cmake_minimum_required(VERSION 2.8.4)
project(graph)

include_directories(${graph_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -g -std=gnu++0x")

set(SOURCE_FILES graph.h graph_testing.cpp gtest/gtest.h gtest/gtest-all.cc gtest/gtest_main.cc)

add_executable(graph ${SOURCE_FILES})

target_link_libraries(graph -lpthread)