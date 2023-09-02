#include "tools.h"
#include <filesystem>

string filePath(const string &path, const string &file_name){
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
    return path + "/" + file_name;
}