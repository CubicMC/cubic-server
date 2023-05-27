#include "Stop.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

void command_parser::Stop::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete stop");
}

void command_parser::Stop::execute(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator()) {
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Stopping server...", *invoker);
            Server::getInstance()->stop();
        }
    } else
        Server::getInstance()->stop();
}

void command_parser::Stop::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("/stop", *invoker);
    } else
        LINFO("/stop");
}
