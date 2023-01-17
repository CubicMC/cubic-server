#include "Seed.hpp"
#include "Server.hpp"

using namespace command_parser;

void Seed::autocomplete(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("autocomplete seed");
}

void Seed::execute(std::vector<std::string>& args) const {
    std::string msg = "Seed: [" + std::to_string(Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimension("overworld")->getSeed()) + "]";
    logging::Logger::get_instance()->info(msg);
}

void Seed::help(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("/seed");
}