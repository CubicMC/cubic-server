#ifndef CUBICSERVER_REGISTRY_HPP
#define CUBICSERVER_REGISTRY_HPP

#include "concept.hpp"
#include "nbt.hpp"
#include <memory>
#include <numeric>
#include <string_view>
#include <vector>

class Server;

namespace registry {

class Entry {
public:
    explicit Entry() = default;
    virtual ~Entry() = default;

    virtual std::shared_ptr<nbt::Base> toNBT() const = 0;
    virtual bool operator==(const std::string &) const = 0;
};

/**
 * @brief Define a registry class.
 *
 * This class is used to store all entries of a registry.
 */
#define DEFINE_REGISTRY_CLASS(T, N)                                         \
    class T : public Registry {                                             \
    public:                                                                 \
        explicit T() = default;                                             \
        ~T() = default;                                                     \
                                                                            \
        std::string_view name() const override { return N; }                \
        static std::string_view staticName() { return N; }                  \
                                                                            \
        T##Element &addEntry() override                                     \
        {                                                                   \
            _entries.emplace_back(std::make_shared<T##Element>());          \
            return *std::dynamic_pointer_cast<T##Element>(_entries.back()); \
        }                                                                   \
    }

/**
 * @brief Base class for all registries.
 */
class Registry {
public:
    explicit Registry() = default;
    virtual ~Registry() = default;

    virtual std::string_view name() const = 0;
    virtual Entry &addEntry() = 0;

    std::shared_ptr<nbt::Base> toNBT() const;
    bool operator==(const std::string_view &name) const { return name == this->name(); }

protected:
    std::vector<std::shared_ptr<Entry>> _entries;
};

} // namespace regsitry

#endif // CUBICSERVER_REGISTRY_HPP
