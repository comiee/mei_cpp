#include "RegisterMsg.h"


string RegisterMsg::build(const string &name, const string &type) {
    return getInstance()->buildMsg(JsonTool::createObject(
            "name", name,
            "client_type", type
    ));
}
