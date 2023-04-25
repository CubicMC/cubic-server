#ifndef CUBICSERVER_PLAYER_HPP
#define CUBICSERVER_PLAYER_HPP

#include "Chat.hpp"
#include "Entity.hpp"
#include "LivingEntity.hpp"
#include "PlayerAttributes.hpp"
#include "SoundList.hpp"
#include "TickClock.hpp"
#include "chat/Message.hpp"
#include "math/Vector3.hpp"
#include "protocol/ClientPackets.hpp"
#include "protocol/ServerPackets.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"

class Client;
// class Entity;

class Player : public LivingEntity {
    friend class Client;

public:
    enum ChunkState {
        Unloaded,
        Loading,
        Loaded
    };

public:
    Player(Client *cli, std::shared_ptr<Dimension> dim, u128 uuid, const std::string &username);
    ~Player() override;

    void tick() override;

    Client *getClient() const;
    const std::string &getUsername() const;
    const u128 &getUuid() const;
    uint16_t getHeldItem() const;
    const std::string &getUuidString() const;
    player_attributes::Gamemode getGamemode() const;
    const protocol::ClientInformation::ChatVisibility &getChatVisibility() const;
    long keepAliveId() const;
    uint8_t keepAliveIgnored() const;
    bool isOperator() const;

public:
    void setPosition(const Vector3<double> &pos, bool onGround) override;
    void setPosition(double x, double y, double z, bool onGround) override;
    void setGamemode(player_attributes::Gamemode gm);
    void teleport(const Vector3<double> &pos) override;
    void setKeepAliveIgnored(uint8_t ign);
    void setOperator(const bool isOp);
    void setKeepAliveId(long id);

public:
    void disconnect(const chat::Message &reason = "Disconnected");
    void sendLoginPlay(const protocol::LoginPlay &packet);
    void sendPlayerInfoUpdate(const protocol::PlayerInfoUpdate &data);
    void sendPlayerInfoRemove(const protocol::PlayerInfoRemove &data);
    void sendSpawnPlayer(const protocol::SpawnPlayer &data);
    void sendEntityVelocity(const protocol::EntityVelocity &data);
    void sendHealth(void);
    void sendUpdateTime(const protocol::UpdateTime &data);
    void sendChatMessageResponse(const protocol::PlayerChatMessage &packet);
    void sendSystemChatMessage(const protocol::SystemChatMessage &packet);
    void sendWorldEvent(const protocol::WorldEvent &packet);
    void playSoundEffect(SoundsList sound, FloatingPosition position, SoundCategory category = SoundCategory::Master);
    void playSoundEffect(SoundsList sound, const Entity &entity, SoundCategory category = SoundCategory::Master);
    void playCustomSound(std::string sound, FloatingPosition position, SoundCategory category = SoundCategory::Master);
    void stopSound(uint8_t flags = 0, SoundCategory category = SoundCategory::Ambient, std::string sound = "");
    void sendKeepAlive(long id);
    void sendSynchronizePosition(const Vector3<double> &pos);
    void sendSwingArm(bool mainHand, int32_t swingerId);
    void sendTeleportEntity(int32_t id, const Vector3<double> &pos);
    void sendRemoveEntities(const std::vector<int32_t> &entities);
    void sendUpdateEntityPosition(const protocol::UpdateEntityPosition &data);
    void sendUpdateEntityPositionAndRotation(const protocol::UpdateEntityPositionRotation &data);
    void sendUpdateEntityRotation(const protocol::UpdateEntityRotation &data);
    void sendHeadRotation(const protocol::HeadRotation &data);
    void sendSetCenterChunk(const Position2D &pos);
    void sendChunkAndLightUpdate(const Position2D &pos);
    void sendChunkAndLightUpdate(int32_t x, int32_t z);
    void sendChunkAndLightUpdate(const world_storage::ChunkColumn &chunk);
    void sendUnloadChunk(int32_t x, int32_t z);
    void sendBlockUpdate(const protocol::BlockUpdate &packet);
    void sendPlayerAbilities(const protocol::PlayerAbilitiesClient &packet);
    void sendFeatureFlags(const protocol::FeatureFlags &packet);
    void sendServerData(const protocol::ServerData &packet);
    void sendEntityAnimation(protocol::EntityAnimation::ID animId, int32_t entityID);
    void sendSetContainerContent(const protocol::SetContainerContent &packet);
    void sendUpdateRecipes(const protocol::UpdateRecipes &packet);
    void sendUpdateTags(const protocol::UpdateTags &packet);
    void sendCommands(const protocol::Commands &packet);
    void sendChangeDifficulty(const protocol::ChangeDifficultyClient &packet);
    void sendSetHeldItem(const protocol::SetHeldItemClient &packet);
    void sendEntityEvent(const protocol::EntityEvent &packet);
    void sendUpdateRecipiesBook(const protocol::UpdateRecipesBook &packet);
    void sendInitializeWorldBorder(const protocol::InitializeWorldBorder &packet);
    void sendSetDefaultSpawnPosition(const protocol::SetDefaultSpawnPosition &packet);
    // void sendSetEntityMetadata(const protocol::SetEntityMetadata &packet);
    void sendUpdateAttributes(const protocol::UpdateAttributes &packet);
    void sendUpdateAdvancements(const protocol::UpdateAdvancements &packet);
    void sendSetExperience(const protocol::SetExperience &packet);

private:
    void _onConfirmTeleportation(const std::shared_ptr<protocol::ConfirmTeleportation> &pck);
    void _onQueryBlockEntityTag(const std::shared_ptr<protocol::QueryBlockEntityTag> &pck);
    void _onChangeDifficulty(const std::shared_ptr<protocol::ChangeDifficulty> &pck);
    void _onChatMessage(const std::shared_ptr<protocol::ChatMessage> &pck);
    void _onMessageAcknowledgement(const std::shared_ptr<protocol::MessageAcknowledgement> &pck);
    void _onChatCommand(const std::shared_ptr<protocol::ChatCommand> &pck);
    void _onClientCommand(const std::shared_ptr<protocol::ClientCommand> &pck);
    void _onClientInformation(const std::shared_ptr<protocol::ClientInformation> &pck);
    void _onCommandSuggestionRequest(const std::shared_ptr<protocol::CommandSuggestionRequest> &pck);
    void _onClickContainerButton(const std::shared_ptr<protocol::ClickContainerButton> &pck);
    void _onClickContainer(const std::shared_ptr<protocol::ClickContainer> &pck);
    void _onCloseContainerRequest(const std::shared_ptr<protocol::CloseContainerRequest> &pck);
    void _onPluginMessage(const std::shared_ptr<protocol::PluginMessage> &pck);
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
    void _onPlayerSession(const std::shared_ptr<protocol::PlayerSession> &pck);
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
    void _onSetCreativeModeSlot(const std::shared_ptr<protocol::SetCreativeModeSlot> &pck);
    void _onProgramJigsawBlock(const std::shared_ptr<protocol::ProgramJigsawBlock> &pck);
    void _onProgramStructureBlock(const std::shared_ptr<protocol::ProgramStructureBlock> &pck);
    void _onUpdateSign(const std::shared_ptr<protocol::UpdateSign> &pck);
    void _onSwingArm(const std::shared_ptr<protocol::SwingArm> &pck);
    void _onTeleportToEntity(const std::shared_ptr<protocol::TeleportToEntity> &pck);
    void _onUseItemOn(const std::shared_ptr<protocol::UseItemOn> &pck);
    void _onUseItem(const std::shared_ptr<protocol::UseItem> &pck);

private:
    void _processKeepAlive();
    void _tickPosition();
    void _updateRenderedChunks(const Position2D &oldChunkPos, const Position2D &newChunkPos);
    void _continueLoginSequence();
    void _unloadChunk(int32_t x, int32_t z);
    void _foodTick();
    void _eat(ItemId itemId);

    Client *_cli;
    std::string _username;
    std::string _uuidString;
    u128 _uuid;
    long _keepAliveId;
    uint8_t _keepAliveIgnored;
    uint16_t _heldItem;
    player_attributes::Gamemode _gamemode;
    TickClock _keepAliveClock;
    std::unordered_map<Position2D, ChunkState> _chunks;

    // Food Mechanics
    int _foodLevel;
    float _foodSaturationLevel;
    int _foodTickTimer;
    float _foodExhaustionLevel;

    // player status
    protocol::ClientInformation::ChatVisibility _chatVisibility;
    bool _isFlying;
    bool _isOperator;
    bool _isSprinting;
    bool _isJumping;
};

#endif // CUBICSERVER_PLAYER_HPP
