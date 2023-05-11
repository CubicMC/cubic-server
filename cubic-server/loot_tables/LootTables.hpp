#ifndef CUBIC_SERVER_LOOT_TABLES_HPP
#define CUBIC_SERVER_LOOT_TABLES_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <utility>
#include <cstdint>

#include <nlohmann/json.hpp>

#include "types.hpp"

#include "LootTable.hpp"
#include "rolls/Roll.hpp"
#include "entries/Entry.hpp"
#include "functions/Function.hpp"
#include "conditions/Condition.hpp"

void addDefaultRollCreators(void);
void addDefaultEntryCreators(void);
void addDefaultFunctionCreators(void);
void addDefaultConditionCreators(void);

class LootTables {
public:
    LootTables() = default;
    ~LootTables() = default;

    void initialize(const std::string &defaultFolder = "assets/loot_tables");

    void addRollCreator(LootTable::Roll::Creator creator, LootTable::Roll::IsOfType check);
    void addEntryCreator(const std::string &_namespace, const std::string &_name, LootTable::Entry::Creator creator);
    void addFunctionCreator(const std::string &_namespace, const std::string &_name, LootTable::Function::Creator creator);
    void addConditionCreator(const std::string &_namespace, const std::string &_name, LootTable::Condition::Creator creator);
    
    std::unique_ptr<LootTable::Roll::Roll> createRoll(const nlohmann::json &roll);
    std::unique_ptr<LootTable::Entry::Entry> createEntry(const nlohmann::json &entry);
    std::unique_ptr<LootTable::Function::Function> createFunction(const nlohmann::json &function);
    std::unique_ptr<LootTable::Condition::Condition> createCondition(const nlohmann::json &condition);

    void importTableFolder(const std::string &_namespace, const std::string &path);

    bool exists(const std::string &_namespace, const std::string &table);
    LootTable::LootTable &get(const std::string &_namespace, const std::string &table);
    LootTable::LootTable &getTable(const std::string &_namespace, const std::string &table);
    std::unordered_map<std::string, std::unique_ptr<LootTable::LootTable>> &getNamespace(const std::string &_namespace);

    std::unordered_map<std::string, std::unique_ptr<LootTable::LootTable>> &operator[](const std::string &_namespace);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::unique_ptr<LootTable::LootTable>>> _lootTables;

    std::vector<std::pair<LootTable::Roll::Creator, LootTable::Roll::IsOfType>> _rollCreator;
    std::unordered_map<std::string, std::unordered_map<std::string, LootTable::Entry::Creator>> _entryCreator;
    std::unordered_map<std::string, std::unordered_map<std::string, LootTable::Function::Creator>> _functionCreator;
    std::unordered_map<std::string, std::unordered_map<std::string, LootTable::Condition::Creator>> _conditionCreator;
};

#endif //CUBIC_SERVER_LOOT_TABLES_HPP
