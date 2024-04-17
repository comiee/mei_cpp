#include <thread>
#include "AsyncClient.h"

Task debug(string s) {
    AsyncClient client("debug");
    PRINT_FUN(s);
    WAIT(client.connectSock())
    PRINT_FUN(s);
    WAIT(res, client.send(s))
    PRINT_FUN(s);
    println(std::get<string>(res), getLoop().size());
}

Task h_pic() {
    AsyncClient client("h_pic");
    WAIT(client.connectSock())
    WAIT(res, client.send(JsonTool::createObject("r18", 2)))
    println(std::get<Json::Value>(res)["data"]);
}

void testAsyncMain() {
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(1, 1), &wsa_data);
    std::thread loop_thread([]() { getLoop().run(/*true*/); });
    getLoop().add(debug("3"));
    getLoop().add(debug("2"));
    getLoop().add(debug("1"));
    getLoop().add(h_pic());
    println(getLoop().size());
    loop_thread.join();
    WSACleanup();
}