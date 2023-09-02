#include "log.h"
#include "log_inner.h"

Logger::Logger(const string &name, Level level) :
        Logger(name, level, name, level) {
}

Logger::Logger(const string &name, Level console_level, Level file_level) :
        Logger(name, console_level, name, file_level) {
}

Logger::Logger(const string &name, Level console_level, const string &file_name, Level file_level) :
        inner(new LoggerInner(name, console_level, file_name, file_level)) {
}

Logger::~Logger() {
    delete inner;
}

void Logger::innerLog(Logger::Level level, const char *str) {
    inner->log(level, str);
}