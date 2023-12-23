#include "MasterRegistry.hpp"
#include "logging/logging.hpp"
#include "nbt.hpp"
#include <memory>

using namespace registry;

MasterRegistry::MasterRegistry():
    _status(Status::Loading)
{
}

void MasterRegistry::initialize()
{
    // clang-format off
    _nbt = std::accumulate(
        _registries.begin(), _registries.end(), NBT_MAKE_AS(nbt::Compound, "", {}),
        [](std::shared_ptr<nbt::Compound> &&acc, const auto &reg) -> decltype(acc)&& {
            acc->addValue(reg.second->toNBT());
            return std::move(acc);
        }
    );
    // clang-format on
    _status = Status::Initialized;
    LINFO("Master registry initialized with {} registries", _registries.size());
}

const std::shared_ptr<const nbt::Compound> MasterRegistry::toNBT() const
{
    if (_status != Status::Initialized)
        throw std::runtime_error("Master registry is not yet initialized");

    return _nbt;
}
