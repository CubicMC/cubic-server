#ifndef CUBICSERVER_COMMANDPARSER_HPP
#define CUBICSERVER_COMMANDPARSER_HPP

#include "Server.hpp"

namespace command_parser {
    /**
     * @brief parse the command given in the command string and call the corresponding function
     */
    void parseCommand(std::string &command, const Player *invoker);
}

#endif //CUBICSERVER_COMMANDPARSER_HPP
