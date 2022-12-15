#include <iostream>
#include <cstring>

#include "Server.hpp"
#include "protocol/ServerPackets.hpp"
#include "interface/ManagementInterface.hpp"

static void print_usage(const char *caller)
{
    std::cout << "Usage:\n\t" << caller << std::endl;
}

// Uncomment that to launch the interface
// #define INTERFACE

int main(int argc, char **argv)
{
    if (argc >= 2 && !strcmp(argv[1], "-h"))
    {
        print_usage(argv[0]);
        return 0;
    }

    auto srv = Server::getInstance();
    ///
#ifdef INTERFACE
    auto InterfaceThread = std::thread(&ManagementInterface::launch, argc, argv);
#endif
    ///

    srv->launch();
}
