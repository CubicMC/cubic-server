#include "Value.hpp"

configuration::Value::Value(configuration::ArgumentsParser &parser):
    _required(false),
    _implicit(false),
    _value(),
    _defaultValue({""}),
    _help(""),
    _arguments(parser),
    _defaultValueConfig(),
    _defaultValueArgument(""),
    _defaultValueEnvironmentVariable("")
{
}

configuration::Value &configuration::Value::required()
{
    _required = true;
    return *this;
}

configuration::Value &configuration::Value::valueFromArgument(const std::string &argument)
{
    _defaultValueArgument = argument;
    return *this;
}

configuration::Value &configuration::Value::valueFromEnvironmentVariable(const std::string &variable)
{
    _defaultValueEnvironmentVariable = variable;
    return *this;
}

configuration::Value &configuration::Value::valueFromConfig(const std::string &key)
{
    _defaultValueConfig = {key};
    return *this;
}

configuration::Value &configuration::Value::help(const std::string &help)
{
    _help = help;
    return *this;
}

configuration::Value &configuration::Value::implicit()
{
    _implicit = true;
    _defaultValue = {"false"};
    return *this;
}

const std::string &configuration::Value::value() const
{ return _value.size() > 0 ? _value[0] : _defaultValue[0]; }

const std::vector<std::string> &configuration::Value::values() const
{ return _value.size() > 0 ? _value : _defaultValue; }

bool configuration::Value::isDefault() const
{ return _value.size() <= 0; }

bool configuration::Value::isArray() const
{ return _value.size() > 1; }

std::ostream &configuration::operator<<(std::ostream &os, const configuration::Value &value)
{ return os << value.value(); }


void configuration::Value::addToParser()
{
    if (_defaultValueArgument.size() <= 0)
        return;

    auto arg = _arguments.addArgument(_defaultValueArgument);
    if (_implicit)
        arg.implicit();
    if (_help.size() > 0)
        arg.help(_help);
    if (_required)
        arg.required();
}

void configuration::Value::parse(const Node &rootNode)
{
    if (_defaultValueEnvironmentVariable.size() > 0) {
        auto envValue = std::getenv(_defaultValueEnvironmentVariable.c_str());
        if (envValue != nullptr)
            _value = {envValue};
    }

    if (_defaultValueArgument.size() > 0) {
        if (_arguments.has(_defaultValueArgument))
            _value = {_arguments.get(_defaultValueArgument)};
    }

    if (_defaultValueConfig.size() > 0) {
        configuration::Node node = rootNode;
        std::cout << (node == rootNode) << std::endl;
        for (auto &key : _defaultValueConfig) {
            if (node.has(key))
                node = node.at(key);
            else {
                std::cout << "key not found: ";
                for (auto &k : _defaultValueConfig)
                    std::cout << k << " ";
                std::cout << std::endl;
                return;
            }
        }
        _value = {node.get()};
        std::cout << "value(";
        for (auto &k : _defaultValueConfig)
            std::cout << k << " ";
        std::cout << "): " << _value[0] << std::endl;
    }
}
