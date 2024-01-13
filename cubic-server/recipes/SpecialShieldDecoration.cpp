#include "SpecialShieldDecoration.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialShieldDecoration::SpecialShieldDecoration(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialShieldDecoration::dump(void) const { LTRACE("recipe special shield decoration"); }

std::shared_ptr<Recipe> SpecialShieldDecoration::create(const nlohmann::json &recipe) { return (std::make_shared<SpecialShieldDecoration>(SpecialShieldDecoration(recipe))); }
} // namespace Recipe
