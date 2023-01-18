#ifndef SEED_HPP_
#define SEED_HPP_

#include "CommandBase.hpp"

namespace command_parser {
struct Seed : public CommandBase {
    Seed() : CommandBase("seed", "/seed") {}

    void autocomplete(std::vector<std::string>& args) const override;
    void execute(std::vector<std::string>& args) const override;
    void help(std::vector<std::string>& args) const override;
};
}

#endif /* !SEED_HPP_ */