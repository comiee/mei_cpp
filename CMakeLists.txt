cmake_minimum_required(VERSION 3.25)
project(mei)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-O2)

add_subdirectory(communal)
add_subdirectory(communication)
add_subdirectory(demo)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} communication) # TODO 后续换成demo

# test
add_subdirectory(test)