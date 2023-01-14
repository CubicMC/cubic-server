#include "TickClock.hpp"

std::vector<TickClock *> TickClock::_tickClocks;

TickClock::TickClock(uint16_t tickRate)
    : _tickRate(tickRate), _started(false), _tick(0)
{
    _tickClocks.push_back(this);
}

TickClock::TickClock(uint16_t tickRate, std::function<void()> callback)
    : _tickRate(tickRate), _callback(callback), _tick(0)
{
    _tickClocks.push_back(this);
}

TickClock::~TickClock()
{
    _tickClocks.erase(std::remove(_tickClocks.begin(), _tickClocks.end(), this), _tickClocks.end());
}

void TickClock::start()
{
    _started = true;
    _tick = 0;
}

void TickClock::stop()
{
    _started = false;
    _tick = 0;
}

void TickClock::tick()
{
    if (!_started)
        return;
    _tick++;
    if (_tick < _tickRate)
        return;

    _tick = 0;
    if (_callback)
        _callback();
}

void TickClock::setTickRate(uint16_t tickRate)
{
    _tickRate = tickRate;
}

uint16_t TickClock::tickRate() const
{
    return _tickRate;
}

void TickClock::setCallback(std::function<void()> callback)
{
    _callback = callback;
}

const std::function<void()> &TickClock::callback() const
{
    return _callback;
}
