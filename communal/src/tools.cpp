#include "tools.h"
#include <filesystem>

string filePath(const string &path, const string &file_name) {
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
    return path + "/" + file_name;
}

Generator<string> stringSplit(const string &s, char sep) {
    string res;
    for (char c: s) {
        if (c == sep) {
            co_yield res;
            res.clear();
        } else {
            res += c;
        }
    }
    co_yield res;
}