#include "Overworld.hpp"

#include "Server.hpp"
#include "World.hpp"
#include "default/DefaultWorld.hpp"
#include "logging/logging.hpp"
#include "world_storage/Level.hpp"
#include <future>
#include <memory>
#include <queue>

#include <iostream>

void Overworld::tick()
{
    std::lock_guard<std::mutex> _(_processingMutex);

    // auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    // LDEBUG("Tick - Overworld");

    // auto endProcessing = std::chrono::system_clock::now();
}

void Overworld::initialize()
{
    Dimension::initialize();
    LINFO("Initialize - Overworld");
    int x = -NB_SPAWN_CHUNKS / 2, z = -NB_SPAWN_CHUNKS / 2;
#ifdef NDEBUG
    int i = 0;
#endif
    while (x < NB_SPAWN_CHUNKS / 2 || z < NB_SPAWN_CHUNKS / 2) {
#ifdef NDEBUG
        // temporary percentage calculation. ugly but works :DDD gets deleted after usage to ensure clean logs.
        ++i;
#endif
        this->getWorld()->getGenerationPool().addJob([=, this] {
#ifdef NDEBUG
            std::stringstream ss;
            constexpr std::array<std::string_view, 4> animation {"/", "-", "\\", "|"}; // cute little animation :D
            ss << animation[i % 4] << " Generating " << i * 100 / (NB_SPAWN_CHUNKS * NB_SPAWN_CHUNKS) << "% " << animation[i % 4] << '\r';
            std::cerr << ss.str();
#endif
            generateChunk(x, z);
        });
        if (x == NB_SPAWN_CHUNKS / 2) {
            x = -NB_SPAWN_CHUNKS / 2;
            z++;
        } else
            x++;
    }
    this->getWorld()->getGenerationPool().addJob([=, this] {
        generateChunk(x, z);
    });

    // TODO: Move this to a better place
    this->_worldGenFuture = std::async(std::launch::async, [this] {
        this->getWorld()->getGenerationPool().waitUntilJobsDone();
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
    auto world = std::dynamic_pointer_cast<DefaultWorld>(_world);
    if (world->persistence.isChunkLoaded(*this, x, z)) {
        LDEBUG("Chunk loaded {} {}", x, z);
        return;
    }

    LDEBUG("Generate - Overworld ({}, {})", x, z);
    Position2D pos {x, z};
    // TODO(huntears): tmp to deactivate generation
    if (CONFIG["enable-generation"].as<bool>())
        _level.addChunkColumn(pos).generate(world_storage::WorldType::NORMAL, this->getWorld()->getSeed());
    else
        _level.addChunkColumn(pos);
}
