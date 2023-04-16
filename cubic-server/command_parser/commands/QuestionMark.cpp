#include "QuestionMark.hpp"
#include "Server.hpp"
#include "World.hpp"

void command_parser::QuestionMark::autocomplete(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete ?");
}

void command_parser::QuestionMark::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.empty()) {
        if (invoker) {
            for (auto command : Server::getInstance()->getCommands()) {
                if (invoker->isOperator())
                    invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(command->_help, invoker);
            }
        } else {
            for (auto command : Server::getInstance()->getCommands()) {
                LINFO(command->_help);
            }
        }
    } else {
        auto result = std::find_if(Server::getInstance()->getCommands().begin(), Server::getInstance()->getCommands().end(), [args](CommandBase *command) {
            return command->_name == args[0];
        });
        if (result != Server::getInstance()->getCommands().end())
            (*result)->help(args, invoker);
        else {
            if (invoker)
                invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Unknown command or insufficient permissions", invoker);
            else
                LINFO("Unknown command or insufficient permissions");
        }
    }
}

void command_parser::QuestionMark::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("/? [<command>]", invoker);
    } else
        LINFO("/? [<command>]");
}
