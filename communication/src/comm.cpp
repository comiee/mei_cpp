#include <sstream>
#include "comm.h"


void sendMsg(SOCKET socket, const string &msg) {
    int length = static_cast<int>(msg.length());
    char len_buf[6] = {0};
    sprintf(len_buf, "%05d", length);
    send(socket, len_buf, 5, 0);
    send(socket, msg.c_str(), length, 0);
}

string recvMsg(SOCKET socket) {
    char len_buf[6] = {0};
    recv(socket, len_buf, 5, 0);
    stringstream ss(len_buf);
    int length;
    ss >> length;
    char *msg_buf = new char[length];
    recv(socket, msg_buf, length, 0);
    string res(msg_buf);
    delete[] msg_buf;
    return res;
}