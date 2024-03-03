#ifndef CUBICSERVER_RECIPES_SPECIAL_BANNER_DUPLICATE_HPP
#define CUBICSERVER_RECIPES_SPECIAL_BANNER_DUPLICATE_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialBannerDuplicate : public Recipe {
public:
    SpecialBannerDuplicate(const std::string &identifier, const nlohmann::json &recipe);
    ~SpecialBannerDuplicate() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);
};
}; // namespace Recipe

#endif // CUBICSERVER_RECIPES_SPECIAL_BANNER_DUPLICATE_HPP
