#include "box2d.h"



Box2D::Box2D(Point2D p1, Point2D p2)
  : m_p1(p1), m_p2(p2)
{}
Box2D::Box2D(Box2D const & obj)
  : m_p1(obj.m_p1), m_p2(obj.m_p2)
{}
Box2D::Box2D(float f1, float f2, float f3, float f4)
  : m_p1(f1,f2), m_p2(f3,f4)
{}

Point2D & Box2D::p1() { return m_p1; }
Point2D & Box2D::p2() { return m_p2; }

// Оператор логического равенства.
bool Box2D::operator == (Box2D const & obj) const
{
  return (m_p1 == obj.m_p1)&&(m_p2 == obj.m_p2);
}

// Оператор присваивания.
Box2D & Box2D::operator = (Box2D const & obj)
{
  if (this == &obj) return *this;
  m_p1 = obj.m_p1;
  m_p2 = obj.m_p2;
  return *this;
}

// Оператор логического неравенства.
bool Box2D::operator != (Box2D const & obj) const
{
  return !Box2D::operator==(obj);
}

// Переопределение оператора [].
Point2D Box2D::operator [] (unsigned int index) const
{
  if (index >= 2) return {0.0f, 0.0f};
  return index == 0 ? m_p1 : m_p2;
}

// Оператор проверки пересечения
bool Box2D::operator % (Box2D const & obj)
{
  Point2D nill;
  bool b1 = obj.m_p1 - m_p2 <<= nill,
       b2 = m_p1 - obj.m_p2 <<= nill;
  return b1 && b2 ? true : false;
}

