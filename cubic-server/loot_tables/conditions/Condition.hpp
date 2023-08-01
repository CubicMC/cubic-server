#ifndef CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP
#define CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP

#include <memory>

#include <nlohmann/json.hpp>

#include "exceptions.hpp"

namespace LootTable {
class LootContext;

namespace Condition {
/*
  Condition class to be overloaded
  invalid by default
*/
class Condition {
public:
    Condition(void);
    virtual ~Condition() = default;

    // condition must be validated, if not overloaded, call setValitity(true) to validate
    bool isValid(void) const noexcept;
    virtual void setValidity(bool validity) noexcept;

    virtual bool verify(const LootContext *context) const;

private:
    bool _validity;
};

// type definition for creator, may return nullptr or a invalid entry
typedef std::unique_ptr<Condition> (*Creator)(const nlohmann::json &condition);

DEFINE_EXCEPTION(NoConditionContructor);
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_CONDITIONS_CONDITION_HPP
