#ifndef CUBICSERVER_RECIPES_CAMPFIRE_COOKING_HPP
#define CUBICSERVER_RECIPES_CAMPFIRE_COOKING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
    class CampfireCooking : public Recipe {
    public:
        CampfireCooking(const nlohmann::json &recipe);
        ~CampfireCooking() = default;

        void dump(void) const override;

        static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
    private:
        ItemId _ingredient;
        ItemId _result;
        double _experience;
        uint64_t _cookingTime;
    };
};

#endif // CUBICSERVER_RECIPES_CAMPFIRE_COOKING_HPP
