#pragma once

#include "point2d.hpp"

class Movable
{
public:
  virtual ~Movable() = default;
  virtual void Move(Point2D const & offset) = 0;
};
