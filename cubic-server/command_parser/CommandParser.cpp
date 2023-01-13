#include "CommandParser.hpp"

void CommandParser::parseCommand(std::string &command) {
    std::vector<std::string> args;
    size_t pos = command.find(' ');

    while (pos != std::string::npos) {
        args.push_back(command.substr(0, pos));
        command = command.substr(pos + 1);
        pos = command.find(' ');
    }
    args.push_back(command);

    std::string commandName = args[0];
    args.erase(args.begin());

    if (commands.find(commandName) != commands.end()) {
        commands.at(commandName)(args);
    } else {
        logging::Logger::get_instance()->info("Unknown or incomplete command, see below for error");
        logging::Logger::get_instance()->info(commandName.erase(commandName.find_last_not_of(' ') + 1) + "<--[HERE]");
    }
}
