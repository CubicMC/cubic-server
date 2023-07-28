#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_STOP_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_STOP_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Stop : public CommandBase {
    Stop():
        CommandBase("stop", "/stop", true)
    {
    }

    ~Stop() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_STOP_HPP
