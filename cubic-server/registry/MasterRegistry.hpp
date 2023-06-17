#ifndef CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP
#define CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP

#include "concept.hpp"
#include "nbt.hpp"
#include "registry/Registry.hpp"
#include <memory>
#include <numeric>

namespace registry {

// template<typename T>
// concept isRegistry =
//     requires {
//         T::EntryType;
//     } && isBaseOf<typename T::EntryType, Entry> && isBaseOf<T, Registry<typename T::EntryType>>;

/**
 * @brief Master registry.
 *
 * This class is used to store all registries.
 */
class MasterRegistry {
public:
    friend class Server;
    enum class Status {
        Loading,
        Initialized,
    };

public:
    explicit MasterRegistry();
    virtual ~MasterRegistry();

    /**
     * @brief Add a registry to the master registry.
     *
     * This function call is valid only if the registry is not initialized.
     *
     * @throw std::runtime_error if the registry is initialized.
     *
     * @tparam RegEntry
     * @tparam T
     * @return T&
     */
    template<isBaseOf<Entry> T, const char *name>
    Registry &addRegistry();

    /**
     * @brief Get the Registry object
     *
     * This function call is valid only if the registry is initialized.
     *
     * @throw std::runtime_error if the registry is not initialized.
     *
     * @return std::shared_ptr<nbt::Compound>
     */
    std::shared_ptr<nbt::Compound> toNBT() const;

    Status getStatus() const;

private:
    void setStatus(Status status);

private:
    std::vector<Registry> _registries;
    Status _status;
};

} // namespace registry

template<isBaseOf<registry::Entry> T, const char *name>
registry::Registry &registry::MasterRegistry::addRegistry()
{
    if (_status != Status::Loading)
        throw std::runtime_error("Master registry is already initialized");

    _registries.emplace_back(Registry(std::string_view(name)));
    return _registries.back();
}

#endif // CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP
