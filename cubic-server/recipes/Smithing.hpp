#ifndef CUBICSERVER_RECIPES_SMITHING_HPP
#define CUBICSERVER_RECIPES_SMITHING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
    class Smithing : public Recipe {
    public:
        Smithing(const nlohmann::json &recipe);
        ~Smithing() = default;

        void dump(void) const override;

        static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
    private:
        ItemId _base;
        ItemId _addition;
        ItemId _result;
    };
};

#endif // CUBICSERVER_RECIPES_SMITHING_HPP
