#include "SpecialFireworkStarFade.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialFireworkStarFade::SpecialFireworkStarFade(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialFireworkStarFade::dump(void) const { LTRACE("recipe special firework star fade"); }

std::shared_ptr<Recipe> SpecialFireworkStarFade::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<SpecialFireworkStarFade>(SpecialFireworkStarFade(identifier, recipe)));
}
} // namespace Recipe
