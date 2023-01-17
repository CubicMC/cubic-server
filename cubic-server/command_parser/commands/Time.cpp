#include "Time.hpp"
#include "Server.hpp"

using namespace command_parser;

void Time::autocomplete(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("autocomplete time");
}

void Time::execute(std::vector<std::string>& args) const {
    Server::getInstance()->time();
}

void Time::help(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("/time");
}
