#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_TITLETIMES_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_TITLETIMES_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct TitleTimes : public CommandBase {
    TitleTimes():
        CommandBase("titletimes", "/titletimes [<player>] [fadeIn] [stay] [fadeOut]", true)
    {
    }

    ~TitleTimes() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_TITLETIMES_HPP
