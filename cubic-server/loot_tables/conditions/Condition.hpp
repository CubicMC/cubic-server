#ifndef CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP

#include <memory>
#include <exception>

#include <nlohmann/json.hpp>

namespace LootTable {
    namespace Condition {
        class Condition {
        public:
            Condition() = default;
            ~Condition() = default;

            virtual bool verify(void) const;
        };

        typedef std::unique_ptr<Condition> (*Creator)(const nlohmann::json &condition);

        class NoConditionContructor : public std::exception {
        public:
            NoConditionContructor(const nlohmann::json &roll);
            ~NoConditionContructor() = default;

            const char *what() const noexcept;
        private:
            const std::string _message;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP