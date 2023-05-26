#ifndef CUBICSERVER_SOUNDSYSTEM_HPP
#define CUBICSERVER_SOUNDSYSTEM_HPP

#include <cstdint>

class WorldGroup;

class SoundSystem {
public:
    SoundSystem(const WorldGroup &group);
    ~SoundSystem() = default;

    void tick();

private:
    const WorldGroup &_group;
    uint32_t _sinceLastSE = 0;
};

#endif // SOUND_SYSTEM_HPP
