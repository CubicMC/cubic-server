#ifndef CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_HPP
#define CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialFireworkStar : public Recipe {
public:
    SpecialFireworkStar(const std::string &identifier, const nlohmann::json &recipe);
    ~SpecialFireworkStar() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_FIREWORK_STAR_HPP
