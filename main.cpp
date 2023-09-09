#include "DemoClient.h"
#include "DebugMsg.h"
#include <iostream>
#include <thread>

int main() {
    DemoClient client;
    std::thread listener([&client]() { client.listenServer(); });
    string s;
    do {
        std::cin >> s;
        Json::Value ret = client.send(DebugMsg::build(s));
        std::cout << ret.asString() << std::endl;
    } while (!s.empty());
    client.close();
    listener.join();
    return 0;
}
