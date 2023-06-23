#ifndef CUBICSERVER_AI_AI_HPP
#define CUBICSERVER_AI_AI_HPP

namespace ai {
class AI {
 public:
  AI() {};
  virtual ~AI() = 0;

  virtual void update(float delta_time) = 0;
};
}  // namespace ai

#endif // CUBICSERVER_AI_AI_HPP
