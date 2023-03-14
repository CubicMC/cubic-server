
#include <iostream>
#include <fstream>

#include "Operator.hpp"
#include "Server.hpp"
#include "World.hpp"

Permissions::Permissions(const std::string &filename):
    _operatorFileName(filename)
{
    // reads the operator file line per line   ! file is not a json !   ! default filename "ops.json" !
    // adds every name in the file to the operator set
    std::ifstream filestream(filename, std::ifstream::in);
    std::string line;

    if (!!filestream) {
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

    if (!!filestream) {
        for (const auto &op : this->_operatorSet) {
            filestream << op << '\n';
        }
        filestream.close();
    }
}

void Permissions::addOperator(const std::string &name)
{
    if (!this->_operatorSet.contains(name)) { // cannot find operator with this name

        // searches for the player with the right name
        Server *server = Server::getInstance();
        Player *selectedPlayer = nullptr;

        server->forEachWorldGroup(
            [&name, &selectedPlayer](WorldGroup &worldGroup)
            {
                worldGroup.forEachWorld(
                    [&name, &selectedPlayer](World &world)
                    {
                        world.forEachPlayer(
                            [&name, &selectedPlayer](Player *player)
                            {
                                if (player && player->getUsername() == name)
                                    selectedPlayer = player;
                            }
                        );
                    }
                ); 
            }
        );

        
        // adds operator to the set
        this->_operatorSet.insert(name);

        if (selectedPlayer) { // player is connected
            // set players own operator variable for rapid access
            selectedPlayer->setOperator(true);
        }
    } else { // player already an operator
    }
}

bool Permissions::removeOperator(const std::string &name)
{
    if (this->_operatorSet.contains(name)) { // cannot find operator with this name

        // searches for the player with the right name
        Server *server = Server::getInstance();
        Player *selectedPlayer = nullptr;

        server->forEachWorldGroup(
            [&name, &selectedPlayer](WorldGroup &worldGroup)
            {
                worldGroup.forEachWorld(
                    [&name, &selectedPlayer](World &world)
                    {
                        world.forEachPlayer(
                            [&name, &selectedPlayer](Player *player)
                            {
                                if (player && player->getUsername() == name)
                                    selectedPlayer = player;
                            }
                        );
                    }
                );
            }
        );

        // remove operator from the set
        this->_operatorSet.erase(name);

        if (selectedPlayer) { // operator is connected
            // set players own operator variable for rapid access
            selectedPlayer->setOperator(false);
        }
        return (true);
    } else { // already not operator
        return (false);
    }
    // returned true if operator successfuly removed, false otherwise
}

const bool Permissions::isOperator(const std::string &name) const
{
    return (this->_operatorSet.contains(name));
}