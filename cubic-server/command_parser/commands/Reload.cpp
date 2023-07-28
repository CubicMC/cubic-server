#include "Reload.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

void command_parser::Reload::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete reload");
}

void command_parser::Reload::execute(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator()) {
            Server::getInstance()->reload();
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Successfully reloaded loot tables, advancements and functions", *invoker);
        }
    } else {
        Server::getInstance()->reload();
        LINFO("Successfully reloaded loot tables, advancements and functions");
    }
}

void command_parser::Reload::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker) {
        if (invoker->isOperator())
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("/reload", *invoker);
    } else
        LINFO("/reload");
}
