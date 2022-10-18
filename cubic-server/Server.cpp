#include <iostream>
#include <netdb.h>
#include <cerrno>
#include <sys/socket.h>
#include <poll.h>
#include <thread>
#include <chrono>
#include <exception>
#include <cstring>
#include <algorithm>

#include <nlohmann/json.hpp>

#include "Server.hpp"

#include "typeSerialization.hpp"
#include "ServerPackets.hpp"
#include "ClientPackets.hpp"

#include "Logger.hpp"

Server::Server()
    : _config("config.yml")
{
    _host = _config.getNode("ip").as<std::string>();
    _port = _config.getNode("port").as<uint16_t>();
    _log = logging::Logger::get_instance();
    _log->debug("Server created with host: " + _host + " and port: " + std::to_string(_port));
}

Server::~Server()
{
    _log->debug("Server destroyed");
}

void Server::launch()
{
    // Get the socket for the server
    _sockfd = socket(AF_INET, SOCK_STREAM, getprotobyname("TCP")->p_proto);

    // Create the addr for the server
    if (!inet_pton(AF_INET, _host.c_str(), &(_addr.sin_addr)))
    {
        throw std::runtime_error("Invalid host ip address");
    }
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(_port);

    // Bind server socket
    int optval = 1;
    setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    if (bind(_sockfd, reinterpret_cast<struct sockaddr *>(&_addr), sizeof(_addr)))
    {
        throw std::runtime_error(strerror(errno));
    }

    // Listen
    listen(_sockfd, SOMAXCONN);

    auto acceptThread = std::thread(&Server::_acceptLoop, this);

    _gameLoop();
}

[[noreturn]] void Server::_gameLoop()
{
    while (true)
    {
        // This is only for test purposes
        // TODO: Remove all that
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(50ms); // TODO: Change it to proper ticking
        _gameTick();
//        std::cout << "Server ticked" << std::endl;
    }
}

void Server::_gameTick()
{
    for (const auto& i : _clients)
        _handleClientPacket(i);
    // TODO: All the server ticking here
}

void Server::_handleClientPacket(std::shared_ptr<Client> cli)
{
    auto &data = cli->get_recv_buffer();
    while (true) {
        // Get the length of the packet stored
        auto buffer_length = data.size();
        if (buffer_length == 0)
            break;
        uint8_t *at = data.data();
        uint8_t *eof = at + buffer_length - 1;
        int32_t length = 0;
        try {
            length = protocol::popVarInt(at, eof);
            if (length > eof - at + 1)
                break; // Not enough data in buffer to parse the packet
            if (length == 0) {
                data.erase(data.begin());
                continue;
            }
        } catch (const protocol::PacketEOF &_) {
            break; // Not enough data in buffer to parse the length of the packet
        }
        const uint8_t *start_payload = at;
        // Handle the packet if the length is there
        const auto packet_id = static_cast<protocol::ServerPacketsID>(protocol::popVarInt(at, eof));
        auto status = cli->getStatus();
        std::function<std::shared_ptr<protocol::BaseServerPacket>(std::vector<uint8_t> &)> parser;
        PARSER_IT_DECLARE(Initial);
        PARSER_IT_DECLARE(Login);
        PARSER_IT_DECLARE(Status);
        PARSER_IT_DECLARE(Play);
        switch (status) {
        case protocol::ClientStatus::Initial:
            GET_PARSER(Initial);
        case protocol::ClientStatus::Login:
            GET_PARSER(Login);
        case protocol::ClientStatus::Status:
            GET_PARSER(Status);
        case protocol::ClientStatus::Play:
            GET_PARSER(Play);
        }
        std::vector<uint8_t> to_parse(data.begin() + (at - data.data()), data.end());
        auto packet = parser(to_parse);
        // Callback to handle the packet
        _handleParsedClientPacket(cli, packet, packet_id);
        data.erase(data.begin(), data.begin() + (start_payload - data.data()) + length);
    }
}

void Server::_acceptLoop()
{
    struct pollfd poll_set[1];

    poll_set[0].fd = _sockfd;
    poll_set[0].events = POLLIN;
    while (true)
    {
        poll(poll_set, 1, 50);
        if (poll_set[0].revents & POLLIN)
        {
            struct sockaddr_in client_addr{};
            socklen_t client_addr_size = sizeof(client_addr);
            int client_fd = accept(
                _sockfd,
                reinterpret_cast<struct sockaddr *>(&client_addr),
                &client_addr_size);
            if (client_fd == -1)
            {
                throw std::runtime_error(strerror(errno));
            }
            // Add accepted client to the vector of clients
            auto cli = std::make_shared<Client>(client_fd, client_addr);
            _clients.push_back(cli);
            // That line is kinda borked, but I'll check one day how to fix it
            auto *cli_thread = new std::thread(&Client::networkLoop, &(*cli));
            // That is 99.99% a data race, but aight, it will probably
            // never happen
            cli->setRunningThread(cli_thread);

//            std::cout << "Client added to the list" << std::endl;
        }

        _clients.erase(std::remove_if(
                           _clients.begin(), _clients.end(),
                           [](const std::shared_ptr<Client> &cli)
                           { return cli->isDisconnected(); }),
                       _clients.end());
    }
}

void Server::_handleParsedClientPacket(std::shared_ptr<Client> cli,
                                       const std::shared_ptr<protocol::BaseServerPacket>& packet,
                                       protocol::ServerPacketsID packetID)
{
    using namespace protocol;

    auto status = cli->getStatus();

    switch (status) {
    case ClientStatus::Initial:
        switch (packetID) {
        case ServerPacketsID::Handshake:
            PCK_CALLBACK(_onHandshake, Handshake);
        default:
            break;
        }
        break;
    case ClientStatus::Status:
        switch (packetID) {
        case ServerPacketsID::StatusRequest:
            PCK_CALLBACK(_onStatusRequest, StatusRequest);
        case ServerPacketsID::PingRequest:
            PCK_CALLBACK(_onPingRequest, PingRequest);
        default:
            break;
        }
        break;
    case ClientStatus::Login:
        switch (packetID) {
        case ServerPacketsID::LoginStart:
            PCK_CALLBACK(_onLoginStart, LoginStart);
        case ServerPacketsID::EncryptionResponse:
            PCK_CALLBACK(_onEncryptionResponse, EncryptionResponse);
        default:
            break;
        }
        break;
    case ClientStatus::Play:
        switch (packetID) {
        case ServerPacketsID::ConfirmTeleportation:
            PCK_CALLBACK(_onConfirmTeleportation, ConfirmTeleportation);
        case ServerPacketsID::QueryBlockEntityTag:
            PCK_CALLBACK(_onQueryBlockEntityTag, QueryBlockEntityTag);
        case ServerPacketsID::ChangeDifficulty:
            PCK_CALLBACK(_onChangeDifficulty, ChangeDifficulty);
        case ServerPacketsID::ClientCommand:
            PCK_CALLBACK(_onClientCommand, ClientCommand);
        case ServerPacketsID::ClientInformation:
            PCK_CALLBACK(_onClientInformation, ClientInformation);
        case ServerPacketsID::CommandSuggestionRequest:
            PCK_CALLBACK(_onCommandSuggestionRequest, CommandSuggestionRequest);
        case ServerPacketsID::ClickContainerButton:
            PCK_CALLBACK(_onClickContainerButton, ClickContainerButton);
        case ServerPacketsID::CloseContainerRequest:
            PCK_CALLBACK(_onCloseContainerRequest, CloseContainerRequest);
        case ServerPacketsID::EditBook:
            PCK_CALLBACK(_onEditBook, EditBook);
        case ServerPacketsID::QueryEntityTag:
            PCK_CALLBACK(_onQueryEntityTag, QueryEntityTag);
        case ServerPacketsID::Interact:
            PCK_CALLBACK(_onInteract, Interact);
        case ServerPacketsID::JigsawGenerate:
            PCK_CALLBACK(_onJigsawGenerate, JigsawGenerate);
        case ServerPacketsID::KeepAliveResponse:
            PCK_CALLBACK(_onKeepAliveResponse, KeepAliveResponse);
        case ServerPacketsID::LockDifficulty:
            PCK_CALLBACK(_onLockDifficulty, LockDifficulty);
        case ServerPacketsID::SetPlayerPosition:
            PCK_CALLBACK(_onSetPlayerPosition, SetPlayerPosition);
        case ServerPacketsID::SetPlayerPositionAndRotation:
            PCK_CALLBACK(_onSetPlayerPositionAndRotation, SetPlayerPositionAndRotation);
        case ServerPacketsID::SetPlayerRotation:
            PCK_CALLBACK(_onSetPlayerRotation, SetPlayerRotation);
        case ServerPacketsID::SetPlayerOnGround:
            PCK_CALLBACK(_onSetPlayerOnGround, SetPlayerOnGround);
        case ServerPacketsID::MoveVehicle:
            PCK_CALLBACK(_onMoveVehicle, MoveVehicle);
        case ServerPacketsID::PaddleBoat:
            PCK_CALLBACK(_onPaddleBoat, PaddleBoat);
        case ServerPacketsID::PickItem:
            PCK_CALLBACK(_onPickItem, PickItem);
        case ServerPacketsID::PlaceRecipe:
            PCK_CALLBACK(_onPlaceRecipe, PlaceRecipe);
        case ServerPacketsID::PlayerAbilities:
            PCK_CALLBACK(_onPlayerAbilities, PlayerAbilities);
        case ServerPacketsID::PlayerAction:
            PCK_CALLBACK(_onPlayerAction, PlayerAction);
        case ServerPacketsID::PlayerCommand:
            PCK_CALLBACK(_onPlayerCommand, PlayerCommand);
        case ServerPacketsID::PlayerInput:
            PCK_CALLBACK(_onPlayerInput, PlayerInput);
        case ServerPacketsID::Pong:
            PCK_CALLBACK(_onPong, Pong);
        case ServerPacketsID::ChangeRecipeBookSettings:
            PCK_CALLBACK(_onChangeRecipeBookSettings, ChangeRecipeBookSettings);
        case ServerPacketsID::SetSeenRecipe:
            PCK_CALLBACK(_onSetSeenRecipe, SetSeenRecipe);
        case ServerPacketsID::RenameItem:
            PCK_CALLBACK(_onRenameItem, RenameItem);
        case ServerPacketsID::ResourcePack:
            PCK_CALLBACK(_onResourcePack, ResourcePack);
        case ServerPacketsID::SeenAdvancements:
            PCK_CALLBACK(_onSeenAdvancements, SeenAdvancements);
        case ServerPacketsID::SelectTrade:
            PCK_CALLBACK(_onSelectTrade, SelectTrade);
        case ServerPacketsID::SetBeaconEffect:
            PCK_CALLBACK(_onSetBeaconEffect, SetBeaconEffect);
        case ServerPacketsID::SetHeldItem:
            PCK_CALLBACK(_onSetHeldItem, SetHeldItem);
        case ServerPacketsID::ProgramCommandBlock:
            PCK_CALLBACK(_onProgramCommandBlock, ProgramCommandBlock);
        case ServerPacketsID::ProgramCommandBlockMinecart:
            PCK_CALLBACK(_onProgramCommandBlockMinecart, ProgramCommandBlockMinecart);
        case ServerPacketsID::ProgramJigsawBlock:
            PCK_CALLBACK(_onProgramJigsawBlock, ProgramJigsawBlock);
        default:
            break;
        }
        break;
    }
    _log->error("Unhandled packet: " + std::to_string(static_cast<int>(packetID)) +
        " in status " + std::to_string(static_cast<int>(status))); // TODO: Properly handle the unknown packet
}

void Server::_onHandshake(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::Handshake>& pck)
{
    _log->debug("Got an handshake");
    if (pck->next_state == 1)
        cli->setStatus(protocol::ClientStatus::Status);
    else if (pck->next_state == 2)
        cli->setStatus(protocol::ClientStatus::Login);
}

void Server::_onStatusRequest(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::StatusRequest> &pck)
{
    _log->debug("Got a status request");

    nlohmann::json json;
    json["version"]["name"] = "1.19"; // TODO: Change with a non hardcoded value
    json["version"]["protocol"] = 759; // TODO: change with a non hardcoded value equal to the protocol version we are using
    json["players"]["max"] = _config.getNode("max_players").as<int>();
    json["players"]["online"] = std::count_if(_clients.begin(), _clients.end(), [](std::shared_ptr<Client> &each) { return each->getStatus() == protocol::ClientStatus::Play; });
    json["description"]["text"] = _config.getNode("motd").as<std::string>();
    // json["favicon"] = DEFAULT_FAVICON; // TODO: get it from the config ? // this invalid the packet if present but idk why
    json["previewsChat"] = false; // TODO: check what we want to do with this
    json["enforcesSecureChat"] = false; // TODO: check what we want to do with this
    std::string status = json.dump();
    _log->debug("Json status: " + status);

    const protocol::StatusResponse status_res(status);
    auto status_res_pck = protocol::createStatusResponse(status_res);
    cli->sendData(*status_res_pck);

    _log->debug("Sent status response");
}

void Server::_onPingRequest(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PingRequest> &pck)
{
    _log->debug("Got a ping request with payload: " + std::to_string(pck->payload));

    const protocol::PingResponse ping_res(pck->payload);
    auto ping_res_pck = protocol::createPingResponse(ping_res);
    cli->sendData(*ping_res_pck);

    _log->debug("Sent a ping response");
}

void Server::_onConfirmTeleportation(std::shared_ptr<Client> cli,
                                     const std::shared_ptr<protocol::ConfirmTeleportation> &pck)
{
    _log->debug("Got a Confirm Teleportation");
}

void Server::_onQueryBlockEntityTag(std::shared_ptr<Client> cli,
                                    const std::shared_ptr<protocol::QueryBlockEntityTag> &pck)
{
    _log->debug("Got a Query Block Entity Tag");
}

void Server::_onChangeDifficulty(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ChangeDifficulty> &pck)
{
    _log->debug("Got a Change difficulty");
}

void Server::_onClientCommand(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ClientCommand> &pck)
{
    _log->debug("Got a Client Command");
}

void Server::_onClientInformation(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ClientInformation> &pck)
{
    _log->debug("Got a Client Information");
}

void Server::_onCommandSuggestionRequest(std::shared_ptr<Client> cli,
                                         const std::shared_ptr<protocol::CommandSuggestionRequest> &pck)
{
    _log->debug("Got a Command Suggestion Request");
}

void Server::_onClickContainerButton(std::shared_ptr<Client> cli,
                                     const std::shared_ptr<protocol::ClickContainerButton> &pck)
{
    _log->debug("Got a Click Container Button");
}

void Server::_onCloseContainerRequest(std::shared_ptr<Client> cli,
                                      const std::shared_ptr<protocol::CloseContainerRequest> &pck)
{
    _log->debug("Got a Close Container Request");
}

void Server::_onEditBook(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::EditBook> &pck)
{
    _log->debug("Got a Edit Book");
}

void Server::_onQueryEntityTag(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::QueryEntityTag> &pck)
{
    _log->debug("Got a Query Entity Tag");
}

void Server::_onLoginStart(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::LoginStart> &pck)
{
    _log->debug("Got a Login Start");
}

void Server::_onEncryptionResponse(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::EncryptionResponse> &pck)
{
    _log->debug("Got a Encryption Response");
}

void Server::_onInteract(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::Interact> &pck)
{
    _log->debug("Got a Interact");
}

void Server::_onJigsawGenerate(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::JigsawGenerate> &pck)
{
    _log->debug("Got a Jigsaw Generate");
}

void Server::_onKeepAliveResponse(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::KeepAliveResponse> &pck)
{
    _log->debug("Got a Keep Alive Response");
}

void Server::_onLockDifficulty(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::LockDifficulty> &pck)
{
    _log->debug("Got a Lock Difficulty");
}

void Server::_onSetPlayerPosition(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetPlayerPosition> &pck)
{
    _log->debug("Got a Set Player Position");
}

void Server::_onSetPlayerPositionAndRotation(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck)
{
    _log->debug("Got a Set Player Position And Rotation");
}

void Server::_onSetPlayerRotation(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetPlayerRotation> &pck)
{
    _log->debug("Got a Set Player Rotation");
}

void Server::_onSetPlayerOnGround(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetPlayerOnGround> &pck)
{
    _log->debug("Got a Set Player On Ground");
}

void Server::_onMoveVehicle(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::MoveVehicle> &pck)
{
    _log->debug("Got a Move Vehicle");
}

void Server::_onPaddleBoat(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PaddleBoat> &pck)
{
    _log->debug("Got a Paddle Boat");
}

void Server::_onPickItem(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PickItem> &pck)
{
    _log->debug("Got a Pick Item");
}

void Server::_onPlaceRecipe(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlaceRecipe> &pck)
{
    _log->debug("Got a Place Recipe");
}

void Server::_onPlayerAbilities(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlayerAbilities> &pck)
{
    _log->debug("Got a Player Abilities");
}

void Server::_onPlayerAction(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlayerAction> &pck)
{
    _log->debug("Got a Player Action");
}

void Server::_onPlayerCommand(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlayerCommand> &pck)
{
    _log->debug("Got a Player Command");
}

void Server::_onPlayerInput(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlayerInput> &pck)
{
    _log->debug("Got a Player Input");
}

void Server::_onPong(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::Pong> &pck)
{
    _log->debug("Got a Pong");
}

void Server::_onChangeRecipeBookSettings(std::shared_ptr<Client> cli,
                                         const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck)
{
    _log->debug("Got a Change Recipe Book Settings");
}

void Server::_onSetSeenRecipe(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetSeenRecipe> &pck)
{
    _log->debug("Got a Set Seen Recipe");
}

void Server::_onRenameItem(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::RenameItem> &pck)
{
    _log->debug("Got a Rename Item");
}

void Server::_onResourcePack(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ResourcePack> &pck)
{
    _log->debug("Got a Resource Pack");
}

void Server::_onSeenAdvancements(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SeenAdvancements> &pck)
{
    _log->debug("Got a Seen Advancements");
}

void Server::_onSelectTrade(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SelectTrade> &pck)
{
    _log->debug("Got a Select Trade");
}

void Server::_onSetBeaconEffect(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetBeaconEffect> &pck)
{
    _log->debug("Got a Set Beacon Effect");
}

void Server::_onSetHeldItem(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetHeldItem> &pck)
{
    _log->debug("Got a Set Held Item");
}

void Server::_onProgramCommandBlock(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ProgramCommandBlock> &pck)
{
    _log->debug("Got a Program Command Block");
}

void Server::_onProgramCommandBlockMinecart(std::shared_ptr<Client> cli,
                                             const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck)
{
    _log->debug("Got a Program Command Block Minecart");
}

void Server::_onProgramJigsawBlock(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ProgramJigsawBlock> &pck)
{
    _log->debug("Got a Program Jigsaw Block");
}
