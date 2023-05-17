#ifndef CUBIC_SERVER_LOOT_TABLES_ENTRIES_ENTRY_HPP
#define CUBIC_SERVER_LOOT_TABLES_ENTRIES_ENTRY_HPP

#include <list>
#include <memory>
#include <exception>

#include <nlohmann/json.hpp>

namespace LootTable {
    class LootTablePoll;
    class LootContext;
    namespace Function {
        class Function;
    };
    namespace Condition {
        class Condition;
    };

    namespace Entry {
        class Entry {
        public:
            Entry(const nlohmann::json &entry);
            ~Entry() = default;

            bool isValid(void) const noexcept;
            void setValidity(bool validity) noexcept;

            const int64_t &getWeight(void) const noexcept;
            const int64_t &getQuality(void) const noexcept;

            void setWeight(int64_t weight) noexcept;
            void setQuality(int64_t quality) noexcept;
            
            virtual bool poll(LootTablePoll &poll, LootContext *context) const = 0;

        protected:
            int64_t _weight;
            int64_t _quality;
            std::list<std::unique_ptr<Function::Function>> _functions;
            std::list<std::unique_ptr<Condition::Condition>> _conditions;
            bool _validity;
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