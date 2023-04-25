#include <fstream>
#include <iostream>
#include <memory>

#include "Permissions.hpp"
#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "Dimension.hpp"

Permissions::Permissions(const std::string &filename):
    _operatorFileName(filename)
{
    // reads the operator file line per line   ! file is not a json !   ! default filename "ops.json" !
    // adds every name in the file to the operator set
    std::ifstream filestream(filename, std::ifstream::in);
    std::string line;

    if (filestream.is_open()) {
        while (!filestream.eof()) {
            std::getline(filestream, line);
            this->_operatorSet.insert(line);
        }
        filestream.close();
    }
}

Permissions::~Permissions()
{
    // writes every operator name in the operator file
    std::ofstream filestream(this->_operatorFileName);

    if (filestream.is_open()) {
        for (const auto &op : this->_operatorSet) {
            filestream << op << '\n';
        }
        filestream.close();
    }
}

void Permissions::addOperator(const std::string &name)
{
    if (this->_operatorSet.contains(name)) // find an operator with this name, exit
        return;

    // searches for the player with the right name
    Server *server = Server::getInstance();
    std::shared_ptr<Player> selectedPlayer = nullptr;

    for (auto [_, worldGroup] : server->getWorldGroups()) {
        for (auto [_, world] : worldGroup->getWorlds()) {
            for (auto [_, dim] : world->getDimensions()) {
                for (auto player : dim->getPlayers()) {
                    if (player->getUsername() == name)
                        selectedPlayer.swap(player);
                }
            }
        }
    }

    // adds operator to the set
    this->_operatorSet.insert(name);

    if (selectedPlayer) { // player is connected
        // set players own operator variable for rapid access
        selectedPlayer->setOperator(true);
    }
}

bool Permissions::removeOperator(const std::string &name)
{
    if (!this->_operatorSet.contains(name)) // cannot find operator with this name, exit
        return false;

    // searches for the player with the right name
    Server *server = Server::getInstance();

    std::shared_ptr<Player> selectedPlayer = nullptr;

    for (auto [_, worldGroup] : server->getWorldGroups()) {
        for (auto [_, world] : worldGroup->getWorlds()) {
            for (auto [_, dim] : world->getDimensions()) {
                for (auto player : dim->getPlayers()) {
                    if (player->getUsername() == name)
                        selectedPlayer.swap(player);
                }
            }
        }
    }

    // remove operator from the set
    this->_operatorSet.erase(name);

    if (selectedPlayer) { // operator is connected
        // set players own operator variable for rapid access
        selectedPlayer->setOperator(false);
    }
    return true;
    // returned true if operator successfuly removed, false otherwise
}

bool Permissions::isOperator(const std::string &name) const { return this->_operatorSet.contains(name); }
