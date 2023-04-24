#include "Node.hpp"
#include <fstream>
#include <iostream>

configuration::Node::Node(const YAML::Node &rootNode):
    _Node(rootNode)
{
    if (this->_impl.IsScalar())
        return;

    for (auto node: rootNode)
        _children.emplace(std::make_pair(node.first.as<std::string>(), Node(node.second)));
    // for (YAML::iterator it = this->_impl.begin(); it != this->_impl.end(); it++)
    //     _children.emplace(std::make_pair(it->first, Node(it->second)));
}

void configuration::Node::load(const std::filesystem::path &path)
{
    this->_impl = YAML::LoadFile(path);

    if (this->_impl.IsScalar())
        return;

    for (auto node: this->_impl)
        _children.emplace(std::make_pair(node.first.as<std::string>(), Node(node.second)));

    // for (YAML::iterator it = this->_impl.begin(); it != this->_impl.end(); it++)
    //     _children.emplace(std::make_pair(it->first, Node(it->second)));
}

void configuration::Node::save(const std::filesystem::path &path)
{
    YAML::Emitter out;

    if (!std::filesystem::exists(path))
        std::filesystem::create_directories(path.parent_path());

    auto file = std::ofstream(path, std::ios::out & std::ios::trunc);

    if (!file.is_open())
        throw configuration::ConfigurationError("Unable to open file '" + path.string() + "'");

    out << _impl;
    file << out.c_str();
}

const configuration::Node &configuration::Node::at(const std::string &key) const
{
    if (_children.find(key) == _children.end()) {
        // if (!_impl[key])
            throw configuration::ConfigurationError("Key '" + key + "' not found");
        // _children.emplace(std::make_pair(key, Node(_impl[key])));
    }
    return _children.at(key);
}

// template<typename... Args>
// configuration::_details::Node<T> &configuration::_details::Node<T>::at(const std::string &key, Args... args) const
// { return at(key).at(args...); }

bool configuration::Node::has(const std::string &key) const
{ return _impl[key].IsDefined(); }

bool configuration::Node::isArray() const
{ return _impl.IsSequence(); }

std::string configuration::Node::get() const
{
    if (!_impl.IsScalar())
        throw configuration::ConfigurationError("Invalid configuration type");
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
