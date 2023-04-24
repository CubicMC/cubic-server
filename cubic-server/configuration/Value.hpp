#ifndef CONFIG_VALUE_HPP
#define CONFIG_VALUE_HPP

#include <string>
#include <variant>
#include "concept.hpp"
#include "ArgumentsParser.hpp"
#include "conversion.hpp"
#include "Node.hpp"

namespace configuration {
class Value {
    friend class ConfigHandler;

public:
    Value &required();

    template<typename T>
    requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, std::nullptr_t>
    Value &defaultValue(const T &defaultValue);

    template<typename... T>
    Value &valueFromConfig(const std::string &node, T... keys);
    Value &valueFromConfig(const std::string &key);
    Value &valueFromArgument(const std::string &argument);
    Value &valueFromEnvironmentVariable(const std::string &variable);
    template<typename T, typename... Args>
    Value &possibleValues(const T &value, Args... values);

    Value &help(const std::string &help);
    Value &implicit();

    const std::string &value() const;
    const std::vector<std::string> &values() const;

    template<typename T>
    bool operator==(const T &key) const
    { return configuration::_details::Convertor<T>()(value()) == key; }

    /**
     * @brief Get the Value as the given type.
     *
     * @tparam T
     * @return T
     */
    template<typename T>
    T as();

    /**
     * @brief Get the Values as the given type.
     *
     * @tparam T
     * @return T
     */
    template<typename R, typename T>
    requires std::is_same_v<R, std::vector<T>>
    std::vector<T> as();

    /**
     * @brief Check if the value is the default one.
     *
     * Always return false if the value has not been parsed yet
     *
     * @return bool
     */
    bool isDefault() const;

    /**
     * @brief Check if the stored value is an array.
     *
     * @details return false if the value has not been parsed yet
     *
     * @return bool
     */
    bool isArray() const;

private:
    Value(const std::string &name, ArgumentsParser &arguments);
    void parse(const Node &node);
    void addToParser();

private:
    bool _required;
    bool _implicit;
    std::vector<std::string> _value;
    std::vector<std::string> _defaultValue;
    std::string _help;

    std::string _name;
    ArgumentsParser &_arguments;

    std::vector<std::string> _possibleValue;
    std::vector<std::string> _defaultValueConfig;
    std::string _defaultValueArgument;
    std::string _defaultValueEnvironmentVariable;
};

std::ostream &operator<<(std::ostream &os, const Value &value);

template<typename T>
requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, std::nullptr_t>
Value &Value::defaultValue(const T &defaultValue)
{
    _defaultValue.resize(1);
    _defaultValue[0] = _details::Convertor<std::string>()(defaultValue);
    return *this;
}


template<typename T, typename... Args>
Value &Value::possibleValues(const T &value, Args... values)
{
    this->_possibleValue.clear();
    this->_possibleValue.resize(sizeof...(values) + 1);
    _possibleValue.push_back(_details::Convertor<std::string>()(value));
    ((_possibleValue.push_back(_details::Convertor<std::string>()(std::forward<Args>(values)))), ...);
    return *this;
}

template<typename... T>
Value &Value::valueFromConfig(const std::string &node, T... keys)
{
    _defaultValueConfig = {node, _details::Convertor<std::string>()(std::forward<T>(keys))...};
    for (auto &key : _defaultValueConfig) {
        if (key.empty())
            throw ConfigurationError("Invalid configuration value");
    }
    return *this;
}

template<typename T>
T Value::as()
{ return _details::Convertor<T>()(isDefault() ? _defaultValue[0] : _value[0]); }

template<typename R, typename T>
requires std::is_same_v<R, std::vector<T>>
std::vector<T> Value::as()
{ return _details::Convertor<std::vector<T>>()(isDefault() ? _defaultValue : _value); }

} // namespace configuration

#endif // CONFIGURATION_VALUE_HPP
