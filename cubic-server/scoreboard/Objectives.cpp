#include "Dimension.hpp"
#include "Player.hpp"
#include "World.hpp"
#include "WorldGroup.hpp"
#include "logging/logging.hpp"
#include "protocol/ClientPackets.hpp"

#include "Objectives.hpp"
#include "Scoreboard.hpp"

namespace Scoreboard {
Score::Score(const int32_t &value):
    _score(value),
    _locked(true)
{
}

Score::Score(const int32_t &value, bool locked):
    _score(value),
    _locked(locked)
{
}

Score::~Score() { }

const int32_t &Score::get(void) const noexcept { return (this->_score); }

void Score::set(int32_t value) noexcept { this->_score = value; }

void Score::add(int32_t value) noexcept { this->_score += value; }

void Score::substract(int32_t value) noexcept { this->_score -= value; }

bool Score::isLocked(void) const noexcept { return (this->_locked); }

void Score::enable(void) noexcept { this->_locked = false; }

void Score::disable(void) noexcept { this->_locked = true; }

namespace Objective {
Objective::Objective(const Scoreboard &scoreboard, const std::string &name, const std::string &criteria):
    _scoreboard(scoreboard),
    _name(name),
    _criteria(criteria),
    _displayName(name),
    _renderType(RenderType::RenderInteger)
{
    LDEBUG("Added objective \"{}\"", name);
}

Objective::Objective(const Scoreboard &scoreboard, const std::string &name, const std::string &criteria, const chat::Message &displayName):
    _scoreboard(scoreboard),
    _name(name),
    _criteria(criteria),
    _displayName(displayName),
    _renderType(RenderType::RenderInteger)
{
    LDEBUG("Added objective \"{}\"", name);
}

Objective::Objective(const Scoreboard &scoreboard, const std::string &name, const std::string &criteria, const RenderType &renderType):
    _scoreboard(scoreboard),
    _name(name),
    _criteria(criteria),
    _displayName(name),
    _renderType(renderType)
{
    LDEBUG("Added objective \"{}\"", name);
}

Objective::Objective(const Scoreboard &scoreboard, const std::string &name, const std::string &criteria, const chat::Message &displayName, const RenderType &renderType):
    _scoreboard(scoreboard),
    _name(name),
    _criteria(criteria),
    _displayName(displayName),
    _renderType(renderType)
{
    LDEBUG("Added objective \"{}\"", name);
}

Objective::~Objective() { LDEBUG("Removed objective \"{}\"", this->_name); }

const std::string &Objective::getName(void) const noexcept { return (this->_name); }

const std::string &Objective::getCriteria(void) const noexcept { return (this->_criteria); }

const chat::Message &Objective::getDisplayName(void) const noexcept { return (this->_displayName); }

const RenderType &Objective::getRenderType(void) const noexcept { return (this->_renderType); }

std::unordered_map<std::string, Score> &Objective::getScores(void) noexcept { return (this->_values); }

Score &Objective::getScore(const std::string &name) { return (this->_values.at(name)); }

void Objective::setDisplayName(const std::string &displayName) noexcept
{
    this->_displayName = displayName;
    this->sendUpdateObjective();
}

void Objective::setRenderType(RenderType type) noexcept
{
    this->_renderType = type;
    this->sendUpdateObjective();
}

void Objective::setScore(const std::string &name, int32_t value)
{
    if (this->_values[name].get() == value)
        return;
    this->_values[name].set(value);
    this->sendUpdateScore(name, this->_values[name]);
    LDEBUG("{}: set {}'s score to {}", this->_name, name, value);
}

void Objective::addScore(const std::string &name, int32_t value)
{
    if (value == 0)
        return;
    this->_values[name].add(value);
    this->sendUpdateScore(name, this->_values[name]);
}

void Objective::substractScore(const std::string &name, int32_t value)
{
    if (value == 0)
        return;
    this->_values[name].substract(value);
    this->sendUpdateScore(name, this->_values[name]);
}

void Objective::deleteScore(const std::string &name)
{
    this->sendRemoveScore(name);
    this->_values.erase(name);
}

Score &Objective::operator[](const std::string &name) { return (this->getScore(name)); }

void Objective::sendUpdateObjective(void) const
{
    const protocol::UpdateObjectives update {this->getName(), 0, this->getDisplayName(), static_cast<protocol::UpdateObjectives::Type>(this->getRenderType())};

    for (const auto &[_, world] : this->_scoreboard.getWorldGroup().getWorlds()) {
        for (const auto &[_, dimension] : world->getDimensions()) {
            for (const auto &player : dimension->getPlayers()) {
                player->sendUpdateObjective(update);
            }
        }
    }
}

void Objective::sendUpdateScore(const std::string &name, const Score &score) const
{
    const protocol::UpdateScore update {name, 0, this->_name, score.get()};
    for (const auto &[_, world] : this->_scoreboard.getWorldGroup().getWorlds()) {
        for (const auto &[_, dimension] : world->getDimensions()) {
            for (const auto &player : dimension->getPlayers()) {
                player->sendUpdateScore(update);
            }
        }
    }
}

void Objective::sendRemoveScore(const std::string &name) const
{
    const protocol::UpdateScore update {name, 1, this->_name, 0};
    for (const auto &[_, world] : this->_scoreboard.getWorldGroup().getWorlds()) {
        for (const auto &[_, dimension] : world->getDimensions()) {
            for (const auto &player : dimension->getPlayers()) {
                player->sendUpdateScore(update);
            }
        }
    }
}
}
}
