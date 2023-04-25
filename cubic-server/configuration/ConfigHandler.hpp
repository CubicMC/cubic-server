#ifndef CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP
#define CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP

#include <string>
#include <map>
#include <optional>
#include <yaml-cpp/yaml.h>
#include <argparse/argparse.hpp>
#include "logging/Logger.hpp"
#include "errors.hpp"
#include "concept.hpp"
#include "Node.hpp"
#include "Value.hpp"

namespace configuration {
class ConfigHandler {
public:
    typedef std::unordered_map<std::string, Value>::iterator iterator;
    friend std::ostream &operator<<(std::ostream &os, const ConfigHandler &config);
public:
    ConfigHandler() = default;
    ~ConfigHandler() = default;

    /**
     * @brief Load the configuration from the given path
     *
     * @throw InvalidConfigurationFile
     * @throw MissingConfigurationFile
     * @throw ios_base::failure Basic file operations may throw this exception
     *
     * @param path
     */
    void load(const std::filesystem::path &path);

    /**
     * @brief Save the configuration to the given path
     *
     * @throw ios_base::failure Basic file operations may throw this exception
     *
     * @param path
     */
    void save(const std::filesystem::path &path);

    /**
     * @brief Add a new value to the configuration
     *
     * @param key
     * @return iterator
     */
    Value &add(const std::string &key);

    // Schema &addSchema(const std::string &rootKey);

    /**
     * @brief Parse All arguments
     *
     * @param argc
     * @param argv
     */
    void parse(int argc, const char * const *argv);

    Value &operator[](const std::string &key);
    const Value &operator[](const std::string &key) const;
    // Value &operator[](const char key[])
    // { return operator[](std::string(key)); }

private:
    std::unordered_map<std::string, Value> _values;
    Node _config;
    ArgumentsParser _arguments;
};

std::ostream &operator<<(std::ostream &os, const ConfigHandler &config);

// template<typename T>
// T ArgumentsHolder::operator[](const std::string &argument) const
// {
//     return get<T>(argument);
// }

// template<typename T>
// T ArgumentsHolder::get(const std::string &argument) const
// {
//     if (has(argument))
//         return _parser.get<T>(argument);
//     throw InvalidConfigurationValue("Invalid configuration value");
// }

// template<typename T>
// requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, Node, std::nullptr_t>
// Value &Value::defaultValueFromConfig(const T &defaultValue)
// {
//     _value = defaultValue;
//     return *this;
// }

// template<typename T>
// T &Value::as()
// {
//     if (std::holds_alternative<T>(_value))
//         return std::get<T>(_value);
//     throw InvalidConfigurationValue("Invalid configuration value");
// }

} // namespace configuration

#endif // CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP
