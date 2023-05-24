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
#include "world_storage/LevelData.hpp"

class Chat;
class Dimension;
class Entity;
class Player;
class WorldGroup;

constexpr int NB_SPAWN_CHUNKS = 19;

class World : public std::enable_shared_from_this<World> {
public:
    World(std::shared_ptr<WorldGroup> worldGroup, std::string folder);
    virtual ~World() = default;

    virtual void tick();
    virtual void initialize();
    virtual void stop();

    NODISCARD virtual bool isInitialized() const;
    NODISCARD virtual const std::shared_ptr<WorldGroup> getWorldGroup() const;
    NODISCARD virtual std::shared_ptr<WorldGroup> getWorldGroup();
    NODISCARD virtual const std::shared_ptr<Chat> getChat() const;
    NODISCARD virtual std::shared_ptr<Chat> getChat();
    NODISCARD virtual std::shared_ptr<Dimension> getDimension(const std::string_view &name);
    NODISCARD virtual const std::shared_ptr<Dimension> getDimension(const std::string_view &name) const;
    NODISCARD virtual std::unordered_map<std::string_view, std::shared_ptr<Dimension>> &getDimensions();
    NODISCARD virtual const std::unordered_map<std::string_view, std::shared_ptr<Dimension>> &getDimensions() const;

    NODISCARD virtual const world_storage::LevelData &getLevelData() const;
    virtual void setLevelData(const world_storage::LevelData &value);
    virtual void updateTime();
    virtual void sendPlayerInfoAddPlayer(Player *);
    virtual void sendPlayerInfoRemovePlayer(const Player *current);

    NODISCARD virtual thread_pool::PriorityThreadPool &getGenerationPool();

    NODISCARD virtual Seed getSeed() const;
    NODISCARD virtual uint8_t getRenderDistance() const;
    NODISCARD virtual long getTime() const;
    NODISCARD virtual long getAge() const;

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

protected:
    std::shared_ptr<Chat> _chat;
    std::shared_ptr<WorldGroup> _worldGroup;
    std::unordered_map<std::string_view, std::shared_ptr<Dimension>> _dimensions;
    long _age;
    long _time;
    uint8_t _renderDistance;
    world_storage::LevelData _levelData;
    TickClock _timeUpdateClock;
    Seed _seed;
    thread_pool::PriorityThreadPool _generationPool;
    std::string _folder;
};

#endif // CUBICSERVER_WORLD_HPP
