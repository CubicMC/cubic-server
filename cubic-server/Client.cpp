#include <iostream>
#include <unistd.h>

#include "Client.hpp"

Client::Client(int sockfd, struct sockaddr_in addr)
{
    std::cout << "Client created" << std::endl;
    write(sockfd, "Aight mate\n", 11); // TODO: Remove
}

Client::~Client()
{
    std::cout << "Client destroyed" << std::endl;
}
