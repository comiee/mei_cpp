cmake_minimum_required(VERSION 3.25)
project(mei)

set(CMAKE_CXX_STANDARD 23)


include_directories(
        demo
        communication
        communal
)

file(GLOB SOURCES
        main.cpp
        demo/*.cpp
        communication/*.cpp
        communal/*.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})
