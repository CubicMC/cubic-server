#ifndef CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_FADE_HPP
#define CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_FADE_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialFireworkStarFade : public Recipe {
public:
    SpecialFireworkStarFade(const nlohmann::json &recipe);
    ~SpecialFireworkStarFade() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_FADE_HPP
