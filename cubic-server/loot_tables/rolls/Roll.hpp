#ifndef CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP
#define CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP

#include <cstdint>
#include <memory>
#include <exception>

#include <nlohmann/json.hpp>

#include "exceptions.hpp"

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
            Roll(void);
            ~Roll() = default;
            bool isValid(void) const noexcept;
            void setValidity(bool validity) noexcept;

            virtual const RollResult poll(LootContext *context) const = 0;
        private:
            bool _validity;
        };

        typedef std::unique_ptr<Roll> (*Creator)(const nlohmann::json &roll);
        typedef bool (*IsOfType)(const nlohmann::json &roll);

        DEFINE_EXCEPTION(NoRollConstructor);
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP