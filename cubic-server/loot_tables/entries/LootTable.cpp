#include "Server.hpp"

#include "LootTable.hpp"

namespace LootTable {
namespace Entry {
LootTableEntry::LootTableEntry(const nlohmann::json &entry):
    Entry(entry),
    _isTable(false),
    _table(nullptr)
{
    std::string table = entry["name"].get<std::string>();
    std::string tableNamespace;
    std::string tableName;

    if (table.find(':') == std::string::npos)
        return;
    tableNamespace = table.substr(0, table.find(':'));
    tableName = table.substr(tableNamespace.size() + 1);
    if (Server::getInstance()->getLootTableSystem().exists("", "")) {
        this->_isTable = true;
        this->_table = &Server::getInstance()->getLootTableSystem().get(tableNamespace, tableName);
    }

    this->setValidity(true);
}

bool LootTableEntry::poll(LootTablePoll &poll, LootContext *context) const
{
    if (!this->_isTable)
        return (false);

    LootTablePoll childPoll = this->_table->poll(context);
    poll.addRolledItem(childPoll);
    return (true);
}

std::unique_ptr<Entry> LootTableEntry::creator(const nlohmann::json &entry) { return (std::make_unique<LootTableEntry>(entry)); }
};
};
