#include "TheEnd.hpp"

void TheEnd::tick()
{
    _processingMutex.lock();

    auto startProcessing = std::chrono::system_clock::now();

    Dimension::tick();
    // Put the ticking code specific for this dimension here
    //    LDEBUG("Tick - TheEnd");

    auto endProcessing = std::chrono::system_clock::now();
    _processingMutex.unlock();
}

void TheEnd::initialize()
{
    Dimension::initialize();
    this->_isInitialized = true;
}
