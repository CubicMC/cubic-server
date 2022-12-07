#include "Overworld.hpp"
#include "../world-storage/WorldStorage.hpp"
#include "../world-storage/ChunkColumn.hpp"

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
    for (int x = -1, z = -1; x != 1 && z != 1; x++) {
        generateChunk(x, z);
        if (x == 1) {
            x = -1;
            z++;
        }
    }
}

void Overworld::generateChunk(int x, int z)
{
    LDEBUG("Generate - Overworld(" + std::to_string(x) + ", " + std::to_string(x) + ")");
    _2d_pos pos{x, z};
    _world->getWorldStorage().getLevelM("overworld")->addChunkColumn(pos)->generate(WorldType::FLAT);
}