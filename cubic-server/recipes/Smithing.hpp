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
    ItemId _base; // first item
    ItemId _addition; // second item
    ItemId _result; // crafter item
};
};

#endif // CUBICSERVER_RECIPES_SMITHING_HPP
