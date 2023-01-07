#ifndef CUBICSERVER_PLAYER_HPP
#define CUBICSERVER_PLAYER_HPP

#include "Client.hpp"
#include "Entity.hpp"
#include "protocol/ServerPackets.hpp"
#include "logging/Logger.hpp"
#include "SoundList.hpp"
#include "types.hpp"

class Client;

class Player : public Entity
{
    friend class Client;
public:
    Player(Client *cli, std::shared_ptr<Dimension> dim, u128 uuid, const std::string &username);
    void tick() override;
    Client *getClient() const;
    const std::string &getUsername() const;
    const u128 &getUuid() const;
    void playSoundEffect(SoundsList sound, protocol::FloatingPosition position, SoundCategory category = SoundCategory::Master);
    void playSoundEffect(SoundsList sound, const Entity *entity, SoundCategory category = SoundCategory::Master);
    void playCustomSound(std::string sound, protocol::FloatingPosition position, SoundCategory category = SoundCategory::Master);
    void stopSound(uint8_t flags = 0, SoundCategory category = SoundCategory::Ambient, std::string sound = "");

private:
    void _onConfirmTeleportation(const std::shared_ptr<protocol::ConfirmTeleportation> &pck);
    void _onQueryBlockEntityTag(const std::shared_ptr<protocol::QueryBlockEntityTag> &pck);
    void _onChangeDifficulty(const std::shared_ptr<protocol::ChangeDifficulty> &pck);
    void _onChatMessage(const std::shared_ptr<protocol::ChatMessage> &pck);
    void _onClientCommand(const std::shared_ptr<protocol::ClientCommand> &pck);
    void _onClientInformation(const std::shared_ptr<protocol::ClientInformation> &pck);
    void _onCommandSuggestionRequest(const std::shared_ptr<protocol::CommandSuggestionRequest> &pck);
    void _onClickContainerButton(const std::shared_ptr<protocol::ClickContainerButton> &pck);
    void _onCloseContainerRequest(const std::shared_ptr<protocol::CloseContainerRequest> &pck);
    void _onEditBook(const std::shared_ptr<protocol::EditBook> &pck);
    void _onQueryEntityTag(const std::shared_ptr<protocol::QueryEntityTag> &pck);
    void _onInteract(const std::shared_ptr<protocol::Interact> &pck);
    void _onJigsawGenerate(const std::shared_ptr<protocol::JigsawGenerate> &pck);
    void _onKeepAliveResponse(const std::shared_ptr<protocol::KeepAliveResponse> &pck);
    void _onLockDifficulty(const std::shared_ptr<protocol::LockDifficulty> &pck);
    void _onSetPlayerPosition(const std::shared_ptr<protocol::SetPlayerPosition> &pck);
    void _onSetPlayerPositionAndRotation(const std::shared_ptr<protocol::SetPlayerPositionAndRotation> &pck);
    void _onSetPlayerRotation(const std::shared_ptr<protocol::SetPlayerRotation> &pck);
    void _onSetPlayerOnGround(const std::shared_ptr<protocol::SetPlayerOnGround> &pck);
    void _onMoveVehicle(const std::shared_ptr<protocol::MoveVehicle> &pck);
    void _onPaddleBoat(const std::shared_ptr<protocol::PaddleBoat> &pck);
    void _onPickItem(const std::shared_ptr<protocol::PickItem> &pck);
    void _onPlaceRecipe(const std::shared_ptr<protocol::PlaceRecipe> &pck);
    void _onPlayerAbilities(const std::shared_ptr<protocol::PlayerAbilities> &pck);
    void _onPlayerAction(const std::shared_ptr<protocol::PlayerAction> &pck);
    void _onPlayerCommand(const std::shared_ptr<protocol::PlayerCommand> &pck);
    void _onPlayerInput(const std::shared_ptr<protocol::PlayerInput> &pck);
    void _onPong(const std::shared_ptr<protocol::Pong> &pck);
    void _onChangeRecipeBookSettings(const std::shared_ptr<protocol::ChangeRecipeBookSettings> &pck);
    void _onSetSeenRecipe(const std::shared_ptr<protocol::SetSeenRecipe> &pck);
    void _onRenameItem(const std::shared_ptr<protocol::RenameItem> &pck);
    void _onResourcePack(const std::shared_ptr<protocol::ResourcePack> &pck);
    void _onSeenAdvancements(const std::shared_ptr<protocol::SeenAdvancements> &pck);
    void _onSelectTrade(const std::shared_ptr<protocol::SelectTrade> &pck);
    void _onSetBeaconEffect(const std::shared_ptr<protocol::SetBeaconEffect> &pck);
    void _onSetHeldItem(const std::shared_ptr<protocol::SetHeldItem> &pck);
    void _onProgramCommandBlock(const std::shared_ptr<protocol::ProgramCommandBlock> &pck);
    void _onProgramCommandBlockMinecart(const std::shared_ptr<protocol::ProgramCommandBlockMinecart> &pck);
    void _onProgramJigsawBlock(const std::shared_ptr<protocol::ProgramJigsawBlock> &pck);
    void _onProgramStructureBlock(const std::shared_ptr<protocol::ProgramStructureBlock> &pck);
    void _onUpdateSign(const std::shared_ptr<protocol::UpdateSign> &pck);
    void _onSwingArm(const std::shared_ptr<protocol::SwingArm> &pck);
    void _onTeleportToEntity(const std::shared_ptr<protocol::TeleportToEntity> &pck);
    void _onUseItemOn(const std::shared_ptr<protocol::UseItemOn> &pck);
    void _onUseItem(const std::shared_ptr<protocol::UseItem> &pck);

    logging::Logger *_log;
    Client *_cli;
    std::string _username;
    u128 _uuid;
};


#endif //CUBICSERVER_PLAYER_HPP
