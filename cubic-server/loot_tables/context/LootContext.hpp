#ifndef CUBIC_SERVER_LOOT_TABLES_LOOT_CONTEXT_HPP
#define CUBIC_SERVER_LOOT_TABLES_LOOT_CONTEXT_HPP

#include <string>

namespace LootTable {
namespace Context {
class LootContext {
public:
    LootContext(const std::string &type);
    ~LootContext() = default;

    const std::string &getType() const noexcept;

private:
    const std::string _type;
};
}
}

#endif // CUBIC_SERVER_LOOT_TABLES_LOOT_CONTEXT_HPP
