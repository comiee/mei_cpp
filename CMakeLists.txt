cmake_minimum_required(VERSION 3.22)
project(mei)

set(CMAKE_CXX_STANDARD 23)
add_compile_options(-O2)

add_subdirectory(comiee)
add_subdirectory(jsoncpp)
add_subdirectory(communal)
add_subdirectory(communication)
add_subdirectory(demo)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} demo)

# test
add_subdirectory(test)