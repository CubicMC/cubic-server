#include <optional>
#include <vector>

#include "PacketUtils.hpp"
#include "ServerPackets.hpp"
#include "nbt.hpp"
#include "typeSerialization.hpp"

using namespace protocol;

std::unique_ptr<Handshake> protocol::parseHandshake(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<Handshake>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popVarInt, &Handshake::prot_version, popString, &Handshake::addr, popShort, &Handshake::port, popVarInt, &Handshake::next_state
    );
    return h;
}

std::unique_ptr<StatusRequest> protocol::parseStatusRequest(UNUSED std::vector<uint8_t> &buffer) { return {}; }

std::unique_ptr<PingRequest> protocol::parsePingRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PingRequest>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popLong, &PingRequest::payload);
    return h;
}

std::unique_ptr<LoginStart> protocol::parseLoginStart(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<LoginStart>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popString, &LoginStart::name, popBoolean, &LoginStart::has_player_uuid);
    if (h->has_player_uuid)
        parse(at, buffer.data() + buffer.size() - 1, *h, popUUID, &LoginStart::player_uuid);
    return h;
}

std::unique_ptr<EncryptionResponse> protocol::parseEncryptionResponse(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<EncryptionResponse>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popArray<uint8_t, popByte>, &EncryptionResponse::shared_secret, popBoolean, &EncryptionResponse::has_verify_token);
    if (!h->has_verify_token)
        return h;
    parse(
        at, buffer.data() + buffer.size() - 1, *h, popArray<uint8_t, popByte>, &EncryptionResponse::verify_token, popLong, &EncryptionResponse::salt, popArray<uint8_t, popByte>,
        &EncryptionResponse::message_signature
    );
    return h;
}

std::unique_ptr<ConfirmTeleportation> protocol::parseConfirmTeleportation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ConfirmTeleportation>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &ConfirmTeleportation::teleport_id);
    return h;
}

std::unique_ptr<QueryBlockEntityTag> protocol::parseQueryBlockEntityTag(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<QueryBlockEntityTag>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &QueryBlockEntityTag::transaction_id, popPosition, &QueryBlockEntityTag::location);
    return h;
}

std::unique_ptr<ChangeDifficulty> protocol::parseChangeDifficulty(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ChangeDifficulty>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popByte, &ChangeDifficulty::new_difficulty);
    return h;
}

std::unique_ptr<ChatCommand> protocol::parseChatCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ChatCommand>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popString, &ChatCommand::command, popLong, &ChatCommand::timestamp, popLong, &ChatCommand::salt,
        popArray<ArgumentSignature, popArgumentSignature>, &ChatCommand::argumentSignatures, popVarInt, &ChatCommand::messageCount, popBitSet<20>, &ChatCommand::acknowledged
    );
    return h;
}

std::unique_ptr<ChatMessage> protocol::parseChatMessage(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ChatMessage>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popString, &ChatMessage::message, popInstantJavaObject, &ChatMessage::timestamp, popLong, &ChatMessage::salt,
        popArray<uint8_t, popByte>, &ChatMessage::signature, popBoolean, &ChatMessage::isSigned
    );
    return h;
}

std::unique_ptr<ClientCommand> protocol::parseClientCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ClientCommand>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popClientCommandActionID, &ClientCommand::action_id);
    return h;
}

std::unique_ptr<ClientInformation> protocol::parseClientInformation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ClientInformation>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popString, &ClientInformation::locale, popByte, &ClientInformation::view_distance, popClientInformationChatMode,
        &ClientInformation::chat_mode, popBoolean, &ClientInformation::chat_colors, popByte, &ClientInformation::displayed_skin_parts, popClientInformationMainHand,
        &ClientInformation::main_hand, popBoolean, &ClientInformation::enable_text_filtering, popBoolean, &ClientInformation::allow_server_listings
    );
    return h;
}

std::unique_ptr<CommandSuggestionRequest> protocol::parseCommandSuggestionRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<CommandSuggestionRequest>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &CommandSuggestionRequest::transaction_id, popString, &CommandSuggestionRequest::text);
    return h;
}

std::unique_ptr<ClickContainerButton> protocol::parseClickContainerButton(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ClickContainerButton>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popByte, &ClickContainerButton::window_id, popByte, &ClickContainerButton::button_id);
    return h;
}

std::unique_ptr<CloseContainerRequest> protocol::parseCloseContainerRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<CloseContainerRequest>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popByte, &CloseContainerRequest::window_id);
    return h;
}

std::unique_ptr<PluginMessage> protocol::parsePluginMessage(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PluginMessage>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popString, &PluginMessage::channel);
    //   popArray<uint8_t, popByte>, &PluginMessage::data);
    // That line cannot work since this is not a normal byte array
    // I will let it empty for now
    h->data = std::vector<uint8_t>();
    return h;
}

std::unique_ptr<EditBook> protocol::parseEditBook(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<EditBook>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &EditBook::slot, popArray<std::string, popString>, &EditBook::entries, popBoolean, &EditBook::has_title);
    if (h->has_title)
        parse(at, buffer.data() + buffer.size() - 1, *h, popString, &EditBook::title);
    return h;
}

std::unique_ptr<QueryEntityTag> protocol::parseQueryEntityTag(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<QueryEntityTag>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &QueryEntityTag::transaction_id, popVarInt, &QueryEntityTag::entity_id);
    return h;
}

std::unique_ptr<Interact> protocol::parseInteract(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<Interact>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &Interact::entity_id, popVarInt, &Interact::type);
    if (h->type == 2)
        parse(at, buffer.data() + buffer.size() - 1, *h, popFloat, &Interact::target_x, popFloat, &Interact::target_y, popFloat, &Interact::target_z);
    if (h->type != 1)
        parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &Interact::hand);
    parse(at, buffer.data() + buffer.size() - 1, *h, popBoolean, &Interact::sneaking);
    return h;
}

std::unique_ptr<JigsawGenerate> protocol::parseJigsawGenerate(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<JigsawGenerate>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popPosition, &JigsawGenerate::location, popVarInt, &JigsawGenerate::levels, popBoolean, &JigsawGenerate::keep_jigsaws);
    return h;
}

std::unique_ptr<KeepAliveResponse> protocol::parseKeepAliveResponse(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<KeepAliveResponse>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popLong, &KeepAliveResponse::keep_alive_id);
    return h;
}

std::unique_ptr<LockDifficulty> protocol::parseLockDifficulty(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<LockDifficulty>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popBoolean, &LockDifficulty::locked);
    return h;
}

std::unique_ptr<SetPlayerPosition> protocol::parseSetPlayerPosition(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SetPlayerPosition>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popDouble, &SetPlayerPosition::x, popDouble, &SetPlayerPosition::feet_y, popDouble, &SetPlayerPosition::z, popBoolean,
        &SetPlayerPosition::on_ground
    );
    return h;
}

std::unique_ptr<SetPlayerPositionAndRotation> protocol::parseSetPlayerPositionAndRotation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SetPlayerPositionAndRotation>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popDouble, &SetPlayerPositionAndRotation::x, popDouble, &SetPlayerPositionAndRotation::feet_y, popDouble,
        &SetPlayerPositionAndRotation::z, popFloat, &SetPlayerPositionAndRotation::yaw, popFloat, &SetPlayerPositionAndRotation::pitch, popBoolean,
        &SetPlayerPositionAndRotation::on_ground
    );
    return h;
}

std::unique_ptr<SetPlayerRotation> protocol::parseSetPlayerRotation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SetPlayerRotation>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popFloat, &SetPlayerRotation::yaw, popFloat, &SetPlayerRotation::pitch, popBoolean, &SetPlayerRotation::on_ground);
    return h;
}

std::unique_ptr<SetPlayerOnGround> protocol::parseSetPlayerOnGround(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SetPlayerOnGround>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popBoolean, &SetPlayerOnGround::on_ground);
    return h;
}

std::unique_ptr<MoveVehicle> protocol::parseMoveVehicle(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<MoveVehicle>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popDouble, &MoveVehicle::x, popDouble, &MoveVehicle::y, popDouble, &MoveVehicle::z, popFloat, &MoveVehicle::yaw, popFloat,
        &MoveVehicle::pitch
    );
    return h;
}

std::unique_ptr<PaddleBoat> protocol::parsePaddleBoat(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PaddleBoat>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popBoolean, &PaddleBoat::left_paddle_turning, popBoolean, &PaddleBoat::right_paddle_turning);
    return h;
}

std::unique_ptr<PickItem> protocol::parsePickItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PickItem>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &PickItem::slot_to_use);
    return h;
}

std::unique_ptr<PlaceRecipe> protocol::parsePlaceRecipe(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PlaceRecipe>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popByte, &PlaceRecipe::window_id, popString, &PlaceRecipe::recipe, popBoolean, &PlaceRecipe::make_all);
    return h;
}

std::unique_ptr<PlayerAbilities> protocol::parsePlayerAbilities(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PlayerAbilities>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popByte, &PlayerAbilities::flags);
    return h;
}

std::unique_ptr<PlayerAction> protocol::parsePlayerAction(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PlayerAction>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popVarInt, &PlayerAction::status, popPosition, &PlayerAction::location, popByte, &PlayerAction::face, popVarInt,
        &PlayerAction::sequence
    );
    return h;
}

std::unique_ptr<PlayerCommand> protocol::parsePlayerCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PlayerCommand>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &PlayerCommand::entity_id, popVarInt, &PlayerCommand::action_id, popVarInt, &PlayerCommand::jump_boost);
    return h;
}

std::unique_ptr<PlayerInput> protocol::parsePlayerInput(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<PlayerInput>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popFloat, &PlayerInput::sideways, popFloat, &PlayerInput::forward, popByte, &PlayerInput::flags);
    return h;
}

std::unique_ptr<Pong> protocol::parsePong(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<Pong>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popInt, &Pong::id);
    return h;
}

std::unique_ptr<ChangeRecipeBookSettings> protocol::parseChangeRecipeBookSettings(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ChangeRecipeBookSettings>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popVarInt, &ChangeRecipeBookSettings::book_id, popBoolean, &ChangeRecipeBookSettings::book_open, popBoolean,
        &ChangeRecipeBookSettings::filter_active
    );
    return h;
}

std::unique_ptr<SetSeenRecipe> protocol::parseSetSeenRecipe(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SetSeenRecipe>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popString, &SetSeenRecipe::recipe_id);
    return h;
}

std::unique_ptr<RenameItem> protocol::parseRenameItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<RenameItem>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popString, &RenameItem::item_name);
    return h;
}

std::unique_ptr<ResourcePack> protocol::parseResourcePack(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ResourcePack>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &ResourcePack::result);
    return h;
}

std::unique_ptr<SeenAdvancements> protocol::parseSeenAdvancements(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SeenAdvancements>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &SeenAdvancements::action);
    if (h->action == 0)
        parse(at, buffer.data() + buffer.size() - 1, *h, popString, &SeenAdvancements::tab_id);
    return h;
}

std::unique_ptr<SelectTrade> protocol::parseSelectTrade(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SelectTrade>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &SelectTrade::selected_slot);
    return h;
}

std::unique_ptr<SetBeaconEffect> protocol::parseSetBeaconEffect(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SetBeaconEffect>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popBoolean, &SetBeaconEffect::primary_effect_present, popVarInt, &SetBeaconEffect::primary_effect, popBoolean,
        &SetBeaconEffect::secondary_effect_present, popVarInt, &SetBeaconEffect::secondary_effect
    );
    return h;
}

std::unique_ptr<SetHeldItem> protocol::parseSetHeldItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SetHeldItem>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popShort, &SetHeldItem::slot);
    return h;
}

std::unique_ptr<ProgramCommandBlock> protocol::parseProgramCommandBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ProgramCommandBlock>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popPosition, &ProgramCommandBlock::location, popString, &ProgramCommandBlock::command, popVarInt, &ProgramCommandBlock::mode,
        popByte, &ProgramCommandBlock::flags
    );
    return h;
}

std::unique_ptr<ProgramCommandBlockMinecart> protocol::parseProgramCommandBlockMinecart(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ProgramCommandBlockMinecart>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popVarInt, &ProgramCommandBlockMinecart::entity_id, popString, &ProgramCommandBlockMinecart::command, popBoolean,
        &ProgramCommandBlockMinecart::track_output
    );
    return h;
}

std::unique_ptr<ProgramJigsawBlock> protocol::parseProgramJigsawBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ProgramJigsawBlock>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popPosition, &ProgramJigsawBlock::location, popString, &ProgramJigsawBlock::name, popString, &ProgramJigsawBlock::target,
        popString, &ProgramJigsawBlock::pool, popString, &ProgramJigsawBlock::final_state, popString, &ProgramJigsawBlock::joint_type
    );
    return h;
}

std::unique_ptr<ProgramStructureBlock> protocol::parseProgramStructureBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<ProgramStructureBlock>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popPosition, &ProgramStructureBlock::location, popVarInt, &ProgramStructureBlock::action, popVarInt,
        &ProgramStructureBlock::mode, popByte, &ProgramStructureBlock::offset_x, popByte, &ProgramStructureBlock::offset_y, popByte, &ProgramStructureBlock::offset_z, popByte,
        &ProgramStructureBlock::size_x, popByte, &ProgramStructureBlock::size_y, popByte, &ProgramStructureBlock::size_z, popVarInt, &ProgramStructureBlock::mirror, popVarInt,
        &ProgramStructureBlock::rotation, popString, &ProgramStructureBlock::metadata, popFloat, &ProgramStructureBlock::integrity, popVarLong, &ProgramStructureBlock::seed,
        popByte, &ProgramStructureBlock::flags
    );
    return h;
}

std::unique_ptr<UpdateSign> protocol::parseUpdateSign(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<UpdateSign>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popPosition, &UpdateSign::location, popString, &UpdateSign::line_1, popString, &UpdateSign::line_2, popString,
        &UpdateSign::line_3, popString, &UpdateSign::line_4
    );
    return h;
}

std::unique_ptr<SwingArm> protocol::parseSwingArm(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<SwingArm>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &SwingArm::hand);
    return h;
}

std::unique_ptr<TeleportToEntity> protocol::parseTeleportToEntity(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<TeleportToEntity>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popUUID, &TeleportToEntity::target_player);
    return h;
}

std::unique_ptr<UseItemOn> protocol::parseUseItemOn(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<UseItemOn>();
    auto at = buffer.data();

    parse(
        at, buffer.data() + buffer.size() - 1, *h, popVarInt, &UseItemOn::hand, popPosition, &UseItemOn::location, popVarInt, &UseItemOn::face, popFloat,
        &UseItemOn::cursor_position_x, popFloat, &UseItemOn::cursor_position_y, popFloat, &UseItemOn::cursor_position_z, popBoolean, &UseItemOn::inside_block, popVarInt,
        &UseItemOn::sequence
    );
    return h;
}

std::unique_ptr<UseItem> protocol::parseUseItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_unique<UseItem>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h, popVarInt, &UseItem::hand, popVarInt, &UseItem::sequence);
    return h;
}
