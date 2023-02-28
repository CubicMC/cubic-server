#include <optional>
#include <vector>

#include "ServerPackets.hpp"
#include "nbt.hpp"
#include "PacketUtils.hpp"
#include "typeSerialization.hpp"

using namespace protocol;

std::shared_ptr<Handshake> protocol::parseHandshake(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Handshake>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &Handshake::prot_version,
          popString, &Handshake::addr,
          popShort, &Handshake::port,
          popVarInt, &Handshake::next_state);
    return h;
}

std::shared_ptr<StatusRequest> protocol::parseStatusRequest(std::vector<uint8_t> &buffer)
{
    return {};
}

std::shared_ptr<LoginStart> protocol::parseLoginStart(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<LoginStart>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popString, &LoginStart::name,
          popBoolean, &LoginStart::has_sig_data);
    if (h->has_sig_data) {
        parse(at, buffer.data() + buffer.size() - 1, *h,
              popLong, &LoginStart::timestamp,
              popArray<uint8_t, popByte>, &LoginStart::public_key,
              popArray<uint8_t, popByte>, &LoginStart::signature);
    }
//    parse(at, buffer.data() + buffer.size() - 1, *h,
//          popBoolean, &LoginStart::has_player_uuid);
//    if (h->has_player_uuid)
//        parse(at, buffer.data() + buffer.size() - 1, *h,
//              popUUID, &LoginStart::player_uuid);
    return h;
}

std::shared_ptr<PingRequest> protocol::parsePingRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PingRequest>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popLong, &PingRequest::payload);
    return h;
}

std::shared_ptr<ConfirmTeleportation> protocol::parseConfirmTeleportation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ConfirmTeleportation>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &ConfirmTeleportation::teleport_id);
    return h;
}

std::shared_ptr<EncryptionResponse> protocol::parseEncryptionResponse(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<EncryptionResponse>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popArray<uint8_t, popByte>, &EncryptionResponse::shared_secret,
          popBoolean, &EncryptionResponse::has_verify_token);
    if (!h->has_verify_token)
        return h;
    parse(at, buffer.data() + buffer.size() - 1, *h,
          popArray<uint8_t, popByte>, &EncryptionResponse::verify_token,
          popLong, &EncryptionResponse::salt,
          popArray<uint8_t, popByte>, &EncryptionResponse::message_signature);
    return h;
}

std::shared_ptr<QueryBlockEntityTag> protocol::parseQueryBlockEntityTag(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<QueryBlockEntityTag>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &QueryBlockEntityTag::transaction_id,
          popPosition, &QueryBlockEntityTag::location);
    return h;
}

std::shared_ptr<ChangeDifficulty> protocol::parseChangeDifficulty(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChangeDifficulty>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popByte, &ChangeDifficulty::new_difficulty);
    return h;
}

std::shared_ptr<ChatMessage> protocol::parseChatMessage(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChatMessage>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popString, &ChatMessage::message,
          popInstantJavaObject, &ChatMessage::timestamp,
          popLong, &ChatMessage::salt,
          popArray<uint8_t, popByte>, &ChatMessage::signature,
          popBoolean, &ChatMessage::isSigned);
    return h;
}

std::shared_ptr<ChatCommand> protocol::parseChatCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChatCommand>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popString, &ChatCommand::command,
          popLong, &ChatCommand::timestamp,
          popLong, &ChatCommand::salt,
          popArray<argumentSignature, popArgumentSignature>, &ChatCommand::argumentSignatures,
          // There are the things for 1.19
          popBoolean, &ChatCommand::signedPreview
          // There are the things for 1.19.3
          // popVarInt, &ChatCommand::messageCount,
          // popBitSet<20>, &ChatCommand::acknowledged
    );
    return h;
}

std::shared_ptr<ClientCommand> protocol::parseClientCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClientCommand>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popClientCommandActionID, &ClientCommand::action_id);
    return h;
}

std::shared_ptr<ClientInformation> protocol::parseClientInformation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClientInformation>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popString, &ClientInformation::locale,
          popByte, &ClientInformation::view_distance,
          popClientInformationChatMode, &ClientInformation::chat_mode,
          popBoolean, &ClientInformation::chat_colors,
          popByte, &ClientInformation::displayed_skin_parts,
          popClientInformationMainHand, &ClientInformation::main_hand,
          popBoolean, &ClientInformation::enable_text_filtering,
          popBoolean, &ClientInformation::allow_server_listings);
    return h;
}

std::shared_ptr<CommandSuggestionRequest> protocol::parseCommandSuggestionRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<CommandSuggestionRequest>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &CommandSuggestionRequest::transaction_id,
          popString, &CommandSuggestionRequest::text);
    return h;
}

std::shared_ptr<ClickContainerButton> protocol::parseClickContainerButton(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ClickContainerButton>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popByte, &ClickContainerButton::window_id,
          popByte, &ClickContainerButton::button_id);
    return h;
}

std::shared_ptr<CloseContainerRequest> protocol::parseCloseContainerRequest(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<CloseContainerRequest>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popByte, &CloseContainerRequest::window_id);
    return h;
}

std::shared_ptr<PluginMessage> protocol::parsePluginMessage(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PluginMessage>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popString, &PluginMessage::channel);
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

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &EditBook::slot,
          popArray<std::string, popString>, &EditBook::entries,
          popBoolean, &EditBook::has_title);
    if (h->has_title)
        parse(at, buffer.data() + buffer.size() - 1, *h,
              popString, &EditBook::title);
    return h;
}

std::shared_ptr<QueryEntityTag> protocol::parseQueryEntityTag(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<QueryEntityTag>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &QueryEntityTag::transaction_id,
          popVarInt, &QueryEntityTag::entity_id);
    return h;
}

std::shared_ptr<Interact> protocol::parseInteract(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Interact>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &Interact::entity_id,
          popVarInt, &Interact::type);
    if (h->type == 2)
        parse(at, buffer.data() + buffer.size() - 1, *h,
              popFloat, &Interact::target_x,
              popFloat, &Interact::target_y,
              popFloat, &Interact::target_z);
    if (h->type != 1)
        parse(at, buffer.data() + buffer.size() - 1, *h,
              popVarInt, &Interact::hand);
    parse(at, buffer.data() + buffer.size() - 1, *h,
          popBoolean, &Interact::sneaking);
    return h;
}

std::shared_ptr<JigsawGenerate> protocol::parseJigsawGenerate(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<JigsawGenerate>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popPosition, &JigsawGenerate::location,
          popVarInt, &JigsawGenerate::levels,
          popBoolean, &JigsawGenerate::keep_jigsaws);
    return h;
}

std::shared_ptr<KeepAliveResponse> protocol::parseKeepAliveResponse(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<KeepAliveResponse>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popLong, &KeepAliveResponse::keep_alive_id);
    return h;
}

std::shared_ptr<LockDifficulty> protocol::parseLockDifficulty(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<LockDifficulty>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popBoolean, &LockDifficulty::locked);
    return h;
}

std::shared_ptr<SetPlayerPosition> protocol::parseSetPlayerPosition(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerPosition>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popDouble, &SetPlayerPosition::x,
          popDouble, &SetPlayerPosition::feet_y,
          popDouble, &SetPlayerPosition::z,
          popBoolean, &SetPlayerPosition::on_ground);
    return h;
}

std::shared_ptr<SetPlayerPositionAndRotation> protocol::parseSetPlayerPositionAndRotation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerPositionAndRotation>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popDouble, &SetPlayerPositionAndRotation::x,
          popDouble, &SetPlayerPositionAndRotation::feet_y,
          popDouble, &SetPlayerPositionAndRotation::z,
          popFloat, &SetPlayerPositionAndRotation::yaw,
          popFloat, &SetPlayerPositionAndRotation::pitch,
          popBoolean, &SetPlayerPositionAndRotation::on_ground);
    return h;
}

std::shared_ptr<SetPlayerRotation> protocol::parseSetPlayerRotation(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerRotation>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popFloat, &SetPlayerRotation::yaw,
          popFloat, &SetPlayerRotation::pitch,
          popBoolean, &SetPlayerRotation::on_ground);
    return h;
}

std::shared_ptr<SetPlayerOnGround> protocol::parseSetPlayerOnGround(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetPlayerOnGround>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popBoolean, &SetPlayerOnGround::on_ground);
    return h;
}

std::shared_ptr<MoveVehicle> protocol::parseMoveVehicle(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<MoveVehicle>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popDouble, &MoveVehicle::x,
          popDouble, &MoveVehicle::y,
          popDouble, &MoveVehicle::z,
          popFloat, &MoveVehicle::yaw,
          popFloat, &MoveVehicle::pitch);
    return h;
}

std::shared_ptr<PaddleBoat> protocol::parsePaddleBoat(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PaddleBoat>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popBoolean, &PaddleBoat::left_paddle_turning,
          popBoolean, &PaddleBoat::right_paddle_turning);
    return h;
}

std::shared_ptr<PickItem> protocol::parsePickItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PickItem>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &PickItem::slot_to_use);
    return h;
}

std::shared_ptr<PlaceRecipe> protocol::parsePlaceRecipe(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlaceRecipe>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popByte, &PlaceRecipe::window_id,
          popString, &PlaceRecipe::recipe,
          popBoolean, &PlaceRecipe::make_all);
    return h;
}

std::shared_ptr<PlayerAbilities> protocol::parsePlayerAbilities(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerAbilities>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popByte, &PlayerAbilities::flags);
    return h;
}

std::shared_ptr<PlayerAction> protocol::parsePlayerAction(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerAction>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &PlayerAction::status,
          popPosition, &PlayerAction::location,
          popByte, &PlayerAction::face,
          popVarInt, &PlayerAction::sequence);
    return h;
}

std::shared_ptr<PlayerCommand> protocol::parsePlayerCommand(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerCommand>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &PlayerCommand::entity_id,
          popVarInt, &PlayerCommand::action_id,
          popVarInt, &PlayerCommand::jump_boost);
    return h;
}

std::shared_ptr<PlayerInput> protocol::parsePlayerInput(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<PlayerInput>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popFloat, &PlayerInput::sideways,
          popFloat, &PlayerInput::forward,
          popByte, &PlayerInput::flags);
    return h;
}

std::shared_ptr<Pong> protocol::parsePong(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<Pong>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popInt, &Pong::id);
    return h;
}

std::shared_ptr<ChangeRecipeBookSettings> protocol::parseChangeRecipeBookSettings(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ChangeRecipeBookSettings>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &ChangeRecipeBookSettings::book_id,
          popBoolean, &ChangeRecipeBookSettings::book_open,
          popBoolean, &ChangeRecipeBookSettings::filter_active);
    return h;
}

std::shared_ptr<SetSeenRecipe> protocol::parseSetSeenRecipe(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetSeenRecipe>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popString, &SetSeenRecipe::recipe_id);
    return h;
}

std::shared_ptr<RenameItem> protocol::parseRenameItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<RenameItem>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popString, &RenameItem::item_name);
    return h;
}

std::shared_ptr<ResourcePack> protocol::parseResourcePack(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ResourcePack>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &ResourcePack::result);
    return h;
}

std::shared_ptr<SeenAdvancements> protocol::parseSeenAdvancements(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SeenAdvancements>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &SeenAdvancements::action);
    if (h->action == 0)
        parse(at, buffer.data() + buffer.size() - 1, *h,
              popString, &SeenAdvancements::tab_id);
    return h;
}

std::shared_ptr<SelectTrade> protocol::parseSelectTrade(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SelectTrade>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &SelectTrade::selected_slot);
    return h;
}

std::shared_ptr<SetBeaconEffect> protocol::parseSetBeaconEffect(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetBeaconEffect>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popBoolean, &SetBeaconEffect::primary_effect_present,
          popVarInt, &SetBeaconEffect::primary_effect,
          popBoolean, &SetBeaconEffect::secondary_effect_present,
          popVarInt, &SetBeaconEffect::secondary_effect);
    return h;
}

std::shared_ptr<SetHeldItem> protocol::parseSetHeldItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SetHeldItem>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popShort, &SetHeldItem::slot);
    return h;
}

std::shared_ptr<ProgramCommandBlock> protocol::parseProgramCommandBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramCommandBlock>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popPosition, &ProgramCommandBlock::location,
          popString, &ProgramCommandBlock::command,
          popVarInt, &ProgramCommandBlock::mode,
          popByte, &ProgramCommandBlock::flags);
    return h;
}

std::shared_ptr<ProgramCommandBlockMinecart> protocol::parseProgramCommandBlockMinecart(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramCommandBlockMinecart>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &ProgramCommandBlockMinecart::entity_id,
          popString, &ProgramCommandBlockMinecart::command,
          popBoolean, &ProgramCommandBlockMinecart::track_output);
    return h;
}

std::shared_ptr<ProgramJigsawBlock> protocol::parseProgramJigsawBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramJigsawBlock>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popPosition, &ProgramJigsawBlock::location,
          popString, &ProgramJigsawBlock::name,
          popString, &ProgramJigsawBlock::target,
          popString, &ProgramJigsawBlock::pool,
          popString, &ProgramJigsawBlock::final_state,
          popString, &ProgramJigsawBlock::joint_type);
    return h;
}

std::shared_ptr<ProgramStructureBlock> protocol::parseProgramStructureBlock(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<ProgramStructureBlock>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popPosition, &ProgramStructureBlock::location,
          popVarInt, &ProgramStructureBlock::action,
          popVarInt, &ProgramStructureBlock::mode,
          popByte, &ProgramStructureBlock::offset_x,
          popByte, &ProgramStructureBlock::offset_y,
          popByte, &ProgramStructureBlock::offset_z,
          popByte, &ProgramStructureBlock::size_x,
          popByte, &ProgramStructureBlock::size_y,
          popByte, &ProgramStructureBlock::size_z,
          popVarInt, &ProgramStructureBlock::mirror,
          popVarInt, &ProgramStructureBlock::rotation,
          popString, &ProgramStructureBlock::metadata,
          popFloat, &ProgramStructureBlock::integrity,
          popVarLong, &ProgramStructureBlock::seed,
          popByte, &ProgramStructureBlock::flags);
    return h;
}

std::shared_ptr<UpdateSign> protocol::parseUpdateSign(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<UpdateSign>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popPosition, &UpdateSign::location,
          popString, &UpdateSign::line_1,
          popString, &UpdateSign::line_2,
          popString, &UpdateSign::line_3,
          popString, &UpdateSign::line_4);
    return h;
}

std::shared_ptr<SwingArm> protocol::parseSwingArm(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<SwingArm>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &SwingArm::hand);
    return h;
}

std::shared_ptr<TeleportToEntity> protocol::parseTeleportToEntity(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<TeleportToEntity>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popUUID, &TeleportToEntity::target_player);
    return h;
}

std::shared_ptr<UseItemOn> protocol::parseUseItemOn(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<UseItemOn>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &UseItemOn::hand,
          popPosition, &UseItemOn::location,
          popVarInt, &UseItemOn::face,
          popFloat, &UseItemOn::cursor_position_x,
          popFloat, &UseItemOn::cursor_position_y,
          popFloat, &UseItemOn::cursor_position_z,
          popBoolean, &UseItemOn::inside_block,
          popVarInt, &UseItemOn::sequence);
    return h;
}

std::shared_ptr<UseItem> protocol::parseUseItem(std::vector<uint8_t> &buffer)
{
    auto h = std::make_shared<UseItem>();
    auto at = buffer.data();

    parse(at, buffer.data() + buffer.size() - 1, *h,
          popVarInt, &UseItem::hand,
          popVarInt, &UseItem::sequence);
    return h;
}
