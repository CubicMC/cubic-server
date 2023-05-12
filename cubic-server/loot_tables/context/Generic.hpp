#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_GENERIC_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_GENERIC_HPP

#include <memory>

#include "LootContext.hpp"

namespace LootTable {
    namespace Context {
        class Generic {
        public:
            Generic() = default;
            ~Generic() = default;

            const std::string &getType() const;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONTEXT_GENERIC_HPP