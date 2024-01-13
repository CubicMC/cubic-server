#include "SpecialFireworkRocket.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialFireworkRocket::SpecialFireworkRocket(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialFireworkRocket::dump(void) const { LTRACE("recipe special firework rocket"); }

std::shared_ptr<Recipe> SpecialFireworkRocket::create(const nlohmann::json &recipe) { return (std::make_shared<SpecialFireworkRocket>(SpecialFireworkRocket(recipe))); }
} // namespace Recipe
