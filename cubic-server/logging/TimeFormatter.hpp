#ifndef CUBICSERVER_LOGGING_TIMEFORMATTER_HPP
#define CUBICSERVER_LOGGING_TIMEFORMATTER_HPP

#include <ctime>
#include <string>

namespace logging {
/**
 * @brief Handles time formatting
 */
namespace TimeFormatter {
std::string getTime();
std::string getTime(std::string format);
std::string getTime(std::string &format);
std::string getTime(std::string format, std::time_t time, int millis);
};
}

#endif // CUBICSERVER_LOGGING_TIMEFORMATTER_HPP
