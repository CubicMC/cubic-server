#ifndef CUBICSERVER_COMMON_HPP
#define CUBICSERVER_COMMON_HPP

#include <cstdint>

#define LIGHT_ARRAY_SIZE 2048

namespace protocol {
    enum class ClientStatus : int32_t {
        Initial = 0x00,
        Status = 0x01,
        Login = 0x02,
        Play = 0x03
    };
}

#endif //CUBICSERVER_COMMON_HPP
