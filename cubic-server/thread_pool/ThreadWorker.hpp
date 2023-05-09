#ifndef ZENITH_THREADWORKER_HPP
#define ZENITH_THREADWORKER_HPP

//=============
// STD includes
//=============
#include <latch>
#include <memory>
#include <string>
#include <thread>

//=====================
// thread_pool includes
//=====================
#include "ThreadPoolUtility.hpp"

namespace thread_pool {
//-----------------------------------------------------------------------------
/// @brief      Thread worker.
///
class ThreadWorker {
private:
    ThreadPoolUtility &_toolBox;
    std::string _name;
    std::jthread _thread;

    bool _stayAlive {true};

    std::list<ThreadWorker>::iterator _self = _toolBox.workers.end();

    std::latch _isInit {1}; // when 0, it is considered ready for work.

    size_t _threadWorkerId {0};

    void _nameThread();

    void doJob();

    void resizePool();

public:
    ThreadWorker(size_t index, ThreadPoolUtility &toolBox, const std::string_view name);

    ~ThreadWorker() = default;

    // this needs to be called only once. else, it will throw for safety reasons.
    void setSelf(std::list<ThreadWorker>::iterator self)
    {
        if (_self != _toolBox.workers.end())
            throw thread_pool::JobException("Trying to set an already setted iterator on worker");
        _self = self;
        _isInit.count_down();
    }
};
}

#endif /* ZENITH_THREADWORKER_HPP */
