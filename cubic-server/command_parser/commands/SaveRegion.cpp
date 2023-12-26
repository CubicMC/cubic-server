#include <cstdint>
#include <memory>
#include <string>

#include "Player.hpp"
#include "PlayerAttributes.hpp"
#include "SaveRegion.hpp"
#include "Server.hpp"
#include "default/DefaultWorld.hpp"
#include "logging/logging.hpp"
#include "options.hpp"
#include "world_storage/Persistence.hpp"

void command_parser::SaveRegion::autocomplete(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (invoker)
        return;
    else
        LINFO("autocomplete gamemode");
}

// TODO(huntears); Code this properly, this is currently only used for testing purposes
void command_parser::SaveRegion::execute(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() != 2) {
        LDEBUG("Usage : {}", _help);
        return;
    }
    if (invoker) {
        if (!invoker->isOperator()) {
            LERROR("You are not an operator");
            return;
        }
    }
    LDEBUG("Called save-region");
    auto world = std::dynamic_pointer_cast<DefaultWorld>(Server::getInstance()->getWorldGroup("default")->getWorld("default"));
    auto &persistence = world->persistence;
    const auto dim = world->getDimension("overworld");
    persistence.saveRegion(*dim, std::stoi(args.at(0)), std::stoi(args.at(1)));
    LDEBUG("Finished call to save-region");
}

void command_parser::SaveRegion::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (!invoker)
        LINFO("Usage : {}", _help);
}
