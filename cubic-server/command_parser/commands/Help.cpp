#include "Help.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

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
            for (auto &&command : Server::getInstance()->getCommands()) {
                if (invoker->isOperator())
                    invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(command->_help, *invoker);
            }
        } else {
            for (auto &&command : Server::getInstance()->getCommands())
                LINFO(command->_help);
        }
    } else {
        for (auto &&result : Server::getInstance()->getCommands()) {
            if (result->_name == args[0]) {
                result->help(args, invoker);
                return;
            }
        }
        if (invoker) {
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Unknown command or insufficient permissions", *invoker);
        } else {
            LINFO("Unknown command or insufficient permissions");
        }
    }
}

void command_parser::Help::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("/help [<command>]", *invoker);
    } else
        LINFO("/help [<command>]");
}
