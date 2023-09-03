#ifndef MEI_CUSTOM_EXCEPTION_H
#define MEI_CUSTOM_EXCEPTION_H

#include "type.h"
#include <exception>

class CustomException : public std::exception {
public:
    explicit CustomException(string msg) : msg(std::move(msg)) {}

    explicit CustomException(const char *msg) : msg(msg) {}

    inline string getMsg() { return msg; }

private:
    string msg;
};

#define DEFINE_EXCEPTION(__name__) \
class __name__ : public CustomException { \
public: \
    explicit __name__(string msg) : CustomException(std::move(msg)) {} \
    explicit __name__(const char *msg) : CustomException(msg) {} \
};

DEFINE_EXCEPTION(JsonException)

#endif //MEI_CUSTOM_EXCEPTION_H
