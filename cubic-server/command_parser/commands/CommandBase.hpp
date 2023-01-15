#ifndef CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP

#include <vector>
#include <string>
#include <algorithm>

struct CommandBase {
    CommandBase(std::string name, std::string help) : _name(name), _help(help) {};
    virtual void autocomplete(std::vector<std::string>& args) const = 0;
    virtual void execute(std::vector<std::string>& args) const = 0;
    virtual void help(std::vector<std::string>& args) const = 0;

    const std::string _name;
    const std::string _help;
};

#endif //CUBICSERVER_COMMANDPARSER_COMMANDS_BASE_HPP
