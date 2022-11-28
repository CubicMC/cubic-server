#include "Overworld.hpp"
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
}

void Overworld::generateChunk(int x, int z)
{
    // Put the generation code specific for this dimension here
    LDEBUG("Generate - Overworld(%d, %d)", x, z);
    this->_world->worldStorage.getLevel("overworld").addChunkColumn({x, z}).generate(WorldType::FLAT);
}