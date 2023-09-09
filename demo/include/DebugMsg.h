#pragma once

#include "Message.h"

class DebugMsg : public Message {
public:
    static string build(const string &value);

    Json::Value receive(const Json::Value &value) override;

private:
    MESSAGE_INSTANCE(DebugMsg, "debug")
};
