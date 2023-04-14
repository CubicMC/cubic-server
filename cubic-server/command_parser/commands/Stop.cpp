#include "Stop.hpp"
#include "Player.hpp"
#include "Server.hpp"

void command_parser::Stop::autocomplete(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete stop");
}

void command_parser::Stop::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator()) { // TODO: uncomment this when permissions are implemented
            // invoker->sendSystemChatMessage("Stopping server..."); // TODO: Know what this will do, and then change this to the correct thing
            Server::getInstance()->stop();
        }
    } else
        Server::getInstance()->stop();
}

void command_parser::Stop::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
        // invoker->sendPlayerChatMessage("/stop"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        LINFO("/stop");
}
