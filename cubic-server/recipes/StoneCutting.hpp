#ifndef CUBICSERVER_RECIPES_STONE_CUTTING_HPP
#define CUBICSERVER_RECIPES_STONE_CUTTING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class StoneCutting : public Recipe {
public:
    StoneCutting(const std::string &identifier, const nlohmann::json &recipe);
    ~StoneCutting() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);

private:
    std::unordered_set<ItemId> _ingredients; // item to be cut
    ItemId _result; // item obtained
    uint64_t _count; // number of items obtained
};
};

#endif // CUBICSERVER_RECIPES_STONE_CUTTING_HPP
