#pragma once

#include "Receiver.h"
#include "simple.h"

class Message : public Receiver {
public:
    Json::Value receive(const Json::Value &value) override;

    Message(const Message &other) = delete;

    const Message &operator=(const Message &other) = delete;

protected:
    explicit Message(const string &cmd);

    string buildMsg(const Json::Value &value);

private:
    const string cmd;
};

#define MESSAGE_INSTANCE(__cls__, __cmd__) \
INSTANCE(__cls__) \
__cls__() : Message(__cmd__) {}
