#include "Server.hpp"

#include "allConditions.hpp"

// adds all minecraft's default condition types
void addDefaultConditionCreators(void)
{
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "alternative", LootTable::Condition::Alternative::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "block_state_property", LootTable::Condition::BlockStateProperties::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "damage_source_properties", LootTable::Condition::DamageSourceProperties::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "entity_properties", LootTable::Condition::EntityProperties::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "entity_scores", LootTable::Condition::EntityScores::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "inverted", LootTable::Condition::Inverted::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "killed_by_player", LootTable::Condition::KilledByPlayer::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "location_check", LootTable::Condition::LocationCheck::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "match_tool", LootTable::Condition::MatchTool::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "random_chance", LootTable::Condition::RandomChance::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "random_chance_with_looting", LootTable::Condition::RandomChanceWithLooting::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "reference", LootTable::Condition::Reference::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "survives_explosion", LootTable::Condition::SurvivesExplosion::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "table_bonus", LootTable::Condition::TableBonus::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "time_check", LootTable::Condition::TimeCheck::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "value_check", LootTable::Condition::ValueCheck::create);
    Server::getInstance()->lootTables.addConditionCreator("minecraft", "weather_check", LootTable::Condition::WeatherCheck::create);
}