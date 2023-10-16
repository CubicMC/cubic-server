#ifndef CUBICSERVER_PROTOCOL_SERVERPACKETS_HPP
#define CUBICSERVER_PROTOCOL_SERVERPACKETS_HPP

#include <bitset>
#include <cstdint>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "PlayerAttributes.hpp"
#include "nbt.h"
#include "protocol/Structures.hpp"
#include "types.hpp"

namespace protocol {

enum class ServerPacketsID : int32_t {
    Handshake = 0x00,

    // Status state
    StatusRequest = 0x00,
    PingRequest = 0x01,

    // Login state
    LoginStart = 0x00,
    EncryptionResponse = 0x01,

    // Play state
    ConfirmTeleportation = 0x00,
    QueryBlockEntityTag = 0x01,
    ChangeDifficulty = 0x02,
    MessageAcknowledgement = 0x03,
    ChatCommand = 0x04,
    ChatMessage = 0x05,
    ClientCommand = 0x06,
    ClientInformation = 0x07,
    CommandSuggestionRequest = 0x08,
    ClickContainerButton = 0x09,
    ClickContainer = 0x0a,
    CloseContainerRequest = 0x0b,
    PluginMessage = 0x0c,
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
    PlayerSession = 0x20,
    ChangeRecipeBookSettings = 0x21,
    SetSeenRecipe = 0x22,
    RenameItem = 0x23,
    ResourcePack = 0x24,
    SeenAdvancements = 0x25,
    SelectTrade = 0x26,
    SetBeaconEffect = 0x27,
    SetHeldItem = 0x28,
    ProgramCommandBlock = 0x29,
    ProgramCommandBlockMinecart = 0x2a,
    SetCreativeModeSlot = 0x2b,
    ProgramJigsawBlock = 0x2c,
    ProgramStructureBlock = 0x2d,
    UpdateSign = 0x2e,
    SwingArm = 0x2f,
    TeleportToEntity = 0x30,
    UseItemOn = 0x31,
    UseItem = 0x32,
};

struct BaseServerPacket {
    virtual ~BaseServerPacket() = default;
};

// Packets

struct Handshake : BaseServerPacket {
    int32_t protVersion;
    std::string addr;
    uint16_t port;
    enum class State : int32_t {
        Status = 1,
        Login = 2,
    } nextState;
};
std::unique_ptr<Handshake> parseHandshake(std::vector<uint8_t> &buffer);

struct StatusRequest : BaseServerPacket { };
std::unique_ptr<StatusRequest> parseStatusRequest(std::vector<uint8_t> &buffer);

struct PingRequest : BaseServerPacket {
    int64_t payload;
};
std::unique_ptr<PingRequest> parsePingRequest(std::vector<uint8_t> &buffer);

struct LoginStart : BaseServerPacket {
    std::string name;
    bool hasPlayerUuid;
    u128 playerUuid;
};
std::unique_ptr<LoginStart> parseLoginStart(std::vector<uint8_t> &buffer);

struct EncryptionResponse : BaseServerPacket {
    std::vector<uint8_t> sharedSecret;
    std::vector<uint8_t> verifyToken;
};
std::unique_ptr<EncryptionResponse> parseEncryptionResponse(std::vector<uint8_t> &buffer);

struct ConfirmTeleportation : BaseServerPacket {
    int32_t teleportId;
};
std::unique_ptr<ConfirmTeleportation> parseConfirmTeleportation(std::vector<uint8_t> &buffer);

struct QueryBlockEntityTag : BaseServerPacket {
    int32_t transactionId;
    Position location;
};
std::unique_ptr<QueryBlockEntityTag> parseQueryBlockEntityTag(std::vector<uint8_t> &buffer);

struct ChangeDifficulty : BaseServerPacket {
    player_attributes::Gamemode newDifficulty;
};
std::unique_ptr<ChangeDifficulty> parseChangeDifficulty(std::vector<uint8_t> &buffer);

struct MessageAcknowledgement : BaseServerPacket {
    int32_t messageCount;
};
std::unique_ptr<MessageAcknowledgement> parseMessageAcknowledgement(std::vector<uint8_t> &buffer);

/**
 * @brief this is the link to the packet: https://wiki.vg/Protocol#Chat_Command
 */
struct ChatCommand : BaseServerPacket {
    struct ArgumentSignature {
        std::string argument;
        std::vector<uint8_t> signature;
    };
    std::string command;
    long timestamp;
    long salt;
    std::vector<ArgumentSignature> argumentSignatures;
    int32_t messageCount;
    std::bitset<20> acknowledged;
};

/**
 * @brief This function is used to parse the chat command packet
 *
 * @param buffer
 * @return std::unique_ptr<ChatCommand>
 */
std::unique_ptr<ChatCommand> parseChatCommand(std::vector<uint8_t> &buffer);

struct ChatMessage : BaseServerPacket {
    std::string message;
    int64_t timestamp;
    long salt;
    bool isSigned;
    std::vector<uint8_t> signature;
    int32_t messageCount;
    std::bitset<20> acknowledged;
};
std::unique_ptr<ChatMessage> parseChatMessage(std::vector<uint8_t> &buffer);

struct ClientCommand : BaseServerPacket {
    enum class ActionID : int32_t {
        PerformRespawn = 0,
        RequestStats = 1,
    } actionId;
};
std::unique_ptr<ClientCommand> parseClientCommand(std::vector<uint8_t> &buffer);

struct ClientInformation : BaseServerPacket {
    std::string locale;
    uint8_t viewDistance;
    enum class ChatVisibility : int32_t {
        Enabled = 0,
        CommandsOnly = 1,
        Hidden = 2,
    } chatMode;
    bool chatColors;
    uint8_t displayedSkinParts;
    enum class MainHand : int32_t {
        Left = 0,
        Right = 1,
    } mainHand;
    bool enableTextFiltering;
    bool allowServerListings;
};
std::unique_ptr<ClientInformation> parseClientInformation(std::vector<uint8_t> &buffer);

struct CommandSuggestionRequest : BaseServerPacket {
    int32_t transactionId;
    std::string text;
};
std::unique_ptr<CommandSuggestionRequest> parseCommandSuggestionRequest(std::vector<uint8_t> &buffer);

struct ClickContainerButton : BaseServerPacket {
    uint8_t windowId;
    uint8_t buttonId;
};
std::unique_ptr<ClickContainerButton> parseClickContainerButton(std::vector<uint8_t> &buffer);

struct ClickContainer : BaseServerPacket {
    struct SlotWithIndex {
        int16_t slotNumber;
        Slot slotData;
    };
    uint8_t windowId;
    int32_t stateId;
    int16_t slot;
    int8_t button;
    int32_t mode; // May be an enum but there is to many cases
    std::vector<SlotWithIndex> arrayOfSlots;
    Slot carriedItem;
};
std::unique_ptr<ClickContainer> parseClickContainer(std::vector<uint8_t> &buffer);

struct CloseContainerRequest : BaseServerPacket {
    uint8_t windowId;
};
std::unique_ptr<CloseContainerRequest> parseCloseContainerRequest(std::vector<uint8_t> &buffer);

struct PluginMessage : BaseServerPacket {
    std::string channel;
    std::vector<uint8_t> data;
};
std::unique_ptr<PluginMessage> parsePluginMessage(std::vector<uint8_t> &buffer);

struct EditBook : BaseServerPacket {
    int32_t slot;
    std::vector<std::string> entries;
    bool hasTitle;
    std::string title;
};
std::unique_ptr<EditBook> parseEditBook(std::vector<uint8_t> &buffer);

struct QueryEntityTag : BaseServerPacket {
    int32_t transactionId;
    int32_t entityId;
};
std::unique_ptr<QueryEntityTag> parseQueryEntityTag(std::vector<uint8_t> &buffer);

struct Interact : BaseServerPacket {
    int32_t entityId;
    enum class Type : int32_t {
        Interact = 0,
        Attack = 1,
        InteractAt = 2,
    } type;
    float targetX;
    float targetY;
    float targetZ;
    enum class Hand : int32_t {
        MainHand = 0,
        OffHand = 1,
    } hand;
    bool sneaking;
};
std::unique_ptr<Interact> parseInteract(std::vector<uint8_t> &buffer);

struct JigsawGenerate : BaseServerPacket {
    Position location;
    int32_t levels;
    bool keepJigsaws;
};
std::unique_ptr<JigsawGenerate> parseJigsawGenerate(std::vector<uint8_t> &buffer);

struct KeepAliveResponse : BaseServerPacket {
    int64_t keepAliveId;
};
std::unique_ptr<KeepAliveResponse> parseKeepAliveResponse(std::vector<uint8_t> &buffer);

struct LockDifficulty : BaseServerPacket {
    bool locked;
};
std::unique_ptr<LockDifficulty> parseLockDifficulty(std::vector<uint8_t> &buffer);

struct SetPlayerPosition : BaseServerPacket {
    double x;
    double feetY;
    double z;
    bool onGround;
};
std::unique_ptr<SetPlayerPosition> parseSetPlayerPosition(std::vector<uint8_t> &buffer);

struct SetPlayerPositionAndRotation : BaseServerPacket {
    double x;
    double feetY;
    double z;
    float yaw;
    float pitch;
    bool onGround;
};
std::unique_ptr<SetPlayerPositionAndRotation> parseSetPlayerPositionAndRotation(std::vector<uint8_t> &buffer);

struct SetPlayerRotation : BaseServerPacket {
    float yaw;
    float pitch;
    bool onGround;
};
std::unique_ptr<SetPlayerRotation> parseSetPlayerRotation(std::vector<uint8_t> &buffer);

struct SetPlayerOnGround : BaseServerPacket {
    bool onGround;
};
std::unique_ptr<SetPlayerOnGround> parseSetPlayerOnGround(std::vector<uint8_t> &buffer);

struct MoveVehicle : BaseServerPacket {
    double x;
    double y;
    double z;
    float yaw;
    float pitch;
};
std::unique_ptr<MoveVehicle> parseMoveVehicle(std::vector<uint8_t> &buffer);

struct PaddleBoat : BaseServerPacket {
    bool leftPaddleTurning;
    bool rightPaddleTurning;
};
std::unique_ptr<PaddleBoat> parsePaddleBoat(std::vector<uint8_t> &buffer);

struct PickItem : BaseServerPacket {
    int32_t slotToUse;
};
std::unique_ptr<PickItem> parsePickItem(std::vector<uint8_t> &buffer);

struct PlaceRecipe : BaseServerPacket {
    uint8_t windowId;
    std::string recipe;
    bool makeAll;
};
std::unique_ptr<PlaceRecipe> parsePlaceRecipe(std::vector<uint8_t> &buffer);

struct PlayerAbilities : BaseServerPacket {
    uint8_t flags;
};
std::unique_ptr<PlayerAbilities> parsePlayerAbilities(std::vector<uint8_t> &buffer);

struct PlayerAction : BaseServerPacket {
    enum class Status : int32_t {
        StartedDigging = 0,
        CancelledDigging = 1,
        FinishedDigging = 2,
        DropItemStack = 3,
        DropItem = 4,
        ShootArrowOrFinishEating = 5,
        SwapItemInHand = 6,
    } status;
    Position location;
    enum class Face : uint8_t {
        Bottom = 0,
        Top = 1,
        North = 2,
        South = 3,
        West = 4,
        East = 5,
    } face;
    int32_t sequence;
};
std::unique_ptr<PlayerAction> parsePlayerAction(std::vector<uint8_t> &buffer);

struct PlayerCommand : BaseServerPacket {
    int32_t entityId;
    enum class ActionId : int32_t {
        StartSneaking = 0,
        StopSneaking = 1,
        LeaveBed = 2,
        StartSprinting = 3,
        StopSprinting = 4,
        StartJumpWithHorse = 5,
        StopJumpWithHorse = 6,
        OpenHorseInventory = 7,
        StartFlyingWithElytra = 8,
    } actionId;
    int32_t jumpBoost;
};
std::unique_ptr<PlayerCommand> parsePlayerCommand(std::vector<uint8_t> &buffer);

struct PlayerInput : BaseServerPacket {
    float sideways;
    float forward;
    uint8_t flags;
};
std::unique_ptr<PlayerInput> parsePlayerInput(std::vector<uint8_t> &buffer);

struct Pong : BaseServerPacket {
    int32_t id;
};
std::unique_ptr<Pong> parsePong(std::vector<uint8_t> &buffer);

struct PlayerSession : BaseServerPacket {
    u128 uuid;
    long expiresAt;
    std::vector<uint8_t> publicKey;
    std::vector<uint8_t> signature;
};
std::unique_ptr<PlayerSession> parsePlayerSession(std::vector<uint8_t> &buffer);

struct ChangeRecipeBookSettings : BaseServerPacket {
    enum class BookID : int32_t {
        Crafting = 0,
        Furnace = 1,
        BlastFurnace = 2,
        Smoker = 3,
    } bookId;
    bool bookOpen;
    bool filterActive;
};
std::unique_ptr<ChangeRecipeBookSettings> parseChangeRecipeBookSettings(std::vector<uint8_t> &buffer);

struct SetSeenRecipe : BaseServerPacket {
    std::string recipeId;
};
std::unique_ptr<SetSeenRecipe> parseSetSeenRecipe(std::vector<uint8_t> &buffer);

struct RenameItem : BaseServerPacket {
    std::string itemName;
};
std::unique_ptr<RenameItem> parseRenameItem(std::vector<uint8_t> &buffer);

struct ResourcePack : BaseServerPacket {
    enum class Result : int32_t {
        SuccessfullyLoaded = 0,
        Declined = 1,
        FailedDownload = 2,
        Accepted = 3,
    } result;
};
std::unique_ptr<ResourcePack> parseResourcePack(std::vector<uint8_t> &buffer);

struct SeenAdvancements : BaseServerPacket {
    enum class Action : int32_t {
        OpenedTab = 0,
        ClosedScreen = 1,
    } action;
    std::string tabId;
};
std::unique_ptr<SeenAdvancements> parseSeenAdvancements(std::vector<uint8_t> &buffer);

struct SelectTrade : BaseServerPacket {
    int32_t selectedSlot;
};
std::unique_ptr<SelectTrade> parseSelectTrade(std::vector<uint8_t> &buffer);

struct SetBeaconEffect : BaseServerPacket {
    bool primaryEffectPresent;
    int32_t primaryEffect;
    bool secondaryEffectPresent;
    int32_t secondaryEffect;
};
std::unique_ptr<SetBeaconEffect> parseSetBeaconEffect(std::vector<uint8_t> &buffer);

struct SetHeldItem : BaseServerPacket {
    uint16_t slot; // Why that a short Mojang ? A byte would have been way enough -_-
};
std::unique_ptr<SetHeldItem> parseSetHeldItem(std::vector<uint8_t> &buffer);

struct ProgramCommandBlock : BaseServerPacket {
    Position location;
    std::string command;
    enum class Mode : int32_t {
        Sequence = 0,
        Auto = 1,
        Redstone = 2,
    } mode;
    uint8_t flags;
};
std::unique_ptr<ProgramCommandBlock> parseProgramCommandBlock(std::vector<uint8_t> &buffer);

struct ProgramCommandBlockMinecart : BaseServerPacket {
    int32_t entityId;
    std::string command;
    bool trackOutput;
};
std::unique_ptr<ProgramCommandBlockMinecart> parseProgramCommandBlockMinecart(std::vector<uint8_t> &buffer);

struct SetCreativeModeSlot : BaseServerPacket {
    int16_t slot;
    Slot clickedItem;
};
std::unique_ptr<SetCreativeModeSlot> parseSetCreativeModeSlot(std::vector<uint8_t> &buffer);

struct ProgramJigsawBlock : BaseServerPacket {
    Position location;
    std::string name;
    std::string target;
    std::string pool;
    std::string finalState;
    std::string jointType;
};
std::unique_ptr<ProgramJigsawBlock> parseProgramJigsawBlock(std::vector<uint8_t> &buffer);

struct ProgramStructureBlock : BaseServerPacket {
    Position location;
    enum class Action : int32_t {
        UpdateData = 0,
        SaveTheStructure = 1,
        LoadTheStructure = 2,
        DetectSize = 3,
    } action;
    enum class Mode : int32_t {
        Save = 0,
        Load = 1,
        Corner = 2,
        Data = 3,
    } mode;
    std::string name;
    uint8_t offsetX;
    uint8_t offsetY;
    uint8_t offsetZ;
    uint8_t sizeX;
    uint8_t sizeY;
    uint8_t sizeZ;
    enum class Mirror : int32_t {
        None = 0,
        LeftRight = 1,
        FrontBack = 2,
    } mirror;
    enum class Rotation : int32_t {
        None = 0,
        ClockWiseNinety = 1,
        ClockWiseOneEighty = 2,
        CounterClockWiseNinety = 3,
    } rotation;
    std::string metadata;
    float integrity;
    int64_t seed;
    uint8_t flags;
};
std::unique_ptr<ProgramStructureBlock> parseProgramStructureBlock(std::vector<uint8_t> &buffer);

struct UpdateSign : BaseServerPacket {
    Position location;
    std::string line1;
    std::string line2;
    std::string line3;
    std::string line4;
};
std::unique_ptr<UpdateSign> parseUpdateSign(std::vector<uint8_t> &buffer);

struct SwingArm : BaseServerPacket {
    enum class Hand : int32_t {
        MainHand = 0,
        OffHand = 1,
    } hand;
};
std::unique_ptr<SwingArm> parseSwingArm(std::vector<uint8_t> &buffer);

struct TeleportToEntity : BaseServerPacket {
    u128 targetPlayer;
};
std::unique_ptr<TeleportToEntity> parseTeleportToEntity(std::vector<uint8_t> &buffer);

struct UseItemOn : BaseServerPacket {
    enum class Hand : int32_t {
        MainHand = 0,
        OffHand = 1,
    } hand;
    Position location;
    enum class Face : int32_t {
        Bottom = 0,
        Top = 1,
        North = 2,
        South = 3,
        West = 4,
        East = 5,
    } face;
    float cursorPositionX;
    float cursorPositionY;
    float cursorPositionZ;
    bool insideBlock;
    int32_t sequence;
};
std::unique_ptr<UseItemOn> parseUseItemOn(std::vector<uint8_t> &buffer);

struct UseItem : BaseServerPacket {
    enum class Hand : int32_t {
        MainHand = 0,
        OffHand = 1,
    } hand;
    int32_t sequence;
};
std::unique_ptr<UseItem> parseUseItem(std::vector<uint8_t> &buffer);

// Maps

static const std::unordered_map<ServerPacketsID, std::function<std::unique_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseInitial = {
    {ServerPacketsID::Handshake, parseHandshake},
};

static const std::unordered_map<ServerPacketsID, std::function<std::unique_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseStatus = {
    {ServerPacketsID::StatusRequest, &parseStatusRequest},
    {ServerPacketsID::PingRequest, &parsePingRequest},
};

static const std::unordered_map<ServerPacketsID, std::function<std::unique_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParseLogin = {
    {ServerPacketsID::LoginStart, &parseLoginStart},
    {ServerPacketsID::EncryptionResponse, &parseEncryptionResponse},
};

static const std::unordered_map<ServerPacketsID, std::function<std::unique_ptr<BaseServerPacket>(std::vector<uint8_t> &)>> packetIDToParsePlay = {
    {ServerPacketsID::ConfirmTeleportation, &parseConfirmTeleportation},
    {ServerPacketsID::QueryBlockEntityTag, &parseQueryBlockEntityTag},
    {ServerPacketsID::ChangeDifficulty, &parseChangeDifficulty},
    {ServerPacketsID::MessageAcknowledgement, &parseMessageAcknowledgement},
    {ServerPacketsID::ChatCommand, &parseChatCommand},
    {ServerPacketsID::ChatMessage, &parseChatMessage},
    {ServerPacketsID::ClientCommand, &parseClientCommand},
    {ServerPacketsID::ClientInformation, &parseClientInformation},
    {ServerPacketsID::CommandSuggestionRequest, &parseCommandSuggestionRequest},
    {ServerPacketsID::ClickContainerButton, &parseClickContainerButton},
    {ServerPacketsID::ClickContainer, &parseClickContainer},
    {ServerPacketsID::CloseContainerRequest, &parseCloseContainerRequest},
    {ServerPacketsID::PluginMessage, &parsePluginMessage},
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
    {ServerPacketsID::PlayerSession, &parsePlayerSession},
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
    {ServerPacketsID::SetCreativeModeSlot, &parseSetCreativeModeSlot},
    {ServerPacketsID::ProgramJigsawBlock, &parseProgramJigsawBlock},
    {ServerPacketsID::ProgramStructureBlock, &parseProgramStructureBlock},
    {ServerPacketsID::UpdateSign, &parseUpdateSign},
    {ServerPacketsID::SwingArm, &parseSwingArm},
    {ServerPacketsID::TeleportToEntity, &parseTeleportToEntity},
    {ServerPacketsID::UseItemOn, &parseUseItemOn},
    {ServerPacketsID::UseItem, &parseUseItem},
};
}

#endif // CUBICSERVER_PROTOCOL_SERVERPACKETS_HPP
