#pragma once

#include "type.h"
#include "sock.h"

static const char *HOST = "172.17.176.1";
static const ushort PORT = 9999;
static const ushort ASYNC_PORT = 9998;

static const uint RECONNECT_TIME = 3;
static const uint RECONNECT_COUNT = 50;

void sendMsg(SOCKET socket, const string &msg);

string recvMsg(SOCKET socket);
