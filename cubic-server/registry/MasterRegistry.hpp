#ifndef CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP
#define CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP

#include "concept.hpp"
#include "logging/logging.hpp"
#include "nbt.hpp"
#include "registry/Registry.hpp"
#include <memory>
#include <numeric>
#include <unordered_map>

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
     * @brief Get the Registry object
     *
     * @throw std::out_of_range if the registry is not found.
     *
     * @tparam T Registry type.
     * @return T&
     */
    template<isBaseOf<registry::Registry> T>
    T &getRegistry() const;

    /**
     * @brief Convert the master registry to NBT.
     *
     * @throw std::runtime_error if the registry is not initialized.
     *
     * @return const std::shared_ptr<const nbt::Compound>
     */
    const std::shared_ptr<const nbt::Compound> toNBT() const;

    Status status() const { return _status; }

private:
    void initialize();

private:
    std::unordered_map<std::string_view, std::shared_ptr<Registry>> _registries;
    Status _status;
    std::shared_ptr<nbt::Compound> _nbt;
};

} // namespace registry

template<isBaseOf<registry::Registry> T>
T &registry::MasterRegistry::addRegistry()
{
    if (_status != Status::Loading)
        throw std::runtime_error("Master registry is already initialized");

    if (_registries.contains(T::staticName())) {
        LWARN("Registry {} is already registered", T::staticName());
        return dynamic_cast<T &>(*_registries.at(T::staticName()));
    }

    _registries.emplace(T::staticName(), std::make_shared<T>());
    return dynamic_cast<T &>(*_registries.at(T::staticName()));
}

template<isBaseOf<registry::Registry> T>
T &registry::MasterRegistry::getRegistry() const
{
    return dynamic_cast<T &>(*_registries.at(T::staticName()));
}

#endif // CUBICSERVER_REGISTRY_MASTER_REGISTRY_HPP
