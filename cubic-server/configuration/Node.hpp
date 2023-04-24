#ifndef CONFIG_NODE_HPP
#define CONFIG_NODE_HPP

#include <string>
#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <unordered_map>
#include "errors.hpp"
#include "details.hpp"

namespace configuration {
namespace _details {
template<typename ChildNode, typename T>
class _Node : public _Impl<T> {
public:
    _Node() = default;
    _Node(const T &impl):
        _Impl<T>(impl) {}
    virtual ~_Node() {};

    virtual void load(const std::filesystem::path &path) = 0;
    virtual void save(const std::filesystem::path &path) = 0;
    virtual const ChildNode &at(const std::string &key) const = 0;
    template<typename... Args>
    const ChildNode &at(const std::string &key, Args... args) const
    { return at(key).at(std::forward<Args>(args)...); }
    virtual std::string get() const = 0;
    virtual std::vector<std::string> getArray() const = 0;
    virtual bool has(const std::string &key) const = 0;
    virtual bool isArray() const = 0;
    bool operator==(const _Node &other) const
    { return this->_impl == other._impl; }

protected:
    std::unordered_map<std::string, ChildNode> _children;
};
} // namespace _details

// Yaml forever ? Naah
class Node : public _details::_Node<Node, YAML::Node> {
public:
    Node() = default;
    Node(const YAML::Node &node);
    ~Node() = default;

    virtual void load(const std::filesystem::path &path) override;
    virtual void save(const std::filesystem::path &path) override;
    virtual const Node &at(const std::string &key) const override;
    virtual std::string get() const override;
    virtual std::vector<std::string> getArray() const override;
    virtual bool has(const std::string &key) const override;
    virtual bool isArray() const override;
};

} // namespace configuration

#endif // CONFIG_NODE_HPP
