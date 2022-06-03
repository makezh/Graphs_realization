cmake_minimum_required(VERSION 3.22)
project(Graphs)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} test.cpp)
include_directories(headers src)
target_include_directories(${PROJECT_NAME} PUBLIC headers src)
file(GLOB sources "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(graph_lib STATIC ${sources})
target_link_libraries(${PROJECT_NAME} PRIVATE graph_lib)



