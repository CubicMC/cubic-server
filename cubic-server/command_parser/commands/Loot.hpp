#ifndef LOOT_HPP_
#define LOOT_HPP_

#include "CommandBase.hpp"

namespace command_parser {
struct Loot : public CommandBase {
    Loot():
        CommandBase("loot", "/loot namespace path", true)
    {
    }

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
} // namespace command_parser

#endif /* !LOOT_HPP_ */
