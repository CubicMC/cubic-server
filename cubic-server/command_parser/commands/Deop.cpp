#include <cstdint>

#include "Deop.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

using namespace command_parser;

void Deop::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

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
    if (!server->permissions.isOperator(args[0])) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(args[0] + " is not an operator.", *invoker);
        LINFO(args[0] + " is not an operator.");
    } else {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(args[0] + " deopped.", *invoker);
        server->permissions.removeOperator(args[0]);
        LINFO(args[0] + " deopped.");
    }
}

void Deop::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Usage: /deop <player>", *invoker);
    } else {
        LINFO("Usage: /deop <player>");
    }
}
