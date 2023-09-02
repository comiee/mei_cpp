#ifndef MEI_LOG_H
#define MEI_LOG_H

#include "type.h"

class LoggerInner;

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

    ~Logger();

    template<typename ...Args>
    void log(Level level, string format, Args...args) {
        char buf[1000];
        int ret = sprintf_s(buf, format, args...);
        if (ret != 0) {
            error("该条日志过长，已被截断");
        }
        innerLog(level, buf);
    }

    template<typename ...Args>
    void debug(string format, Args...args) {
        log(DEBUG, format, args...);
    }

    template<typename ...Args>
    void info(string format, Args...args) {
        log(INFO, format, args...);
    }

    template<typename ...Args>
    void warning(string format, Args...args) {
        log(WARNING, format, args...);
    }

    template<typename ...Args>
    void error(string format, Args...args) {
        log(ERROR, format, args...);
    }

private:
    void innerLog(Level level, const char *str);

    LoggerInner *const inner;
};

#endif //MEI_LOG_H
