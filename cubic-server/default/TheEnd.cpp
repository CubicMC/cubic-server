#include "TheEnd.hpp"
#include "logging/logging.hpp"

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

void TheEnd::save(const std::string &folder)
{
    Dimension::save(folder + "/DIM1");
    LINFO("Save - TheEnd");
}