#ifndef CUBICSERVER_RECIPES_STONE_CUTTING_HPP
#define CUBICSERVER_RECIPES_STONE_CUTTING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class StoneCutting : public Recipe {
public:
    StoneCutting(const nlohmann::json &recipe);
    ~StoneCutting() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);

private:
    ItemId _ingredient; // item to be cut
    ItemId _result; // item obtained
    uint64_t _count; // number of items obtained
};
};

#endif // CUBICSERVER_RECIPES_STONE_CUTTING_HPP
