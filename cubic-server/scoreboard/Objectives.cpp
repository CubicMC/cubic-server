#include "Objectives.hpp"

namespace Scoreboard {
    Score::Score(const int32_t &value) : _score(value), _locked(true)
    {}

    Score::Score(const int32_t &value, bool locked) : _score(value), _locked(locked)
    {}

    Score::~Score()
    {}

    const int32_t &Score::get(void) const noexcept
    {
        return (this->_score);
    }

    void Score::set(int32_t value) noexcept
    {
        this->_score = value;
    }

    void Score::add(int32_t value) noexcept
    {
        this->_score += value;
    }

    void Score::substract(int32_t value) noexcept
    {
        this->_score -= value;
    }

    void Score::enable(void) noexcept
    {
        this->_locked = false;
    }

    void Score::disable(void) noexcept
    {
        this->_locked = true;
    }

    namespace Objective {
        Objective::Objective(const std::string &name, const Criteria criteria) : _name(name), _criteria(criteria), _displayName(name), _renderType(RenderInteger)
        {}

        Objective::Objective(const std::string &name, const Criteria criteria, const std::string &displayName) : _name(name), _criteria(criteria), _displayName(displayName), _renderType(RenderInteger)
        {}

        Objective::Objective(const std::string &name, const Criteria criteria, const std::string &displayName, const RenderType &renderType) : _name(name), _criteria(criteria), _displayName(displayName), _renderType(renderType)
        {}

        Objective::Objective(const Objective &other) : _name(other.getName()), _criteria(other.getCriteria()), _displayName(other.getDisplayName()), _renderType(other.getRenderType()), _values(other.getScores())
        {}

        Objective::~Objective()
        {}

        const std::string &Objective::getName(void) const noexcept
        {
            return (this->_name);
        }

        const Criteria &Objective::getCriteria(void) const noexcept
        {
            return (this->_criteria);
        }

        const std::string &Objective::getDisplayName(void) const noexcept
        {
            return (this->_displayName);
        }

        const RenderType &Objective::getRenderType(void) const noexcept
        {
            return (this->_renderType);
        }

        const std::unordered_map<std::string, Score> &Objective::getScores(void) const noexcept
        {
            return (this->_values);
        }

        const int32_t &Objective::getScore(const std::string &name) const
        {
            return (this->_values.at(name).get());
        }

        void Objective::setDisplayName(const std::string &displayName) noexcept
        {
            this->_displayName = displayName;
        }

        void Objective::setRenderType(RenderType type) noexcept
        {
            this->_renderType = type;
        }

        void Objective::setScore(const std::string &name, int32_t value)
        {
            this->_values[name].set(value);
        }

        void Objective::addScore(const std::string &name, int32_t value)
        {
            this->_values[name].add(value);
        }

        void Objective::substractScore(const std::string &name, int32_t value)
        {
            this->_values[name].substract(value);
        }

        void Objective::deleteScore(const std::string &name)
        {
            this->_values.erase(name);
        }

        void Objective::setScores(const std::unordered_map<std::string, Score> &values)
        {
            this->_values = values;
        }

        const int32_t &Objective::operator[](const std::string &name)
        {
            return (this->getScore(name));
        }
    };
};