#include "ScoreboardSystem.hpp"
#include "Scoreboard.hpp"

namespace Scoreboard {
    Scoreboard::Scoreboard(const ScoreboardSystem &system) : _system(system)
    {
        this->_displaySlots.fill(nullptr);
    }

    bool Scoreboard::isObjective(const std::string &name) const noexcept
    {
        return (this->_objectives.contains(name));
    }

    const Objective::Objective &Scoreboard::getObjective(const std::string &name) const
    {
        return (*this->_objectives.at(name));
    }

    const std::unordered_map<std::string, std::shared_ptr<Objective::Objective>> &Scoreboard::getObjectives(void) const noexcept
    {
        return (this->_objectives);
    }

    bool Scoreboard::addObjective(const std::string &name, const std::string &criteria)
    {
        if (this->_objectives.contains(name))
            return (false);
        if (!this->_system.hasObjectiveCriteria(criteria))
            return (false);
        this->_objectives[name] = std::make_unique<Objective::Objective>(name, criteria);
        this->_objectivesByCriteria[criteria][name] = this->_objectives[name];
        return (true);
    }

    bool Scoreboard::addObjective(const std::string &name, const std::string &criteria, std::string &displayName)
    {
        if (this->_objectives.contains(name))
            return (false);
        if (!this->_system.hasObjectiveCriteria(criteria))
            return (false);
        this->_objectives[name] = std::make_unique<Objective::Objective>(name, criteria, displayName);
        this->_objectivesByCriteria[criteria][name] = this->_objectives[name];
        return (true);
    }

    bool Scoreboard::removeObjective(const std::string &name)
    {
        if (!this->_objectives.contains(name))
            return (false);
        this->_objectivesByCriteria[this->_objectives[name]->getCriteria()].erase(name);
        this->_objectives.erase(name);
        return (true);
    }

    void Scoreboard::displayObjective(DisplaySlot slot, Objective::Objective *objective) noexcept
    {
        this->_displaySlots[slot] = objective;
    }

    void Scoreboard::addToObjectivebyCriteria(const std::string &criteria, const std::string &entity, int32_t value)
    {
        for (auto &[name, objective] : this->_objectivesByCriteria[criteria])
            objective->addScore(entity, value);
    }

    void Scoreboard::setToObjectivebyCriteria(const std::string &criteria, const std::string &entity, int32_t value)
    {
        for (auto &[name, objective] : this->_objectivesByCriteria[criteria])
            objective->setScore(entity, value);
    }

    bool Scoreboard::isTeam(const std::string &name) const noexcept
    {
        return (this->_teams.contains(name));
    }

    const Team::Team &Scoreboard::getTeam(const std::string &name) const
    {
        return (*this->_teams.at(name));
    }

    const std::unordered_map<std::string, std::unique_ptr<Team::Team>> &Scoreboard::getTeams(void) const noexcept
    {
        return (this->_teams);
    }

    bool Scoreboard::addTeam(const std::string &name)
    {
        if (this->_teams.contains(name))
            return (false);
        this->_teams[name] = std::unique_ptr<Team::Team>();
        return (true);
    }

    bool Scoreboard::removeTeam(const std::string &name)
    {
        if (!this->_teams.contains(name))
            return (false);
        this->_teams.erase(name);
        return (true);
    }
};

