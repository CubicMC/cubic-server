#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_QUESTIONMARK_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_QUESTIONMARK_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct QuestionMark : public CommandBase {
    QuestionMark() : CommandBase("?", "/? [<command>] (question mark)") {}

    void autocomplete(std::vector<std::string>& args) const override;
    void execute(std::vector<std::string>& args) const override;
    void help(std::vector<std::string>& args) const override;
};
}

#endif //CUBICSERVER_COMMANDPARSER_COMMANDS_QUESTIONMARK_HPP
