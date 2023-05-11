#include "WeatherCheck.hpp"

namespace LootTable {
    namespace Condition {
        WeatherCheck::WeatherCheck(const nlohmann::json &condition)
        {
            (void)condition;
        }

        bool WeatherCheck::verify(void)
        {
            return (true);
        }

        std::unique_ptr<Condition> WeatherCheck::create(const nlohmann::json &condition)
        {
            return (std::make_unique<WeatherCheck>(condition));
        }
    };
};