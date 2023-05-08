#ifndef CUBICSERVER_SCOREBOARD_HPP
#define CUBICSERVER_SCOREBOARD_HPP

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>
#include <array>
#include <cstdint>

#include "Objectives.hpp"
#include "Teams.hpp"

class Entity;

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
};

class Scoreboards {
public:
    Scoreboards();
    ~Scoreboards();

    void initialize(void);

    void addObjectiveCriteria(const std::string &criteria);

    const Scoreboard::Objective::Objective *getObjective(const std::string &name);
    const std::unordered_map<std::string, std::unique_ptr<Scoreboard::Objective::Objective>> &getObjectives(void);
    
    void addObjective(const std::string &name, Scoreboard::Objective::Criteria criteria);
    void addObjective(const std::string &name, Scoreboard::Objective::Criteria criteria, std::string &displayName);
    void removeObjective(const std::string &name);
    void displayObjective(Scoreboard::DisplaySlot slot, Scoreboard::Objective::Objective *objective) noexcept;

private:
    std::unordered_map<std::string, std::unique_ptr<Scoreboard::Objective::Objective>> _objectives;
    std::vector<Scoreboard::Score> _scores;
    std::vector<Scoreboard::Team::Team> _teams;
    std::array<Scoreboard::Objective::Objective *, 18> _displaySlots;
    std::vector<std::string> _criteriaList;
};

#endif /* CUBICSERVER_SCOREBOARD_HPP */
