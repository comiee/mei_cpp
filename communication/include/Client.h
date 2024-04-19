#pragma once

#include "type.h"
#include "json/json.h"
#include "sock.h"

class Client {
public:
    explicit Client(string name);

    string getName();

    Json::Value send(const string &message);

    void listenServer();

    void close() const;

    ~Client();

private:
    SOCKET registerClient(const string &client_type);

    const string name;
    SOCKET sender = INVALID_SOCKET;
    SOCKET receiver = INVALID_SOCKET;
};
