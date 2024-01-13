#include <fstream>
#include <iostream>

#include "logging/logging.hpp"

#include "Recipes.hpp"

#include "Blasting.hpp"
#include "CampfireCooking.hpp"
#include "CraftingShaped.hpp"
#include "CraftingShapeless.hpp"
#include "Smelting.hpp"
#include "Smithing.hpp"
#include "Smoking.hpp"
#include "StoneCutting.hpp"

#include "SpecialArmorDye.hpp"
#include "SpecialBannerDuplicate.hpp"
#include "SpecialBookCloning.hpp"
#include "SpecialFireworkRocket.hpp"
#include "SpecialFireworkStar.hpp"
#include "SpecialFireworkStarFade.hpp"
#include "SpecialMapCloning.hpp"
#include "SpecialMapExtending.hpp"
#include "SpecialRepairItem.hpp"
#include "SpecialShieldDecoration.hpp"
#include "SpecialShulkerboxColoring.hpp"
#include "SpecialSuspiciousStew.hpp"
#include "SpecialTippedArrow.hpp"

namespace Recipe {
Recipe::Recipe(const std::string &identifier, const nlohmann::json &recipe):
    _identifier(identifier),
    _hasCategory(false),
    _hasGroup(false),
    _isValid(false)
{
    this->setCategory(recipe);
    this->setGroup(recipe);
}

const std::string &Recipe::getIdentifier(void) const noexcept { return (this->_identifier); }

bool Recipe::hasCategory(void) const noexcept { return (this->_hasCategory); }

void Recipe::setCategory(const nlohmann::json &recipe)
{
    if (recipe.contains("category") && recipe["category"].is_string()) {
        this->_hasCategory = true;
        this->_category = recipe["category"].get<std::string>();
    } else {
        this->_hasCategory = false;
    }
}

const std::string &Recipe::getCategory(void) const noexcept { return (this->_category); }

bool Recipe::hasGroup(void) const noexcept { return (this->_hasGroup); }

void Recipe::setGroup(const nlohmann::json &recipe)
{
    if (recipe.contains("group") && recipe["group"].is_string()) {
        this->_hasGroup = true;
        this->_group = recipe["group"].get<std::string>();
    } else {
        this->_hasGroup = false;
    }
}

const std::string &Recipe::getGroup(void) const noexcept { return (this->_group); }

// debug purpose: writes the recipe content to the standard output
void Recipe::dump(void) const { LTRACE("No data for this recipe."); }

bool Recipe::isValid(void) const noexcept { return (this->_isValid); }

// set the recipe validity, invalid recipes will be removed
void Recipe::setValidity(bool validity) noexcept { this->_isValid = validity; }
} // namespace Recipe

void Recipes::addRecipeCreator(const std::string &_namespace, const std::string &type, Recipe::Creator creator) { this->_recipeCreators[_namespace][type] = creator; }

void Recipes::loadFolder(const std::string &_namespace, const std::string &folder)
{
    this->_folderPaths[_namespace].push_back(folder); // stores namespace and folder pair, used for reload

    size_t path_length = folder.size(); // stores the path size, used to getting the recipe names

    // goes recursively through every file in the given folder
    if (!std::filesystem::exists(folder))
        std::filesystem::create_directories(folder);

    for (const auto &filepath : std::filesystem::recursive_directory_iterator(folder)) {
        // checks if the file has the json extension
        if (filepath.path().string().ends_with(".json")) {
            nlohmann::json recipeContent = nlohmann::json::parse(std::ifstream(filepath.path()));

            // if the json contains "type", proceeds to creating the recipe
            if (recipeContent.contains("type") && recipeContent["type"].is_string()) {
                std::string recipeType = recipeContent["type"].get<std::string>(); // "minecraft:smelting" ->
                std::string recipeTypeNamespace = recipeType.substr(0, recipeType.find(':')); // "minecraft"
                std::string recipeTypeType = recipeType.substr(recipeType.find(':') + 1); // "smelting"
                std::string identifier = _namespace + ':' + filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5);

                // if no valid creator is found, throws the UnknownRecipeType exception
                if (!this->_recipeCreators.contains(recipeTypeNamespace) ||
                    !this->_recipeCreators[recipeTypeNamespace].contains(recipeTypeType)) // checks if type creator exists for current recipe
                    throw(UnknownRecipeType("No recipe creator found for recipe type " + recipeTypeNamespace + ":" + recipeTypeType));
                // creates a recipe using the right recipe creator
                this->_recipes[_namespace][filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5)] =
                    this->_recipeCreators[recipeTypeNamespace][recipeTypeType](identifier, recipeContent);
                // removes the recipe if it is not valid (call setValifity(true) to set as valid)
                if (!this->_recipes[_namespace][filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5)]->isValid())
                    this->_recipes[_namespace].erase(filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5));
            }
        }
    }
    LINFO("Loaded {} recipes from path {} into namespace \"{}\"", this->_recipes[_namespace].size(), folder, _namespace);
    // prints the recipes loaded into the given namespace (includes previously loaded recipes from other sources)
    for (const auto &[name, recipe] : this->_recipes[_namespace]) {
        LTRACE("\"{}:{}\":", _namespace, name);
        LTRACE("category: {}", recipe->hasCategory() ? recipe->getCategory() : "none");
        LTRACE("group: {}", recipe->hasGroup() ? recipe->getGroup() : "none");
        LTRACE("valid: {}", recipe->isValid() ? "true" : "false");
        recipe->dump();
        LTRACE("");
    }
}

void Recipes::initialize(void)
{
    // adding default's minecraft recipes
    addRecipeCreator("minecraft", "blasting", Recipe::Blasting::create);
    addRecipeCreator("minecraft", "campfire_cooking", Recipe::CampfireCooking::create);
    addRecipeCreator("minecraft", "crafting_shaped", Recipe::CraftingShaped::create);
    addRecipeCreator("minecraft", "crafting_shapeless", Recipe::CraftingShapeless::create);
    addRecipeCreator("minecraft", "smelting", Recipe::Smelting::create);
    addRecipeCreator("minecraft", "smithing", Recipe::Smithing::create);
    addRecipeCreator("minecraft", "smoking", Recipe::Smoking::create);
    addRecipeCreator("minecraft", "stonecutting", Recipe::StoneCutting::create);

    addRecipeCreator("minecraft", "crafting_special_armordye", Recipe::SpecialArmorDye::create);
    addRecipeCreator("minecraft", "crafting_special_bannerduplicate", Recipe::SpecialBannerDuplicate::create);
    addRecipeCreator("minecraft", "crafting_special_bookcloning", Recipe::SpecialBookCloning::create);
    addRecipeCreator("minecraft", "crafting_special_firework_rocket", Recipe::SpecialFireworkRocket::create);
    addRecipeCreator("minecraft", "crafting_special_firework_star", Recipe::SpecialFireworkStar::create);
    addRecipeCreator("minecraft", "crafting_special_firework_star_fade", Recipe::SpecialFireworkStarFade::create);
    addRecipeCreator("minecraft", "crafting_special_mapcloning", Recipe::SpecialMapCloning::create);
    addRecipeCreator("minecraft", "crafting_special_mapextending", Recipe::SpecialMapExtending::create);
    addRecipeCreator("minecraft", "crafting_special_repairitem", Recipe::SpecialRepairItem::create);
    addRecipeCreator("minecraft", "crafting_special_shielddecoration", Recipe::SpecialSuspiciousStew::create);
    addRecipeCreator("minecraft", "crafting_special_shulkerboxcoloring", Recipe::SpecialSuspiciousStew::create);
    addRecipeCreator("minecraft", "crafting_special_suspiciousstew", Recipe::SpecialSuspiciousStew::create);
    addRecipeCreator("minecraft", "crafting_special_tippedarrow", Recipe::SpecialTippedArrow::create);

    loadFolder("minecraft", "assets/recipes");
}

// reload all recipes
void Recipes::reload(void)
{
    this->clear();
    for (const auto &[_namespace, folders] : this->_folderPaths) {
        for (const auto &folder : folders) {
            this->loadFolder(_namespace, folder);
        }
    }
}

// remove all recipes
void Recipes::clear(void)
{
    for (auto &[_namespace, recipes] : this->_recipes) {
        for (auto &[name, recipe] : recipes) {
            recipe.reset();
        }
    }
    this->_recipes.clear();
}
