#include <thread>
#include "AsyncClient.h"
#include "print.h"

Task debug(string s) {
    AsyncClient client("debug");
    PRINT_FUN(s);
    WAIT(client.connectSock())
    PRINT_FUN(s);
    WAIT(res, client.send(s))
    PRINT_FUN(s);
    println(res, getLoop().size());
}

void testAsyncMain() {
    WSADATA wsa_data;
    WSAStartup(MAKEWORD(1, 1), &wsa_data);
    std::thread loop_thread([]() { getLoop().run(/*true*/); });
    getLoop().add(debug("3"));
    getLoop().add(debug("2"));
    getLoop().add(debug("1"));
    println(getLoop().size());
    loop_thread.join();
    WSACleanup();
}