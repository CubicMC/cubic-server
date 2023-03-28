#include "Server.hpp"
#include "LootTables.hpp"

#include <fstream>

NoLootTableException::NoLootTableException() noexcept
{
}

const char *NoLootTableException::what() const noexcept
{
    return ("No loot tables in folder \"assets/loot_tables\".");
}

LootTables::LootTables(const std::string &path)
{
    const std::string defaultNamespace = "minecraft";
    if (!this->importTableFolder(defaultNamespace, path) || this->_lootTables[defaultNamespace].size() == 0)
        throw (NoLootTableException());
}

bool LootTables::importTableFolder(const std::string &_namespace, const std::string &path)
{
    size_t path_length = path.size();

    if (!std::filesystem::is_directory(path))
        return (false);
    // recursively loops through every file in the given folder
    for (const auto &filepath : std::filesystem::recursive_directory_iterator(path)) {
        if (filepath.path().string().ends_with(".json")) {
            std::ifstream filestream(filepath.path().string());
            std::stringstream filecontent;

            filecontent << filestream.rdbuf();

//            std::cout << filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5) << std::endl;
            this->_lootTables[_namespace][filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5)] = nlohmann::json::parse(filecontent.str());
//            std::cout << this->_lootTables[_namespace][filepath.path().string().substr(path_length + 1, filepath.path().string().length() - (path_length + 1) - 5)] << std::endl;
        }
    }
    return (true);
}

void LootTables::deleteTable(const std::string &_namespace, const std::string &name)
{
    this->_lootTables[_namespace].erase(name);
}

void LootTables::deleteNamespace(const std::string &_namespace)
{
    this->_lootTables.erase(_namespace);
}

void LootTables::clearAll(void)
{
    this->_lootTables.clear();
}

bool LootTables::exists(const std::string &_namespace, const std::string &table)
{
    if (this->_lootTables.count(_namespace) > 0)
        return (this->_lootTables[_namespace].count(table) > 0);
    return (false);
}

bool LootTables::poll(LootTablePoll &result, const std::string &_namespace, const std::string &table)
{
    std::cout << "trying to poll table " << _namespace << ":" << table << std::endl;

    if (this->exists(_namespace, table)) {
        const auto selectedTable = this->_lootTables[_namespace][table];
        std::cout << "table exists:" << std::endl;
        std::cout << this->_lootTables[_namespace][table] << std::endl;;

        std::cout << "table contains \"pools\" ? : " << selectedTable.contains("pools") << std::endl;
        std::cout << "table contains \"pools\" ? : " << selectedTable["pools"].is_array() << std::endl;
        if (selectedTable.contains("pools") && selectedTable["pools"].is_array()) { 
            std::cout << "table looks like a valid table" << std::endl;

            for (const auto &pool_entry : selectedTable["pools"].items()) {
                std::cout << pool_entry.value() << std::endl;
                //
                if (pool_entry.value()["rolls"].is_number_integer() ||
                    (pool_entry.value()["rolls"].is_object() && pool_entry.value()["rools"]["type"] == "minecraft:constant"))
                    std::cout << "   ---   poll of type Uniform:   ---" << std::endl;
                    this->pollRollsTypeUniform(result, pool_entry.value());
            }
            return (false);
        }
        else
            std::cout << "table is not valid" << std::endl;
        return (true);
    } else {
        std::cout << "table does not exist" << std::endl;
        return (false);
    }
}

bool LootTables::pollRollsTypeUniform(LootTablePoll &result, nlohmann::json pool)
{
    int max_weight = 0;
    int roll_number = 0;

    std::cout << "enter rool type uniform" << std::endl;
    if (pool["rolls"].is_number_integer()) {
        std::cout << "roll variable is a number" << std::endl;
        roll_number = pool["rolls"].get<nlohmann::json::number_integer_t>();
    } else {
        std::cout << "roll variable is an object" << std::endl;
        roll_number = pool["rools"]["value"].get<nlohmann::json::number_integer_t>();
    }
    std::cout << "roll_number " << roll_number << std::endl;

    for (const auto &entry : pool["entries"].items()) {
        if (entry.value().contains("weight") && entry.value()["weight"].is_number_integer())
            max_weight += entry.value()["weight"].get<nlohmann::json::number_integer_t>();
        else
            max_weight += 1;
    }

    std::cout << "max_weight " << max_weight << std::endl;
    for (int n = 0; n < roll_number; n++) {
        int choice = rand() % max_weight;

        int elapsed_weight = 0;
        int position = 1;

        std::cout << "go to weight " << choice << std::endl;
        std::cout << "entry: " << std::endl << pool["entries"].at(0) << std::endl;
        if (pool["entries"].at(0).contains("weight"))
            elapsed_weight += pool["entries"].at(0)["weight"].get<nlohmann::json::number_integer_t>();
        else
            elapsed_weight += 1;
        while (elapsed_weight < choice) {
            std::cout << "entry: " << std::endl << pool["entries"].at(position) << std::endl;
            std::cout << "elapsed weight: " << elapsed_weight << " from position " << position << std::endl;
            if (pool["entries"].at(position).contains("weight"))
                elapsed_weight += pool["entries"].at(position)["weight"].get<nlohmann::json::number_integer_t>();
            else
                elapsed_weight += 1;
            position++;
        }
        result.push_back(std::pair<ItemId, uint8_t>(Server::getInstance()->getItemConverter().fromItemToProtocolId(pool["entries"].at(position - 1)["name"]), 1));
    }
    for (const auto &item : result) {
        std::cout << std::to_string(item.second) << " " << Server::getInstance()->getItemConverter().fromProtocolIdToItem(item.first) << std::endl;
    }
    return (true);
}

void LootTables::snitchTables(void) const
{
    for (const auto &ns : this->_lootTables) {
        std::cout << "from namespace \"" << ns.first << "\":" << std::endl;
        for (const auto &tb : ns.second) {
            std::cout << "\t\"" << tb.first << "\"," << std::endl;
        }
    }
}
