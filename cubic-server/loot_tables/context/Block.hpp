#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_BLOCK_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_BLOCK_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Entity;

namespace LootTable {
    namespace Context {
        class Block {
        public:
            Block(const int32_t &blockState, const FloatingPosition &origin, const ItemId &tool, const Entity *breaker, const int32_t *blockEntityData, const int32_t *explosionRadius);
            ~Block() = default;

            const std::string &getType() const;

            const int32_t &_blockState;
            const FloatingPosition &_origin;
            const ItemId &_tool;
            const Entity *_breaker;
            const int32_t *_blockEntityData;
            const int32_t *_explosionRadius;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONTEXT_BLOCK_HPP