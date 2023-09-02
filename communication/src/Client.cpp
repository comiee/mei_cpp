#include "log.h"
#include "Client.h"
#include <utility>

Client::Client(string name) :
        name(std::move(name)) {

}

string Client::getName() {
    return name;
}