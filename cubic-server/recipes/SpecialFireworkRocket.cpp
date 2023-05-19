#include "SpecialFireworkRocket.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialFireworkRocket::SpecialFireworkRocket(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialFireworkRocket::dump(void) const
    {
        LINFO("recipe special suspicious stew");
    }

    std::unique_ptr<Recipe> SpecialFireworkRocket::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialFireworkRocket>(SpecialFireworkRocket(recipe)));
    }
};