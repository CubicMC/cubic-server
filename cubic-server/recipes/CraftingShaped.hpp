#ifndef CUBICSERVER_RECIPES_CRAFTING_SHAPED_HPP
#define CUBICSERVER_RECIPES_CRAFTING_SHAPED_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class CraftingShaped : public Recipe {
public:
    CraftingShaped(const nlohmann::json &recipe);
    ~CraftingShaped() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);

private:
    // class containing or not any list of item
    class MaybeItems {
    public:
        MaybeItems(void);
        MaybeItems(const std::shared_ptr<std::vector<ItemId>> &item);
        ~MaybeItems() = default;

        bool isEmpty(void) const noexcept;
        const std::weak_ptr<std::vector<ItemId>> &getItems(void) const noexcept;

    private:
        bool _empty;
        // refering to an entry of the "key" map, will always be valid
        std::weak_ptr<std::vector<ItemId>> _items;
    };

    // get the corresponding indexed items
    bool getKey(char key, const nlohmann::json &content);

    std::unordered_map<char, std::shared_ptr<std::vector<ItemId>>> _key; // list of item to be placed on the table
    std::vector<std::vector<MaybeItems>> _pattern; // pattern of the craft
    ItemId _result; // item crafted
    uint64_t _count; // number of items crafted
};
};

#endif // CUBICSERVER_RECIPES_CRAFTING_SHAPED_HPP
