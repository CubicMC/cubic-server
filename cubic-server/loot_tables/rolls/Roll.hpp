#ifndef CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP
#define CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP

#include <cstdint>
#include <exception>
#include <memory>

#include <nlohmann/json.hpp>

#include "exceptions.hpp"

namespace LootTable {
class LootContext;
namespace Roll {
/*
  Roll result is the result of a roll
  it contains the number of rolls to be done and a probability(0=none;1=always) for each roll to be added
*/
struct RollResult {
    RollResult(int64_t nbr, double probability);
    ~RollResult() = default;

    int64_t nbr;
    double probability;
};

/*
  Roll class to inherit,
  invalid by default
*/
class Roll {
public:
    Roll(void);
    virtual ~Roll() = default;

    // roll must be valid, call setValidity(true) to validate
    bool isValid(void) const noexcept;
    void setValidity(bool validity) noexcept;

    virtual const RollResult poll(LootContext *context) const = 0;

private:
    bool _validity;
};

/*
  types definitions for creators and types checker
  if isOfType(rollJson) returns true, creator(rollJSON) will be called
*/
typedef std::unique_ptr<Roll> (*Creator)(const nlohmann::json &roll);
typedef bool (*IsOfType)(const nlohmann::json &roll);

DEFINE_EXCEPTION(NoRollConstructor);
};
};

#endif // CUBIC_SERVER_LOOT_TABLES_ROOLS_ROLL_HPP
