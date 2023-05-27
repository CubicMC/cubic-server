#include "Task.hpp"

thread_pool::Task::Task(Id id, std::function<void()> task):
    _id(id),
    _status(Status::Waiting),
    _task(task)
{
}

bool thread_pool::Task::operator==(const Task &other) const { return this->_id == other._id; }

bool thread_pool::Task::operator==(Id id) const { return this->_id == id; }

const thread_pool::Task::Status &thread_pool::Task::status() const { return this->_status; }

void thread_pool::Task::cancel()
{
    if (this->_status == Status::Running)
        return;
    this->_status = Status::Canceled;
}

thread_pool::Task::Id thread_pool::Task::id() const { return this->_id; }

void thread_pool::Task::run()
{
    this->_status = Status::Running;
    this->_task();
    this->_status = Status::Done;
}

void thread_pool::Task::operator()() { this->run(); }
