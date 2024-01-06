#include "DefaultWorldGroup.hpp"

#include <utility>

#include "DefaultWorld.hpp"
#include "Server.hpp"

namespace world_storage {
static const boost::container::flat_map<std::string, world_storage::WorldType> _worldTypes = {
    {"default", world_storage::WorldType::DEFAULT},
    {"superflat", world_storage::WorldType::SUPERFLAT},
    {"largebiome", world_storage::WorldType::LARGEBIOME},
    {"amplified", world_storage::WorldType::AMPLIFIED},
    {"singlebiome", world_storage::WorldType::SINGLEBIOME},
    {"debug", world_storage::WorldType::DEBUG},
    {"superflat_cubic_server", world_storage::WorldType::SUPERFLAT_CUBIC_SERVER}};
} // namespace world_storage

DefaultWorldGroup::DefaultWorldGroup(std::shared_ptr<Chat> chat):
    WorldGroup(std::move(chat))
{
}

void DefaultWorldGroup::initialize()
{
    _worlds.emplace(
        "default", std::make_shared<DefaultWorld>(shared_from_this(), world_storage::_worldTypes.at(CONFIG["world-type"].as<std::string>()), CONFIG["level-name"].as<std::string>())
    );
    _worlds.at("default")->initialize();

    WorldGroup::initialize();
}
