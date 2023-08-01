#include "CommandParser.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

void command_parser::parseCommand(std::string &command, Player *invoker)
{
    std::vector<std::string> args;
    size_t pos = command.find(' ');

    if (command.empty())
        return;

    while (pos != std::string::npos) {
        args.push_back(command.substr(0, pos));
        command = command.substr(pos + 1);
        pos = command.find(' ');
    }
    args.push_back(command);

    std::string commandName = args[0];
    if (args[0][0] == '/')
        commandName = commandName.erase(0, 1);
    args.erase(args.begin());

    for (auto &&result : Server::getInstance()->getCommands()) {
        if (result->_name == commandName) {
            result->execute(args, invoker);
            return;
        }
    }
    if (invoker) {
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Unknown or incomplete command, see below for error", *invoker);
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(commandName.erase(commandName.find_last_not_of(' ') + 1) + "<--[HERE]", *invoker);
    } else {
        LINFO("Unknown or incomplete command, see below for error");
        LINFO("{}<--[HERE]", commandName.erase(commandName.find_last_not_of(' ') + 1));
    }
}
