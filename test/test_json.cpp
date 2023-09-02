#include "json/writer.h"
#include <iostream>

using namespace std;

void testJsonMain() {
    Json::Value s = "hi";
    cout << Json::writeString(Json::StreamWriterBuilder(),s) << endl;
}

