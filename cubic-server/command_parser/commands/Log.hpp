#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_LOG_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_LOG_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Log : public CommandBase {
    Log():
        CommandBase("log", "/log [logger_name] type", false)
    {
    }
    ~Log() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_LOG_HPP
