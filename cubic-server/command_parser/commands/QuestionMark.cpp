#include "QuestionMark.hpp"
#include "Server.hpp"

using namespace command_parser;

void QuestionMark::autocomplete(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("autocomplete ?");
}

void QuestionMark::execute(std::vector<std::string>& args) const {
    auto result = std::find_if(
        Server::getInstance()->getCommands().begin(),
        Server::getInstance()->getCommands().end(),
        [args] (CommandBase *command) {
            //std::cout << Server::getInstance()->getCommands().size() << command->_name << std::endl; // TODO: understand why there is a segfault here
            return command->_name == args[0];
        }
    );
    if (result != Server::getInstance()->getCommands().end())
        (*result)->help(args);
    else
        logging::Logger::get_instance()->info("Unknown command or insufficient permissions");
}

void QuestionMark::help(std::vector<std::string>& args) const {
    logging::Logger::get_instance()->info("/? [<command>]");
}
