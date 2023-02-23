#include "QuestionMark.hpp"
#include "Server.hpp"

using namespace command_parser;

void QuestionMark::autocomplete(std::vector<std::string>& args, const std::optional<Player *> &invoker) const {
    if (invoker.has_value())
        return;
    else
        logging::Logger::get_instance()->info("autocomplete ?");
}

void QuestionMark::execute(std::vector<std::string>& args, const std::optional<Player *> &invoker) const {
    if (args.empty()) {
        if (invoker.has_value()) {
            for (auto command : Server::getInstance()->getCommands()) {
                // if (invoker.value()->_operatorLevel >= command->_permissionLevel) // TODO: uncomment this when permissions are implemented
                    // (*invoker)->sendPlayerChatMessage(command->_help); // TODO: Change this to the correct packet (gl @STMiki)
            }
        } else {
            for (auto command : Server::getInstance()->getCommands()) {
                logging::Logger::get_instance()->info(command->_help);
            }
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
            (*result)->help(args, invoker);
        else {
            if (invoker.has_value())
                // (*invoker)->sendPlayerChatMessage("Unknown command or insufficient permissions"); // TODO: Change this to the correct packet (gl @STMiki)
                return;
            else
                logging::Logger::get_instance()->info("Unknown command or insufficient permissions");
        }
    }
}

void QuestionMark::help(std::vector<std::string>& args, const std::optional<Player *> &invoker) const {
    if (invoker.has_value()) {
        // if (invoker.value()->_operatorLevel >= this->_permissionLevel) // TODO: uncomment this when permissions are implemented
            // (*invoker)->sendPlayerChatMessage("/? [<command>]"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        logging::Logger::get_instance()->info("/? [<command>]");
}
