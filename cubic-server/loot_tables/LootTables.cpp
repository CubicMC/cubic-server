#include "LootTables.hpp"

#include <filesystem>
#include <fstream>

#include "logging/Logger.hpp"

void LootTables::initialize(const std::string &defaultFolder)
{
    addDefaultRollCreators();
    addDefaultEntryCreators();
    addDefaultFunctionCreators();
    addDefaultConditionCreators();

    this->importTableFolder("minecraft", defaultFolder);
}

void LootTables::addRollCreator(LootTable::Roll::Creator creator, LootTable::Roll::IsOfType check)
{
    this->_rollCreator.push_back({creator, check});
}

void LootTables::addEntryCreator(const std::string &_namespace, const std::string &_name, LootTable::Entry::Creator creator)
{
    this->_entryCreator[_namespace][_name] = creator;
}

void LootTables::addFunctionCreator(const std::string &_namespace, const std::string &_name, LootTable::Function::Creator creator)
{
    this->_functionCreator[_namespace][_name] = creator;
}

void LootTables::addConditionCreator(const std::string &_namespace, const std::string &_name, LootTable::Condition::Creator creator)
{
    this->_conditionCreator[_namespace][_name] = creator;
}

std::unique_ptr<LootTable::Roll::Roll> LootTables::createRoll(const nlohmann::json &roll)
{
    for (const auto &[creator, check] : this->_rollCreator) {
        if (check(roll))
            return (creator(roll));
    }
    throw (LootTable::Roll::NoRollConstructor("No constructor fitting the roll: " + roll.dump()));
    return (nullptr);
}

std::unique_ptr<LootTable::Entry::Entry> LootTables::createEntry(const nlohmann::json &entry)
{
    if (entry.is_object() && \
        entry.contains("type") && \
        entry["type"].is_string()) {
        const std::string &type = entry["type"].get<std::string>();
        size_t separator = type.find(':');

        if (separator == std::string::npos)
            return (nullptr);
        return (this->_entryCreator[type.substr(0, separator)][type.substr(separator + 1)](entry));
    }
    throw (LootTable::Entry::NoEntryContructor(entry));
    return (nullptr);
}

std::unique_ptr<LootTable::Function::Function> LootTables::createFunction(const nlohmann::json &function)
{
    if (function.is_object() && \
        function.contains("function") && \
        function["function"].is_string()) {
        const std::string &type = function["function"].get<std::string>();
        size_t separator = type.find(':');

        if (separator == std::string::npos)
            return (nullptr);
        return (this->_functionCreator[type.substr(0, separator)][type.substr(separator + 1)](function));
    }
    throw (LootTable::Function::NoFunctionContructor("No constructor fitting the function: " + function.dump()));
    return (nullptr);
}

std::unique_ptr<LootTable::Condition::Condition> LootTables::createCondition(const nlohmann::json &condition)
{
    if (condition.is_object() && \
        condition.contains("condition") && \
        condition["condition"].is_string()) {
        const std::string &type = condition["condition"].get<std::string>();
        size_t separator = type.find(':');

        if (separator == std::string::npos)
            return (nullptr);
        return (this->_conditionCreator[type.substr(0, separator)][type.substr(separator + 1)](condition));
    }
    throw (LootTable::Condition::NoConditionContructor("No constructor fitting the entry: " + condition.dump()));
    return (nullptr);
}

void LootTables::importTableFolder(const std::string &_namespace, const std::string &path)
{
    size_t path_length = path.size();

    if (!std::filesystem::is_directory(path))
        return;
    // recursively loops through every file in the given folder
    for (const auto &filepath : std::filesystem::recursive_directory_iterator(path)) {
        if (filepath.is_regular_file() && filepath.path().string().ends_with(".json")) {
            std::ifstream filestream(filepath.path().string());
            std::stringstream filecontent;

            filecontent << filestream.rdbuf();

            std::unique_ptr<LootTable::LootTable> newTable = std::make_unique<LootTable::LootTable>(nlohmann::json::parse(filecontent.str()));
            if (newTable->isValid())
                this->_lootTables[_namespace][filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5)].swap(newTable);
            else
                LINFO("invalid table " + filepath.path().string());
            LDEBUG("loaded ", _namespace, ":", filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5));
        }
    }
}

bool LootTables::exists(const std::string &_namespace, const std::string &table)
{
    return (this->_lootTables.contains(_namespace) && this->_lootTables[_namespace].contains(table));
}

LootTable::LootTable &LootTables::get(const std::string &_namespace, const std::string &table)
{
    return (*this->_lootTables[_namespace][table]);
}

LootTable::LootTable &LootTables::getTable(const std::string &_namespace, const std::string &table)
{
    return (*this->_lootTables[_namespace][table]);
}

std::unordered_map<std::string, std::unique_ptr<LootTable::LootTable>> &LootTables::getNamespace(const std::string &_namespace)
{
    return (this->_lootTables[_namespace]);
}

std::unordered_map<std::string, std::unique_ptr<LootTable::LootTable>> &LootTables::operator[](const std::string &_namespace)
{
    return (this->_lootTables[_namespace]);
}
