#ifndef CUBICSERVER_WHITELIST_HPP
#define CUBICSERVER_WHITELIST_HPP

#include <string>

#include <nlohmann/json.hpp>

#include "types.hpp"

namespace WhitelistHandling {

/**
 * @brief Handles the server whitelist
 * by parsing the whitelist.json file
 */
class Whitelist {
public:
    Whitelist();
    ~Whitelist();

    void addPlayer(u128 uuid, std::string playerName);
    void removePlayer(u128 uuid, std::string playerName);
    std::pair<bool, int> isPlayerWhitelisted(u128 uuid, std::string playerName) const;

    const std::string &getFilename() const { return _filename; }

protected:
    void _parseWhitelist(const std::string &path);

private:
    std::string _filename;
    nlohmann::json _whitelistData;
};
}

#endif // CUBICSERVER_WHITELIST_HPP
