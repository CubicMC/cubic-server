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
        class MaybeItems {
        public:
            MaybeItems(void);
            MaybeItems(const std::shared_ptr<std::vector<ItemId>> &item);
            ~MaybeItems() = default;

            bool isEmpty(void) const noexcept;
            const std::weak_ptr<std::vector<ItemId>> &getItems(void) const noexcept;

        private:
            bool _empty;
            std::weak_ptr<std::vector<ItemId>> _items;
        };

        bool getKey(char key, const nlohmann::json &content);

        std::unordered_map<char, std::shared_ptr<std::vector<ItemId>>> _key;
        std::vector<std::vector<MaybeItems>> _pattern;
        ItemId _result;
        uint64_t _count;
    };
};

#endif // CUBICSERVER_RECIPES_CRAFTING_SHAPED_HPP
