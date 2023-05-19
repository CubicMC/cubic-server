#include "SpecialBookCloning.hpp"

#include "Server.hpp"

namespace Recipe {
    SpecialBookCloning::SpecialBookCloning(const nlohmann::json &recipe):
        Recipe(recipe)
    {
        this->setValidity(false);
    }

    void SpecialBookCloning::dump(void) const
    {
        LINFO("recipe special suspicious stew");
    }

    std::unique_ptr<Recipe> SpecialBookCloning::create(const nlohmann::json &recipe)
    {
        return (std::make_unique<SpecialBookCloning>(SpecialBookCloning(recipe)));
    }
};