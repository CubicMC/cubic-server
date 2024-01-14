#ifndef CUBICSERVER_RECIPES_SPECIAL_MAP_EXTENDING_HPP
#define CUBICSERVER_RECIPES_SPECIAL_MAP_EXTENDING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialMapExtending : public Recipe {
public:
    SpecialMapExtending(const std::string &identifier, const nlohmann::json &recipe);
    ~SpecialMapExtending() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_MAP_EXTENDING_HPP
