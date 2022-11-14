#include "Overworld.hpp"

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
