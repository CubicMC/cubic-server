#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_MSPT_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_MSPT_HPP

#include "CommandBase.hpp"

namespace command_parser {
struct MSPT : public CommandBase {
    MSPT():
        CommandBase("mspt", "/mspt (dimension)", false)
    {
    }
    ~MSPT() override = default;

    void autocomplete(std::vector<std::string> &args, Player *invoker) const override;
    void execute(std::vector<std::string> &args, Player *invoker) const override;
    void help(std::vector<std::string> &args, Player *invoker) const override;
};
} // namespace command_parser

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_MSPT_HPP
