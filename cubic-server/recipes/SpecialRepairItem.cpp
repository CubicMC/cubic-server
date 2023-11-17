#include "SpecialRepairItem.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialRepairItem::SpecialRepairItem(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialRepairItem::dump(void) const { LINFO("recipe special repair item"); }

std::unique_ptr<Recipe> SpecialRepairItem::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_unique<SpecialRepairItem>(SpecialRepairItem(identifier, recipe)));
}
} // namespace Recipe
