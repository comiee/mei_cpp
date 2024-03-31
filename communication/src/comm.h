#pragma once

#include "type.h"
#include <winsock.h>

static const char *HOST = "192.168.1.108";
static const ushort PORT = 9999;

static const uint RECONNECT_TIME = 3;
static const uint RECONNECT_COUNT = 50;

void sendMsg(SOCKET socket, const string &msg);

string recvMsg(SOCKET socket);
