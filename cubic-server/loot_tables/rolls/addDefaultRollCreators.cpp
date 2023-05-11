#include "Server.hpp"

#include "allRolls.hpp"

void addDefaultRollCreators(void)
{
    Server::getInstance()->lootTables.addRollCreator(LootTable::Roll::Constant::creator, LootTable::Roll::Constant::isOfType);
    Server::getInstance()->lootTables.addRollCreator(LootTable::Roll::Uniform::creator, LootTable::Roll::Uniform::isOfType);
    Server::getInstance()->lootTables.addRollCreator(LootTable::Roll::Binomial::creator, LootTable::Roll::Binomial::isOfType);
    Server::getInstance()->lootTables.addRollCreator(LootTable::Roll::Score::creator, LootTable::Roll::Score::isOfType);
}