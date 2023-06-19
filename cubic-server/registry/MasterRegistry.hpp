#ifndef CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP
#define CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP

#include "concept.hpp"
#include "nbt.hpp"
#include "registry/Registry.hpp"
#include <memory>
#include <numeric>

namespace registry {

/**
 * @brief Master registry.
 *
 * This class is used to store all registries.
 */
class MasterRegistry {
public:
    friend class ::Server;
    enum class Status {
        Loading,
        Initialized,
    };

public:
    explicit MasterRegistry();
    virtual ~MasterRegistry() = default;

    /**
     * @brief Add a registry to the master registry.
     *
     * This function call is valid only if the registry is not initialized.
     *
     * @throw std::runtime_error if the registry is already initialized.
     *
     * @tparam T Type of the registry.
     * @return T&
     */
    template<isBaseOf<registry::Registry> T>
    T &addRegistry();

    /**
     * @brief Convert the master registry to NBT.
     *
     * @return const std::shared_ptr<const nbt::Compound>
     */
    const std::shared_ptr<const nbt::Compound> toNBT() const;

    Status status() const;

private:
    void initialize();

private:
    std::vector<std::shared_ptr<Registry>> _registries;
    Status _status;
    std::shared_ptr<nbt::Compound> _nbt;
};

} // namespace registry

template<isBaseOf<registry::Registry> T>
T &registry::MasterRegistry::addRegistry()
{
    if (_status != Status::Loading)
        throw std::runtime_error("Master registry is already initialized");

    _registries.emplace_back(std::make_shared<T>());
    return dynamic_cast<T&>(*_registries.back());
}

#endif // CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP
