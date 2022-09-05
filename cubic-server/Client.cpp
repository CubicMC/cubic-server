#include <iostream>
#include <unistd.h>
#include <poll.h>
#include <string.h>

#include "Client.hpp"

Client::Client(int sockfd, struct sockaddr_in addr)
    : _sockfd(sockfd), _addr(addr)
{
    std::cout << "Client created" << std::endl;
    _is_running = true;
}

Client::~Client()
{
    std::cout << "Client destroyed" << std::endl;
}

void Client::networkLoop()
{
    struct pollfd poll_set[1];
    uint8_t in_buffer[2048];

    poll_set[0].fd = _sockfd;
    poll_set[0].events = POLLIN;
    while (1)
    {
        poll(poll_set, 1, -1);
        if (poll_set[0].revents & POLLIN)
        {
            int read_size = read(_sockfd, in_buffer, 2048);
            if (read_size == -1)
                std::cerr << "Read error: " << strerror(errno) << std::endl;
            else if (read_size == 0)
                break;
            else
            {
                // This is extremely inefficient but it will do for now
                for (int i = 0; i < read_size; i++)
                    _recv_buffer.push_back(in_buffer[i]);
                std::cout << "Received " << read_size << " bytes of data!" << std::endl;
                std::cout << "Size of deque: " << _recv_buffer.size() << std::endl;
            }
        }
    }
    _is_running = false;
}

std::thread *Client::getRunningThread()
{
    return _current_thread;
}

void Client::setRunningThread(std::thread *thread)
{
    _current_thread = thread;
}

bool Client::isDisconnected() const
{
    return !_is_running;
}
