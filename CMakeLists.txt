cmake_minimum_required(VERSION 3.24.1)

project(CommandLine)

add_subdirectory(googletest)

file(GLOB TEST_SRC_FILES
    "test/*.cpp"
)

file(GLOB LIB_SRC_FILES
    "src/*.cpp"
)

# add_library(${PROJECT_NAME} STATIC ${SRC_FILES} ${HEADER_FILES})
add_executable(${PROJECT_NAME}_test test.cpp ${TEST_SRC_FILES} ${LIB_SRC_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_directories(${PROJECT_NAME}_test
    PRIVATE BEFORE ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

target_link_libraries(${PROJECT_NAME}_test gtest)