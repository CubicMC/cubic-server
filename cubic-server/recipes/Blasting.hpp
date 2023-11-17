#ifndef CUBICSERVER_RECIPES_BLASTING_HPP
#define CUBICSERVER_RECIPES_BLASTING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class Blasting : public Recipe {
public:
    Blasting(const std::string &identifier, const nlohmann::json &recipe);
    ~Blasting() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);

private:
    std::unordered_set<ItemId> _ingredients; // what to cook
    ItemId _result; // what is obtained
    double _experience; // experience generated by the smelting
    uint64_t _cookingTime; // time it takes to cook
};
}

#endif // CUBICSERVER_RECIPES_CAMPFIRE_COOKING_HPP
