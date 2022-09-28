#ifndef CONFIG_CONFIGHANDLER_HPP
#define CONFIG_CONFIGHANDLER_HPP

#include <string>
#include <map>
#include <yaml-cpp/yaml.h>

namespace Configuration
{

    /**
     * @brief Handles the server configuration
     * by parsing the config.yml file
     */
    class ConfigHandler
    {
    public:
        ConfigHandler(std::string);

        YAML::Node getNode(std::string);
    private:
        std::unordered_map<std::string, YAML::Node> _configFile;
        void getConfigFile(std::string);
        void parseFile(YAML::Node);
    };
}

#endif /* CONFIG_CONFIGHANDLER_HPP */