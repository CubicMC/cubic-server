#pragma once

#include <functional>
#include <string>

template<typename T>
class Symbol;

template<typename Result, typename... Args>
class Symbol<Result(Args...)> {
public:
    Symbol(const std::string &name, void *symbol):
        _name(name),
        _symbol(symbol),
        _function(reinterpret_cast<Result(Args...)>(symbol))
    {
    }

    void *get() { return _symbol; }

    Result operator()(Args... args) { return _function(std::forward<Args>(args)...); }

private:
    const std::string &_name;
    void *_symbol;
    std::function<Result(Args...)> _function;
};
