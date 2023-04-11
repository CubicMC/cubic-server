#ifndef CONFIG_VALUE_HPP
#define CONFIG_VALUE_HPP

#include <string>
#include <variant>
#include "concept.hpp"
#include "ArgumentsHolder.hpp"

namespace configuration
{

#define BIT(x) (1 << x)

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

class Value
{
public:
    typedef std::variant<std::string, int, float, bool, std::nullptr_t> ValueType;
    typedef std::vector<ValueType> Array;

public:
    Value &required(bool required = true);
    Value &type(const Type &type);

    template<typename T>
    requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, std::nullptr_t>
    Value &defaultValue(const T &defaultValue);

    template<typename... T>
    Value &defaultValueFromConfig(const std::string &node, T... keys);
    Value &defaultValueFromConfig(const std::string &key);
    Value &defaultValueFromArgument(const std::string &argument);
    Value &defaultValueFromEnvironmentVariable(const std::string &variable);

    ValueType &value();
    Array &values();

    /**
     * @brief Get the Value as the given type
     *
     * @throw std::bad_variant_access if the type is not the same as the one stored
     *
     * @tparam T
     * @return T&
     */
    template<typename T>
    T &as();

    /**
     * @brief Check if the value is the default one
     *
     * @return true
     * @return false
     */
    bool isDefault() const;

private:
    Value(const char * const *environment, const ArgumentsHolder &argsHolder);

private:
    bool _required;
    Type _types;
    Array _value;
    Array _defaultValue;
    ArgumentsHolder _arguments;
    std::vector<std::string> _defaultValueConfig;
    std::string _defaultValueArgument;
    std::string _defaultValueEnvironmentVariable;
};

template<typename T>
requires is_one_or_convertible_to_one_of<T, std::string, int, float, bool, std::nullptr_t>
Value &Value::defaultValue(const T &defaultValue)
{
    _defaultValue.resize(1);
    _defaultValue[0] = defaultValue;
    return *this;
}

template<typename... T>
Value &Value::defaultValueFromConfig(const std::string &node, T... keys)
{
    _defaultValueConfig = {node, keys...};
    return *this;
}

template<typename T>
T &Value::as()
{
    return std::get<T>(_value);
}

} // namespace configuration

#endif // CONFIGURATION_VALUE_HPP
