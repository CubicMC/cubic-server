#ifndef CUBICSERVER_RECIPES_SPECIAL_SHULKERBOX_COLORING_HPP
#define CUBICSERVER_RECIPES_SPECIAL_SHULKERBOX_COLORING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialShulkerboxColoring : public Recipe {
public:
    SpecialShulkerboxColoring(const nlohmann::json &recipe);
    ~SpecialShulkerboxColoring() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_SHULKERBOX_COLORING_HPP
