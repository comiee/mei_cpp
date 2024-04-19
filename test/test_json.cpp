#include "JsonTool.h"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    Json::Value s = "hi";
    cout << Json::writeString(Json::StreamWriterBuilder(), s) << endl;

    auto a = JsonTool::createArray(1, "a");
    cout << a.type() << JsonTool::dump(a) << endl;

    auto b = JsonTool::createObject("a", 1);
    cout << b.type() << JsonTool::dump(b) << endl;

    map<string, int> c{{"1", 3},
                       {"2", 4}};
    auto d = JsonTool::toObject(c);
    cout << JsonTool::dump(d) << endl;

    vector<int> e{5, 6, 7};
    auto f = JsonTool::toArray(e);
    cout << JsonTool::dump(f) << endl;

    int g[]{8, 9, 0};
    auto h = JsonTool::toArray(g);
    cout << JsonTool::dump(h) << endl;

    auto i = JsonTool::toArray(g, g + 3);
    cout << JsonTool::dump(i) << endl;

    return 0;
}