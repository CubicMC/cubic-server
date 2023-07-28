#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_GAMEMODE_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_GAMEMODE_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Gamemode : public CommandBase {
    Gamemode():
        CommandBase("gamemode", "/gamemode <adventure|creative|spectator|survival> (entity)", true)
    {
    }

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_GAMEMODE_HPP
