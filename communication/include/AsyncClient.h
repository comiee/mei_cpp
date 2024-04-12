#pragma once

#include "type.h"
#include "Loop.h"
#include <winsock.h>

class AsyncClient {
public:
    explicit AsyncClient(string cmd);

    Future<void> connectSock();

    [[nodiscard]] Future<string> send(const string &message) const;

    void close() const;

    ~AsyncClient();

private:
    [[nodiscard]] Future<string> receive() const;

    const string cmd;
    SOCKET sock = INVALID_SOCKET;
};

Loop &getLoop();