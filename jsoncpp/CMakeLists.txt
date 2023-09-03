file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
        src/lib_json/*.cpp
        src/*.cpp
)

add_library(jsoncpp STATIC ${srcs})

target_include_directories(jsoncpp
PUBLIC
    include
PRIVATE
    src/lib_json
    src
)

target_link_libraries(jsoncpp communal)
