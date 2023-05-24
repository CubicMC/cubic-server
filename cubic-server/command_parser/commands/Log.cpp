#include "Log.hpp"
#include "Server.hpp"

#include "logging/Logger.hpp"

void command_parser::Log::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete log");
}

void command_parser::Log::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    if (args.size() < 2) {
        LDEBUG("Usage : /log [on|off] (type)");
        return;
    }

    if (args[0] == "on") {
        args.erase(args.begin());
        for (auto arg : args) {
            if (arg == "trace")
                logging::enable(logging::EnablingLogLevelSink::level_enum::trace);
            else if (arg == "debug")
                logging::enable(logging::EnablingLogLevelSink::level_enum::debug);
            else if (arg == "info")
                logging::enable(logging::EnablingLogLevelSink::level_enum::info);
            else if (arg == "warning")
                logging::enable(logging::EnablingLogLevelSink::level_enum::warn);
            else if (arg == "error")
                logging::enable(logging::EnablingLogLevelSink::level_enum::err);
            else if (arg == "fatal")
                logging::enable(logging::EnablingLogLevelSink::level_enum::critical);
            else
                LDEBUG("Unknown log type : {}", arg);
        }
    } else if (args[0] == "off") {
        args.erase(args.begin());
        for (auto arg : args) {
            if (arg == "trace")
                logging::disable(logging::EnablingLogLevelSink::level_enum::trace);
            else if (arg == "debug")
                logging::disable(logging::EnablingLogLevelSink::level_enum::debug);
            else if (arg == "info")
                logging::disable(logging::EnablingLogLevelSink::level_enum::info);
            else if (arg == "warning")
                logging::disable(logging::EnablingLogLevelSink::level_enum::warn);
            else if (arg == "error")
                logging::disable(logging::EnablingLogLevelSink::level_enum::err);
            else if (arg == "fatal")
                logging::disable(logging::EnablingLogLevelSink::level_enum::critical);
            else
                LDEBUG("Unknown log type : {}", arg);
        }
    } else
        LDEBUG("Usage : /log <on|off> (type)");
}

void command_parser::Log::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (!invoker)
        LINFO("/log <on|off> (type)");
}
