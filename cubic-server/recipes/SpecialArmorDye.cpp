#include "SpecialArmorDye.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialArmorDye::SpecialArmorDye(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialArmorDye::dump(void) const
    {
        LINFO("recipe special armor dye");
    }

    std::unique_ptr<Recipe> SpecialArmorDye::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialArmorDye>(SpecialArmorDye(recipe)));
    }
};