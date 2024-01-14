#include "SpecialMapExtending.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialMapExtending::SpecialMapExtending(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialMapExtending::dump(void) const { LTRACE("recipe special map extending"); }

std::shared_ptr<Recipe> SpecialMapExtending::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<SpecialMapExtending>(SpecialMapExtending(identifier, recipe)));
}
} // namespace Recipe
