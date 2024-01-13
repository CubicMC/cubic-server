#include "SoundSystem.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "entities/Chicken.hpp"

#include "logging/logging.hpp"

SoundSystem::SoundSystem(const WorldGroup &group):
    _group(group)
{
}

void SoundSystem::tick()
{
    _sinceLastSE++;
    // 20t = 1s -> SE every 20 seconds
    if (_sinceLastSE <= 20 * 20)
        return;
    _sinceLastSE = 0;
    for (auto [_, world] : _group.getWorlds()) {
        for (auto [_, dim] : world->getDimensions()) {
            for (auto player : dim->getPlayers()) {
                player->playSoundEffect({
                    (int32_t) SOUND_EVENT_CONVERTER.fromSoundEventToProtocolId("minecraft:block.bell.use"), (int32_t) SoundCategory::Ambient, player->getId(),
                    1.0, // TODO: get the right volume
                    1.0, // TODO: get the right pitch
                    1 // TODO: get the right seed
                });
            }
        }
    }

    // Spawn a chicken if there is none
    // auto dim = const_cast<WorldGroup &>(_group).getWorld("default")->getDimension("overworld");
    // int chickenCount = 0;
    // for (auto entity : dim->getEntities()) {
    //     if (entity->getType() == EntityType::Chicken)
    //         chickenCount++;
    // }
    // if (chickenCount > 0)
    //     return;
    // auto chicken = dim->makeEntity<Chicken>();
    // LINFO("spawn entity chicken");
    // dim->spawnEntity(chicken);
}
