#ifndef CUBICSERVER_RECIPES_SPECIAL_SHIELD_DECORATION_HPP
#define CUBICSERVER_RECIPES_SPECIAL_SHIELD_DECORATION_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialShieldDecoration : public Recipe {
public:
    SpecialShieldDecoration(const nlohmann::json &recipe);
    ~SpecialShieldDecoration() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_SHIELD_DECORATION_HPP
