#include "QuestionMark.hpp"
#include "Server.hpp"

using namespace command_parser;

void QuestionMark::autocomplete(std::vector<std::string>& args) const {
    LINFO("autocomplete ?");
}

void QuestionMark::execute(std::vector<std::string>& args) const {
    if (args.empty()) {
        for (auto command : Server::getInstance()->getCommands()) {
            LINFO(command->_help);
        }
    }
    else {
        auto result = std::find_if(
            Server::getInstance()->getCommands().begin(),
            Server::getInstance()->getCommands().end(),
            [args] (CommandBase *command) {
                return command->_name == args[0];
            }
        );
        if (result != Server::getInstance()->getCommands().end())
            (*result)->help(args);
        else
            LINFO("Unknown command or insufficient permissions");
    }
}

void QuestionMark::help(std::vector<std::string>& args) const {
    LINFO("/? [<command>]");
}
