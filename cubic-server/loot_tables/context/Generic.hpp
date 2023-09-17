#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_GENERIC_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_GENERIC_HPP

#include <memory>

#include "LootContext.hpp"

namespace LootTable {
namespace Context {
class Generic : public LootContext {
public:
    Generic();
    ~Generic() = default;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_CONTEXT_GENERIC_HPP
