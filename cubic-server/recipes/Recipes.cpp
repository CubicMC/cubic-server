#include <iostream>
#include <fstream>

#include "logging/Logger.hpp"

#include "Recipes.hpp"

#include "Blasting.hpp"
#include "CampfireCooking.hpp"
#include "CraftingShaped.hpp"
#include "CraftingShapeless.hpp"
#include "Smelting.hpp"
#include "Smithing.hpp"
#include "Smoking.hpp"
#include "StoneCutting.hpp"

UnknownRecipeType::UnknownRecipeType(const std::string &_namespace, const std::string &type) :
    _message("No recipe creator found for recipe type " + _namespace + ":" + type)
{}

const char *UnknownRecipeType::what() const noexcept
{
    return (this->_message.c_str());
}

namespace Recipe {
    Recipe::Recipe() : _hasCategory(false), _hasGroup(false), _isValid(false)
    {}

    bool Recipe::hasCategory(void) const noexcept
    {
        return (this->_hasCategory);
    }

    void Recipe::setCategory(const nlohmann::json &recipe)
    {
        if (recipe.contains("category") && recipe["category"].is_string()) {
            this->_hasCategory = true;
            this->_category = recipe["category"].get<std::string>();
        } else {
            this->_hasCategory = false;
        }
    }

    const std::string &Recipe::getCategory(void) const noexcept
    {
        return (this->_category);
    }

    bool Recipe::hasGroup(void) const noexcept
    {
        return (this->_hasGroup);
    }

    void Recipe::setGroup(const nlohmann::json &recipe)
    {
        if (recipe.contains("group") && recipe["group"].is_string()) {
            this->_hasGroup = true;
            this->_group = recipe["group"].get<std::string>();
        } else {
            this->_hasGroup = false;
        }
    }

    const std::string &Recipe::getGroup(void) const noexcept
    {
        return (this->_group);
    }

    void Recipe::dump(void) const
    {
        std::cout << "No data for this recipe." << std::endl;
    }

    bool Recipe::isValid(void) const noexcept
    {
        return (this->_isValid);
    }

    void Recipe::setValidity(bool validity) noexcept
    {
        this->_isValid = validity;
    }
};

void Recipes::addRecipeCreator(const std::string &_namespace, const std::string &type, Recipe::Creator creator)
{
    this->_recipeCreators[_namespace][type] = creator;
}

void Recipes::loadFolder(const std::string &_namespace, const std::string &folder)
{
    this->_folderPaths[_namespace].push_back(folder); // stocks namespace and folder pair, used for reload

    size_t path_length = folder.size();

    for (const auto &filepath : std::filesystem::recursive_directory_iterator(folder)) {
        if (filepath.path().string().ends_with(".json")) {
            std::ifstream filestream(filepath.path().string());
            std::stringstream filecontent;

            filecontent << filestream.rdbuf();
            
            nlohmann::json recipeContent = nlohmann::json::parse(filecontent.str());

            if (recipeContent.contains("type") && recipeContent["type"].is_string()) {
                std::string recipeType = recipeContent["type"].get<std::string>();            // "minecraft:smelting"
                std::string recipeTypeNamespace = recipeType.substr(0, recipeType.find(':')); // "minecraft"
                std::string recipeTypeType = recipeType.substr(recipeType.find(':') + 1);         // "smelting"

                if (!this->_recipeCreators.contains(recipeTypeNamespace) || !this->_recipeCreators[recipeTypeNamespace].contains(recipeTypeType)) // checks if type creator exists for current recipe
                    throw (UnknownRecipeType(recipeTypeNamespace, recipeTypeType));
                this->_recipes[_namespace][filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5)] = this->_recipeCreators[recipeTypeNamespace][recipeTypeType](recipeContent);
                if (!this->_recipes[_namespace][filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5)]->isValid())
                    this->_recipes[_namespace].erase(filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5));
            }
        }
    }
    LINFO("Loaded ", this->_recipes[_namespace].size(), " recipes from path ", folder, " into namespace \"", _namespace, "\"");
    /* prints the recipes loaded into the given namespace (includes previously loaded recipes from other sources)
    for (const auto &[name, recipe] : this->_recipes[_namespace]) {
        std::cout << "\"" << _namespace << ":" << name << "\":" << std::endl;
        recipe->dump();
        std::cout << std::endl;
    }
    */
}

void Recipes::initialize(void)
{
    addRecipeCreator("minecraft", "blasting", Recipe::Blasting::create);
    addRecipeCreator("minecraft", "campfire_cooking", Recipe::CampfireCooking::create);
    addRecipeCreator("minecraft", "crafting_shaped", Recipe::CraftingShaped::create);
    addRecipeCreator("minecraft", "crafting_shapeless", Recipe::CraftingShapeless::create);
    addRecipeCreator("minecraft", "smelting", Recipe::Smelting::create);
    addRecipeCreator("minecraft", "smithing", Recipe::Smithing::create);
    addRecipeCreator("minecraft", "smoking", Recipe::Smoking::create);
    addRecipeCreator("minecraft", "stonecutting", Recipe::StoneCutting::create);

    loadFolder("minecraft", "assets/recipes");
}

void Recipes::reload(void)
{
    this->clear();
    for (const auto &[_namespace, folders] : this->_folderPaths) {
        for (const auto &folder : folders) {
            this->loadFolder(_namespace, folder);
        }
    }
}

void Recipes::clear(void)
{
    for (auto &[_namespace, recipes] : this->_recipes) {
        for (auto &[name, recipe] : recipes) {
            recipe.reset();
        }
    }
    this->_recipes.clear();
}