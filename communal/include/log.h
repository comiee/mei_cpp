#ifndef MEI_LOG_H
#define MEI_LOG_H

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
    void log(Level level, const string &format, Args...args) {
        char buf[1000];
        int ret = sprintf_s(buf, format.c_str(), args...);
        if (ret < 0) {
            error("该条日志过长，已被截断");
        }
        _log(level, buf);
    }

    template<typename ...Args>
    void debug(const string &format, Args...args) {
        log(DEBUG, format, args...);
    }

    template<typename ...Args>
    void info(const string &format, Args...args) {
        log(INFO, format, args...);
    }

    template<typename ...Args>
    void warning(const string &format, Args...args) {
        log(WARNING, format, args...);
    }

    template<typename ...Args>
    void error(const string &format, Args...args) {
        log(ERROR, format, args...);
    }

private:
    void _log(Level level, const char *str);

    string name;
    Logger::Level console_level;
    string file_name;
    Logger::Level file_level;
};

#endif //MEI_LOG_H
