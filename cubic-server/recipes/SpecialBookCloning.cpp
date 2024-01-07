#include "SpecialBookCloning.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialBookCloning::SpecialBookCloning(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialBookCloning::dump(void) const { LTRACE("recipe special book cloning"); }

std::unique_ptr<Recipe> SpecialBookCloning::create(const nlohmann::json &recipe) { return (std::make_unique<SpecialBookCloning>(SpecialBookCloning(recipe))); }
} // namespace Recipe
