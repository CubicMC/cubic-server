#ifndef CUBICSERVER_SCOREBOARD_SCOREBOARD_HPP
#define CUBICSERVER_SCOREBOARD_SCOREBOARD_HPP

#include <array>
#include <memory>
#include <unordered_map>

#include "Objectives.hpp"
#include "Teams.hpp"

class ScoreboardSystem;
class WorldGroup;
class Player;

namespace Scoreboard {
enum DisplaySlot {
    list = 0,
    sidebar,
    belowName,
    sidebarTeamBlack,
    sidebarTeamDarkBlue,
    sidebarTeamDarkGreen,
    sidebarTeamDarkAqua,
    sidebarTeamDarkRed,
    sidebarTeamDarkPurple,
    sidebarTeamGold,
    sidebarTeamGray,
    sidebarTeamDarkGray,
    sidebarTeamBlue,
    sidebarTeamGreen,
    sidebarTeamAqua,
    sidebarTeamRed,
    sidebarTeamLightPurple,
    sidebarTeamYellow,
    sidebarTeamWhite
};

class Scoreboard {
public:
    Scoreboard(const ScoreboardSystem &system, const WorldGroup &worldGroup);
    ~Scoreboard() = default;

    const WorldGroup &getWorldGroup(void) const noexcept;
    bool isObjective(const std::string &name) const noexcept;
    Objective::Objective &getObjective(const std::string &name);
    std::unordered_map<std::string, std::shared_ptr<Objective::Objective>> &getObjectives(void) noexcept;

    bool addObjective(const std::string &name, const std::string &criteria);
    bool addObjective(const std::string &name, const std::string &criteria, std::string &displayName);
    bool removeObjective(const std::string &name);
    void displayObjective(DisplaySlot slot, Objective::Objective *objective) noexcept;

    void addToObjectivebyCriteria(const std::string &criteria, const std::string &entity, int32_t value);
    void setToObjectivebyCriteria(const std::string &criteria, const std::string &entity, int32_t value);

    bool isTeam(const std::string &name) const noexcept;
    Team::Team &getTeam(const std::string &name);
    std::unordered_map<std::string, std::unique_ptr<Team::Team>> &getTeams(void) noexcept;

    bool addTeam(const std::string &name);
    bool addTeam(const std::string &name, const Team::Color &color);
    bool addTeam(const std::string &name, const std::string &displayName);
    bool addTeam(const std::string &name, const Team::Color &color, const std::string &displayName);
    bool removeTeam(const std::string &name);

    void sendAddObjective(const Objective::Objective &objective) const;
    void sendRemoveObjective(const Objective::Objective &objective) const;
    void sendDisplayObjective(DisplaySlot slot, const Objective::Objective *objective) const;

    void sendAddTeam(const Team::Team &team) const;
    void sendRemoveTeam(const Team::Team &team) const;

    void sendScoreboardStatus(Player &player) const;

private:
    const ScoreboardSystem &_system;
    const WorldGroup &_worldGroup;
    std::unordered_map<std::string, std::shared_ptr<Objective::Objective>> _objectives;
    std::unordered_map<std::string, std::unique_ptr<Team::Team>> _teams;
    std::array<Objective::Objective *, 18> _displaySlots;
    std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<Objective::Objective>>> _objectivesByCriteria;
};
}

#endif // CUBICSERVER_SCOREBOARD_SCOREBOARD_HPP
