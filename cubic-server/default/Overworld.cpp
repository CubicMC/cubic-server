#include "Overworld.hpp"
#include "World.hpp"

void Overworld::tick()
{
    _numThreadsWaiting++;
    _processingMutex.lock();
    _numThreadsWaiting--;

    auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
//    LDEBUG("Tick - Overworld");

    auto endProcessing = std::chrono::system_clock::now();
    _processingMutex.unlock();
}

void Overworld::initialize()
{
    Dimension::initialize();
    int x = -NB_SPAWN_CHUNKS/2, z = -NB_SPAWN_CHUNKS/2;
    while (x < NB_SPAWN_CHUNKS/2 || z < NB_SPAWN_CHUNKS/2) {
        generateChunk(x, z);
        if (x == NB_SPAWN_CHUNKS/2) {
            x = -NB_SPAWN_CHUNKS/2;
            z++;
        } else
            x++;
    }
    generateChunk(x, z);
}

void Overworld::generateChunk(int x, int z)
{
    LDEBUG("Generate - Overworld (" + std::to_string(x) + ", " + std::to_string(z) + ")");
    _2d_pos pos{x, z};
    _level.addChunkColumn(pos).generate(world_storage::WorldType::FLAT);
}
