#include "comm.h"
#include "CustomException.h"
#include "tools.h"
#include <memory>


void sendEx(SOCKET socket, const string &s) {
    int len = static_cast<int>(s.length());
    if (send(socket, s.c_str(), len, 0) == SOCKET_ERROR) {
        throw SocketException("发送失败：" + s);
    }
}

string recvEx(SOCKET socket, int len) {
    std::unique_ptr<char> buf(new char[len + 1]{0});
    if (recv(socket, buf.get(), len, 0) == SOCKET_ERROR) {
        throw SocketException("接收失败：" + toString(len));
    }
    return buf.get();
}

void sendMsg(SOCKET socket, const string &msg) {
    string len = toString(msg.length());
    int n = static_cast<int>(len.length());
    sendEx(socket, stringFormat("%05d", n));
    sendEx(socket, len);
    sendEx(socket, msg);
}

string recvMsg(SOCKET socket) {
    int n = stringTo<int>(recvEx(socket, 5));
    int len = stringTo<int>(recvEx(socket, n));
    string res= recvEx(socket, len);
    return res;
}