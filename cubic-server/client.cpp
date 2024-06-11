#include <cassert>

#include "cubic-protocol/c2s/handshake.hpp"

#include "client.hpp"

namespace cubic::server::client::hpcb {

auto handshake(Client &cli, const protocol::c2s::handshake::Handshake &pck) -> void
{
    printf("Client %p old state: %d\n", &cli, (int32_t) cli.state);
    assert(cli.state == Client::state::Handshaking);
    assert(cli.isRunning == true);
    assert(pck.next_state == 1 || pck.next_state == 2 || pck.next_state == 3);

    printf("addr: %s\n", pck.server_address.c_str());
    printf("protocol_version: %d\n", pck.protocol_version);
    printf("next_state: %d\n", pck.next_state);
    printf("port: %d\n", pck.server_port);

    // TODO: Change that magic value to be defined somewhere
    if (pck.protocol_version != 766) {
        // TODO: Add a way to schedule a client to shutdown so that we can send it data before
        // killing it such as a disconnection notice
        cli.isRunning = false;
        return;
    }
    if (pck.next_state == 1)
        cli.state = Client::state::Status;
    else if (pck.next_state == 2)
        cli.state = Client::state::Login;
    else {
        // TODO: Handle transfers
        printf("Unsupported next state transfer in handshake\n");
    }
    printf("Client %p new state: %d\n", &cli, (int32_t) cli.state);
}

} // namespace cubic::server::client::hpcb
