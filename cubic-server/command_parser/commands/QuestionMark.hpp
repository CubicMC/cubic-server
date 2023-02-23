#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_QUESTIONMARK_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_QUESTIONMARK_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct QuestionMark : public CommandBase {
    QuestionMark() : CommandBase("?", "/help [<command>] (question mark)", 0) {}

    void autocomplete(std::vector<std::string>& args, const std::optional<Player *> &invoker) const override;
    void execute(std::vector<std::string>& args, const std::optional<Player *> &invoker) const override;
    void help(std::vector<std::string>& args, const std::optional<Player *> &invoker) const override;
};
}

#endif //CUBICSERVER_COMMANDPARSER_COMMANDS_QUESTIONMARK_HPP
