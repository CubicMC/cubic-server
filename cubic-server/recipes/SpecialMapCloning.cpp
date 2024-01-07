#include "SpecialMapCloning.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialMapCloning::SpecialMapCloning(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialMapCloning::dump(void) const { LTRACE("recipe special map cloning"); }

std::unique_ptr<Recipe> SpecialMapCloning::create(const nlohmann::json &recipe) { return (std::make_unique<SpecialMapCloning>(SpecialMapCloning(recipe))); }
} // namespace Recipe
