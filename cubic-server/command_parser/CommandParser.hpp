#ifndef CUBICSERVER_COMMANDPARSER_COMMANDPARSER_HPP
#define CUBICSERVER_COMMANDPARSER_COMMANDPARSER_HPP

#include <memory>
#include <string>

class Player;

namespace command_parser {
/**
 * @brief parse the command given in the command string and call the corresponding function
 */
void parseCommand(std::string &command, std::shared_ptr<Player> invoker);
}

#endif // CUBICSERVER_COMMANDPARSER_COMMANDPARSER_HPP
