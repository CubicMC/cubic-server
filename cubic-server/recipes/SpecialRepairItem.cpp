#include "SpecialRepairItem.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialRepairItem::SpecialRepairItem(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialRepairItem::dump(void) const { LTRACE("recipe special repair item"); }

std::shared_ptr<Recipe> SpecialRepairItem::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<SpecialRepairItem>(SpecialRepairItem(identifier, recipe)));
}
} // namespace Recipe
