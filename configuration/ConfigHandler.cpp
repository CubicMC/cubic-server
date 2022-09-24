#include "ConfigHandler.hpp"
#include <iostream>
#include <fstream>
#include "yaml-cpp/yaml.h"

Configuration::ConfigHandler::ConfigHandler(){}
Configuration::ConfigHandler::~ConfigHandler(){}

std::map <std::string, std::string> Configuration::ConfigHandler::getConfigFile()
{
    std::fstream configFile;
    std::map <std::string, std::string> fileContent;
    YAML::Node config = YAML::LoadFile("../config.yml");

    const std::string ip = config["network"]["ip"].as<std::string>();
    const int port = config["network"]["port"].as<int>();
    const int max_players = config["general"]["max_players"].as<int>();
    const std::string motd = config["general"]["motd"].as<std::string>();

    fileContent.insert(std::pair<std::string, std::string>("ip", ip));
    fileContent.insert(std::pair<std::string, std::string>("port", std::to_string(port)));
    fileContent.insert(std::pair<std::string, std::string>("max_players", std::to_string(max_players)));
    fileContent.insert(std::pair<std::string, std::string>("motd", motd));

   return fileContent;
}

std::string Configuration::ConfigHandler::getIP(void)
{
    std::string value = getConfigFile().find("ip")->second;
    return value;
}

std::string Configuration::ConfigHandler::getMotd(void)
{
    std::string value = getConfigFile().find("motd")->second;
    return value;
}

std::string Configuration::ConfigHandler::getPort(void)
{
    std::string value = getConfigFile().find("port")->second;
    return value;
}

std::string Configuration::ConfigHandler::getMaxPlayers(void)
{
    std::string value = getConfigFile().find("max_players")->second;
    return value;
}