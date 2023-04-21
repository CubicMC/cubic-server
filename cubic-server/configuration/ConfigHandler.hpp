#ifndef CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP
#define CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP

#include <string>

#include <yaml-cpp/yaml.h>

namespace Configuration {

/**
 * @brief Handles the server configuration
 * by parsing the config.yml file
 */
class ConfigHandler {
public:
    ConfigHandler();
    const std::string &getIP() const;
    uint16_t getPort() const;
    uint32_t getMaxPlayers() const;
    const std::string &getMotd() const;
    bool getWhitelist() const;
    bool getEnforceWhitelist() const;
    void parse(const std::string &path);

private:
    YAML::Node _baseNode;
    std::string _ip;
    uint16_t _port;
    uint32_t _maxPlayers;
    std::string _motd;
    bool _whitelist;
    bool _enforceWhitelist;
};
}

#endif // CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP
