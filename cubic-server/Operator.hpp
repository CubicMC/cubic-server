#ifndef CUBICSERVER_OPERATOR_HPP
#define CUBICSERVER_OPERATOR_HPP

#include <unordered_map>
#include <vector>

#include "types.hpp"

class Operator
{
public:
    Operator(const u128 &uuid, const std::string name, const uint8_t level, const bool bypassSpawnProtection);
    ~Operator() = default;

    const u128 &getUuid() const;
    const std::string &getName() const;
    const uint8_t &getLevel() const;
    const bool &getBypassSpawnProtection() const;

    Operator &operator=(const Operator &op);
    const bool operator==(const u128 &uuid) const;
    const bool operator==(const std::string &name) const;
    const bool operator>(const Operator &op) const;
    const bool operator>=(const Operator &op) const;
    const bool operator<(const Operator &op) const;
    const bool operator<=(const Operator &op) const;

private:
    u128 _uuid;
    std::string _name;
    uint8_t _level;
    bool _bypassSpawnProtection;
};

class Permissions
{
public:
    Permissions(const std::string &filename = "ops.json");
    ~Permissions();
    
    void addOperator(const std::string &name);
    bool removeOperator(const std::string &name);
    const bool getOperatorInfos(const std::string &name, Operator &op) const;
    const bool isOperator(const std::string &name) const;
    const uint8_t getOperatorLevel(const std::string &name) const;
    const bool canBypassSpawnProtection(const std::string &name) const;

private:
    std::string _operatorFileName;
    uint8_t _defaultOperatorLevel;
    uint8_t _minimalSpawnProtectionBypassLevel;
    std::vector<Operator> _operatorList;
    std::unordered_map<std::string, Operator> _operators;
};

#endif /* CUBICSERVER_OPERATOR_HPP */
