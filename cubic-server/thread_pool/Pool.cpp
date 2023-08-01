#include "Pool.hpp"

thread_pool::Pool::Pool(size_t nbThreads, const std::string &name, const Behavior &behavior):
    _name(name),
    _stop(false),
    _behavior(behavior)
{
    this->_queueMutex.lock();
    for (size_t i = 0; i < nbThreads; ++i) {
        this->_isRunning[i] = false;
        this->_workers.emplace_back(&Pool::runJob, this, i);
    }
    this->_queueMutex.unlock();
}

thread_pool::Pool::~Pool() { this->stop(); }

void thread_pool::Pool::cancel(Task::Id id)
{
    this->_queueMutex.lock();
    auto task = std::find_if(this->_tasks.begin(), this->_tasks.end(), [id](const std::shared_ptr<const Task> &task) {
        return task->id() == id;
    });
    if (task != this->_tasks.end())
        (*task)->cancel();
    this->_queueMutex.unlock();
}

void thread_pool::Pool::stop()
{
    if (this->_behavior == Behavior::Cancel) {
        this->_queueMutex.lock();
        this->_tasks.clear();
        this->_queueMutex.unlock();
    }

    this->_stop = true;
    this->_condition.notify_all();

    for (auto &worker : this->_workers) {
        if (worker.joinable())
            worker.join();
    }
}

// TODO(huntears): Fix whatever the hell is going on here
void thread_pool::Pool::wait()
{
    this->_queueMutex.lock();
    while (this->_tasks.size() > 0) {
        this->_queueMutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        this->_queueMutex.lock();
    }
    this->_queueMutex.unlock();

    for (size_t i = 0; i < this->_workers.size(); ++i) {
        // auto &worker = this->_workers[i];
        while (true) {
            if (this->_isRunning[i] != true)
                break;
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
}

void thread_pool::Pool::resize(size_t nbThreads)
{
    if (nbThreads == this->_workers.size())
        return;

    if (nbThreads > this->_workers.size())
        this->grow(nbThreads - this->_workers.size());
    else
        this->shrink(this->_workers.size() - nbThreads);
}

void thread_pool::Pool::grow(size_t nbThreads)
{
    if (nbThreads == 0)
        return;

    for (size_t i = this->_workers.size(); i < nbThreads; ++i)
        this->_workers.emplace_back(&Pool::runJob, this, i);
}

void thread_pool::Pool::shrink(size_t nbThreads)
{
    if (nbThreads == 0)
        return;

    this->_queueMutex.lock();
    this->_stop = true;
    this->_condition.notify_all();

    for (auto &worker : this->_workers) {
        if (worker.joinable())
            worker.join();
    }

    this->_workers.clear();
    this->_stop = false;

    for (size_t i = 0; i < nbThreads; ++i)
        this->_workers.emplace_back(&Pool::runJob, this, i);
    this->_queueMutex.unlock();
}

void thread_pool::Pool::runJob(int workerId)
{
    while (true) {
        std::shared_ptr<Task> task = nullptr;

        while (task == nullptr || task->status() != Task::Status::Waiting) {
            std::unique_lock<std::mutex> lock(this->_queueMutex);
            this->_condition.wait(lock, [this] {
                return this->_stop || !this->_tasks.empty();
            });
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

const std::string &thread_pool::Pool::name() const { return this->_name; }

size_t thread_pool::Pool::size() const { return this->_workers.size(); }

const thread_pool::Pool::Behavior &thread_pool::Pool::behavior() const { return this->_behavior; }

std::vector<std::shared_ptr<thread_pool::Task>> thread_pool::Pool::tasks()
{
    std::vector<std::shared_ptr<thread_pool::Task>> tasks;

    this->_queueMutex.lock();
    for (auto &task : this->_tasks)
        tasks.push_back(task);
    this->_queueMutex.unlock();

    return tasks;
}
