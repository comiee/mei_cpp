project(communication)

file(GLOB_RECURSE SOURCES "src/*.cpp")

target_link_directories(PROJECT_NAME PUBLIC include)

add_library(PROJECT_NAME STATIC SOURCES)
