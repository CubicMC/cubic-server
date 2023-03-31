#ifndef CUBIC_SERVER_LOOTTABLES_HPP
#define CUBIC_SERVER_LOOTTABLES_HPP

#include "nlohmann/json.hpp"

#include "types.hpp"

#include <unordered_map>
#include <vector>
#include <exception>
#include <filesystem>

using LootTablePoll = std::vector<std::pair<ItemId, uint8_t>>;

class NoLootTableException : public std::exception
{
public:
    NoLootTableException() noexcept;
    ~NoLootTableException() = default;
    const char *what() const noexcept;
};

class LootTables
{
public:
    LootTables(const std::string &path = "assets/loot_tables");
    ~LootTables() = default;

    bool importTableFolder(const std::string &_namespace, const std::string &path);
    void deleteTable(const std::string &_namespace, const std::string &table);
    void deleteNamespace(const std::string &_namespace);
    void clearAll(void);

    bool exists(const std::string &_namespace, const std::string &table);

    bool poll(LootTablePoll &result, const std::string &_namespace, const std::string &table);

    void snitchTables(void) const;

private:
    bool pollRollsTypeConstant(LootTablePoll &result, nlohmann::json pool);
    bool pollRollsTypeUniform(LootTablePoll &result, nlohmann::json pool);
    bool pollRollsTypeBinomial(LootTablePoll &result, nlohmann::json pool);
    bool pollRollsTypeScore(LootTablePoll &result, nlohmann::json pool);

    bool pollXPool(LootTablePoll &result, int x, nlohmann::json entries);

    // stores all tables; call "minecraft:chests/end_city_treasure" with _lootTables["minecraft"]["chests/end_city_treasure"]
    std::unordered_map<std::string, std::unordered_map<std::string, nlohmann::json>> _lootTables;
};

#endif //CUBIC_SERVER_LOOTTABLES_HPP
