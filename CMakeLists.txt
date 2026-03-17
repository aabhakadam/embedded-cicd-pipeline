cmake_minimum_required(VERSION 3.14)
project(EmbeddedCICD)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest QUIET)
if(NOT GTest_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
    )
    FetchContent_MakeAvailable(googletest)
endif()

add_library(sensor_lib src/sensor.cpp)
target_include_directories(sensor_lib PUBLIC src/)

add_executable(sensor_main src/main.cpp)
target_link_libraries(sensor_main sensor_lib)

add_executable(run_tests tests/test_sensor.cpp)
target_link_libraries(run_tests sensor_lib GTest::gtest_main)

enable_testing()
add_test(NAME SensorTests COMMAND run_tests)
