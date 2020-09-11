cmake_minimum_required(VERSION 3.14)
project(scs-common)

set (CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11)

set(Boost_USE_STATIC_LIBS ON)

set(DIR_LIBS    libs)
set(DIR_SRC     src)
set(DIR_TESTS   tests)

add_subdirectory(${DIR_LIBS})
add_subdirectory(${DIR_SRC})

if (NOT DEFINED NO_TESTS)
    add_subdirectory(${DIR_TESTS})
endif()
