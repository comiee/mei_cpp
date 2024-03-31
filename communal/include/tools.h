#pragma once

#include "type.h"
#include "CustomException.h"
#include "sstream"

string filePath(const string &path, const string &file_name);


// 以下为使用了模板的方法


template<typename T>
string toString(T x) {
    std::stringstream ss;
    ss << x;
    return ss.str();
}

template<typename T>
T stringTo(const std::stringstream::__string_type &s) {
    std::stringstream ss(s);
    T x;
    ss >> x;
    return x;
}

template<typename ...Args>
string stringFormat(const char *format, Args...args) {
    char buf[1000];
    int ret = sprintf_s(buf, sizeof(buf) / sizeof(char), format, args...);
    if (ret < 0) {
        throw BufferNotEnoughException("字符串过长");
    }
    return buf;
}

template<typename T, typename ...Args>
string stringJoin(const string &split, T obj, Args...args) {
    std::stringstream ss;
    ss << obj;
    if constexpr (sizeof...(args) > 0) {
        ss << split << stringJoin(split, args...);
    }
    return ss.str();
}
