#include "Block.hpp"
#include <regex>

world_storage::Block::Block():
    name("minecraft:air")
{
}

world_storage::Block::Block(const std::string &name, std::unordered_map<std::string, std::string> properties):
    name(name),
    properties(properties)
{
    static auto regName = std::regex("([a-z0-9\\.\\-_]+:)?([a-z0-9\\.\\-_/]+)(?:\\[(?:([a-zA-Z_]+=[a-zA-Z0-9_]+),?)*\\])?");

    if (!std::regex_match(name, regName))
        throw std::runtime_error("Invalid block name");

    auto namePos = name.find(":");
    auto propertiesPos = name.find("[");
    this->name = (namePos != std::string::npos ? name.substr(0, propertiesPos) : "minecraft:" + name.substr(0, propertiesPos));

    if (!properties.empty()) {
        this->properties = properties;
        return;
    }

    if (propertiesPos == std::string::npos)
        return;

    auto propertiesStr = name.substr(propertiesPos + 1, name.size() - propertiesPos - 2);
    while (!propertiesStr.empty()) {
        auto propertyPos = propertiesStr.find(",");
        auto property = propertiesStr.substr(0, propertyPos);
        auto propertyKeyPos = property.find("=");
        auto propertyKey = property.substr(0, propertyKeyPos);
        auto propertyValuePos = property.find(",");
        auto propertyValue = property.substr(propertyKeyPos + 1, propertyValuePos);
        this->properties[propertyKey] = propertyValue;
        if (propertyPos == std::string::npos)
            break;
        propertiesStr = propertiesStr.substr(propertyPos + 1);
    }
}

std::string world_storage::Block::toString() const
{
    if (this->properties.empty())
        return this->name;

    auto identifier = this->name;
    identifier += "[";
    for (auto &[key, value] : this->properties) {
        identifier += key;
        identifier += "=";
        identifier += value;
        identifier += ",";
    }
    identifier.pop_back();
    identifier += "]";
    return identifier;
}
