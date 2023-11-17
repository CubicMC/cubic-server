#include "SpecialFireworkStarFade.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialFireworkStarFade::SpecialFireworkStarFade(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialFireworkStarFade::dump(void) const { LINFO("recipe special firework star fade"); }

std::unique_ptr<Recipe> SpecialFireworkStarFade::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_unique<SpecialFireworkStarFade>(SpecialFireworkStarFade(identifier, recipe)));
}
} // namespace Recipe
