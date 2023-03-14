#include "Log.hpp"
#include "logging/Logger.hpp"

void command_parser::Log::autocomplete(std::vector<std::string>& args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete log");
}

void command_parser::Log::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() < 2) {
        LDEBUG("Usage : /log <on|off> (type)");
        return;
    }

    if (args[0] == "on") {
        args.erase(args.begin());
        for (auto arg : args) {
            if (arg == "debug")
                logging::Logger::get_instance()->set_display_specification_level_in_console(logging::LogLevel::DEBUG);
            else if (arg == "info")
                logging::Logger::get_instance()->set_display_specification_level_in_console(logging::LogLevel::INFO);
            else if (arg == "warning")
                logging::Logger::get_instance()->set_display_specification_level_in_console(logging::LogLevel::WARNING);
            else if (arg == "error")
                logging::Logger::get_instance()->set_display_specification_level_in_console(logging::LogLevel::ERROR);
            else if (arg == "fatal")
                logging::Logger::get_instance()->set_display_specification_level_in_console(logging::LogLevel::FATAL);
            else
                LDEBUG("Unknown log type : " + arg);
        }
    }
    else if (args[0] == "off") {
        args.erase(args.begin());
        for (auto arg : args) {
            if (arg == "debug")
                logging::Logger::get_instance()->unset_display_specification_level_in_console(logging::LogLevel::DEBUG);
            else if (arg == "info")
                logging::Logger::get_instance()->unset_display_specification_level_in_console(logging::LogLevel::INFO);
            else if (arg == "warning")
                logging::Logger::get_instance()->unset_display_specification_level_in_console(logging::LogLevel::WARNING);
            else if (arg == "error")
                logging::Logger::get_instance()->unset_display_specification_level_in_console(logging::LogLevel::ERROR);
            else if (arg == "fatal")
                logging::Logger::get_instance()->unset_display_specification_level_in_console(logging::LogLevel::FATAL);
            else
                LDEBUG("Unknown log type : " + arg);
        }
    }
    else
        LDEBUG("Usage : /log <on|off> (type)");
}

void command_parser::Log::help(std::vector<std::string>& args, Player *invoker) const
{
    if (!invoker)
        LINFO("/log <on|off> (type)");
}
