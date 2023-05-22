#ifndef CUBICSERVER_RECIPES_SPECIAL_FIREWORK_ROCKET_HPP
#define CUBICSERVER_RECIPES_SPECIAL_FIREWORK_ROCKET_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialFireworkRocket : public Recipe {
public:
    SpecialFireworkRocket(const nlohmann::json &recipe);
    ~SpecialFireworkRocket() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_FIREWORK_ROCKET_HPP
