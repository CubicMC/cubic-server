#ifndef CUBICSERVER_COMMANDPARSER_HPP
#define CUBICSERVER_COMMANDPARSER_HPP

#include "Server.hpp"

namespace command_parser {
    void parseCommand(std::string &command, const std::optional<Player *> &invoker);
}

#endif //CUBICSERVER_COMMANDPARSER_HPP
