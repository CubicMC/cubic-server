#ifndef CUBICSERVER_REGISTRY_HPP
#define CUBICSERVER_REGISTRY_HPP

#include "concept.hpp"
#include "nbt.hpp"
#include <memory>
#include <vector>
#include <string_view>

class Server;

namespace registry {

class Entry {
public:
    explicit Entry() = default;
    virtual ~Entry();

    virtual std::shared_ptr<nbt::Base> toNBT() const = 0;
    virtual bool operator==(const std::string &) const = 0;
};

class Registry {
public:
    template<isBaseOf<Entry> T>
    explicit Registry(std::string_view name);
    ~Registry();

    template<isBaseOf<Entry> T, typename... Args>
    std::shared_ptr<T> addEntry(Args &&... args);

    std::shared_ptr<nbt::Base> toNBT() const;

protected:
    std::vector<std::shared_ptr<Entry>> _entries;
    std::function<std::shared_ptr<Entry>(std::string_view)> _entryFactory;
};

} // namespace regsitry

template<isBaseOf<registry::Entry> T>
registry::Registry::Registry(std::string_view name):
    _entryFactory([name](auto &&... entry) -> std::shared_ptr<registry::Entry> {
        return std::make_shared<T>(name, std::forward(entry)...);
    })
{
}

template<isBaseOf<registry::Entry> T, typename... Args>
std::shared_ptr<T> registry::Registry::addEntry(Args &&... args)
{
    auto entry = _entryFactory(std::forward<Args>(args)...);
    _entries.push_back(entry);
    return entry;
}

#endif // CUBICSERVER_REGISTRY_HPP
