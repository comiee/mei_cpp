#ifndef MEI_LOG_INNER_H
#define MEI_LOG_INNER_H

class LoggerInner {
public:
    LoggerInner(
            string name,
            Logger::Level console_level,
            string file_name,
            Logger::Level file_level
    );

    void log(Logger::Level level, const char *str);

private:
    string name;
    Logger::Level console_level;
    string file_name;
    Logger::Level file_level;
};

#endif //MEI_LOG_INNER_H
