#include "ResultMsg.h"
#include "CustomException.h"


string ResultMsg::build(const Json::Value &value) {
    return getInstance()->buildMsg(value);
}

Json::Value ResultMsg::parse(const string &message) {
    Json::Value object = JsonTool::parse(message);
    if (!object.isMember("cmd") || !object["cmd"].isString()) {
        throw MessageException("解析消息出错，不存在cmd字段或cmd不是string：" + message);
    }
    if (!object.isMember("value")) {
        throw MessageException("解析消息出错，不存在value字段：" + message);
    }
    string cmd = object["cmd"].asString();
    Json::Value value = object["value"];

    if (cmd != "result") {
        throw MessageException("解析响应消息出错，cmd不是result：" + message);
    }
    return value;
}
