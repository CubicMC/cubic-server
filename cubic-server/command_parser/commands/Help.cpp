#include "Help.hpp"
#include "Server.hpp"

void command_parser::Help::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete help");
}

void command_parser::Help::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.empty()) {
        if (invoker) {
            // for (auto command : Server::getInstance()->getCommands()) {
            // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
            // invoker->sendPlayerChatMessage(command->_help); // TODO: Change this to the correct packet (gl @STMiki)
            // }
        } else {
            for (auto &&command : Server::getInstance()->getCommands()) {
                LINFO(command->_help);
            }
        }
    } else {
        for (auto &&result : Server::getInstance()->getCommands()) {
            if (result->_name == args[0]) {
                result->help(args, invoker);
                return;
            }
        }
        if (invoker) {
            // invoker->sendPlayerChatMessage("Unknown command or insufficient permissions"); // TODO: Change this to the correct packet (gl @STMiki)
            // @STMiki)
        } else {
            LINFO("Unknown command or insufficient permissions");
        }
    }
}

void command_parser::Help::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        // if (invoker->isOperator()) // TODO: uncomment this when permissions are implemented
        // invoker->sendPlayerChatMessage("/help [<command>]"); // TODO: Change this to the correct packet (gl @STMiki)
    } else
        LINFO("/help [<command>]");
}
