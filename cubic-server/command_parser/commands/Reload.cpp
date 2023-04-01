#include "Reload.hpp"
#include "Server.hpp"

void command_parser::Reload::autocomplete(std::vector<std::string>& args, Player *invoker) const {
    if (invoker)
        return;
    else
        LINFO("autocomplete reload");
}

void command_parser::Reload::execute(std::vector<std::string>& args, Player *invoker) const {
    if (invoker) {
        return;
    } else {
        Server::getInstance()->reload();
        LINFO("Successfully reloaded loot tables, advancements and functions");
    }
}

void command_parser::Reload::help(std::vector<std::string>& args, Player *invoker) const {
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
            // invoker->sendPlayerChatMessage("/reload"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        LINFO("/reload");
}
