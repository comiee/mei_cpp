#if __linux__

#include "sock.h"
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
    int flags = fcntl(sock, F_GETFL);
    flags |= O_NONBLOCK;
    fcntl(sock, F_SETFL, flags);
}

#endif