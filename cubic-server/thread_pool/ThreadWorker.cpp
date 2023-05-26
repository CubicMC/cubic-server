#include "ThreadWorker.hpp"

#ifdef __linux__
#include <sys/prctl.h>
#endif

using namespace thread_pool;

#ifdef __linux__
void ThreadWorker::_nameThread()
{
    prctl(PR_SET_NAME, reinterpret_cast<unsigned long>((_name + "|" + std::to_string(_threadWorkerId)).c_str()));
} // only way to set thread name under all linux (no POSIX standard).
#else
void ThreadWorker::_nameThread() { } // currently not supported. not all os supports this anyway
#endif

void ThreadWorker::resizePool()
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

void ThreadWorker::doJob()
{
    _toolBox.jobSemaphore.acquire();
    _toolBox.library.increment();
    if (!_toolBox.stayAlive.load())
        return;
    --_toolBox.inactiveThreads;
    std::queue<std::function<void(void)>> jobList;
    {
        const std::lock_guard<std::mutex> _guard(_toolBox.queueProtection);
        jobList = _toolBox.jobQueue.front();
        _toolBox.jobQueue.pop();
    }
    do {
        const auto job = jobList.front();
        try {
            job();
        } catch (const std::exception &) { /* TODO: add either a logger or an exception propagation here */
        }
        jobList.pop();
    } while (!jobList.empty());
    ++_toolBox.totalJobsDone;
    ++_toolBox.inactiveThreads;
    _toolBox.library.decrement();
}

ThreadWorker::ThreadWorker(size_t index, ThreadPoolUtility &toolBox, const std::string_view name):
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
