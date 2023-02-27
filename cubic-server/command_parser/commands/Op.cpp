#include "Op.hpp"
#include "Server.hpp"

using namespace command_parser;

void Op::autocomplete(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("autocomplete op");
}

void Op::execute(std::vector<std::string>& args) const {
    if (args.empty()) {
        logging::Logger::get_instance()->info("Need a player name");
    } else {
        if (args.size() != 1)
            logging::Logger::get_instance()->info("Too many arguments");
        else {
            // do nothing if operator found with that name, otherwise, promote player to operator
            Server *server = Server::getInstance();

            if (server->permissions.isOperator(args[0]))
                logging::Logger::get_instance()->info(args[0] + " is already opped.");
            else {
                server->permissions.addOperator(args[0]);
                logging::Logger::get_instance()->info(args[0] + " opped.");
            }
                
        }
    }
}

void Op::help(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("/op [<player>]");
}
