
#include <iostream>
#include <fstream>
#include <algorithm>

#include "Operator.hpp"
#include "Server.hpp"
#include "World.hpp"

Operator::Operator(const u128 &uuid, const std::string name, const uint8_t level, const bool bypassSpawnProtection):
    _uuid(uuid),
    _name(name),
    _level(level),
    _bypassSpawnProtection(bypassSpawnProtection)
{
}

const u128 &Operator::getUuid() const
{
    return (this->_uuid);
}

const std::string &Operator::getName() const
{
    return (this->_name);
}

const uint8_t &Operator::getLevel() const
{
    return (this->_level);
}

const bool &Operator::getBypassSpawnProtection() const
{
    return (this->_bypassSpawnProtection);
}

Operator &Operator::operator=(const Operator &other)
{
    this->_uuid = other.getUuid();
    this->_name = other.getName();
    this->_level = other.getLevel();
    this->_bypassSpawnProtection = other.getBypassSpawnProtection();
    return (*this);
}

const bool Operator::operator==(const u128 &uuid) const
{
    return (this->_uuid.least == uuid.least && this->_uuid.most == uuid.most);
}

const bool Operator::operator==(const std::string &name) const
{
    return (this->_name == name);
}

const bool Operator::operator>(const Operator &op) const
{
    return (this->_level > op.getLevel());
}

const bool Operator::operator>=(const Operator &op) const
{
    return (this->_level >= op.getLevel());
}

const bool Operator::operator<(const Operator &op) const
{
    return (this->_level < op.getLevel());
}

const bool Operator::operator<=(const Operator &op) const
{
    return (this->_level <= op.getLevel());
}

Permissions::Permissions(const std::string &filename):
    _operatorFileName(filename)
{
    this->_defaultOperatorLevel = 4;
    this->_minimalSpawnProtectionBypassLevel = 4;

    std::ifstream filestream(filename, std::ifstream::in);
    std::string line;

    if (!!filestream) {
        while (!filestream.eof()) {
            std::getline(filestream, line);
            this->_operators.emplace(
                line,
                Operator(
                    {0, 0},
                    line,
                    4,
                    true
                )
            );
        }
        filestream.close();
    }
}

Permissions::~Permissions()
{
    std::ofstream filestream(this->_operatorFileName);

    if (!!filestream) {
        for (const auto &op : this->_operators) {
            filestream << op.first;
        }
        filestream.close();
    }
}

void Permissions::addOperator(const std::string &name)
{
    if (this->_operators.find(name) == this->_operators.end()) { // cannot find operator with this name
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

        if (selectedPlayer == nullptr) {
            this->_operators.emplace(
                name,
                Operator(
                    {0, 0},
                    name,
                    this->_defaultOperatorLevel,
                    this->_minimalSpawnProtectionBypassLevel <= this->_defaultOperatorLevel
                )
            );
        } else {
            this->_operators.emplace(
                name,
                Operator(
                    selectedPlayer->getUuid(),
                    selectedPlayer->getUsername(),
                    this->_defaultOperatorLevel,
                    this->_minimalSpawnProtectionBypassLevel <= this->_defaultOperatorLevel
                )
            );
            selectedPlayer->setOperatorLevel(this->_defaultOperatorLevel);
        }
    } else { // already op
    }
}

bool Permissions::removeOperator(const std::string &name)
{
    if (this->_operators.find(name) != this->_operators.end()) { // cannot find operator with this name

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

        this->_operators.erase(name); // erase from operator map
        if (selectedPlayer) { // if operator is connected
            selectedPlayer->setOperatorLevel(0);
            selectedPlayer->setSpawnProtectionBypass(0 >= this->_minimalSpawnProtectionBypassLevel);
        }
        return (true);
    } else { // already not operator
        return (false);
    }
}

const bool Permissions::getOperatorInfos(const std::string &name, Operator &op) const
{
    auto it = this->_operators.find(name);

    if (it != this->_operators.end()) {
        op = it->second;
        return (true);
    } else {
        return (false);
    }
}

const bool Permissions::isOperator(const std::string &name) const
{
    return (this->_operators.find(name) != this->_operators.end());
}

const uint8_t Permissions::getOperatorLevel(const std::string &name) const
{
    auto it = this->_operators.find(name);

    if (it != this->_operators.end())
        return (it->second.getLevel());
    else
        return (0);
}

const bool Permissions::canBypassSpawnProtection(const std::string &name) const
{
    auto it = this->_operators.find(name);

    if (it != this->_operators.end())
        return (it->second.getBypassSpawnProtection());
    else
        return (false);
}
