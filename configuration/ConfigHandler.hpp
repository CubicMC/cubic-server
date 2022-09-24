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

        std::map <std::string, std::string> getConfigFile(void);
        std::string getIP(void);
        std::string getMotd(void);
        std::string getPort(void);
        std::string getMaxPlayers(void);
    };
}

#endif /* CONFIG_CONFIGHANDLER_HPP */