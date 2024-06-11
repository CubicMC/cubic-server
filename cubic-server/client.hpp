#ifndef CUBIC_SERVER_CLIENT_
#define CUBIC_SERVER_CLIENT_

#include <cstdint>
#include <mutex>
#include <vector>

namespace cubic::protocol::c2s::handshake {
struct Handshake;
} // namespace cubic::protocol::c2s::handshake

namespace cubic::server::client {

class Client {
public:
    int fd;
    bool isRunning = true;
    enum class state {
        Handshaking = 1 << 8,
        Status = 2 << 8,
        Login = 3 << 8,
        Configuration = 4 << 8,
        Playing = 5 << 8,
    } state = state::Handshaking;
    std::vector<uint8_t> inBuffer;
    std::vector<uint8_t> outBuffer;
    std::vector<std::pair<int32_t, void *>> inPackets;
    std::vector<std::pair<int32_t, void *>> inHighPriorityPackets;
    mutable std::mutex outBufferMutex{};
    mutable std::mutex inPacketsMutex{};

    Client(int client_fd):
        fd(client_fd)
    {
    }
};

namespace hpcb {

auto handshake(Client &cli, protocol::c2s::handshake::Handshake &packet) -> void;

} // namespace hpcb

namespace lpcb {

} // namespace lpcb

} // namespace cubic::server::client

#endif // CUBIC_SERVER_CLIENT_
