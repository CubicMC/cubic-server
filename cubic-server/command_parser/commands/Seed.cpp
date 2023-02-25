#include "Seed.hpp"
#include "Server.hpp"
#include "World.hpp"

void command_parser::Seed::autocomplete(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("autocomplete seed");
}

void command_parser::Seed::execute(std::vector<std::string>& args) const {
    std::string msg = "Seed: [" + std::to_string(Server::getInstance()->getWorldGroup("default")->getWorld("default")->getSeed()) + "]";
    logging::Logger::get_instance()->info(msg);
}

void command_parser::Seed::help(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("/seed");
}
