#include "Tps.hpp"

#include <algorithm>

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

namespace command_parser {

void Tps::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete time");
}

void Tps::execute(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    switch (args.size()) {
    case 0:
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(invoker->getDimension()->getWorld()->getTps().toString(), *invoker);
        else
            LINFO(Server::getInstance()->getWorldGroup("default")->getWorld("default")->getTps().toString());
        break;
    case 1:
        if (auto search = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimensions().find(args[0]);
            search != Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimensions().end()) {
            if (invoker)
                invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(search->second->getTps().toString(), *invoker);
            else
                LINFO(search->second->getTps().toString());
        } else {
            LINFO("Dimension {} not found", args[0]);
        }
        break;
    default:
        this->help(args, invoker);
        break;
    }
}

void Tps::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(invoker->getDimension()->getWorld()->getTps().toString(), *invoker);
    else
        LINFO(this->_help);
}
}
