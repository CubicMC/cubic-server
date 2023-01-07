#include <iostream>
#include <cstring>

#include <argparse/argparse.hpp>
#include "Server.hpp"
#include "protocol/ServerPackets.hpp"
#include "interface/ManagementInterface.hpp"

argparse::ArgumentParser argParser(int argc, char **argv) {
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

int main(int argc, char **argv)
{
    argparse::ArgumentParser program = argParser(argc, argv);
    std::thread InterfaceThread;

    if (program["--nogui"] == false) {
        InterfaceThread = std::thread(&ManagementInterface::launch, argc, argv);
    }

    auto srv = Server::getInstance();
    srv->launch();
}
