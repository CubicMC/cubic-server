#ifndef CUBIC_SERVER_LOOT_TABLES_CONTEXT_COMMAND_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONTEXT_COMMAND_HPP

#include <memory>

#include "types.hpp"

#include "LootContext.hpp"

class Entity;

namespace LootTable {
    namespace Context {
        class Command {
        public:
            Command(const FloatingPosition &origin, const Entity *entity);
            ~Command();

            const std::string &getType() const;

            static std::unique_ptr<LootContext> create(void);
            
            const FloatingPosition &_origin;
            const Entity *_entity;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONTEXT_COMMAND_HPP