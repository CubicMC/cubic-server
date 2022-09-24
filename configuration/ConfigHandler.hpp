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
        ConfigHandler(std::string);
        ~ConfigHandler();

        std::string getIP(void);
        std::string getMotd(void);
        std::string getPort(void);
        std::string getMaxPlayers(void);

    private:
        std::map <std::string, std::string> _configFile;
        void getConfigFile(std::string);
    };
}

#endif /* CONFIG_CONFIGHANDLER_HPP */