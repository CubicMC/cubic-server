#include <iostream>
#include <poll.h>
#include <string>

#include "CommandLine.hpp"

#include "Server.hpp"
#include "command_parser/CommandParser.hpp"

void CommandLine::launch() { this->_thread = std::thread(&CommandLine::run, this); }

void CommandLine::stop()
{
    this->_running = false;
    if (this->_thread.joinable())
        this->_thread.join();
}

void CommandLine::run()
{
    std::string command = "";
    pollfd pollSet[1];
    pollSet[0].fd = STDIN_FILENO;

    while (this->_running) {
        pollSet[0].events = POLLIN;
        poll(pollSet, 1, 50);
        if ((pollSet[0].revents & POLLIN) == 0)
            continue;

        if (!std::getline(std::cin, command))
            break;

        command_parser::parseCommand(command, nullptr);
    }
    Server::getInstance()->stop();
}
