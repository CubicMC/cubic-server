#include "Registry.hpp"
#include "logging/logging.hpp"
#include "nbt.hpp"

std::shared_ptr<nbt::Base> registry::Registry::toNBT() const
{
    LINFO("Generating NBT for registry {} with {}", name(), _entries.size());
    // clang-format off
    return NBT_MAKE(nbt::Compound, std::string(name()), {
        NBT_MAKE(nbt::String, "type", std::string(name())),
        std::accumulate(
            _entries.begin(), _entries.end(), NBT_MAKE_AS(nbt::List, "value", {}),
            [](auto &&acc, const auto &entry) -> decltype(acc)&& {
                acc->push_back(entry->toNBT());
                return std::move(acc);
            }
        )
    });
    // clang-format on
}
