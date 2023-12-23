#ifndef CUBICSERVER_WORLD_HPP
#define CUBICSERVER_WORLD_HPP

#include <functional>
#include <memory>
#include <thread>
#include <vector>

#include "TickClock.hpp"
#include "options.hpp"
#include "thread_pool/PriorityThreadPool.hpp"
#include "types.hpp"
#include "world_storage/ChunkColumn.hpp"
#include "world_storage/LevelData.hpp"

class Chat;
class Dimension;
class Entity;
class Player;
class WorldGroup;

constexpr int NB_SPAWN_CHUNKS = 19;

class World : public std::enable_shared_from_this<World> {
public:
    World(std::shared_ptr<WorldGroup> worldGroup, world_storage::WorldType worldType, std::string folder);
    virtual ~World() = default;

    virtual void tick();
    virtual void initialize();
    virtual void stop();

    NODISCARD virtual bool isInitialized() const;
    NODISCARD virtual std::shared_ptr<const WorldGroup> getWorldGroup() const { return _worldGroup; }
    NODISCARD virtual std::shared_ptr<const Chat> getChat() const { return _chat; }
    NODISCARD virtual std::shared_ptr<const Dimension> getDimension(const std::string_view &name) const { return _dimensions.at(name); }
    NODISCARD virtual const std::unordered_map<std::string_view, std::shared_ptr<Dimension>> &getDimensions() const { return _dimensions; }
    NODISCARD virtual const world_storage::LevelData &getLevelData() const { return _levelData; }
    NODISCARD virtual Seed getSeed() const { return _seed; }
    NODISCARD virtual uint8_t getRenderDistance() const { return _renderDistance; }
    NODISCARD virtual long getTime() const { return _time; }
    NODISCARD virtual long getAge() const { return _age; }
    NODISCARD virtual world_storage::WorldType getWorldType() const { return _worldType; }

    NODISCARD virtual std::shared_ptr<WorldGroup> getWorldGroup() { return _worldGroup; }
    NODISCARD virtual std::shared_ptr<Chat> getChat() { return _chat; }
    NODISCARD virtual std::shared_ptr<Dimension> getDimension(const std::string_view &name) { return _dimensions.at(name); }
    NODISCARD virtual std::unordered_map<std::string_view, std::shared_ptr<Dimension>> &getDimensions() { return _dimensions; }
    NODISCARD virtual thread_pool::PriorityThreadPool &getGenerationPool() { return _generationPool; }

    virtual void setLevelData(const world_storage::LevelData &value) { _levelData = value; }
    virtual void updateTime();
    virtual void sendPlayerInfoAddPlayer(Player *);
    virtual void sendPlayerInfoRemovePlayer(const Player *current);

    /*
    **  Used in the /time command.
    **  Adds time to the current world time
    */
    virtual int addTime(int time);

    /*
    **  Used in the /time command.
    **  Sets the current world time to the given time
    */
    virtual void setTime(int time);

    /**
     * @brief Get the tps of all dimensions
     * @return a vector of pairs of dimension type and their tps
     */
    virtual std::vector<std::pair<world_storage::DimensionType, Tps>> getTps() const;

    /**
     * @brief Get the mspt of all dimensions
     * @return a vector of pairs of dimension type and their mspt
     */
    virtual std::vector<std::pair<world_storage::DimensionType, MSPTInfos>> getMSPTInfos() const;

protected:
    std::shared_ptr<Chat> _chat;
    std::shared_ptr<WorldGroup> _worldGroup;
    std::unordered_map<std::string_view, std::shared_ptr<Dimension>> _dimensions;
    long _age;
    long _time;
    uint8_t _renderDistance;
    world_storage::LevelData _levelData;
    TickClock _timeUpdateClock;
    const Seed _seed;
    thread_pool::PriorityThreadPool _generationPool;
    world_storage::WorldType _worldType;
    std::string _folder;
    TickClock _publishTpsClock;
};

#endif // CUBICSERVER_WORLD_HPP
