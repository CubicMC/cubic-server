#ifndef CUBICSERVER_RECIPES_SPECIAL_REPAIR_ITEM_HPP
#define CUBICSERVER_RECIPES_SPECIAL_REPAIR_ITEM_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialRepairItem : public Recipe {
public:
    SpecialRepairItem(const std::string &identifier, const nlohmann::json &recipe);
    ~SpecialRepairItem() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_REPAIR_ITEM_HPP
