#ifndef CUBICSERVER_RECIPES_CRAFTING_SHAPELESS_HPP
#define CUBICSERVER_RECIPES_CRAFTING_SHAPELESS_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class CraftingShapeless : public Recipe {
public:
    CraftingShapeless(const std::string &identifier, const nlohmann::json &recipe);
    ~CraftingShapeless() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);

    const std::vector<std::unordered_set<ItemId>> &getIngredients() const;
    ItemId getCraftedItem() const noexcept;
    uint64_t getCraftedItemCount() const noexcept;

private:
    std::vector<std::unordered_set<ItemId>> _ingredients; // list of alternative items to craft
    ItemId _result; // crafted item
    uint64_t _count; // number of crafted items
};
};

#endif // CUBICSERVER_RECIPES_CRAFTING_SHAPELESS_HPP
