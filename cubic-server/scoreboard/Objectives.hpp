#ifndef CUBICSERVER_SCOREBOARD_OBJECTIVES_HPP
#define CUBICSERVER_SCOREBOARD_OBJECTIVES_HPP

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

#include "chat/Message.hpp"

class Entity;
class ScoreboardSystem;

namespace Scoreboard {
class Scoreboard;

class Score {
public:
    Score(const int32_t &value = 0);
    Score(const int32_t &value, bool locked);
    ~Score();

    const int32_t &get(void) const noexcept;
    void set(int32_t value) noexcept;
    void add(int32_t value) noexcept;
    void substract(int32_t value) noexcept;

    bool isLocked(void) const noexcept;
    void enable(void) noexcept;
    void disable(void) noexcept;

private:
    int32_t _score;
    bool _locked;
};

namespace Objective {
enum class RenderType : int32_t {
    RenderInteger = 0,
    RenderHearts
};

class Objective {
public:
    Objective(const Scoreboard &scoreboard, const std::string &name, const std::string &criteria);
    Objective(const Scoreboard &scoreboard, const std::string &name, const std::string &criteria, const chat::Message &displayName);
    Objective(const Scoreboard &scoreboard, const std::string &name, const std::string &criteria, const RenderType &renderType);
    Objective(const Scoreboard &scoreboard, const std::string &name, const std::string &criteria, const chat::Message &displayName, const RenderType &renderType);
    ~Objective();

    const std::string &getName(void) const noexcept;
    const std::string &getCriteria(void) const noexcept;
    const chat::Message &getDisplayName(void) const noexcept;
    const RenderType &getRenderType(void) const noexcept;
    std::unordered_map<std::string, Score> &getScores(void) noexcept;
    Score &getScore(const std::string &name);

    void setDisplayName(const std::string &displayName) noexcept;
    void setRenderType(RenderType type) noexcept;
    void setScore(const std::string &name, int32_t value);
    void addScore(const std::string &name, int32_t value);
    void substractScore(const std::string &name, int32_t value);
    void deleteScore(const std::string &name);

    Score &operator[](const std::string &name);

    void sendUpdateObjective(void) const;
    void sendUpdateScore(const std::string &name, const Score &score) const;
    void sendRemoveScore(const std::string &name) const;

private:
    const Scoreboard &_scoreboard;
    const std::string _name;
    const std::string _criteria;
    chat::Message _displayName; // json format
    RenderType _renderType;
    std::unordered_map<std::string, Score> _values;
};
}
}

#endif /* CUBICSERVER_SCOREBOARD_OBJECTIVES_HPP */
