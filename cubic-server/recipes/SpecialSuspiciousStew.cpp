#include "SpecialSuspiciousStew.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialSuspiciousStew::SpecialSuspiciousStew(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialSuspiciousStew::dump(void) const { LINFO("recipe special suspicious stew"); }

std::unique_ptr<Recipe> SpecialSuspiciousStew::create(const std::string &identifier, const nlohmann::json &recipe) { return (std::make_unique<SpecialSuspiciousStew>(SpecialSuspiciousStew(identifier, recipe))); }
} // namespace Recipe
