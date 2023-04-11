#ifndef CONFIG_CONFIGHANDLER_HPP
#define CONFIG_CONFIGHANDLER_HPP

#include <string>
#include <map>
#include <optional>
#include <yaml-cpp/yaml.h>
#include <argparse/argparse.hpp>
#include "logging/Logger.hpp"
#include "exceptions.hpp"
#include "concept.hpp"

#define BIT(x) (1 << x)

namespace configuration
{

DEFINE_EXCEPTION(InvalidArguments);
DEFINE_EXCEPTION(InvalidArgumentParameter);

DEFINE_EXCEPTION(MissingRequiredConfigurationKey);
DEFINE_EXCEPTION(InvalidConfigurationType);
DEFINE_EXCEPTION(InvalidConfigurationFile);
DEFINE_EXCEPTION(MissingConfigurationFile);

enum class Type {
    Any = 0,
    String = BIT(0),
    Integer = BIT(1),
    Float = BIT(2),
    Boolean = BIT(3),
    Array = BIT(4),
    Map = BIT(5),
    Null = BIT(6)
};

/**
 * @brief This class is only usefull if one day we want to change the way we handle arguments
 */
class ArgumentsHolder
{
public:
    typedef argparse::ArgumentParser Parser;

public:
    ArgumentsHolder() = default;

    void init();
    void parseArgs(int argc, char **argv);

    bool has(const std::string &argument) const;

    template<typename T>
    T operator[](const std::string &argument) const;

    template<typename T>
    T get(const std::string &argument) const;

    const Parser &impl() const;

private:
    argparse::ArgumentParser _parser;
};

std::ostream &operator<<(std::ostream &os, const ArgumentsHolder &parser);

class Value
{
public:
    typedef std::variant<std::string, int, float, bool, Node, std::nullptr_t> ValueType;
    typedef std::vector<ValueType> Array;

public:
    Value &required(bool required = true);
    Value &type(const Type &type);

    template<typename T>
    requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, Node, std::nullptr_t>
    Value &defaultValue(const T &defaultValue);
    Value &defaultValueArgument(const std::string &argument);
    Value &defaultValueFromEnvironmentVariable(const std::string &variable);

    ValueType &value();
    template<typename T>
    T &as();

private:
    Value(const Node &parent, const std::string &key, const char * const *environment, const ArgumentsHolder);

private:
    bool _required;
    Type _types;
    Array _value;
    ArgumentsHolder _arguments;
    std::string _defaultValueArgument;
    std::string _defaultValueEnvironmentVariable;
};

class Node
{
public:
    Node() = default;

    Value &addKey(const std::string &key);
    Node &addNode(const std::string &key);

    /**
     * @brief Validate the configuration
     *
     * @throw MissingRequiredConfigurationKey
     * @throw InvalidConfigurationType
     */
    void validate();

protected:
    std::map<std::string, Value> _keys;
    std::map<std::string, Node> _nodes;
    YAML::Node _yaml;
};

class ConfigHandler
{
public:
    ConfigHandler() = default;

    /**
     * @brief Load the configuration from the given path
     *
     * @throw InvalidConfigurationFile
     * @throw MissingConfigurationFile
     * @throw ios_base::failure Basic file operations may throw this exception
     *
     * @param path
     */
    void load(const std::string &path);

    /**
     * @brief Save the configuration to the given path
     *
     * @throw ios_base::failure Basic file operations may throw this exception
     *
     * @param path
     */
    void save(const std::string &path);

    Value &add();

    /**
     * @brief Validate the configuration
     *
     * @throw MissingRequiredConfigurationKey
     * @throw InvalidConfigurationType
     */
    void validate();
};

template<typename T>
T ArgumentsHolder::operator[](const std::string &argument) const
{
    return get<T>(argument);
}

template<typename T>
T ArgumentsHolder::get(const std::string &argument) const
{
    if (has(argument))
        return _parser.get<T>(argument);
    throw InvalidConfigurationValue("Invalid configuration value");
}

template<typename T>
requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, Node, std::nullptr_t>
Value &Value::defaultValue(const T &defaultValue)
{
    _value = defaultValue;
    return *this;
}

template<typename T>
requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, Node, std::nullptr_t>
Value &Value::defaultValue(cosnt std::vector<T> &defaultValue)
{
    _ = defaultValue;
    return *this;
}

template<typename T>
T &Value::as()
{
    if (std::holds_alternative<T>(_value))
        return std::get<T>(_value);
    throw InvalidConfigurationValue("Invalid configuration value");
}

/******************************************************************************/

DEFINE_EXCEPTION(InvalidConfiguration);

class Argument
{
public:
    Argument(const std::string &key, const std::string &description, const Type &type, const std::string &defaultValue = "");

    Argument &required(bool required = true);
    template<typename T>
    requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, Node, std::nullptr_t>
    Argument &defaultValueFromConfig(const std::string &key, const T &defaultValue);
    template<typename... T>
    Argument &defaultValueFromConfig(const std::string &node, const T&... defaultValue);
    Argument &defaultValueFromArgument(const std::string &argument);
    Argument &defaultValueFromEnvironmentVariable(const std::string &variable);

    const std::string &key() const;
    const std::string &description() const;
    const Type &type() const;
    bool required() const;

protected:
    template<typename T>
    requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, Node, std::nullptr_t>
    void _addDefaultValueFromConfig(YAML::Node &node, const std::string &key, const T &defaultValue);
    template<typename... T>
    void _addDefaultValueFromConfig(YAML::Node &node, const std::string &node, const T... &nodeAndDefaultValue);

protected:
    YAML::Node _yaml;
    std::string _key;
    std::string _description;
    Type _type;
    std::string _defaultValue;
    std::string _defaultValueArgument;
    std::string _defaultValueEnvironmentVariable;
    bool _required;
};

template<typename T>
requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, Node, std::nullptr_t>
Argument &Argument::defaultValueFromConfig(const std::string &key, const T &defaultValue)
{
    _addDefaultValueFromConfig(_yaml, key, defaultValue);
    return *this;
}

template<typename T>
requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, Node, std::nullptr_t>
void Argument::_addDefaultValueFromConfig(YAML::Node &node, const std::string &key, const T &defaultValue)
{
    if (!node[key].IsDefined())
        node[key] = defaultValue;
    else if (!node.IsMap())
        throw InvalidConfiguration("Trying to add a default value to a sub map node");
}

template<typename... T>
Argument &Argument::defaultValueFromConfig(const std::string &node, const T... &nodeAndDefaultValue)
{
    _addDefaultValueFromConfig(_yaml, node, nodeAndDefaultValue...);
    return *this;
}

template<typename... T>
void Argument::_addDefaultValueFromConfig(YAML::Node &node, const std::string &node, const T... &nodeAndDefaultValue)
{
    if (!node[node].IsDefined())
        node[node] = YAML::Node(YAML::NodeType::Map);
    else if (!node.IsMap())
        throw InvalidConfiguration("Trying to add a default value to a sub map node");
    _addDefaultValueFromConfig(node[node], nodeAndDefaultValue...);
}

class Handler
{
public:
    void load(const std::string &path);
    void save(const std::string &path);
    void generate(const std::string &path);

    void validate();

    Argument &expect();
}

} // namespace configuration

#endif /* CONFIG_CONFIGHANDLER_HPP */
