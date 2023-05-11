#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP

#include <list>
#include <memory>
#include <exception>

#include <nlohmann/json.hpp>

#include "loot_tables/conditions/Condition.hpp"

namespace LootTable {
    namespace Function {
        class Function {
        public:
            Function(const nlohmann::json &function);
            ~Function() = default;

            virtual void apply(void) = 0;

        protected:
            std::list<std::unique_ptr<Condition::Condition>> _conditions;
        };

        typedef std::unique_ptr<Function> (*Creator)(const nlohmann::json &function);

        class NoFunctionContructor : public std::exception {
        public:
            NoFunctionContructor(const nlohmann::json &roll);
            ~NoFunctionContructor() = default;

            const char *what() const noexcept;

        private:
            const std::string _message;
        };
    };
};

#endif //CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP