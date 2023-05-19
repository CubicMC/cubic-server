#include "SpecialTippedArrow.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialTippedArrow::SpecialTippedArrow(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialTippedArrow::dump(void) const
    {
        LINFO("recipe special tipped arrow");
    }

    std::unique_ptr<Recipe> SpecialTippedArrow::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialTippedArrow>(SpecialTippedArrow(recipe)));
    }
};