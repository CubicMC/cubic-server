#ifndef TICK_CLOCK_HPP
#define TICK_CLOCK_HPP

#include <cstdint>
#include <functional>
#include <vector>

class TickClock
{
public:
    TickClock() = default;
    ~TickClock() = default;
    TickClock(uint16_t tickRate);
    TickClock(uint16_t tickRate, std::function<void()> callback);

    void start();
    void stop();
    void tick();

    void setTickRate(uint16_t tickRate);
    uint16_t tickRate() const;

    void setCallback(std::function<void()> callback);
    const std::function<void()> &callback() const;

private:
    bool _started;
    uint16_t _tickRate;
    std::function<void()> _callback;
    uint16_t _tick;
};

#endif // TICK_CLOCK_HPP
