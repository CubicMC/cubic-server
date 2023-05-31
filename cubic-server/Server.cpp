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

#include "Server.hpp"
#include "World.hpp"

#include "Chat.hpp"
#include "Client.hpp"
#include "Dimension.hpp"
#include "Player.hpp"
#include "WorldGroup.hpp"
#include "command_parser/commands/Gamemode.hpp"
#include "default/DefaultWorldGroup.hpp"
#include "logging/logging.hpp"

using boost::asio::ip::tcp;

Server::Server():
    _running(false),
    // _sockfd(-1),
    _config(),
    _toSend(1024),
    _pluginManager(this)
{
    // _config.load("./config.yml");
    // _config.parse("./config.yml");
    // _config.parse(2, (const char * const *){"./CubicServer", "--nogui"});
    // _host = _config.getIP();
    // _port = _config.getPort();
    // _maxPlayer = _config.getMaxPlayers();
    // _motd = _config.getMotd();
    // _enforceWhitelist = _config.getEnforceWhitelist();

    _commands.reserve(11);
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
    _commands.emplace_back(std::make_unique<command_parser::Gamemode>());
}

Server::~Server() { }

void Server::launch(const configuration::ConfigHandler &config)
{
    this->_config = config;

    // Get plugins
    this->_pluginManager.load();

    // Initialize the global palette
    _globalPalette.initialize(std::string("blocks-") + MC_VERSION + ".json");
    LINFO("GlobalPalette initialized");

    // Initialize the item converter
    _itemConverter.initialize(std::string("registries-") + MC_VERSION + ".json");
    LINFO("ItemConverter initialized");

    // Initialize default world group
    auto defaultChat = std::make_shared<Chat>();
    _worldGroups.emplace("default", new DefaultWorldGroup(defaultChat));
    _worldGroups.at("default")->initialize();

    // TODO(huntears): Deal with this
    // Initialize default recipes
    // this->_recipes.initialize();

    this->_running = true;

    LINFO("Starting server on {}:{}", _config["ip"], _config["port"]);

    _acceptor = std::make_unique<boost::asio::ip::tcp::acceptor>(_io_context, tcp::endpoint(tcp::v4(), _config["port"].as<uint16_t>()));

    _writeThread = std::thread(&Server::_writeLoop, this);

    _doAccept();

    _io_context.run();

    // Cleanup stuff here
    this->_writeThread.join();
    std::unique_lock _(clientsMutex);
    for (auto [id, cli] : _clients) {
        cli->stop();
    }
    for (auto [id, cli] : _clients) {
        cli->getThread().join();
    }
    _clients.clear();
    using namespace std::chrono_literals;
    // Wait for 5 seconds max for all data to be out
    for (int i = 0; i < 500; i++) {
        if (_toSend.empty())
            break;
        std::this_thread::sleep_for(10ms);
    }
}

void Server::sendData(size_t clientID, std::unique_ptr<std::vector<uint8_t>> &&data) { _toSend.push({clientID, data.release()}); }

void Server::_writeLoop()
{
    using namespace std::chrono_literals;

    // TODO(huntears): Check if doing something other than a busy loop is worth it
    while (_running) {
        while (_toSend.empty()) {
            std::this_thread::sleep_for(500us);
            if (!_running)
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
            // TODO(huntears): Handle errors properly xd
            if (ec) {
                // LERROR(ec.what());
                continue;
            }
        }
        delete data.data;
    }
}

void Server::triggerClientCleanup(size_t clientID)
{
    if (clientID != (size_t) -1) {
        _clients.erase(clientID);
        return;
    }
    // boost::lockfree::queue<size_t> toDelete(_clients.size());
    // for (auto [id, cli] : _clients) {
    //     if (!cli) {
    //         _clients.erase(id);
    //     } else if (cli->isDisconnected()) {
    //         cli->getThread().join();
    //         _clients.erase(id);
    //     }
    // }
    std::erase_if(_clients, [](const auto augh) {
        if (augh.second->isDisconnected()) {
            augh.second->getThread().join();
            return true;
        }
        return false;
    });
}

void Server::addCommand(std::unique_ptr<CommandBase> command)
{
    this->_commands.emplace(this->_commands.end(), command);
}

void Server::_doAccept()
{
    // while (_running) {
    //     boost::system::error_code ec;
    //     tcp::socket socket(_io_context);

    //     _acceptor->accept(socket, ec);
    //     if (!ec) {
    //         std::shared_ptr<Client> _cli(new Client(std::move(socket), currentClientID));
    //         _clients.emplace(currentClientID++, _cli);
    //         _cli->run();
    //     }
    // }
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
            // for (auto [id, cli] : _clients) {
            //     if (!cli || cli->isDisconnected()) // Somehow they can already be freed before we get here...
            //         _clients.erase(id);
            // }
            this->_doAccept();
        }
    });
}

void Server::stop()
{
    static auto num = 0;
    LINFO("Server has received a stop command");
    this->_running = false;
    this->_acceptor->cancel();
    if (num++ >= 5) {
        exit(1); // Mash that Ctrl-C xd
    }
}

void Server::_stop()
{
    // Disconect all clients
    clientsMutex.lock();
    for (auto [_, client] : _clients)
        client->stop("Server Closed");

    // Needed because the client will not be destroyed if a reference still exists
    this->_clients.clear();

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

std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> &Server::getWorldGroups() { return _worldGroups; }

const std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> &Server::getWorldGroups() const { return _worldGroups; }
Recipes &Server::getRecipeSystem(void) noexcept { return (this->_recipes); }