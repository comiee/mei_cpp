#pragma once

#include "type.h"
#include "json/json.h"

class Receiver {
public:
    virtual Json::Value receive(const Json::Value &value) = 0;

    static Json::Value parse(const string &message);

protected:
    static void registerReceiver(const string &cmd, Receiver *receiver);
};
