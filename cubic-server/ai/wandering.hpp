#ifndef CUBICSERVER_AI_WANDERING_HPP
#define CUBICSERVER_AI_WANDERING_HPP

#include "ai.hpp"

namespace ai {
class Wandering : public AI {
 public:
  Wandering();
  ~Wandering();

  void update(float delta_time) override;
};
}  // namespace ai
#endif // CUBICSERVER_AI_WANDERING_HPP
