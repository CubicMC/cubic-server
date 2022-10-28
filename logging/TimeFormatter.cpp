#include "TimeFormatter.hpp"

#include <chrono>
#include <unordered_map>
#include <sstream>
#include <iomanip>

namespace logging
{
    /**
     * @brief Get the current time
     *
     * @return std::string The current time
     *
     * @note The format is YYYY/MM/DD HH:MM:SS.sss by default
     */
    std::string TimeFormatter::get_time()
    {
        const std::time_t now = std::time(nullptr);
        const std::tm* tm_now = std::localtime(&now);
        int millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - (now * 1000);
        std::stringstream ss;
        ss << std::put_time(tm_now, "%Y/%m/%d %H:%M:%S.") << std::setfill('0') << std::setw(3) << millis;
        return ss.str();
    }

    /**
     * @brief Get the current time
     *
     * @param format The format of the time
     *
     * @return std::string The current time
     *
     * @overload std::string Logger::get_time() const
     */
    std::string TimeFormatter::get_time(std::string format)
    {
        const std::time_t now = std::time(nullptr);
        const std::tm* tm_now = std::localtime(&now);
        int millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - (now * 1000);
        std::unordered_map<std::string, std::string> values = {
            {"YYYY", std::to_string(tm_now->tm_year + 1900)},
            {"MM", tm_now->tm_mon + 1 < 10 ? "0" + std::to_string(tm_now->tm_mon + 1) : std::to_string(tm_now->tm_mon + 1)},
            {"DD", tm_now->tm_mday < 10 ? "0" + std::to_string(tm_now->tm_mday) : std::to_string(tm_now->tm_mday)},
            {"HH", tm_now->tm_hour < 10 ? "0" + std::to_string(tm_now->tm_hour) : std::to_string(tm_now->tm_hour)},
            {"mm", tm_now->tm_min < 10 ? "0" + std::to_string(tm_now->tm_min) : std::to_string(tm_now->tm_min)},
            {"SS", tm_now->tm_sec < 10 ? "0" + std::to_string(tm_now->tm_sec) : std::to_string(tm_now->tm_sec)},
            {"sss", millis < 10 ? "00" + std::to_string(millis) : millis < 100 ? "0" + std::to_string(millis) : std::to_string(millis)}
        };

        for (auto iter = values.begin(); iter != values.end(); iter++) {
            if (format.find(iter->first) != std::string::npos)
                format.replace(format.find(iter->first), iter->first.length(), iter->second);
        }
        return format;
    }

    /**
     * @brief Get the current time
     *
     * @param format Format of the time. When there is YYYY or any other format letters, they will be replaced by the current time
     *
     * @return std::string The current time
     *
     * @overload std::string Logger::get_time() const
     */
    std::string TimeFormatter::get_time(std::string &format)
    {
        const std::time_t now = std::time(nullptr);
        const std::tm* tm_now = std::localtime(&now);
        int millis = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - (now * 1000);
        std::unordered_map<std::string, std::string> values = {
            {"YYYY", std::to_string(tm_now->tm_year + 1900)},
            {"MM", tm_now->tm_mon + 1 < 10 ? "0" + std::to_string(tm_now->tm_mon + 1) : std::to_string(tm_now->tm_mon + 1)},
            {"DD", tm_now->tm_mday < 10 ? "0" + std::to_string(tm_now->tm_mday) : std::to_string(tm_now->tm_mday)},
            {"HH", tm_now->tm_hour < 10 ? "0" + std::to_string(tm_now->tm_hour) : std::to_string(tm_now->tm_hour)},
            {"mm", tm_now->tm_min < 10 ? "0" + std::to_string(tm_now->tm_min) : std::to_string(tm_now->tm_min)},
            {"SS", tm_now->tm_sec < 10 ? "0" + std::to_string(tm_now->tm_sec) : std::to_string(tm_now->tm_sec)},
            {"sss", millis < 10 ? "00" + std::to_string(millis) : millis < 100 ? "0" + std::to_string(millis) : std::to_string(millis)}
        };

        for (auto iter = values.begin(); iter != values.end(); iter++) {
            if (format.find(iter->first) != std::string::npos)
                format.replace(format.find(iter->first), iter->first.length(), iter->second);
        }
        return format;
    }

    std::string TimeFormatter::get_time(std::string format, std::time_t time, int millis)
    {
        const std::tm* tm_now = std::localtime(&time);
        std::unordered_map<std::string, std::string> values = {
            {"YYYY", std::to_string(tm_now->tm_year + 1900)},
            {"MM", tm_now->tm_mon + 1 < 10 ? "0" + std::to_string(tm_now->tm_mon + 1) : std::to_string(tm_now->tm_mon + 1)},
            {"DD", tm_now->tm_mday < 10 ? "0" + std::to_string(tm_now->tm_mday) : std::to_string(tm_now->tm_mday)},
            {"HH", tm_now->tm_hour < 10 ? "0" + std::to_string(tm_now->tm_hour) : std::to_string(tm_now->tm_hour)},
            {"mm", tm_now->tm_min < 10 ? "0" + std::to_string(tm_now->tm_min) : std::to_string(tm_now->tm_min)},
            {"SS", tm_now->tm_sec < 10 ? "0" + std::to_string(tm_now->tm_sec) : std::to_string(tm_now->tm_sec)},
            {"sss", millis < 10 ? "00" + std::to_string(millis) : millis < 100 ? "0" + std::to_string(millis) : std::to_string(millis)}
        };

        for (auto iter = values.begin(); iter != values.end(); iter++) {
            if (format.find(iter->first) != std::string::npos)
                format.replace(format.find(iter->first), iter->first.length(), iter->second);
        }
        return format;
    }
}