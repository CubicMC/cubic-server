#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>

#include "Whitelist.hpp"

std::string u128_to_uuidString(u128 u)
{
    std::stringstream sstr;
    std::string str;

    sstr << std::hex << u.most << u.least;
    str = sstr.str();
    str.insert(8, "-");
    str.insert(12, "-");
    str.insert(16, "-");
    str.insert(20, "-");

    return str;
}

// u128 uuidString_to_u128(std::string str)
// {
//     std::stringstream sstr;
//     std::istringstream isstr;
//     u128 u;
//     uint64_t u_most;
//     uint64_t u_least;

//     str.erase(std::remove(str.begin(), str.end(), '-'), str.end());
//     isstr.str(str);
//     isstr >> std::hex >> sstr;
//     u_most = strtoull(sstr.str().substr(0, 16));
//     u_least = strtoull(sstr.str().substr(15, 16));
//     u.most = u_most;
//     u.least = u_least;

//     return u;
// }

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

    nlohmann::json Whitelist::parseWhitelist(const std::string &path)
    {
        std::ifstream whitelistFile(path);
        nlohmann::json whitelistData = nlohmann::json::parse(whitelistFile);
        whitelistFile.close();
        return whitelistData;
    }

    Whitelist::Whitelist()
    {
        _filename = "./whitelist.json";
        defaultWhitelistContent(_filename);
    }

    Whitelist::~Whitelist()
    {
    }

    void Whitelist::addPlayer(u128 uuid, std::string playerName)
    {
        nlohmann::json whitelistData = parseWhitelist(this->_filename);
        bool check = isPlayer(uuid, playerName, whitelistData).first;

        if (!check) {
            whitelistData.push_back({{"name", playerName}, {"uuid", u128_to_uuidString(uuid)}});
            std::ofstream whitelistFile(this->_filename);
            whitelistFile << std::setw(4) << whitelistData << std::endl;
            whitelistFile.close();
        }
    }

    void Whitelist::removePlayer(u128 uuid, std::string playerName)
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

    std::pair<bool, int> Whitelist::isPlayer(u128 uuid, std::string playerName, nlohmann::json whitelistData)
    {
        bool check = false;
        int playerPos = 0;
        int pos = 0;

        for (nlohmann::json::iterator it = whitelistData.begin(); it != whitelistData.end(); ++it) {
            ++pos;
            if (it.value()["uuid"] == u128_to_uuidString(uuid) || it.value()["name"] == playerName) {
                check = true;
                playerPos = pos - 1;
            }
        }

        std::pair<bool, int> p = std::make_pair(check, playerPos);
        return p;
    }
}