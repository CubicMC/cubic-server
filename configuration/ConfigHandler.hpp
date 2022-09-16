#ifndef CONFIG_CONFIGHANDLER_HPP
#define CONFIG_CONFIGHANDLER_HPP

#include <string>
#include <map>

namespace Configuration
{

    /**
     * @brief Handles the server configuration
     * by parsing the config.yml file
     */
    class ConfigHandler
    {
    public:
        ConfigHandler();
        ~ConfigHandler();

        std::map <std::string, std::string> getConfigFile();
        std::string getIP(std::map <std::string, std::string> fileContent);
        std::string getMotd(std::map <std::string, std::string> fileContent);
        int getPort(std::map <std::string, std::string> fileContent);
        int getMaxPlayers(std::map <std::string, std::string> fileContent);
    };
}

#endif /* CONFIG_CONFIGHANDLER_HPP */