#include <iostream>
#include <cstring>
#include <unordered_map>
#include <functional>

#include <argparse/argparse.hpp>
#include "Server.hpp"
#include "protocol/ServerPackets.hpp"
#include "interface/ManagementInterface.hpp"

bool arg_parser(int argc, char **argv) {
    argparse::ArgumentParser program("cubic_server");

    program.add_argument("--nogui")
        .help("prevents the GUI from displaying")
        .default_value(true)
        .implicit_value(false);
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    if (program["--nogui"] == false) {
        return false;
    }
    return true;

}

int main(int argc, char **argv)
{
    bool gui = arg_parser(argc, argv);
    std::thread InterfaceThread;

    if (gui) {
        InterfaceThread = std::thread(&ManagementInterface::launch, argc, argv);
    }

    auto srv = Server::getInstance();
    srv->launch();
}
