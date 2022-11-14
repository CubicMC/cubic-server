#ifndef CUBICSERVER_DIMENSION_HPP
#define CUBICSERVER_DIMENSION_HPP


#include <atomic>
#include <thread>
#include <vector>

#include "Logger.hpp"

class Dimension
{
public:
    Dimension() {
        _log = logging::Logger::get_instance();
    }
    virtual void initialize();
    virtual void tick();
protected:
    logging::Logger *_log;
    std::atomic<int> _numThreadsWaiting;
    std::mutex _processingMutex;
};


#endif //CUBICSERVER_DIMENSION_HPP
