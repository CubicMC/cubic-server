#include "TitleTimes.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

void command_parser::TitleTimes::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

void command_parser::TitleTimes::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    // not enough arguments, returns
    if (args.size() != 4) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(this->_help, *invoker);
        else
            LINFO(this->_help);
        return;
    }
    // invalid json, returns
    int32_t times[3];

    for (size_t i = 0; i < 3; i++) {
        try {
            times[i] = std::stoi(args[i + 1]);
        } catch (const std::invalid_argument &err) {
            if (invoker)
                invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("titletimes: " + args[i + 1] + " is not a number", *invoker);
            else
                LINFO("titletimes: " + args[i + 1] + " is not a number");
            return;
        } catch (const std::out_of_range &err) {
            if (invoker)
                invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("titletimes: " + args[i + 1] + " is out of range", *invoker);
            else
                LINFO("titletimes: " + args[i + 1] + " is not a number");
            return;
        }
    }

    for (auto &[_, worldGroup] : Server::getInstance()->getWorldGroups()) {
        for (auto &[_, world] : worldGroup->getWorlds()) {
            for (auto &[_, dim] : world->getDimensions()) {
                for (auto &player : dim->getPlayers()) {
                    if (player->getUsername() == args[0]) {
                        player->sendTitleAnimationTimes({times[0], times[1], times[2]});
                        return;
                    }
                }
            }
        }
    }
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("titletimes: target not found", *invoker);
    else
        LINFO("titletimes: target not found");
}

void command_parser::TitleTimes::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(this->_help, *invoker);
    else
        LINFO(this->_help);
}
