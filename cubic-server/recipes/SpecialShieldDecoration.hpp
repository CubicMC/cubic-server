#ifndef CUBICSERVER_RECIPES_SPECIAL_SHIELD_DECORATION_HPP
#define CUBICSERVER_RECIPES_SPECIAL_SHIELD_DECORATION_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialShieldDecoration : public Recipe {
public:
    SpecialShieldDecoration(const std::string &identifier, const nlohmann::json &recipe);
    ~SpecialShieldDecoration() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_SHIELD_DECORATION_HPP
