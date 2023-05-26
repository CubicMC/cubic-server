#ifndef CUBICSERVER_RECIPES_SPECIAL_SUSPICIOUS_STEW_HPP
#define CUBICSERVER_RECIPES_SPECIAL_SUSPICIOUS_STEW_HPP

#include "Recipes.hpp"

#include "Server.hpp"

namespace Recipe {
class SpecialSuspiciousStew : public Recipe {
public:
    SpecialSuspiciousStew(const nlohmann::json &recipe);
    ~SpecialSuspiciousStew() = default;

    void dump(void) const override;

    static std::unique_ptr<Recipe> create(const nlohmann::json &recipe);
};
};

#endif // CUBICSERVER_RECIPES_SPECIAL_SUSPICIOUS_STEW_HPP
