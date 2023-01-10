#ifndef WHITELIST_HPP_
#define WHITELIST_HPP_

#include <string>

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

            void addPlayer(__int128_t uuid, std::string playerName);
            void removePlayer(__int128_t uuid, std::string playerName);

        protected:
        private:
            std::string _filename;
    };
}

#endif /* !WHITELIST_HPP_ */