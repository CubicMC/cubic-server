#ifndef CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP

#include <memory>

#include <nlohmann/json.hpp>

#include "exceptions.hpp"

namespace LootTable {
    namespace Condition {
        class Condition {
        public:
            Condition(void);
            ~Condition() = default;

            bool isValid(void) const noexcept;
            virtual void setValidity(bool validity) noexcept;

            virtual bool verify(void) const;

        private:
            bool _validity;
        };

        typedef std::unique_ptr<Condition> (*Creator)(const nlohmann::json &condition);

        DEFINE_EXCEPTION(NoConditionContructor);
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP