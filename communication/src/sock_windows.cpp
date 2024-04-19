#ifdef _WIN32

#include "sock.h"
#include "CustomException.h"

void wsaInit() {
    WSADATA wsa_data;
    THROW_IF(WSAStartup(MAKEWORD(1, 1), &wsa_data) != 0,
             SocketException("初始化socket失败"))
}

void wsaClear() {
    WSACleanup();
}

void closeSocket(SOCKET sock) {
    closesocket(sock);
}

void setNotBlock(SOCKET sock) {
    int iMode = 1;
    THROW_IF(ioctlsocket(sock, FIONBIO, (u_long FAR *)&iMode) != 0,
             SocketException("设置非阻塞模式失败"));
}

#endif