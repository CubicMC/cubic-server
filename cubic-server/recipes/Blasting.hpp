#ifndef CUBICSERVER_RECIPES_BLASTING_HPP
#define CUBICSERVER_RECIPES_BLASTING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
    class Blasting : public Recipe {
    public:
        Blasting(const nlohmann::json &recipe);
        ~Blasting() = default;

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
