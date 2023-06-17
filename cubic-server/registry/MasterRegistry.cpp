#include "MasterRegistry.hpp"

using namespace registry;

MasterRegistry::MasterRegistry():
    _status(Status::Loading)
{}

MasterRegistry::~MasterRegistry()
{}

MasterRegistry::Status MasterRegistry::getStatus() const
{
    return _status;
}

void MasterRegistry::setStatus(Status status)
{
    _status = status;
}

std::shared_ptr<nbt::Compound> MasterRegistry::toNBT() const
{
    if (_status != Status::Initialized)
        throw std::runtime_error("Master registry is not yet initialized");

    static auto nbt = std::accumulate(
        _registries.begin(), _registries.end(), std::make_shared<nbt::Compound>(new nbt::Compound("", {})),
        [](auto &&acc, const auto &reg) {
            acc->addValue(reg.toNBT());
            return std::move(acc);
        }
    );

    return nbt;
}
