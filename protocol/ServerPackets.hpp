#ifndef AE9C1FA0_D3A2_4B7D_962E_4EAF72963603
#define AE9C1FA0_D3A2_4B7D_962E_4EAF72963603

#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include <optional>
#include <unordered_map>
#include <functional>
#include <map>

#include "typeSerialization.hpp"

namespace protocol
{

    enum class ServerPacketsID : int32_t {
        Handshake = 0x00,
        StatusRequest = 0x00,
        LoginStart = 0x00,
        ConfirmTeleportation = 0x00,
        PingRequest = 0x01,
        EncryptionResponse = 0x01,
        QueryBlockEntityTag = 0x01,
        ChangeDifficulty = 0x02,
        ClientCommand = 0x06,
        ClientInformation = 0x07,
        CommandSuggestionRequest = 0x08,
        ClickContainerButton = 0x09,
        CloseContainerRequest = 0x0b,
        EditBook = 0x0d,
        QueryEntityTag = 0x0e,
        Interact = 0x0F,
        JigsawGenerate = 0x10,
        KeepAliveResponse = 0x11,
        LockDifficulty = 0x12,
        SetPlayerPosition = 0x13,
        SetPlayerPositionAndRotation = 0x14,
        SetPlayerRotation = 0x15,
        SetPlayerOnGround = 0x16,
        MoveVehicle = 0x17,
    };

    struct BaseServerPacket {
        virtual ~BaseServerPacket() = default;
    };

    // Packets

    struct Handshake : BaseServerPacket
    {
        int32_t prot_version;
        std::string addr;
        uint16_t port;
        int32_t next_state; // TODO: Use an enum here instead of an int32_t
    };
    std::shared_ptr<Handshake> parseHandshake(std::vector<uint8_t> &buffer);

    struct StatusRequest : BaseServerPacket
    {};
    std::shared_ptr<StatusRequest> parseStatusRequest(std::vector<uint8_t> &buffer);

    struct LoginStart : BaseServerPacket
    {
        std::string name;
        bool has_sig_data;
        int64_t timestamp;
        int32_t public_key_length;
        std::vector<uint8_t> public_key;
        int32_t signature_length;
        std::vector<uint8_t> signature;
        bool has_player_uuid;
        __int128 player_uuid;
    };
    std::shared_ptr<LoginStart> parseLoginStart(std::vector<uint8_t> &buffer);

    struct PingRequest : BaseServerPacket
    {
        int64_t payload;
    };
    std::shared_ptr<PingRequest> parsePingRequest(std::vector<uint8_t> &buffer);

    struct ConfirmTeleportation : BaseServerPacket
    {
        int32_t teleport_id;
    };
    std::shared_ptr<ConfirmTeleportation> parseConfirmTeleportation(std::vector<uint8_t> &buffer);

    struct EncryptionResponse : BaseServerPacket
    {
        int32_t shared_secret_length;
        std::vector<uint8_t> shared_secret;
        bool has_verify_token;
        int32_t verify_token_length;
        std::vector<uint8_t> verify_token;
        int64_t salt;
        int32_t message_signature_length;
        std::vector<uint8_t> message_signature;
    };
    std::shared_ptr<EncryptionResponse> parseEncryptionResponse(std::vector<uint8_t> &buffer);

    struct QueryBlockEntityTag : BaseServerPacket
    {
        int32_t transaction_id;
        Position location;
    };
    std::shared_ptr<QueryBlockEntityTag> parseQueryBlockEntityTag(std::vector<uint8_t> &buffer);

    struct ChangeDifficulty : BaseServerPacket
    {
        uint8_t new_difficulty;
    };
    std::shared_ptr<ChangeDifficulty> parseChangeDifficulty(std::vector<uint8_t> &buffer);

    struct ClientCommand : BaseServerPacket
    {
        ClientCommandActionID action_id;
    };
    std::shared_ptr<ClientCommand> parseClientCommand(std::vector<uint8_t> &buffer);

    struct ClientInformation : BaseServerPacket
    {
        std::string locale;
        uint8_t view_distance;
        ClientInformationChatMode chat_mode;
        bool chat_colors;
        uint8_t displayed_skin_parts;
        ClientInformationMainHand main_hand;
        bool enable_text_filtering;
        bool allow_server_listings;
    };
    std::shared_ptr<ClientInformation> parseClientInformation(std::vector<uint8_t> &buffer);

    struct CommandSuggestionRequest : BaseServerPacket
    {
        int32_t transaction_id;
        std::string text;
    };
    std::shared_ptr<CommandSuggestionRequest> parseCommandSuggestionRequest(std::vector<uint8_t> &buffer);

    struct ClickContainerButton : BaseServerPacket
    {
        uint8_t window_id;
        uint8_t button_id;
    };
    std::shared_ptr<ClickContainerButton> parseClickContainerButton(std::vector<uint8_t> &buffer);

    struct CloseContainerRequest : BaseServerPacket
    {
        uint8_t window_id;
    };
    std::shared_ptr<CloseContainerRequest> parseCloseContainerRequest(std::vector<uint8_t> &buffer);

    struct EditBook : BaseServerPacket
    {
        int32_t slot;
        int32_t count;
        std::vector<std::string> entries;
        bool has_title;
        std::string title;
    };
    std::shared_ptr<EditBook> parseEditBook(std::vector<uint8_t> &buffer);

    struct QueryEntityTag : BaseServerPacket
    {
        int32_t transaction_id;
        int32_t entity_id;
    };
    std::shared_ptr<QueryEntityTag> parseQueryEntityTag(std::vector<uint8_t> &buffer);

    struct Interact : BaseServerPacket
    {
        int32_t entity_id;
        int32_t type; // TODO: Use an enum
        float target_x;
        float target_y;
        float target_z;
        int32_t hand; // TODO: Use an enum
        bool sneaking;
    };
    std::shared_ptr<Interact> parseInteract(std::vector<uint8_t> &buffer);

    struct JigsawGenerate : BaseServerPacket
    {
        Position location;
        int32_t levels;
        bool keep_jigsaws;
    };
    std::shared_ptr<JigsawGenerate> parseJigsawGenerate(std::vector<uint8_t> &buffer);

    struct KeepAliveResponse : BaseServerPacket
    {
        int64_t keep_alive_id;
    };
    std::shared_ptr<KeepAliveResponse> parseKeepAliveResponse(std::vector<uint8_t> &buffer);

    struct LockDifficulty : BaseServerPacket
    {
        bool locked;
    };
    std::shared_ptr<LockDifficulty> parseLockDifficulty(std::vector<uint8_t> &buffer);

    struct SetPlayerPosition : BaseServerPacket
    {
        double x;
        double feet_y;
        double z;
        bool on_ground;
    };
    std::shared_ptr<SetPlayerPosition> parseSetPlayerPosition(std::vector<uint8_t> &buffer);

    struct SetPlayerPositionAndRotation : BaseServerPacket
    {
        double x;
        double feet_y;
        double z;
        float yaw;
        float pitch;
        bool on_ground;
    };
    std::shared_ptr<SetPlayerPositionAndRotation> parseSetPlayerPositionAndRotation(std::vector<uint8_t> &buffer);

    struct SetPlayerRotation : BaseServerPacket
    {
        float yaw;
        float pitch;
        bool on_ground;
    };
    std::shared_ptr<SetPlayerRotation> parseSetPlayerRotation(std::vector<uint8_t> &buffer);

    struct SetPlayerOnGround : BaseServerPacket
    {
        bool on_ground;
    };
    std::shared_ptr<SetPlayerOnGround> parseSetPlayerOnGround(std::vector<uint8_t> &buffer);

    struct MoveVehicle : BaseServerPacket
    {
        double x;
        double y;
        double z;
        float yaw;
        float pitch;
    };
    std::shared_ptr<MoveVehicle> parseMoveVehicle(std::vector<uint8_t> &buffer);

    // Maps

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseInitial = {
            {ServerPacketsID::Handshake, parseHandshake},
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseStatus = {
            {ServerPacketsID::StatusRequest, &parseStatusRequest},
            {ServerPacketsID::PingRequest, &parsePingRequest},
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseLogin = {
            {ServerPacketsID::LoginStart, &parseLoginStart},
            {ServerPacketsID::EncryptionResponse, &parseEncryptionResponse},
    };

    static const std::unordered_map<ServerPacketsID, std::function<std::shared_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParsePlay = {
            {ServerPacketsID::ConfirmTeleportation, &parseConfirmTeleportation},
            {ServerPacketsID::QueryBlockEntityTag, &parseQueryBlockEntityTag},
            {ServerPacketsID::ChangeDifficulty, &parseChangeDifficulty},
            {ServerPacketsID::ClientCommand, &parseClientCommand},
            {ServerPacketsID::ClientInformation, &parseClientInformation},
            {ServerPacketsID::CommandSuggestionRequest, &parseCommandSuggestionRequest},
            {ServerPacketsID::ClickContainerButton, &parseClickContainerButton},
            {ServerPacketsID::CloseContainerRequest, &parseCloseContainerRequest},
            {ServerPacketsID::EditBook, &parseEditBook},
            {ServerPacketsID::QueryEntityTag, &parseQueryEntityTag},
            {ServerPacketsID::Interact, &parseInteract},
            {ServerPacketsID::JigsawGenerate, &parseJigsawGenerate},
            {ServerPacketsID::KeepAliveResponse, &parseKeepAliveResponse},
            {ServerPacketsID::LockDifficulty, &parseLockDifficulty},
            {ServerPacketsID::SetPlayerPosition, &parseSetPlayerPosition},
            {ServerPacketsID::SetPlayerPositionAndRotation, &parseSetPlayerPositionAndRotation},
            {ServerPacketsID::SetPlayerRotation, &parseSetPlayerRotation},
            {ServerPacketsID::SetPlayerOnGround, &parseSetPlayerOnGround},
            {ServerPacketsID::MoveVehicle, &parseMoveVehicle},
    };
}

#endif /* AE9C1FA0_D3A2_4B7D_962E_4EAF72963603 */
