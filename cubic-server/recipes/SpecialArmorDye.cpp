#include "SpecialArmorDye.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialArmorDye::SpecialArmorDye(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialArmorDye::dump(void) const { LTRACE("recipe special armor dye"); }

std::shared_ptr<Recipe> SpecialArmorDye::create(const nlohmann::json &recipe) { return (std::make_shared<SpecialArmorDye>(SpecialArmorDye(recipe))); }
} // namespace Recipe
