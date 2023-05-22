#ifndef CUBICSERVER_RECIPES_SPECIAL_BANNER_DUPLICATE_HPP
#define CUBICSERVER_RECIPES_SPECIAL_BANNER_DUPLICATE_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialBannerDuplicate : public Recipe {
public:
    SpecialBannerDuplicate(const nlohmann::json &recipe);
    ~SpecialBannerDuplicate() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_BANNER_DUPLICATE_HPP
