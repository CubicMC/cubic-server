#include "SpecialShieldDecoration.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialShieldDecoration::SpecialShieldDecoration(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialShieldDecoration::dump(void) const { LTRACE("recipe special shield decoration"); }

std::shared_ptr<Recipe> SpecialShieldDecoration::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<SpecialShieldDecoration>(SpecialShieldDecoration(identifier, recipe)));
}
} // namespace Recipe
