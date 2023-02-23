#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP

#include <vector>
#include <string>
#include <algorithm>
#include <optional>

class Player;

struct CommandBase {
    CommandBase(std::string name, std::string help, uint8_t permissionLevel) : _name(name), _help(help), _permissionLevel(permissionLevel) {}

    virtual void autocomplete(std::vector<std::string>& args, const std::optional<Player *> &invoker) const = 0;
    virtual void execute(std::vector<std::string>& args, const std::optional<Player *> &invoker) const = 0;
    virtual void help(std::vector<std::string>& args, const std::optional<Player *> &invoker) const = 0;

    const std::string _name;
    const std::string _help;
    const uint8_t _permissionLevel;
};

#endif //CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP
