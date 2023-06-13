#ifndef CONFIG_VALUE_HPP
#define CONFIG_VALUE_HPP

#include "ArgumentsParser.hpp"
#include "Node.hpp"
#include "concept.hpp"
#include "conversion.hpp"
#include "options.hpp"
#include <optional>
#include <string>
#include <variant>

namespace configuration {
class Value {
    friend class ConfigHandler;

public:
    /**
     * @brief Set the value as required.
     *
     * @return Value&
     */
    Value &required();

    /**
     * @brief Provide a default value for the value.
     *
     * @param defaultValue
     * @return Value&
     */
    Value &defaultValue(const auto &defaultValue);

    /**
     * @brief Set the value from the configuration file.
     *
     * @tparam Args...
     * @param node
     * @param keys
     * @return Value&
     */
    template<typename... Args>
    Value &valueFromConfig(const std::string &node, Args... keys);

    /**
     * @brief Set the value from the configuration file.
     *
     * @param key
     * @return Value&
     */
    Value &valueFromConfig(const std::string &key);

    /**
     * @brief Set the value from the command line argument.
     *
     * @param argument
     * @return Value&
     */
    Value &valueFromArgument(const std::string &argument);

    /**
     * @brief Set the value from the environment variable.
     *
     * @param variable
     * @return Value&
     */
    Value &valueFromEnvironmentVariable(const std::string &variable);

    /**
     * @brief Specify the possible values for the value.
     *
     * @tparam T
     * @tparam Args
     * @param value
     * @param values
     * @return Value&
     */
    template<typename T, typename... Args>
    Value &possibleValues(const T &value, Args... values);

    /**
     * @brief Specify a range of values for the value.
     *
     * @tparam T
     * @param min
     * @param max
     * @return Value&
     */
    template<typename T>
    Value &inRange(const T &min, const T &max);

    /**
     * @brief Specify a help message for the value.
     *
     * @param help
     * @return Value&
     */
    Value &help(const std::string &help);
    Value &implicit();

    NODISCARD const std::string &value() const;
    NODISCARD const std::vector<std::string> &values() const;

    /**
     * @brief Get the Value as the given type.
     *
     * @tparam T
     * @return T
     */
    template<typename T>
    NODISCARD T as() const;

    /**
     * @brief Get the Values as the given type.
     *
     * @tparam T
     * @return T
     */
    template<typename R, typename T>
        requires std::is_same_v<R, std::vector<T>>
    NODISCARD std::vector<T> as();

    /**
     * @brief Check if the value is the default one.
     *
     * Always return false if the value has not been parsed yet
     *
     * @return bool
     */
    NODISCARD inline bool isDefault() const { return _value.size() <= 0; }

    /**
     * @brief Check if the stored value is an array.
     *
     * @details return false if the value has not been parsed yet
     *
     * @return bool
     */
    NODISCARD inline bool isArray() const { return _value.size() > 1; }

public:
    // Operators
    operator bool() const { return configuration::_details::Convertor<bool>()(value()); }
    operator std::nullptr_t() const { return configuration::_details::Convertor<std::nullptr_t>()(value()); }
    operator std::string() const { return configuration::_details::Convertor<std::string>()(value()); }
    operator float() const { return configuration::_details::Convertor<float>()(value()); }
    operator double() const { return configuration::_details::Convertor<double>()(value()); }
    operator int8_t() const { return configuration::_details::Convertor<int8_t>()(value()); }
    operator uint8_t() const { return configuration::_details::Convertor<uint8_t>()(value()); }
    operator int32_t() const { return configuration::_details::Convertor<int32_t>()(value()); }
    operator uint32_t() const { return configuration::_details::Convertor<uint32_t>()(value()); }
    operator int64_t() const { return configuration::_details::Convertor<int64_t>()(value()); }
    operator uint64_t() const { return configuration::_details::Convertor<uint64_t>()(value()); }

    template<typename T>
    NODISCARD bool operator==(const T &key) const
    {
        return configuration::_details::Convertor<T>()(value()) == key;
    }

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

    std::optional<std::function<bool(std::string)>> _rangeChecker;
    std::optional<std::pair<std::string, std::string>> _rangeValues;
    std::vector<std::string> _possibleValue;
    std::vector<std::string> _defaultValueConfig;
    std::string _defaultValueArgument;
    std::string _defaultValueEnvironmentVariable;
};

std::ostream &operator<<(std::ostream &os, const Value &value);

template<typename T>
Value &Value::defaultValue(const T &defaultValue)
{
    _defaultValue.push_back(_details::Convertor<std::string>()(defaultValue));
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

template<typename T>
Value &Value::inRange(const T &min, const T &max)
{
    _rangeChecker = [min, max](const std::string &value) {
        auto v = _details::Convertor<T>()(value);
        return v >= min && v <= max;
    };
    _rangeValues = {_details::Convertor<std::string>()(min), _details::Convertor<std::string>()(max)};
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
T Value::as() const
{
    return _details::Convertor<T>()(isDefault() ? _defaultValue[0] : _value[0]);
}

template<typename R, typename T>
    requires std::is_same_v<R, std::vector<T>>
std::vector<T> Value::as()
{
    return _details::Convertor<std::vector<T>>()(isDefault() ? _defaultValue : _value);
}

} // namespace configuration

#endif // CONFIGURATION_VALUE_HPP
