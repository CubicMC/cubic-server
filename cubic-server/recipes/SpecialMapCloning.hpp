#ifndef CUBICSERVER_RECIPES_SPECIAL_MAP_CLONING_HPP
#define CUBICSERVER_RECIPES_SPECIAL_MAP_CLONING_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialMapCloning : public Recipe {
public:
    SpecialMapCloning(const std::string &identifier, const nlohmann::json &recipe);
    ~SpecialMapCloning() = default;

    void dump(void) const override;

    static std::shared_ptr<Recipe> create(const std::string &identifier, const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_MAP_CLONING_HPP
