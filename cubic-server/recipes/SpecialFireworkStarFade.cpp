#include "SpecialFireworkStarFade.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialFireworkStarFade::SpecialFireworkStarFade(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialFireworkStarFade::dump(void) const
    {
        LINFO("recipe special suspicious stew");
    }

    std::unique_ptr<Recipe> SpecialFireworkStarFade::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialFireworkStarFade>(SpecialFireworkStarFade(recipe)));
    }
};