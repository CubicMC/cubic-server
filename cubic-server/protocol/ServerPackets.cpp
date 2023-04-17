#include <memory>
#include <optional>
#include <vector>

#include "PacketUtils.hpp"
#include "ServerPackets.hpp"
#include "nbt.hpp"
#include "protocol/Structures.hpp"
#include "typeSerialization.hpp"

using namespace protocol;

std::shared_ptr<Handshake> protocol::parseHandshake(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Handshake>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &Handshake::protVersion,
        popString, &Handshake::addr,
        popShort, &Handshake::port,
        popVarInt, &Handshake::nextState
    );
    // clang-format on
    return h;
}

std::shared_ptr<StatusRequest> protocol::parseStatusRequest(std::vector<uint8_t> &buffer) { return {}; }

std::shared_ptr<PingRequest> protocol::parsePingRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PingRequest>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popLong, &PingRequest::payload
    );
    // clang-format ons
    return h;
}

std::shared_ptr<LoginStart> protocol::parseLoginStart(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<LoginStart>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popString, &LoginStart::name,
        popBoolean, &LoginStart::hasPlayerUuid
    );
    // clang-format on
    if (h->hasPlayerUuid) {
        // clang-format off
        parse(at, buffer.data() + buffer.size() - 1, *h,
            popUUID, &LoginStart::playerUuid
        );
        // clang-format on
    }
    return h;
}

std::shared_ptr<EncryptionResponse> protocol::parseEncryptionResponse(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<EncryptionResponse>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popArray<uint8_t, popByte>, &EncryptionResponse::sharedSecret,
        popBoolean, &EncryptionResponse::hasVerifyToken
    );
    // clang-format on
    if (!h->hasVerifyToken)
        return h;
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popArray<uint8_t, popByte>, &EncryptionResponse::verifyToken,
        popLong, &EncryptionResponse::salt,
        popArray<uint8_t, popByte>, &EncryptionResponse::messageSignature
    );
    // clang-format on
    return h;
}

std::shared_ptr<ConfirmTeleportation> protocol::parseConfirmTeleportation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ConfirmTeleportation>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &ConfirmTeleportation::teleportId
    );
    // clang-format on
    return h;
}

std::shared_ptr<QueryBlockEntityTag> protocol::parseQueryBlockEntityTag(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<QueryBlockEntityTag>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &QueryBlockEntityTag::transactionId,
        popPosition, &QueryBlockEntityTag::location
    );
    // clang-format on
    return h;
}

std::shared_ptr<ChangeDifficulty> protocol::parseChangeDifficulty(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChangeDifficulty>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popByte, &ChangeDifficulty::newDifficulty
    );
    // clang-format on
    return h;
}

std::shared_ptr<MessageAcknowledgement> protocol::parseMessageAcknowledgement(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<MessageAcknowledgement>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &MessageAcknowledgement::messageCount
    );
    // clang-format on
    return h;
}

std::shared_ptr<ChatCommand> protocol::parseChatCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChatCommand>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popString, &ChatCommand::command,
        popLong, &ChatCommand::timestamp,
        popLong, &ChatCommand::salt,
        popArray<ArgumentSignature, popArgumentSignature>, &ChatCommand::argumentSignatures,
        popVarInt, &ChatCommand::messageCount,
        popBitSet<20>, &ChatCommand::acknowledged
    );
    // clang-format on
    return h;
}

std::shared_ptr<ChatMessage> protocol::parseChatMessage(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChatMessage>();
    auto at = buffer.data();
    // clang-format off
    parse(
        at, buffer.data() + buffer.size() - 1, *h,
        popString, &ChatMessage::message,
        popLong, &ChatMessage::timestamp,
        popLong, &ChatMessage::salt,
        popBoolean, &ChatMessage::isSigned
    );
    if (h->isSigned) {
        parse(at, buffer.data() + buffer.size() - 1, *h,
            popArray<uint8_t, popByte>, &ChatMessage::signature
        );
    }
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popBitSet<20>, &ChatMessage::acknowledged
    );
    // clang-format on
    return h;
}

std::shared_ptr<ClientCommand> protocol::parseClientCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClientCommand>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &ClientCommand::actionId
    );
    // clang-format on
    return h;
}

std::shared_ptr<ClientInformation> protocol::parseClientInformation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClientInformation>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popString, &ClientInformation::locale,
        popByte, &ClientInformation::viewDistance,
        popVarInt, &ClientInformation::chatMode,
        popBoolean, &ClientInformation::chatColors,
        popByte, &ClientInformation::displayedSkinParts,
        popVarInt, &ClientInformation::mainHand,
        popBoolean, &ClientInformation::enableTextFiltering,
        popBoolean, &ClientInformation::allowServerListings
    );
    // clang-format on
    return h;
}

std::shared_ptr<CommandSuggestionRequest> protocol::parseCommandSuggestionRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<CommandSuggestionRequest>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &CommandSuggestionRequest::transactionId,
        popString, &CommandSuggestionRequest::text
    );
    // clang-format on
    return h;
}

std::shared_ptr<ClickContainerButton> protocol::parseClickContainerButton(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClickContainerButton>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popByte, &ClickContainerButton::windowId,
        popByte, &ClickContainerButton::buttonId
    );
    // clang-format on
    return h;
}

std::shared_ptr<ClickContainer> protocol::parseClickContainer(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClickContainer>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popByte, &ClickContainer::windowId,
        popVarInt, &ClickContainer::stateId,
        popShort, &ClickContainer::slot,
        popByte, &ClickContainer::button,
        popVarInt, &ClickContainer::mode,
        popArray<SlotWithIndex, popSlotWithIndex>, &ClickContainer::arrayOfSlots,
        popSlot, &ClickContainer::carriedItem
    );
    // clang-format on
    return h;
}

std::shared_ptr<CloseContainerRequest> protocol::parseCloseContainerRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<CloseContainerRequest>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popByte, &CloseContainerRequest::windowId
    );
    // clang-format on
    return h;
}

std::shared_ptr<PluginMessage> protocol::parsePluginMessage(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PluginMessage>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popString, &PluginMessage::channel
    );
    // clang-format on
    //   popArray<uint8_t, popByte>, &PluginMessage::data);
    // That line cannot work since this is not a normal byte array
    // I will let it empty for now
    h->data = std::vector<uint8_t>();
    return h;
}

std::shared_ptr<EditBook> protocol::parseEditBook(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<EditBook>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &EditBook::slot,
        popArray<std::string, popString>, &EditBook::entries,
        popBoolean, &EditBook::hasTitle
    );
    if (h->hasTitle) {
        parse(at, buffer.data() + buffer.size() - 1, *h,
            popString, &EditBook::title
        );
    }
    // clang-format on
    return h;
}

std::shared_ptr<QueryEntityTag> protocol::parseQueryEntityTag(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<QueryEntityTag>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &QueryEntityTag::transactionId,
        popVarInt, &QueryEntityTag::entityId
    );
    // clang-format on
    return h;
}

std::shared_ptr<Interact> protocol::parseInteract(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Interact>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &Interact::entityId,
        popVarInt, &Interact::type
    );
    if (h->type == protocol::Interact::Type::InteractAt) {
        parse(at, buffer.data() + buffer.size() - 1, *h,
            popFloat, &Interact::targetX,
            popFloat, &Interact::targetY,
            popFloat, &Interact::targetZ
        );
    }
    if (h->type != protocol::Interact::Type::Attack) {
        parse(at, buffer.data() + buffer.size() - 1, *h,
            popVarInt, &Interact::hand
        );
    }
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popBoolean, &Interact::sneaking
    );
    // clang-format on
    return h;
}

std::shared_ptr<JigsawGenerate> protocol::parseJigsawGenerate(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<JigsawGenerate>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popPosition, &JigsawGenerate::location,
        popVarInt, &JigsawGenerate::levels,
        popBoolean, &JigsawGenerate::keepJigsaws
    );
    // clang-format on
    return h;
}

std::shared_ptr<KeepAliveResponse> protocol::parseKeepAliveResponse(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<KeepAliveResponse>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popLong, &KeepAliveResponse::keepAliveId
    );
    // clang-format on
    return h;
}

std::shared_ptr<LockDifficulty> protocol::parseLockDifficulty(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<LockDifficulty>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popBoolean, &LockDifficulty::locked
    );
    // clang-format on
    return h;
}

std::shared_ptr<SetPlayerPosition> protocol::parseSetPlayerPosition(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerPosition>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popDouble, &SetPlayerPosition::x,
        popDouble, &SetPlayerPosition::feetY,
        popDouble, &SetPlayerPosition::z,
        popBoolean, &SetPlayerPosition::onGround
    );
    // clang-format on
    return h;
}

std::shared_ptr<SetPlayerPositionAndRotation> protocol::parseSetPlayerPositionAndRotation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerPositionAndRotation>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popDouble, &SetPlayerPositionAndRotation::x,
        popDouble, &SetPlayerPositionAndRotation::feetY,
        popDouble, &SetPlayerPositionAndRotation::z,
        popFloat, &SetPlayerPositionAndRotation::yaw,
        popFloat, &SetPlayerPositionAndRotation::pitch,
        popBoolean, &SetPlayerPositionAndRotation::onGround
    );
    // clang-format on
    return h;
}

std::shared_ptr<SetPlayerRotation> protocol::parseSetPlayerRotation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerRotation>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popFloat, &SetPlayerRotation::yaw,
        popFloat, &SetPlayerRotation::pitch,
        popBoolean, &SetPlayerRotation::onGround
    );
    // clang-format on
    return h;
}

std::shared_ptr<SetPlayerOnGround> protocol::parseSetPlayerOnGround(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerOnGround>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popBoolean, &SetPlayerOnGround::onGround
    );
    // clang-format on
    return h;
}

std::shared_ptr<MoveVehicle> protocol::parseMoveVehicle(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<MoveVehicle>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popDouble, &MoveVehicle::x,
        popDouble, &MoveVehicle::y,
        popDouble, &MoveVehicle::z,
        popFloat, &MoveVehicle::yaw,
        popFloat, &MoveVehicle::pitch
    );
    // clang-format on
    return h;
}

std::shared_ptr<PaddleBoat> protocol::parsePaddleBoat(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PaddleBoat>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popBoolean, &PaddleBoat::leftPaddleTurning,
        popBoolean, &PaddleBoat::rightPaddleTurning
    );
    // clang-format on
    return h;
}

std::shared_ptr<PickItem> protocol::parsePickItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PickItem>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &PickItem::slotToUse
    );
    // clang-format on
    return h;
}

std::shared_ptr<PlaceRecipe> protocol::parsePlaceRecipe(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlaceRecipe>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popByte, &PlaceRecipe::windowId,
        popString, &PlaceRecipe::recipe,
        popBoolean, &PlaceRecipe::makeAll
    );
    // clang-format on
    return h;
}

std::shared_ptr<PlayerAbilities> protocol::parsePlayerAbilities(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerAbilities>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popByte, &PlayerAbilities::flags
    );
    // clang-format on
    return h;
}

std::shared_ptr<PlayerAction> protocol::parsePlayerAction(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerAction>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &PlayerAction::status,
        popPosition, &PlayerAction::location,
        popByte, &PlayerAction::face,
        popVarInt, &PlayerAction::sequence
    );
    // clang-format on
    return h;
}

std::shared_ptr<PlayerCommand> protocol::parsePlayerCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerCommand>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &PlayerCommand::entityId,
        popVarInt, &PlayerCommand::actionId,
        popVarInt, &PlayerCommand::jumpBoost
    );
    // clang-format on
    return h;
}

std::shared_ptr<PlayerInput> protocol::parsePlayerInput(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerInput>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popFloat, &PlayerInput::sideways,
        popFloat, &PlayerInput::forward,
        popByte, &PlayerInput::flags
    );
    // clang-format on
    return h;
}

std::shared_ptr<Pong> protocol::parsePong(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Pong>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popInt, &Pong::id
    );
    // clang-format on
    return h;
}

std::shared_ptr<PlayerSession> protocol::parsePlayerSession(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerSession>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popUUID, &PlayerSession::uuid,
        popLong, &PlayerSession::expiresAt,
        popArray<uint8_t, popByte>, &PlayerSession::publicKey,
        popArray<uint8_t, popByte>, &PlayerSession::signature
    );
    // clang-format on
    return h;
}

std::shared_ptr<ChangeRecipeBookSettings> protocol::parseChangeRecipeBookSettings(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChangeRecipeBookSettings>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &ChangeRecipeBookSettings::bookId,
        popBoolean, &ChangeRecipeBookSettings::bookOpen,
        popBoolean, &ChangeRecipeBookSettings::filterActive
    );
    // clang-format on
    return h;
}

std::shared_ptr<SetSeenRecipe> protocol::parseSetSeenRecipe(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetSeenRecipe>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popString, &SetSeenRecipe::recipeId
    );
    // clang-format on
    return h;
}

std::shared_ptr<RenameItem> protocol::parseRenameItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<RenameItem>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popString, &RenameItem::itemName
    );
    // clang-format on
    return h;
}

std::shared_ptr<ResourcePack> protocol::parseResourcePack(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ResourcePack>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &ResourcePack::result
    );
    // clang-format on
    return h;
}

std::shared_ptr<SeenAdvancements> protocol::parseSeenAdvancements(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SeenAdvancements>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &SeenAdvancements::action
    );
    if (h->action == protocol::SeenAdvancements::Action::OpenedTab) {
        parse(at, buffer.data() + buffer.size() - 1, *h,
            popString, &SeenAdvancements::tabId
        );
    }
    // clang-format on
    return h;
}

std::shared_ptr<SelectTrade> protocol::parseSelectTrade(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SelectTrade>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &SelectTrade::selectedSlot
    );
    // clang-format on
    return h;
}

std::shared_ptr<SetBeaconEffect> protocol::parseSetBeaconEffect(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetBeaconEffect>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popBoolean, &SetBeaconEffect::primaryEffectPresent,
        popVarInt, &SetBeaconEffect::primaryEffect,
        popBoolean, &SetBeaconEffect::secondaryEffectPresent,
        popVarInt, &SetBeaconEffect::secondaryEffect
    );
    // clang-format on
    return h;
}

std::shared_ptr<SetHeldItem> protocol::parseSetHeldItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetHeldItem>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popShort, &SetHeldItem::slot
    );
    // clang-format on
    return h;
}

std::shared_ptr<ProgramCommandBlock> protocol::parseProgramCommandBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramCommandBlock>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popPosition, &ProgramCommandBlock::location,
        popString, &ProgramCommandBlock::command,
        popVarInt, &ProgramCommandBlock::mode,
        popByte, &ProgramCommandBlock::flags
    );
    // clang-format on
    return h;
}

std::shared_ptr<ProgramCommandBlockMinecart> protocol::parseProgramCommandBlockMinecart(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramCommandBlockMinecart>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &ProgramCommandBlockMinecart::entityId,
        popString, &ProgramCommandBlockMinecart::command,
        popBoolean, &ProgramCommandBlockMinecart::trackOutput
    );
    // clang-format on
    return h;
}

std::shared_ptr<SetCreativeModeSlot> protocol::parseSetCreativeModeSlot(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetCreativeModeSlot>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popShort, &SetCreativeModeSlot::slot,
        popSlot, &SetCreativeModeSlot::clickedItem
    );
    // clang-format on
    return h;
}

std::shared_ptr<ProgramJigsawBlock> protocol::parseProgramJigsawBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramJigsawBlock>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popPosition, &ProgramJigsawBlock::location,
        popString, &ProgramJigsawBlock::name,
        popString, &ProgramJigsawBlock::target,
        popString, &ProgramJigsawBlock::pool,
        popString, &ProgramJigsawBlock::finalState,
        popString, &ProgramJigsawBlock::jointType
    );
    // clang-format on
    return h;
}

std::shared_ptr<ProgramStructureBlock> protocol::parseProgramStructureBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramStructureBlock>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popPosition, &ProgramStructureBlock::location,
        popVarInt, &ProgramStructureBlock::action,
        popVarInt, &ProgramStructureBlock::mode,
        popByte, &ProgramStructureBlock::offsetX,
        popByte, &ProgramStructureBlock::offsetY,
        popByte, &ProgramStructureBlock::offsetZ,
        popByte, &ProgramStructureBlock::sizeX,
        popByte, &ProgramStructureBlock::sizeY,
        popByte, &ProgramStructureBlock::sizeZ,
        popVarInt, &ProgramStructureBlock::mirror,
        popVarInt, &ProgramStructureBlock::rotation,
        popString, &ProgramStructureBlock::metadata,
        popFloat, &ProgramStructureBlock::integrity,
        popVarLong, &ProgramStructureBlock::seed,
        popByte, &ProgramStructureBlock::flags
    );
    // clang-format on
    return h;
}

std::shared_ptr<UpdateSign> protocol::parseUpdateSign(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<UpdateSign>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popPosition, &UpdateSign::location,
        popString, &UpdateSign::line1,
        popString, &UpdateSign::line2,
        popString, &UpdateSign::line3,
        popString, &UpdateSign::line4
    );
    // clang-format on
    return h;
}

std::shared_ptr<SwingArm> protocol::parseSwingArm(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SwingArm>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &SwingArm::hand
    );
    // clang-format on
    return h;
}

std::shared_ptr<TeleportToEntity> protocol::parseTeleportToEntity(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<TeleportToEntity>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popUUID, &TeleportToEntity::targetPlayer
    );
    // clang-format on
    return h;
}

std::shared_ptr<UseItemOn> protocol::parseUseItemOn(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<UseItemOn>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &UseItemOn::hand,
        popPosition, &UseItemOn::location,
        popVarInt, &UseItemOn::face,
        popFloat, &UseItemOn::cursorPositionX,
        popFloat, &UseItemOn::cursorPositionY,
        popFloat, &UseItemOn::cursorPositionZ,
        popBoolean, &UseItemOn::insideBlock,
        popVarInt, &UseItemOn::sequence
    );
    // clang-format on
    return h;
}

std::shared_ptr<UseItem> protocol::parseUseItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<UseItem>();
    auto at = buffer.data();
    // clang-format off
    parse(at, buffer.data() + buffer.size() - 1, *h,
        popVarInt, &UseItem::hand,
        popVarInt, &UseItem::sequence
    );
    // clang-format on
    return h;
}
