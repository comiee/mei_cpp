#include "json/json.h"
#include <iostream>

using namespace std;

void test_json_main() {
    Json::Value s = "hi";
    cout << s.toStyledString() << endl;
}

