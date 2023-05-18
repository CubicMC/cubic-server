#include "Server.hpp"

#include "allEntries.hpp"

// adds all minecraft's default entry types
void addDefaultEntryCreators(void)
{
    Server::getInstance()->lootTables.addEntryCreator("minecraft", "alternatives", LootTable::Entry::Alternative::creator);
    Server::getInstance()->lootTables.addEntryCreator("minecraft", "dynamic", LootTable::Entry::Dynamic::creator);
    Server::getInstance()->lootTables.addEntryCreator("minecraft", "empty", LootTable::Entry::Empty::creator);
    Server::getInstance()->lootTables.addEntryCreator("minecraft", "group", LootTable::Entry::Group::creator);
    Server::getInstance()->lootTables.addEntryCreator("minecraft", "item", LootTable::Entry::Item::creator);
    Server::getInstance()->lootTables.addEntryCreator("minecraft", "tag", LootTable::Entry::ItemTag::creator);
    Server::getInstance()->lootTables.addEntryCreator("minecraft", "loot_table", LootTable::Entry::LootTableEntry::creator);
    Server::getInstance()->lootTables.addEntryCreator("minecraft", "sequence", LootTable::Entry::Sequence::creator);
}