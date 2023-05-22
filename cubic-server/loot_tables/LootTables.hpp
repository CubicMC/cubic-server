#ifndef CUBIC_SERVER_LOOT_TABLES_HPP
#define CUBIC_SERVER_LOOT_TABLES_HPP

#include <cstdint>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include <nlohmann/json.hpp>

#include "types.hpp"

#include "LootTable.hpp"
#include "conditions/Condition.hpp"
#include "entries/Entry.hpp"
#include "functions/Function.hpp"
#include "rolls/Roll.hpp"

void addDefaultRollCreators(void);
void addDefaultEntryCreators(void);
void addDefaultFunctionCreators(void);
void addDefaultConditionCreators(void);

/*
  Loot tables system,
  holds all creators and tables
  initialize must be called after initializing the item converter
*/

class LootTables {
public:
    LootTables() = default;
    ~LootTables() = default;

    void initialize(const std::string &defaultFolder = "assets/loot_tables");

    // creators handle specific loot table components
    void addRollCreator(LootTable::Roll::Creator creator, LootTable::Roll::IsOfType check);
    void addEntryCreator(const std::string &_namespace, const std::string &_name, LootTable::Entry::Creator creator);
    void addFunctionCreator(const std::string &_namespace, const std::string &_name, LootTable::Function::Creator creator);
    void addConditionCreator(const std::string &_namespace, const std::string &_name, LootTable::Condition::Creator creator);

    // calls the right creator
    std::unique_ptr<LootTable::Roll::Roll> createRoll(const nlohmann::json &roll);
    std::unique_ptr<LootTable::Entry::Entry> createEntry(const nlohmann::json &entry);
    std::unique_ptr<LootTable::Function::Function> createFunction(const nlohmann::json &function);
    std::unique_ptr<LootTable::Condition::Condition> createCondition(const nlohmann::json &condition);

    // import all tables within folder and subfolders; does not keed invalid tables
    void importTableFolder(const std::string &_namespace, const std::string &path);

    // table getters have no checks, please make sure your table exists by calling exists("namespace", "table")
    bool exists(const std::string &_namespace, const std::string &table);
    LootTable::LootTable &get(const std::string &_namespace, const std::string &table);
    LootTable::LootTable &getTable(const std::string &_namespace, const std::string &table);
    std::unordered_map<std::string, std::unique_ptr<LootTable::LootTable>> &getNamespace(const std::string &_namespace);

    // operator overload, equivalent to getNamespace for practical uses
    std::unordered_map<std::string, std::unique_ptr<LootTable::LootTable>> &operator[](const std::string &_namespace);

private:
    // loot table map, default loot tables will be imported under the namespace "minecraft"
    std::unordered_map<std::string, std::unordered_map<std::string, std::unique_ptr<LootTable::LootTable>>> _lootTables;

    // creators;
    std::vector<std::pair<LootTable::Roll::Creator, LootTable::Roll::IsOfType>> _rollCreator;
    std::unordered_map<std::string, std::unordered_map<std::string, LootTable::Entry::Creator>> _entryCreator;
    std::unordered_map<std::string, std::unordered_map<std::string, LootTable::Function::Creator>> _functionCreator;
    std::unordered_map<std::string, std::unordered_map<std::string, LootTable::Condition::Creator>> _conditionCreator;
};

#endif // CUBIC_SERVER_LOOT_TABLES_HPP
