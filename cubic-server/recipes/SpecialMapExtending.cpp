#include "SpecialMapExtending.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialMapExtending::SpecialMapExtending(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialMapExtending::dump(void) const { LINFO("recipe special map extending"); }

std::unique_ptr<Recipe> SpecialMapExtending::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_unique<SpecialMapExtending>(SpecialMapExtending(identifier, recipe)));
}
} // namespace Recipe
