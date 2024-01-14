#ifndef CUBICSERVER_RECIPES_CRAFTING_SHAPED_HPP
#define CUBICSERVER_RECIPES_CRAFTING_SHAPED_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class CraftingShaped : public Recipe {
public:
    CraftingShaped(const std::string &identifier, const nlohmann::json &recipe);
    ~CraftingShaped() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);

    const std::unordered_map<char, std::shared_ptr<std::unordered_set<ItemId>>> &getKeys() const;
    const std::vector<char> &getPattern() const;
    size_t getXSize() const noexcept;
    size_t getYSize() const noexcept;
    ItemId getCraftedItem() const noexcept;
    uint64_t getCraftedItemCount() const noexcept;

private:
    // get the corresponding indexed items from recipe json
    bool getKey(char key, const nlohmann::json &content);

    size_t _x; // horizontal crafting size requiered
    size_t _y; // vertical crafting size requiered
    std::unordered_map<char, std::shared_ptr<std::unordered_set<ItemId>>> _key; // list of item to be placed on the table
    std::vector<char> _pattern; // pattern of the craft
    ItemId _result; // item crafted
    uint64_t _count; // number of items crafted
};
};

#endif // CUBICSERVER_RECIPES_CRAFTING_SHAPED_HPP
