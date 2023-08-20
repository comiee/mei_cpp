#ifndef MEI_CLIENT_H
#define MEI_CLIENT_H

#include "comm.h"

class Client {
public:
    Client(string name);

private:
    const string name;
    SOCKET sender;
    SOCKET receiver;
};


#endif //MEI_CLIENT_H
