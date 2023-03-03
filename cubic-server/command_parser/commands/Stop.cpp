#include "Stop.hpp"
#include "Server.hpp"

using namespace command_parser;

void Stop::autocomplete(std::vector<std::string>& args, Player *invoker) const {
    if (invoker)
        return;
    else
        LINFO("autocomplete stop");
}

void Stop::execute(std::vector<std::string>& args, Player *invoker) const {
    if (invoker) {
        // if (invoker->isOperator()) { // TODO: uncomment this when permissions are implemented
            // invoker->sendSystemChatMessage("Stopping server..."); // TODO: Know what this will do, and then change this to the correct thing
            // Server::getInstance()->stop();
        // }
    } else
        Server::getInstance()->stop();
}

void Stop::help(std::vector<std::string>& args, Player *invoker) const {
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
            // invoker->sendPlayerChatMessage("/stop"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        LINFO("/stop");
}
