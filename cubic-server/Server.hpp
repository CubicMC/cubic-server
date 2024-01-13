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
#include "nbt.hpp"
#include "protocol/ServerPackets.hpp"

#include "WorldGroup.hpp"
#include "configuration/ConfigHandler.hpp"
#include "registry/Registry.hpp"
#include "whitelist/Whitelist.hpp"

#include "allCommands.hpp"

#include "protocol_id_converter/blockDataConverter.hpp"
#include "protocol_id_converter/blockIdConverter.hpp"
#include "protocol_id_converter/itemConverter.hpp"
#include "protocol_id_converter/soundEventConverter.hpp"

#include "Permissions.hpp"
#include "loot_tables/LootTables.hpp"

#include "options.hpp"
#include "scoreboard/ScoreboardSystem.hpp"

#include "recipes/Recipes.hpp"

#include "PluginManager.hpp"

#include "registry/MasterRegistry.hpp"

#if PROMETHEUS_SUPPORT == 1
#include "PrometheusExporter.hpp"
#endif

constexpr char MC_VERSION[] = "1.19.3";
constexpr char MC_VERSION_BRANDING[] = "CubicServer 1.19.3";
constexpr uint16_t MC_PROTOCOL = 761;
constexpr uint16_t MS_PER_TICK = 50;

#define GLOBAL_PALETTE Server::getInstance()->getGlobalPalette()
#define ITEM_CONVERTER Server::getInstance()->getItemConverter()
#define SOUND_EVENT_CONVERTER Server::getInstance()->getSoundEventConverter()
#define BLOCK_DATA_CONVERTER Server::getInstance()->getBlockDataConverter()
#define CONFIG Server::getInstance()->getConfig()
#define RECIPES Server::getInstance()->getRecipeSystem()

#if PROMETHEUS_SUPPORT == 1
#define PROMETHEUS Server::getInstance()->getPrometheusExporter()
#define PEXP(method)                                   \
    if (Server::getInstance()->prometheusExporterOn()) \
        Server::getInstance()->getPrometheusExporter().method();
#define PEXPP(method, ...)                             \
    if (Server::getInstance()->prometheusExporterOn()) \
        Server::getInstance()->getPrometheusExporter().method(__VA_ARGS__);
#else
#define PEXP(method)
#define PEXPP(method, ...)
#endif

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

    NODISCARD const std::unordered_map<size_t, std::shared_ptr<Client>> &getClients() const { return _clients; }
    NODISCARD std::shared_ptr<const WorldGroup> getWorldGroup(const std::string_view &name) const { return this->_worldGroups.at(name); }
    NODISCARD const std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> &getWorldGroups() const { return _worldGroups; }
    NODISCARD const std::vector<std::unique_ptr<CommandBase>> &getCommands() const { return _commands; }
    NODISCARD bool isRunning() const { return _running; }
    NODISCARD Blocks::GlobalPalette &getGlobalPalette() { return _globalPalette; }
    NODISCARD const Blocks::GlobalPalette &getGlobalPalette() const { return _globalPalette; }
    NODISCARD const Items::ItemConverter &getItemConverter() const { return _itemConverter; }
    NODISCARD const SoundEvents::SoundEventConverter &getSoundEventConverter() const { return _soundEventConverter; }
    NODISCARD const Blocks::BlockDataConverter &getBlockDataConverter() const { return _blockDataConverter; }

    NODISCARD registry::MasterRegistry &getRegistry() noexcept { return _registry; }
    NODISCARD std::shared_ptr<WorldGroup> getWorldGroup(const std::string_view &name) { return this->_worldGroups.at(name); }
    NODISCARD std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> &getWorldGroups() { return _worldGroups; }
    NODISCARD PluginManager &getPluginManager() noexcept { return _pluginManager; }
    NODISCARD Recipes &getRecipeSystem() noexcept { return _recipes; }
    NODISCARD ScoreboardSystem &getScoreboardSystem() { return _scoreboardSystem; }
    NODISCARD LootTables &getLootTableSystem() noexcept { return _lootTables; }
    NODISCARD RSAEncryptionHandler &getPrivateKey() { return _rsaKey; }

    // Network
public:
    void sendData(size_t clientID, std::unique_ptr<std::vector<uint8_t>> &&data);
    void triggerClientCleanup(size_t clientID = -1);
    void addCommand(std::unique_ptr<CommandBase> command);

    Permissions permissions;

private:
    Server();
    void _stop();
    void _reloadWhitelist();
    void _reloadConfig();
    void _enforceWhitelistOnReload();
    void _generateKeyPair();
    void _doAccept();
    void _writeLoop();

    // Random mutex
public:
    mutable std::mutex clientsMutex;

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
    SoundEvents::SoundEventConverter _soundEventConverter;
    Blocks::BlockDataConverter _blockDataConverter;
    Recipes _recipes;
    PluginManager _pluginManager;
    LootTables _lootTables;
    ScoreboardSystem _scoreboardSystem;

    registry::MasterRegistry _registry;

    // new boost stuff
    boost::asio::io_context _io_context;
    std::unique_ptr<boost::asio::ip::tcp::acceptor> _acceptor;

    boost::lockfree::queue<OutboundClientData> _toSend;
    std::thread _writeThread;

    RSAEncryptionHandler _rsaKey;

#if PROMETHEUS_SUPPORT == 1
    std::unique_ptr<PrometheusExporter> _prometheusExporter;
    bool _prometheusExporterOn;

public:
    NODISCARD inline const PrometheusExporter &getPrometheusExporter() const { return *_prometheusExporter; }
    NODISCARD inline PrometheusExporter &getPrometheusExporter() { return *_prometheusExporter; }
    bool prometheusExporterOn() const noexcept { return _prometheusExporterOn; }
#endif

public:
    NODISCARD inline bool isCompressed() const { return _config["compression"].as<bool>(); }
};

#endif // CUBICSERVER_SERVER_HPP
