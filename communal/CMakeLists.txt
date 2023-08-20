file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp)
add_library(communal STATIC ${srcs})

target_include_directories(communal
PUBLIC
    include
PRIVATE
    src
)