#include "ThreadPool.hpp"
#include "logging/logging.hpp"

using namespace thread_pool;

ThreadPool::ThreadPool(uint16_t threadCount, std::string_view name)
{
    std::lock_guard<std::mutex> guard(_toolBox.workerProtection);
    std::lock_guard<std::mutex> _(_toolBox.sizeProtection);
    logging::registerLogger(name);
    for (; _toolBox.lastId < threadCount; ++_toolBox.lastId) {
        auto it = _toolBox.workers.emplace(_toolBox.workers.end(), _toolBox.lastId, _toolBox, name);
        it->setSelf(it);
    }
    _toolBox.targetSize = threadCount;
    _toolBox.actualSize = threadCount;
}

ThreadPool::~ThreadPool()
{
    _toolBox.stayAlive.store(false);
    _toolBox.jobSemaphore.release(_toolBox.targetSize); // we might end up releasing more than enough, however that's destructor so we don't care.
}

[[maybe_unused]] void ThreadPool::waitUntilJobsDone() const { _toolBox.library.wait(); }

// ThreadPool::operator bool() const { return safeQueueEmpty() && _toolBox.inactiveThreads == threadCount; }

[[nodiscard]] bool ThreadPool::safeQueueEmpty() const
{
    const std::lock_guard<std::mutex> _guard(_toolBox.queueProtection);
    return _toolBox.jobQueue.empty();
}
