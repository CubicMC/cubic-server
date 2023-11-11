#include <argparse/argparse.hpp>
#include <csignal>
#include <cstring>
#include <iostream>
#include <limits>
#include <thread>

#include "CommandLine.hpp"
#include "Server.hpp"
#include "logging/logging.hpp"
#include "options.hpp"
#include "protocol/ServerPackets.hpp"
#include "world_storage/Persistence.hpp"

#if GUI_UNAVAILABLE == 0
#include "interface/InterfaceContainer.hpp"
#endif

auto initArgs(int argc, const char *const argv[])
{
    auto program = configuration::ConfigHandler(PROGRAM_NAME, PROGRAM_VERSION);

    // clang-format off
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

    program.add("compression")
        .help("enables compression of the protocol")
        .valueFromConfig("network", "compression")
        .valueFromEnvironmentVariable("CBSRV_COMPRESSION")
        .defaultValue(true)
        .required();

    program.add("compression-level")
        .help("sets the zlib compression level for outbound packets (0-9, 9 best compression)")
        .valueFromConfig("network", "compression-level")
        .valueFromEnvironmentVariable("CBSRV_COMPRESSION_LEVEL")
        .defaultValue(6)
        .inRange(0, 9)
        .required();

    program.add("compression-threshold")
        .help("Minimum of bytes in a packet before compressing it")
        .valueFromConfig("network", "compression-threshold")
        .valueFromEnvironmentVariable("CBSRV_COMPRESSION_THRESHOLD")
        .defaultValue(256)
        .inRange(0, std::numeric_limits<int32_t>::max())
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

    program.add("whitelist-enabled")
        .help("enables the whitelist")
        .valueFromConfig("general", "whitelist-enabled")
        .valueFromEnvironmentVariable("CBSRV_WHITELIST_ENABLED")
        .possibleValues(true, false)
        .defaultValue(false)
        .required();

    program.add("enforce-whitelist")
        .help("enforces the whitelist")
        .valueFromConfig("general", "enforce-whitelist")
        .valueFromEnvironmentVariable("CBSRV_ENFORCE_WHITELIST")
        .possibleValues(true, false)
        .defaultValue(false)
        .required();

    program.add("enable-generation")
        .help("Enables chunk generation")
        .valueFromConfig("generation", "enable-generation")
        .valueFromEnvironmentVariable("CBSRV_ENABLE_GENERATION")
        .valueFromArgument("--enable-generation")
        .possibleValues(true, false)
        .defaultValue(true);

    program.add("level-name")
        .help("Name of the world")
        .valueFromConfig("general", "level-name")
        .valueFromEnvironmentVariable("CBSRV_LEVEL_NAME")
        .valueFromArgument("--level-name")
        .defaultValue("world");

    program.add("num-gen-thread")
        .help("Number of threads allocated to chunk generation")
        .valueFromConfig("generation", "num-gen-thread")
        .valueFromEnvironmentVariable("CBSRV_NUM_GEN_THREAD")
        .valueFromArgument("--num-gen-thread")
        .inRange((unsigned int)1, std::thread::hardware_concurrency())
        .defaultValue(4);

    program.add("world-type")
        .help("World type to generate")
        .valueFromConfig("generation", "world-type")
        .valueFromEnvironmentVariable("CBSRV_LEVEL_TYPE")
        .valueFromArgument("--world-type")
        .possibleValues("default", "superflat", "largebiome", "amplified", "singlebiome", "debug", "superflat_cubic_server")
        .defaultValue("default");

    program.add("seed")
        .help("Seed to use for world generation")
        .valueFromConfig("generation", "seed")
        .valueFromEnvironmentVariable("CBSRV_SEED")
        .valueFromArgument("--seed")
        .defaultValue(-721274728);

    program.add("render-distance")
        .help("Render distance")
        .valueFromConfig("general", "render-distance")
        .valueFromEnvironmentVariable("CBSRV_RENDER_DISTANCE")
        .valueFromArgument("--render-distance")
        .defaultValue(10);

    program.add("online-mode")
        .help("Enable client/server encryption and only accepts legitimate accounts")
        .valueFromConfig("general", "online-mode")
        .valueFromEnvironmentVariable("CBSRV_ONLINE_MODE")
        .valueFromArgument("--online-mode")
        .possibleValues(false, true)
        .defaultValue(true);

    program.add("gamemode")
        .help("Default gamemode")
        .valueFromConfig("general", "gamemode")
        .valueFromEnvironmentVariable("CBSRV_GAMEMODE")
        .possibleValues("creative", "survival", "adventure", "spectator")
        .defaultValue("survival");

    program.add("world-border")
        .help("Set the world border")
        .valueFromConfig("general", "world-border")
        .valueFromEnvironmentVariable("CBSRV_WORLD_BORDER")
        .valueFromArgument("--world-border")
        .defaultValue(10000);

    program.add("randomtickspeed")
        .help("Set the randomtickspeed")
        .valueFromConfig("gamerule", "randomtickspeed")
        .valueFromEnvironmentVariable("CBSRV_RANDOMTICKSPEED")
        .valueFromArgument("--randomtickspeed")
        .defaultValue(3)
        .inRange(0, std::numeric_limits<int32_t>::max());

    program.add("monitoring-prometheus-enable")
        .help("Enable prometheus data exporting")
        .valueFromConfig("monitoring", "prometheus", "enable")
        .valueFromEnvironmentVariable("CBSRV_MONITORING_PROMETHEUS_ENABLE")
        .valueFromArgument("--monitoring-prometheus-enable")
        .defaultValue(false)
        .implicit();

    program.add("monitoring-prometheus-ip")
        .help("Prometheus IP")
        .valueFromConfig("monitoring", "prometheus", "ip")
        .valueFromEnvironmentVariable("CBSRV_MONITORING_PROMETHEUS_IP")
        .valueFromArgument("--monitoring-prometheus-ip")
        .defaultValue("0.0.0.0");

    program.add("monitoring-prometheus-port")
        .help("Prometheus port")
        .valueFromConfig("monitoring", "prometheus", "port")
        .valueFromEnvironmentVariable("CBSRV_MONITORING_PROMETHEUS_PORT")
        .valueFromArgument("--monitoring-prometheus-port")
        .defaultValue("8080");
    // clang-format on

    try {
        program.load("./config.yml");
    } catch (const configuration::BadFile &) {
        if (std::filesystem::exists("./config.yml")) {
            LERROR("Failed to open config file, check permissions");
            std::exit(1);
        }
        LWARN("No config file found, creating one");
        program.save("./config.yml");
    }

    try {
        program.parse(argc, argv);
    } catch (const std::runtime_error &err) {
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

#if GUI_UNAVAILABLE == 0
    InterfaceContainer interfaceContainer;
#endif

    CommandLine cmd;

    std::signal(SIGTERM, signalHandler);
    std::signal(SIGINT, signalHandler);
    std::signal(SIGPIPE, SIG_IGN);

#if GUI_UNAVAILABLE == 0
    if (program["nogui"] == false)
        interfaceContainer.launch(argc, argv);
#endif

    try {
        // This should be inside the server
        cmd.launch();

        srv->launch(program);

        cmd.stop();
#if GUI_UNAVAILABLE == 0
        interfaceContainer.stop();
#endif
    } catch (const std::exception &e) {
        LFATAL(e.what());
        srv->stop();
        srv->_stop();
        cmd.stop();
        return 1;
    }

    cmd.stop();

#if GUI_UNAVAILABLE == 0
    interfaceContainer.stop();
#endif
    return 0;
}
