#ifndef CUBICSERVER_RECIPES_SPECIAL_TIPPED_ARROW_HPP
#define CUBICSERVER_RECIPES_SPECIAL_TIPPED_ARROW_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialTippedArrow : public Recipe {
public:
    SpecialTippedArrow(const nlohmann::json &recipe);
    ~SpecialTippedArrow() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_TIPPED_ARROW_HPP
