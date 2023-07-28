#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

class Player;

struct CommandBase {
    CommandBase(std::string name, std::string help, bool needOp):
        _name(name),
        _help(help),
        _needOp(needOp)
    {
    }
    virtual ~CommandBase() = default;

    virtual void autocomplete(std::vector<std::string> &args, Player *invoker) const = 0;
    virtual void execute(std::vector<std::string> &args, Player *invoker) const = 0;
    virtual void help(std::vector<std::string> &args, Player *invoker) const = 0;

    const std::string _name;
    const std::string _help;
    const uint8_t _needOp;
};

#endif // CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP
