#include "TheNether.hpp"
#include "Server.hpp"

void TheNether::initialize()
{
    Dimension::initialize();
    this->_isInitialized = true;
}

void TheNether::tick()
{
    std::lock_guard<std::mutex> _(_processingMutex);

    // auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    //    LDEBUG("Tick - TheNether");

    // auto endProcessing = std::chrono::system_clock::now();
}

void TheNether::removePlayer(int32_t entity_id)
{
    Dimension::removePlayer(entity_id);
    PEXP(decrementPlayerCountNether);
}

void TheNether::spawnPlayer(Player &player)
{
    Dimension::spawnPlayer(player);
    PEXP(incrementPlayerCountNether);
}
