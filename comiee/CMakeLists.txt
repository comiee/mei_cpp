file(GLOB_RECURSE srcs CONFIGURE_DEPENDS
    *.cpp
    **/*.cpp
)

add_library(comiee STATIC ${srcs})

target_include_directories(comiee
PUBLIC
    ..
    .
    async
)