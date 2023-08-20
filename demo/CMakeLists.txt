file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp)
add_library(demo STATIC ${srcs})

target_include_directories(demo
PUBLIC
    include
PRIVATE
    src
)

target_link_libraries(demo communal communication)