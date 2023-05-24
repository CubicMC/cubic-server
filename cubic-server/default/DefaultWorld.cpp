#include "DefaultWorld.hpp"

#include "Overworld.hpp"
#include "TheEnd.hpp"
#include "TheNether.hpp"
#include "world_storage/Persistence.hpp"
#include <memory>

DefaultWorld::DefaultWorld(std::shared_ptr<WorldGroup> worldGroup, std::string folder):
    World(worldGroup, folder),
    persistence(std::make_unique<world_storage::Persistence>(std::weak_ptr<World>(), ""))
{
}

void DefaultWorld::tick() { World::tick(); }

void DefaultWorld::initialize()
{
    this->_dimensions.emplace("end", std::make_shared<TheEnd>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));
    this->_dimensions.emplace("nether", std::make_shared<TheNether>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));
    this->_dimensions.emplace("overworld", std::make_shared<Overworld>(std::dynamic_pointer_cast<DefaultWorld>(shared_from_this())));

    persistence = std::make_unique<world_storage::Persistence>(shared_from_this(), _folder);

    World::initialize();
}

void DefaultWorld::stop() { World::stop(); }
