#ifndef CUBICSERVER_SCOREBOARD_OBJECTIVES_HPP
#define CUBICSERVER_SCOREBOARD_OBJECTIVES_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <cstdint>

class Entity;

namespace Scoreboard {
    class Score {
    public:
        Score(const int32_t &value = 0);
        Score(const int32_t &value, bool locked);
        ~Score();

        const int32_t &get(void) const noexcept;
        void set(int32_t value) noexcept;
        void add(int32_t value) noexcept;
        void substract(int32_t value) noexcept;

        void enable(void) noexcept;
        void disable(void) noexcept;

    private:
        int32_t _score;
        bool _locked;
    };

    namespace Objective {
        using Criteria = uint16_t;

        enum RenderType {
            RenderInteger = 0,
            RenderHearts
        };

        class Objective {
        public:
            Objective(const std::string &name, const Criteria criteria);
            Objective(const std::string &name, const Criteria criteria, const std::string &displayName);
            Objective(const std::string &name, const Criteria criteria, const std::string &displayName, const RenderType &renderType);
            Objective(const Objective &other);
            ~Objective();

            const std::string &getName(void) const noexcept;
            const Criteria &getCriteria(void) const noexcept;
            const std::string &getDisplayName(void) const noexcept;
            const RenderType &getRenderType(void) const noexcept;
            const std::unordered_map<std::string, Score> &getScores(void) const noexcept;
            const int32_t &getScore(const std::string &name) const;

            void setDisplayName(const std::string &displayName) noexcept;
            void setRenderType(RenderType type) noexcept;
            void setScore(const std::string &name, int32_t value);
            void addScore(const std::string &name, int32_t value);
            void substractScore(const std::string &name, int32_t value);
            void deleteScore(const std::string &name);
            void setScores(const std::unordered_map<std::string, Score> &values);

            const int32_t &operator[](const std::string &name);

        private:
            const std::string _name;
            const Criteria _criteria;
            std::string _displayName; //json format
            RenderType _renderType;
            std::unordered_map<std::string, Score> _values;
        };
    };
};

#endif /* CUBICSERVER_SCOREBOARD_OBJECTIVES_HPP */
