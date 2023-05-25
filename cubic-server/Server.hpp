#ifndef CUBICSERVER_SERVER_HPP
#define CUBICSERVER_SERVER_HPP

#include <arpa/inet.h>
#include <cstdint>
#include <memory>
#include <netinet/in.h>
#include <string>
#include <vector>

#include "configuration/ConfigHandler.hpp"
#include "whitelist/Whitelist.hpp"

#include "allCommands.hpp"

#include "protocol_id_converter/blockStates.hpp"
#include "protocol_id_converter/itemConverter.hpp"

#include "Permissions.hpp"
#include "loot_tables/LootTables.hpp"

#include "options.hpp"

#include "recipes/Recipes.hpp"

constexpr char MC_VERSION[] = "1.19.3";
constexpr uint16_t MC_PROTOCOL = 761;
constexpr uint16_t MS_PER_TICK = 50;

#define GLOBAL_PALETTE Server::getInstance()->getGlobalPalette()
#define ITEM_CONVERTER Server::getInstance()->getItemConverter()

class Client;
class WorldGroup;

class Server {
public:
    ~Server();

    void launch(const configuration::ConfigHandler &config);

    void stop();

    void reload();

    const configuration::ConfigHandler &getConfig() const { return _config; }

    const WhitelistHandling::Whitelist &getWhitelist() const { return _whitelist; }

    bool isWhitelistEnabled() const { return _config["whitelist-enabled"]; }

    bool isWhitelistEnforce() const { return _config["enforce-whitelist"]; }

    static Server *getInstance()
    {
        static Server srv;
        return &srv;
    }

    const std::vector<std::shared_ptr<Client>> &getClients() const { return _clients; }

    std::shared_ptr<WorldGroup> getWorldGroup(const std::string_view &name) { return this->_worldGroups.at(name); }

    const std::shared_ptr<WorldGroup> getWorldGroup(const std::string_view &name) const { return this->_worldGroups.at(name); }

    const std::vector<std::unique_ptr<CommandBase>> &getCommands() const { return _commands; }

    bool isRunning() const { return _running; }

    const Blocks::GlobalPalette &getGlobalPalette() const { return _globalPalette; }

    const Items::ItemConverter &getItemConverter() const { return _itemConverter; }

    std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> &getWorldGroups();

    const std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> &getWorldGroups() const;

    Recipes &getRecipeSystem(void) noexcept;

    LootTables &getLootTableSystem(void) noexcept;

    Permissions permissions;

private:
    Server();
    void _acceptLoop();
    void _stop();
    void _reloadWhitelist();
    void _reloadConfig();
    void _enforceWhitelistOnReload();

private:
    std::atomic<bool> _running;

    // Looks like it is thread-safe, if something breaks it is here
    std::vector<std::shared_ptr<Client>> _clients;

    int _sockfd;
    struct sockaddr_in6 _addr;

    configuration::ConfigHandler _config;
    WhitelistHandling::Whitelist _whitelist;
    std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> _worldGroups;
    std::vector<std::unique_ptr<CommandBase>> _commands;
    Blocks::GlobalPalette _globalPalette;
    Items::ItemConverter _itemConverter;
    Recipes _recipes;
    LootTables _lootTables;
};

#endif // CUBICSERVER_SERVER_HPP
