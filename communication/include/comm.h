#ifndef MEI_COMM_H
#define MEI_COMM_H

#include <winsock.h>
#include "type.h"

const string HOST="127.0.0.1";
const int PORT=9999;
const string ENCODING="utf-8";

const int RECONNECT_TIME = 3;

void sendMsg(SOCKET socket, const string& msg);

string recvMsg(SOCKET socket);


#endif //MEI_COMM_H
