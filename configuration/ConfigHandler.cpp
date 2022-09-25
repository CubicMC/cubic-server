#include "ConfigHandler.hpp"
#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>

Configuration::ConfigHandler::ConfigHandler(std::string filePath)
{
    this->getConfigFile(filePath);
}

void Configuration::ConfigHandler::parseFile(YAML::Node base_node)
{
    std::vector<YAML::Node> nodes_list;
    int i = 0;

    for (YAML::const_iterator it = base_node.begin(); it != base_node.end(); ++it, ++i) {
        nodes_list.push_back(it->first);
        const std::string buff = it->first.as<std::string>();
        this->_configFile.insert(std::pair<std::string, YAML::Node>(buff, base_node[nodes_list[i]]));
        if (base_node[nodes_list.back()].size() > 1) {
            for (YAML::const_iterator itbis = base_node[nodes_list[i]].begin(); itbis != base_node[nodes_list[i]].end(); ++itbis) {
                YAML::Node node = itbis->first;
                const std::string temp = itbis->first.as<std::string>();
                this->_configFile.insert(std::pair<std::string, YAML::Node>(temp, base_node[nodes_list[i]][node]));
                parseFile(base_node[nodes_list[i]][node]);
            }
        } else {
            const std::string temp = it->first.as<std::string>();
            this->_configFile.insert(std::pair<std::string, YAML::Node>(temp, base_node[nodes_list[i]]));
        }
    }
}

void Configuration::ConfigHandler::getConfigFile(std::string configFile)
{
    try
    {
        YAML::Node config = YAML::LoadFile(configFile);
        parseFile(config);
    }
    catch(const YAML::BadFile& e)
    {
        std::cerr << e.what() << '\n';
    }
}

YAML::Node Configuration::ConfigHandler::getNode(std::string node_name)
{
    try
    {
        if (this->_configFile.count(node_name)) {
            std::unordered_map<std::string, YAML::Node>::const_iterator got = this->_configFile.find(node_name);
            if (got != this->_configFile.end()) {
                return got->second;
            } else {
                throw std::invalid_argument("This node does not exist.");
            }
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
}