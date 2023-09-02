file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/lib_json/*.cpp)
add_library(jsoncpp STATIC ${srcs})

target_include_directories(jsoncpp
PUBLIC
    include
PRIVATE
    src/lib_json
)

