#ifndef MEI_CLIENT_H
#define MEI_CLIENT_H

#include "comm.h"

class Client {
public:
    explicit Client(string name);
    string getName();

private:
    const string name;
    SOCKET sender;
    SOCKET receiver;
};


#endif //MEI_CLIENT_H
