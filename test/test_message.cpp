#include "Message.h"
#include "JsonTool.h"
#include <iostream>

using namespace std;

class TestMsg : public Message{
public :
    static string build(const string &text) {
        return getInstance()->buildMsg(JsonTool::createObject(
                "text", text
        ));
    }

    Json::Value receive(const Json::Value &value) override {
        cout << JsonTool::dump(value) << endl;
        return value;
    }

private:
    MESSAGE_INSTANCE(TestMsg, "test")
};

int main() {
    Receiver::parse(TestMsg::build("abc"));
    return 0;
}