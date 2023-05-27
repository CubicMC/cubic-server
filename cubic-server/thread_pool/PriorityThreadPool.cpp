#include "PriorityThreadPool.hpp"
#include "logging/logging.hpp"

using namespace thread_pool;

PriorityThreadPool::PriorityThreadPool(uint16_t threadCount, std::string_view name):
    _name(name)
{
    std::lock_guard<std::mutex> guard(_toolBox.workerProtection);
    std::lock_guard<std::mutex> _(_toolBox.sizeProtection);
    logging::registerLogger(std::string(name));
    for (; _toolBox.lastId < threadCount; ++_toolBox.lastId) {
        auto it = _toolBox.workers.emplace(_toolBox.workers.end(), _toolBox.lastId, _toolBox, name);
        it->setSelf(it);
    }
    _toolBox.targetSize = threadCount;
    _toolBox.actualSize = threadCount;
}

PriorityThreadPool::~PriorityThreadPool()
{
    _toolBox.stayAlive.store(false);
    _toolBox.jobSemaphore.release(_toolBox.targetSize); // we might end up releasing more than enough, however that's destructor so we don't care.
    logging::unregisterLogger(std::string(_name));
}

[[maybe_unused]] void PriorityThreadPool::waitUntilJobsDone() const
{
    do {
        _toolBox.library.wait();
    } while (_toolBox.jobSemaphore.getCounter() != 0);
}

// ThreadPool::operator bool() const { return safeQueueEmpty() && _toolBox.inactiveThreads == threadCount; }

[[nodiscard]] bool PriorityThreadPool::safeQueueEmpty() const
{
    const std::lock_guard<std::mutex> _guard(_toolBox.queueProtection);
    return _toolBox.jobQueue.empty();
}
