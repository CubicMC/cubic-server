#include "Seed.hpp"
#include "Server.hpp"
#include "World.hpp"

void command_parser::Seed::autocomplete(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete seed");
}

void command_parser::Seed::execute(std::vector<std::string> &args, Player *invoker) const
{
    std::string msg = "Seed: [" + std::to_string(Server::getInstance()->getWorldGroup("default")->getWorld("default")->getSeed()) + "]";
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(msg, invoker);
    } else
        LINFO(msg);
}

void command_parser::Seed::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("/seed", invoker);
    } else
        LINFO("/seed");
}
