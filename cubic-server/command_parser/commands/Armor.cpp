#include "Armor.hpp"

#include "Chat.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"

void command_parser::Armor::autocomplete(UNUSED std::vector<std::string> &args, UNUSED Player *invoker) const { }

void command_parser::Armor::execute(std::vector<std::string> &args, UNUSED Player *invoker) const
{
    // not enough arguments, returns
    if (args.size() != 3) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(this->_help, *invoker);
        else
            LINFO(this->_help);
        return;
    }

    float defense = 0;
    float toughness = 0;

    // invalid defense value
    try {
        defense = std::stoi(args[1]);
    } catch (const std::invalid_argument &err) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("armor: " + args[1] + " is not a number", *invoker);
        else
            LINFO("armor: " + args[1] + " is not a number");
        return;
    } catch (const std::out_of_range &err) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("titletimes: " + args[1] + " is not a number", *invoker);
        else
            LINFO("armor: " + args[1] + " is not a number");
        return;
    }
    // invalid toughness value
    try {
        toughness = std::stoi(args[2]);
    } catch (const std::invalid_argument &err) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("armor: " + args[2] + " is not a number", *invoker);
        else
            LINFO("armor: " + args[2] + " is not a number");
        return;
    } catch (const std::out_of_range &err) {
        if (invoker)
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("armor: " + args[2] + " is not a number", *invoker);
        else
            LINFO("armor: " + args[2] + " is not a number");
        return;
    }

    for (auto &[_, worldGroup] : Server::getInstance()->getWorldGroups()) {
        for (auto &[_, world] : worldGroup->getWorlds()) {
            for (auto &[_, dim] : world->getDimensions()) {
                for (auto &player : dim->getPlayers()) {
                    if (player->getUsername() == args[0]) {
                        player->setDefense(defense);
                        player->setToughness(toughness);
                        if (invoker)
                            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(
                                "Set " + args[0] + "'s defense to " + args[1] + " and toughness to " + args[2] + ".", *invoker
                            );
                        else
                            LINFO("Set " + args[0] + "'s defense to " + args[1] + " and toughness to " + args[2] + ".");
                        return;
                    }
                }
            }
        }
    }
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("armor: target not found", *invoker);
    else
        LINFO("armor: target not found");
}

void command_parser::Armor::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage(this->_help, *invoker);
    else
        LINFO(this->_help);
}
