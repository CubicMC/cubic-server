#include "Deop.hpp"
#include "Server.hpp"

using namespace command_parser;

void Deop::autocomplete(std::vector<std::string> &args, Player *invoker) const { }

void Deop::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker && !invoker->isOperator())
        return;
    if (args.empty()) {
        LINFO("Need a player name.");
        return;
    }
    if (args.size() != 1) {
        LINFO("Too many arguments");
        return;
    }
    Server *server = Server::getInstance();

    // do nothing if operator with that name not found, otherwise, removes operator privilege
    if (!server->permissions.isOperator(args[0]))
        LINFO(args[0] + " is not an operator.");
    else {
        server->permissions.removeOperator(args[0]);
        LINFO(args[0] + " deopped.");
    }
}

void Deop::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // invoker->sendMessage("Usage: /deop <player>");
    } else {
        LINFO("Usage: /deop <player>");
    }
}
