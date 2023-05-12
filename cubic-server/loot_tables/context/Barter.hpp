#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_BARTER_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_BARTER_HPP

#include <memory>

#include "LootContext.hpp"

namespace LootTable {
    namespace Context {
        class Barter {
        public:
            Barter(const Entity &barterer);
            ~Barter() = default;

            const std::string &getType() const;

            const Entity &_barterer;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONTEXT_BARTER_HPP