#include "RegisterMsg.h"
#include "JsonTool.h"

string RegisterMsg::build(const string &name, const string &type) {
    return getInstance()->buildMsg(JsonTool::createObject(
            "name", name,
            "client_type", type
    ));
}
