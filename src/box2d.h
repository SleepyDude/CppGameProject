#pragma once

#include <ostream>
#include <cmath>
#include "point2d.hpp"


class Box2D
{
public:
  Box2D() = default;
  Box2D(Point2D const & boxMin, Point2D const & boxMax);
  Box2D(Box2D const & obj);
  Box2D(float f1, float f2, float f3, float f4);
  Box2D(Box2D && obj);

  Box2D Shift(Point2D const & obj);
  bool operator == (Box2D const & obj) const;
  bool operator != (Box2D const & obj) const;
  Point2D operator [] (unsigned int const & index) const;
  bool operator % (Box2D const & obj);
  Box2D & operator = (Box2D && obj);

  Point2D const & boxMin() const;
  Point2D const & boxMax() const;
  void SetMin(Point2D const & obj);
  void SetMax(Point2D const & obj);
  Box2D & operator = (Box2D const & obj);

private:
  Point2D m_boxMin = { 0.0f, 0.0f }, m_boxMax = { 1.0f, 1.0f };
  Box2D Validate();
};
