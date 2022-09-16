#include "ConfigHandler.hpp"
#include <iostream>
#include <fstream>

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

std::string findKey(std::string const& s)
{
    std::string::size_type pos = s.find(':');
    std::string key;

    if (pos != std::string::npos)
    {
        key = s.substr(0, pos);
        replace(key, " - ", "");
        return key;
    }
    else
    {
        return s;
    }
}

std::map <std::string, std::string> Configuration::ConfigHandler::getConfigFile()
{
    std::fstream configFile;
    std::map <std::string, std::string> fileContent;
    std::string rawLine;
    std::string mapKey;
    std::string mapValue;

    configFile.open("../config.yml",std::ios::in);
    if (configFile.is_open()) {                                                 //checking whether the file is open
      while(getline(configFile, rawLine)) {                                     //read data from file and put it into string
         if (rawLine.find("- ip:") or rawLine.find("- motd:") or 
        rawLine.find("- max_players:") or rawLine.find("- port:")) {
             mapKey = findKey(rawLine);
             mapValue = rawLine.substr(rawLine.find(':') + 1);
             fileContent.insert(mapKey, mapValue);                              //put line data into a map
         }
      }
      configFile.close();                                                       //close the file
   }
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

int Configuration::ConfigHandler::getPort(void)
{
    int value = std::stoi(getConfigFile().find("port")->second);
    return value;
}

int Configuration::ConfigHandler::getMaxPlayers(void)
{
    int value = std::stoi(getConfigFile().find("max_players")->second);
    return value;
}