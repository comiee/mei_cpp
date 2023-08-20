file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp)
add_library(communication STATIC ${srcs})

target_include_directories(communication
PUBLIC
    include
PRIVATE
    src
)

target_link_libraries(communication communal)