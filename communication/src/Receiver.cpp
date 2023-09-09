#include "Receiver.h"
#include "CustomException.h"
#include "JsonTool.h"

std::map<string, Receiver *> receiver_map;

Json::Value Receiver::parse(const string &message) {
    Json::Value object = JsonTool::parse(message);
    if (!object.isMember("cmd") || !object["cmd"].isString()) {
        throw MessageException("解析消息出错，不存在cmd字段或cmd不是string：" + message);
    }
    if (!object.isMember("value")) {
        throw MessageException("解析消息出错，不存在value字段：" + message);
    }
    string cmd = object["cmd"].asString();
    Json::Value value = object["value"];

    for (const auto &[k, v]: receiver_map) {
        if (k == cmd) {
            return v->receive(value);
        }
    }
    throw MessageException("解析消息出错，未注册的命令：" + message);
}

void Receiver::registerReceiver(const string &cmd, Receiver *receiver) {
    receiver_map[cmd] = receiver;
}