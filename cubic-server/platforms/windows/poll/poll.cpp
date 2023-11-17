#include "platforms/windows/poll/poll.hpp"
#include <winsock2.h>

int poll(pollfd *__fds, nfds_t __nfds, int __timeout)
{
    LPWSAPOLLFD fds = new pollfd[__nfds];

    for (nfds_t i = 0; i < __nfds; i++) {
        fds[i].fd = __fds[i].fd;
        fds[i].events = __fds[i].events;
        fds[i].revents = __fds[i].revents;
    }

    auto result = WSAPoll(fds, __nfds, __timeout);

    for (nfds_t i = 0; i < __nfds; i++)
        __fds[i].revents = fds[i].revents;

    delete[] fds;
    return result;
}
