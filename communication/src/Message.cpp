#include "Message.h"

std::map<string, Receiver *> Receiver::receiver_map;

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

void Receiver::registerMessage(const string &cmd, Receiver *receiver) {
    receiver_map[cmd] = receiver;
}

class RegisterMsg : public Message<RegisterMsg> {
    friend class Message<RegisterMsg>;

public:
    static string build(const string &name, const string &type) {
        return getInstance()->buildMsg(JsonTool::createObject(
                "name", name,
                "client_type", type
        ));
    }

private:
    RegisterMsg() : Message<RegisterMsg>("register") {}
};

class ResultMsg : public Message<ResultMsg> {
    friend class Message<ResultMsg>;

public :
    static string build(const Json::Value &value) {
        return getInstance()->buildMsg(value);
    }

    static Json::Value parse(const string &message) {
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

private:
    ResultMsg() : Message<ResultMsg>("result") {}
};
