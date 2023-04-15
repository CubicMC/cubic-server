#include "Op.hpp"
#include "Player.hpp"
#include "Server.hpp"

using namespace command_parser;

void Op::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

void Op::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker && !invoker->isOperator())
        return;
    if (args.empty()) {
        LINFO("Need a player name");
        return;
    }
    if (args.size() != 1) {
        LINFO("Too many arguments");
        return;
    }
    // do nothing if operator found with that name, otherwise, promote player to operator
    Server *server = Server::getInstance();

    if (server->permissions.isOperator(args[0]))
        LINFO(args[0] + " is already opped.");
    else {
        server->permissions.addOperator(args[0]);
        LINFO(args[0] + " opped.");
    }
}

void Op::help(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { LINFO("/op [<player>]"); }
