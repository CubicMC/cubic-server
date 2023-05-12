#ifndef CUBICSERVER_SCOREBOARD_SCOREBOARD_HPP
#define CUBICSERVER_SCOREBOARD_SCOREBOARD_HPP

#include <unordered_map>
#include <memory>
#include <array>

#include "Objectives.hpp"
#include "Teams.hpp"

class ScoreboardSystem;

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
        Scoreboard(const ScoreboardSystem &system);
        ~Scoreboard() = default;

        bool isObjective(const std::string &name) const noexcept;
        const Objective::Objective &getObjective(const std::string &name) const;
        const std::unordered_map<std::string, std::shared_ptr<Objective::Objective>> &getObjectives(void) const noexcept;

        bool addObjective(const std::string &name, const std::string &criteria);
        bool addObjective(const std::string &name, const std::string &criteria, std::string &displayName);
        bool removeObjective(const std::string &name);
        void displayObjective(DisplaySlot slot, Objective::Objective *objective) noexcept;
    
        void addToObjectivebyCriteria(const std::string &criteria, const std::string &entity, int32_t value);
        void setToObjectivebyCriteria(const std::string &criteria, const std::string &entity, int32_t value);

        bool isTeam(const std::string &name) const noexcept;
        const Team::Team &getTeam(const std::string &name) const;
        const std::unordered_map<std::string, std::unique_ptr<Team::Team>> &getTeams(void) const noexcept;

        bool addTeam(const std::string &name);
        bool removeTeam(const std::string &name);

    private:
        const ScoreboardSystem &_system;
        std::unordered_map<std::string, std::shared_ptr<Objective::Objective>> _objectives;
        std::unordered_map<std::string, std::unique_ptr<Team::Team>> _teams;
        std::array<Objective::Objective *, 18> _displaySlots;
        std::unordered_map<std::string, std::unordered_map<std::string, std::shared_ptr<Objective::Objective>>> _objectivesByCriteria;
    };
};


#endif //CUBICSERVER_SCOREBOARD_SCOREBOARD_HPP