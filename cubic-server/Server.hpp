#ifndef F43D56DD_C750_470F_A7C9_27CE21D37FC3
#define F43D56DD_C750_470F_A7C9_27CE21D37FC3

#include <cstdint>
#include <string>
#include <vector>
#include <arpa/inet.h>
#include <memory>

#include "Client.hpp"
#include "ServerPackets.hpp"

#include "ConfigHandler.hpp"
#include "Logger.hpp"

#define PCK_CALLBACK(function, type) return this->function(cli, std::static_pointer_cast<type>(packet))

#define PARSER_IT_DECLARE(state) \
    std::unordered_map<protocol::ServerPacketsID, std::function<std::shared_ptr<protocol::BaseServerPacket>(std::vector<uint8_t> &)>>::const_iterator __##state

#define GET_PARSER(state) __##state = protocol::packetIDToParse##state.find(packet_id); \
    if (__##state == protocol::packetIDToParse##state.end()) \
        throw std::runtime_error("Unknown packet ID"); \
    parser = __##state->second;                                                                  \
    break

#define DEFAULT_FAVICON "data:image/png;base64,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"

class Server
{
public:
    Server();
    ~Server();

    void launch();

private:
    void _acceptLoop();

    [[noreturn]] void _gameLoop();
    void _gameTick();
    void _handleClientPacket(std::shared_ptr<Client> cli);
    void _handleParsedClientPacket(std::shared_ptr<Client> cli,
                                   const std::shared_ptr<protocol::BaseServerPacket>& packet,
                                   protocol::ServerPacketsID packetID);

    std::string _host;
    uint16_t _port;
    logging::Logger *_log;

    // Looks like it is thread-safe, if something breaks it is here
    std::vector<std::shared_ptr<Client>> _clients;

    int _sockfd;
    struct sockaddr_in _addr;

    // Packet handling (This will be moved somewhere else later)

    void _onHandshake(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::Handshake>& pck);
    void _onStatusRequest(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::StatusRequest>& pck);
    void _onLoginStart(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::LoginStart> &pck);
    void _onPingRequest(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PingRequest>& pck);
    void _onConfirmTeleportation(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ConfirmTeleportation>& pck);
    void _onEncryptionResponse(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::EncryptionResponse> &pck);
    void _onQueryBlockEntityTag(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::QueryBlockEntityTag>& pck);
    void _onChangeDifficulty(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ChangeDifficulty> &pck);
    void _onClientCommand(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ClientCommand> &pck);
    void _onClientInformation(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ClientInformation> &pck);
    void _onCommandSuggestionRequest(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::CommandSuggestionRequest> &pck);
    void _onClickContainerButton(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ClickContainerButton> &pck);
    void _onCloseContainerRequest(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::CloseContainerRequest> &pck);
    void _onEditBook(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::EditBook> &pck);
    void _onQueryEntityTag(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::QueryEntityTag> &pck);
    void _onInteract(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::Interact> &pck);
    void _onJigsawGenerate(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::JigsawGenerate> &pck);
    void _onKeepAliveResponse(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::KeepAliveResponse> &pck);
    void _onLockDifficulty(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::LockDifficulty> &pck);
    void _onSetPlayerPosition(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetPlayerPosition> &pck);
    void _onSetPlayerPositionAndRotation(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck);
    void _onSetPlayerRotation(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetPlayerRotation> &pck);
    void _onSetPlayerOnGround(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetPlayerOnGround> &pck);
    void _onMoveVehicle(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::MoveVehicle> &pck);
    void _onPaddleBoat(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PaddleBoat> &pck);
    void _onPickItem(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PickItem> &pck);
    void _onPlaceRecipe(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlaceRecipe> &pck);
    void _onPlayerAbilities(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlayerAbilities> &pck);
    void _onPlayerAction(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlayerAction> &pck);
    void _onPlayerCommand(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlayerCommand> &pck);
    void _onPlayerInput(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::PlayerInput> &pck);
    void _onPong(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::Pong> &pck);
    void _onChangeRecipeBookSettings(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck);
    void _onSetSeenRecipe(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetSeenRecipe> &pck);
    void _onRenameItem(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::RenameItem> &pck);
    void _onResourcePack(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ResourcePack> &pck);
    void _onSeenAdvancements(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SeenAdvancements> &pck);
    void _onSelectTrade(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SelectTrade> &pck);
    void _onSetBeaconEffect(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetBeaconEffect> &pck);
    void _onSetHeldItem(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::SetHeldItem> &pck);
    void _onProgramCommandBlock(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ProgramCommandBlock> &pck);
    void _onProgramCommandBlockMinecart(std::shared_ptr<Client> cli, const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck);

    Configuration::ConfigHandler _config;
};

#endif /* F43D56DD_C750_470F_A7C9_27CE21D37FC3 */
