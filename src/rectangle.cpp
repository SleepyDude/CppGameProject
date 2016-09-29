#include "rectangle.h"



Rectangle::Rectangle(Point2D p1, Point2D p2)
  : m_p1(p1), m_p2(p2)
{}
Rectangle::Rectangle(Rectangle const & obj)
  : m_p1(obj.m_p1), m_p2(obj.m_p2)
{}
Rectangle::Rectangle(float f1, float f2, float f3, float f4)
  : m_p1(f1,f2), m_p2(f3,f4)
{}

Point2D & Rectangle::p1() { return m_p1; }
Point2D & Rectangle::p2() { return m_p2; }

// Оператор логического равенства.
bool Rectangle::operator == (Rectangle const & obj) const
{
  return (m_p1 == obj.m_p1)&&(m_p2 == obj.m_p2);
}

// Оператор присваивания.
Rectangle & Rectangle::operator = (Rectangle const & obj)
{
  if (this == &obj) return *this;
  m_p1 = obj.m_p1;
  m_p2 = obj.m_p2;
  return *this;
}

// Оператор логического неравенства.
bool Rectangle::operator != (Rectangle const & obj) const
{
  return !Rectangle::operator==(obj);
}

// Переопределение оператора [].
Point2D Rectangle::operator [] (unsigned int index) const
{
  if (index >= 2) return {0.0f, 0.0f};
  return index == 0 ? m_p1 : m_p2;
}

// Оператор проверки пересечения
bool Rectangle::operator % (Rectangle const & obj)
{
  Point2D nill;
  bool b1 = obj.m_p1 - m_p2 <<= nill,
       b2 = m_p1 - obj.m_p2 <<= nill;
  return b1 && b2 ? true : false;
}

