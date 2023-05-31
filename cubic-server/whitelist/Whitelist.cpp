#include "Whitelist.hpp"
#include "logging/logging.hpp"
#include <fstream>

std::string u128ToUuidString(u128 u)
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

namespace WhitelistHandling {
static void defaultWhitelistContent(const std::string &path)
{
    if (!std::filesystem::exists(path)) {
        std::ofstream whitelistFile(path);
        whitelistFile << nlohmann::json::array() << std::endl;
        whitelistFile.close();
    }
}

void Whitelist::_parseWhitelist(const std::string &path)
{
    std::ifstream whitelistFile(path);
    try {
        _whitelistData = nlohmann::json::parse(whitelistFile);
    } catch (const std::exception &e) {
        LERROR("whitelist parsing failed : {}", e.what());
        throw std::runtime_error("whitelist parsing failed");
    }
    whitelistFile.close();
}

Whitelist::Whitelist()
{
    _filename = "./whitelist.json";
    defaultWhitelistContent(_filename);
    _parseWhitelist(_filename);
}

Whitelist::~Whitelist() { }

void Whitelist::addPlayer(u128 uuid, std::string playerName)
{
    bool check = isPlayerWhitelisted(uuid, playerName).first;

    if (!check) {
        _whitelistData.push_back({{"name", playerName}, {"uuid", u128ToUuidString(uuid)}});
        std::ofstream whitelistFile(this->_filename);
        whitelistFile << std::setw(4) << _whitelistData << std::endl;
        whitelistFile.close();
    }
}

void Whitelist::removePlayer(u128 uuid, std::string playerName)
{
    bool check = isPlayerWhitelisted(uuid, playerName).first;
    int playerPos = isPlayerWhitelisted(uuid, playerName).second;

    if (check) {
        _whitelistData.erase(playerPos);
        std::ofstream whitelistFile(this->_filename);
        whitelistFile << std::setw(4) << _whitelistData << std::endl;
        whitelistFile.close();
    }
}

std::pair<bool, int> Whitelist::isPlayerWhitelisted(u128 uuid, std::string playerName) const
{
    bool check = false;
    int playerPos = 0;
    int pos = 0;

    for (auto it = _whitelistData.begin(); it != _whitelistData.end(); ++it) {
        ++pos;
        if (it.value()["uuid"] == u128ToUuidString(uuid) || it.value()["name"] == playerName) {
            check = true;
            playerPos = pos - 1;
        }
    }

    std::pair<bool, int> p = std::make_pair(check, playerPos);
    return p;
}
}
