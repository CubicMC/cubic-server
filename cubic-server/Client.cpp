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
    while (1)
    {
        poll_set[0].events = POLLIN;
        // if (_send_buffer.size() != 0)
        poll_set[0].events |= POLLOUT;
        poll(poll_set, 1, 50); // TODO: Check if this is can be changed
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
        if (poll_set[0].revents & POLLOUT)
        {
            _sendData();
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

void Client::sendData(const std::vector<uint8_t> &data)
{
    // This is extremely inefficient but it will do for now
    for (const auto i : data)
        _send_buffer.push_back(i);
}

void Client::_sendData(void)
{
    char send_buffer[2048];
    size_t to_send = _send_buffer.size() > 2048 ? 2048 : _send_buffer.size();
    std::copy(_send_buffer.begin(), _send_buffer.begin() + to_send, send_buffer);

    ssize_t write_return = write(_sockfd, send_buffer, to_send);
    if (write_return == -1)
        std::cerr << "Write error: " << strerror(errno) << std::endl;

    if (write_return <= 0)
        return;

    _send_buffer.erase(_send_buffer.begin(), _send_buffer.begin() + write_return);
}
