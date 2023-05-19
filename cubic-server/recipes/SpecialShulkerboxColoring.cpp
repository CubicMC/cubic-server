#include "SpecialShulkerboxColoring.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialShulkerboxColoring::SpecialShulkerboxColoring(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialShulkerboxColoring::dump(void) const
    {
        LINFO("recipe special suspicious stew");
    }

    std::unique_ptr<Recipe> SpecialShulkerboxColoring::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialShulkerboxColoring>(SpecialShulkerboxColoring(recipe)));
    }
};