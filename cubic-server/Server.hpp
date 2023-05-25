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

#include "PluginManager.hpp"

constexpr char MC_VERSION[] = "1.19.3";

constexpr uint16_t MC_PROTOCOL = 761;

constexpr uint16_t MS_PER_TICK = 50;

#define GLOBAL_PALETTE Server::getInstance()->getGlobalPalette()

class Client;
class WorldGroup;

class Server {
public:
    ~Server();

    void launch();

    void stop();

    void reload();

    const Configuration::ConfigHandler &getConfig() const;

    const WhitelistHandling::Whitelist &getWhitelist() const;

    const bool isWhitelistEnabled() const;

    const bool getEnforceWhitelist() const;

    static Server *getInstance();

    const std::vector<std::shared_ptr<Client>> &getClients() const;

    const WorldGroup *getWorldGroup(const std::string_view &name) const;

    const std::vector<CommandBase *> &getCommands() const;

    bool isRunning() const;

    const Blocks::GlobalPalette &getGlobalPalette() const;

    const Items::ItemConverter &getItemConverter() const;

    PluginManager &getPluginManager();

    void forEachWorldGroup(std::function<void(WorldGroup &)> callback);
    void forEachWorldGroupIf(std::function<void(WorldGroup &)> callback, std::function<bool(const WorldGroup &)> predicate);

    Permissions permissions;

private:
    Server();
    void _acceptLoop();
    void _stop();
    void _downloadFile(const std::string &url, const std::string &path);
    void _reloadWhitelist();
    void _reloadConfig();
    void _enforceWhitelistOnReload();

private:
    std::string _host;
    uint16_t _port;
    uint32_t _maxPlayer;
    std::string _motd;
    bool _whitelistEnabled;
    bool _enforceWhitelist;
    std::atomic<bool> _running;

    // Looks like it is thread-safe, if something breaks it is here
    std::vector<std::shared_ptr<Client>> _clients;

    int _sockfd;
    struct sockaddr_in6 _addr;

    Configuration::ConfigHandler _config;
    WhitelistHandling::Whitelist _whitelist;
    std::unordered_map<std::string_view, WorldGroup *> _worldGroups;
    PluginManager _pluginManager;
    // clang-format off
    std::vector<CommandBase *> _commands = {
        new command_parser::Help,
        new command_parser::QuestionMark,
        new command_parser::Stop,
        new command_parser::Seed,
        new command_parser::DumpChunk,
        new command_parser::Log,
        new command_parser::Op,
        new command_parser::Deop,
        new command_parser::Reload,
        new command_parser::Time,
    };
    // clang-format on
    Blocks::GlobalPalette _globalPalette;
    Items::ItemConverter _itemConverter;
};

#endif // CUBICSERVER_SERVER_HPP
