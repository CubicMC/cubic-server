#include <iostream>
#include <poll.h>
#include <string>

#include "CommandLine.hpp"
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
    pollfd poll_set[1];
    poll_set[0].fd = STDIN_FILENO;

    while (this->_running) {
        poll_set[0].events = POLLIN;
        poll(poll_set, 1, 50);
        if ((poll_set[0].revents & POLLIN) == 0)
            continue;

        std::getline(std::cin, command);

        command_parser::parseCommand(command, nullptr);
    }
    Server::getInstance()->stop();
}
