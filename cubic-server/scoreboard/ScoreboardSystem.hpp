#ifndef CUBICSERVER_SCOREBOARD_SYSTEM_HPP
#define CUBICSERVER_SCOREBOARD_SYSTEM_HPP

#include <string>
#include <unordered_set>

class ScoreboardSystem {
public:
    ScoreboardSystem() = default;
    ~ScoreboardSystem() = default;

    void initialize(void);

    void addObjectiveCriteria(const std::string &criteria);
    bool hasObjectiveCriteria(const std::string &criteria) const;

private:
    std::unordered_set<std::string> _criteriaSet;
};

#endif /* CUBICSERVER_SCOREBOARD_SYSTEM_HPP */
