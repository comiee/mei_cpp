file(GLOB_RECURSE srcs CONFIGURE_DEPENDS src/*.cpp)
add_library(communication STATIC ${srcs})

target_include_directories(communication
PUBLIC
    include
PRIVATE
    src
)

target_link_libraries(communication comiee communal jsoncpp)

if(WIN32)
    # 链接 Windows 平台的库文件
    target_link_libraries(communication ws2_32.lib)
elseif(UNIX)
    # 链接 Linux 平台的库文件
endif()
