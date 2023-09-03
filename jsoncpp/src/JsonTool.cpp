#include "JsonTool.h"
#include "CustomException.h"

string JsonTool::dump(const Json::Value &root) {
    Json::FastWriter writer;
    return writer.write(root);
}

Json::Value JsonTool::parse(const string &str) {
    Json::Value root;
    Json::Reader reader;
    if (reader.parse(str, root)) {
        return root;
    } else {
        throw JsonException(reader.getFormattedErrorMessages().c_str());
    }
}
