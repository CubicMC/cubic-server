#ifndef CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP
#define CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP

#include <cstdint>
#include <memory>
#include <exception>

#include <nlohmann/json.hpp>

namespace LootTable {
    class LootContext;
    namespace Roll {
        struct RollResult {
            RollResult(int64_t nbr, double probability);
            ~RollResult() = default;

            int64_t _nbr;
            double _probability;
        };

        class Roll {
        public:
            virtual const RollResult poll(LootContext *context) const = 0;
        };

        typedef std::unique_ptr<Roll> (*Creator)(const nlohmann::json &roll);
        typedef bool (*IsOfType)(const nlohmann::json &roll);

        class NoRollContructor : public std::exception {
        public:
            NoRollContructor(const nlohmann::json &roll);
            ~NoRollContructor() = default;

            const char *what() const noexcept;
        private:
            const std::string _message;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP