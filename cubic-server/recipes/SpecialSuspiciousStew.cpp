#include "SpecialSuspiciousStew.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialSuspiciousStew::SpecialSuspiciousStew(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialSuspiciousStew::dump(void) const { LINFO("recipe special suspicious stew"); }

std::unique_ptr<Recipe> SpecialSuspiciousStew::create(const nlohmann::json &recipe) { return (std::make_unique<SpecialSuspiciousStew>(SpecialSuspiciousStew(recipe))); }
};