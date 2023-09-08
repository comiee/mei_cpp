#ifndef MEI_MESSAGE_H
#define MEI_MESSAGE_H

#include "type.h"
#include "jsonTool.h"
#include "CustomException.h"
#include <map>

class Receiver {
public:
    virtual Json::Value receive(const Json::Value &value) = 0;

    static Json::Value parse(const string &message);

protected:
    static void registerMessage(const string &cmd, Receiver *receiver);

private:
    static std::map<string, Receiver *> receiver_map;
};

template<typename T>
class Message : public Receiver {
public:
    Json::Value receive(const Json::Value &value) override { return Json::nullValue; }

    inline static T *getInstance() {
        static T instance;
        return &instance;
    }

    Message(const Message &other) = delete;

    const Message &operator=(const Message &other) = delete;

protected:
    explicit Message(const string &cmd) : cmd(cmd) { registerMessage(cmd, this); }

    string buildMsg(const Json::Value &value) { return _buildMsg(value); };

private:
    const string cmd;

private:
    string _buildMsg(const Json::Value &value) {
        Json::Value object = JsonTool::createObject(
                "cmd", cmd,
                "value", value
        );
        return JsonTool::dump(object);
    }
};


#endif //MEI_MESSAGE_H
