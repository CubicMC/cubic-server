#ifndef CUBICSERVER_RECIPES_SMITHING_HPP
#define CUBICSERVER_RECIPES_SMITHING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
    class Smithing : public Recipe {
    public:
        Smithing(const std::string &identifier, const nlohmann::json &recipe);
        ~Smithing() = default;

        void dump(void) const override;
        void insertToPayload(std::vector<uint8_t> &payload) const override;

        static std::unique_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);
    private:
        std::unordered_set<ItemId> _bases; // first item
        std::unordered_set<ItemId> _additions; // second item
        ItemId _result; // crafter item
    };
};

#endif // CUBICSERVER_RECIPES_SMITHING_HPP
