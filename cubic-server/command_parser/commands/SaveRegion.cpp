#include <cstdint>
#include <memory>
#include <string>

#include "Dimension.hpp"
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
        LDEBUG("autocomplete save-region");
}

// TODO(huntears); Code this properly, this is currently only used for testing purposes
void command_parser::SaveRegion::execute(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (args.size() != 2) {
        return help(args, invoker);
    }
    if (invoker) {
        if (!invoker->isOperator()) {
            invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("You are not an operator", *invoker);
            return;
        }
    }
    LDEBUG("Called save-region");
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Starting to save region", *invoker);
    auto world = std::dynamic_pointer_cast<DefaultWorld>(Server::getInstance()->getWorldGroup("default")->getWorld("default"));
    auto &persistence = world->persistence;
    const auto dim = world->getDimension("overworld");
    persistence.saveRegion(*dim, std::stoi(args.at(0)), std::stoi(args.at(1)));
    if (invoker)
        invoker->getDimension()->getWorld()->getChat()->sendSystemMessage("Finished saving region", *invoker);
    LDEBUG("Finished call to save-region");
}

void command_parser::SaveRegion::help(UNUSED std::vector<std::string> &args, Player *invoker) const
{
    if (!invoker)
        LINFO("Usage : {}", _help);
}
