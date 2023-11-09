#include "Tps.hpp"

#include <algorithm>

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "chat/Message.hpp"
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
    case 0: {
        if (invoker) {
            auto msg = chat::Message("Dimension Tps: 1min 5min 15min");
            msg.style().italic = true;
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(msg, *invoker);
            for (const auto &each : invoker->getDimension()->getWorld()->getTps()) {
                auto msg = chat::Message(each.first + " " + each.second.toString());
                msg.style().italic = true;
                invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(msg, *invoker);
            }
        } else {
            LINFO("Dimension Tps: 1min 5min 15min");
            for (const auto &each : Server::getInstance()->getWorldGroup("default")->getWorld("default")->getTps())
                LINFO(each.first + " " + each.second.toString());
        }
        break;
    }
    case 1:
        if (auto search = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimensions().find(args[0]);
            search != Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimensions().end()) {
            if (invoker)
                invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(chat::Message(args[0] + " " + search->second->getTps().toString(), {false, true}), *invoker);
            else
                LINFO(args[0] + " " + search->second->getTps().toString());
        } else {
            if (invoker)
                invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Dimension " + args[0] + " not found", *invoker);
            else
                LINFO("Dimension {} not found", args[0]);
        }
        break;
    default:
        this->help(args, invoker);
        break;
    }
}

void Tps::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(this->_help, *invoker);
    else
        LINFO(this->_help);
}
}
