#include "SpecialMapCloning.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialMapCloning::SpecialMapCloning(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialMapCloning::dump(void) const { LTRACE("recipe special map cloning"); }

std::shared_ptr<Recipe> SpecialMapCloning::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<SpecialMapCloning>(SpecialMapCloning(identifier, recipe)));
}
} // namespace Recipe
