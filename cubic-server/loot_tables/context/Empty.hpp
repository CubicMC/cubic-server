#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_EMPTY_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_EMPTY_HPP

#include <memory>

#include "LootContext.hpp"

namespace LootTable {
    namespace Context {
        class Empty {
        public:
            Empty() = default;
            ~Empty() = default;

            const std::string &getType() const;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONTEXT_EMPTY_HPP