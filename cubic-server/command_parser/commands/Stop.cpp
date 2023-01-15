#include "Stop.hpp"
#include "Server.hpp"

using namespace command_parser;

void Stop::autocomplete(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("autocomplete stop");
}

void Stop::execute(std::vector<std::string>& args) const {
    Server::getInstance()->stop();
}

void Stop::help(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("/stop");
}
