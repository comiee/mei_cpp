#pragma once

#include "type.h"

#ifdef ERROR
#undef ERROR
#endif

class Logger {
public:
    enum Level {
        DEBUG = 10,
        INFO = 20,
        WARNING = 30,
        ERROR = 40,
    };

    Logger(const string &name, Level level);

    Logger(const string &name, Level console_level, Level file_level);

    Logger(const string &name, Level console_level, const string &file_name, Level file_level);

    template<typename ...Args>
    inline void log(Level level, const string &format, Args...args) {
        _log(level, format, args...);
    }

    template<typename ...Args>
    inline void debug(const string &format, Args...args) {
        log(DEBUG, format, args...);
    }

    template<typename ...Args>
    inline void info(const string &format, Args...args) {
        log(INFO, format, args...);
    }

    template<typename ...Args>
    inline void warning(const string &format, Args...args) {
        log(WARNING, format, args...);
    }

    template<typename ...Args>
    inline void error(const string &format, Args...args) {
        log(ERROR, format, args...);
    }

private:
    void doLog(Level level, const char *str);

    string name;
    Logger::Level console_level;
    string file_name;
    Logger::Level file_level;

private:
    //模板方法实现

    template<typename ...Args>
    void _log(Level level, const string &format, Args...args) {
        char buf[1000];
        snprintf(buf, sizeof(buf) / sizeof(char), format.c_str(), args...);
        doLog(level, buf);
    }
};
