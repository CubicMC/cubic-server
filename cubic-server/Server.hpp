#ifndef CUBICSERVER_SERVER_HPP
#define CUBICSERVER_SERVER_HPP

#include <arpa/inet.h>
#include <array>
#include <boost/asio.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/lockfree/queue.hpp>
#include <cstdint>
#include <memory>
#include <netinet/in.h>
#include <string>
#include <unordered_map>
#include <vector>

#include "Client.hpp"
#include "RSAEncryptionHandler.hpp"
#include "command_parser/commands/Gamemode.hpp"
#include "command_parser/commands/Help.hpp"
#include "protocol/ServerPackets.hpp"

#include "WorldGroup.hpp"
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
#define CONFIG Server::getInstance()->getConfig()

class Client;
class WorldGroup;

struct OutboundClientData {
    size_t clientID;
    std::vector<uint8_t> *data;
};

class Server {
public:
    friend int main(int argc, char **argv);

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

    // const boost::container::flat_map<size_t, std::shared_ptr<Client>> &getClients() const { return _clients; }

    const std::unordered_map<size_t, std::shared_ptr<Client>> &getClients() const { return _clients; }
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

    void sendData(size_t clientID, std::unique_ptr<std::vector<uint8_t>> &&data);
    void triggerClientCleanup(size_t clientID = -1);

    Permissions permissions;

    NODISCARD inline RSAEncryptionHandler &getPrivateKey() { return _rsaKey; }

private:
    Server();
    void _stop();
    void _reloadWhitelist();
    void _reloadConfig();
    void _enforceWhitelistOnReload();
    void _generateKeyPair();

public:
    std::mutex clientsMutex;

private:
    std::atomic<bool> _running;
    std::atomic<bool> _hasTerminated;

    // Looks like it is thread-safe, if something breaks it is here
    // std::vector<std::shared_ptr<Client>> _clients;
    // boost::container::flat_map<size_t, std::shared_ptr<Client>> _clients;
    std::unordered_map<size_t, std::shared_ptr<Client>> _clients;

    configuration::ConfigHandler _config;
    WhitelistHandling::Whitelist _whitelist;
    std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> _worldGroups;
    std::vector<std::unique_ptr<CommandBase>> _commands;
    Blocks::GlobalPalette _globalPalette;
    Items::ItemConverter _itemConverter;
    Recipes _recipes;
    LootTables _lootTables;

    // new boost stuff

    void _doAccept();

    boost::asio::io_context _io_context;
    std::unique_ptr<boost::asio::ip::tcp::acceptor> _acceptor;

    boost::lockfree::queue<OutboundClientData> _toSend;
    void _writeLoop();
    std::thread _writeThread;

    RSAEncryptionHandler _rsaKey;
};

#endif // CUBICSERVER_SERVER_HPP
