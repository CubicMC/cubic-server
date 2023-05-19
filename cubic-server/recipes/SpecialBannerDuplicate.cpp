#include "SpecialBannerDuplicate.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialBannerDuplicate::SpecialBannerDuplicate(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialBannerDuplicate::dump(void) const
    {
        LINFO("recipe special suspicious stew");
    }

    std::unique_ptr<Recipe> SpecialBannerDuplicate::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialBannerDuplicate>(SpecialBannerDuplicate(recipe)));
    }
};