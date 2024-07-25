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
    if (pck.protocol_version != CUBIC_MC_PROTOCOL) {
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
        // TODO: Shutdown state
        cli.isRunning = false;
    }
    printf("Client %p new state: %d\n", &cli, (int32_t) cli.state);
}

auto status_request(Client &cli, const protocol::c2s::status::StatusRequest &pck) -> void
{
    constexpr std::string_view base_status = R"({"version":{"name":"1.21","protocol":767}})";

    printf("Got a status request from client %p\n", &cli);
    // TODO: Answer the status request
}

auto ping_request(Client &cli, const protocol::c2s::status::PingRequest &pck) -> void
{
    printf("Got a ping request from client %p\n", &cli);
    // TODO
}

} // namespace cubic::server::client::hpcb
