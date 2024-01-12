#include "SpecialTippedArrow.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialTippedArrow::SpecialTippedArrow(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialTippedArrow::dump(void) const { LTRACE("recipe special tipped arrow"); }

std::shared_ptr<Recipe> SpecialTippedArrow::create(const nlohmann::json &recipe) { return (std::make_shared<SpecialTippedArrow>(SpecialTippedArrow(recipe))); }
} // namespace Recipe
