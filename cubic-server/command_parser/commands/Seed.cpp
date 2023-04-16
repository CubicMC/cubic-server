#include "Seed.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "chat/events.hpp"
#include "chat/events/clicks/CopyToClipboard.hpp"

void command_parser::Seed::autocomplete(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete seed");
}

void command_parser::Seed::execute(std::vector<std::string> &args, Player *invoker) const
{
    auto seed = std::to_string(Server::getInstance()->getWorldGroup("default")->getWorld("default")->getSeed());
    auto message = chat::Message("Seed: [");
    auto seedMsg = chat::Message(seed);
    auto endMsg = chat::Message("]");

    seedMsg.messageComponent().style().color = "green";
    seedMsg.makeClickEvent<chat::message::event::CopyToClipboardClick>(seed);
    seedMsg.makeHoverEvent<chat::message::event::TextHover>("Click to copy seed to clipboard");

    endMsg.messageComponent().style().color = "white";

    message.messageComponent().extra().push_back(seedMsg);
    message.messageComponent().extra().push_back(endMsg);

    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(message, invoker);
    } else
        LINFO(seed);
}

void command_parser::Seed::help(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("/seed", invoker);
    } else
        LINFO("/seed");
}
