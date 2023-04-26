#include "Logger.hpp"

#include <algorithm>
#include <iostream>

#include "TimeFormatter.hpp"

namespace logging {

LogMessage::LogMessage(LogLevel level, std::string message):
    _level(level),
    _message(message)
{
    std::chrono::time_point<std::chrono::system_clock> timePoint = std::chrono::system_clock::now();
    const std::time_t now = std::chrono::system_clock::to_time_t(timePoint);
    _time = now;
    _millis = std::chrono::duration_cast<std::chrono::milliseconds>(timePoint.time_since_epoch()).count() - (now * 1000);
}

const LogLevel &LogMessage::getLevel() const { return _level; }

const std::string &LogMessage::getMessage() const { return _message; }

const std::time_t &LogMessage::getTime() const { return _time; }

int LogMessage::getMillis() const { return _millis; }

std::ostream &operator<<(std::ostream &os, const LogMessage &log)
{
    os << TimeFormatter::getTime("[YYYY/MM/DD HH:mm:SS:sss] ", log.getTime(), log.getMillis()) << levelToString(log.getLevel()) << log.getMessage();
    return os;
}

/**
 * @brief create an instance of the Logger class if it doesn't exist and return it
 *
 * @return Logger& the instance of the Logger class as a reference
 */
Logger *Logger::getInstance()
{
    static auto instance = Logger();
    return &instance;
}

/**
 * @brief Construct a new Logger:: Logger object
 */
Logger::Logger()
{
    this->_fileAndFolderHandler.createFolder("logs");
    std::string filename = TimeFormatter::getTime("YYYY-MM-DD-1.log");

    for (int i = 1; this->_fileAndFolderHandler.fileExist("logs/" + filename); i++)
        filename = TimeFormatter::getTime("YYYY-MM-DD-" + std::to_string(i) + ".log");

    this->_fileAndFolderHandler.createFile(filename);
    this->_fileStream.open(this->_fileAndFolderHandler.getFilePath(), std::ios::app);

    this->_specificationLevelInFile = {
        {LogLevel::DEBUG, "[DEBUG] "}, {LogLevel::INFO, "[INFO] "}, {LogLevel::WARNING, "[WARNING] "}, {LogLevel::ERROR, "[ERROR] "}, {LogLevel::FATAL, "[FATAL] "}};
    this->_specificationLevelInConsole = {
        {LogLevel::DEBUG, "[DEBUG] "}, {LogLevel::INFO, "[INFO] "}, {LogLevel::WARNING, "[WARNING] "}, {LogLevel::ERROR, "[ERROR] "}, {LogLevel::FATAL, "[FATAL] "}};

    this->_bufferSize = 1000;
}

/**
 * @brief Destroy the Logger:: Logger object
 *
 * @note The file stream will be closed
 */
Logger::~Logger() { this->_fileStream.close(); }

/**
 * @brief Write a message in the log file
 *
 * @param message Message to write
 *
 * @note The message will be written in the log file with the current time
 */
void Logger::_log(LogLevel level, const std::string &message)
{
    _loggerMutex.lock();
    LogMessage log(level, message);
    this->_logBuffer.push(log);
    if (this->_logBuffer.size() > this->_bufferSize)
        this->_logBuffer.pop();

    if (this->_specificationLevelInFile.find(level) != this->_specificationLevelInFile.end())
        this->_fileStream << log << std::endl;

    if (this->_specificationLevelInConsole.find(level) != this->_specificationLevelInConsole.end())
        std::cout << log << std::endl;
    _loggerMutex.unlock();
}

/**
 * @brief Write a debug message in the console and in the log file
 *
 * @param message Message to write
 *
 * @note The message will be written with the current time
 */
void Logger::debug(const std::string &message) { this->_log(LogLevel::DEBUG, message); }

/**
 * @brief Write an info message in the console and in the log file
 *
 * @param message Message to write
 *
 * @note The message will be written with the current time
 */
void Logger::info(const std::string &message) { this->_log(LogLevel::INFO, message); }

/**
 * @brief Write a warning message in the console and in the log file
 *
 * @param message Message to write
 *
 * @note The message will be written with the current time
 */
void Logger::warn(const std::string &message) { this->_log(LogLevel::WARNING, message); }

/**
 * @brief Write an error message in the console and in the log file
 *
 * @param message Message to write
 *
 * @note The message will be written with the current time
 */
void Logger::error(const std::string &message) { this->_log(LogLevel::ERROR, message); }

/**
 * @brief Write a fatal message in the console and in the log file
 *
 * @param message Message to write
 *
 * @note The message will be written with the current time
 */
void Logger::fatal(const std::string &message) { this->_log(LogLevel::FATAL, message); }

/**
 * @brief Set log levels to display in the console
 *
 * @param level LogLevel to display in the console
 */
void Logger::setDisplaySpecificationLevelInConsole(LogLevel level) { this->_specificationLevelInConsole.insert({level, levelToString(level)}); }

/**
 * @brief Unset log levels to display in the console
 *
 * @param level LogLevel to not display in the console
 */
void Logger::unsetDisplaySpecificationLevelInConsole(LogLevel level) { this->_specificationLevelInConsole.erase(level); }

/**
 * @brief Get the log display settings of the console
 *
 * @return std::vector<LogLevel> Log levels that are displayed in the console
 */
const std::unordered_map<LogLevel, std::string> &Logger::getDisplaySpecificationLevelInConsole() const { return this->_specificationLevelInConsole; }

/**
 * @brief Set log levels to display in the log file
 *
 * @param level LogLevel to display in the log file
 */
void Logger::setDisplaySpecificationLevelInFile(LogLevel level) { this->_specificationLevelInFile.insert({level, levelToString(level)}); }

/**
 * @brief Unset log levels to display in the log file
 *
 * @param level LogLevel to not display in the log file
 */
void Logger::unsetDisplaySpecificationLevelInFile(LogLevel level) { this->_specificationLevelInFile.erase(level); }

/**
 * @brief Get the log display settings of the log file
 *
 * @return std::vector<LogLevel> Log levels that are displayed in the log file
 */
const std::unordered_map<LogLevel, std::string> &Logger::getDisplaySpecificationLevelInFile() const { return this->_specificationLevelInFile; }

std::string Logger::getFilePath() const { return this->_fileAndFolderHandler.getFilePath(); }

const std::queue<LogMessage> &Logger::getLogs() const { return this->_logBuffer; }

int Logger::getLogBufferSize() const { return this->_bufferSize; }

void Logger::setLogBufferSize(int size) { this->_bufferSize = size; }

const char *levelToString(const LogLevel &level)
{
    switch (level) {
    case LogLevel::NONE:
        return "[NONE] ";
    case LogLevel::DEBUG:
        return "[DEBUG] ";
    case LogLevel::INFO:
        return "[INFO] ";
    case LogLevel::WARNING:
        return "[WARNING] ";
    case LogLevel::ERROR:
        return "[ERROR] ";
    case LogLevel::FATAL:
        return "[FATAL] ";
    default:
        return "[UNDEFINED] ";
    }
}
}
