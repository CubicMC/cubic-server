#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_OP_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_OP_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Op : public CommandBase {
    Op():
        CommandBase("op", "/op [<player>]", true)
    {
    }
    ~Op() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_OP_HPP
