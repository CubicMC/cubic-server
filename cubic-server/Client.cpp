#include <iostream>
#include <unistd.h>
#include <poll.h>
#include <cstring>

#include "Client.hpp"

Client::Client(int sockfd, struct sockaddr_in addr)
    : _sockfd(sockfd), _addr(addr)
{
    _is_running = true;
}

Client::~Client()
{
}

void Client::networkLoop()
{
    struct pollfd poll_set[1];
    uint8_t in_buffer[2048];

    poll_set[0].fd = _sockfd;
    while (1)
    {
        poll_set[0].events = POLLIN;
        if (!_send_buffer.empty())
            poll_set[0].events |= POLLOUT;
        poll(poll_set, 1, 50); // TODO: Check how this can be changed
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

void Client::_sendData()
{
    char send_buffer[2048];
    size_t to_send = std::min(_send_buffer.size(), (size_t)2048);
    std::copy(_send_buffer.begin(), _send_buffer.begin() + to_send, send_buffer);

    ssize_t write_return = write(_sockfd, send_buffer, to_send);
    if (write_return == -1)
        std::cerr << "Write error: " << strerror(errno) << std::endl;

    if (write_return <= 0)
        return;

    _send_buffer.erase(_send_buffer.begin(), _send_buffer.begin() + write_return);
}

std::vector<uint8_t> &Client::get_recv_buffer()
{
    return _recv_buffer;
}
