#include "CommandParser.hpp"

void command_parser::parseCommand(std::string &command) {
    std::vector<std::string> args;
    size_t pos = command.find(' ');

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

    auto result = std::find_if(
        Server::getInstance()->getCommands().begin(),
        Server::getInstance()->getCommands().end(),
        [commandName] (CommandBase *command) {
            return command->_name == commandName;
        }
    );
    if (result != Server::getInstance()->getCommands().end())
        (*result)->execute(args);
    else {
        LINFO("Unknown or incomplete command, see below for error");
        LINFO(commandName.erase(commandName.find_last_not_of(' ') + 1) + "<--[HERE]");
    }
}
