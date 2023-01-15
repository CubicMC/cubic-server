#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_HELP_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_HELP_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Help : public CommandBase {
    Help() : CommandBase("help", "/help [<command>] (help)") {};
    void autocomplete(std::vector<std::string>& args) const override;
    void execute(std::vector<std::string>& args) const override;
    void help(std::vector<std::string>& args) const override;
};
}

#endif //CUBICSERVER_COMMANDPARSER_COMMANDS_HELP_HPP
