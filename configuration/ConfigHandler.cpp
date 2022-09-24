#include "ConfigHandler.hpp"
#include <iostream>
#include <fstream>
#include "../yaml-cpp/include/yaml-cpp/yaml.h"

Configuration::ConfigHandler::ConfigHandler(std::string filePath)
{
    this->getConfigFile(filePath);
}

void Configuration::ConfigHandler::getConfigFile(std::string configFile)
{
    try
    {
        YAML::Node config = YAML::LoadFile(configFile);

        const std::string ip = config["network"]["ip"].as<std::string>();
        const int port = config["network"]["port"].as<int>();
        const int max_players = config["general"]["max_players"].as<int>();
        const std::string motd = config["general"]["motd"].as<std::string>();

        this->_configFile.insert({"ip", ip});
        this->_configFile.insert({"port", std::to_string(port)});
        this->_configFile.insert({"max_players", std::to_string(max_players)});
        this->_configFile.insert({"motd", motd});
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

std::string Configuration::ConfigHandler::getNode(std::string node_name)
{
    try
    {
        std::string value = this->_configFile.find(node_name)->second;
        return value;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}