#include "DemoClient.h"
#include "DebugMsg.h"
#include "tools.h"
#include <thread>

void testMultiMsg() {
    DemoClient client;
    client.send(DebugMsg::build("test"));
    std::thread ts[30];
    for(std::thread&t:ts){
        t=std::thread([&](){
            client.send(DebugMsg::build(toString(&t-ts)));
        });
    }
    for(std::thread&t:ts){
        t.join();
    }
}

int main() {
    testMultiMsg();
    return 0;
}