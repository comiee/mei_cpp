#pragma once

#include "Message.h"

class RegisterMsg : public Message {
public:
    static string build(const string &name, const string &type);

private:
    MESSAGE_INSTANCE(RegisterMsg, "register")
};
