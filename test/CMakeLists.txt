file(GLOB_RECURSE srcs CONFIGURE_DEPENDS ./*.cpp)

function(add_exec name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} communication communal jsoncpp demo)
endfunction()

add_exec(test_async)
add_exec(test_generator)
add_exec(test_json)
add_exec(test_message)
add_exec(test_tools)
add_exec(test_client)