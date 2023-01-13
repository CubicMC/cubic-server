#ifndef CUBICSERVER_COMMANDPARSER_HPP
#define CUBICSERVER_COMMANDPARSER_HPP

#include <string>
#include <unordered_map>
#include <functional>

#include "commands/help.hpp"

namespace command_parser {
    const std::unordered_map<std::string, std::function<void(std::vector<std::string>&)>> commands {
        {"/help", help::execute},
        {"/?", help::execute}
    };
    void parseCommand(std::string &command);
}

#endif //CUBICSERVER_COMMANDPARSER_HPP
