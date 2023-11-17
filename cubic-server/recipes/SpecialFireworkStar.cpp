#include "SpecialFireworkStar.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialFireworkStar::SpecialFireworkStar(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialFireworkStar::dump(void) const { LINFO("recipe special firework star"); }

std::unique_ptr<Recipe> SpecialFireworkStar::create(const std::string &identifier, const nlohmann::json &recipe) { return (std::make_unique<SpecialFireworkStar>(SpecialFireworkStar(identifier, recipe))); }
} // namespace Recipe
