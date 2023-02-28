#include <string>
#include <iostream>

#include "CommandLine.hpp"
#include "command_parser/CommandParser.hpp"

void CommandLine::launch()
{
    std::string command = "";
    do {
        std::getline(std::cin, command);
        command_parser::parseCommand(command, nullptr);
    } while (command != "/stop" || command != "stop");

}
