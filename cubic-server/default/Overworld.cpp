#include "Overworld.hpp"
#include "World.hpp"
#include <future>
#include <queue>

void Overworld::tick()
{
    _processingMutex.lock();

    auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    // LDEBUG("Tick - Overworld");

    auto endProcessing = std::chrono::system_clock::now();
    _processingMutex.unlock();
}

void Overworld::initialize()
{
    Dimension::initialize();
    LINFO("Initialize - Overworld");
    int x = -NB_SPAWN_CHUNKS / 2, z = -NB_SPAWN_CHUNKS / 2;
    while (x < NB_SPAWN_CHUNKS / 2 || z < NB_SPAWN_CHUNKS / 2) {
        this->getWorld()->getGenerationPool().add(&Overworld::generateChunk, this, x, z);
        if (x == NB_SPAWN_CHUNKS / 2) {
            x = -NB_SPAWN_CHUNKS / 2;
            z++;
        } else
            x++;
    }
    this->getWorld()->getGenerationPool().add(&Overworld::generateChunk, this, x, z);

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

void Overworld::generateChunk(int x, int z)
{
    LDEBUG("Generate - Overworld (", x, ", ", z, ")");
    Position2D pos {x, z};
    _level.addChunkColumn(pos).generate(world_storage::WorldType::NORMAL, this->getWorld()->getSeed());
    LDEBUG("Chunk generated (", x, ", ", z, ")");
}
