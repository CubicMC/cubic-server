#ifndef CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP
#define CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP

#include <list>
#include <memory>

#include <nlohmann/json.hpp>

#include "loot_tables/conditions/Condition.hpp"

#include "exceptions.hpp"

namespace LootTable {
class LootContext;
namespace Function {
/*
  function class to be overloaded,
  invalid by default
*/
class Function {
public:
    Function(const nlohmann::json &function);
    virtual ~Function() = default;

    // function must be validated, if not overloaded, call setValitity(true) to validate
    bool isValid(void) const noexcept;
    // setValitidy(true) will not set the validity to true if any condition is invalid
    virtual void setValidity(bool validity) noexcept;

    virtual void apply(const LootContext &context) = 0;

private:
    std::list<std::unique_ptr<Condition::Condition>> _conditions;
    bool _validity;
};

// type definition for creator, may return nullptr or a invalid entry
typedef std::unique_ptr<Function> (*Creator)(const nlohmann::json &function);

DEFINE_EXCEPTION(NoFunctionContructor);
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_FUNCTIONS_FUNCTION_HPP
