#include <argparse/argparse.hpp>
#include <csignal>
#include <cstring>
#include <iostream>
#include <thread>

#include "CommandLine.hpp"
#include "Server.hpp"
#include "interface/InterfaceContainer.hpp"
#include "logging/Logger.hpp"

// argparse::ArgumentParser argParser(int argc, char **argv)
// {
//     argparse::ArgumentParser program("cubic_server");

//     program.add_argument("--nogui")
//         .help("prevents the GUI from displaying")
//         .default_value(false)
//         .implicit_value(true);
//     try {
//         program.parse_args(argc, argv);
//     }
//     catch (const std::runtime_error& err) {
//         std::cerr << err.what() << std::endl;
//         std::cerr << program;
//         std::exit(1);
//     }
//     return program;
// }

auto initArgs(int argc, char **argv)
{
    auto program = configuration::ConfigHandler();
    program.load("./config.yml");

    // auto node = YAML::LoadFile("config.yml");

    // std::cout << node.IsDefined("general") << std::endl;
    // std::cout << node.IsMap("general") << std::endl;

    program.add("nogui")
        .help("prevents the GUI from displaying")
        .valueFromArgument("--nogui")
        .valueFromEnvironmentVariable("CBSRV_NOGUI")
        .implicit();

    program.add("ip")
        .help("sets the ip on which the server will listen")
        // .valueFromArgument("--ip")
        .valueFromConfig("network", "ip")
        .valueFromEnvironmentVariable("CBSRV_IP")
        // .defaultValue("0.0.0.0");
        .required();

    program.add("port")
        .help("sets the port on which the server will listen")
        // .valueFromArgument("--port")
        .valueFromConfig("network", "port")
        .valueFromEnvironmentVariable("CBSRV_PORT")
        // .defaultValue(25565);
        .required();

    program.add("max-players")
        .help("sets the maximum number of players")
        // .valueFromArgument("--max-players")
        .valueFromConfig("general", "max_players")
        .valueFromEnvironmentVariable("CBSRV_MAX_PLAYERS")
        // .defaultValue(20);
        .required();

    program.add("motd")
        .help("sets the message of the day")
        // .valueFromArgument("--motd")
        .valueFromConfig("general", "motd")
        .valueFromEnvironmentVariable("CBSRV_MOTD")
        // .defaultValue("A Cubic Server");
        .required();

    // program.add("world")
    //     .help("sets the world to load")
    //     // .valueFromArgument("--world")
    //     .valueFromConfig("general", "world")
    //     .valueFromEnvironmentVariable("CBSRV_WORLD")
    //     .defaultValue("world");

    program.add("enforce-whitelist")
        .help("enforces the whitelist")
        // .valueFromArgument("--enforce-whitelist")
        .valueFromConfig("general", "enforce-whitelist")
        .valueFromEnvironmentVariable("CBSRV_ENFORCE_WHITELIST")
        // .defaultValue(false);
        .required();

    program.parse(argc, argv);

    return program;
}

void signalHandler(int sig)
{
    if (sig != SIGINT && sig != SIGTERM)
        return;
    Server::getInstance()->stop();
}

int main(int argc, char **argv)
{
    auto program = initArgs(argc, argv);

    std::cout << program << std::endl;
    std::cout << "nogui: " << program["nogui"] << std::boolalpha << ' ' << program["nogui"].as<bool>() << std::endl;
    std::cout << "ip: " << program["ip"] << std::endl;
    std::cout << "port: " << program["port"] << std::endl;
    std::cout << "max-players: " << program["max-players"] << std::endl;
    std::cout << "motd: " << program["motd"] << std::endl;
    std::cout << "enforce-whitelist: " << program["enforce-whitelist"] << std::endl;
    /*
    auto srv = Server::getInstance();

    InterfaceContainer interfaceContainer;
    CommandLine cmd;

    auto logger = logging::Logger::getInstance();
    logger->unsetDisplaySpecificationLevelInConsole(logging::LogLevel::DEBUG);

    if (program["--nogui"] == false)
        interfaceContainer.launch(argc, argv);

    std::signal(SIGTERM, signalHandler);
    std::signal(SIGINT, signalHandler);
    std::signal(SIGPIPE, SIG_IGN);

    // This should be inside the server
    cmd.launch();

    srv->launch();

    cmd.stop();
    interfaceContainer.stop();
    */
    return 0;
}
