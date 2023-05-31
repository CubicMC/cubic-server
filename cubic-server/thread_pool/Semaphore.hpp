#ifndef ZENITH_SEMAPHORE_HPP
#define ZENITH_SEMAPHORE_HPP

#include <condition_variable>
#include <mutex>

namespace thread_pool {

class ReverseSemaphore {
private:
    std::atomic<bool> _notifier {true};
    int _books {0};
    std::mutex _bookMutex;

public:
    void increment(int nb = 1)
    {
        std::lock_guard<std::mutex> _(_bookMutex);
        _books += nb;
        _notifier = false;
    }
    void decrement()
    {
        std::lock_guard<std::mutex> _(_bookMutex);
        --_books;
        if (_books == 0) {
            _notifier = true;
            _notifier.notify_all();
        }
    }

    void wait()
    {
        while (true) {
            _notifier.wait(false, std::memory_order::relaxed);
            std::lock_guard<std::mutex> guard(_bookMutex);
            if (_books != 0)
                continue;
            return;
        }
    }
};

// light semaphore recoded. might have some bugs
class Semaphore {
private:
    std::atomic<std::ptrdiff_t> _counter {};
    std::mutex _counterMutex {};

public:
    std::ptrdiff_t getCounter() const noexcept { return _counter; }

    void release(std::ptrdiff_t n = 1)
    {
        _counter += n;
        _counter.notify_all();
    }

    void increment(std::ptrdiff_t n = 1)
    {
        std::lock_guard<std::mutex> guard(_counterMutex);
        if (_counter > n)
            _counter -= n;
        else
            _counter = 0;
        _counter.notify_all();
    }

    void acquire(std::ptrdiff_t n = 1)
    {
        while (true) {
            _counter.wait(0, std::memory_order::relaxed);

            std::lock_guard<std::mutex> guard(_counterMutex);
            if (_counter < n)
                continue;
            _counter -= n;
            return;
        }
    }
};
}

#endif /* ZENITH_SEMAPHORE_HPP */
