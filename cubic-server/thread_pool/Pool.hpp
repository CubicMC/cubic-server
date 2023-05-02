#ifndef CUBICSERVER_THREADPOOL_POOL_HPP
#define CUBICSERVER_THREADPOOL_POOL_HPP

#include <atomic>
#include <condition_variable>
#include <deque>
#include <mutex>
#include <thread>
#include <vector>

// #include <bits/stl_construct.h>

#include "Task.hpp"

namespace thread_pool {

class Pool {
public:
    enum Behavior {
        Wait,
        Cancel
    };

public:
    Pool(size_t nbThreads, const std::string &name = "ThreadPool", const Behavior &behavior = Behavior::Wait);
    ~Pool();

    /**
     * @brief Add a new task to the thread pool
     *
     * @note The task will be copied and stored in the queue.
     * The task will be executed by a thread in the pool, even if the thread pool is stopped.
     *
     * @tparam F function type
     * @tparam Args arguments type
     * @param task function to execute
     * @param args arguments to pass to the function
     */
    template<typename F, typename... Args>
    std::shared_ptr<Task> add(F &&task, Args &&...args);

    void cancel(Task::Id id);

    void resize(size_t nbThreads);
    void grow(size_t nbThreads);
    void shrink(size_t nbThreads);

    void stop();
    void wait();

    const std::string &name() const;

    size_t size() const;

    const Behavior &behavior() const;

    // Can't be const because of the mutex
    std::vector<std::shared_ptr<Task>> tasks();

private:
    // no copy
    Pool(const Pool &) = delete;

    void runJob(int id);

private:
    std::vector<std::thread> _workers;
    std::unordered_map<int, bool> _isRunning;
    std::deque<std::shared_ptr<Task>> _tasks;
    std::string _name;

    std::mutex _queueMutex;
    std::condition_variable _condition;
    std::atomic<bool> _stop;
    std::atomic<int32_t> _ids;

    Behavior _behavior;
};

// add new work item to the pool
template<typename F, typename... Args>
std::shared_ptr<Task> Pool::add(F &&taskFunction, Args &&...args)
{
    auto boundTask = std::bind(std::forward<F>(taskFunction), std::forward<Args>(args)...);
    std::shared_ptr<Task> task = nullptr;

    {
        std::unique_lock<std::mutex> lock(_queueMutex);

        if (_stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        _tasks.emplace_back(std::make_shared<Task>(_ids.fetch_add(1), boundTask, this));
        task = _tasks.back();
    }
    _condition.notify_one();
    return task;
}

} // namespace ThreadPool

#endif // CUBICSERVER_THREADPOOL_POOL_HPP
