#include "ScoreboardSystem.hpp"
#include "Scoreboard.hpp"

void ScoreboardSystem::initialize(void)
{
    this->addObjectiveCriteria("dummy");
    this->addObjectiveCriteria("trigger");
    this->addObjectiveCriteria("deathCount");
    this->addObjectiveCriteria("playerKillCount");
    this->addObjectiveCriteria("totalKillCount");
    this->addObjectiveCriteria("health");
    this->addObjectiveCriteria("xp");
    this->addObjectiveCriteria("level");
    this->addObjectiveCriteria("food");
    this->addObjectiveCriteria("air");
    this->addObjectiveCriteria("armor");
}

void ScoreboardSystem::addObjectiveCriteria(const std::string &criteria) { this->_criteriaSet.insert(criteria); }

bool ScoreboardSystem::hasObjectiveCriteria(const std::string &criteria) const { return (this->_criteriaSet.contains(criteria)); }
