#include "Deop.hpp"
#include "Server.hpp"

using namespace command_parser;

void Deop::autocomplete(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("autocomplete help");
}

void Deop::execute(std::vector<std::string>& args) const {
    if (args.empty()) {
        logging::Logger::get_instance()->info("Need a player name.");
    } else {
        if (args.size() != 1)
            logging::Logger::get_instance()->info("Too many arguments");
        else {
            Server *server = Server::getInstance();

            if (!server->permissions.isOperator(args[0]))
                logging::Logger::get_instance()->info(args[0] + " is not an operator.");
            else {
                server->permissions.removeOperator(args[0]);
                logging::Logger::get_instance()->info(args[0] + " deopped.");
            }
        }
    }
}

void Deop::help(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("/help [<command>]");
}
