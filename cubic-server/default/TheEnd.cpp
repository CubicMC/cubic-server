#include "TheEnd.hpp"

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
