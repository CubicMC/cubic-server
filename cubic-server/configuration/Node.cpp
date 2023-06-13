#include "Node.hpp"
#include <fstream>
#include <iostream>

configuration::Node::Node(const YAML::Node &rootNode):
    _Node(rootNode)
{
    if (!this->_impl.IsDefined())
        throw ConfigurationError("Node is not defined");

    if (this->_impl.IsScalar() || this->_impl.IsNull())
        return;

    if (this->_impl.IsSequence())
        this->initSequence();
    else
        this->initMap();
}

void configuration::Node::initSequence()
{
    for (size_t i = 0; i < this->_impl.size(); i++)
        _children.emplace(std::make_pair(std::to_string(i), Node(this->_impl[i])));
}

void configuration::Node::initMap()
{
    for (auto node : this->_impl)
        _children.emplace(std::make_pair(node.first.as<std::string>(), Node(node.second)));
}

void configuration::Node::load(const std::filesystem::path &path)
{
    try {
        this->_impl = YAML::LoadFile(path);
    } catch (const YAML::BadFile &) {
        throw configuration::BadFile("Unable to open file '" + path.string() + "'");
    }

    if (this->_impl.IsScalar() || this->_impl.IsNull())
        return;

    for (auto node : this->_impl)
        _children.emplace(std::make_pair(node.first.as<std::string>(), Node(node.second)));
}

void configuration::Node::save(const std::filesystem::path &path)
{
    if (std::filesystem::exists(path))
        throw BadFile("File '" + path.string() + "' already exists ! If you want to overwrite it, delete it first.");

    std::filesystem::create_directories(path.parent_path());

    auto file = std::ofstream(path, std::ios::out & std::ios::trunc);

    if (!file.is_open())
        throw configuration::BadFile("Unable to open file '" + path.string() + "'");

    file << _impl << std::endl;
}

configuration::Node &configuration::Node::at(const std::string &key)
{
    if (_children.find(key) == _children.end())
        throw configuration::ConfigurationError("Key '" + key + "' not found");
    return _children.at(key);
}

const configuration::Node &configuration::Node::at(const std::string &key) const
{
    if (_children.find(key) == _children.end())
        throw configuration::ConfigurationError("Key '" + key + "' not found");
    return _children.at(key);
}

bool configuration::Node::has(const std::string &key) const { return _impl[key].IsDefined(); }
bool configuration::Node::isArray() const { return _impl.IsDefined() && _impl.IsSequence(); }
bool configuration::Node::isScalar() const { return _impl.IsDefined() && (_impl.IsScalar() || _impl.IsNull()); }
bool configuration::Node::isMap() const { return _impl.IsDefined() && _impl.IsMap(); }
bool configuration::Node::isDefined() const { return _impl.IsDefined(); }

configuration::Node &configuration::Node::add(const std::string &key)
{
    this->_impl[key] = YAML::Node();
    _children.emplace(std::make_pair(key, Node(this->_impl[key])));
    return _children.at(key);
}

configuration::Node &configuration::Node::set(const std::string &value)
{
    this->_impl = value;
    return *this;
}

configuration::Node &configuration::Node::set(const std::vector<std::string> &values)
{
    for (const auto &value : values)
        this->_impl.push_back(value);
    return *this;
}

std::string configuration::Node::get() const
{
    if (!_impl.IsScalar() && !_impl.IsNull())
        throw configuration::ConfigurationError("Node type is not scalar");
    return _impl.as<std::string>();
}

std::vector<std::string> configuration::Node::getArray() const
{
    std::vector<std::string> array;

    if (!_impl.IsSequence())
        throw configuration::ConfigurationError("Invalid configuration type");

    for (const auto &value : _impl)
        array.push_back(value.as<std::string>());
    return array;
}
