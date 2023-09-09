#include "DebugMsg.h"
#include <iostream>

string DebugMsg::build(const string &value) {
    return getInstance()->buildMsg(value);
}

Json::Value DebugMsg::receive(const Json::Value &value) {
    std::cout << "收到：" << value.asString() << std::endl;
    return value;
}