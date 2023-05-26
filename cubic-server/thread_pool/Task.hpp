#ifndef CUBICSERVER_THREADPOOL_TASK_HPP
#define CUBICSERVER_THREADPOOL_TASK_HPP

#include <cstdint>
#include <functional>

namespace thread_pool {

class Pool;

class Task {
public:
    enum Status {
        Canceled,
        Waiting,
        Running,
        Done
    };

    typedef size_t Id;

public:
    // This constructor should be private, but because we are making shared_ptr<Task> in the Pool class, we need to make it public
    /**
     * @brief Construct a new Task object
     *
     * @private This constructor is private and should only be used by the Pool class
     *
     * @param id The id of the task
     * @param task
     * @param pool
     */
    Task(Id id, std::function<void()> task);
    Task() = default;
    Task(const Task &other) = default;
    Task(Task &&other) noexcept = default;
    ~Task() = default;

    Task &operator=(const Task &other) = default;
    Task &operator=(Task &&other) noexcept = default;

    bool operator==(const Task &other) const;
    bool operator==(Id id) const;

    const Status &status() const;
    Id id() const;

    void cancel();
    void run();
    void operator()();

private:
    Id _id;
    Status _status;
    std::function<void()> _task;
};

} // namespace thread_pool

#endif // CUBICSERVER_THREADPOOL_TASK_HPP
