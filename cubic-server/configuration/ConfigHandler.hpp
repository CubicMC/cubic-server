#ifndef CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP
#define CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP

#include <string>
#include <map>
#include <optional>
#include <yaml-cpp/yaml.h>
#include <argparse/argparse.hpp>
#include "logging/Logger.hpp"
#include "exceptions.hpp"
#include "concept.hpp"
#include "Value.hpp"

#define BIT(x) (1 << x)

namespace configuration
{

DEFINE_EXCEPTION(InvalidArguments);
DEFINE_EXCEPTION(InvalidArgumentParameter);

DEFINE_EXCEPTION(MissingRequiredConfigurationKey);
DEFINE_EXCEPTION(InvalidConfigurationType);
DEFINE_EXCEPTION(InvalidConfigurationFile);
DEFINE_EXCEPTION(MissingConfigurationFile);


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
