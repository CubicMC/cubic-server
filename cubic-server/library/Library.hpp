#pragma once

#include "Symbol.hpp"

class Library {
public:
    virtual ~Library() = default;

    template<typename T>
    Symbol<T> *getSymbol(const std::string &name)
    {
        if (auto symbol = _getSymbol(name))
            return new Symbol<T>(name, symbol);
        return nullptr;
    }

    void *getRawSymbol(const std::string &name) { return _getSymbol(name); }

protected:
    virtual void *_getSymbol(const std::string_view &name) = 0;
};
