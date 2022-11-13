#include "TheNether.hpp"

void TheNether::initialize()
{
    Dimension::initialize();
}

void TheNether::tick()
{
    _numThreadsWaiting++;
    _processingMutex.lock();
    _numThreadsWaiting--;

    auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    LDEBUG("Tick - TheNether");

    auto endProcessing = std::chrono::system_clock::now();
    _processingMutex.unlock();
}
