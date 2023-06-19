#include "Registry.hpp"
#include "logging/logging.hpp"
#include "nbt.hpp"

std::shared_ptr<nbt::Base> registry::Registry::toNBT() const
{
    LINFO("Generating NBT for registry {} with {}", name(), _entries.size());
    return NBT_MAKE(nbt::Compound, std::string(name()), {
        NBT_MAKE(nbt::String, "type", std::string(name())),
        std::accumulate(
            _entries.begin(), _entries.end(), NBT_MAKE(nbt::List, "value", {}),
            [](std::shared_ptr<nbt::Base> &&acc, const auto &entry) -> decltype(acc)&& {
                acc->as<nbt::List>()->push_back(entry->toNBT());
                return std::move(acc);
            }
        )
    });
}
