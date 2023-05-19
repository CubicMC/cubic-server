#include "SpecialRepairItem.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialRepairItem::SpecialRepairItem(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialRepairItem::dump(void) const
    {
        LINFO("recipe special suspicious stew");
    }

    std::unique_ptr<Recipe> SpecialRepairItem::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialRepairItem>(SpecialRepairItem(recipe)));
    }
};