#include "Message.h"
#include "simple.h"
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
    INSTANCE(TestMsg)

    TestMsg() : Message("test") {}
};

void testMessageMain() {
    Receiver::parse(TestMsg::build("abc"));
}