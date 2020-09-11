#add_subdirectory(googletest-1.10.0)
#SET(GTEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/googletest-1.10.0)
#add_subdirectory(PathProvider)

project(scs-common--test)

cmake_minimum_required(VERSION 3.14)

set (CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED unit_test_framework)

set(tests
    main.cpp
    test_color.cpp
    test_ieee754.cpp
    test_hexcodec.cpp
    test_errormessage.cpp
)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${Boost_INCLUDE_DIR}
    ../${DIR_SRC}
)
link_directories(${Boost_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${tests})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} scs-common)

add_dependencies(${PROJECT_NAME} scs-common)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_FILE:${PROJECT_NAME}>
        ARGS --result_code=no --report_level=short
        COMMENT ==== Run unit tests ====
    )
endif(WIN32)

enable_testing()
add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})