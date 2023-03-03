#include "Seed.hpp"
#include "Server.hpp"
#include "World.hpp"

void command_parser::Seed::autocomplete(std::vector<std::string>& args) const {
    LINFO("autocomplete seed");
}

void command_parser::Seed::execute(std::vector<std::string>& args) const {
    LINFO("Seed: [", Server::getInstance()->getWorldGroup("default")->getWorld("default")->getSeed(), "]");
}

void command_parser::Seed::help(std::vector<std::string>& args) const {
    LINFO("/seed");
}
