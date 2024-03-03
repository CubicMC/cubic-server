#ifndef CUBICSERVER_RECIPES_CAMPFIRE_COOKING_HPP
#define CUBICSERVER_RECIPES_CAMPFIRE_COOKING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class CampfireCooking : public Recipe {
public:
    CampfireCooking(const std::string &identifier, const nlohmann::json &recipe);
    ~CampfireCooking() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);

private:
    std::unordered_set<ItemId> _ingredients; // what to cook
    ItemId _result;                          // what is obtained
    double _experience;                      // experience generated by the smelting
    uint64_t _cookingTime;                   // time it takes to cook
};
}; // namespace Recipe

#endif // CUBICSERVER_RECIPES_CAMPFIRE_COOKING_HPP
