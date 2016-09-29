#pragma once

#include <ostream>
#include <cmath>
#include "point2d.hpp"


class Rectangle
{
public:
  Rectangle() = default;
  Rectangle(Point2D,Point2D);
  Rectangle(Rectangle const &);
  Rectangle(float,float,float,float);

  bool operator == (Rectangle const &) const;
  bool operator != (Rectangle const &) const;
  Point2D operator [] (unsigned int index) const;
  bool operator % (Rectangle const &);

  Point2D & p1();
  Point2D & p2();

  Rectangle & operator = (Rectangle const &);
private:

  Point2D m_p1 = { 0.0f, 0.0f }, m_p2 = { 1.0f, 1.0f };
};
