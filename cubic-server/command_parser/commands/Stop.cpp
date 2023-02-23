#include "Stop.hpp"
#include "Server.hpp"

using namespace command_parser;

void Stop::autocomplete(std::vector<std::string>& args, const std::optional<Player *> &invoker) const {
    if (invoker.has_value())
        return;
    else
        logging::Logger::get_instance()->info("autocomplete stop");
}

void Stop::execute(std::vector<std::string>& args, const std::optional<Player *> &invoker) const {
    if (invoker.has_value()) {
        // if (invoker.value()->_operatorLevel >= this->_permissionLevel) { // TODO: uncomment this when permissions are implemented
            // (*invoker)->sendSystemChatMessage("Stopping server..."); // TODO: Know what this will do, and then change this to the correct thing
            // Server::getInstance()->stop(); // TODO: change this behavior to the correct one
        // }
    } else
        Server::getInstance()->stop();
}

void Stop::help(std::vector<std::string>& args, const std::optional<Player *> &invoker) const {
    if (invoker.has_value()) {
        // if (invoker.value()->_operatorLevel >= this->_permissionLevel) // TODO: uncomment this when permissions are implemented
            // (*invoker)->sendPlayerChatMessage("/stop"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        logging::Logger::get_instance()->info("/stop");
}
