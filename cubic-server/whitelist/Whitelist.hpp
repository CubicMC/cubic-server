#ifndef WHITELIST_HPP_
#define WHITELIST_HPP_

#include <string>

#include "types.hpp"
#include "nlohmann/json.hpp"

namespace WhitelistHandling
{

    /**
     * @brief Handles the server whitelist
     * by parsing the whitelist.json file
     */
    class Whitelist
    {
        public:
            Whitelist();
            ~Whitelist();

            nlohmann::json parseWhitelist(const std::string &path);
            void addPlayer(u128 uuid, std::string playerName);
            void removePlayer(u128 uuid, std::string playerName);
            std::pair<bool, int> isPlayer(u128 uuid, std::string playerName, nlohmann::json whitelistData);

            const std::string &getFilename() const {
                return _filename;
            }

        protected:
        private:
            std::string _filename;
    };
}

#endif /* !WHITELIST_HPP_ */