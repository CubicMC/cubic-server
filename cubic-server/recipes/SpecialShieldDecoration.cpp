#include "SpecialShieldDecoration.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialShieldDecoration::SpecialShieldDecoration(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialShieldDecoration::dump(void) const { LINFO("recipe special shield decoration"); }

std::unique_ptr<Recipe> SpecialShieldDecoration::create(const nlohmann::json &recipe) { return (std::make_unique<SpecialShieldDecoration>(SpecialShieldDecoration(recipe))); }
};