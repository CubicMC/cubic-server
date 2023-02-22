#include "ThreadPool.hpp"
#include "logging/Logger.hpp"

ThreadPool::Task::Task(Id id, std::function<void()> task, ThreadPool *pool):
    _id(id),
    _status(Status::Waiting),
    _task(task),
    _pool(pool)
{}

ThreadPool::ThreadPool(size_t nbThreads, const std::string &name, const Behavior &behavior):
    _name(name),
    _stop(false),
    _behavior(behavior)
{
    this->_queueMutex.lock();
    for (size_t i = 0; i < nbThreads; ++i) {
        this->_isRunning[i] = false;
        this->_workers.emplace_back(&ThreadPool::runJob, this, i);
    }
    this->_queueMutex.unlock();
}

ThreadPool::~ThreadPool()
{
    this->stop();
}

void ThreadPool::cancel(Task::Id id)
{
    this->_queueMutex.lock();
    auto task = std::find_if(
        this->_tasks.begin(),
        this->_tasks.end(),
        [id](const std::shared_ptr<Task> &task) {
            return task->id() == id;
        }
    );
    if (task != this->_tasks.end())
        (*task)->cancel();
    this->_queueMutex.unlock();
}

void ThreadPool::stop()
{
    if (this->_behavior == Behavior::Cancel) {
        this->_queueMutex.lock();
        this->_tasks.clear();
        this->_queueMutex.unlock();
    }

    this->_stop = true;
    this->_condition.notify_all();

    for (auto &worker: this->_workers) {
        if (worker.joinable())
            worker.join();
    }
}

void ThreadPool::wait()
{
    this->_queueMutex.lock();
    while (this->_tasks.size() > 0) {
        this->_queueMutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        this->_queueMutex.lock();
    }
    this->_queueMutex.unlock();

    for (size_t i = 0; i < this->_workers.size(); ++i) {
        auto &worker = this->_workers[i];
        while (true) {
            if (this->_isRunning[i] != true)
                break;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}

void ThreadPool::resize(size_t nbThreads)
{
    if (nbThreads == this->_workers.size())
        return;

    if (nbThreads > this->_workers.size())
        this->grow(nbThreads - this->_workers.size());
    else
        this->shrink(this->_workers.size() - nbThreads);
}

void ThreadPool::grow(size_t nbThreads)
{
    if (nbThreads == 0)
        return;

    for (size_t i = this->_workers.size(); i < nbThreads; ++i)
        this->_workers.emplace_back(&ThreadPool::runJob, this, i);
}

void ThreadPool::shrink(size_t nbThreads)
{
    if (nbThreads == 0)
        return;

    this->_queueMutex.lock();
    this->_stop = true;
    this->_condition.notify_all();

    for (auto &worker: this->_workers) {
        if (worker.joinable())
            worker.join();
    }

    this->_workers.clear();
    this->_stop = false;

    for (size_t i = 0; i < nbThreads; ++i)
        this->_workers.emplace_back(&ThreadPool::runJob, this, i);
    this->_queueMutex.unlock();
}

void ThreadPool::runJob(int workerId)
{
    while(true)
    {
        std::shared_ptr<Task> task = nullptr;

        while (task == nullptr || task->status() != Task::Status::Waiting) {
            std::unique_lock<std::mutex> lock(this->_queueMutex);
            this->_condition.wait(lock, [this]{ return this->_stop || !this->_tasks.empty(); });
            if (this->_stop && this->_tasks.empty())
                return;
            task = std::move(this->_tasks.front());
            this->_tasks.pop_front();
        }

        this->_isRunning[workerId] = true;
        task->run();
        this->_isRunning[workerId] = false;
    }
}


std::string ThreadPool::name() const
{
    return this->_name;
}

std::string &ThreadPool::name()
{
    return this->_name;
}


size_t ThreadPool::size() const
{
    return this->_workers.size();
}


ThreadPool::Behavior ThreadPool::behavior() const
{
    return this->_behavior;
}

ThreadPool::Behavior &ThreadPool::behavior()
{
    return this->_behavior;
}

std::vector<std::shared_ptr<ThreadPool::Task>> ThreadPool::tasks()
{
    std::vector<std::shared_ptr<Task>> tasks;

    this->_queueMutex.lock();
    for (auto &task: this->_tasks)
        tasks.push_back(task);
    this->_queueMutex.unlock();

    return tasks;
}
