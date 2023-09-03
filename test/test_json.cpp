#include "JsonTool.h"
#include <iostream>

using namespace std;

void testJsonMain() {
    Json::Value s = "hi";
    cout << Json::writeString(Json::StreamWriterBuilder(), s) << endl;

    auto a = JsonTool::createArray(1, "a");
    cout << a.type() << JsonTool::dump(a) << endl;

    auto b = JsonTool::createObject("a", 1);
    cout << b.type() << JsonTool::dump(b) << endl;
}

