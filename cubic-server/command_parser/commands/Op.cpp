#include "Op.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

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

    if (server->permissions.isOperator(args[0])) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(chat::Message(args[0] + " is already opped."), *invoker);
        LINFO("{} is already opped.", args[0]);
    } else {
        server->permissions.addOperator(args[0]);
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(chat::Message("opped " + args[0]), *invoker);
        LINFO("opped {}", args[0]);
    }
}

void Op::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("/op [<player>]", *invoker);
    LINFO("/op [<player>]");
}
