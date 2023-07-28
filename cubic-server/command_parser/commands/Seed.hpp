#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_SEED_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_SEED_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct Seed : public CommandBase {
    Seed():
        CommandBase("seed", "/seed", true)
    {
    }

    ~Seed() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_SEED_HPP
