#include "TheNether.hpp"

void TheNether::initialize()
{
    Dimension::initialize();
    this->_isInitialized = true;
}

void TheNether::tick()
{
    _processingMutex.lock();

    auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    //    LDEBUG("Tick - TheNether");

    auto endProcessing = std::chrono::system_clock::now();
    _processingMutex.unlock();
}
