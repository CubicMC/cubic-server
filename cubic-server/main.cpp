#include <argparse/argparse.hpp>
#include <csignal>
#include <cstring>
#include <iostream>
#include <thread>

#include "CommandLine.hpp"
#include "Server.hpp"
#include "interface/InterfaceContainer.hpp"
#include "logging/Logger.hpp"
#include "protocol/ServerPackets.hpp"
#include "world_storage/Persistence.hpp"

argparse::ArgumentParser argParser(int argc, char **argv)
{
    argparse::ArgumentParser program("cubic_server");

    program.add_argument("--nogui").help("prevents the GUI from displaying").default_value(false).implicit_value(true);
    try {
        program.parse_args(argc, argv);
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

int main(int argc, char **argv)
{
    // Server::getInstance()->_globalPalette.initialize(std::string("blocks-") + MC_VERSION + ".json");
    // LINFO("GlobalPalette initialized");
    // world_storage::Persistence augh("world");
    // u128 uuid = {0xbe74ad46b9c14fc3, 0xb63024159d0de399};
    // auto bruh = augh.loadPlayerData(uuid);
    // std::cout << bruh.uuid.toString() << std::endl;
    // augh.loadRegion(0, 0);
    // return 0;
    argparse::ArgumentParser program = argParser(argc, argv);
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
}
