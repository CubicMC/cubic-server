#include "SpecialArmorDye.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialArmorDye::SpecialArmorDye(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialArmorDye::dump(void) const { LINFO("recipe special armor dye"); }

std::unique_ptr<Recipe> SpecialArmorDye::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_unique<SpecialArmorDye>(SpecialArmorDye(identifier, recipe)));
}
} // namespace Recipe
