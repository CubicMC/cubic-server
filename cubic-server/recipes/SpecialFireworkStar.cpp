#include "SpecialFireworkStar.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialFireworkStar::SpecialFireworkStar(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialFireworkStar::dump(void) const { LTRACE("recipe special firework star"); }

std::unique_ptr<Recipe> SpecialFireworkStar::create(const nlohmann::json &recipe) { return (std::make_unique<SpecialFireworkStar>(SpecialFireworkStar(recipe))); }
} // namespace Recipe
