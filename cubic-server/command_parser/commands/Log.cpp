#include "Log.hpp"
#include "Server.hpp"

#include "logging/Sinks.hpp"
#include "logging/logging.hpp"

void command_parser::Log::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete log");
}

void command_parser::Log::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 1) {
        LDEBUG("Usage : /log [logger_name] type");
        return;
    }

    auto levelNames = logging::LEVEL_NAMES;
    auto begin = &(levelNames[0]);
    auto end = &(levelNames[static_cast<int>(logging::Registry::LogLevel::n_levels)]);

    if (std::find(begin, end, args[0]) == end) {
        if (auto logger = logging::Registry::instance().get(args[0])) {
            logger->set_level(logging::stringToLevel(args[1]));
            LINFO("Set level of logger {} to {}", args[0], args[1]);
            return;
        }
        LWARN("Unknown logger {}", args[0]);
        return;
    }

    logging::setLevel(logging::stringToLevel(args[0]));
    LWARN("Set level of all logger to {}", args[0]);
}

void command_parser::Log::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (!invoker)
        LINFO("/log [logger_name] type");
}
