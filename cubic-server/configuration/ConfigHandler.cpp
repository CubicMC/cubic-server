#include "ConfigHandler.hpp"

#include "logging/Logger.hpp"
#include <filesystem>

namespace Configuration {
constexpr std::string_view fileContent = "network:\n\
  ip: 0.0.0.0\n\
  port: 25565\n\
\n\
general:\n\
  max_players: 20\n\
  motd: A Cubic Server\n\
  whitelist: false\n\
  enforce-whitelist: false\
";

static void defaultConfigContent(const std::string &path)
{
    if (!std::filesystem::exists(path)) {
        std::ofstream configFile(path);
        configFile << fileContent << std::endl;
        configFile.close();
    }
}

ConfigHandler::ConfigHandler() { }

void ConfigHandler::parse(const std::string &path)
{
    YAML::Node config;
    defaultConfigContent(path);
    try {
        _baseNode = YAML::LoadFile(path);
        _ip = _baseNode["network"]["ip"].as<std::string>();
        _port = _baseNode["network"]["port"].as<uint16_t>();
        _maxPlayers = _baseNode["general"]["max_players"].as<uint32_t>();
        _motd = _baseNode["general"]["motd"].as<std::string>();
        _whitelist = _baseNode["general"]["whitelist"].as<bool>();
        _enforceWhitelist = _baseNode["general"]["enforce-whitelist"].as<bool>();
    } catch (const std::exception &e) {
        LERROR("config parsing failed : " << e.what());
        throw std::runtime_error("config parsing failed");
    }
}

const std::string &ConfigHandler::getIP() const { return _ip; }

uint16_t ConfigHandler::getPort() const { return _port; }

uint32_t ConfigHandler::getMaxPlayers() const { return _maxPlayers; }

const std::string &ConfigHandler::getMotd() const { return _motd; }

bool ConfigHandler::getEnforceWhitelist() const { return _enforceWhitelist; }

bool ConfigHandler::getWhitelist() const { return _whitelist; }
}
