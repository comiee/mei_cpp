#include "AsyncClient.h"
#include "log.h"
#include <thread>
#include <cassert>

Logger logger("test_async", Logger::DEBUG);
std::vector<string> result;

Task debug(string s) {
    AsyncClient client("debug");
    logger.debug("line:%d, str:%s", __LINE__, s.c_str());
    WAIT(client.connectSock())
    logger.debug("line:%d, str:%s", __LINE__, s.c_str());
    WAIT(res, client.send(s))
    logger.debug("line:%d, str:%s, res:%s, remain:%d",
                 __LINE__, s.c_str(), std::get<string>(res).c_str(), getLoop().size());
    result.push_back(s);
}

Task h_pic() {
    AsyncClient client("h_pic");
    WAIT(client.connectSock())
    WAIT(res, client.send(JsonTool::createObject("r18", 2)))
    println("url: ", std::get<Json::Value>(res)["data"]);
}

int main() {
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
    return 0;
}