#include "log.h"
#include "log_inner.h"
#include <iostream>
#include <fstream>

LoggerInner::LoggerInner(
        string name,
        Logger::Level console_level,
        string file_name,
        Logger::Level file_level
) :
        name(std::move(name)),
        console_level(console_level),
        file_name(std::move(file_name)),
        file_level(file_level) {
}

void LoggerInner::log(Logger::Level level, const char *str) {
    //TODO
    std::cout << str << std::endl;
}