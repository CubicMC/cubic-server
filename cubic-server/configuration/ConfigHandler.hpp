#ifndef CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP
#define CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP

#include "Node.hpp"
#include "Value.hpp"
#include "concept.hpp"
#include "errors.hpp"
#include <argparse/argparse.hpp>
#include <map>
#include <optional>
#include <string>
#include <yaml-cpp/yaml.h>

namespace configuration {
class ConfigHandler {
public:
    typedef std::unordered_map<std::string, Value>::iterator iterator;
    friend std::ostream &operator<<(std::ostream &os, const ConfigHandler &config);

public:
    ConfigHandler(const std::string &name = "", const std::string &version = "");
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

    /**
     * @brief Parse All arguments, config file and environment variables
     *
     * @param argc
     * @param argv
     */
    void parse(int argc, const char *const argv[]);

    /**
     * @brief Parse All arguments, config file and environment variables
     *
     * @param args
     */
    void parse(const std::vector<std::string> &args);

    /**
     * @brief Parse config file and environment variables
     */
    void parse();

public:
    // Operators
    Value &operator[](const auto &key);
    const Value &operator[](const auto &key) const;

private:
    std::unordered_map<std::string, Value> _values;
    Node _config;
    ArgumentsParser _arguments;
};

std::ostream &operator<<(std::ostream &os, const ConfigHandler &config);

Value &ConfigHandler::operator[](const auto &key) { return this->_values.at(_details::Convertor<std::string>()(key)); }

const Value &ConfigHandler::operator[](const auto &key) const { return this->_values.at(_details::Convertor<std::string>()(key)); }

} // namespace configuration

#endif // CUBICSERVER_CONFIGURATION_CONFIGHANDLER_HPP
