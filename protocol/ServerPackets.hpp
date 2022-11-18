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
        ChatMessage = 0x03,
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
        PaddleBoat = 0x18,
        PickItem = 0x19,
        PlaceRecipe = 0x1a,
        PlayerAbilities = 0x1b,
        PlayerAction = 0x1c,
        PlayerCommand = 0x1d,
        PlayerInput = 0x1e,
        Pong = 0x1f,
        ChangeRecipeBookSettings = 0x20,
        SetSeenRecipe = 0x21,
        RenameItem = 0x22,
        ResourcePack = 0x23,
        SeenAdvancements = 0x24,
        SelectTrade = 0x25,
        SetBeaconEffect = 0x26,
        SetHeldItem = 0x27,
        ProgramCommandBlock = 0x28,
        ProgramCommandBlockMinecart = 0x29,
        ProgramJigsawBlock = 0x2b,
        ProgramStructureBlock = 0x2c,
        UpdateSign = 0x2d,
        SwingArm = 0x2e,
        TeleportToEntity = 0x2f,
        UseItemOn = 0x30,
        UseItem = 0x31,
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

    struct ChatMessage : BaseServerPacket
    {
        std::string message;
        // I think this is a string, it is marked as an 'Instant' in the protocol
        // https://wiki.vg/index.php?title=Protocol&oldid=17753#Chat_Command
        Instant timestamp;
        long salt;
        int32_t signature_length;
        std::vector<uint8_t> signature;
        bool isSigned;
    };
    std::shared_ptr<ChatMessage> parseChatMessage(std::vector<uint8_t> &buffer);

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

    struct PaddleBoat : BaseServerPacket
    {
        bool left_paddle_turning;
        bool right_paddle_turning;
    };
    std::shared_ptr<PaddleBoat> parsePaddleBoat(std::vector<uint8_t> &buffer);

    struct PickItem : BaseServerPacket
    {
        int32_t slot_to_use;
    };
    std::shared_ptr<PickItem> parsePickItem(std::vector<uint8_t> &buffer);

    struct PlaceRecipe : BaseServerPacket
    {
        uint8_t window_id;
        std::string recipe;
        bool make_all;
    };
    std::shared_ptr<PlaceRecipe> parsePlaceRecipe(std::vector<uint8_t> &buffer);

    struct PlayerAbilities : BaseServerPacket
    {
        uint8_t flags;
    };
    std::shared_ptr<PlayerAbilities> parsePlayerAbilities(std::vector<uint8_t> &buffer);

    struct PlayerAction : BaseServerPacket
    {
        int32_t status; // TODO: Use an enum
        Position location;
        uint8_t face; // TODO: Use an enum
        int32_t sequence;
    };
    std::shared_ptr<PlayerAction> parsePlayerAction(std::vector<uint8_t> &buffer);

    struct PlayerCommand : BaseServerPacket
    {
        int32_t entity_id;
        int32_t action_id; // TODO: Use an enum
        int32_t jump_boost;
    };
    std::shared_ptr<PlayerCommand> parsePlayerCommand(std::vector<uint8_t> &buffer);

    struct PlayerInput : BaseServerPacket
    {
        float sideways;
        float forward;
        uint8_t flags;
    };
    std::shared_ptr<PlayerInput> parsePlayerInput(std::vector<uint8_t> &buffer);

    struct Pong : BaseServerPacket
    {
        int32_t id;
    };
    std::shared_ptr<Pong> parsePong(std::vector<uint8_t> &buffer);

    struct ChangeRecipeBookSettings : BaseServerPacket
    {
        int32_t book_id; // TODO: Use an enum
        bool book_open;
        bool filter_active;
    };
    std::shared_ptr<ChangeRecipeBookSettings> parseChangeRecipeBookSettings(std::vector<uint8_t> &buffer);

    struct SetSeenRecipe : BaseServerPacket
    {
        std::string recipe_id;
    };
    std::shared_ptr<SetSeenRecipe> parseSetSeenRecipe(std::vector<uint8_t> &buffer);

    struct RenameItem : BaseServerPacket
    {
        std::string item_name;
    };
    std::shared_ptr<RenameItem> parseRenameItem(std::vector<uint8_t> &buffer);

    struct ResourcePack : BaseServerPacket
    {
        int32_t result; // TODO: Use an enum
    };
    std::shared_ptr<ResourcePack> parseResourcePack(std::vector<uint8_t> &buffer);

    struct SeenAdvancements : BaseServerPacket
    {
        int32_t action; // TODO: use an enum
        std::string tab_id;
    };
    std::shared_ptr<SeenAdvancements> parseSeenAdvancements(std::vector<uint8_t> &buffer);

    struct SelectTrade : BaseServerPacket
    {
        int32_t selected_slot;
    };
    std::shared_ptr<SelectTrade> parseSelectTrade(std::vector<uint8_t> &buffer);

    struct SetBeaconEffect : BaseServerPacket
    {
        bool primary_effect_present;
        int32_t primary_effect;
        bool secondary_effect_present;
        int32_t secondary_effect;
    };
    std::shared_ptr<SetBeaconEffect> parseSetBeaconEffect(std::vector<uint8_t> &buffer);

    struct SetHeldItem : BaseServerPacket
    {
        uint16_t slot; // Why that a short Mojang ? A byte would have been way enough -_-
    };
    std::shared_ptr<SetHeldItem> parseSetHeldItem(std::vector<uint8_t> &buffer);

    struct ProgramCommandBlock : BaseServerPacket
    {
        Position location;
        std::string command;
        int32_t mode; // TODO: Use an enum
        uint8_t flags;
    };
    std::shared_ptr<ProgramCommandBlock> parseProgramCommandBlock(std::vector<uint8_t> &buffer);

    struct ProgramCommandBlockMinecart : BaseServerPacket
    {
        int32_t entity_id;
        std::string command;
        bool track_output;
    };
    std::shared_ptr<ProgramCommandBlockMinecart> parseProgramCommandBlockMinecart(std::vector<uint8_t> &buffer);

    struct ProgramJigsawBlock : BaseServerPacket
    {
        Position location;
        std::string name;
        std::string target;
        std::string pool;
        std::string final_state;
        std::string joint_type;
    };
    std::shared_ptr<ProgramJigsawBlock> parseProgramJigsawBlock(std::vector<uint8_t> &buffer);

    struct ProgramStructureBlock : BaseServerPacket
    {
        Position location;
        int32_t action; // TODO: Use an enum
        int32_t mode; // TODO: Use an enum
        std::string name;
        uint8_t offset_x;
        uint8_t offset_y;
        uint8_t offset_z;
        uint8_t size_x;
        uint8_t size_y;
        uint8_t size_z;
        int32_t mirror; // TODO: Use an enum
        int32_t rotation; // TODO: Use an enum
        std::string metadata;
        float integrity;
        int64_t seed;
        uint8_t flags;
    };
    std::shared_ptr<ProgramStructureBlock> parseProgramStructureBlock(std::vector<uint8_t> &buffer);

    struct UpdateSign : BaseServerPacket
    {
        Position location;
        std::string line_1;
        std::string line_2;
        std::string line_3;
        std::string line_4;
    };
    std::shared_ptr<UpdateSign> parseUpdateSign(std::vector<uint8_t> &buffer);

    struct SwingArm : BaseServerPacket
    {
        int32_t hand; // TODO: Use an enum
    };
    std::shared_ptr<SwingArm> parseSwingArm(std::vector<uint8_t> &buffer);

    struct TeleportToEntity : BaseServerPacket
    {
        __int128 target_player;
    };
    std::shared_ptr<TeleportToEntity> parseTeleportToEntity(std::vector<uint8_t> &buffer);

    struct UseItemOn : BaseServerPacket
    {
        int32_t hand; // TODO: Use an enum
        Position location;
        int32_t face; // TODO: Use an enum
        float cursor_position_x;
        float cursor_position_y;
        float cursor_position_z;
        bool inside_block;
        int32_t sequence;
    };
    std::shared_ptr<UseItemOn> parseUseItemOn(std::vector<uint8_t> &buffer);

    struct UseItem : BaseServerPacket
    {
        int32_t hand; // TODO: Use an enum
        int32_t sequence;
    };
    std::shared_ptr<UseItem> parseUseItem(std::vector<uint8_t> &buffer);

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
            {ServerPacketsID::ChatMessage, &parseChatMessage},
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
            {ServerPacketsID::PaddleBoat, &parsePaddleBoat},
            {ServerPacketsID::PickItem, &parsePickItem},
            {ServerPacketsID::PlaceRecipe, &parsePlaceRecipe},
            {ServerPacketsID::PlayerAbilities, &parsePlayerAbilities},
            {ServerPacketsID::PlayerAction, &parsePlayerAction},
            {ServerPacketsID::PlayerCommand, &parsePlayerCommand},
            {ServerPacketsID::PlayerInput, &parsePlayerInput},
            {ServerPacketsID::Pong, &parsePong},
            {ServerPacketsID::ChangeRecipeBookSettings, &parseChangeRecipeBookSettings},
            {ServerPacketsID::SetSeenRecipe, &parseSetSeenRecipe},
            {ServerPacketsID::RenameItem, &parseRenameItem},
            {ServerPacketsID::ResourcePack, &parseResourcePack},
            {ServerPacketsID::SeenAdvancements, &parseSeenAdvancements},
            {ServerPacketsID::SelectTrade, &parseSelectTrade},
            {ServerPacketsID::SetBeaconEffect, &parseSetBeaconEffect},
            {ServerPacketsID::SetHeldItem, &parseSetHeldItem},
            {ServerPacketsID::ProgramCommandBlock, &parseProgramCommandBlock},
            {ServerPacketsID::ProgramCommandBlockMinecart, &parseProgramCommandBlockMinecart},
            {ServerPacketsID::ProgramJigsawBlock, &parseProgramJigsawBlock},
            {ServerPacketsID::ProgramStructureBlock, &parseProgramStructureBlock},
            {ServerPacketsID::UpdateSign, &parseUpdateSign},
            {ServerPacketsID::SwingArm, &parseSwingArm},
            {ServerPacketsID::TeleportToEntity, &parseTeleportToEntity},
            {ServerPacketsID::UseItemOn, &parseUseItemOn},
            {ServerPacketsID::UseItem, &parseUseItem},
    };
}

#endif /* AE9C1FA0_D3A2_4B7D_962E_4EAF72963603 */
