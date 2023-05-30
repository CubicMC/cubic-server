#ifndef CUBICSERVER_RECIPES_HPP
#define CUBICSERVER_RECIPES_HPP

#include <memory>
#include <stdint.h>
#include <unordered_map>
#include <vector>

#include <nlohmann/json.hpp>

#include "exceptions.hpp"
#include "types.hpp"

/*
  Trying to create a recipe without a valid constructor
  throws a UnknownRecipeType exception
*/
DEFINE_EXCEPTION(UnknownRecipeType);

namespace Recipe {
class Recipe {
public:
    Recipe(const nlohmann::json &recipe);
    virtual ~Recipe() = default;

    bool hasCategory(void) const noexcept;
    void setCategory(const nlohmann::json &recipe);
    const std::string &getCategory(void) const noexcept;
    bool hasGroup(void) const noexcept;
    void setGroup(const nlohmann::json &recipe);
    const std::string &getGroup(void) const noexcept;
    bool isValid(void) const noexcept;
    // after successfully getting a craft, set its validity to true or it will be removed
    void setValidity(bool validity) noexcept;

    virtual void dump(void) const;

private:
    bool _hasCategory;
    std::string _category;
    bool _hasGroup;
    std::string _group;
    bool _isValid;
};

/*
  Recipe creators are used to add a recipe type.
  Minecraft default's recipe types include :
  crafting_shapeless, crafting_shaped, smelting, stonecutting...
*/
typedef std::unique_ptr<Recipe> (*Creator)(const nlohmann::json &recipe);
};

/*
  Recipes class holds every recipe, creators and recipe folder paths
*/
class Recipes {
public:
    Recipes() = default;
    ~Recipes() = default;

    void addRecipeCreator(const std::string &_namespace, const std::string &type, Recipe::Creator creator);

    void loadFolder(const std::string &_namespace, const std::string &folder);

    void initialize(void);
    void reload(void);
    void clear(void);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::unique_ptr<Recipe::Recipe>>> _recipes;
    std::unordered_map<std::string, std::unordered_map<std::string, Recipe::Creator>> _recipeCreators;
    std::unordered_map<std::string, std::vector<std::string>> _folderPaths;
};

#endif // CUBICSERVER_RECIPES_HPP
