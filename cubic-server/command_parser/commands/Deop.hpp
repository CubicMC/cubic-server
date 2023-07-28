#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_DEOP_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_DEOP_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Deop : public CommandBase {
    Deop():
        CommandBase("deop", "/deop [<player>]", true)
    {
    }
    ~Deop() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_DEOP_HPP
