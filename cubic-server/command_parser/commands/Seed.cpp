#include "Seed.hpp"
#include "Server.hpp"
#include "World.hpp"

using namespace command_parser;

void Seed::autocomplete(std::vector<std::string>& args, const Player *invoker) const {
    if (invoker)
        return;
    else
        logging::Logger::get_instance()->info("autocomplete seed");
}

void Seed::execute(std::vector<std::string>& args, const Player *invoker) const {
    std::string msg = "Seed: [" + std::to_string(Server::getInstance()->getWorldGroup("default")->getWorld("default")->getSeed()) + "]";
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
            // invoker->sendPlayerChatMessage(msg); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        logging::Logger::get_instance()->info(msg);
}

void Seed::help(std::vector<std::string>& args, const Player *invoker) const {
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
            // invoker->sendPlayerChatMessage("/seed"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        logging::Logger::get_instance()->info("/seed");
}
