#include "SpecialShulkerboxColoring.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialShulkerboxColoring::SpecialShulkerboxColoring(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialShulkerboxColoring::dump(void) const { LTRACE("recipe special shulkerbox coloring"); }

std::shared_ptr<Recipe> SpecialShulkerboxColoring::create(const nlohmann::json &recipe) { return (std::make_shared<SpecialShulkerboxColoring>(SpecialShulkerboxColoring(recipe))); }
} // namespace Recipe
