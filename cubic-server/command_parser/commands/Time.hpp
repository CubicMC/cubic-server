#ifndef TIME_HPP_
#define TIME_HPP_

#include "CommandBase.hpp"

namespace command_parser {
struct Time : public CommandBase {
    Time() : CommandBase("time", "/time") {}

    void autocomplete(std::vector<std::string>& args) const override;
    void execute(std::vector<std::string>& args) const override;
    void help(std::vector<std::string>& args) const override;
};
}

#endif /* !TIME_HPP_ */