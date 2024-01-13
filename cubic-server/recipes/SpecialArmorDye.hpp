#ifndef CUBICSERVER_RECIPES_SPECIAL_ARMOR_DYE_HPP
#define CUBICSERVER_RECIPES_SPECIAL_ARMOR_DYE_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialArmorDye : public Recipe {
public:
    SpecialArmorDye(const std::string &identifier, const nlohmann::json &recipe);
    ~SpecialArmorDye() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_ARMOR_DYE_HPP
