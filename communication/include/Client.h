#ifndef MEI_CLIENT_H
#define MEI_CLIENT_H

#include "type.h"
#include <winsock.h>

class Client {
public:
    explicit Client(string name);
    string getName();

private:
    const string name;
    SOCKET sender = INVALID_SOCKET;
    SOCKET receiver = INVALID_SOCKET;
};


#endif //MEI_CLIENT_H
