#include "SpecialMapCloning.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialMapCloning::SpecialMapCloning(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialMapCloning::dump(void) const
    {
        LINFO("recipe special suspicious stew");
    }

    std::unique_ptr<Recipe> SpecialMapCloning::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialMapCloning>(SpecialMapCloning(recipe)));
    }
};