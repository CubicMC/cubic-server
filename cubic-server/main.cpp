#include <iostream>
#include <string.h>

#include "Server.hpp"
#include "ServerPackets.hpp"

static void print_usage(const char *caller)
{
    std::cout << "Usage:\n\t" << caller << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<uint8_t> test = {0x5, 0x1, 'h', 0x69, 0x69, 0x1};
    std::shared_ptr<protocol::Handshake> result = protocol::parseHandshake(test);
    std::cout << "prot version: " << result->prot_version << std::endl;
    std::cout << "addr: " << result->addr << std::endl;
    std::cout << "port: " << result->port << std::endl;
    std::cout << "next state: " << result->next_state << std::endl;
    return 0;
    if (argc >= 2 && !strcmp(argv[1], "-h"))
    {
        print_usage(argv[0]);
        return 0;
    }

    auto srv = Server("0.0.0.0", 25565);
    srv.launch();
}
