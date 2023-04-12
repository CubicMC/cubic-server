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
    if (this->exists(_namespace, table)) {
        const auto selectedTable = this->_lootTables[_namespace][table];

        if (selectedTable.contains("pools") && selectedTable["pools"].is_array()) { 
            for (const auto &pool_entry : selectedTable["pools"].items()) {

                if (pool_entry.value()["rolls"].is_number_integer() || // roll type constant
                    (pool_entry.value()["rolls"].is_object() && pool_entry.value()["rolls"].contains("type") &&
                     pool_entry.value()["rolls"]["type"].get<std::string>() == "minecraft:constant"))
                    this->pollRollsTypeConstant(result, pool_entry.value());
                else if (pool_entry.value()["rolls"].is_object() && // roll type uniform
                         pool_entry.value()["rolls"].contains("min") && pool_entry.value()["rolls"].contains("max") &&
                         pool_entry.value()["rolls"]["min"].is_number_integer() && pool_entry.value()["rolls"]["max"].is_number_integer())
                    this->pollRollsTypeUniform(result, pool_entry.value());
                else if (pool_entry.value()["rolls"].is_object() && // roll type binomial
                         pool_entry.value()["rolls"].contains("n") && pool_entry.value()["rolls"].contains("p") &&
                         pool_entry.value()["rolls"]["n"].is_number_integer() && pool_entry.value()["rolls"]["p"].is_number_float())
                    this->pollRollsTypeBinomial(result, pool_entry.value());
//                else if (pool_entry.value()["rolls"].is_object() && // roll type score
//                         (pool_entry.value()["rolls"]["type"] == "minecraft:score"))
//                    this->pollRollsTypeScore(result, pool_entry.value());
            }
        }
        return (true);
    } else
        return (false);
}

bool LootTables::pollRollsTypeConstant(LootTablePoll &result, nlohmann::json pool)
{
    int roll_number = 0;

    if (pool["rolls"].is_number_integer()) {
        roll_number = pool["rolls"].get<nlohmann::json::number_integer_t>();
    } else {
        roll_number = pool["rools"]["value"].get<nlohmann::json::number_integer_t>();
    }

    return (this->pollXPool(result, roll_number, pool["entries"]));
}

bool LootTables::pollRollsTypeUniform(LootTablePoll &result, nlohmann::json pool)
{
    int min_roll = 0;
    int max_roll = 0;
    int roll_number = 0;

    min_roll = pool["rolls"]["min"].get<nlohmann::json::number_integer_t>();
    max_roll = pool["rolls"]["max"].get<nlohmann::json::number_integer_t>();

    if (min_roll > max_roll)
        roll_number = min_roll;
    else
        roll_number = rand() % (max_roll - min_roll + 1) + min_roll;

    return (this->pollXPool(result, roll_number, pool["entries"]));
}

bool LootTables::pollRollsTypeBinomial(LootTablePoll &result, nlohmann::json pool)
{
    int n = 0;
    float p = 0;
    int roll_number = 0;

    n = pool["rolls"]["n"].get<nlohmann::json::number_integer_t>();
    p = pool["rolls"]["p"].get<nlohmann::json::number_float_t>();
    roll_number = n;
    
    if (n < 0)
        return (true);
    if (p < 1.0) {
        for (int i = 0; i < n; i++) {
            if ((int)(p * 100000.0) < rand() % 100000)
                roll_number--;
        }
    }

    return (this->pollXPool(result, roll_number, pool["entries"]));
}

bool LootTables::pollRollsTypeScore(LootTablePoll &result, nlohmann::json pool)
{
    /*
      TO DO:
      get number of rolls with target's score
      targets can be constants by giving a name or "this", "killer", "direct_killer" and "killer_player"
     */
    return (false);
}

bool LootTables::pollXPool(LootTablePoll &result, int x, nlohmann::json entries)
{
    if (x < 1)
        return (true);
    int max_weight = 0;

    for (const auto &entry : entries.items()) {
        if (entry.value().contains("weight") && entry.value()["weight"].is_number_integer())
            max_weight += entry.value()["weight"].get<nlohmann::json::number_integer_t>();
        else
            max_weight += 1;
    }

    for (int n = 0; n < x; n++) {
        int choice = rand() % max_weight;

        int elapsed_weight = 0;
        int position = 1;

        if (entries.at(0).contains("weight"))
            elapsed_weight += entries.at(0)["weight"].get<nlohmann::json::number_integer_t>();
        else
            elapsed_weight += 1;
        while (elapsed_weight < choice) {
            if (entries.at(position).contains("weight"))
                elapsed_weight += entries.at(position)["weight"].get<nlohmann::json::number_integer_t>();
            else
                elapsed_weight += 1;
            position++;
        }
        result.push_back(std::pair<ItemId, uint8_t>(Server::getInstance()->getItemConverter().fromItemToProtocolId(entries.at(position - 1)["name"]), 1));
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
