#ifndef CUBICSERVER_RECIPES_CRAFTING_SHAPELESS_HPP
#define CUBICSERVER_RECIPES_CRAFTING_SHAPELESS_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
    class CraftingShapeless : public Recipe {
    public:
        CraftingShapeless(const nlohmann::json &recipe);
        ~CraftingShapeless() = default;

        void dump(void) const override;

        static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
    private:
        std::vector<ItemId> _ingredients;
        ItemId _result;
        uint64_t _count;
    };
};

#endif // CUBICSERVER_RECIPES_CRAFTING_SHAPELESS_HPP
