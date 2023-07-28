#include "Server.hpp"

#include "allConditions.hpp"

// adds all minecraft's default condition types
void addDefaultConditionCreators(void)
{
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "alternative", LootTable::Condition::Alternative::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "block_state_property", LootTable::Condition::BlockStateProperties::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "damage_source_properties", LootTable::Condition::DamageSourceProperties::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "entity_properties", LootTable::Condition::EntityProperties::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "entity_scores", LootTable::Condition::EntityScores::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "inverted", LootTable::Condition::Inverted::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "killed_by_player", LootTable::Condition::KilledByPlayer::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "location_check", LootTable::Condition::LocationCheck::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "match_tool", LootTable::Condition::MatchTool::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "random_chance", LootTable::Condition::RandomChance::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "random_chance_with_looting", LootTable::Condition::RandomChanceWithLooting::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "reference", LootTable::Condition::Reference::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "survives_explosion", LootTable::Condition::SurvivesExplosion::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "table_bonus", LootTable::Condition::TableBonus::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "time_check", LootTable::Condition::TimeCheck::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "value_check", LootTable::Condition::ValueCheck::create);
    Server::getInstance()->getLootTableSystem().addConditionCreator("minecraft", "weather_check", LootTable::Condition::WeatherCheck::create);
}
