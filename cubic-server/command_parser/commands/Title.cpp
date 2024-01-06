#include "Title.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

void command_parser::Title::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

void command_parser::Title::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
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
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("title: invalid JSON", *invoker);
        else
            LINFO("title: invalid JSON");
        return;
    }
    for (auto &[_, worldGroup] : Server::getInstance()->getWorldGroups()) {
        for (auto &[_, world] : worldGroup->getWorlds()) {
            for (auto &[_, dim] : world->getDimensions()) {
                for (auto &player : dim->getPlayers()) {
                    if (player->getUsername() == args[0]) {
                        player->sendTitleText({args[1]});
                        return;
                    }
                }
            }
        }
    }
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("title: target not found", *invoker);
    else
        LINFO("title: target not found");
}

void command_parser::Title::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(this->_help, *invoker);
    else
        LINFO(this->_help);
}
