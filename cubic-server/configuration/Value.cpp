#include "Value.hpp"

configuration::Value &configuration::Value::required(bool required)
{
    _required = required;
    return *this;
}

configuration::Value &configuration::Value::type(const Type &type)
{
    _types = type;
    return *this;
}

configuration::Value &configuration::Value::defaultValueFromArgument(const std::string &argument)
{
    _defaultValueArgument = argument;
    return *this;
}

configuration::Value &configuration::Value::defaultValueFromEnvironmentVariable(const std::string &variable)
{
    _defaultValueEnvironmentVariable = variable;
    return *this;
}

configuration::Value &configuration::Value::defaultValueFromConfig(const std::string &key)
{
    _defaultValueConfig = {key};
    return *this;
}

configuration::Value::ValueType &configuration::Value::value()
{
    return _value.size() > 0 ? _value[0] : _defaultValue[0];
}

configuration::Value::Array &configuration::Value::values()
{
    return _value.size() > 0 ? _value : _defaultValue;
}

bool configuration::Value::isDefault() const
{
    return _value.size() > 0;
}
