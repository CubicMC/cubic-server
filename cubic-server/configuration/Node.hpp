#ifndef CONFIG_NODE_HPP
#define CONFIG_NODE_HPP

#include <string>
#include <filesystem>
#include <yaml-cpp/yaml.h>
#include <unordered_map>
#include "conversion.hpp"
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
    virtual ChildNode &at(const std::string &key) = 0;
    virtual const ChildNode &at(const std::string &key) const = 0;
    template<typename... Args>
    const ChildNode &at(const std::string &key, Args... args) const
    { return at(key).at(std::forward<Args>(args)...); }
    template<typename... Args>
    ChildNode &at(const std::string &key, Args... args)
    { return at(key).at(std::forward<Args>(args)...); }
    virtual std::string get() const = 0;
    virtual std::vector<std::string> getArray() const = 0;
    virtual bool has(const std::string &key) const = 0;
    virtual ChildNode &add(const std::string &key) = 0;
    virtual ChildNode &set(const std::string &value) = 0;
    virtual ChildNode &set(const std::vector<std::string> &values) = 0;
    template<typename U>
    ChildNode &set(const std::vector<U> &values);
    ChildNode &set(const auto &value)
    { return set(_details::Convertor<std::string>()(value)); }
    virtual bool isArray() const = 0;
    bool operator==(const _Node &other) const
    { return this->_impl == other._impl; }
    const ChildNode &operator[](const auto &key) const
    { return at(_details::Convertor<std::string>()(key)); }

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
    virtual Node &at(const std::string &key) override;
    virtual std::string get() const override;
    virtual std::vector<std::string> getArray() const override;
    virtual bool has(const std::string &key) const override;
    virtual Node &add(const std::string &key) override;
    virtual Node &set(const std::string &value) override;
    virtual Node &set(const std::vector<std::string> &values) override;
    virtual bool isArray() const override;

private:
    void initSequence();
    void initMap();
};

} // namespace configuration

template<typename C, typename T>
template<typename U>
C &configuration::_details::_Node<C, T>::set(const std::vector<U> &values)
{
    std::vector<std::string> convertedValues;
    Convertor<std::string> convertor;
    for (const auto &value: values)
        convertedValues.push_back(convertor(value));
    return set(convertedValues);
}

#endif // CONFIG_NODE_HPP
