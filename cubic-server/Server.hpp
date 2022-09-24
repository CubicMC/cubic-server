#ifndef F43D56DD_C750_470F_A7C9_27CE21D37FC3
#define F43D56DD_C750_470F_A7C9_27CE21D37FC3

#include <stdint.h>
#include <string>
#include <vector>
#include <arpa/inet.h>
#include <memory>

#include "Client.hpp"

class Server
{
public:
    Server(const std::string &host, uint16_t port);
    ~Server();

    int launch();

private:
    void acceptLoop();
    void gameLoop();

    const std::string &_host;
    const uint16_t _port;

    // Looks like it is thread-safe, if something breaks it is here
    std::vector<std::shared_ptr<Client>> _clients;

    int _sockfd;
    struct sockaddr_in _addr;
};

#endif /* F43D56DD_C750_470F_A7C9_27CE21D37FC3 */
