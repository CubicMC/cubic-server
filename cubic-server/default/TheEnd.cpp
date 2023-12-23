#include "TheEnd.hpp"
#include "Server.hpp"

void TheEnd::tick()
{
    std::lock_guard<std::mutex> _(_processingMutex);

    // auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    //    LDEBUG("Tick - TheEnd");

    // auto endProcessing = std::chrono::system_clock::now();
}

void TheEnd::initialize()
{
    Dimension::initialize();
    this->_isInitialized = true;
}

void TheEnd::removePlayer(int32_t entity_id)
{
    Dimension::removePlayer(entity_id);
    PEXP(decrementPlayerCountEnd);
}

void TheEnd::spawnPlayer(Player &player)
{
    Dimension::spawnPlayer(player);
    PEXP(incrementPlayerCountEnd);
}
