#include "comm.h"
#include "CustomException.h"
#include <sstream>

void sendMsg(SOCKET socket, const string &msg) {
    int length = static_cast<int>(msg.length());
    char len_buf[6] = {0};
    sprintf(len_buf, "%05d", length);
    if (send(socket, len_buf, 5, 0) == SOCKET_ERROR) {
        throw SocketException("发送消息长度失败");
    }
    if (send(socket, msg.c_str(), length, 0) == SOCKET_ERROR) {
        throw SocketException("发送消息内容失败");
    }
}

string recvMsg(SOCKET socket) {
    char len_buf[6] = {0};
    if (recv(socket, len_buf, 5, 0) == SOCKET_ERROR) {
        throw SocketException("接收消息长度失败");
    }
    std::stringstream ss(len_buf);
    int length;
    ss >> length;
    char *msg_buf = new char[length + 1]{0};
    if (recv(socket, msg_buf, length, 0) == SOCKET_ERROR) {
        throw SocketException("接收消息内容失败");
    }
    string res(msg_buf);
    delete[] msg_buf;
    return res;
}