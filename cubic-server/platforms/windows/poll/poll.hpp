#pragma once

#include <winsock2.h>

using nfds_t = unsigned long int;

int poll(struct pollfd *__fds, nfds_t __nfds, int __timeout);
