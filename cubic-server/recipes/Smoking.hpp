#ifndef CUBICSERVER_RECIPES_SMOKING_HPP
#define CUBICSERVER_RECIPES_SMOKING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
    class Smoking : public Recipe {
    public:
        Smoking(const nlohmann::json &recipe);
        ~Smoking() = default;

        void dump(void) const override;

        static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
    private:
        ItemId _ingredient;
        ItemId _result;
        double _experience;
        uint64_t _cookingTime;
    };
};

#endif // CUBICSERVER_RECIPES_SMOKING_HPP
