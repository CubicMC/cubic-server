#include "Gamemode.hpp"
#include "Server.hpp"
#include "logging/Logger.hpp"
#include "protocol/ClientPackets.hpp"

void command_parser::Gamemode::autocomplete(std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete gamemode");
}

void command_parser::Gamemode::execute(std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() >= 2) {
        LDEBUG("Usage : ", _help);
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
    if (args[0] == "adventure") {
        invoker->sendGameEvent({protocol::GameEvent::Event::ChangeGamemode, 2});
        LINFO("Gamemode changed to adventure for ", invoker->getUsername());
    } else if (args[0] == "creative") {
        invoker->sendGameEvent({protocol::GameEvent::Event::ChangeGamemode, 1});
        LINFO("Gamemode changed to creative for ", invoker->getUsername());
    } else if (args[0] == "spectator") {
        invoker->sendGameEvent({protocol::GameEvent::Event::ChangeGamemode, 3});
        invoker->sendPlayerAbilities(
            {(uint8_t) protocol::PlayerAbilitiesFlags::Invulnerable | (uint8_t) protocol::PlayerAbilitiesFlags::Flying | (uint8_t) protocol::PlayerAbilitiesFlags::AllowFlying, 1.0,
             0.1}
        );
        LINFO("Gamemode changed to spectator for ", invoker->getUsername());
    } else if (args[0] == "survival") {
        invoker->sendGameEvent({protocol::GameEvent::Event::ChangeGamemode, 0});
        LINFO("Gamemode changed to survival for ", invoker->getUsername());
    } else
        LDEBUG("Usage : ", _help);
}

void command_parser::Gamemode::help(std::vector<std::string> &args, Player *invoker) const
{
    if (!invoker)
        LINFO("Usage : ", _help);
}
