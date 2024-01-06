#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_TITLE_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_TITLE_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Title : public CommandBase {
    Title():
        CommandBase("title", "/title [<player>] [rawJson]", true)
    {
    }

    ~Title() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_TITLE_HPP
