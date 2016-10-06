#pragma once

#include <ostream>
#include <cmath>
#include "point2d.hpp"


class Box2D
{
public:
  Box2D() = default;
  Box2D(Point2D const &, Point2D const &);
  Box2D(Box2D const &);
  Box2D(float, float, float, float);

  bool operator == (Box2D const &) const;
  bool operator != (Box2D const &) const;
  Point2D operator [] (unsigned int index) const;
  bool operator % (Box2D const &);

  Point2D p1();
  Point2D p2();
  void SetMin(Point2D const &);
  void SetMax(Point2D const &);
  Box2D & operator = (Box2D const &);
private:

  Point2D m_p1 = { 0.0f, 0.0f }, m_p2 = { 1.0f, 1.0f };
};
