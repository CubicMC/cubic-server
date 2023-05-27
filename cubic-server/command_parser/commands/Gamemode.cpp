#include "Gamemode.hpp"

#include "Player.hpp"
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
        invoker->setGamemode(player_attributes::Gamemode::Adventure);
        invoker->sendPlayerAbilities({0, 0.05, 0.1});
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
        invoker->sendPlayerAbilities({0, 0.05, 0.1});
        chat::Message message = { "Set own game mode to Adventure Mode"};
        invoker->getWorld()->getChat()->sendSystemMessage(message, *invoker);
        LINFO("Gamemode changed to adventure for {}", invoker->getUsername());
    } else if (args[0] == "creative") {
        invoker->setGamemode(player_attributes::Gamemode::Creative);
        invoker->sendPlayerAbilities(
            {(uint8_t) protocol::PlayerAbilitiesClient::Flags::Invulnerable | (uint8_t) protocol::PlayerAbilitiesClient::Flags::AllowFlying |
                 (uint8_t) protocol::PlayerAbilitiesClient::Flags::CreativeMode,
             0.05, 0.1}
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
            {(uint8_t) protocol::PlayerAbilitiesClient::Flags::Invulnerable | (uint8_t) protocol::PlayerAbilitiesClient::Flags::AllowFlying |
                 (uint8_t) protocol::PlayerAbilitiesClient::Flags::CreativeMode,
             0.05, 0.1}
        );
        chat::Message message = { "Set own game mode to Creative Mode"};
        invoker->getWorld()->getChat()->sendSystemMessage(message, *invoker);
        LINFO("Gamemode changed to creative for {}", invoker->getUsername());
    } else if (args[0] == "spectator") {
        invoker->setGamemode(player_attributes::Gamemode::Spectator);
        invoker->sendPlayerAbilities(
            {(uint8_t) protocol::PlayerAbilitiesClient::Flags::Invulnerable | (uint8_t) protocol::PlayerAbilitiesClient::Flags::Flying |
                 (uint8_t) protocol::PlayerAbilitiesClient::Flags::AllowFlying,
             1.0, 0.1}
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
            {(uint8_t) protocol::PlayerAbilitiesClient::Flags::Invulnerable | (uint8_t) protocol::PlayerAbilitiesClient::Flags::Flying |
                 (uint8_t) protocol::PlayerAbilitiesClient::Flags::AllowFlying,
             1.0, 0.1}
        );
        chat::Message message = { "Set own game mode to Spectator Mode"};
        invoker->getWorld()->getChat()->sendSystemMessage(message, *invoker);
        LINFO("Gamemode changed to spectator for {}", invoker->getUsername());
    } else if (args[0] == "survival") {
        invoker->setGamemode(player_attributes::Gamemode::Survival);
        invoker->sendPlayerAbilities({0, 0.05, 0.1});
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
        invoker->sendPlayerAbilities({0, 0.05, 0.1});
        chat::Message message = { "Set own game mode to Survival Mode"};
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
