#ifndef MEI_RESULTMSG_H
#define MEI_RESULTMSG_H

#include "Message.h"

class ResultMsg : public Message {
public:
    static string build(const Json::Value &value);

    static Json::Value parse(const string &message);

private:
    MESSAGE_INSTANCE(ResultMsg, "result")
};


#endif //MEI_RESULTMSG_H
