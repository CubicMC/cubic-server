#include "Player.hpp"

Player::Player(Client *cli)
    : _cli(cli)
{
    _log = logging::Logger::get_instance();
}

void Player::tick()
{}

void Player::_onConfirmTeleportation(const std::shared_ptr<protocol::ConfirmTeleportation> &pck)
{
    LDEBUG("Got a Confirm Teleportation");
}

void Player::_onQueryBlockEntityTag(const std::shared_ptr<protocol::QueryBlockEntityTag> &pck)
{
    LDEBUG("Got a Query Block Entity Tag");
}

void Player::_onChangeDifficulty(const std::shared_ptr<protocol::ChangeDifficulty> &pck)
{
    LDEBUG("Got a Change difficulty");
}

void Player::_onClientCommand(const std::shared_ptr<protocol::ClientCommand> &pck)
{
    LDEBUG("Got a Client Command");
}

void Player::_onClientInformation(const std::shared_ptr<protocol::ClientInformation> &pck)
{
    LDEBUG("Got a Client Information");
}

void Player::_onCommandSuggestionRequest(const std::shared_ptr<protocol::CommandSuggestionRequest> &pck)
{
    LDEBUG("Got a Command Suggestion Request");
}

void Player::_onClickContainerButton(const std::shared_ptr<protocol::ClickContainerButton> &pck)
{
    LDEBUG("Got a Click Container Button");
}

void Player::_onCloseContainerRequest(const std::shared_ptr<protocol::CloseContainerRequest> &pck)
{
    LDEBUG("Got a Close Container Request");
}

void Player::_onEditBook(const std::shared_ptr<protocol::EditBook> &pck)
{
    LDEBUG("Got a Edit Book");
}

void Player::_onQueryEntityTag(const std::shared_ptr<protocol::QueryEntityTag> &pck)
{
    LDEBUG("Got a Query Entity Tag");
}

void Player::_onInteract(const std::shared_ptr<protocol::Interact> &pck)
{
    LDEBUG("Got a Interact");
}

void Player::_onJigsawGenerate(const std::shared_ptr<protocol::JigsawGenerate> &pck)
{
    LDEBUG("Got a Jigsaw Generate");
}

void Player::_onKeepAliveResponse(const std::shared_ptr<protocol::KeepAliveResponse> &pck)
{
    LDEBUG("Got a Keep Alive Response");
}

void Player::_onLockDifficulty(const std::shared_ptr<protocol::LockDifficulty> &pck)
{
    LDEBUG("Got a Lock Difficulty");
}

void Player::_onSetPlayerPosition(const std::shared_ptr<protocol::SetPlayerPosition> &pck)
{
    LDEBUG("Got a Set Player Position");
}

void Player::_onSetPlayerPositionAndRotation(const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck)
{
    LDEBUG("Got a Set Player Position And Rotation");
}

void Player::_onSetPlayerRotation(const std::shared_ptr<protocol::SetPlayerRotation> &pck)
{
    LDEBUG("Got a Set Player Rotation");
}

void Player::_onSetPlayerOnGround(const std::shared_ptr<protocol::SetPlayerOnGround> &pck)
{
    LDEBUG("Got a Set Player On Ground");
}

void Player::_onMoveVehicle(const std::shared_ptr<protocol::MoveVehicle> &pck)
{
    LDEBUG("Got a Move Vehicle");
}

void Player::_onPaddleBoat(const std::shared_ptr<protocol::PaddleBoat> &pck)
{
    LDEBUG("Got a Paddle Boat");
}

void Player::_onPickItem(const std::shared_ptr<protocol::PickItem> &pck)
{
    LDEBUG("Got a Pick Item");
}

void Player::_onPlaceRecipe(const std::shared_ptr<protocol::PlaceRecipe> &pck)
{
    LDEBUG("Got a Place Recipe");
}

void Player::_onPlayerAbilities(const std::shared_ptr<protocol::PlayerAbilities> &pck)
{
    LDEBUG("Got a Player Abilities");
}

void Player::_onPlayerAction(const std::shared_ptr<protocol::PlayerAction> &pck)
{
    LDEBUG("Got a Player Action");
}

void Player::_onPlayerCommand(const std::shared_ptr<protocol::PlayerCommand> &pck)
{
    LDEBUG("Got a Player Command");
}

void Player::_onPlayerInput(const std::shared_ptr<protocol::PlayerInput> &pck)
{
    LDEBUG("Got a Player Input");
}

void Player::_onPong(const std::shared_ptr<protocol::Pong> &pck)
{
    LDEBUG("Got a Pong");
}

void Player::_onChangeRecipeBookSettings(const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck)
{
    LDEBUG("Got a Change Recipe Book Settings");
}

void Player::_onSetSeenRecipe(const std::shared_ptr<protocol::SetSeenRecipe> &pck)
{
    LDEBUG("Got a Set Seen Recipe");
}

void Player::_onRenameItem(const std::shared_ptr<protocol::RenameItem> &pck)
{
    LDEBUG("Got a Rename Item");
}

void Player::_onResourcePack(const std::shared_ptr<protocol::ResourcePack> &pck)
{
    LDEBUG("Got a Resource Pack");
}

void Player::_onSeenAdvancements(const std::shared_ptr<protocol::SeenAdvancements> &pck)
{
    LDEBUG("Got a Seen Advancements");
}

void Player::_onSelectTrade(const std::shared_ptr<protocol::SelectTrade> &pck)
{
    LDEBUG("Got a Select Trade");
}

void Player::_onSetBeaconEffect(const std::shared_ptr<protocol::SetBeaconEffect> &pck)
{
    LDEBUG("Got a Set Beacon Effect");
}

void Player::_onSetHeldItem(const std::shared_ptr<protocol::SetHeldItem> &pck)
{
    LDEBUG("Got a Set Held Item");
}

void Player::_onProgramCommandBlock(const std::shared_ptr<protocol::ProgramCommandBlock> &pck)
{
    LDEBUG("Got a Program Command Block");
}

void Player::_onProgramCommandBlockMinecart(const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck)
{
    LDEBUG("Got a Program Command Block Minecart");
}

void Player::_onProgramJigsawBlock(const std::shared_ptr<protocol::ProgramJigsawBlock> &pck)
{
    LDEBUG("Got a Program Jigsaw Block");
}

void Player::_onProgramStructureBlock(const std::shared_ptr<protocol::ProgramStructureBlock> &pck)
{
    LDEBUG("Got a Program Structure Block");
}

void Player::_onUpdateSign(const std::shared_ptr<protocol::UpdateSign> &pck)
{
    LDEBUG("Got a Update Sign");
}

void Player::_onSwingArm(const std::shared_ptr<protocol::SwingArm> &pck)
{
    LDEBUG("Got a Swing Arm");
}

void Player::_onTeleportToEntity(const std::shared_ptr<protocol::TeleportToEntity> &pck)
{
    LDEBUG("Got a Teleport To Entity");
}

void Player::_onUseItemOn(const std::shared_ptr<protocol::UseItemOn> &pck)
{
    LDEBUG("Got a Use Item On");
}

void Player::_onUseItem(const std::shared_ptr<protocol::UseItem> &pck)
{
    LDEBUG("Got a Use Item");
}
