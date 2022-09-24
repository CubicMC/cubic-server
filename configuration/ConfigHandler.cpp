#include "ConfigHandler.hpp"
#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>

Configuration::ConfigHandler::ConfigHandler(std::string filePath)
{
    this->getConfigFile(filePath);
}

void Configuration::ConfigHandler::getConfigFile(std::string configFile)
{
    YAML::Node config;
    
    try
    {
        config = YAML::LoadFile(configFile);
    }
    catch(const YAML::BadFile& e)
    {
        std::cerr << e.what() << '\n';
    }

    // don't know how to generalize this
    const std::string ip = config["network"]["ip"].as<std::string>();
    const int port = config["network"]["port"].as<int>();
    const int max_players = config["general"]["max_players"].as<int>();
    const std::string motd = config["general"]["motd"].as<std::string>();

    this->_configFile.insert({"ip", ip});
    this->_configFile.insert({"port", std::to_string(port)});
    this->_configFile.insert({"max_players", std::to_string(max_players)});
    this->_configFile.insert({"motd", motd});
}

std::string Configuration::ConfigHandler::getNode(std::string node_name)
{
    std::string value;

    try
    {
        if (this->_configFile.find(node_name) != this->_configFile.end()) {
            value = this->_configFile.find(node_name)->second;
            return value;
        } else {
            throw invalid_argument("This node does not exist.");
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
        return nullptr;
    }
}