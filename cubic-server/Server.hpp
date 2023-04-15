#ifndef F43D56DD_C750_470F_A7C9_27CE21D37FC3
#define F43D56DD_C750_470F_A7C9_27CE21D37FC3

#include <arpa/inet.h>
#include <cstdint>
#include <memory>
#include <netinet/in.h>
#include <string>
#include <vector>

#include "protocol/ServerPackets.hpp"

#include "WorldGroup.hpp"
#include "configuration/ConfigHandler.hpp"
#include "logging/Logger.hpp"
#include "whitelist/Whitelist.hpp"

#include "allCommands.hpp"
#include "command_parser/commands/CommandBase.hpp"

#include "protocol_id_converter/blockStates.hpp"
#include "protocol_id_converter/itemConverter.hpp"

#include "Permissions.hpp"

#ifndef MC_VERSION
#define MC_VERSION "1.19.3"
#endif

#ifndef MC_PROTOCOL
#define MC_PROTOCOL 761
#endif

#ifndef MS_PER_TICK
#define MS_PER_TICK 50
#endif

#define UNUSED __attribute__((unused))

#define GLOBAL_PALETTE Server::getInstance()->getGlobalPalette()

class Client;

class Server {
public:
    ~Server();

    void launch();

    void stop();

    void reload();

    const Configuration::ConfigHandler &getConfig() const { return _config; }

    const WhitelistHandling::Whitelist &getWhitelist() const { return _whitelist; }

    bool isWhitelistEnabled() const { return _whitelistEnabled; }

    bool getEnforceWhitelist() const { return _enforceWhitelist; }

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
    std::unordered_map<std::string_view, std::shared_ptr<WorldGroup>> _worldGroups;
    // clang-format off
    std::vector<std::unique_ptr<CommandBase>> _commands;
    // clang-format on
    Blocks::GlobalPalette _globalPalette;
    Items::ItemConverter _itemConverter;
};

#endif /* F43D56DD_C750_470F_A7C9_27CE21D37FC3 */
