#ifndef CUBICSERVER_COMMON_HPP
#define CUBICSERVER_COMMON_HPP

#include <cstdint>
#include <string>

namespace protocol {
enum class ClientStatus : int32_t {
    Initial = 0x00,
    Status = 0x01,
    Login = 0x02,
    Play = 0x03
};

struct PlayerProperty {
    PlayerProperty(std::string name, std::string value, bool isSigned, std::string signature):
        name(std::move(name)),
        value(std::move(value)),
        isSigned(isSigned),
        signature(std::move(signature))
    {
    }
    std::string name;
    std::string value;
    bool isSigned;
    std::string signature;
};
}

#endif // CUBICSERVER_COMMON_HPP
