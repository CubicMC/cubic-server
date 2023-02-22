#ifndef THREADPOOL_HPP
#define THREADPOOL_HPP

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

#include <bits/stl_construct.h>

class ThreadPool
{
public:
    class Task
    {
    public:
        enum Status
        {
            Canceled,
            Waiting,
            Running,
            Done
        };

        typedef size_t Id;

    public:
        Task() = default;
        Task(const Task &other) = default;
        Task(Task &&other) noexcept = default;
        Task(Id id, std::function<void()> task, ThreadPool *pool);
        ~Task() = default;

        Task &operator=(const Task &other) = default;
        Task &operator=(Task &&other) noexcept = default;

        bool operator==(const Task &other) const
        {
            return this->_id == other._id;
        }

        bool operator==(Id id) const
        {
            return this->_id == id;
        }

        Status status() const
        {
            return this->_status;
        }

        Status &status()
        {
            return this->_status;
        }

        void cancel()
        {
            if (this->_status == Status::Running)
                return;
            this->status() = Status::Canceled;
        }

        Id id() const
        {
            return this->_id;
        }

        void run()
        {
            this->_status = Status::Running;
            this->_task();
            this->_status = Status::Done;
        }

        void operator()()
        {
            this->run();
        }

    private:
        Id _id;
        Status _status;
        std::function<void()> _task;
        ThreadPool *_pool;
    };

    enum Behavior
    {
        Wait,
        Cancel
    };

public:
    ThreadPool(size_t nbThreads, const std::string &name = "ThreadPool", const Behavior &behavior = Behavior::Wait);
    ~ThreadPool();

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
    template <typename F, typename... Args>
    std::shared_ptr<Task> add(F &&task, Args &&... args);

    void cancel(Task::Id id);

    void resize(size_t nbThreads);
    void grow(size_t nbThreads);
    void shrink(size_t nbThreads);

    void stop();
    void wait();

    std::string name() const;
    std::string &name();

    size_t size() const;

    Behavior behavior() const;
    Behavior &behavior();

    // Can't be const because of the mutex
    std::vector<std::shared_ptr<Task>> tasks();

private:
    // no copy
    ThreadPool(const ThreadPool &) = delete;

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
template <typename F, typename... Args>
std::shared_ptr<ThreadPool::Task> ThreadPool::add(F &&taskFunction, Args &&... args)
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

#endif //THREADPOOL_HPP
