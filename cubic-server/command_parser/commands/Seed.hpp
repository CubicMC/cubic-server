#ifndef SEED_HPP_
#define SEED_HPP_

#include "CommandBase.hpp"

namespace command_parser {
struct Seed : public CommandBase {
    Seed() : CommandBase("seed", "/seed", true) {}

    void autocomplete(std::vector<std::string>& args, const Player *invoker) const override;
    void execute(std::vector<std::string>& args, const Player *invoker) const override;
    void help(std::vector<std::string>& args, const Player *invoker) const override;
};
}

#endif /* !SEED_HPP_ */
