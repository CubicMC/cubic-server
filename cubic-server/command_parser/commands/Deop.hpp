#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_DEOP_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_DEOP_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Deop : public CommandBase {
    Deop() : CommandBase("deop", "/deop [<player>]") {}

    void autocomplete(std::vector<std::string>& args) const override;
    void execute(std::vector<std::string>& args) const override;
    void help(std::vector<std::string>& args) const override;
};
}

#endif //CUBICSERVER_COMMANDPARSER_COMMANDS_DEOP_HPP
