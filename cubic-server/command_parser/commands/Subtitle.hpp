#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_SUBTITLE_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_SUBTITLE_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Subtitle : public CommandBase {
    Subtitle():
        CommandBase("subtitle", "/subtitle [<player>] [rawJson]", true)
    {
    }

    ~Subtitle() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_SUBTITLE_HPP
