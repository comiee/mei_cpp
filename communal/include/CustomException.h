#pragma once

#include "type.h"
#include <exception>

class CustomException : public std::exception {
public:
    explicit CustomException(string msg) : msg(std::move(msg)) {}

    explicit CustomException(const char *msg) : msg(msg) {}

    inline const char *getMsg() { return msg.c_str(); }

private:
    string msg;
};

#define THROW_IF(__condition__, __exception__) \
if (__condition__) {                           \
    throw __exception__;                       \
}

#define DEFINE_EXCEPTION(__name__) \
class __name__ : public CustomException { \
public: \
    explicit __name__(string msg) : CustomException(std::move(msg)) {} \
    explicit __name__(const char *msg) : CustomException(msg) {} \
};

// 构造/解析Json时发生的错误
DEFINE_EXCEPTION(JsonException)
// 构造/解析消息时发生的错误
DEFINE_EXCEPTION(MessageException)
// 使用socket通信时发生的错误
DEFINE_EXCEPTION(SocketException)
// 缓存区不足
DEFINE_EXCEPTION(BufferNotEnoughException)
// 内存错误（越界访问、空指针、野指针等）
DEFINE_EXCEPTION(MemoryException)
