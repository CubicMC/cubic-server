#include "Dimension.hpp"

#include "Player.hpp"
#include "Server.hpp"
#include "World.hpp"
#include "entities/Entity.hpp"
#include "entities/EntityType.hpp"
#include "logging/logging.hpp"
#include "math/Vector3.hpp"
#include "protocol/ClientPackets.hpp"
#include "tiles-entities/TileEntity.hpp"
#include "tiles-entities/TileEntityList.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/Level.hpp"
#include <chrono>
#include <cstdint>
#include <memory>
#include <mutex>
#include <thread>

Dimension::Dimension(std::shared_ptr<World> world, world_storage::DimensionType dimensionType):
    _playersMutex(),
    _entitiesMutex(),
    _newEntitiesMutex(),
    _loadingChunksMutex(),
    _dimensionLock(std::counting_semaphore<SEMAPHORE_MAX>(0)),
    _entities({}),
    _newEntities({}),
    _players({}),
    _world(world),
    _processingMutex(),
    _isInitialized(false),
    _isRunning(false),
    _level(),
    _loadingChunks({}),
    _processingThread(),
    _dimensionType(dimensionType),
    _circularBufferTps((TICK_PER_MINUTE * 15)),
    _previousTickTime(std::chrono::high_resolution_clock::now()),
    _circularBufferMSPT((TICK_PER_MINUTE * 15))
{
}

void Dimension::tick()
{
    auto startTickTime = std::chrono::high_resolution_clock::now();

    _removeDeadEntities();
    _removeDeadPlayers();

    {
        std::unique_lock a(_entitiesMutex, std::defer_lock);
        std::unique_lock b(_newEntitiesMutex, std::defer_lock);
        std::lock(a, b);

        for (auto ent : _entities) {
            ent->tick();
        }

        if (_newEntities.size() != 0) {
            _entities.insert(_entities.end(), _newEntities.begin(), _newEntities.end());
            _newEntities.clear();
        }
    }
    {
        std::unique_lock a(_entitiesMutex, std::defer_lock);
        std::unique_lock b(_playersMutex, std::defer_lock);
        std::lock(a, b);

        // We remove all entities below a certain threshold
        // Especially useful for arrows that currently go
        // through blocks
        constexpr float minYLevelForEntities = -200.0f;
        for (auto &ent : _entities) {
            if (ent->getType() == EntityType::Player)
                continue;
            if (ent->getPosition().y < minYLevelForEntities)
                _idsToRemove.push_back(ent->getId());
        }
        if (!_idsToRemove.empty()) {
            _players.erase(
                std::remove_if(
                    _players.begin(), _players.end(),
                    [this](const std::shared_ptr<Player> player) {
                        int32_t playerId = player->getId();
                        return std::find_if(_idsToRemove.begin(), _idsToRemove.end(), [playerId](int32_t id) {
                                   return id == playerId;
                               }) != _idsToRemove.end();
                    }
                ),
                _players.end()
            );
            for (auto player : _players) {
                player->sendRemoveEntities(_idsToRemove);
            }
            _entities.erase(
                std::remove_if(
                    _entities.begin(), _entities.end(),
                    [this](const std::shared_ptr<Entity> ent) {
                        int32_t entId = ent->getId();
                        return std::find_if(_idsToRemove.begin(), _idsToRemove.end(), [entId](int32_t id) {
                                   return id == entId;
                               }) != _idsToRemove.end();
                    }
                ),
                _entities.end()
            );
            _idsToRemove.clear();
        }
    }
    uint32_t rts = CONFIG["randomtickspeed"].as<uint32_t>();
    if (rts != 0) {
        for (auto &[_, chunk] : _level.getChunkColumns()) {
            // TODO(huntears): Test if a chunk is within simulation distance of a player
            if (!chunk.isReady())
                continue;
            chunk.processRandomTick(rts);
        }
    }
    for (auto &[_, chunk] : _level.getChunkColumns()) {
        if (!chunk.isReady())
            continue;
        if (auto &blocks = chunk.getBlocksToBeUpdated(); !blocks.empty()) {
            std::lock_guard _(_playersMutex);
            for (auto player : _players) {
                for (auto [pos, id] : blocks) {
                    LTRACE("Sending block update to player {} for block {} with id {}", player->getUsername(), pos, id);
                    player->sendBlockUpdate({pos, id});
                }
            }
            blocks.clear();
        }
    }
    for (auto &[_, chunk] : _level.getChunkColumns()) {
        if (!chunk.isReady())
            continue;
        chunk.tick();
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto compute_time = endTime - _previousTickTime;
    auto msptTime = endTime - startTickTime;
    _previousTickTime = endTime;
    float compute_time_micro = (float) std::chrono::duration_cast<std::chrono::microseconds>(compute_time).count();
    float msptTime_micro = (float) std::chrono::duration_cast<std::chrono::microseconds>(msptTime).count();
    _circularBufferTps.push_back(compute_time_micro);
    _circularBufferMSPT.push_back(msptTime_micro);
    switch (_dimensionType) {
    case world_storage::DimensionType::OVERWORLD:
        PEXPP(addMsptOverworld, msptTime_micro / MILLIS_IN_ONE_SEC)
        break;
    case world_storage::DimensionType::NETHER:
        PEXPP(addMsptNether, msptTime_micro / MILLIS_IN_ONE_SEC)
        break;
    case world_storage::DimensionType::END:
        PEXPP(addMsptEnd, msptTime_micro / MILLIS_IN_ONE_SEC)
        break;
    }
}

void Dimension::_removeDeadEntities()
{
    std::lock_guard _(_entitiesMutex);

    _entities.erase(
        std::remove_if(
            _entities.begin(), _entities.end(),
            [this](const std::shared_ptr<Entity> ent) {
                if (ent->isReadyToBeRemoved()) {
                    LDEBUG("Entity {} removed from dimension {}", ent->getId(), this->_dimensionType);
                    for (auto player : this->_players)
                        player->sendRemoveEntities({ent->getId()});
                    return true;
                }
                return false;
            }
        ),
        _entities.end()
    );
}

void Dimension::_removeDeadPlayers()
{
    std::lock_guard _(_playersMutex);
    std::vector<int32_t> players_to_remove_buf;

    for (auto player : this->_players) {
        if (player->isReadyToBeRemoved()) {
            players_to_remove_buf.push_back(player->getId());
            player->setReadyToRemove(false);
        }
    }
    if (players_to_remove_buf.empty())
        return;

    for (auto player : this->_players) {
        player->sendRemoveEntities(players_to_remove_buf);
    }
}

void Dimension::stop()
{
    this->_isRunning = false;
    this->_dimensionLock.release(_dimensionLock.max());

    if (_processingThread.joinable())
        _processingThread.join();
    // TODO: Save the dimension

    _level.clear();
}

void Dimension::initialize()
{
    this->_isRunning = true;
    this->_processingThread = std::thread(&Dimension::_run, this);
}

std::shared_ptr<Entity> Dimension::getEntityByID(int32_t id)
{
    std::lock_guard _(_entitiesMutex);
    for (auto &entity : _entities)
        if (entity->getId() == id)
            return entity;
    LERROR("Entity not found");
    return nullptr;
}

std::shared_ptr<const Entity> Dimension::getEntityByID(int32_t id) const
{
    std::lock_guard _(_entitiesMutex);
    for (auto &entity : _entities)
        if (entity->getId() == id)
            return entity;
    LERROR("Entity not found");
    return nullptr;
}

void Dimension::removeEntity(int32_t entity_id)
{
    {
        std::lock_guard _(_entitiesMutex);

        _entities.erase(
            std::remove_if(
                _entities.begin(), _entities.end(),
                [entity_id](const std::shared_ptr<Entity> ent) {
                    return entity_id == ent->getId();
                }
            ),
            _entities.end()
        );
    }

    std::lock_guard _(_playersMutex);
    for (auto player : _players)
        player->sendRemoveEntities({entity_id});
}

void Dimension::removePlayer(int32_t entity_id)
{
    std::lock_guard _(_playersMutex);
    LDEBUG("Removing player with id: {}", entity_id);
    _players.erase(
        std::remove_if(
            _players.begin(), _players.end(),
            [entity_id](const std::shared_ptr<Player> ent) {
                return entity_id == ent->getId();
            }
        ),
        _players.end()
    );
    for (auto player : _players)
        player->sendRemoveEntities({entity_id});
}

void Dimension::addEntity(std::shared_ptr<Entity> entity)
{
    std::lock_guard _(_newEntitiesMutex);
    _newEntities.emplace_back(entity);
}

void Dimension::addPlayer(std::shared_ptr<Player> entity)
{
    std::lock_guard _(_playersMutex);
    _players.emplace_back(entity);
}

void Dimension::generateChunk(Position2D pos, world_storage::GenerationState goalState) { generateChunk(pos.x, pos.z, goalState); }

void Dimension::generateChunk(UNUSED int x, UNUSED int z, UNUSED world_storage::GenerationState goalState) { }

void Dimension::loadOrGenerateChunk(int x, int z, const std::shared_ptr<Player> player)
{
    std::lock_guard _(_loadingChunksMutex);
    if (this->_loadingChunks.contains({x, z})) {
        if (std::find_if(this->_loadingChunks[{x, z}].players.begin(), this->_loadingChunks[{x, z}].players.end(), [player](const std::weak_ptr<const Player> current_weak_player) {
                if (auto current_player = current_weak_player.lock())
                    return current_player->getId() == player->getId();
                return false;
            }) == this->_loadingChunks[{x, z}].players.end()) {
            this->_loadingChunks[{x, z}].players.push_back(player);
        }
        return;
    }

    auto id = this->_world->getGenerationPool().addJob(
        [this, x, z] {
            std::lock_guard _(this->_playersMutex);
            double current_min = 999999.0f; // TODO(huntears): Change this magic value xd;
            for (auto player : this->getPlayers()) {
                const auto &pos = player->getPosition();
                const Vector3<double> chunkPos = {(double) x * 16, pos.y, (double) z * 16};
                current_min = std::min(current_min, pos.distance(chunkPos));
            }
            return static_cast<int>(std::ceil(current_min));
        },
        [this, x, z] {
            // TODO: load chunk from disk if it exists
            this->generateChunk(x, z);

            if (!this->hasChunkLoaded(x, z))
                return;

            this->sendChunkToPlayers(x, z);
        }
    );

    auto request = ChunkRequest {id, {player}};

    this->_loadingChunks[{x, z}] = request;

    return;
}

void Dimension::_run()
{
    // TODO(huntears): Remove this busy loop
    while (this->_isRunning && !this->_isInitialized)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    while (this->_isRunning) {
        this->_dimensionLock.acquire();
        this->tick();
    }
}

bool Dimension::hasChunkLoaded(int x, int z) const { return this->_level.hasChunkColumn(x, z); }

void Dimension::removePlayerFromLoadingChunk(const Position2D &pos, const std::shared_ptr<const Player> player)
{
    std::lock_guard _(_loadingChunksMutex);
    if (!this->_loadingChunks.contains(pos))
        return;

    this->_loadingChunks[pos].players.erase(
        std::remove_if(
            this->_loadingChunks[pos].players.begin(), this->_loadingChunks[pos].players.end(),
            [player](const std::weak_ptr<const Player> current_weak_player) {
                if (auto current_player = current_weak_player.lock())
                    return current_player->getId() == player->getId();
                return true;
            }
        ),
        this->_loadingChunks[pos].players.end()
    );

    if (this->_loadingChunks[pos].players.empty() && this->getWorld()->getGenerationPool().cancelJob(this->_loadingChunks[pos].id)) {
        // this->_loadingChunks[pos].task->cancel();
        // This could be replaced using either an iterator, or something else (maybe an if condition inside the job? or simply integrated inside the overlay.)
        this->_loadingChunks.erase(pos);
    }
}

world_storage::ChunkColumn &Dimension::getChunk(int x, int z) { return this->_level.getChunkColumn(x, z); }
world_storage::ChunkColumn &Dimension::getChunk(const Position2D &pos) { return this->_level.getChunkColumn(pos); }

const world_storage::ChunkColumn &Dimension::getChunk(int x, int z) const { return this->_level.getChunkColumn(x, z); }
const world_storage::ChunkColumn &Dimension::getChunk(const Position2D &pos) const { return this->_level.getChunkColumn(pos); }

void Dimension::spawnPlayer(Player &current)
{
    auto current_id = current.getId();
    {

        std::lock_guard _(_playersMutex);
        for (auto player : _players) {
            LDEBUG("player is: {}", player->getUsername());
            LDEBUG("current is: {}", current.getUsername());
            // if (current->getPos().distance(player->getPos()) <= 12) {
            if (player->getId() != current_id) {
                player->sendSpawnPlayer(
                    {current_id, current.getUuid(), current.getPosition().x, current.getPosition().y, current.getPosition().z, current.getRotation().x, current.getRotation().z}
                );
                LDEBUG("send spawn player to {}", player->getUsername());
                current.sendSpawnPlayer(
                    {player->getId(), player->getUuid(), player->getPosition().x, player->getPosition().y, player->getPosition().z, player->getRotation().x,
                     player->getRotation().z}
                );
                LDEBUG("send spawn player to {}", current.getUsername());
                //}
            }
            player->sendEntityMetadata(current);
            current.sendEntityMetadata(*player);
        }
    }
    {
        std::lock_guard _(_entitiesMutex);
        for (auto ent : _entities) {
            if (ent->getType() == EntityType::Player)
                continue;
            current.sendSpawnEntity(*ent);
            current.sendEntityMetadata(*ent);
        }
    }
}

void Dimension::spawnEntity(const std::shared_ptr<const Entity> current)
{
    std::lock_guard _(_entitiesMutex);
    for (auto player : _players) {
        LDEBUG("spawn entity with id: {}", current->getId());
        player->sendSpawnEntity({
            current->getId(), // Entity ID
            current->getUuid(), // Entity UUID
            current->getType(), // Entity Type
            current->getPosition().x, // Entity Position X
            current->getPosition().y, // Entity Position Y
            current->getPosition().z, // Entity Position Z
            current->getRotation().z, // Entity Pitch
            current->getRotation().x, // Entity Yaw
            0, // Entity Head Yaw
            0, // Entity data
            (int16_t) current->getVelocity().x, // Entity Velocity X
            (int16_t) current->getVelocity().y, // Entity Velocity Y
            (int16_t) current->getVelocity().z // Entity Velocity Z
        });
        player->sendEntityMetadata(*current);
    }
}

void Dimension::updateBlock(Position position, int32_t id)
{
    LDEBUG("Dimension block update {} -> {}", position, id);
    auto &chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);

    auto chunkPosition = world_storage::convertPositionToChunkPosition(position);
    chunk.updateBlock(chunkPosition, id);
    std::shared_ptr<const tile_entity::TileEntity> tileEntity = nullptr;
    if (id == 0)
        chunk.removeTileEntity(position);
    else {
        using namespace tile_entity;
        if (convertBlockNameToBlockEntityType(GLOBAL_PALETTE.fromProtocolIdToBlock(id).name) != TileEntityType::UnknownType) {
            chunk.addTileEntity(createTileEntity(id, position));
            tileEntity = chunk.getTileEntity(position);
        }
    }
    if (tileEntity) {
        std::lock_guard _(_playersMutex);
        for (auto player : _players)
            player->sendBlockEntityData(tileEntity->toBlockEntityData());
    }
}

void Dimension::addTileEntity(const Position &position, BlockId type)
{
    auto &chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);

    auto chunkPosition = world_storage::convertPositionToChunkPosition(position);
    chunk.modifyBlock(chunkPosition, type);
    chunk.addTileEntity(tile_entity::createTileEntity(type, position));
    for (auto player : _players) {
        player->sendBlockUpdate({position, type});
        player->sendBlockEntityData(chunk.getTileEntity(position)->toBlockEntityData());
    }
}

void Dimension::removeTileEntity(const Position &position)
{
    auto &chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);

    auto chunkPosition = world_storage::convertPositionToChunkPosition(position);

    auto type = chunk.getBlock(chunkPosition);
    chunk.modifyBlock(chunkPosition, 0);
    chunk.removeTileEntity(position);
    for (auto player : _players) {
        player->sendBlockUpdate({position, type});
    }
}

std::shared_ptr<tile_entity::TileEntity> Dimension::getTileEntity(const Position &position)
{
    auto &chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);
    return chunk.getTileEntity(position);
}

std::shared_ptr<const tile_entity::TileEntity> Dimension::getTileEntity(const Position &position) const
{
    auto &chunk = this->_level.getChunkColumnFromBlockPos(position.x, position.z);
    return chunk.getTileEntity(position);
}

void Dimension::updateEntityAttributes(const protocol::UpdateAttributes &attributes)
{
    std::lock_guard _(_entitiesMutex);
    for (auto player : _players) {
        player->sendUpdateAttributes(attributes);
    }
}

void Dimension::sendChunkToPlayers(int x, int z)
{
    // This send the chunk to the players that are loading it
    std::lock_guard _(_loadingChunksMutex);

    // This if should not be needed normally but somehow 2 jobs get the same
    // chunk to process and try to send it to the players at the same time
    // which will literally segfault the whole stuff.
    // TODO(huntears): Fix that freaking threadpool :(
    if (!this->_loadingChunks.contains({x, z}))
        return;

    for (auto weak_player : this->_loadingChunks[{x, z}].players) {
        if (auto player = weak_player.lock()) {
            player->sendChunkAndLightUpdate(this->_level.getChunkColumn(x, z));
        }
    }
    this->_loadingChunks.erase({x, z});
}

Tps Dimension::getTps() const
{
    const auto buffer_size = _circularBufferTps.size();
    const auto buffer_end = _circularBufferTps.end();
    const auto tpsCalculation = [buffer_end](const int tick_number) {
        return 1.0f / ((std::accumulate(buffer_end - tick_number, buffer_end, 0.0f) / (float) (tick_number)) / MICROSECS_IN_ONE_SEC);
    };
    const float tpsOnFullBuffer = tpsCalculation(buffer_size);

    Tps tps {0, 0, 0};

    if (buffer_size < TICK_PER_MINUTE - 1) {
        tps.oneMinTps = tps.fiveMinTps = tps.fifteenMinTps = tpsOnFullBuffer;
        return tps;
    }
    tps.oneMinTps = tpsCalculation(TICK_PER_MINUTE);
    if (buffer_size < (TICK_PER_MINUTE * 5) - 1) {
        tps.fiveMinTps = tps.fifteenMinTps = tpsOnFullBuffer;
        return tps;
    }
    tps.fiveMinTps = tpsCalculation((TICK_PER_MINUTE * 5));
    if (buffer_size < (TICK_PER_MINUTE * 15) - 1) {
        tps.fifteenMinTps = tpsOnFullBuffer;
        return tps;
    }
    tps.fifteenMinTps = tpsCalculation((TICK_PER_MINUTE * 15));
    return tps;
}

MSPTInfos Dimension::getMSPTInfos() const
{
    if (_circularBufferMSPT.empty())
        return {0, 0, 0};
    const auto buffer_begin = _circularBufferMSPT.begin();
    const auto buffer_end = _circularBufferMSPT.end();
    // clang-format off
    return {
        *std::min_element(buffer_begin, buffer_end) / MILLIS_IN_ONE_SEC,
        (std::accumulate(buffer_begin, buffer_end, 0.0f) / float(_circularBufferMSPT.size())) / MILLIS_IN_ONE_SEC,
        *std::max_element(buffer_begin, buffer_end) / MILLIS_IN_ONE_SEC
    };
    // clang-format on
}
