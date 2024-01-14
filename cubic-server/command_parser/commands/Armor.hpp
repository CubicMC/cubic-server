#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_ARMOR_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_ARMOR_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Armor : public CommandBase {
    Armor():
        CommandBase("armor", "/armor [<player>] [<defense points>] [<toughness points>]", true)
    {
    }

    ~Armor() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_ARMOR_HPP
