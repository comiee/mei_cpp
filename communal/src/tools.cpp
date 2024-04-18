#include "tools.h"
#include <filesystem>

string filePath(const string &path, const string &file_name) {
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
    return path + "/" + file_name;
}

Generator<string> stringSplit(const string &s, char sep, int max_times) {
    string res;
    for (char c: s) {
        if (max_times != 0 && c == sep) {
            co_yield res;
            res.clear();
            --max_times;
        } else {
            res += c;
        }
    }
    co_yield res;
}