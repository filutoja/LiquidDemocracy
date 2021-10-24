cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)

project(LiquidDemocracy)

add_library(VoutsCounter SHARED votes_counter.cpp
                                votes_counter.h
                                node.cpp
                                node.h)

add_executable(LiquidDemocracy main.cpp)
target_link_libraries(LiquidDemocracy VoutsCounter)

add_executable(UTLiquidDemocracy ut_main.cpp
                                 votes_counter_unittests.cpp)
target_link_libraries(UTLiquidDemocracy VoutsCounter gtest_main gtest pthread)
