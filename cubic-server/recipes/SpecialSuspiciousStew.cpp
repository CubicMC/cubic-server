#include "SpecialSuspiciousStew.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialSuspiciousStew::SpecialSuspiciousStew(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialSuspiciousStew::dump(void) const { LTRACE("recipe special suspicious stew"); }

std::unique_ptr<Recipe> SpecialSuspiciousStew::create(const nlohmann::json &recipe) { return (std::make_unique<SpecialSuspiciousStew>(SpecialSuspiciousStew(recipe))); }
} // namespace Recipe
