#include "SpecialRepairItem.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialRepairItem::SpecialRepairItem(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialRepairItem::dump(void) const { LTRACE("recipe special repair item"); }

std::unique_ptr<Recipe> SpecialRepairItem::create(const nlohmann::json &recipe) { return (std::make_unique<SpecialRepairItem>(SpecialRepairItem(recipe))); }
} // namespace Recipe
