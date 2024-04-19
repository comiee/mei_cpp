#if __linux__

#include "sock.h"
#include "CustomException.h"
#include <unistd.h>
#include <fcntl.h>

void wsaInit() {
}

void wsaClear() {
}

void closeSocket(SOCKET sock) {
    close(sock);
}

void setNotBlock(SOCKET sock) {
    THROW_IF(fcntl(sock, F_GETFL, 0) == -1,
             SocketException("设置非阻塞模式失败"));
}

#endif