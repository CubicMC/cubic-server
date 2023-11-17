#include "SpecialBookCloning.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialBookCloning::SpecialBookCloning(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialBookCloning::dump(void) const { LINFO("recipe special book cloning"); }

std::unique_ptr<Recipe> SpecialBookCloning::create(const std::string &identifier, const nlohmann::json &recipe) { return (std::make_unique<SpecialBookCloning>(SpecialBookCloning(identifier, recipe))); }
} // namespace Recipe
