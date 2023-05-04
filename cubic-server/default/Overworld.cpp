#include "Overworld.hpp"

#include "World.hpp"
#include "logging/Logger.hpp"

void Overworld::tick()
{
    _processingMutex.lock();

    // auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    // LDEBUG("Tick - Overworld");

    // auto endProcessing = std::chrono::system_clock::now();
    _processingMutex.unlock();
}

void Overworld::initialize()
{
    Dimension::initialize();
    LINFO("Initialize - Overworld");
    int x = -NB_SPAWN_CHUNKS / 2, z = -NB_SPAWN_CHUNKS / 2;
    while (x < NB_SPAWN_CHUNKS / 2 || z < NB_SPAWN_CHUNKS / 2) {
        this->getWorld()->getGenerationPool().add(&Overworld::generateChunk, this, x, z, world_storage::GenerationState::READY);
        if (x == NB_SPAWN_CHUNKS / 2) {
            x = -NB_SPAWN_CHUNKS / 2;
            z++;
        } else
            x++;
    }
    this->getWorld()->getGenerationPool().add(&Overworld::generateChunk, this, x, z, world_storage::GenerationState::READY);

    // TODO: Move this to a better place
    this->_worldGenFuture = std::async(std::launch::async, [this] {
        this->getWorld()->getGenerationPool().wait();
        LINFO("Overworld initialized");
        this->_isInitialized = true;
    });
}

void Overworld::stop()
{
    Dimension::stop();
    this->_worldGenFuture.wait();
}

void Overworld::generateChunk(int x, int z, world_storage::GenerationState goalState)
{
    LDEBUG("Generate - Overworld (", x, ", ", z, ")");
    Position2D pos {x, z};
    _level.addChunkColumn(pos, shared_from_this()).generate(goalState);
    LDEBUG("Chunk generated (", x, ", ", z, ")");
}
