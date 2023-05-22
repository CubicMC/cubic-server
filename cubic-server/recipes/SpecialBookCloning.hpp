#ifndef CUBICSERVER_RECIPES_SPECIAL_BOOK_CLONING_HPP
#define CUBICSERVER_RECIPES_SPECIAL_BOOK_CLONING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialBookCloning : public Recipe {
public:
    SpecialBookCloning(const nlohmann::json &recipe);
    ~SpecialBookCloning() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_BOOK_CLONING_HPP
