#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/address_v6.hpp>
#include <boost/asio/ip/v6_only.hpp>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <mutex>
#include <netdb.h>
#include <poll.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

#include <mbedtls/rsa.h>

#include "PrometheusExporter.hpp"
#include "Server.hpp"
#include "World.hpp"

#include "Chat.hpp"
#include "Client.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "WorldGroup.hpp"
#include "command_parser/commands/Gamemode.hpp"
#include "command_parser/commands/InventoryDump.hpp"
#include "command_parser/commands/SaveRegion.hpp"
#include "command_parser/commands/Teleport.hpp"
#include "command_parser/commands/Tps.hpp"
#include "default/DefaultWorldGroup.hpp"
#include "logging/logging.hpp"
#include "registry/Biome.hpp"
#include "registry/Chat.hpp"
#include "registry/Dimension.hpp"
#include "registry/MasterRegistry.hpp"
#include "scoreboard/ScoreboardSystem.hpp"

using boost::asio::ip::tcp;

Server::Server():
    _running(false),
    _config(),
    _pluginManager(this),
    _toSend(1024)
{
    _commands.emplace_back(std::make_unique<command_parser::Help>());
    _commands.emplace_back(std::make_unique<command_parser::QuestionMark>());
    _commands.emplace_back(std::make_unique<command_parser::Stop>());
    _commands.emplace_back(std::make_unique<command_parser::Seed>());
    _commands.emplace_back(std::make_unique<command_parser::DumpChunk>());
    _commands.emplace_back(std::make_unique<command_parser::Log>());
    _commands.emplace_back(std::make_unique<command_parser::Op>());
    _commands.emplace_back(std::make_unique<command_parser::Deop>());
    _commands.emplace_back(std::make_unique<command_parser::Reload>());
    _commands.emplace_back(std::make_unique<command_parser::Time>());
    _commands.emplace_back(std::make_unique<command_parser::Objectives>());
    _commands.emplace_back(std::make_unique<command_parser::AddObjective>());
    _commands.emplace_back(std::make_unique<command_parser::SetScore>());
    _commands.emplace_back(std::make_unique<command_parser::RemoveScore>());
    _commands.emplace_back(std::make_unique<command_parser::DisplayObjective>());
    _commands.emplace_back(std::make_unique<command_parser::RemoveObjective>());
    _commands.emplace_back(std::make_unique<command_parser::Teams>());
    _commands.emplace_back(std::make_unique<command_parser::AddTeam>());
    _commands.emplace_back(std::make_unique<command_parser::ModifyTeam>());
    _commands.emplace_back(std::make_unique<command_parser::JoinTeam>());
    _commands.emplace_back(std::make_unique<command_parser::LeaveTeam>());
    _commands.emplace_back(std::make_unique<command_parser::RemoveTeam>());
    _commands.emplace_back(std::make_unique<command_parser::Loot>());
    _commands.emplace_back(std::make_unique<command_parser::Gamemode>());
    _commands.emplace_back(std::make_unique<command_parser::InventoryDump>());
    _commands.emplace_back(std::make_unique<command_parser::Tp>());
    _commands.emplace_back(std::make_unique<command_parser::Teleport>());
    _commands.emplace_back(std::make_unique<command_parser::Tps>());
    _commands.emplace_back(std::make_unique<command_parser::MSPT>());
    _commands.emplace_back(std::make_unique<command_parser::Title>());
    _commands.emplace_back(std::make_unique<command_parser::Subtitle>());
    _commands.emplace_back(std::make_unique<command_parser::TitleTimes>());
    _commands.emplace_back(std::make_unique<command_parser::Armor>());
    _commands.emplace_back(std::make_unique<command_parser::SaveRegion>());
}

Server::~Server() { }

void Server::launch(const configuration::ConfigHandler &config)
{
    this->_config = config;

    _rsaKey.generate();
    auto &dimensionRegistry = _registry.addRegistry<registry::Dimension>();
    auto &biomeRegistry = _registry.addRegistry<registry::Biome>();
    auto &chatRegistry = _registry.addRegistry<registry::Chat>();

    registry::setupDefaultsDimension(dimensionRegistry);
    registry::setupDefaultsBiome(biomeRegistry);
    registry::setupDefaultsChat(chatRegistry);

    // Initialize the global palette
    if (_globalPalette.initialize(std::string("blocks-") + MC_VERSION + ".json"))
        LINFO("GlobalPalette initialized");
    else {
        LFATAL("GlobalPalette failed to initialize");
        exit(1);
    }

    // Initialize the item converter
    if (_itemConverter.initialize(std::string("registries-") + MC_VERSION + ".json"))
        LINFO("ItemConverter initialized");
    else {
        LFATAL("ItemConverter failed to initialize");
        exit(1);
    }

    // Initialize the sound event converter
    if (_soundEventConverter.initialize(std::string("registries-") + MC_VERSION + ".json"))
        LINFO("SoundEventConverter initialized");
    else {
        LFATAL("SoundEventConverter failed to initialize");
        exit(1);
    }

    // Initialize the block data converter
    if (_blockDataConverter.initialize(std::string("blocks-data-") + MC_VERSION + ".json"))
        LINFO("BlockDataConverter initialized");
    else {
        LFATAL("BlockDataConverter failed to initialize");
        exit(1);
    }

    // Initialize loot tables
    _lootTables.initialize();

    // Initialize recipes
    _recipes.initialize();

    // Initialize default world group
    auto defaultChat = std::make_shared<Chat>();
    _worldGroups.emplace("default", new DefaultWorldGroup(defaultChat));

    // TODO(huntears): Deal with this
    // Initialize default recipes
    // this->_recipes.initialize();

    // Initialize scoreboard system
    this->_scoreboardSystem.initialize();

    // Get plugins
    this->_pluginManager.load();

    _worldGroups.at("default")->initialize();
    _registry.initialize();

    this->_running = true;

    boost::asio::ip::tcp::resolver resolver(_io_context);
    auto it = resolver.resolve(boost::asio::ip::tcp::resolver::query(_config["ip"].as<std::string>(), std::to_string(_config["port"].as<uint16_t>())));
    boost::asio::ip::address addr = it->endpoint().address();

    // This force ipv6 for any and loopback
    // If the user want to use ipv6, he should provide an ipv6 address
    if (addr == boost::asio::ip::address_v4::any())
        addr = boost::asio::ip::address_v6::any();
    else if (addr == boost::asio::ip::address_v4::loopback())
        addr = boost::asio::ip::address_v6::loopback();

    auto endpoint = tcp::endpoint(addr, _config["port"].as<uint16_t>());

    _acceptor = std::make_unique<boost::asio::ip::tcp::acceptor>(_io_context, endpoint.protocol());

    _acceptor->set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    if (addr.is_v6())
        _acceptor->set_option(boost::asio::ip::v6_only(false));

    _acceptor->bind(endpoint);
    _acceptor->listen();

    _writeThread = std::thread(&Server::_writeLoop, this);

#if PROMETHEUS_SUPPORT == 1
    if (CONFIG["monitoring-prometheus-enable"].as<bool>()) {
        _prometheusExporter =
            std::make_unique<PrometheusExporter>(CONFIG["monitoring-prometheus-ip"].as<std::string>() + std::string(":") + CONFIG["monitoring-prometheus-port"].as<std::string>());
        _prometheusExporter->registerMetrics();
        _prometheusExporterOn = true;
    }
#endif

    _doAccept();

    _io_context.run();

    // Cleanup stuff here
    this->_stop();
}

void Server::sendData(size_t clientID, std::unique_ptr<std::vector<uint8_t>> &&data) { _toSend.push({clientID, data.release()}); }

void Server::_writeLoop()
{
    using namespace std::chrono_literals;

    // TODO(huntears): Check if doing something other than a busy loop is worth it
    while (!_hasTerminated || !_toSend.empty()) {
        while (_toSend.empty()) {
            std::this_thread::sleep_for(500us);
            if (_hasTerminated)
                return;
        }

        OutboundClientData data = {0, nullptr};
        if (!_toSend.pop(data))
            continue;
        {
            std::unique_lock _(clientsMutex);
            triggerClientCleanup();
            if (!_clients.contains(data.clientID)) {
                delete data.data;
                continue;
            }
            auto client = _clients.at(data.clientID);
            if (client->isDisconnected()) {
                triggerClientCleanup(client->getID());
                delete data.data;
                continue;
            }
            boost::system::error_code ec;
            boost::asio::write(client->getSocket(), boost::asio::buffer(data.data->data(), data.data->size()), ec);
            PEXP(incrementPacketTxCounter);
            // TODO(huntears): Handle errors properly xd
            if (ec) {
                client->disconnect("Network error");
                delete data.data;
                LERROR(ec.what());
                continue;
            }
        }
        delete data.data;
    }
}

void Server::triggerClientCleanup(size_t clientID)
{
    if (clientID != (size_t) -1) {
        if (_clients.at(clientID)->getThread().joinable())
            _clients[clientID]->getThread().join();
        _clients.erase(clientID);
        return;
    }
    std::erase_if(_clients, [](const auto augh) {
        if (augh.second->isDisconnected()) {
            if (augh.second->getThread().joinable())
                augh.second->getThread().join();
            return true;
        }
        return false;
    });
}

void Server::addCommand(std::unique_ptr<CommandBase> command) { this->_commands.emplace_back(std::move(command)); }

void Server::_doAccept()
{
    tcp::socket *socket = new tcp::socket(_io_context);

    _acceptor->async_accept(*socket, [socket, this](const boost::system::error_code &error) {
        static size_t currentClientID = 0;
        if (!error) {
            std::shared_ptr<Client> _cli(new Client(std::move(*socket), currentClientID));
            _clients.emplace(currentClientID++, _cli);
            _cli->run();
        }
        delete socket;
        if (this->_running) {
            this->_doAccept();
        }
    });
}

void Server::stop()
{
    static auto num = 0;
    LINFO("Server has received a stop command");
    this->_running = false;
    if (this->_acceptor)
        this->_acceptor->cancel();
    if (num++ >= 5) {
        exit(1); // Mash that Ctrl-C xd
    }
}

void Server::_stop()
{
    // Disconect all clients
    {
        std::lock_guard _(clientsMutex);
        for (auto [_, client] : _clients)
            client->disconnect("Server Closed");

        for (auto [_, client] : _clients) {
            if (client->getThread().joinable())
                client->getThread().join();
        }
    }

    using namespace std::chrono_literals;
    // Wait for 5 seconds max for all data to be out
    for (int i = 0; i < 500; i++) {
        if (_toSend.empty())
            break;
        std::this_thread::sleep_for(10ms);
    }

    _hasTerminated = true;
    if (this->_writeThread.joinable())
        this->_writeThread.join();

    while (!_toSend.empty()) {
        OutboundClientData data = {0, nullptr};
        _toSend.pop(data);
        if (data.data)
            delete data.data;
    }

    _clients.clear();

    for (auto &[name, worldGroup] : _worldGroups) {
        worldGroup->stop();
        worldGroup.reset();
    }
    // if (this->_sockfd != -1)
    //     close(this->_sockfd);
    LINFO("Server stopped");
}

/*
**  Reloads the config if no error within the new file
*/
void Server::_reloadConfig()
{
    try {
        _config.load("./config.yml");
    } catch (const configuration::ConfigurationError &e) {
        LERROR(e.what());
        return;
    }
}

/*
**  Reloads the whitelist if no error within the new file
*/
void Server::_reloadWhitelist()
{
    try {
        if (isWhitelistEnabled()) {
            WhitelistHandling::Whitelist whitelistReloaded = WhitelistHandling::Whitelist();
            _whitelist = whitelistReloaded;
        }
    } catch (const std::exception &e) {
        LERROR(e.what());
    }
}

/*
**  Reloads the server. Used in the /reload command.
**  More details in *Reload.hpp*.
*/
void Server::reload()
{
    _reloadConfig();
    _reloadWhitelist();
    _enforceWhitelistOnReload();
    /* Reload datapacks + plugins */
}

/*
**  If the server gets a /reload, players not on the whitelist
**  must be kicked out from the server if enforce-whitelist is
**   true & the whitelist is in effect
*/
void Server::_enforceWhitelistOnReload()
{
    if (!isWhitelistEnabled() || !isWhitelistEnforce())
        return;
    for (auto [_, worldGroup] : _worldGroups) {
        for (auto [_, world] : worldGroup->getWorlds()) {
            for (auto [_, dim] : world->getDimensions()) {
                for (auto player : dim->getPlayers()) {
                    if (!_whitelist.isPlayerWhitelisted(player->getUuid(), player->getUsername()).first) {
                        player->disconnect("You are not whitelisted on this server.");
                    }
                }
            }
        }
    }
}
