#include "SpecialBannerDuplicate.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialBannerDuplicate::SpecialBannerDuplicate(const std::string &identifier, const nlohmann::json &recipe):
    Recipe(identifier, recipe)
{
    this->setValidity(false);
}

void SpecialBannerDuplicate::dump(void) const { LINFO("recipe special banner duplicate"); }

std::unique_ptr<Recipe> SpecialBannerDuplicate::create(const std::string &identifier, const nlohmann::json &recipe) { return (std::make_unique<SpecialBannerDuplicate>(SpecialBannerDuplicate(identifier, recipe))); }
} // namespace Recipe
