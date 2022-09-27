#ifndef TIMEFORMATTER_HPP_
#define TIMEFORMATTER_HPP_

#include <string>

namespace logging
{
    /**
     * @brief Handles time formatting
     */
    namespace TimeFormatter
    {
        std::string get_time();
        std::string get_time(std::string format);
        std::string get_time(std::string& format);
    };
}

#endif /* !TIMEFORMATTER_HPP_ */