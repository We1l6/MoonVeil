#ifndef LOGGERMANAGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <memory>
#include <iostream>


#define LOG_INFO(...) Logger::getInstance().getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) Logger::getInstance().getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) Logger::getInstance().getLogger()->error(__VA_ARGS__)
//#define LOG_DEBUG(...) Logger::getInstance().getLogger()->debug(__VA_ARGS__)

class LoggerManager {
public:
    static LoggerManager& getInstance();
    std::shared_ptr<spdlog::logger> getLogger();
    void setLogLevel(spdlog::level::level_enum level);

private:
    LoggerManager();

    std::shared_ptr<spdlog::logger> logger;

    LoggerManager(const LoggerManager&) = delete;
    LoggerManager& operator=(const LoggerManager&) = delete;
};

#endif // LOGGERMANAGER_H
