#ifndef CUBICSERVER_RECIPES_SMELTING_HPP
#define CUBICSERVER_RECIPES_SMELTING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
    class Smelting : public Recipe {
    public:
        Smelting(const nlohmann::json &recipe);
        ~Smelting() = default;

        void dump(void) const override;

        static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
    private:
        ItemId _ingredient;
        ItemId _result;
        double _experience;
        uint64_t _cookingTime;
    };
};

#endif // CUBICSERVER_RECIPES_SMELTING_HPP
