#include "MasterRegistry.hpp"
#include "logging/logging.hpp"
#include "nbt.hpp"
#include <memory>

using namespace registry;

MasterRegistry::MasterRegistry():
    _status(Status::Loading)
{}

MasterRegistry::Status MasterRegistry::status() const
{
    return _status;
}

void MasterRegistry::initialize()
{
    _nbt = std::accumulate(
        _registries.begin(), _registries.end(), NBT_MAKE(nbt::Compound, "", {}),
        [](std::shared_ptr<nbt::Base> &&acc, const auto &reg) -> decltype(acc)&& {
            acc->as<nbt::Compound>()->addValue(reg.second->toNBT());
            return std::move(acc);
        }
    )->as<nbt::Compound>();
    _status = Status::Initialized;
    LINFO("Master registry initialized with {} registries", _registries.size());
}

const std::shared_ptr<const nbt::Compound> MasterRegistry::toNBT() const
{
    if (_status != Status::Initialized)
        throw std::runtime_error("Master registry is not yet initialized");

    return _nbt;
}
