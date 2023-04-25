#include <argparse/argparse.hpp>
#include <csignal>
#include <cstring>
#include <iostream>
#include <thread>

#include "CommandLine.hpp"
#include "Server.hpp"
#include "interface/InterfaceContainer.hpp"
#include "logging/Logger.hpp"

auto initArgs(int argc, const char * const argv[])
{
    auto program = configuration::ConfigHandler("CubicServer", "0.1.0");

    program.add("nogui")
        .help("prevents the GUI from displaying")
        .valueFromArgument("--nogui")
        .valueFromEnvironmentVariable("CBSRV_NOGUI")
        .possibleValues(true, false)
        .implicit();

    program.add("ip")
        .help("sets the ip on which the server will listen")
        .valueFromConfig("network", "ip")
        .valueFromEnvironmentVariable("CBSRV_IP")
        .defaultValue("0.0.0.0")
        .required();

    program.add("port")
        .help("sets the port on which the server will listen")
        .valueFromConfig("network", "port")
        .valueFromEnvironmentVariable("CBSRV_PORT")
        .defaultValue(25565)
        .required();

    program.add("max-players")
        .help("sets the maximum number of players")
        .valueFromConfig("general", "max_players")
        .valueFromEnvironmentVariable("CBSRV_MAX_PLAYERS")
        .defaultValue(20)
        .required();

    program.add("motd")
        .help("sets the message of the day")
        .valueFromConfig("general", "motd")
        .valueFromEnvironmentVariable("CBSRV_MOTD")
        .defaultValue("A Cubic Server")
        .required();

    // program.add("world")
    //     .help("sets the world to load")
    //     .valueFromConfig("general", "world")
    //     .valueFromEnvironmentVariable("CBSRV_WORLD")
    //     .defaultValue("world");

    program.add("enforce-whitelist")
        .help("enforces the whitelist")
        .valueFromConfig("general", "enforce-whitelist")
        .valueFromEnvironmentVariable("CBSRV_ENFORCE_WHITELIST")
        .possibleValues(true, false)
        .defaultValue(false)
        .required();

    try {
        program.load("./config.yml");
    } catch (configuration::BadFile) {
        if (std::filesystem::exists("./config.yml")) {
            LERROR("Failled to open config file, check permissions");
            std::exit(1);
        }
        LINFO("No config file found, creating one");
        program.save("./config.yml");
    }

    try {
        program.parse(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    return program;
}

void signalHandler(int sig)
{
    if (sig != SIGINT && sig != SIGTERM)
        return;
    Server::getInstance()->stop();
}

int main(int argc, char *argv[])
{
    auto program = initArgs(argc, argv);

    auto srv = Server::getInstance();

    InterfaceContainer interfaceContainer;
    CommandLine cmd;

    auto logger = logging::Logger::get_instance();
    logger->unset_display_specification_level_in_console(logging::LogLevel::DEBUG);

    if (program["nogui"] == false)
        interfaceContainer.launch(argc, argv);

    std::signal(SIGTERM, signalHandler);
    std::signal(SIGINT, signalHandler);
    std::signal(SIGPIPE, SIG_IGN);

    // This should be inside the server
    cmd.launch();

    srv->launch(program);

    cmd.stop();
    interfaceContainer.stop();
    return 0;
}
