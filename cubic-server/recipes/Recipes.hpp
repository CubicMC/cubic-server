#ifndef CUBICSERVER_RECIPES_HPP
#define CUBICSERVER_RECIPES_HPP

#include <unordered_map>
#include <vector>
#include <memory>
#include <exception>
#include <stdint.h>

#include <nlohmann/json.hpp>

#include "types.hpp"

class UnknownRecipeType : public std::exception {
public:
    UnknownRecipeType(const std::string &_namespace, const std::string &type);
    ~UnknownRecipeType() = default;
    const char *what() const noexcept;

private:
    const std::string _message;
};

namespace Recipe {
    /*
    enum IngredientType {
        IngredientInvalid = -1,
        IngredientItem = 0,
        IngredientItemList,
        IngredientTag,
        IngredientTypeCount
    };

    union IngredientUnion {
        ItemId item;
        std::vector<ItemId> itemList;
        std::string tag;
    };

    struct Ingredient {
        public:
            Ingredient();
            IngredientType type;
            IngredientUnion ingredient;
    };

    Ingredient getIngredient(const nlohmann::json &json);
    */

    class Recipe {
    public:
        Recipe();
        ~Recipe() = default;

        bool hasCategory(void) const noexcept;
        void setCategory(const nlohmann::json &recipe);
        const std::string &getCategory(void) const noexcept;
        bool hasGroup(void) const noexcept;
        void setGroup(const nlohmann::json &recipe);
        const std::string &getGroup(void) const noexcept;
        bool isValid(void) const noexcept;
        void setValidity(bool validity) noexcept;

        virtual void dump(void) const;

    private:
        bool _hasCategory;
        std::string _category;
        bool _hasGroup;
        std::string _group;
        bool _isValid;
    };

    typedef std::unique_ptr<Recipe> (*Creator)(const nlohmann::json &recipe);
};

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
