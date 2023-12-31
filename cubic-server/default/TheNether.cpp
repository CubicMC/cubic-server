#include "TheNether.hpp"

#include "Dimension.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "default/DefaultWorld.hpp"
#include "logging/logging.hpp"
#include "world_storage/Level.hpp"
#include <future>
#include <memory>
#include <queue>

#include <iostream>

void TheNether::tick()
{
    std::lock_guard<std::mutex> _(_processingMutex);

    // auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    // LDEBUG("Tick - TheNether");

    // auto endProcessing = std::chrono::system_clock::now();
}

void TheNether::initialize()
{
    Dimension::initialize();
    LINFO("Initialize - TheNether");
    int x = -NB_SPAWN_CHUNKS / 2, z = -NB_SPAWN_CHUNKS / 2;
    int i = 0;
    while (x < NB_SPAWN_CHUNKS / 2 || z < NB_SPAWN_CHUNKS / 2) {
        // temporary percentage calculation. ugly but works :DDD gets deleted after usage to ensure clean logs.
        ++i;
        this->getWorld()->getGenerationPool().addJob([x, z, i, this] {
            std::stringstream ss;
            constexpr std::array<std::string_view, 4> animation {"/", "-", "\\", "|"}; // cute little animation :D
            ss << animation[i % 4] << " Generating " << i * 100 / (NB_SPAWN_CHUNKS * NB_SPAWN_CHUNKS) << "% " << animation[i % 4] << '\r';
            std::cerr << ss.str();
            generateChunk(x, z, world_storage::GenerationState::READY);
        });
        if (x == NB_SPAWN_CHUNKS / 2) {
            x = -NB_SPAWN_CHUNKS / 2;
            z++;
        } else
            x++;
    }
    this->getWorld()->getGenerationPool().addJob([x, z, this] {
        generateChunk(x, z, world_storage::GenerationState::READY);
    });

    // TODO: Move this to a better place
    this->_worldGenFuture = std::async(std::launch::async, [this] {
        this->getWorld()->getGenerationPool().waitUntilJobsDone();
        LINFO("TheNether initialized");
        this->_isInitialized = true;
    });
}

void TheNether::stop()
{
    Dimension::stop();
    this->_worldGenFuture.wait();
}

void TheNether::generateChunk(int x, int z, world_storage::GenerationState goalState)
{
    auto world = std::dynamic_pointer_cast<DefaultWorld>(_world);
    if (world->persistence.isChunkLoaded(*this, x, z)) {
        LDEBUG("Chunk loaded {} {}", x, z);
        return;
    }

    LDEBUG("Generate - TheNether ({}, {})", x, z);
    Position2D pos {x, z};
    // TODO(huntears): tmp to deactivate generation
    if (CONFIG["enable-generation"].as<bool>())
        _level.addChunkColumn(pos, shared_from_this()).generate(goalState);
    else
        _level.addChunkColumn(pos, shared_from_this());
}

void TheNether::removePlayer(int32_t entity_id)
{
    Dimension::removePlayer(entity_id);
    PEXP(incrementPlayerCountNether);
}

void TheNether::spawnPlayer(Player &player)
{
    Dimension::spawnPlayer(player);
    PEXP(incrementPlayerCountNether);
}
