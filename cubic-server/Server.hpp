#ifndef F43D56DD_C750_470F_A7C9_27CE21D37FC3
#define F43D56DD_C750_470F_A7C9_27CE21D37FC3

#include <cstdint>
#include <string>
#include <vector>
#include <arpa/inet.h>
#include <memory>
#include <netinet/in.h>

#include "Client.hpp"
#include "protocol/ServerPackets.hpp"

#include "configuration/ConfigHandler.hpp"
#include "whitelist/Whitelist.hpp"
#include "logging/Logger.hpp"
#include "WorldGroup.hpp"

#include "command_parser/commands/CommandBase.hpp"
#include "allCommands.hpp"

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

#define GLOBAL_PALETTE Server::getInstance()->getGlobalPalette()

class Server
{
public:
    ~Server();

    void launch();

    void stop();

    void enforceWhitelistOnReload();

    const Configuration::ConfigHandler &getConfig() const {
        return _config;
    }

    const WhitelistHandling::Whitelist &getWhitelist() const {
        return _whitelist;
    }

    const bool isWhitelistEnabled() const {
        return _whitelistEnabled;
    }

    const bool getEnforceWhitelist() const {
        return _enforceWhitelist;
    }

    static Server *getInstance() {
        static Server srv;
        return &srv;
    }

    const std::vector<std::shared_ptr<Client>> &getClients() const {
        return _clients;
    }

    const WorldGroup *getWorldGroup(const std::string_view &name) const {
        return this->_worldGroups.at(name);
    }

    const std::vector<CommandBase *> &getCommands() const {
        return _commands;
    }

    bool isRunning() const {
        return _running;
    }

    const Blocks::GlobalPalette &getGlobalPalette() const {
        return _globalPalette;
    }

    const Items::ItemConverter &getItemConverter() const {
        return _itemConverter;
    }

    void forEachWorldGroup(std::function<void(WorldGroup &)> callback);
    void forEachWorldGroupIf(std::function<void(WorldGroup &)> callback, std::function<bool(const WorldGroup &)> predicate);

    Permissions permissions;

private:
    Server();
    void _acceptLoop();
    void _stop();
    void _downloadFile(const std::string &url, const std::string &path);

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
    std::vector<CommandBase *> _commands = {
        new command_parser::Help,
        new command_parser::QuestionMark,
        new command_parser::Stop,
        new command_parser::Seed,
        new command_parser::DumpChunk,
        new command_parser::Log,
        new command_parser::Op,
        new command_parser::Deop,
    };
    Blocks::GlobalPalette _globalPalette;
    Items::ItemConverter _itemConverter;
};

#endif /* F43D56DD_C750_470F_A7C9_27CE21D37FC3 */
