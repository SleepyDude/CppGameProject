#pragma once
#include <functional>
#include "box2d.h"

using EventHandler = std::function<void()>;

class Observer
{
public:
  virtual ~Observer() = default;
  virtual void UpdateEvent(EventHandler const &, Box2D box) = 0;
};
