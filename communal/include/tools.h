#ifndef MEI_TOOLS_H
#define MEI_TOOLS_H

#include "type.h"
#include "sstream"

string filePath(const string &path, const string &file_name);


// 以下为使用了模板的方法


template<typename T, typename ...Args>
string stringJoin(const string &split, T obj, Args...args) {
    std::stringstream ss;
    ss << obj;
    if constexpr (sizeof...(args) > 0) {
        ss << split << stringJoin(split, args...);
    }
    return ss.str();
}

#endif //MEI_TOOLS_H
