#include "Subtitle.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

void command_parser::Subtitle::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

void command_parser::Subtitle::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    // not enough arguments, returns
    if (args.size() != 2) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(this->_help, *invoker);
        else
            LINFO(this->_help);
        return;
    }
    // invalid json, returns
    if (!nlohmann::json::accept(args[1])) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("subtitle: invalid JSON", *invoker);
        else
            LINFO("subtitle: invalid JSON");
        return;
    }
    for (auto &[_, worldGroup] : Server::getInstance()->getWorldGroups()) {
        for (auto &[_, world] : worldGroup->getWorlds()) {
            for (auto &[_, dim] : world->getDimensions()) {
                for (auto &player : dim->getPlayers()) {
                    if (player->getUsername() == args[0]) {
                        player->sendSubtitleText({args[1]});
                        return;
                    }
                }
            }
        }
    }
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("subtitle: target not found", *invoker);
    else
        LINFO("subtitle: target not found");
}

void command_parser::Subtitle::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(this->_help, *invoker);
    else
        LINFO(this->_help);
}
