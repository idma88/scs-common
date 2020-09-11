для преобразования строк между "сырым" (ASCII) и шестнадцатеричным представлениямиproject(scs-common)

cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost)

set(src_color
    color.h
    color.cpp
)

set(src_errormessage
    errormessage.h
    errormessage.cpp
)

set(src_hexcodec
    hexcodec.h
    hexcodec.cpp
)

set(src_ieee754
    ieee754.h
    ieee754.cpp
)

set(src_others
    algoritms.h
)

set(sources
    ${src_color}
    ${src_errormessage}
    ${src_hexcodec}
    ${src_ieee754}
    ${src_others}
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${Boost_INCLUDE_DIR}
)
link_directories(${Boost_LIBRARY_DIRS})

add_library(${PROJECT_NAME} STATIC ${sources})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})