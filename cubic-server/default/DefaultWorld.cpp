#include "DefaultWorld.hpp"

#include "Overworld.hpp"
#include "TheEnd.hpp"
#include "TheNether.hpp"
#include "world_storage/Persistence.hpp"
#include <memory>

DefaultWorld::DefaultWorld(std::shared_ptr<WorldGroup> worldGroup, world_storage::WorldType worldType, std::string folder):
    World(worldGroup, worldType, folder),
    persistence(folder)
{
}

void DefaultWorld::tick() { World::tick(); }

void DefaultWorld::initialize()
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));

    World::initialize();
}

void DefaultWorld::stop() { World::stop(); }
