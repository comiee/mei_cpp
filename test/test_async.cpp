#include <thread>
#include <cassert>
#include "AsyncClient.h"

std::vector<string> result;

Task debug(string s) {
    AsyncClient client("debug");
    PRINT_FUN(s);
    WAIT(client.connectSock())
    PRINT_FUN(s);
    WAIT(res, client.send(s))
    PRINT_FUN(s);
    println(std::get<string>(res), getLoop().size());
    result.push_back(s);
}

Task h_pic() {
    AsyncClient client("h_pic");
    WAIT(client.connectSock())
    WAIT(res, client.send(JsonTool::createObject("r18", 2)))
    PRINT_FUN(res.index());
    println("url: ", std::get<Json::Value>(res)["data"]);
    PRINT_FUN();
}

void testAsyncMain() {
    std::thread loop_thread([]() { getLoop().run(/*true*/); });
    getLoop().add(debug("3"));
    getLoop().add(debug("2"));
    getLoop().add(debug("1"));
    getLoop().add(h_pic());
    println(getLoop().size());
    loop_thread.join();
    assert(result[0] == "1");
    assert(result[1] == "2");
    assert(result[2] == "3");
}