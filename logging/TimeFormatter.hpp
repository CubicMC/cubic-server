#ifndef TIMEFORMATTER_HPP_
#define TIMEFORMATTER_HPP_

#include <string>

namespace logging
{
    /**
     * @brief Handles time formatting
     */
    class TimeFormatter
    {
        public:
            static std::string get_time();
            static std::string get_time(std::string format);
            static std::string get_time(std::string &format);
    };
}

#endif /* !TIMEFORMATTER_HPP_ */