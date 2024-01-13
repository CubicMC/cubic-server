#include "SpecialBookCloning.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialBookCloning::SpecialBookCloning(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialBookCloning::dump(void) const { LTRACE("recipe special book cloning"); }

std::shared_ptr<Recipe> SpecialBookCloning::create(const std::string &identifier, const nlohmann::json &recipe)
{
    return (std::make_shared<SpecialBookCloning>(SpecialBookCloning(identifier, recipe)));
}
} // namespace Recipe
