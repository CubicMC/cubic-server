#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_SAVEREGION_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_SAVEREGION_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct SaveRegion : public CommandBase {
    SaveRegion():
        CommandBase("save-region", "/save-region <x> <z>", true)
    {
    }

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_SAVEREGION_HPP
