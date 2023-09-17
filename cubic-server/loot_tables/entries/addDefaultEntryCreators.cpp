#include "Server.hpp"

#include "allEntries.hpp"

// adds all minecraft's default entry types
void addDefaultEntryCreators(void)
{
    Server::getInstance()->getLootTableSystem().addEntryCreator("minecraft", "alternatives", LootTable::Entry::Alternative::creator);
    Server::getInstance()->getLootTableSystem().addEntryCreator("minecraft", "dynamic", LootTable::Entry::Dynamic::creator);
    Server::getInstance()->getLootTableSystem().addEntryCreator("minecraft", "empty", LootTable::Entry::Empty::creator);
    Server::getInstance()->getLootTableSystem().addEntryCreator("minecraft", "group", LootTable::Entry::Group::creator);
    Server::getInstance()->getLootTableSystem().addEntryCreator("minecraft", "item", LootTable::Entry::Item::creator);
    Server::getInstance()->getLootTableSystem().addEntryCreator("minecraft", "tag", LootTable::Entry::ItemTag::creator);
    Server::getInstance()->getLootTableSystem().addEntryCreator("minecraft", "loot_table", LootTable::Entry::LootTableEntry::creator);
    Server::getInstance()->getLootTableSystem().addEntryCreator("minecraft", "sequence", LootTable::Entry::Sequence::creator);
}
