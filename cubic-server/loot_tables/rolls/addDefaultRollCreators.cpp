#include "Server.hpp"

#include "allRolls.hpp"

// adds all minecraft's default roll types
void addDefaultRollCreators(void)
{
    Server::getInstance()->getLootTableSystem().addRollCreator(LootTable::Roll::Constant::creator, LootTable::Roll::Constant::isOfType);
    Server::getInstance()->getLootTableSystem().addRollCreator(LootTable::Roll::Uniform::creator, LootTable::Roll::Uniform::isOfType);
    Server::getInstance()->getLootTableSystem().addRollCreator(LootTable::Roll::Binomial::creator, LootTable::Roll::Binomial::isOfType);
    Server::getInstance()->getLootTableSystem().addRollCreator(LootTable::Roll::Score::creator, LootTable::Roll::Score::isOfType);
}
