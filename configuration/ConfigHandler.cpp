#include "ConfigHandler.hpp"
#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

Configuration::ConfigHandler::ConfigHandler(std::string filePath)
{
    this->getConfigFile(filePath);
}

Configuration::ConfigHandler::~ConfigHandler(){}

void Configuration::ConfigHandler::getConfigFile(std::string configFile)
{
    YAML::Node config = YAML::LoadFile(configFile);

    const std::string ip = config["network"]["ip"].as<std::string>();
    const int port = config["network"]["port"].as<int>();
    const int max_players = config["general"]["max_players"].as<int>();
    const std::string motd = config["general"]["motd"].as<std::string>();

    this->_configFile.insert(std::pair<std::string, std::string>("ip", ip));
    this->_configFile.insert(std::pair<std::string, std::string>("port", std::to_string(port)));
    this->_configFile.insert(std::pair<std::string, std::string>("max_players", std::to_string(max_players)));
    this->_configFile.insert(std::pair<std::string, std::string>("motd", motd));
}

std::string Configuration::ConfigHandler::getIP(void)
{
    std::string value = this->_configFile.find("ip")->second;
    return value;
}

std::string Configuration::ConfigHandler::getMotd(void)
{
    std::string value = this->_configFile.find("motd")->second;
    return value;
}

std::string Configuration::ConfigHandler::getPort(void)
{
    std::string value = this->_configFile.find("port")->second;
    return value;
}

std::string Configuration::ConfigHandler::getMaxPlayers(void)
{
    std::string value = this->_configFile.find("max_players")->second;
    return value;
}