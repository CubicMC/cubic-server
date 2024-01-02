#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_TPS_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_TPS_HPP

#include "CommandBase.hpp"

/*
** The command can have zero or one argument
**
**      - tps
**      - tps <dimension name>
**
** The command queries the tps of the specified dimension if successful or the current tps of the world
*/

namespace command_parser {
struct Tps : public CommandBase {
    Tps():
        CommandBase("tps", "/tps (dimension name)", false)
    {
    }

    ~Tps() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_TPS_HPP
