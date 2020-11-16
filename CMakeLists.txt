cmake_minimum_required(VERSION 3.6 FATAL_ERROR)

project(stack)

include(cmake/function.cmake)

add_subdirectory(function_lib)
add_subdirectory(main)

option(BTEST "build test?" Yes)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()
