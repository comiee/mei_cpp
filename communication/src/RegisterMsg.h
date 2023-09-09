#ifndef MEI_REGISTERMSG_H
#define MEI_REGISTERMSG_H

#include "Message.h"

class RegisterMsg : public Message {
public:
    static string build(const string &name, const string &type);

private:
    MESSAGE_INSTANCE(RegisterMsg, "register")
};


#endif //MEI_REGISTERMSG_H
