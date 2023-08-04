#include "SoundSystem.hpp"

#include "Dimension.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"

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
    return; // TODO(huntears): Handle sound properly
    for (auto [_, world] : _group.getWorlds()) {
        for (auto [_, dim] : world->getDimensions()) {
            for (auto player : dim->getPlayers()) {
                player->playSoundEffect(SoundsList::block_bell_use, *player, SoundCategory::Ambient);
            }
        }
    }
}
