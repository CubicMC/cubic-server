#include "cubic-protocol/c2s/handshake.hpp"

#include "client.hpp"

namespace cubic::server::client::hpcb {

auto handshake(Client &cli, const protocol::c2s::handshake::Handshake &pck) -> void
{
    printf("addr: %s\n", pck.server_address.c_str());
    printf("protocol_version: %d\n", pck.protocol_version);
    printf("next_state: %d\n", pck.next_state);
    printf("port: %d\n", pck.server_port);
}

} // namespace cubic::server::client::hpcb
