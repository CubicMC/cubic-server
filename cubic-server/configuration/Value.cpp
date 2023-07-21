#include "Value.hpp"
#include "logging/logging.hpp"
#include <cstdlib>
#include <filesystem>
#include <fstream>

const std::vector<std::string> &configuration::Value::values() const { return _value.size() > 0 ? _value : _defaultValue; }
std::ostream &configuration::operator<<(std::ostream &os, const configuration::Value &value) { return os << value.value(); }

configuration::Value::Value(const std::string &name, configuration::ArgumentsParser &parser):
    _required(false),
    _implicit(false),
    _value(),
    _defaultValue({}),
    _help(""),
    _name(name),
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
{
    if (_value.size() > 0)
        return _value[0];
    if (_defaultValue.size() > 0)
        return _defaultValue[0];
    throw ConfigurationError("Value '" + _name + "' is not set");
}

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
    // First argument has the highest priority
    if (!_defaultValueArgument.empty()) {
        if (_arguments.has(_defaultValueArgument))
            _value = {_arguments.get(_defaultValueArgument)};
    }

    // Then environment variable
    if (!_defaultValueEnvironmentVariable.empty() && _value.empty()) {
        // We check if a `_FILE` variant of the environment variable exists
        // since containers really like this kind of stuff for secret managements
        auto envSecretValue = std::getenv(std::string(_defaultValueEnvironmentVariable + "_FILE").c_str());
        if (envSecretValue != nullptr) {
            std::string __tmpSecret(envSecretValue);
            if (std::filesystem::exists(envSecretValue)) {
                auto stream = std::ifstream(__tmpSecret);
                std::ostringstream sstr;
                sstr << stream.rdbuf();
                _value = {sstr.str()};
            }
        }
        if (_value.empty()) {
            auto envValue = std::getenv(_defaultValueEnvironmentVariable.c_str());
            if (envValue != nullptr)
                _value = {envValue};
        }
    }

    // Then config file
    if (!_defaultValueConfig.empty() && _value.empty()) {
        const auto *node = &rootNode;
        for (auto &key : _defaultValueConfig) {
            if (node->has(key))
                node = &node->at(key);
            else
                break;
        }
        if (!node->isDefined())
            return;

        if (node->isArray())
            _value = node->getArray();
        else if (node->isScalar())
            _value = {node->get()};
    }

    // Check if required
    if (_value.empty()) {
        if (_required)
            throw ConfigurationError("Missing value: " + _name);
        if (_defaultValueConfig.size() > 0)
            LWARN("Missing value in config: " + _name);
    }

    if (_rangeValues.has_value() && _rangeChecker.has_value() && !_rangeChecker.value()(value()))
        throw ConfigurationError(
            "Invalid value: " + _name + " value '" + value() + "' is not in the range (" + _rangeValues.value().first + ", " + _rangeValues.value().second + ")"
        );

    // Check if the value is in the possible values list
    if (_possibleValue.empty())
        return;

    if (_value.empty())
        return;
    for (auto &value : _value) {
        if (std::find(_possibleValue.begin(), _possibleValue.end(), value) == _possibleValue.end())
            throw ConfigurationError("Invalid value: " + _name + " value '" + value + "' is not in the possible values list");
    }
}
