#include <iostream>
#include <cstring>
#include <argparse/argparse.hpp>
#include <csignal>
#include <thread>

#include "Server.hpp"
#include "logging/Logger.hpp"
#include "protocol/ServerPackets.hpp"
#include "interface/InterfaceContainer.hpp"
#include "CommandLine.hpp"

argparse::ArgumentParser argParser(int argc, char **argv)
{
    argparse::ArgumentParser program("cubic_server");

    program.add_argument("--nogui")
        .help("prevents the GUI from displaying")
        .default_value(false)
        .implicit_value(true);
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
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
    argparse::ArgumentParser program = argParser(argc, argv);
    auto srv = Server::getInstance();

    InterfaceContainer interfaceContainer;
    CommandLine cmd;

    auto logger = logging::Logger::get_instance();
    //logger->unset_display_specification_level_in_console(logging::LogLevel::DEBUG);

    if (program["--nogui"] == false)
        interfaceContainer.launch(argc, argv);

    std::signal(SIGTERM, signalHandler);
    std::signal(SIGINT, signalHandler);

    // This should be inside the server
    cmd.launch();

    srv->launch();

    cmd.stop();
    interfaceContainer.stop();
}
