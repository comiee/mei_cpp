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

// NOLINTBEGIN
#define DEFINE_EXCEPTION(__name__) \
class __name__ : public CustomException { \
public: \
    explicit __name__(string msg) : CustomException(std::move(msg)) {} \
    explicit __name__(const char *msg) : CustomException(msg) {} \
};
// NOLINTEND

// 构造/解析Json时发生的错误
DEFINE_EXCEPTION(JsonException)
// 构造/解析消息时发生的错误
DEFINE_EXCEPTION(MessageException)
// 使用socket通信时发生的错误
DEFINE_EXCEPTION(SocketException)
