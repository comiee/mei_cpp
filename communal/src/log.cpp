#include "log.h"
#include "ignore_check.h"
#include "tools.h"
#include <iostream>
#include <fstream>
#include <ctime>

inline string logPath(const string &file_name) {
    return filePath("log", file_name);
}

Logger::Logger(const string &name, Level level) :
        Logger(name, level, name, level) {
}

Logger::Logger(const string &name, Level console_level, Level file_level) :
        Logger(name, console_level, name, file_level) {
}

Logger::Logger(const string &name, Level console_level, const string &file_name, Level file_level) :
        name(name), console_level(console_level), file_name(file_name), file_level(file_level) {
    IGNORE_MOVE_CHECK(name)
    IGNORE_MOVE_CHECK(file_name)
}

string getTimeString() {
    time_t now = time(nullptr);
    tm ltm = {0};
    localtime_s(&ltm, &now);
    char date[100];
    strftime(date, sizeof(date) / sizeof(char), "[%Y-%m-%d %H:%M:%S]", &ltm);
    return date;
}

string levelToString(Logger::Level level) {
    switch (level) {
        case Logger::DEBUG:
            return "DEBUG";
        case Logger::INFO:
            return "INFO";
        case Logger::WARNING:
            return "WARNING";
        case Logger::ERROR:
            return "ERROR";
        default:
            return "INVALID";
    }
}

void Logger::doLog(Level level, const char *str) {
    if (level < console_level && level < file_level) {
        return;
    }
    string format_string = stringJoin(" ", getTimeString(), name, levelToString(level) + ":", str);
    if (level >= console_level) {
        std::cout << format_string << std::endl;
    }
    if (level >= file_level) {
        std::ofstream out(logPath(file_name), std::ios::app);
        out << format_string << std::endl;
        out.close();
    }
}