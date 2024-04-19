#pragma once

#ifdef _WIN32

#include <winsock.h>

#elif __linux__

#include <pcap/pcap.h>

#define Sleep sleep
#define SOCKET_ERROR -1

#endif

#include "type.h"

void wsaInit();

void wsaClear();

void closeSocket(SOCKET sock);

void setNotBlock(SOCKET sock);
