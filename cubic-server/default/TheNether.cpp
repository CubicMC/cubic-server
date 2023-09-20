#include "TheNether.hpp"
#include "logging/logging.hpp"

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

void TheNether::save(const std::string &folder)
{
    Dimension::save(folder + "/DIM-1");
    LINFO("Save - TheNether");
}