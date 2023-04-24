#include "ConfigHandler.hpp"
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <filesystem>
#include "errors.hpp"

// namespace Configuration
// {
//     constexpr std::string_view fileContent =
// "network:\n\
//   ip: 0.0.0.0\n\
//   port: 25565\n\
// \n\
// general:\n\
//   max_players: 20\n\
//   motd: A Cubic Server\n\
//   enforce-whitelist: false\
// ";

//     static void defaultConfigContent(const std::string &path) {
//         if (!std::filesystem::exists(path)) {
//             std::ofstream configFile(path);
//             configFile << fileContent << std::endl;
//             configFile.close();
//         }
//     }

//     ConfigHandler::ConfigHandler()
//     {
//     }

//     void ConfigHandler::parse(const std::string &path) {
//         YAML::Node config;
//         defaultConfigContent(path);
//         try {
//             _baseNode = YAML::LoadFile(path);
//             _ip = _baseNode["network"]["ip"].as<std::string>();
//             _port = _baseNode["network"]["port"].as<uint16_t>();
//             _maxPlayers = _baseNode["general"]["max_players"].as<uint32_t>();
//             _motd = _baseNode["general"]["motd"].as<std::string>();
//             _enforceWhitelist = _baseNode["general"]["enforce-whitelist"].as<bool>();
//         }
//         catch (const std::exception &e) {
//             LERROR("Config parsing failed, exiting now!" << std::endl << e.what());
//             exit(1); // TODO: Use an exception
//         }
//     }

//     const std::string &ConfigHandler::getIP() const
//     {
//         return _ip;
//     }

//     uint16_t ConfigHandler::getPort() const
//     {
//         return _port;
//     }

//     uint32_t ConfigHandler::getMaxPlayers() const
//     {
//         return _maxPlayers;
//     }

//     const std::string &ConfigHandler::getMotd() const
//     {
//         return _motd;
//     }

//     bool ConfigHandler::getEnforceWhitelist() const
//     {
//         return _enforceWhitelist;
//     }
// }


// void configuration::ArgumentsHolder::init()
// {
    // this->_parser.add_argument("-c", "--config")
    //     .help("Specify the configuration file to use UNUSED")
    //     .default_value("config.yml");
    // this->_parser.add_argument("-w", "--world")
    //     .help("Specify the world to load UNUSED")
    //     .default_value("world");
    // this->_parser.add_argument("--nogui")
    //     .help("Disable the GUI")
    //     .default_value(false)
    //     .implicit_value(true);
// }

// void ConfigHandler::init()
// {
//     auto network = this->addNode("network");
//     auto general = this->addNode("general");

//     network.addKey("ip")
//         .required()
//         .type(Type::String)
//         .defaultValue("0.0.0.0")
//         .defaultValueFromEnvironmentVariable("CUBIC_SERVER_IP");

//     network.addKey("port")
//         .required()
//         .type(Type::Integer)
//         .defaultValue(25565)
//         .defaultValueFromEnvironmentVariable("CUBIC_SERVER_PORT");

//     general.addKey("max_players")
//         .type(Type::Integer)
//         .defaultValue(20)
//         .defaultValueFromEnvironmentVariable("CUBIC_SERVER_MAX_PLAYERS");

//     general.addKey("motd")
//         .type(Type::String)
//         .defaultValue("A Cubic Server")
//         .defaultValueFromEnvironmentVariable("CUBIC_SERVER_MOTD");

//     general.addKey("enforce_whitelist")
//         .type(Type::Boolean)
//         .defaultValue(false)
//         .defaultValueFromEnvironmentVariable("CUBIC_SERVER_ENFORCE_WHITELIST");

//     general.addKey("enable_whitelist")
//         .type(Type::Boolean)
//         .defaultValue(false)
//         .defaultValueFromEnvironmentVariable("CUBIC_SERVER_ENABLE_WHITELIST");

//     general.addKey("no_gui")
//         .type(Type::Boolean)
//         .defaultValue(true)
//         .defaultValueFromEnvironmentVariable("CUBIC_SERVER_NO_GUI");
// }

void configuration::ConfigHandler::load(const std::filesystem::path &path)
{ this->_config.load(path); }

void configuration::ConfigHandler::save(const std::filesystem::path &path)
{ this->_config.save(path); }

configuration::Value &configuration::ConfigHandler::add(const std::string &key)
{
    this->_values.emplace(std::make_pair(key, Value(key, this->_arguments)));
    return this->_values.at(key);
}

void configuration::ConfigHandler::parse(int argc, const char * const *argv)
{
    for (auto &[_, value]: this->_values)
        value.addToParser();

    this->_arguments.parse(argc, argv);

    for (auto &[_, value]: this->_values)
        value.parse(this->_config);
    // this->_arguments.parse(argc, argv, envp);
    // this->_config.parse(this->_arguments.get("config"));
}

configuration::Value &configuration::ConfigHandler::operator[](const std::string &key)
{ return this->_values.at(key); }


std::ostream &configuration::operator<<(std::ostream &os, const configuration::ConfigHandler &config)
{ return os << config._arguments; }
