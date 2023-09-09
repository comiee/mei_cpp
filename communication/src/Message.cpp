#include "Message.h"
#include "JsonTool.h"

Json::Value Message::receive(const Json::Value &value)  {
    return Json::nullValue;
}

Message::Message(const string &cmd) : cmd(cmd) {
    registerMessage(cmd, this);
}

string Message::buildMsg(const Json::Value &value) {
    Json::Value object = JsonTool::createObject(
            "cmd", cmd,
            "value", value
    );
    return JsonTool::dump(object);
}
