cmake_minimum_required(VERSION 3.25)
project(test)

set(CMAKE_CXX_STANDARD 23)

target_include_directories(test public communication)
target_link_libraries(test public communication)

add_subdirectory(communication)

add_executable(test test.cpp)
