#pragma once

class Movable
{
public:
  virtual ~Movable() {}
  virtual void Move(Point2D const & offset) = 0;
};
