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
        QueryBlockEntityTag = 0x01,
        ChangeDifficulty = 0x02,
        ClientCommand = 0x06,
        ClientInformation = 0x07,
        CommandSuggestionRequest = 0x08,
        ClickContainerButton = 0x09,
        CloseContainerRequest = 0x0b,
        EditBook = 0x0d,
        QueryEntityTag = 0x0e,
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
    };
}

#endif /* AE9C1FA0_D3A2_4B7D_962E_4EAF72963603 */
