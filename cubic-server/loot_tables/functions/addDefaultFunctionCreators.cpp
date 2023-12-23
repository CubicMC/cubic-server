#include "Server.hpp"

#include "allFunctions.hpp"

// adds all minecraft's default functions types
void addDefaultFunctionCreators(void)
{
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "apply_bonus", LootTable::Function::ApplyBonus::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "copy_state", LootTable::Function::CopyBlockStates::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "copy_name", LootTable::Function::CopyName::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "copy_nbt", LootTable::Function::CopyNBT::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "enchant_randomly", LootTable::Function::EnchantRandomly::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "enchant_with_levels", LootTable::Function::EnchantWithLevels::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "exploration_map", LootTable::Function::ExplorationMapProperties::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "explosion_decay", LootTable::Function::ExplosionDecay::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "fill_player_head", LootTable::Function::FillPlayerHead::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "furnace_smelt", LootTable::Function::FurnaceSmelt::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "limit_count", LootTable::Function::LimitCount::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "looting_enchant", LootTable::Function::LootingEnchant::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_attributes", LootTable::Function::SetAttributes::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_banner_pattern", LootTable::Function::SetBannerPattern::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_contents", LootTable::Function::SetContents::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_count", LootTable::Function::SetCount::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_damage", LootTable::Function::SetDamage::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_enchantments", LootTable::Function::SetEnchantments::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_instrument", LootTable::Function::SetInstrument::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_loot_table", LootTable::Function::SetLootTable::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_lore", LootTable::Function::SetLore::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_name", LootTable::Function::SetName::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_nbt", LootTable::Function::SetNBT::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_potion", LootTable::Function::SetPotion::create);
    Server::getInstance()->getLootTableSystem().addFunctionCreator("minecraft", "set_stew_effect", LootTable::Function::SetStewEffect::create);
}
