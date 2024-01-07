#include "SpecialBannerDuplicate.hpp"
#include "logging/logging.hpp"

#include "Server.hpp"

namespace Recipe {
SpecialBannerDuplicate::SpecialBannerDuplicate(const nlohmann::json &recipe):
    Recipe(recipe)
{
    this->setValidity(false);
}

void SpecialBannerDuplicate::dump(void) const { LTRACE("recipe special banner duplicate"); }

std::unique_ptr<Recipe> SpecialBannerDuplicate::create(const nlohmann::json &recipe) { return (std::make_unique<SpecialBannerDuplicate>(SpecialBannerDuplicate(recipe))); }
} // namespace Recipe
