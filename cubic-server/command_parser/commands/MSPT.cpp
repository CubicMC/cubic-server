#include "MSPT.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"
#include <vector>

using namespace command_parser;

void worldMSPTMessage(Player *invoker)
{
    if (invoker) {
        auto msg = chat::Message("Dimension MSPT: min avg max");
        msg.style().italic = true;
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(msg, *invoker);
        for (const auto &each : invoker->getDimension()->getWorld()->getMSPTInfos()) {
            auto msg = chat::Message("Dimension(" + std::to_string(int(each.first)) + ") " + each.second.toString());
            msg.style().italic = true;
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(msg, *invoker);
        }
    } else {
        LINFO("Dimension MSPT: min avg max");
        for (const auto &each : Server::getInstance()->getWorldGroup("default")->getWorld("default")->getMSPTInfos())
            LINFO("Dimension({}) {}", each.first, each.second.toString());
    }
}

void dimensionMSPTMessage(std::vector<std::string> &args, Player *invoker)
{
    if (auto search = Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimensions().find(args[0]);
        search != Server::getInstance()->getWorldGroup("default")->getWorld("default")->getDimensions().end()) {
        if (invoker) {
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(chat::Message("Dimension MSPT: min avg max", {false, true}), *invoker);
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(chat::Message(args[0] + " " + search->second->getMSPTInfos().toString(), {false, true}), *invoker);
        } else {
            LINFO("Dimension MSPT: min avg max");
            LINFO(args[0] + " " + search->second->getMSPTInfos().toString());
        }
    } else {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Dimension " + args[0] + " not found", *invoker);
        else
            LINFO("Dimension {} not found", args[0]);
    }
}

void MSPT::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

void MSPT::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() == 0) {
        worldMSPTMessage(invoker);
    } else if (args.size() == 1) {
        dimensionMSPTMessage(args, invoker);
    } else {
        this->help(args, invoker);
    }
}

void MSPT::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(_help, *invoker);
    else
        LINFO(_help);
}
