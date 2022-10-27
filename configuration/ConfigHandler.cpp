#include "ConfigHandler.hpp"
#include <iostream>
#include <yaml-cpp/yaml.h>

namespace Configuration
{
    ConfigHandler::ConfigHandler() {}

    YAML::Node ConfigHandler::_seekNode(const std::initializer_list<std::string> &queries) const
    {
        auto current_node = _baseNode;

        for (auto const &query : queries) {
//            if (!current_node.IsMap())
//                throw YAML::BadFile("Queries could not resolve a yaml node, node is not map");
            bool found_next_node = false;
            printf("---------------\n");
            printf("%s\n", query.c_str());
            for (auto node : current_node) {
                printf("%s\n", node.first.as<std::string>().c_str());
                if (node.first.as<std::string>() == query) {
                    current_node = node.second;
                    found_next_node = true;
                    break;
                }
            }
            if (!found_next_node)
                throw YAML::BadFile("Queries could not resolve a yaml node");
        }
        printf("Returned\n");
        return current_node;
    }

    void ConfigHandler::parse(const std::string &path) {
        YAML::Node config;
        try {
            _baseNode = YAML::LoadFile(path);
            _ip = _seekNode({"network", "ip"}).as<std::string>();
            _port = _seekNode({"network", "port"}).as<uint16_t>();
            _maxPlayers = _seekNode({"general", "max_players"}).as<uint32_t>();
            _motd = _seekNode({"general", "motd"}).as<std::string>();
        }
        catch (const YAML::BadFile &e) {
            std::cerr << "Config parsing failed, exiting now!" << std::endl; // TODO: Use the logger once the new version is ready
            std::cerr << e.what() << std::endl;
            exit(1); // TODO: Use an exception
        }
    }

    const std::string &ConfigHandler::getIP() const
    {
        return _ip;
    }

    uint16_t ConfigHandler::getPort() const
    {
        return _port;
    }

    uint32_t ConfigHandler::getMaxPlayers() const
    {
        return _maxPlayers;
    }

    const std::string &ConfigHandler::getMotd() const
    {
        return _motd;
    }
}