file(GLOB_RECURSE srcs CONFIGURE_DEPENDS ./*.cpp)

add_executable(test ${srcs})

target_link_libraries(test communication jsoncpp)
