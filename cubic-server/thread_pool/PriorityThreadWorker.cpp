#include "PriorityThreadWorker.hpp"
#include "logging/logging.hpp"

#ifdef __linux__
#include <sys/prctl.h>
#endif

using namespace thread_pool;

void PriorityThreadWorker::_nameThread()
{
// Named thread is only supported on linux.
#ifdef __linux__
    // only way to set thread name under all linux (no POSIX standard).
    prctl(PR_SET_NAME, reinterpret_cast<unsigned long>((_name + "|" + std::to_string(_threadWorkerId)).c_str()));
#endif
    logging::Registry::instance().setThreadDefaultLogger(_name);
}

void PriorityThreadWorker::resizePool()
{
    bool doAdd = false;
    int oldTargetSize = 0;
    int oldActualSize = 0;
    {
        std::lock_guard<std::mutex> _(_toolBox.sizeProtection);

        if (_toolBox.targetSize == _toolBox.actualSize)
            return;
        oldActualSize = _toolBox.actualSize;
        oldTargetSize = _toolBox.targetSize;
        if (oldTargetSize > oldActualSize) {
            doAdd = true;
            _toolBox.actualSize = _toolBox.targetSize;
        } else
            --_toolBox.actualSize;
    }
    {
        std::lock_guard<std::mutex> _(_toolBox.workerProtection);
        if (!doAdd) {
            _toolBox.workers.erase(_self);
            _stayAlive = false;
        } else {
            int nbToAdd = oldTargetSize - oldActualSize;
            for (int i = 0; i < nbToAdd; ++i) {
                auto newId = _toolBox.lastId.fetch_add(1);
                auto it = _toolBox.workers.emplace(_toolBox.workers.end(), newId, _toolBox, _name);
                it->setSelf(it);
            }
        }
    }
}

void PriorityThreadWorker::doJob()
{
    PriorityThreadPoolUtility::Job jobList;

    _toolBox.jobSemaphore.acquire();
    {
        const std::lock_guard<std::mutex> _guard(_toolBox.queueProtection);

        if (!_toolBox.stayAlive.load() || _toolBox.jobQueue.empty())
            return;

        _toolBox.library.increment();
        --_toolBox.inactiveThreads;

        auto greater = _toolBox.jobQueue.begin();
        for (auto it = greater; it != _toolBox.jobQueue.end(); ++it)
            if (it->priority() < greater->priority())
                greater = it;
        // auto tmp = std::move(greater->second);
        if (greater != _toolBox.jobQueue.end()) {
            jobList = *greater;
            _toolBox.jobQueue.erase(greater);
        }
    }
    do {
        if (jobList.jobs.empty())
            break;
        const auto job = jobList.jobs.front();
        try {
            job();
        } catch (const std::exception &e) { /* TODO: add either a logger or an exception propagation here */
            LERROR(e.what());
        }
        jobList.jobs.pop();
    } while (!jobList.jobs.empty());
    ++_toolBox.totalJobsDone;
    ++_toolBox.inactiveThreads;
    _toolBox.library.decrement();
}

PriorityThreadWorker::PriorityThreadWorker(size_t index, PriorityThreadPoolUtility &toolBox, const std::string_view name):
    _toolBox(toolBox),
    _name(name),
    _threadWorkerId(index)
{
    std::jthread thrd([&]() -> void {
        _nameThread();
        _isInit.wait();
        while (_toolBox.stayAlive.load() && _stayAlive) {
            doJob();
            resizePool();
        }
    });
    _thread.swap(thrd);
}
