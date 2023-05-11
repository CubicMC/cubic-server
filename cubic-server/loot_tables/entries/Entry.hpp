#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_ENTRY_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_ENTRY_HPP

#include <list>
#include <memory>
#include <exception>

#include <nlohmann/json.hpp>

#include "loot_tables/functions/Function.hpp"
#include "loot_tables/conditions/Condition.hpp"

namespace LootTable {
    class LootTablePoll;

    namespace Entry {
        class Entry {
        public:
            Entry(const nlohmann::json &entry);
            ~Entry() = default;

            const int32_t &getWeight(void) const noexcept;
            const int32_t &getQuality(void) const noexcept;

            void setWeight(int32_t weight) noexcept;
            void setQuality(int32_t quality) noexcept;
            
            virtual bool poll(LootTablePoll &poll) = 0;

        protected:
            int32_t _weight;
            int32_t _quality;
            std::list<std::unique_ptr<Function::Function>> _functions;
            std::list<std::unique_ptr<Condition::Condition>> _conditions;
        };

        typedef std::unique_ptr<Entry> (*Creator)(const nlohmann::json &entry);
    
        class NoEntryContructor : public std::exception {
        public:
            NoEntryContructor(const nlohmann::json &roll);
            ~NoEntryContructor() = default;

            const char *what() const noexcept;
        private:
            const std::string _message;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_ENTRIES_ENTRY_HPP