
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Operator.hpp"
#include "Server.hpp"

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
            this->_operatorList.push_back(
                {
                    {0, 0},
                    line,
                    4,
                    true
                }
            );
        }
        filestream.close();
    }
}

Permissions::~Permissions()
{
    std::ofstream filestream(this->_operatorFileName);

    if (!!filestream) {
        for (Operator op : this->_operatorList) {
            filestream << op.getName();
        }
        filestream.close();
    }
}

void Permissions::addOperator(const u128 &uuid, const std::string &name)
{
    this->_operatorList.push_back(
        {
            uuid,
            name,
            this->_defaultOperatorLevel,
            this->_minimalSpawnProtectionBypassLevel <= this->_defaultOperatorLevel
        }
    );
    Server *server = Server::getInstance();
}

bool Permissions::removeOperator(const std::string &name)
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), name);

    if (it != this->_operatorList.end()) {
        this->_operatorList.erase(it);
        return (true);
    } else {
        return (false);
    }
}

const bool Permissions::getOperatorInfos(const u128 &uuid, Operator &op) const
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), uuid);

    if (it != this->_operatorList.end()) {
        op = *it;
        return (true);
    } else {
        return (false);
    }
}

const bool Permissions::getOperatorInfos(const std::string &name, Operator &op) const
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), name);

    if (it != this->_operatorList.end()) {
        op = *it;
        return (true);
    } else {
        return (false);
    }
}

const bool Permissions::isOperator(const u128 &uuid) const
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), uuid);

    return (it != this->_operatorList.end());
}

const bool Permissions::isOperator(const std::string &name) const
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), name);

    return (it != this->_operatorList.end());
}

const uint8_t Permissions::getOperatorLevel(const u128 &uuid) const
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), uuid);

    if (it != this->_operatorList.end())
        return (it->getLevel());
    else
        return (0);
}

const uint8_t Permissions::getOperatorLevel(const std::string &name) const
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), name);

    if (it != this->_operatorList.end())
        return (it->getLevel());
    else
        return (0);
}

const bool Permissions::canBypassSpawnProtection(const u128 &uuid) const
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), uuid);

    if (it != this->_operatorList.end())
        return (it->getBypassSpawnProtection());
    else
        return (false);
}

const bool Permissions::canBypassSpawnProtection(const std::string &name) const
{
    std::vector<Operator>::const_iterator it = std::find(this->_operatorList.begin(), this->_operatorList.end(), name);

    if (it != this->_operatorList.end())
        return (it->getBypassSpawnProtection());
    else
        return (false);
}

