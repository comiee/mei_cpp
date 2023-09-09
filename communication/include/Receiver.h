#ifndef MEI_RECEIVER_H
#define MEI_RECEIVER_H

#include "type.h"
#include "jsonTool.h"

class Receiver {
public:
    virtual Json::Value receive(const Json::Value &value) = 0;

    static Json::Value parse(const string &message);

protected:
    static void registerMessage(const string &cmd, Receiver *receiver);
};

#endif //MEI_RECEIVER_H
