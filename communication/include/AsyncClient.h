#pragma once

#include "type.h"
#include "EventLoop.h"
#include "JsonTool.h"
#include <winsock.h>
#include <variant>

class AsyncClient {
public:
    using MessageType = std::variant<const char *, string, Json::Value>;

    explicit AsyncClient(string cmd);

    [[nodiscard]] Future<void> connectSock(); // 加nodiscard防止未等待结果

    [[nodiscard]] Future<MessageType> send(MessageType obj); // 需要从其他类型的对象创建MessageType对象，这里一定不能用引用

    void close() const;

    ~AsyncClient();

private:
    string messageEncode(const MessageType &obj);

    MessageType messageDecode(const string &message);

    [[nodiscard]] Future<string> receive() const;

    const string cmd;
    SOCKET sock = INVALID_SOCKET;
};

EventLoop &getLoop();