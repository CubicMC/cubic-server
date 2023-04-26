#ifndef CUBICSERVER_PERMISSIONS_HPP
#define CUBICSERVER_PERMISSIONS_HPP

#include <string>
#include <unordered_set>

class Permissions {
public:
    Permissions(const std::string &filename = "ops.json");
    ~Permissions();

    void addOperator(const std::string &name);
    bool removeOperator(const std::string &name);
    bool isOperator(const std::string &name) const;

private:
    std::string _operatorFileName;
    std::unordered_set<std::string> _operatorSet;
};

#endif /* CUBICSERVER_PERMISSIONS_HPP */
