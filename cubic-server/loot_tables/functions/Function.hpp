#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP

#include <list>
#include <memory>

#include <nlohmann/json.hpp>

#include "loot_tables/conditions/Condition.hpp"

#include "exceptions.hpp"

namespace LootTable {
    namespace Function {
        class Function {
        public:
            Function(const nlohmann::json &function);
            ~Function() = default;

            bool isValid(void) const noexcept;
            virtual void setValidity(bool validity) noexcept;

            virtual void apply(void) = 0;

        private:
            std::list<std::unique_ptr<Condition::Condition>> _conditions;
            bool _validity;
        };

        typedef std::unique_ptr<Function> (*Creator)(const nlohmann::json &function);

        DEFINE_EXCEPTION(NoFunctionContructor);
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP