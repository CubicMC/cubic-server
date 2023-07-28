#include "Gamemode.hpp"

#include "Player.hpp"
#include "PlayerAttributes.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"
#include <cstdint>

void command_parser::Gamemode::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete gamemode");
}

void command_parser::Gamemode::execute(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    using Gamemode = player_attributes::Gamemode;

    if (args.size() >= 2) {
        LDEBUG("Usage : {}", _help);
        return;
    }
    if (invoker) {
        if (!invoker->isOperator()) {
            LERROR("You are not an operator");
            return;
        }
    }
    if (!invoker)
        return;
    // clang-format off
    if (args[0] == "adventure") {
        invoker->setGamemode(Gamemode::Adventure);
        invoker->sendPlayerAbilities({player_attributes::getAbilitiesByGamemode(Gamemode::Adventure), 0.05, 0.1});
        invoker->updatePlayerInfo({
            .actions = (uint8_t) protocol::PlayerInfoUpdate::Actions::UpdateGamemode,
            .actionSets = {
                {
                    .uuid = invoker->getUuid(),
                    .updateGamemode = {
                        .gamemode = (int32_t) invoker->getGamemode(),
                    }
                }
            }
        });
        invoker->sendGameEvent({protocol::GameEvent::Event::ChangeGamemode, 2});
        invoker->sendPlayerAbilities({player_attributes::getAbilitiesByGamemode(Gamemode::Adventure), 0.05, 0.1});
        chat::Message message = { "Set own game mode to Adventure Mode"};
        invoker->getWorld()->getChat()->sendSystemMessage(message, *invoker);
        LINFO("Gamemode changed to adventure for {}", invoker->getUsername());
    } else if (args[0] == "creative") {
        invoker->setGamemode(Gamemode::Creative);
        invoker->sendPlayerAbilities(
            {player_attributes::getAbilitiesByGamemode(Gamemode::Creative), 0.05, 0.1}
        );
        invoker->updatePlayerInfo({
            .actions = (uint8_t) protocol::PlayerInfoUpdate::Actions::UpdateGamemode,
            .actionSets = {
                {
                    .uuid = invoker->getUuid(),
                    .updateGamemode = {
                        .gamemode = (int32_t) invoker->getGamemode(),
                    }
                }
            }
        });
        invoker->sendGameEvent({protocol::GameEvent::Event::ChangeGamemode, 1});
        invoker->sendPlayerAbilities(
            {player_attributes::getAbilitiesByGamemode(Gamemode::Creative), 0.05, 0.1}
        );
        chat::Message message = "Set own game mode to Creative Mode";
        invoker->getWorld()->getChat()->sendSystemMessage(message, *invoker);
        LINFO("Gamemode changed to creative for {}", invoker->getUsername());
    } else if (args[0] == "spectator") {
        invoker->setGamemode(Gamemode::Spectator);
        invoker->sendPlayerAbilities(
            {player_attributes::getAbilitiesByGamemode(Gamemode::Spectator), 1.0, 0.1}
        );
        invoker->updatePlayerInfo({
            .actions = (uint8_t) protocol::PlayerInfoUpdate::Actions::UpdateGamemode,
            .actionSets = {
                {
                    .uuid = invoker->getUuid(),
                    .updateGamemode = {
                        .gamemode = (int32_t) invoker->getGamemode(),
                    }
                }
            }
        });
        invoker->sendGameEvent({protocol::GameEvent::Event::ChangeGamemode, 3});
        invoker->sendPlayerAbilities(
            {player_attributes::getAbilitiesByGamemode(Gamemode::Spectator), 1.0, 0.1}
        );
        chat::Message message = { "Set own game mode to Spectator Mode"};
        invoker->getWorld()->getChat()->sendSystemMessage(message, *invoker);
        LINFO("Gamemode changed to spectator for {}", invoker->getUsername());
    } else if (args[0] == "survival") {
        invoker->setGamemode(Gamemode::Survival);
        invoker->sendPlayerAbilities({player_attributes::getAbilitiesByGamemode(Gamemode::Survival), 0.05, 0.1});
        invoker->updatePlayerInfo({
            .actions = (uint8_t) protocol::PlayerInfoUpdate::Actions::UpdateGamemode,
            .actionSets = {
                {
                    .uuid = invoker->getUuid(),
                    .updateGamemode = {
                        .gamemode = (int32_t) invoker->getGamemode(),
                    }
                }
            }
        });
        invoker->sendGameEvent({protocol::GameEvent::Event::ChangeGamemode, 0});
        invoker->sendPlayerAbilities({player_attributes::getAbilitiesByGamemode(Gamemode::Survival), 0.05, 0.1});
        chat::Message message = "Set own game mode to Survival Mode";
        invoker->getWorld()->getChat()->sendSystemMessage(message, *invoker);
        LINFO("Gamemode changed to survival for {}", invoker->getUsername());
    } else
        LDEBUG("Usage : {}", _help);
    // clang-format on
}

void command_parser::Gamemode::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (!invoker)
        LINFO("Usage : {}", _help);
}
