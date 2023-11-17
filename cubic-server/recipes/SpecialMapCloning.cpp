#include "SpecialMapCloning.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialMapCloning::SpecialMapCloning(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialMapCloning::dump(void) const { LINFO("recipe special map cloning"); }

std::unique_ptr<Recipe> SpecialMapCloning::create(const std::string &identifier, const nlohmann::json &recipe) { return (std::make_unique<SpecialMapCloning>(SpecialMapCloning(identifier, recipe))); }
} // namespace Recipe
