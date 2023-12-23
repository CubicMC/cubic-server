#include "WeatherCheck.hpp"

namespace LootTable {
namespace Condition {
WeatherCheck::WeatherCheck(const nlohmann::json &condition)
{
    (void) condition;

    this->setValidity(true);
}

bool WeatherCheck::verify(const LootContext *context) const
{
    (void) context;
    return (true);
}

std::unique_ptr<Condition> WeatherCheck::create(const nlohmann::json &condition) { return (std::make_unique<WeatherCheck>(condition)); }
};
};
