#include "Scoreboard.hpp"

Scoreboards::Scoreboards()
{
    this->_displaySlots.fill(nullptr);
}

Scoreboards::~Scoreboards()
{

}

void Scoreboards::initialize(void)
{
    this->addObjectiveCriteria("dummy");
    this->addObjectiveCriteria("trigger");
}

void Scoreboards::addObjectiveCriteria(const std::string &criteria)
{
    this->_criteriaList.push_back(criteria);
}

const Scoreboard::Objective::Objective *Scoreboards::getObjective(const std::string &name)
{
    return (this->_objectives[name].get());
}

const std::unordered_map<std::string, std::unique_ptr<Scoreboard::Objective::Objective>> &Scoreboards::getObjectives(void)
{
    return (this->_objectives);
}

void Scoreboards::addObjective(const std::string &name, Scoreboard::Objective::Criteria criteria)
{
    this->_objectives[name] = std::make_unique<Scoreboard::Objective::Objective>(Scoreboard::Objective::Objective(name, criteria));
}

void Scoreboards::addObjective(const std::string &name, Scoreboard::Objective::Criteria criteria, std::string &displayName)
{
    this->_objectives[name] = std::make_unique<Scoreboard::Objective::Objective>(Scoreboard::Objective::Objective(name, criteria, displayName));
}

void Scoreboards::removeObjective(const std::string &name)
{
    this->_objectives.erase(name);
}

void Scoreboards::displayObjective(Scoreboard::DisplaySlot slot, Scoreboard::Objective::Objective *objective) noexcept
{
    this->_displaySlots[slot] = objective;
}

