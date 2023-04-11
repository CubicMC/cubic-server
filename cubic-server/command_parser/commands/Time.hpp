#ifndef TIME_HPP_
#define TIME_HPP_

#include "CommandBase.hpp"
#include <string>

/*
**  The command has three different args: add, query and set
**
**       - time add <time>
**       - time query <daytime|gametime|day>
**       - time set <day|night|noon|midnight>
**       - time set <time>
**
**  The command fails if:
**       - at least one of the arguments is not specified correctly
**
**  The command changes the game time (or queries the time) if successful
*/

namespace command_parser {
struct Time : public CommandBase {
    Time() : CommandBase("time", "/time", true) {}

    void autocomplete(std::vector<std::string>& args, Player *invoker) const override;
    void execute(std::vector<std::string>& args, Player *invoker) const override;
    void help(std::vector<std::string>& args, Player *invoker) const override;
};
}

#endif /* !TIME_HPP_ */