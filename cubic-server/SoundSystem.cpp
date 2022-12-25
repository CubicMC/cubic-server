#include "SoundSystem.hpp"
#include "Player.hpp"

SoundSystem::SoundSystem(const WorldGroup *group)
    : _group(group)
{
}

void SoundSystem::tick()
{
    _sinceLastSE++;
    // 20t = 1s -> SE every 20 seconds
    if (_sinceLastSE <= 20 * 20)
        return;
    _sinceLastSE = 0;
    // TODO: play REAL sound effect
    for (const auto &elm : _group->getWorlds()) {
        for (auto entity : elm.second->getEntities()) {
            auto player = dynamic_cast<Player *>(entity);
            if (!player)
                continue;

            player->playSoundEffect(SoundsList::ambient_cave, player);
        }
    }
}
