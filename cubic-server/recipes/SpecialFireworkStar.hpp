#ifndef CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_HPP
#define CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialFireworkStar : public Recipe {
public:
    SpecialFireworkStar(const nlohmann::json &recipe);
    ~SpecialFireworkStar() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_HPP
