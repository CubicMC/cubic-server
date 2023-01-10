#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>

#include "Whitelist.hpp"
#include "nlohmann/json.hpp"

namespace WhitelistHandling
{
    static void defaultWhitelistContent(const std::string &path)
    {
        if (!std::filesystem::exists(path)) {
            std::ofstream whitelistFile(path);
            whitelistFile << nlohmann::json::array() << std::endl;
            whitelistFile.close();
        }
    }

    nlohmann::json parseWhitelist(const std::string &path)
    {
        std::ifstream whitelistFile(path);
        nlohmann::json whitelistData = nlohmann::json::parse(whitelistFile);
        whitelistFile.close();
        return whitelistData;
    }

    std::pair<bool, int> isPlayer(__int128_t uuid, std::string playerName, nlohmann::json whitelistData)
    {
        bool check = false;
        int playerPos = 0;
        int pos = 0;

        for (nlohmann::json::iterator it = whitelistData.begin(); it != whitelistData.end(); ++it) {
            ++pos;
            if (it.value()["uuid"] == uuid && it.value()["name"] == playerName) {
                check = true;
                playerPos = pos - 1;
            }
        }

        std::pair<bool, int> p = std::make_pair(check, playerPos);
        return p;
    }

    Whitelist::Whitelist()
    {
        _filename = "./whitelist.json";
        defaultWhitelistContent(_filename);
    }

    Whitelist::~Whitelist()
    {
    }

    void Whitelist::addPlayer(__int128_t uuid, std::string playerName)
    {
        nlohmann::json whitelistData = parseWhitelist(this->_filename);
        bool check = isPlayer(uuid, playerName, whitelistData).first;

        if (!check) {
            whitelistData.push_back({{"name", playerName}, {"uuid", uuid}});
            std::ofstream whitelistFile(this->_filename);
            whitelistFile << std::setw(4) << whitelistData << std::endl;
            whitelistFile.close();
        }
    }

    void Whitelist::removePlayer(__int128_t uuid, std::string playerName)
    {
        nlohmann::json whitelistData = parseWhitelist(this->_filename);
        bool check = isPlayer(uuid, playerName, whitelistData).first;
        int playerPos = isPlayer(uuid, playerName, whitelistData).second;

        if (check) {
            whitelistData.erase(playerPos);
            std::ofstream whitelistFile(this->_filename);
            whitelistFile << std::setw(4) << whitelistData << std::endl;
            whitelistFile.close();
        }
    }
}